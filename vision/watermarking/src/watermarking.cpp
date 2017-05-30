/**********
Copyright (c) 2017, Xilinx, Inc.
All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice,
this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice,
this list of conditions and the following disclaimer in the documentation
and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors
may be used to endorse or promote products derived from this software
without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**********/

#include <iostream>

//Includes
#include "xcl.h"
#include "bitmap.h"

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cout << "Usage: " << argv[0] << " <input bitmap> <golden bitmap>" << std::endl;
        return EXIT_FAILURE ;
    }
    const char* bitmapFilename = argv[1];
    const char* goldenFilename;

    //Read the input bit map file into memory
    BitmapInterface image(bitmapFilename);
    bool result = image.readBitmapFile() ;
    if (!result)
    {
        std::cout << "ERROR:Unable to Read Input Bitmap File "<< bitmapFilename << std::endl;
        return EXIT_FAILURE ;
    }


    int width = image.getWidth() ;
    int height = image.getHeight() ;
   
    //Allocate Memory in Host Memory 
    int image_size_bytes = image.numPixels() * sizeof(int); 
    int* outImage = (int*)(malloc(image_size_bytes)) ;
    if (outImage == NULL)
    {
        std::cout << "Unable to allocate host memory!" << std::endl ;
        return EXIT_FAILURE ;
    }

//OPENCL HOST CODE AREA START
   //Create Program and Kernels
    xcl_world world = xcl_world_single();
    cl_program program = xcl_import_binary(world, "apply_watermark");
    cl_kernel krnl_applyWatermark = xcl_get_kernel(program, "apply_watermark");

    // For Allocating Buffer to specific Global Memory Bank, user has to use cl_mem_ext_ptr_t
    // and provide the Banks
    //
    cl_mem_ext_ptr_t inExt, outExt;  // Declaring two extensions for both buffers
    inExt.flags  = XCL_MEM_DDR_BANK0; // Specify Bank0 Memory for input memory
    outExt.flags = XCL_MEM_DDR_BANK1; // Specify Bank1 Memory for output Memory
    inExt.obj = 0   ; outExt.obj = 0; // Setting Obj and Param to Zero
    inExt.param = 0 ; outExt.param = 0; 

    int err;
    //Allocate Buffer in Bank0 of Global Memory for Input Image using Xilinx Extension
    cl_mem buffer_inImage = clCreateBuffer(world.context, CL_MEM_READ_ONLY | CL_MEM_EXT_PTR_XILINX,
            image_size_bytes, &inExt, &err);
    if (err != CL_SUCCESS){
        std::cout << "Error: Failed to allocate device Memory" << std::endl;
        return EXIT_FAILURE;
    }
    //Allocate Buffer in Bank1 of Global Memory for Input Image using Xilinx Extension
    cl_mem buffer_outImage = clCreateBuffer(world.context, CL_MEM_WRITE_ONLY | CL_MEM_EXT_PTR_XILINX,
            image_size_bytes, &outExt, NULL);
    if (err != CL_SUCCESS){
        std::cout << "Error: Failed to allocate device Memory" << std::endl;
        return EXIT_FAILURE;
    }

    //Copy input Image to device global memory
    xcl_memcpy_to_device(world,buffer_inImage,image.bitmap(),image_size_bytes);
   
    //Set the Kernel Arguments
    xcl_set_kernel_arg(krnl_applyWatermark,0,sizeof(cl_mem),&buffer_inImage);
    xcl_set_kernel_arg(krnl_applyWatermark,1,sizeof(cl_mem),&buffer_outImage);
    xcl_set_kernel_arg(krnl_applyWatermark,2,sizeof(int),&width);
    xcl_set_kernel_arg(krnl_applyWatermark,3,sizeof(int),&height);
    
    //Launch the Kernel
    xcl_run_kernel3d(world,krnl_applyWatermark,1,1,1);

    //Copy Result from Device Global Memory to Host Local Memory
    xcl_memcpy_from_device(world, outImage, buffer_outImage,image_size_bytes);
    clFinish(world.command_queue);

    //Release Device Memories and Kernels
    clReleaseMemObject(buffer_inImage);
    clReleaseMemObject(buffer_outImage);
    clReleaseKernel(krnl_applyWatermark);
    clReleaseProgram(program);
    xcl_release_world(world);
//OPENCL HOST CODE AREA END


    bool match = false;
    if (argc > 2){
        goldenFilename = argv[2];
        //Read the golden bit map file into memory
        BitmapInterface goldenImage(goldenFilename);
        result = goldenImage.readBitmapFile() ;
        if (!result)
        {
            std::cout << "ERROR:Unable to Read Golden Bitmap File "<< goldenFilename << std::endl;
            return EXIT_FAILURE ;
        }
        //Compare Golden Image with Output image
        if ( image.getHeight() != goldenImage.getHeight() || image.getWidth() != goldenImage.getWidth()){
            match = true;
        }else{
            int* goldImgPtr = goldenImage.bitmap();
            for (unsigned int i = 0 ; i < image.numPixels(); i++){
                if (outImage[i] != goldImgPtr[i]){
                    match = true;
                    printf ("Pixel %d Mismatch Output %x and Expected %x \n", i, outImage[i], goldImgPtr[i]);
                    break;
                }
            }
        }
    }
        
    // Write the final image to disk
    image.writeBitmapFile(outImage);

    free(outImage) ;
    if (match){
        std::cout << "TEST FAILED." << std::endl; 
        return EXIT_FAILURE;
    }
    std::cout << "TEST PASSED." << std::endl;
    return EXIT_SUCCESS;

}

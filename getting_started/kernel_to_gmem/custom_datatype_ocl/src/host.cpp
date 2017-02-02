/**********
Copyright (c) 2016, Xilinx, Inc.
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
#define USE_IN_HOST
//OpenCL utility layer include
#include "xcl.h"
#include "bitmap.h"
#include "rgb_to_hsv.h"

//Utility Function Declaration
void sw_RgbToHsv(int* in, int *out, int image_size);
void sw_HsvToRgb(int *in, int *out, int image_size);
int compareImages(int * _in, int * _out, int image_size);


int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cout << "Usage: " << argv[0] << " <input bitmap>" << std::endl;
        return EXIT_FAILURE ;
    }
    const char* bitmapFilename = argv[1];

 
    //Read the bit map file into memory
    BitmapInterface image(bitmapFilename);
    bool result = image.readBitmapFile() ;
    if (!result)
    {
        std::cout << "ERROR:Unable to Read Bitmap File "<< bitmapFilename << std::endl;
      return EXIT_FAILURE ;
    }
   
    //Allocate Memory in Host Memory 
    int image_size = image.numPixels();
    size_t image_size_bytes = sizeof(int) * image_size;
    int* swHsvImage  = (int*)(malloc(image_size_bytes)) ;
    int* hwHsvImage  = (int*)(malloc(image_size_bytes)) ;
    int* outRgbImage = (int*)(malloc(image_size_bytes)) ;
   
//OPENCL HOST CODE AREA START
   //Create Program and Kernels
    xcl_world world = xcl_world_single();
    cl_program program = xcl_import_binary(world, "rgb_to_hsv");
    cl_kernel krnl_rgb2hsv = xcl_get_kernel(program, "rgb_to_hsv");
    
    //Allocate Buffer in Global Memory
    cl_mem buffer_rgbImage = xcl_malloc(world, CL_MEM_READ_ONLY, image_size_bytes);
    cl_mem buffer_hsvImage = xcl_malloc(world, CL_MEM_WRITE_ONLY, image_size_bytes);

    //Copy input RGB Image to device global memory
    xcl_memcpy_to_device(world,buffer_rgbImage,image.bitmap(),image_size_bytes);
   
    //Set the Kernel Arguments
    xcl_set_kernel_arg(krnl_rgb2hsv,0,sizeof(cl_mem),&buffer_rgbImage);
    xcl_set_kernel_arg(krnl_rgb2hsv,1,sizeof(cl_mem),&buffer_hsvImage);
    xcl_set_kernel_arg(krnl_rgb2hsv,2,sizeof(int),&image_size);
    
    //Launch the Kernel
    xcl_run_kernel3d(world,krnl_rgb2hsv,1,1,1);

    //Copy Result from Device Global Memory to Host Local Memory
    xcl_memcpy_from_device(world, hwHsvImage, buffer_hsvImage,image_size_bytes);
    clFinish(world.command_queue);

    //Release Device Memories and Kernels
    clReleaseMemObject(buffer_rgbImage);
    clReleaseMemObject(buffer_hsvImage);
    clReleaseKernel(krnl_rgb2hsv);
    xcl_release_world(world);
//OPENCL HOST CODE AREA END

    //Calculating sw based HSV Image 
    sw_RgbToHsv(image.bitmap(), swHsvImage, image.numPixels());

    //Compare the results of the Device to the Sw Based
    int match= compareImages(swHsvImage, hwHsvImage,image.numPixels());

    //Converting Generated HSV to back to RGB and Writing RGB file to disk
    sw_HsvToRgb(hwHsvImage, outRgbImage, image.numPixels());
    image.writeBitmapFile(outRgbImage) ;

    // Release Memory from Host Memory
    free(hwHsvImage) ;
    free(swHsvImage) ;
    free(outRgbImage) ;

    if (match){
        std::cout << "TEST FAILED." << std::endl; 
        return EXIT_FAILURE;
    }
    std::cout << "TEST PASSED." << std::endl;
    return EXIT_SUCCESS;
}


//Utility Functions Definitions Start Here

//Convert RGB to HSV Format
void sw_RgbToHsv(int* in, int *out, int image_size)
{
    RGBcolor rgb;
    HSVcolor hsv;
    for(unsigned int i = 0 ; i < image_size ; out[i] = hsv.h | (hsv.s << 8) | (hsv.v << 16), i++){
        rgb.r =  (in[i]) & 0xff;
        rgb.g = ( (in[i]) & 0xff00 ) >> 8 ;
        rgb.b = ( (in[i]) & 0xff0000 ) >> 16 ;
        unsigned char rgbMin, rgbMax;
        
        rgbMin = imin(rgb.r, (imin(rgb.g,rgb.b)));
        rgbMax = imax(rgb.r, (imax(rgb.g,rgb.b)));
        
        hsv.v = rgbMax;
        if (hsv.v == 0)
        {
            hsv.h = 0;
            hsv.s = 0;
            continue;
        }
        
        hsv.s = 255 * ((long)(rgbMax - rgbMin)) / hsv.v;
        if (hsv.s == 0)
        {
            hsv.h = 0;
            continue;
        }
        
        if (rgbMax == rgb.r)
            hsv.h = 0 + 43 * (rgb.g - rgb.b) / (rgbMax - rgbMin);
        else if (rgbMax == rgb.g)
            hsv.h = 85 + 43 * (rgb.b - rgb.r) / (rgbMax - rgbMin);
        else
            hsv.h = 171 + 43 * (rgb.r - rgb.g) / (rgbMax - rgbMin);
        }
}

//Convert RGB to HSV Format
void sw_HsvToRgb(int *in, int *out, int image_size)
{
    RGBcolor rgb;
    HSVcolor hsv;
    for (int i = 0 ; i < image_size ; out[i] = rgb.r | (rgb.g << 8) | (rgb.b << 16), i++)
    {
        hsv.h = in[i] & 0xff;
        hsv.s = (in[i] & 0xff00) >> 8;
        hsv.v = (in[i] & 0xff0000) >> 16;
        unsigned char region, p, q, t;
        unsigned int h, s, v, remainder;

        if (hsv.s == 0)
        {
            rgb.r = hsv.v;
            rgb.g = hsv.v;
            rgb.b = hsv.v;
            continue;
        }

        // converting to 16 bit to prevent overflow
        h = hsv.h;
        s = hsv.s;
        v = hsv.v;

        region = h / 43;
        remainder = (h - (region * 43)) * 6; 

        p = (v * (255 - s)) >> 8;
        q = (v * (255 - ((s * remainder) >> 8))) >> 8;
        t = (v * (255 - ((s * (255 - remainder)) >> 8))) >> 8;

        switch (region)
        {
            case 0:
                rgb.r = v;
                rgb.g = t;
                rgb.b = p;
                break;
            case 1:
                rgb.r = q;
                rgb.g = v;
                rgb.b = p;
                break;
            case 2:
                rgb.r = p;
                rgb.g = v;
                rgb.b = t;
                break;
            case 3:
                rgb.r = p;
                rgb.g = q;
                rgb.b = v;
                break;
            case 4:
                rgb.r = t;
                rgb.g = p;
                rgb.b = v;
                break;
            default:
                rgb.r = v;
                rgb.g = p;
                rgb.b = q;
                break;
        }
    }
}

int compareImages(int * _in, int * _out, int image_size)
{
    for (int i = 0, cnt = 0 ; i < image_size ; i++)
    {
        int in  = _in[i];
        int out = _out[i];
        in  = in  & 0xffffff;
        out = out & 0xffffff;
        if (in != out ){
            cnt++;
            std::cout << "ERROR: Pixel=" << i << " mismatch Expected=" 
                << in << " and Got=" << out << std::endl;
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}


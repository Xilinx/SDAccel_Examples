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

/*******************************************************************************
Description: 

    This is a CNN (Convolutional Neural Network) convolutional layer based
    example to showcase the effectiveness of using multiple compute units when
    the base algorithm consists of multiple nested loops with large loop count.    

*******************************************************************************/

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cassert>

//OpenCL utility layer include
#include "xcl.h"
#include "defns.h"

#define WORK_GROUP 4 
#define WORK_ITEM_PER_GROUP 1

#define DATA_SIZE OChan * OSize * OSize

// Software solution
void convGolden(int *weight, int *image, int *out, int i_chan, int o_chan)
{
    // Runs over output filters
    for(int output = 0; output < o_chan; output++){
        // Runs over output pixel in Y-direction
        for(int y = 0; y < OSize; y++){
            // Runs over output pixel in X-direction
            for(int x = 0; x < OSize; x++){
                short acc = 0;
                // Runs over each input channel of input feature map
                for(int input = 0; input < i_chan; input++){
                    // Runs over filter window 
                    for(int i = 0; i < WSize; i++){
                        // Runs over filter windows 
                        for(int j = 0; j < WSize; j++){

                            // Calculate input padding boundaries
                            int xVal = x*Stride + j-Padding, yVal = y*Stride + i-Padding;

                            // Convolution operation
                            if(yVal >= 0 && yVal < ISize && xVal >= 0 && xVal < ISize){
                                acc += (short) image[(input*ISize + yVal)*ISize + xVal] * 
                                       (short) weight[((output*WInChan + input)*WSize + i)*WSize + j];
                            }
                        }
                        // Update each output pixel / output filter
                        out[(output*OSize + y)*OSize + x] = acc;
                    }
                }
            }
        }
    }
}

unsigned long run_opencl_cnn(
    xcl_world world,
    bool good,
    int size,
    int* weight,
    int* image,
    int* output,
    int i_chan,
    int o_chan
) {
    cl_program program = xcl_import_binary(world, good ? "cnn_GOOD" : "cnn_BAD");
    cl_kernel krnl_cnn_conv = xcl_get_kernel(program, "cnn");

    std::cout << "Starting " << (good ? "GOOD" : "BAD") << " Kernel" << std::endl;

    size_t image_size_bytes  = sizeof(int) * i_chan * ISize * ISize;
    size_t weight_size_bytes = sizeof(int) * o_chan * WInChan * WSize * WSize;
    size_t output_size_bytes = sizeof(int) * o_chan * OSize * OSize;

    // Allocate Buffer in Global Memory
    cl_mem buffer_image    = xcl_malloc(world, CL_MEM_READ_ONLY, image_size_bytes);
    cl_mem buffer_weight   = xcl_malloc(world, CL_MEM_READ_ONLY, weight_size_bytes);
    cl_mem buffer_output   = xcl_malloc(world, CL_MEM_WRITE_ONLY, output_size_bytes);

    //Copy input data to device global memory
    xcl_memcpy_to_device(world, buffer_image, image, image_size_bytes);
    xcl_memcpy_to_device(world,buffer_weight,weight, weight_size_bytes);

    //Set the Kernel Arguments
    int narg = 0;
    xcl_set_kernel_arg(krnl_cnn_conv, narg++, sizeof(cl_mem), &buffer_image);
    xcl_set_kernel_arg(krnl_cnn_conv, narg++, sizeof(cl_mem), &buffer_weight);
    xcl_set_kernel_arg(krnl_cnn_conv, narg++, sizeof(cl_mem), &buffer_output);
    xcl_set_kernel_arg(krnl_cnn_conv, narg++, sizeof(int), &size);
    xcl_set_kernel_arg(krnl_cnn_conv, narg++, sizeof(int), &i_chan);
    xcl_set_kernel_arg(krnl_cnn_conv, narg++, sizeof(int), &o_chan);

    std::cout << "Begin " << (good ? "GOOD" : "BAD") << " Kernel" << std::endl;

    unsigned long duration;

    if(good) {
        int work_group = WORK_GROUP;
        int work_item_per_group = WORK_ITEM_PER_GROUP;

        int err = 0; 
        
        //Declare global & local Grids
        cl_uint dimension = 1;
        size_t global_size[dimension];
        size_t local_size[dimension];

        //Set global & local grids
        global_size[0] = work_group;
        local_size[0]  = work_item_per_group;

        cl_event event;

        //Launch the Kernel
        err = clEnqueueNDRangeKernel(world.command_queue, krnl_cnn_conv, 1, NULL, global_size, local_size, 0, NULL, &event);
        if(err != CL_SUCCESS){
            printf("Error: failed to execute kernel! %d\n", err);
            printf("Test failed\n");
            exit(EXIT_FAILURE);
        }
        clFinish(world.command_queue);

        duration = xcl_get_event_duration(event);
    } else {
        // Launch a single thread to perform the same computation
        // The kernel takes care of running over the whole data set
        duration = xcl_run_kernel3d(world, krnl_cnn_conv, 1, 1, 1);
    }

    //Copy Result from Device Global Memory to Host Local Memory
    xcl_memcpy_from_device(world, output, buffer_output, output_size_bytes);

    std::cout << "Finished " << (good ? "GOOD" : "BAD") << " Kernel" << std::endl;

    //Release Device Memories and Kernels
    clReleaseMemObject(buffer_image);
    clReleaseMemObject(buffer_weight);
    clReleaseMemObject(buffer_output);
    clReleaseKernel(krnl_cnn_conv);
    clReleaseProgram(program);
    return duration;
}

int main(int argc, char** argv)
{
    int i_chan = IChan;
    int o_chan = OChan;

    int size = DATA_SIZE;

    const char *xcl_emu = getenv("XCL_EMULATION_MODE");
    if(xcl_emu && !strcmp(xcl_emu, "hw_emu")) {
        i_chan = 1;
        o_chan = 1;

        size = o_chan * OSize * OSize;

        printf("\nOriginal Dataset is Reduced for Faster Execution of Hardware Emulation Flow\n");
        printf("\t#Input_Channels (IChan)            = %d (Original : 96 )\n", i_chan);
        printf("\t#Weight_Output_Channels (WOutChan) = %d (Original : 256)\n\n", o_chan);
    }

    // Allocate Memory in Host (Image, Weights and Output)
    size_t image_size_bytes  = sizeof(int) * i_chan * ISize * ISize;
    size_t weight_size_bytes = sizeof(int) * o_chan * WInChan * WSize * WSize;
    size_t output_size_bytes = sizeof(int) * o_chan * OSize * OSize;

    int *image                  = (int *) malloc(image_size_bytes);  assert(image);
    int *weight                 = (int *) malloc(weight_size_bytes); assert(weight);
    int *source_good_hw_results = (int *) malloc(output_size_bytes); assert(source_good_hw_results);
    int *source_bad_hw_results  = (int *) malloc(output_size_bytes); assert(source_bad_hw_results);
    int *source_sw_results      = (int *) malloc(output_size_bytes); assert(source_sw_results);

    // Initialize Image, Weights & Output Host Buffers
    for(int i = 0; i < i_chan*ISize*ISize; i++)
        image[i] = i%255;

    for(int i = 0; i < o_chan*WInChan*WSize*WSize; i++)
        weight[i] = i%255;

    for(int i = 0; i < o_chan*OSize*OSize; i++)
        source_sw_results[i] = source_good_hw_results[i] = source_bad_hw_results[i] = 0;

    convGolden(weight, image, source_sw_results, i_chan, o_chan);

    xcl_world world = xcl_world_single();

    unsigned long good_duration = run_opencl_cnn(world, true, size,
        weight, image, source_good_hw_results, i_chan, o_chan);

    unsigned long bad_duration = run_opencl_cnn(world, false, size,
        weight, image, source_bad_hw_results, i_chan, o_chan);

    xcl_release_world(world);

    // Compare the results of the Device to the simulation
    int match = 0;
    for (int i = 0 ; i < size; i++){
        if (source_good_hw_results[i] != source_sw_results[i]){
            std::cout << "Error: Result mismatch in good kernel" << std::endl;
            std::cout << "i = " << i << " CPU result = " << source_sw_results[i]
                << " Device result = " << source_good_hw_results[i] << std::endl;
            match = 1;
            break;
        }
        if (source_bad_hw_results[i] != source_sw_results[i]){
            std::cout << "Error: Result mismatch in bad kernel" << std::endl;
            std::cout << "i = " << i << " CPU result = " << source_sw_results[i]
                << " Device result = " << source_bad_hw_results[i] << std::endl;
            match = 1;
            break;
        }
 
    }

    /* Release Memory from Host Memory*/
    free(image);
    free(weight);
    free(source_good_hw_results);
    free(source_bad_hw_results);
    free(source_sw_results);

    std::cout << "GOOD duration = " << good_duration << " ns" << std::endl;
    std::cout << "BAD duration = "  << bad_duration  << " ns" << std::endl;

    std::cout << "TEST " << (match ? "FAILED" : "PASSED") << std::endl; 
    return (match ? EXIT_FAILURE :  EXIT_SUCCESS);
}

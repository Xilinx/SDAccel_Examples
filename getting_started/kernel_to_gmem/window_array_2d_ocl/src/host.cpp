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
#include <cstring>
#include <stdio.h>

//OpenCL utility layer include
#include "xcl.h"
#include "host.h"

////////////////////////////////////////////////////////////////////////////////
int main(int argc, char** argv)
{
    //Allocate Memory in Host Memory
    size_t vector_size_bytes = sizeof(int) * BLOCK_SIZE;
    int* a = (int*)malloc(vector_size_bytes);// original data set given to device
    int* c = (int*)malloc(vector_size_bytes);// results returned from device
    int* sw_c = (int*)malloc(vector_size_bytes);// results returned from software
 
    // Create the test data and Software Result 
    int alpha = 3;
    for(int i = 0; i < BLOCK_SIZE; i++) {
      a[i] = i;
      c[i] = 0;
      sw_c[i] = alpha*a[i];
    }

//OPENCL HOST CODE AREA START
    //Create Program and Kernel
    xcl_world world = xcl_world_single();
    cl_program program = xcl_import_binary(world, "window_array_2d");
    cl_kernel krnl_read_data  = xcl_get_kernel(program, "read_data");
    cl_kernel krnl_write_data = xcl_get_kernel(program, "write_data");
    cl_kernel krnl_compute    = xcl_get_kernel(program, "compute");


    // By-default xcl_world_single create command queues with sequential command.
    // For this example, user to replace command queue with out of order command queue
    clReleaseCommandQueue(world.command_queue);
    int err;
    world.command_queue = clCreateCommandQueue(world.context, world.device_id,
            CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE | CL_QUEUE_PROFILING_ENABLE,
            &err);
    if (err != CL_SUCCESS){
        std::cout << "Error: Failed to create a command queue!" << std::endl;
        std::cout << "Test failed" << std::endl;
        exit(EXIT_FAILURE);
    }

    //Allocate Buffer in Global Memory
    cl_mem buffer_a = xcl_malloc(world, CL_MEM_READ_ONLY, vector_size_bytes);
    cl_mem buffer_c = xcl_malloc(world, CL_MEM_WRITE_ONLY, vector_size_bytes);

    //Copy input data to device global memory
    xcl_memcpy_to_device(world,buffer_a,a,vector_size_bytes);

    //Wait
    clFinish(world.command_queue);

    //Set the Kernel Arguments
    xcl_set_kernel_arg(krnl_read_data,0,sizeof(cl_mem),&buffer_a);
    xcl_set_kernel_arg(krnl_compute,0,sizeof(int),&alpha);
    xcl_set_kernel_arg(krnl_write_data,0,sizeof(cl_mem),&buffer_c);

    //Launch the Kernel
    xcl_run_kernel3d_nb(world,krnl_read_data);
    xcl_run_kernel3d_nb(world,krnl_compute);
    xcl_run_kernel3d_nb(world,krnl_write_data);

    //wait for all kernels to finish their operations
    clFinish(world.command_queue);

    //Copy Result from Device Global Memory to Host Local Memory
    xcl_memcpy_from_device(world, c, buffer_c ,vector_size_bytes);
    clFinish(world.command_queue);

    //Release Device Memories and Kernels
    clReleaseMemObject(buffer_a);
    clReleaseMemObject(buffer_c);
    clReleaseKernel(krnl_read_data);
    clReleaseKernel(krnl_compute);
    clReleaseKernel(krnl_write_data);
    clReleaseProgram(program);
    xcl_release_world(world);
//OPENCL HOST CODE AREA END

    // Validate
    unsigned int correct = 0;              // number of correct results returned
    for (int i = 0;i < BLOCK_SIZE; i++) {
      if(c[i] == sw_c[i]) {
        correct++; 
      } else { 
        printf("\n wrong sw %d hw %d index %d \n", sw_c[i], c[i], i);
      }
    }
    
    // Print a brief summary detailing the results
    printf("Computed '%d/%d' correct values!\n", correct, BLOCK_SIZE);

    free(a);
    free(c);
    free(sw_c);
    
    if(correct == BLOCK_SIZE){
        std::cout << "TEST PASSED." << std::endl; 
        return EXIT_SUCCESS;
    }
    else{
        std::cout << "TEST FAILED." << std::endl; 
        return EXIT_FAILURE;
    }
}

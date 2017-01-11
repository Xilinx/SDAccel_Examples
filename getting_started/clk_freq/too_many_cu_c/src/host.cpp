/*******************************************************************************
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
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,THE IMPLIED 
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, 
INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, 
BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, 
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY 
OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*******************************************************************************/

/*******************************************************************************
Description: 

    SDx Vector Addition example to show case effectiveness of using a heavier 
    single compute unit to achieve better performance than using lighter
    multiple compute units.

*******************************************************************************/
#include <iostream>
#include <cstring>
#include <cstdio>
//OpenCL utility layer include
#include "xcl.h"

#define DATA_SIZE 81920
#define WORK_GROUP 8
#define WORK_ITEM_PER_GROUP 1

#define NUM_CU 8

int main(int argc, char** argv)
{
    //Allocate Memory in Host Memory
    size_t vector_size_bytes = sizeof(int) * DATA_SIZE;

    int *source_in1         = (int *) malloc(vector_size_bytes);
    int *source_in2         = (int *) malloc(vector_size_bytes);
    int *source_hw_results  = (int *) malloc(vector_size_bytes);
    int *source_sw_results  = (int *) malloc(vector_size_bytes);
    
    // Create the test data and Software Result 
    for(int i = 0 ; i < DATA_SIZE ; i++){
        source_in1[i] = i;
        source_in2[i] = i * i;
        source_sw_results[i] = i * i + i;
        source_hw_results[i] = 0;
    }

//OPENCL HOST CODE AREA START
    //Create Program and Kernels
    xcl_world world = xcl_world_single();
    cl_program program = xcl_import_binary(world, "vadd");
    cl_kernel krnl_vector_add = xcl_get_kernel(program, "vadd");
    
    //Allocate Buffer in Global Memory
    cl_mem buffer_in1    = xcl_malloc(world, CL_MEM_READ_ONLY, vector_size_bytes);
    cl_mem buffer_in2    = xcl_malloc(world, CL_MEM_READ_ONLY, vector_size_bytes);
    cl_mem buffer_output = xcl_malloc(world, CL_MEM_WRITE_ONLY, vector_size_bytes);

    //Copy input data to device global memory
    xcl_memcpy_to_device(world,buffer_in1,source_in1,vector_size_bytes);
    xcl_memcpy_to_device(world,buffer_in2,source_in2,vector_size_bytes);
    
    //Amount of vector data to be processed by kernel
    int size = DATA_SIZE;
    
    #ifdef BAD
        int err;
        // By-default xcl_world_single create command queues with sequential command.
        // For this example, user to replace command queue with out of order command queue
        clReleaseCommandQueue(world.command_queue);
        world.command_queue = clCreateCommandQueue(world.context, world.device_id, CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE | CL_QUEUE_PROFILING_ENABLE, &err);
        if (err != CL_SUCCESS){
            std::cout << "Error: Failed to create a command queue!" << std::endl;
            std::cout << "Test failed" << std::endl;
            return EXIT_FAILURE;
        }
        
        for(int i = 0; i < NUM_CU; i++){
            
            int narg = 0;
            int global_size = WORK_GROUP;
            
            xcl_set_kernel_arg(krnl_vector_add,narg++, sizeof(cl_mem), &buffer_in1);
            xcl_set_kernel_arg(krnl_vector_add,narg++, sizeof(cl_mem), &buffer_in2);
            xcl_set_kernel_arg(krnl_vector_add,narg++, sizeof(cl_mem), &buffer_output);
            xcl_set_kernel_arg(krnl_vector_add,narg++, sizeof(int), &size);
            xcl_set_kernel_arg(krnl_vector_add,narg++, sizeof(int), &i);
            xcl_set_kernel_arg(krnl_vector_add,narg++, sizeof(int), &global_size);
            
            xcl_run_kernel3d_nb(world, krnl_vector_add);
        }
        clFinish(world.command_queue);
        
        //Copy Result from Device Global Memory to Host Local Memory
        xcl_memcpy_from_device(world, source_hw_results, buffer_output,vector_size_bytes);
        clFinish(world.command_queue);
        
    #else
        //Set the Kernel Arguments
        int narg = 0;
        xcl_set_kernel_arg(krnl_vector_add,narg++,sizeof(cl_mem),&buffer_in1);
        xcl_set_kernel_arg(krnl_vector_add,narg++,sizeof(cl_mem),&buffer_in2);
        xcl_set_kernel_arg(krnl_vector_add,narg++,sizeof(cl_mem),&buffer_output);
        xcl_set_kernel_arg(krnl_vector_add,narg++,sizeof(int),&size);

        //Launch the Kernel
        xcl_run_kernel3d(world,krnl_vector_add,1,1,1);

        //Copy Result from Device Global Memory to Host Local Memory
        xcl_memcpy_from_device(world, source_hw_results, buffer_output,vector_size_bytes);
        clFinish(world.command_queue);

        //Release Device Memories and Kernels
        clReleaseMemObject(buffer_in1);
        clReleaseMemObject(buffer_in2);
        clReleaseMemObject(buffer_output);
        clReleaseKernel(krnl_vector_add);
        xcl_release_world(world);
    #endif
//OPENCL HOST CODE AREA END
    
    // Compare the results of the Device to the simulation
    int match = 0;
    for (int i = 0 ; i < DATA_SIZE ; i++){
        if (source_hw_results[i] != source_sw_results[i]){
            std::cout << "Error: Result mismatch" << std::endl;
            std::cout << "i = " << i << " CPU result = " << source_sw_results[i]
                << " Device result = " << source_hw_results[i] << std::endl;
            match = 1;
            break;
        }
    }

    /* Release Memory from Host Memory*/
    free(source_in1);
    free(source_in2);
    free(source_hw_results);
    free(source_sw_results);

    if (match){
        std::cout << "TEST FAILED." << std::endl; 
        return -1;
    }
    std::cout << "TEST PASSED." << std::endl;
    return 0;
}

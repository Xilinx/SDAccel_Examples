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
#include <cstring>

//OpenCL utility layer include
#include "xcl.h"

#define DATA_SIZE 256

int main(int argc, char** argv)
{
    int size = DATA_SIZE;
    //Allocate Memory in Host Memory
    size_t vector_size_bytes = sizeof(int) * size;

    int *source_input1      = (int *) malloc(vector_size_bytes);
    int *source_input2      = (int *) malloc(vector_size_bytes);
    int *source_hw_results  = (int *) malloc(vector_size_bytes);
    int *source_sw_results  = (int *) malloc(vector_size_bytes);

    // Create the test data and Software Result 
    for(int i = 0 ; i < size ; i++){
        source_input1[i] = i;
        source_input2[i] = i;
        source_sw_results[i] = source_input1[i] + source_input2[i];
        source_hw_results[i] = 0;
    }

//OPENCL HOST CODE AREA START
    //Create Program and Kernel
    xcl_world world = xcl_world_single();
    cl_program program = xcl_import_binary(world, "vadd");
    cl_kernel krnl_vadd = xcl_get_kernel(program, "krnl_vadd_rtl");

    //Allocate Buffer in Global Memory
    cl_mem buffer_r1 = xcl_malloc(world, CL_MEM_READ_ONLY, vector_size_bytes);
    cl_mem buffer_r2 = xcl_malloc(world, CL_MEM_READ_ONLY, vector_size_bytes);
    cl_mem buffer_w = xcl_malloc(world, CL_MEM_WRITE_ONLY, vector_size_bytes);

    //Copy input data to device global memory
    xcl_memcpy_to_device(world,buffer_r1,source_input1,vector_size_bytes);
    xcl_memcpy_to_device(world,buffer_r2,source_input2,vector_size_bytes);

    //Set the Kernel Arguments
    xcl_set_kernel_arg(krnl_vadd,0,sizeof(cl_mem),&buffer_r1);
    xcl_set_kernel_arg(krnl_vadd,1,sizeof(cl_mem),&buffer_r2);
    xcl_set_kernel_arg(krnl_vadd,2,sizeof(cl_mem),&buffer_w);
    xcl_set_kernel_arg(krnl_vadd,3,sizeof(int),&size);

    //Launch the Kernel
    xcl_run_kernel3d(world,krnl_vadd,1,1,1);

    //Copy Result from Device Global Memory to Host Local Memory
    xcl_memcpy_from_device(world, source_hw_results, buffer_w ,vector_size_bytes);

    //Release Device Memories and Kernels
    clReleaseMemObject(buffer_r1);
    clReleaseMemObject(buffer_r2);
    clReleaseMemObject(buffer_w);
    clReleaseKernel(krnl_vadd);
    xcl_release_world(world);
//OPENCL HOST CODE AREA END
    
    // Compare the results of the Device to the simulation
    int match = 0;
    for (int i = 0 ; i < size ; i++){
        if (source_hw_results[i] != source_sw_results[i]){
            std::cout << "Error: Result mismatch" << std::endl;
            std::cout << "i = " << i << " Software result = " << source_sw_results[i]
                << " Device result = " << source_hw_results[i] << std::endl;
            match = 1;
            break;
        }
    }

    // Release Memory from Host Memory
    free(source_input1);
    free(source_input2);
    free(source_hw_results);
    free(source_sw_results);

    if (match){
        std::cout << "TEST FAILED." << std::endl; 
        return EXIT_FAILURE;
    }
    std::cout << "All Device results match CPU results! " << std::endl;
    std::cout << "TEST PASSED." << std::endl; 
    return EXIT_SUCCESS; 
}

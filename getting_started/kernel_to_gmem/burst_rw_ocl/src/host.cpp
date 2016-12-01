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

#include <iostream>
#include <cstring>

//OpenCL utility layer include
#include "xcl.h"

#define DATA_SIZE 256
#define INCR_VALUE 10
//define internal buffer max size
#define BURSTBUFFERSIZE 2048

int main(int argc, char** argv)
{
    int size = DATA_SIZE;
    int inc_value = INCR_VALUE;
    //Allocate Memory in Host Memory
    size_t vector_size_bytes = sizeof(int) * size;

    int *source_input       = (int *) malloc(vector_size_bytes);
    int *source_hw_results  = (int *) malloc(vector_size_bytes);
    int *source_sw_results  = (int *) malloc(vector_size_bytes);

    // Create the test data and Software Result 
    for(int i = 0 ; i < size ; i++){
        source_input[i] = i;
        source_sw_results[i] = i + inc_value;
        source_hw_results[i] = 0;
    }

//OPENCL HOST CODE AREA START
    //Create Program and Kernel
    xcl_world world = xcl_world_single();
    cl_program program = xcl_import_binary(world, "vadd");
    cl_kernel krnl_vadd = xcl_get_kernel(program, "vadd");

    //Allocate Buffer in Global Memory
    cl_mem buffer_rw = xcl_malloc(world, CL_MEM_READ_WRITE, vector_size_bytes);

    //Copy input data to device global memory
    xcl_memcpy_to_device(world,buffer_rw,source_input,vector_size_bytes);

    //Set the Kernel Arguments
    xcl_set_kernel_arg(krnl_vadd,0,sizeof(cl_mem),&buffer_rw);
    xcl_set_kernel_arg(krnl_vadd,1,sizeof(int),&size);
    xcl_set_kernel_arg(krnl_vadd,2,sizeof(int),&inc_value);

    //Launch the Kernel
    xcl_run_kernel3d(world,krnl_vadd,1,1,1);

    //Copy Result from Device Global Memory to Host Local Memory
    xcl_memcpy_from_device(world, source_hw_results, buffer_rw ,vector_size_bytes);
    clFinish(world.command_queue);

    //Release Device Memories and Kernels
    clReleaseMemObject(buffer_rw);
    clReleaseKernel(krnl_vadd);
    xcl_release_world(world);
//OPENCL HOST CODE AREA END
    
    // Compare the results of the Device to the simulation
    int match = 0;
    for (int i = 0 ; i < size ; i++){
        if (source_hw_results[i] != source_sw_results[i]){
            std::cout << "Error: Result mismatch" << std::endl;
            std::cout << "i = " << i << " CPU result = " << source_sw_results[i]
                << " Device result = " << source_hw_results[i] << std::endl;
            match = 1;
            break;
        }else{
            std::cout << source_hw_results[i] << " " ;
            if ( ( (i+1) % 16) == 0) std::cout << std::endl;
        }
    }

    // Release Memory from Host Memory
    free(source_input);
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

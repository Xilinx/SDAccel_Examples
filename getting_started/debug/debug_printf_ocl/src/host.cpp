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

#include <cstring>
#include <iostream>

//OpenCL includes
#include "xcl.h"
#include "host.h"

int main(int argc, char* argv[])
{
// OPENCL HOST CODE AREA START
    xcl_world world = xcl_world_single();
    cl_program program = xcl_import_binary(world, "vadd");
    cl_kernel krnl = xcl_get_kernel(program, "krnl_vadd");

    size_t vector_size_bytes = sizeof(int) * LENGTH;
    cl_mem buffer_a = xcl_malloc(world, CL_MEM_READ_ONLY, 4*vector_size_bytes);
    cl_mem buffer_e = xcl_malloc(world, CL_MEM_WRITE_ONLY, vector_size_bytes);

    int *source_a = (int *) malloc(4*vector_size_bytes);
    int *result_sim = (int *) malloc(vector_size_bytes);

    //Create the test data and run the vector addition locally 
    for(int i=0; i < LENGTH; i++){
        source_a[4*i] = i;
        source_a[4*i+1] = 2*i;
        source_a[4*i+2] = 3*i;
        source_a[4*i+3] = 4*i;
        result_sim[i] = source_a[4*i] + source_a[4*i+1] + source_a[4*i+2] + source_a[4*i+3];

    }

    // Copy input vectors to memory 
    xcl_memcpy_to_device(world,buffer_a,source_a,4*vector_size_bytes);

    // Release the memory for temporary source data buffers on the host 
    free(source_a);


    // Set the kernel arguments 

    size_t global_size[3] = {LENGTH,1,1}; // global data size, set to 256
    size_t local_size[3]  = {WORKGROUP_SIZE,1,1}; // local workgroup size, set to 16

    xcl_set_kernel_arg(krnl, 0, sizeof(cl_mem), &buffer_a);
    xcl_set_kernel_arg(krnl, 1, sizeof(cl_mem), &buffer_e);

    // Launch the kernel with global data size <256,1,1> and local workgroup size <16,1,1> 
	int err = clEnqueueNDRangeKernel(world.command_queue, krnl, 3,
	                                 NULL, global_size, local_size, 0, NULL, NULL);
    if (err != CL_SUCCESS){
        std::cout << "Error: failed to execute kernel!" << err << std::endl;
        exit(EXIT_FAILURE);
    }

    // Allocate result buffer on host memory 
    int *result_krnl = (int*) malloc(vector_size_bytes);

    // Copy result to local buffer 
    xcl_memcpy_from_device(world, result_krnl, buffer_e, vector_size_bytes);
    clFinish(world.command_queue);

    clReleaseMemObject(buffer_a);
    clReleaseMemObject(buffer_e);
    clReleaseKernel(krnl);
    xcl_release_world(world);

// OPENCL HOST CODE AREA END

    // Compare the results of the kernel to the simulation 
    int krnl_match = 0;
    std::cout <<"Checking against expected results and printing every 16th result (in 1024 additions)..." << std::endl;
    for(int i = 0; i < LENGTH; i++){
        if(result_sim[i] != result_krnl[i]){
            std::cout <<"Error: Result mismatch" << std::endl;
            std::cout <<"i = " << i << " CPU result = " << result_sim[i] << " Krnl Result = " << result_krnl[i] << std::endl;
            krnl_match = 1;
            break;
        }
        else{
            if (i %16 == 0)
                std::cout <<"Result Match: i = " << i << " CPU result = " << result_sim[i] << " Krnl Result = " << result_krnl[i] << std::endl;
        }
    }

    // Release memory objects from the host 
    free(result_sim);
    free(result_krnl);

    if(krnl_match == 1)
    {
        std::cout << "TEST FAILED! Kernel results do not match cpu results." << std::endl;
        return EXIT_FAILURE;
    }
    else{
        std::cout << "TEST PASSED! Kernel results match cpu results." << std::endl;
        return EXIT_SUCCESS;
    }
}

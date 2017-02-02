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

/*******************************************************************************

Description: 

    SDx Vector Addition example which showcases the how reordering the loops
    helps achieve better pipeline initiation interval(II) and better performance.

*******************************************************************************/

#include <iostream>
#include <cstring>

//OpenCL utility layer include
#include "xcl.h"

//Array Size to access 
#define DATA_SIZE 64

//Maximum Array Size
#define MAX_SIZE 64

// Software implementation of Matrix Multiplication
// The inputs are of the size (DATA_SIZE x DATA_SIZE)
void m_softwareGold(
                    int *in1,   //Input Matrix 1
                    int *in2,   //Input Matrix 2
                    int *out    //Output Matrix
                   )
{
    //Perform Matrix multiply Out = In1 x In2
    for(int i = 0; i < DATA_SIZE; i++) {
        for(int j = 0; j < DATA_SIZE; j++) {
            for(int k = 0; k < DATA_SIZE; k++) {
                out[i * DATA_SIZE + j] += in1[i * DATA_SIZE + k] * in2[k * DATA_SIZE + j];
            }
        }
    }
}  

int main(int argc, char** argv)
{
    //Allocate Memory in Host Memory
    
    if (DATA_SIZE > MAX_SIZE) {
        std::cout << "Size is bigger than internal buffer size, please use a size smaller than " << MAX_SIZE << "!" << std::endl;
        return EXIT_FAILURE;
    }
    
    size_t matrix_size_bytes = sizeof(int) * DATA_SIZE * DATA_SIZE;

    int *source_in1         = (int *) malloc(matrix_size_bytes);
    int *source_in2         = (int *) malloc(matrix_size_bytes);
    int *source_hw_results  = (int *) malloc(matrix_size_bytes);
    int *source_sw_results  = (int *) malloc(matrix_size_bytes);

    // Create the test data and Software Result 
    for(int i = 0 ; i < DATA_SIZE * DATA_SIZE ; i++){
        source_in1[i] = i;
        source_in2[i] = i * i;
        source_sw_results[i] = 0;
        source_hw_results[i] = 0;
    }

//OPENCL HOST CODE AREA START
    //Create Program and Kernels
    xcl_world world = xcl_world_single();
    cl_program program = xcl_import_binary(world, "mmult");
    cl_kernel krnl_loop_reorder = xcl_get_kernel(program, "mmult");

    //Allocate Buffer in Global Memory
    cl_mem buffer_in1    = xcl_malloc(world, CL_MEM_READ_ONLY, matrix_size_bytes);
    cl_mem buffer_in2    = xcl_malloc(world, CL_MEM_READ_ONLY, matrix_size_bytes);
    cl_mem buffer_output = xcl_malloc(world, CL_MEM_WRITE_ONLY, matrix_size_bytes);

    //Copy input data to device global memory
    xcl_memcpy_to_device(world,buffer_in1,source_in1,matrix_size_bytes);
    xcl_memcpy_to_device(world,buffer_in2,source_in2,matrix_size_bytes);
    xcl_memcpy_to_device(world,buffer_output,source_hw_results,matrix_size_bytes);

    int size = DATA_SIZE;
    //Set the Kernel Arguments
    xcl_set_kernel_arg(krnl_loop_reorder,0,sizeof(cl_mem),&buffer_in1);
    xcl_set_kernel_arg(krnl_loop_reorder,1,sizeof(cl_mem),&buffer_in2);
    xcl_set_kernel_arg(krnl_loop_reorder,2,sizeof(cl_mem),&buffer_output);
    xcl_set_kernel_arg(krnl_loop_reorder,3,sizeof(int),&size);

    //Launch the Kernel
    xcl_run_kernel3d(world,krnl_loop_reorder,1,1,1);

    //Copy Result from Device Global Memory to Host Local Memory
    xcl_memcpy_from_device(world, source_hw_results, buffer_output,matrix_size_bytes);
    clFinish(world.command_queue);

    //Release Device Memories and Kernels
    clReleaseMemObject(buffer_in1);
    clReleaseMemObject(buffer_in2);
    clReleaseMemObject(buffer_output);
    clReleaseKernel(krnl_loop_reorder);
    xcl_release_world(world);
//OPENCL HOST CODE AREA END
 
    // Compute Software Results
    m_softwareGold(source_in1, source_in2, source_sw_results);

    // Compare the results of the Device to the simulation
    int match = 0;
    for (int i = 0 ; i < DATA_SIZE * DATA_SIZE ; i++){
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

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

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

//OpenCL includes
#include "xcl.h"
#include "vadd.h"

int main(int argc, char* argv[]) {

    xcl_world world    = xcl_world_single();
    cl_program program = xcl_import_binary(world, "krnl_vadd");
    cl_kernel krnl     = xcl_get_kernel(program, "krnl_vadd");

    size_t vector_size_bytes = sizeof(int) * LENGTH;
    cl_mem buffer_a = xcl_malloc(world, CL_MEM_READ_ONLY, vector_size_bytes);
    cl_mem buffer_b = xcl_malloc(world,CL_MEM_READ_ONLY, vector_size_bytes);
    cl_mem buffer_c = xcl_malloc(world, CL_MEM_WRITE_ONLY, vector_size_bytes);

    int *source_a = (int *) malloc(vector_size_bytes);
    int *source_b = (int *) malloc(vector_size_bytes);
    int *result_sim = (int *) malloc(vector_size_bytes);

    /* Create the test data and run the vector addition locally */
    for(int i=0; i < LENGTH; i++){
        source_a[i] = i;
        source_b[i] = 2*i;
        result_sim[i] = source_a[i] + source_b[i];
    }

    /* Copy input vectors to memory */
    xcl_memcpy_to_device(world,buffer_a,source_a,vector_size_bytes);
    xcl_memcpy_to_device(world,buffer_b,source_b,vector_size_bytes);

    /* Release the memory for temporary source data buffers on the host */
    free(source_a);
    free(source_b);

    /* Set the kernel arguments */
    int vector_length = LENGTH;
    clSetKernelArg(krnl, 0, sizeof(cl_mem), &buffer_a);
    clSetKernelArg(krnl, 1, sizeof(cl_mem), &buffer_b);
    clSetKernelArg(krnl, 2, sizeof(cl_mem), &buffer_c);
    clSetKernelArg(krnl, 3, sizeof(int), &vector_length);

    /* Launch the kernel */
    unsigned long duration = xcl_run_kernel3d(world, krnl, 1, 1, 1);

    /* Allocate result buffer on host memory */
    int *result_krnl = (int*) malloc(vector_size_bytes);

     /* Copy result to local buffer */
    xcl_memcpy_from_device(world, result_krnl, buffer_c, vector_size_bytes);

    clReleaseMemObject(buffer_a);
    clReleaseMemObject(buffer_b);
    clReleaseMemObject(buffer_c);
    clReleaseKernel(krnl);
    xcl_release_world(world);

    /* Compare the results of the kernel to the simulation */
    int krnl_match = 0;
    for(int i = 0; i < LENGTH; i++){
        if(result_sim[i] != result_krnl[i]){
            printf("Error: Result mismatch\n");
            printf("i = %d CPU result = %d Krnl Result = %d\n", i, result_sim[i], result_krnl[i]);
            krnl_match = 1;
            break;
        } else{
            printf("Result Match: i = %d CPU result = %d Krnl Result = %d\n", i, result_sim[i], result_krnl[i]);
        }
    }

    /* Release memory objects from the host */
    free(result_sim);
    free(result_krnl);

    if(krnl_match == 1)
        return EXIT_FAILURE;
    else{
        printf("Success! kernel results match cpu results.\n");
        return EXIT_SUCCESS;
    }
}

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
#include <xcl.h>
#include <vdotprod.h>

int main(int argc, char* argv[]) {
    xcl_world world    = xcl_world_single();
    cl_program program = xcl_import_binary(world, "krnl_vdotprod");
    cl_kernel krnl     = xcl_get_kernel(program, "krnl_vdotprod");

    int nhalf = NPOINTS >> 1;
    size_t input_size_bytes = sizeof(int) * NPOINTS;
    size_t output_size_bytes = sizeof(int) * nhalf;

    cl_mem buffer_x = xcl_malloc(world, CL_MEM_READ_ONLY, input_size_bytes);
    cl_mem buffer_y = xcl_malloc(world, CL_MEM_READ_ONLY, input_size_bytes);
    cl_mem buffer_z = xcl_malloc(world, CL_MEM_READ_ONLY, input_size_bytes);
    cl_mem buffer_d = xcl_malloc(world, CL_MEM_WRITE_ONLY, output_size_bytes);

    int *source_x = (int *) malloc(input_size_bytes);
    int *source_y = (int *) malloc(input_size_bytes);
    int *source_z = (int *) malloc(input_size_bytes);
    int *result_sim = (int *) malloc(output_size_bytes);

    /* Create the test data and run the vector addition locally */
    for(int i=0; i < NPOINTS; i++) {
        source_x[i] = i;
        source_y[i] = 2*i;
        source_z[i] = 2*i - NPOINTS;
    }

    int j = 0;
    for(int i=0; i < nhalf; i++) {
        j = i + nhalf;
        result_sim[i] = source_x[i] * source_x[j] + 
                        source_y[i] * source_y[j] + 
                        source_z[i] * source_z[j];
    }

    /* Copy input vectors to memory */
    xcl_memcpy_to_device(world, buffer_x, source_x, input_size_bytes);
    xcl_memcpy_to_device(world, buffer_y, source_y, input_size_bytes);
    xcl_memcpy_to_device(world, buffer_z, source_z, input_size_bytes);

    /* Release the memory for temporary source data buffers on the host */
    free(source_x);
    free(source_y);
    free(source_z);

    /* Set the kernel arguments */
    clSetKernelArg(krnl, 0, sizeof(cl_mem), &buffer_x);
    clSetKernelArg(krnl, 1, sizeof(cl_mem), &buffer_y);
    clSetKernelArg(krnl, 2, sizeof(cl_mem), &buffer_z);
    clSetKernelArg(krnl, 3, sizeof(cl_mem), &buffer_d);
    clSetKernelArg(krnl, 4, sizeof(int), &nhalf);

    /* Launch the kernel */
    unsigned long duration = xcl_run_kernel3d(world, krnl, 1, 1, 1);

    /* Allocate result buffer on host memory */
    int *result_krnl = (int*) malloc(output_size_bytes);

     /* Copy result to local buffer */
    xcl_memcpy_from_device(world, result_krnl, buffer_d, output_size_bytes);

    clReleaseMemObject(buffer_x);
    clReleaseMemObject(buffer_y);
    clReleaseMemObject(buffer_z);
    clReleaseMemObject(buffer_d);
    clReleaseKernel(krnl);
    xcl_release_world(world);

	// OPENCL HOST CODE AREA END
    /* Compare the results of the kernel to the simulation */
    int krnl_match = 0;
    for(int i = 0; i < nhalf; i++){
        if(result_sim[i] != result_krnl[i]){
            printf("Error: Result mismatch");
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

    if(krnl_match == 1) {
        return EXIT_FAILURE;
    } else{
        printf("Success! kernel results match cpu results.");
        return EXIT_SUCCESS;
    }
}

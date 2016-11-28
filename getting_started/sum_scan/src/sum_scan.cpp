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

#include <xcl.h>

int main(int argc, char* argv[]) {
    if(argc != 1 && argc != 2) {
        printf("Usage: %s [length]\n", argv[0]);
        return EXIT_FAILURE;
    }

    unsigned length = 1000000;

    if(argc == 2) {
        length = atoi(argv[1]);
    }

    printf("length = %d\n", length);

    xcl_world world    = xcl_world_single();
    cl_program program = xcl_import_binary(world, "krnl_sum_scan");
    cl_kernel krnl     = xcl_get_kernel(program, "krnl_sum_scan");

    size_t vector_size_bytes = sizeof(float) * ((length-1)/16 + 1) * 16;
    cl_mem dev_in  = xcl_malloc(world, CL_MEM_READ_ONLY, vector_size_bytes);
    cl_mem dev_out = xcl_malloc(world,CL_MEM_READ_ONLY, vector_size_bytes);

    float *in = (float *) malloc(vector_size_bytes);
    float *out = (float *) malloc(vector_size_bytes);

    float sum = 0;

    /* Create the test data and run the vector addition locally */
    for(unsigned i=0; i < length; i++) {
        in[i] = (i%2 == 0) ? -1.0f : 1.0f;
        out[i] = (sum += in[i]);
    }

    /* Copy input vectors to memory */
    xcl_memcpy_to_device(world, dev_in, in, vector_size_bytes);

    /* Set the kernel arguments */
    clSetKernelArg(krnl, 0, sizeof(cl_mem), &dev_in);
    clSetKernelArg(krnl, 1, sizeof(cl_mem), &dev_out);
    clSetKernelArg(krnl, 2, sizeof(unsigned), &length);

    /* Launch the kernel */
    unsigned long duration = xcl_run_kernel3d(world, krnl, 1, 1, 1);

    /* Allocate result buffer on host memory */
    float *out_fpga = (float *) malloc(vector_size_bytes);

     /* Copy result to local buffer */
    xcl_memcpy_from_device(world, out_fpga, dev_out, vector_size_bytes);

    clReleaseMemObject(dev_in);
    clReleaseMemObject(dev_out);
    clReleaseKernel(krnl);
    xcl_release_world(world);

    /* Compare the results of the kernel to the simulation */
    size_t krnl_match = 0;
    for(unsigned i = 0; i < length; i++){
        if(out[i] != out_fpga[i]){
            printf("Error: Result mismatch\n");
            printf("i = %d CPU result = %f Krnl Result = %f\n", i, out[i], out_fpga[i]);
            krnl_match = 1;
            break;
        }
    }

    /* Release memory objects from the host */
    free(in);
    free(out);
    free(out_fpga);

    if(krnl_match == 1) {
        printf("Fail! kernel results do not match cpu results\n");
        return EXIT_FAILURE;
    } else{
        printf("Success! Kernel took %lld ns to execute\n", duration);
        return EXIT_SUCCESS;
    }
}

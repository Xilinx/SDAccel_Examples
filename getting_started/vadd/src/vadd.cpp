/*******************************************************************************
Vendor: Xilinx
Associated Filename: vadd.cpp
Purpose: SDAccel vector addition
Revision History: January 28, 2016

*******************************************************************************
Copyright (C) 2016 XILINX, Inc.

This file contains confidential and proprietary information of Xilinx, Inc. and
is protected under U.S. and international copyright and other intellectual
property laws.

DISCLAIMER
This disclaimer is not a license and does not grant any rights to the materials
distributed herewith. Except as otherwise provided in a valid license issued to
you by Xilinx, and to the maximum extent permitted by applicable law:
(1) THESE MATERIALS ARE MADE AVAILABLE "AS IS" AND WITH ALL FAULTS, AND XILINX
HEREBY DISCLAIMS ALL WARRANTIES AND CONDITIONS, EXPRESS, IMPLIED, OR STATUTORY,
INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, NON-INFRINGEMENT, OR
FITNESS FOR ANY PARTICULAR PURPOSE; and (2) Xilinx shall not be liable (whether
in contract or tort, including negligence, or under any other theory of
liability) for any loss or damage of any kind or nature related to, arising under
or in connection with these materials, including for any direct, or any indirect,
special, incidental, or consequential loss or damage (including loss of data,
profits, goodwill, or any type of loss or damage suffered as a result of any
action brought by a third party) even if such damage or loss was reasonably
foreseeable or Xilinx had been advised of the possibility of the same.

CRITICAL APPLICATIONS
Xilinx products are not designed or intended to be fail-safe, or for use in any
application requiring fail-safe performance, such as life-support or safety
devices or systems, Class III medical devices, nuclear facilities, applications
related to the deployment of airbags, or any other applications that could lead
to death, personal injury, or severe property or environmental damage
(individually and collectively, "Critical Applications"). Customer assumes the
sole risk and liability of any use of Xilinx products in Critical Applications,
subject only to applicable laws and regulations governing limitations on product
liability.

THIS COPYRIGHT NOTICE AND DISCLAIMER MUST BE RETAINED AS PART OF THIS FILE AT
ALL TIMES.

*******************************************************************************/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

//OpenCL includes
#include <xcl.h>
#include <vadd.h>

int main(int argc, char* argv[]) {
    if(argc != 1) {
        printf("Usage: %s\n", argv[0]);
        return EXIT_FAILURE;
    }

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

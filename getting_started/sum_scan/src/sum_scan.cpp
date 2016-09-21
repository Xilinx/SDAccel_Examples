/*******************************************************************************
Vendor: Xilinx
Associated Filename: sum_scan.cpp
Purpose: SDAccel Sum Scan
Revision History: September 21, 2016

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

#include <xcl.h>

int main(int argc, char* argv[]) {
    if(argc != 1 && argc != 2) {
        printf("Usage: %s [length]\n", argv[0]);
        return EXIT_FAILURE;
    }

    unsigned length = 1000000000;

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

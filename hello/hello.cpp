/*******************************************************************************
Vendor: Xilinx
Associated Filename: hello.cpp
Purpose: SDAccel printf example
Revision History: February 2, 2016

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

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <math.h>

//OpenCL includes
#include <xcl.h>
#include <hello.h>

int main(int argc, char* argv[])
{

    if(argc != 2)
    {
        std::cout << "Usage: " << argv[0] <<" <xclbin>" << std::endl;
        return -1;
    }

    const char* xclbinFilename = argv[1];

// OPENCL HOST CODE AREA START
    xcl_world world;
    cl_kernel krnl;

    if(strstr(argv[1], ".xclbin") != NULL) {
        world = xcl_world_single(CL_DEVICE_TYPE_ACCELERATOR);
        krnl  = xcl_import_binary(world, xclbinFilename, "krnl_hello");
    } else {
        world = xcl_world_single(CL_DEVICE_TYPE_CPU);
        krnl  = xcl_import_source(world, xclbinFilename, "krnl_hello");
    }


    size_t vector_size_bytes = sizeof(char) * LENGTH;
    cl_mem buffer_a = xcl_malloc(world, CL_MEM_READ_ONLY, vector_size_bytes);

    int *source_a = (int *) malloc(vector_size_bytes);


    /* Create the test data and run the vector addition locally */
    source_a[0] = 5;
    source_a[1] = 25;

    /* Copy input vectors to memory */
    xcl_memcpy_to_device(world,buffer_a,source_a,vector_size_bytes);

    /* Release the memory for temporary source data buffers on the host */
    free(source_a);

    /* Set the kernel arguments */
    int vector_length = LENGTH;
    clSetKernelArg(krnl, 0, sizeof(cl_mem), &buffer_a);

    /* Launch the kernel */
    unsigned long duration = xcl_run_kernel3d(world, krnl, 1, 1, 1);

    clReleaseMemObject(buffer_a);
    clReleaseKernel(krnl);
    xcl_release_world(world);

// OPENCL HOST CODE AREA END
}

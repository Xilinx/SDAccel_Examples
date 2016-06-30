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

typedef unsigned char u8;

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

    char* source_a = (char *) malloc(vector_size_bytes);


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

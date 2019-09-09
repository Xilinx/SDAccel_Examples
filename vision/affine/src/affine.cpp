/**********
Copyright (c) 2018, Xilinx, Inc.
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
#include "bitmap.h"
#include "xcl2.hpp"
#include <CL/cl.h>
#include <cstring>
#include <fcntl.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <vector>

#define X_SIZE 512
#define Y_SIZE 512

int main(int argc, char **argv) {

    if (argc != 3) {
        printf("Usage: %s <XCLBIN File> <image> \n", argv[0]);
        return -1;
    }

    std::string binaryFile = argv[1];

    FILE *input_file;
    FILE *output_file;

    size_t vector_size_bytes = sizeof(unsigned short) * Y_SIZE * X_SIZE;
    std::vector<unsigned short, aligned_allocator<unsigned short>> input_image(
        Y_SIZE * X_SIZE);
    cl_int err;

    std::vector<unsigned short, aligned_allocator<unsigned short>> output_image(
        Y_SIZE * X_SIZE);

    // Read the bit map file into memory and allocate memory for the final image
    std::cout << "Reading input image...\n";
    // Load the input image
    const char *imageFilename = argv[1];
    input_file = fopen(imageFilename, "rb");
    if (!input_file) {
        printf("Error: Unable to open input image file %s!\n", imageFilename);
        return 1;
    }
    printf("\n");
    printf("   Reading RAW Image\n");
    size_t items_read =
        fread(input_image.data(), vector_size_bytes, 1, input_file);
    printf("   Bytes read = %d\n\n", (int)(items_read * sizeof input_image));

    auto devices = xcl::get_xil_devices();
    auto device = devices[0];
    OCL_CHECK(err, cl::Context context(device, NULL, NULL, NULL, &err));

    OCL_CHECK(
        err,
        cl::CommandQueue q(context, device, CL_QUEUE_PROFILING_ENABLE, &err));

    OCL_CHECK(err,
              std::string device_name = device.getInfo<CL_DEVICE_NAME>(&err));
   auto fileBuf = xcl::read_binary_file(binaryFile);
   cl::Program::Binaries bins{{fileBuf.data(), fileBuf.size()}};
    devices.resize(1);
    OCL_CHECK(err, cl::Program program(context, devices, bins, NULL, &err));
    OCL_CHECK(err, cl::Kernel krnl(program, "affine_kernel", &err));

    OCL_CHECK(err,
              cl::Buffer imageToDevice(context,
                                       CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY,
                                       vector_size_bytes,
                                       input_image.data(),
                                       &err));
    OCL_CHECK(
        err,
        cl::Buffer imageFromDevice(context,
                                   CL_MEM_USE_HOST_PTR | CL_MEM_WRITE_ONLY,
                                   vector_size_bytes,
                                   output_image.data(),
                                   &err));

    // Set the kernel arguments
    OCL_CHECK(err, err = krnl.setArg(0, imageToDevice));
    OCL_CHECK(err, err = krnl.setArg(1, imageFromDevice));

    /* Copy input vectors to memory */
    OCL_CHECK(err,
              err = q.enqueueMigrateMemObjects({imageToDevice},
                                               0 /* 0 means from host*/));

    // Launch the kernel
    OCL_CHECK(err, err = q.enqueueTask(krnl));

    // Read back the image from the kernel
    std::cout << "Reading output image and writing to file...\n";
    output_file = fopen("transformed_image.raw", "wb");
    if (!output_file) {
        printf("Error: Unable to open output image file!\n");
        return 1;
    }

    OCL_CHECK(err,
              err = q.enqueueMigrateMemObjects({imageFromDevice},
                                               CL_MIGRATE_MEM_OBJECT_HOST));
    q.finish();


    printf("   Writing RAW Image\n");
    size_t items_written =
        fwrite(output_image.data(), vector_size_bytes, 1, output_file);
    printf("   Bytes written = %d\n\n",
           (int)(items_written * sizeof output_image));

    return 0;
}

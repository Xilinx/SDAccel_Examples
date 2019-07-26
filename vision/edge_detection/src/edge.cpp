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

// Edge Detection Example
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

// OpenCV includes
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

// XCL Helper Library
#include "xcl2.hpp"

#include "edge.h"

short getAbsMax(cv::Mat mat) {
    short max = 0;

    size_t rows = mat.rows;
    size_t cols = mat.cols;

    for (size_t r = 0; r < rows; r++) {
        for (size_t c = 0; c < cols; c++) {
            uchar tmp = std::abs(mat.at<uchar>(r, c));
            if (tmp > max) {
                max = tmp;
            }
        }
    }

    return max;
}

int main(int argc, char *argv[]) {
    cl_int err;
    cl::Event event;

    if (argc != 3) {
        std::cout << "Usage: " << argv[0] << " <XCLBIN File>"
                  << " <input>" << std::endl;
        return EXIT_FAILURE;
    }

    std::string binaryFile = argv[1];
    std::string inputFileName(argv[2]);
    cv::Mat inputColor = cv::imread(inputFileName);

    // Convert image to grayscale then convert to unsigned 8 bit values
    cv::Mat inputRaw, input;
    cv::cvtColor(inputColor, inputRaw, CV_BGR2GRAY);
    inputRaw.convertTo(input, CV_8UC1);

    //Vector IO Buffers are used to avoid unaligned host pointers
    std::vector<uchar, aligned_allocator<uchar>> image;
    if (input.isContinuous()) {
        image.assign(input.datastart, input.dataend);
    } else {
        for (int i = 0; i < input.rows; ++i) {
            image.insert(image.end(),
                         input.ptr<uchar>(i),
                         input.ptr<uchar>(i) + input.cols);
        }
    }

    size_t img_size = input.rows * input.cols;
    cv::Mat output(input.rows, input.cols, CV_8UC1);
    std::vector<uchar, aligned_allocator<uchar>> outimage(img_size);

    std::cout << "Calculating Max Energy..." << std::endl;
    short inputMax = getAbsMax(input);
    std::cout << "inputBits = " << ceil(log2(inputMax)) << " coefMax = 2"
              << std::endl;
    long long max_bits = (long long)inputMax * 2 * 3 * 3;
    std::cout << "Max Energy = " << ceil(log2(max_bits)) + 1 << " Bits"
              << std::endl;

    std::cout << "Image Dimensions: " << input.cols << "x" << input.rows
              << std::endl;

    assert(input.cols == IMAGE_WIDTH);
    assert(input.rows <= IMAGE_HEIGHT);

    // OPENCL HOST CODE AREA START
    // get_xil_devices() is a utility API which will find the xilinx
    // platforms and will return list of devices connected to Xilinx platform
    auto devices = xcl::get_xil_devices();
    auto device = devices[0];

    std::cout << "Creating Context..." << std::endl;
    OCL_CHECK(err, cl::Context context(device, NULL, NULL, NULL, &err));
    OCL_CHECK(
        err,
        cl::CommandQueue q(context, device, CL_QUEUE_PROFILING_ENABLE, &err));
    OCL_CHECK(err,
              std::string device_name = device.getInfo<CL_DEVICE_NAME>(&err));

    // read_binary_file() is a utility API which will load the binaryFile
    // and will return pointer to file buffer.
   auto fileBuf = xcl::read_binary_file(binaryFile);
   cl::Program::Binaries bins{{fileBuf.data(), fileBuf.size()}};
    devices.resize(1);
    OCL_CHECK(err, cl::Program program(context, devices, bins, NULL, &err));
    OCL_CHECK(err, cl::Kernel krnl_sobel(program, "krnl_sobel", &err));

    // Allocate Buffer in Global Memory
    // Buffers are allocated using CL_MEM_USE_HOST_PTR for efficient memory and
    // Device-to-host communication
    std::cout << "Creating Buffers..." << std::endl;
    OCL_CHECK(err,
              cl::Buffer devInput(context,
                                  CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY,
                                  ((img_size - 1) / 32 + 1) * sizeof(cl_uint16),
                                  image.data(),
                                  &err));
    OCL_CHECK(
        err,
        cl::Buffer devOutput(context,
                             CL_MEM_USE_HOST_PTR | CL_MEM_WRITE_ONLY,
                             ((img_size - 1) / 32 + 1) * sizeof(cl_uint16),
                             outimage.data(),
                             &err));

    std::cout << "Setting Arguments..." << std::endl;
    OCL_CHECK(err, err = krnl_sobel.setArg(0, devInput));
    OCL_CHECK(err, err = krnl_sobel.setArg(1, devOutput));

    // Copy input data to device global memory
    std::cout << "Copying Buffers to device..." << std::endl;
    OCL_CHECK(
        err,
        err = q.enqueueMigrateMemObjects({devInput}, 0 /*0 means from host*/));

    // Launch the Kernel
    // For HLS kernels global and local size is always (1,1,1). So, it is recommended
    // to always use enqueueTask() for invoking HLS kernel
    std::cout << "Launching Kernel..." << std::endl;
    OCL_CHECK(err, err = q.enqueueTask(krnl_sobel, NULL, &event));

    // Copy Result from Device Global Memory to Host Local Memory
    std::cout << "Getting Result..." << std::endl;
    OCL_CHECK(err,
              err = q.enqueueMigrateMemObjects({devOutput},
                                               CL_MIGRATE_MEM_OBJECT_HOST));
    q.finish();
    uint64_t nstimestart, nstimeend;
    OCL_CHECK(err,
              err = event.getProfilingInfo<uint64_t>(CL_PROFILING_COMMAND_START,
                                                     &nstimestart));
    OCL_CHECK(err,
              err = event.getProfilingInfo<uint64_t>(CL_PROFILING_COMMAND_END,
                                                     &nstimeend));

    auto duration = nstimeend - nstimestart;

    std::cout << "Kernel Duration: " << duration << " ns" << std::endl;
    //OPENCL HOST CODE AREA ENDS

    std::memcpy(output.data, outimage.data(), outimage.size());

    std::cout << "Calculating Output energy...." << std::endl;
    short outputMax = getAbsMax(output);

    std::cout << "outputBits = " << ceil(log2(outputMax)) << std::endl;

    cv::imwrite("input.bmp", input);
    cv::imwrite("output.bmp", output);


    std::cout << "Completed Successfully" << std::endl;

    return EXIT_SUCCESS;
}

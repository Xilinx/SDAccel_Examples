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

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

// OpenCV includes
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

// XCL Helper Library
#include "xcl.h"

#include "edge.h"

short getAbsMax(cv::Mat mat) {
	short max = 0;

	size_t rows = mat.rows;
	size_t cols = mat.cols;

	for(size_t r = 0; r < rows; r++) {
		for(size_t c = 0; c < cols; c++) {
			uchar tmp = std::abs(mat.at<uchar>(r,c));
			if(tmp > max) {
				max = tmp;
			}
		}
	}

	return max;
}

int main(int argc, char* argv[]) {
    if(argc != 2) {
        std::cout << "Usage: " << argv[0] << "<input>" << std::endl;
        return EXIT_FAILURE;
    }

    std::string inputFileName(argv[1]);
    cv::Mat inputColor = cv::imread(inputFileName);

    // Convert image to grayscale then convert to unsigned 8 bit values
    cv::Mat inputRaw, input;
    cv::cvtColor(inputColor, inputRaw, CV_BGR2GRAY);
    inputRaw.convertTo(input, CV_8UC1);
    // Ensure continous allocation of memory
    input.reshape(0);

    std::cout << "Calculating Max Energy..." << std::endl;
    short inputMax = getAbsMax(input);
    std::cout << "inputBits = " << ceil(log2(inputMax)) << " coefMax = 2" << std::endl;
    long long max_bits = (long long) inputMax * 2 * 3*3;
    std::cout << "Max Energy = " << ceil(log2(max_bits)) + 1 << " Bits" << std::endl;

    std::cout << "Image Dimensions: " << input.cols << "x" << input.rows << std::endl;
    size_t img_size = input.rows * input.cols;

    assert(input.cols == IMAGE_WIDTH);
    assert(input.rows <= IMAGE_HEIGHT);

    std::cout << "Creating context..." << std::endl;
    xcl_world world = xcl_world_single();
    cl_program program = xcl_import_binary(world, "krnl_edge");
    cl_kernel krnl = xcl_get_kernel(program, "krnl_sobel");

    std::cout << "Creating Buffers..." << std::endl;
    // Pad buffers to cl_uint16 bounderies
    cl_mem devInput  = xcl_malloc(world, CL_MEM_READ_ONLY,  ((img_size-1)/64 + 1)*sizeof(cl_uint16));
    cl_mem devOutput = xcl_malloc(world, CL_MEM_WRITE_ONLY, ((img_size-1)/64 + 1)*sizeof(cl_uint16));
 
    std::cout << "Copying Buffers to device...." << std::endl;
    xcl_memcpy_to_device(world, devInput, input.data, img_size);

    std::cout << "Starting Kernel..." << std::endl;
    xcl_set_kernel_arg(krnl, 0, sizeof(cl_mem), &devInput);
    xcl_set_kernel_arg(krnl, 1, sizeof(cl_mem), &devOutput);

    unsigned long duration = xcl_run_kernel3d(world, krnl, 1, 1, 1);
    std::cout << "Kernel Duration: " << duration << " ns" << std::endl;

    cv::Mat output(input.rows, input.cols, CV_8UC1);
    output.reshape(0);

    std::cout << "Copying results to host...." << std::endl;
    xcl_memcpy_from_device(world, output.data, devOutput, img_size);

    std::cout << "Calculating Output energy...." << std::endl;
    short outputMax  = getAbsMax(output);

    std::cout << "outputBits = " << ceil(log2(outputMax)) << std::endl;

    cv::imwrite("input.bmp", input);
    cv::imwrite("output.bmp", output);

    clReleaseMemObject(devOutput);
    clReleaseMemObject(devInput);
    clReleaseKernel(krnl);
    clReleaseProgram(program);
    xcl_release_world(world);

    std::cout << "Completed Successfully" << std::endl;

    return EXIT_SUCCESS;
}

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

// Convolve Example

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

// OpenCV includes
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

// XCL Helper Library
#include <xcl.h>

std::string getXclbinFileName(std::string name, std::string xmode, std::string xdevice) {
    std::string xclbinFileName;

    for(size_t i = 0; i < xdevice.size(); i++) {
        if(xdevice[i] == ':') {
            xdevice[i] = '_';
        }
    }

    return "xclbin/" + name + "." + xmode + "." + xdevice + ".xclbin";
}

short getAbsMax(cv::Mat mat, size_t rows, size_t cols) {
	short max = 0;
	
	for(int r = 0; r < rows; r++) {
		for(int c = 0; c < cols; c++) {
			short tmp = std::abs(mat.at<short>(r,c));
			if(tmp > max) {
				max = tmp;
			}
		}
	}

	return max;
}

cv::Mat readTxtFile(std::string fileName, size_t rows, size_t cols) {

    cv::Mat mat(rows, cols, CV_16S);

    std::ifstream txtFile(fileName.c_str());

    if(!txtFile.is_open()) {
        std::cout << "ERROR: Could not open file " << fileName << std::endl;
        abort();
    }

    for(int r = 0; r < rows; r++) {
        for(int c = 0; c < cols; c++) {
            txtFile >> mat.at<short>(r,c);
        }
    }

    return mat;
}

cv::Mat readFloatTxtFile(std::string fileName, size_t rows, size_t cols) {

    cv::Mat mat(rows, cols, CV_32F);

    std::ifstream txtFile(fileName.c_str());

    if(!txtFile.is_open()) {
        std::cout << "ERROR: Could not open file " << fileName << std::endl;
        abort();
    }

    for(int r = 0; r < rows; r++) {
        for(int c = 0; c < cols; c++) {
            txtFile >> mat.at<float>(r,c);
        }
    }

    return mat;
}

int main(int argc, char* argv[]) {
    if(argc != 3 && argc != 4)
    {
        std::cout << "Usage: " << argv[0] <<"<input> <coef> [<golden>]" << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "Parsing Command Line..." << std::endl;
    std::string inputFileName(argv[1]);
    std::string coefFileName(argv[2]);

    bool validate = false;

    if (argc == 4) {
        validate = true;
    }

    std::cout << "Creating context..." << std::endl;
    xcl_world world = xcl_world_single();
    cl_program program = xcl_import_binary(world, "krnl_convolve");
    cl_kernel krnl = xcl_get_kernel(program, "krnl_convolve");

    std::cout << "Reading inputs..." << std::endl;
    cv::Mat input  = readTxtFile(inputFileName, 1024, 1024);
    cv::Mat coef   = readTxtFile(coefFileName, 11, 11);

    input /= 32;
    coef *= 1;

    std::cout << "Calculating Max Energy..." << std::endl;
    short inputMax = getAbsMax(input, 1024, 1024);
    short coefMax  = getAbsMax(coef, 11, 11);

    std::cout << "inputBits = " << ceil(log2(inputMax)) << " coefMax = " << ceil(log2(coefMax)) << std::endl;
    long long max_bits = (long long) inputMax * coefMax * 11*11;

    std::cout << "Max Energy = " << ceil(log2(max_bits)) + 1 << " Bits" << std::endl;

    std::cout << "Creating Buffers..." << std::endl;
    cl_mem devCoef   = xcl_malloc(world, CL_MEM_READ_ONLY,  ((11*11-1)/32 + 1)*sizeof(cl_uint16));
    cl_mem devInput  = xcl_malloc(world, CL_MEM_READ_ONLY,  ((1024*1024-1)/32 + 1)*sizeof(cl_uint16));
    cl_mem devOutput = xcl_malloc(world, CL_MEM_WRITE_ONLY, ((1024*1024-1)/32 + 1)*sizeof(cl_uint16));
 
    std::cout << "Copying Buffers to device...." << std::endl;
    xcl_memcpy_to_device(world, devCoef, coef.data, 11*11*sizeof(short));
    xcl_memcpy_to_device(world, devInput, input.data, 1024*1024*sizeof(short));

    std::cout << "Starting Kernel..." << std::endl;
    clSetKernelArg(krnl, 0, sizeof(cl_mem), &devCoef);
    clSetKernelArg(krnl, 1, sizeof(cl_mem), &devInput);
    clSetKernelArg(krnl, 2, sizeof(cl_mem), &devOutput);

    unsigned long duration = xcl_run_kernel3d(world, krnl, 1, 1, 1);
    std::cout << "Kernel Duration: " << duration << " ns" << std::endl;

    cv::Mat output(1024, 1024, CV_16S);
    xcl_memcpy_from_device(world, output.data, devOutput, 1024*1024*sizeof(short));

    short outputMax  = getAbsMax(output, 1024, 1024);

    std::cout << "outputBits = " << ceil(log2(outputMax)) << std::endl;

    cv::imwrite("input.bmp", input);
    cv::imwrite("output.bmp", output);
    cv::imwrite("coef.bmp", coef);

    if(validate) {
        std::cout << "Validate" << std::endl;
        std::string goldenFileName(argv[3]);
        cv::Mat golden  = readFloatTxtFile(goldenFileName, 1014, 1014);

        cv::imwrite("golden.bmp", golden);
    }

    std::cout << "Cleanup..." << std::endl;
    clReleaseMemObject(devOutput);
    clReleaseMemObject(devInput);
    clReleaseMemObject(devCoef);
    clReleaseKernel(krnl);
    xcl_release_world(world);

    std::cout << "Completed Successfully" << std::endl;

    return EXIT_SUCCESS;
}

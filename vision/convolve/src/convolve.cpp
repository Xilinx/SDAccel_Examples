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
// Convolve Example
#define FILTER_WIDTH 11
#define FILTER_HEIGHT 11

#define IMAGE_WIDTH 1024
#define IMAGE_HEIGHT 1024

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>

// OpenCV includes
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

// XCL Helper Library
#include <xcl2.hpp>

short getAbsMax(cv::Mat mat, size_t rows, size_t cols) {
    short max = 0;

    for(size_t r = 0; r < rows; r++) {
        for(size_t c = 0; c < cols; c++) {
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

    for(size_t r = 0; r < rows; r++) {
        for(size_t c = 0; c < cols; c++) {
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

    for(size_t r = 0; r < rows; r++) {
        for(size_t c = 0; c < cols; c++) {
            txtFile >> mat.at<float>(r,c);
        }
    }

    return mat;
}

int main(int argc, char* argv[]) {
    cl_int err;
    cl::Event event;

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

    std::cout << "Reading inputs..." << std::endl;
    cv::Mat input  = readTxtFile(inputFileName, IMAGE_HEIGHT, IMAGE_WIDTH);
    cv::Mat coef   = readTxtFile(coefFileName, FILTER_HEIGHT, FILTER_WIDTH);

    input /= 32;
    coef *= 1;

    std::vector<double, aligned_allocator<double>> vecInput;
    vecInput.assign((double*)input.datastart, (double*)input.dataend);
    std::vector<double, aligned_allocator<double>> vecOutput(vecInput.size());

    std::cout << "Calculating Max Energy..." << std::endl;
    short inputMax = getAbsMax(input, IMAGE_HEIGHT, IMAGE_WIDTH);
    short coefMax  = getAbsMax(coef, FILTER_HEIGHT, FILTER_WIDTH);

    std::cout << "inputBits = " << ceil(log2(inputMax)) << " coefMax = " << ceil(log2(coefMax)) << std::endl;
    long long max_bits = (long long) inputMax * coefMax * FILTER_HEIGHT * FILTER_WIDTH;
    cv::Mat output(IMAGE_HEIGHT, IMAGE_WIDTH, CV_16S);
    output.reshape(0);

    std::cout << "Max Energy = " << ceil(log2(max_bits)) + 1 << " Bits" << std::endl;

// OPENCL HOST CODE AREA START
    // get_xil_devices() is a utility API which will find the Xilinx
    // platforms and will return list of devices connected to Xilinx platform
    std::vector<cl::Device> devices = xcl::get_xil_devices();
    cl::Device device = devices[0];

    std::cout << "Creating Context..." <<std::endl;
    OCL_CHECK(err, cl::Context context (device, NULL, NULL, NULL, &err));
    OCL_CHECK(err, cl::CommandQueue q (context, device, CL_QUEUE_PROFILING_ENABLE, &err));
    OCL_CHECK(err, std::string device_name = device.getInfo<CL_DEVICE_NAME>(&err));

    // find_binary_file() is a utility API which will search the xclbin file for
    // targeted mode (sw_emu/hw_emu/hw) and for targeted platforms.
    std::string binaryFile = xcl::find_binary_file(device_name, "krnl_convolve");

    // import_binary_file() ia a utility API which will load the binaryFile
    // and will return Binaries.
    cl::Program::Binaries bins = xcl::import_binary_file(binaryFile);
    devices.resize(1);
    OCL_CHECK(err, cl::Program program (context, devices, bins, NULL, &err));
    OCL_CHECK(err, cl::Kernel krnl_convolve(program, "krnl_convolve", &err));

    // Allocate Buffer in Global Memory
    // Buffers are allocated using CL_MEM_USE_HOST_PTR for efficient memory and
    // Device-to-host communication
    std::cout << "Creating Buffers..." <<std::endl;
    OCL_CHECK(err, cl::Buffer devCoef(context, CL_MEM_COPY_HOST_PTR | CL_MEM_READ_ONLY,
            ((FILTER_HEIGHT*FILTER_WIDTH-1)/32 + 1)*sizeof(cl_uint16), coef.data, &err));
    OCL_CHECK(err, cl::Buffer devInput(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY,
            ((IMAGE_HEIGHT*IMAGE_WIDTH-1)/32 + 1)*sizeof(cl_uint16), vecInput.data(), &err));
    OCL_CHECK(err, cl::Buffer devOutput(context, CL_MEM_USE_HOST_PTR | CL_MEM_WRITE_ONLY,
            ((IMAGE_HEIGHT*IMAGE_WIDTH-1)/32 + 1)*sizeof(cl_uint16), vecOutput.data(), &err));

    // Copy input data to device global memory
    std::cout << "Copying data..." << std::endl;
    OCL_CHECK(err, err = q.enqueueMigrateMemObjects({devCoef, devInput}, 0/*0 means from host*/));

    std::cout << "Setting Arguments..." << std::endl;
    OCL_CHECK(err, err = krnl_convolve.setArg(0, devCoef));
    OCL_CHECK(err, err = krnl_convolve.setArg(1, devInput));
    OCL_CHECK(err, err = krnl_convolve.setArg(2, devOutput));
    
    // Launch the Kernel
    // For HLS kernels global and local size is always (1,1,1). So, it is recommended
    // to always use enqueueTask() for invoking HLS kernel
    std::cout << "Launching Kernel..." << std::endl;
    OCL_CHECK(err, err = q.enqueueTask(krnl_convolve, NULL, &event));

    // Copy Result from Device Global Memory to Host Local Memory
    std::cout << "Getting Results..." << std::endl;
    OCL_CHECK(err, err = q.enqueueMigrateMemObjects({devOutput}, CL_MIGRATE_MEM_OBJECT_HOST));
    OCL_CHECK(err, err = q.finish());
    uint64_t nstimestart, nstimeend;
    OCL_CHECK(err, err = event.getProfilingInfo<uint64_t>(CL_PROFILING_COMMAND_START,&nstimestart));
    OCL_CHECK(err, err = event.getProfilingInfo<uint64_t>(CL_PROFILING_COMMAND_END,&nstimeend));

    auto duration = nstimeend-nstimestart;

    std::cout << "Kernel Duration: " << duration << " ns" <<std::endl;
//OPENCL HOST CODE AREA ENDS

    std::memcpy(output.data, vecOutput.data(), vecOutput.size()*sizeof(double));

    short outputMax  = getAbsMax(output, IMAGE_HEIGHT, IMAGE_WIDTH);
    std::cout << "outputBits = " << ceil(log2(outputMax)) << std::endl;

    cv::imwrite("input.bmp", input);
    cv::imwrite("output.bmp", output);
    cv::imwrite("coef.bmp", coef);

    if(validate) {
        std::cout << "Validate" << std::endl;
        std::string goldenFileName(argv[3]);
        cv::Mat golden  = readFloatTxtFile(goldenFileName, IMAGE_HEIGHT, IMAGE_WIDTH);

        cv::imwrite("golden.bmp", golden);
    }

    std::cout << "Completed Successfully" << std::endl;
    return EXIT_SUCCESS;
}

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

//OpenCV includes
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

//OpenCL includes
#include "xcl2.hpp"
#include "equalizer.h"

#include <vector>

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        std::cout << "Usage: " << argv[0] <<" <input_image>" << std::endl;
        return -1;
    }

    //Read the input image
    std::cout << "Reading input image..." << std::endl;
    const char* inputFilename = argv[1];

    cv::Mat inputImageRaw;

    inputImageRaw = cv::imread(inputFilename);

    if(!inputImageRaw.data)
    {
        std::cout << "ERROR: Image file not found" << std::endl;
        return -1;
    }
    
    //Convert BGR Image into Gray Image
    cv::cvtColor(inputImageRaw,inputImageRaw,CV_BGR2GRAY);

    cv::Mat inputImage;
    inputImageRaw.convertTo(inputImage, CV_16U, 255);

	size_t image_size_bytes = sizeof(unsigned short) * IMAGE_WIDTH_PIXELS * IMAGE_HEIGHT_PIXELS;
	cl_int err;
    // The get_xil_devices will return vector of Xilinx Devices
    std::vector<cl::Device> devices = xcl::get_xil_devices();
    cl::Device device = devices[0];
    
    //Creating Context and Command Queue for selected Device
    OCL_CHECK(err, cl::Context context(device, NULL, NULL, NULL, &err));
    OCL_CHECK(err, cl::CommandQueue q(context, device, CL_QUEUE_PROFILING_ENABLE, &err));
    OCL_CHECK(err, std::string device_name = device.getInfo<CL_DEVICE_NAME>(&err));
    std::cout << "Found Device=" << device_name.c_str() << std::endl;

    //import_binary() command will find the OpenCL binary file
    std::string xclBinaryFile = xcl::find_binary_file(device_name, "krnl_equalizer");
    cl::Program::Binaries bins  = xcl::import_binary_file(xclBinaryFile);
    devices.resize(1);
    OCL_CHECK(err, cl::Program program(context, devices, bins, NULL, &err));
    
    //Getting kernel from program
    OCL_CHECK(err, cl::Kernel krnl(program,"krnl_equalizer", &err));

    std::cout << "Image Size: " << inputImage.cols << "x" << inputImage.rows << std::endl;
    assert(inputImage.cols == IMAGE_WIDTH_PIXELS);
    assert(inputImage.rows == IMAGE_HEIGHT_PIXELS);
    
    std::vector<unsigned short,aligned_allocator<unsigned short>> eqimage(image_size_bytes, 16);
    std::vector<unsigned short,aligned_allocator<unsigned short>> image(image_size_bytes, 16);
    
    for(int i = 0; i < IMAGE_HEIGHT_PIXELS/32; i++) {
    	for(int j = 0; j < IMAGE_WIDTH_PIXELS; j++) {
            for(int k = 0; k < 32; k++) {
               image[i*IMAGE_WIDTH_PIXELS*32 + j*32 + k] = inputImage.at<ushort>(i*32 + k,j);
            }
        }
    }

    // These commands will allocate memory(Buffer) on the FPGA.
    OCL_CHECK(err, cl::Buffer mem_image(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY,
            image_size_bytes, image.data(),&err));

    OCL_CHECK(err, cl::Buffer mem_eqimage(context, CL_MEM_USE_HOST_PTR | CL_MEM_WRITE_ONLY,
            image_size_bytes, eqimage.data(), &err));
    
    //Separate Read/write Buffer vector is needed to migrate data between host/device
    std::vector<cl::Memory> inBufVec, outBufVec;
    inBufVec.push_back(mem_image);
    outBufVec.push_back(mem_eqimage);


    /* Copy image to memory */
    OCL_CHECK(err, err = q.enqueueMigrateMemObjects(inBufVec,0/* 0 means from host*/));
    
    //set the kernel Arguments
    int narg=0;
    OCL_CHECK(err, err = krnl.setArg(narg++,mem_image));
    OCL_CHECK(err, err = krnl.setArg(narg++,mem_eqimage));

    //Launch the Kernel
    cl::Event event;
    OCL_CHECK(err, err = q.enqueueTask(krnl, NULL, &event));
    
    uint64_t nstimestart, nstimeend;
    
    /* Copy image to mat */
    cv::Mat result_eq;
    result_eq.create(inputImage.rows,inputImage.cols,CV_16U);
	OCL_CHECK(err, err = q.enqueueMigrateMemObjects(outBufVec,CL_MIGRATE_MEM_OBJECT_HOST));
    q.finish();

    OCL_CHECK(err, err = event.getProfilingInfo<uint64_t>(CL_PROFILING_COMMAND_START,&nstimestart));
    OCL_CHECK(err, err = event.getProfilingInfo<uint64_t>(CL_PROFILING_COMMAND_END,&nstimeend));
    auto duration = nstimeend-nstimestart;

    for(int i = 0; i < IMAGE_HEIGHT_PIXELS/32; i++) {
        for(int j = 0; j < IMAGE_WIDTH_PIXELS; j++) {
            for(int k = 0; k < 32; k++) {
                result_eq.at<ushort>(i*32 + k, j) = eqimage[i*IMAGE_WIDTH_PIXELS*32 + j*32 + k];
            }
        }
    }

    std::cout << "Kernel Duration: " << duration << " ns" << std::endl;

    std::string outFilename = std::string("out.bmp");

    std::cout << "Writing Image to " << outFilename << std::endl;
    cv::imwrite(outFilename.c_str(), result_eq);

    return 0;
}


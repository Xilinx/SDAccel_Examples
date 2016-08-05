/*******************************************************************************
Vendor: Xilinx
Associated Filename: equalizer.cpp
Purpose: SDAccel histogram equalization example
Revision History: December 6, 2015

*******************************************************************************
Copyright (C) 2015 XILINX, Inc.

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

//OpenCV includes
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

//OpenCL includes
#include <xcl.h>
#include <equalizer.h>

int main(int argc, char* argv[])
{
    if(argc != 3)
    {
        std::cout << "Usage: " << argv[0] <<" <xclbin> <input_image>" << std::endl;
        return -1;
    }

    //Read the input image
    std::cout << "Reading input image..." << std::endl;
    const char* inputFilename = argv[2];
    const char* xclbinFilename = argv[1];

    cv::Mat inputImageRaw;

    inputImageRaw = cv::imread(inputFilename);

    if(!inputImageRaw.data)
    {
        std::cout << "ERROR: Image file not found" << std::endl;
        return -1;
    }

    cv::cvtColor(inputImageRaw,inputImageRaw,CV_BGR2GRAY);

    cv::Mat inputImage;
    inputImageRaw.convertTo(inputImage, CV_16U, 255);

// OPENCL HOST CODE AREA START
    xcl_world world;
    cl_kernel krnl;

    if(strstr(argv[1], ".xclbin") != NULL) {
        world = xcl_world_single(CL_DEVICE_TYPE_ACCELERATOR);
        krnl  = xcl_import_binary(world, xclbinFilename, "krnl_equalizer");
    } else {
        world = xcl_world_single(CL_DEVICE_TYPE_CPU);
        krnl  = xcl_import_source(world, xclbinFilename, "krnl_equalizer");
    }

    std::cout << "Image Size: " << inputImage.cols << "x" << inputImage.rows << std::endl;

    assert(inputImage.cols == IMAGE_WIDTH_PIXELS);
    assert(inputImage.rows == IMAGE_HEIGHT_PIXELS);

    size_t image_size_bytes = sizeof(unsigned short) * IMAGE_WIDTH_PIXELS * IMAGE_HEIGHT_PIXELS;
    cl_mem mem_image   = xcl_malloc(world, CL_MEM_READ_ONLY, image_size_bytes);
    cl_mem mem_eqimage = xcl_malloc(world, CL_MEM_WRITE_ONLY, image_size_bytes);

    unsigned short *image = (unsigned short*) malloc(sizeof(unsigned short) * IMAGE_WIDTH_PIXELS * IMAGE_HEIGHT_PIXELS);
    for(int i = 0; i < IMAGE_HEIGHT_PIXELS/32; i++) {
        for(int j = 0; j < IMAGE_WIDTH_PIXELS; j++) {
            for(int k = 0; k < 32; k++) {
                image[i*IMAGE_WIDTH_PIXELS*32 + j*32 + k] = inputImage.at<ushort>(i*32 + k,j);
            }
        }
    }

    /* Copy image to memory */
    xcl_memcpy_to_device(world, mem_image, image, image_size_bytes);
    free(image);

    clSetKernelArg(krnl, 0, sizeof(cl_mem), &mem_image);
    clSetKernelArg(krnl, 1, sizeof(cl_mem), &mem_eqimage);

    unsigned long duration = xcl_run_kernel3d(world, krnl, 1, 1, 1);

    unsigned short *eqimage = (unsigned short*) malloc(sizeof(unsigned short) * IMAGE_WIDTH_PIXELS * IMAGE_HEIGHT_PIXELS);

     /* Copy image to mat */
    cv::Mat result_eq;
    result_eq.create(inputImage.rows,inputImage.cols,CV_16U);
    xcl_memcpy_from_device(world, eqimage, mem_eqimage, image_size_bytes);

    for(int i = 0; i < IMAGE_HEIGHT_PIXELS/32; i++) {
        for(int j = 0; j < IMAGE_WIDTH_PIXELS; j++) {
            for(int k = 0; k < 32; k++) {
                result_eq.at<ushort>(i*32 + k, j) = eqimage[i*IMAGE_WIDTH_PIXELS*32 + j*32 + k];
            }
        }
    }
    free(eqimage);

    clReleaseMemObject(mem_image);
    clReleaseMemObject(mem_eqimage);
    clReleaseKernel(krnl);
    xcl_release_world(world);

    std::cout << "Kernel Duration: " << duration << " ns" << std::endl;

		
	//on jenkins we can not open a display 
	/*
    cv::namedWindow("Image");
    cv::imshow("Image",result_eq);
    cv::waitKey(0);
	*/

    return 0;
}

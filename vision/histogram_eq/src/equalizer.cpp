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
#include "xcl.h"
#include "equalizer.h"

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

    cv::cvtColor(inputImageRaw,inputImageRaw,CV_BGR2GRAY);

    cv::Mat inputImage;
    inputImageRaw.convertTo(inputImage, CV_16U, 255);

    xcl_world world = xcl_world_single();
    cl_program program  = xcl_import_binary(world, "krnl_equalizer");
    cl_kernel krnl = xcl_get_kernel(program, "krnl_equalizer");

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
    clReleaseProgram(program);
    xcl_release_world(world);

    std::cout << "Kernel Duration: " << duration << " ns" << std::endl;

    std::string outFilename = std::string("out.bmp");

    std::cout << "Writing Image to " << outFilename << std::endl;
    cv::imwrite(outFilename.c_str(), result_eq);

    return 0;
}

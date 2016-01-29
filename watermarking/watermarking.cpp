/*******************************************************************************
Vendor: Xilinx
Associated Filename: watermarking.cpp
Purpose: SDAccel watermarking example
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

#include <CL/cl.h>

#include "bitmap.h"
#include "oclHelper.h"

void checkErrorStatus(cl_int error, const char* message)
{
  if (error != CL_SUCCESS)
  {
    printf("%s\n", message) ;
    printf("%s\n", oclErrorCode(error)) ;
    exit(0) ;
  }
}

int main(int argc, char* argv[])
{
  if (argc != 3)
  {
    printf("Usage: %s <input bitmap> <xclbin>\n", argv[0]) ;
    return -1 ;
  }
  
  // Read the bit map file into memory and allocate memory for the
  //  final image
  std::cout << "Reading input image...\n";
  const char* bitmapFilename = argv[1] ;
  int width = 128 ; // Default size
  int height = 128 ; // Default size

  BitmapInterface image(bitmapFilename) ;
  
  bool result = image.readBitmapFile() ;
  if (!result)
  {
    return -1 ;
  }

  width = image.getWidth() ;
  height = image.getHeight() ;

  int* outImage = (int*)(malloc(image.numPixels() * sizeof(int))) ;

  if (outImage == NULL)
  {
    fprintf(stderr, "Unable to allocate host memory!\n") ;
    return 0 ;
  }

  // Set up OpenCL hardware and software constructs
  std::cout << "Setting up OpenCL hardware and software...\n";
  cl_int err = 0 ;
  const char* xclbinFilename = argv[2] ;

  oclHardware hardware = getOclHardware(CL_DEVICE_TYPE_ACCELERATOR) ;
  oclSoftware software ;

  memset(&software, 0, sizeof(oclSoftware)) ;
  strcpy(software.mKernelName, "applyWatermark") ;
  strcpy(software.mFileName, xclbinFilename) ;
  strcpy(software.mCompileOptions, "-g -Wall") ;

  getOclSoftware(software, hardware) ;

  software.mKernel = clCreateKernel(software.mProgram,
				    software.mKernelName,
				    &err) ;
  checkErrorStatus(err, "Unable to create kernel!") ;

  // Initialize OpenCL buffers with pointers to allocated memory
  cl_mem imageToDevice ;
  cl_mem imageFromDevice ;

  imageToDevice = clCreateBuffer(hardware.mContext,
				 CL_MEM_READ_ONLY | CL_MEM_USE_HOST_PTR,
				 image.numPixels() * sizeof(int),
				 image.bitmap(),
				 &err) ;
  checkErrorStatus(err, "Unable to create read buffer") ;

  imageFromDevice = clCreateBuffer(hardware.mContext,
				   CL_MEM_WRITE_ONLY | CL_MEM_USE_HOST_PTR,
				   image.numPixels() * sizeof(int),
				   outImage,
				   &err) ;
  checkErrorStatus(err, "Unable to create write buffer") ;

  // Send the image to the hardware
  std::cout << "Writing input image to buffer...\n";
  err = clEnqueueWriteBuffer(hardware.mQueue,
			     imageToDevice,
			     CL_TRUE,
			     0,
			     image.numPixels() * sizeof(int),
			     image.bitmap(),
			     0,
			     NULL,
			     NULL) ;

  checkErrorStatus(err, "Unable to enqueue write buffer") ;

  // Pass the arguments to the kernel
  std::cout << "Setting arguments and enqueueing kernel...\n";
  err = clSetKernelArg(software.mKernel, 0, sizeof(cl_mem), &imageToDevice) ;
  checkErrorStatus(err, "Unable to set argument 0") ;
  err = clSetKernelArg(software.mKernel, 1, sizeof(cl_mem), &imageFromDevice) ;
  checkErrorStatus(err, "Unable to set argument 1") ;
  //err = clSetKernelArg(software.mKernel, 2, sizeof(int), &width) ;
  //checkErrorStatus(err, "Unable to set argument 2") ;
 // err = clSetKernelArg(software.mKernel, 3, sizeof(int), &height) ;
 // checkErrorStatus(err, "Unable to set argument 3") ;

  // Define iteration space 
  size_t globalSize[3] = { 1, 1, 1 } ;
  size_t localSize[3] = { 1, 1, 1} ;
  cl_event seq_complete ;

  // Actually start the kernels on the hardware
  err = clEnqueueNDRangeKernel(hardware.mQueue,
			       software.mKernel,
			       1,
			       NULL,
			       globalSize,
			       localSize,
			       0,
			       NULL,
			       &seq_complete) ;

  checkErrorStatus(err, "Unable to enqueue NDRange") ;

  // Wait for kernel to finish
  clWaitForEvents(1, &seq_complete) ;

  // Read back the image from the kernel
  std::cout << "Reading output image and writing to file...\n";
  err = clEnqueueReadBuffer(hardware.mQueue,
			    imageFromDevice,
			    CL_TRUE,
			    0,
			    image.numPixels() * sizeof(int),
			    outImage,
			    0,
			    NULL,
			    &seq_complete) ;

  checkErrorStatus(err, "Unable to enqueue read buffer") ;

  clWaitForEvents(1, &seq_complete) ;

  // Write the final image to disk
  image.writeBitmapFile(outImage) ;
  free(outImage) ;

  release(software) ;
  release(hardware) ;
  return 0 ;
}

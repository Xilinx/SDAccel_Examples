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
#include <CL/cl.h>
#include "bitmap.h"
#include "oclHelper.h"

#define X_SIZE  512
#define Y_SIZE 512

void checkErrorStatus(cl_int error, const char* message)
{
  if (error != CL_SUCCESS)
  {
    printf("%s\n", message) ;
    printf("%s\n", oclErrorCode(error)) ;
    exit(0) ;
  }
}

int main(int argc, char** argv)
{

if (argc != 2)
  {
    printf("Usage: %s <xclbin>\n", argv[0]) ;
    return -1 ;
}
   
   FILE *input_file;
   unsigned short    input_image[Y_SIZE][X_SIZE];

   FILE             *output_file;

   unsigned short    output_image[Y_SIZE][X_SIZE];

 // Read the bit map file into memory and allocate memory for the
  //  final image
  std::cout << "Reading input image...\n";

 // Load the input image
   input_file = fopen("data/CT-MONO2-16-brain.raw", "rb");
   if (!input_file)
   {
      printf("Error: Unable to open input image file!\n");
      return 1;
   }
   
   printf("\n");
   printf("   Reading RAW Image\n");
   size_t items_read = fread(input_image, sizeof input_image, 1, input_file);
   printf("   Bytes read = %d\n\n", (int)(items_read * sizeof input_image));

  // Set up OpenCL hardware and software constructs
  std::cout << "Setting up OpenCL hardware and software...\n";
  cl_int err = 0 ;
  const char* xclbinFilename = argv[1] ;

  oclHardware hardware = getOclHardware(CL_DEVICE_TYPE_ACCELERATOR) ;
  oclSoftware software ;

  memset(&software, 0, sizeof(oclSoftware)) ;
  strcpy(software.mKernelName, "affine_kernel") ;
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
				 CL_MEM_READ_ONLY, 
				 sizeof(input_image), 
				 NULL,
				 &err) ;
  checkErrorStatus(err, "Unable to create read buffer") ;

  imageFromDevice = clCreateBuffer(hardware.mContext,
				   CL_MEM_WRITE_ONLY, 
				   sizeof(output_image), 
				   NULL,
				   &err) ;
  checkErrorStatus(err, "Unable to create write buffer") ;

  // Send the image to the hardware
  std::cout << "Writing input image to buffer...\n";
  err = clEnqueueWriteBuffer(hardware.mQueue,
			     imageToDevice,
			     CL_TRUE,
			     0,
			     sizeof input_image, 
			     (void *)(&input_image),
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
			    sizeof output_image, 
			    (void *)(&output_image),
			    0,
			    NULL,
			    &seq_complete) ;

  checkErrorStatus(err, "Unable to enqueue read buffer") ;

  clWaitForEvents(1, &seq_complete) ;

  output_file = fopen("transformed_image.raw", "wb");
  if (!output_file)
   {
      printf("Error: Unable to open output image file!\n");
      return 1;
   }

   printf("   Writing RAW Image\n");
   size_t items_written = fwrite(output_image, sizeof output_image, 1, output_file);
   printf("   Bytes written = %d\n\n", (int)(items_read * sizeof output_image));

  release(software) ;
  release(hardware) ;
  return 0 ;
}

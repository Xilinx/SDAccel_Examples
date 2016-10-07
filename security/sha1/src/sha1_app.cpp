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
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <streambuf>

#include "sha1_app.h"

using namespace std;

sha1Runner::sha1Runner(cl_context context, cl_command_queue command_queue, cl_kernel kernel) {
  mContext = context;
  mCommandQueue = command_queue;
  mKernel = kernel;

  int err;
  mDevGBuf = clCreateBuffer(mContext, CL_MEM_READ_ONLY, 64*CHANNELS*BLOCKS, NULL, &err);
  if (err != CL_SUCCESS) {
    std::cout << "ERROR: Could not create buffer" << std::endl;
    abort();
  }

  mDevGState = clCreateBuffer(mContext, CL_MEM_READ_WRITE, 64*CHANNELS, NULL, &err);
  if (err != CL_SUCCESS) {
    std::cout << "ERROR: Could not create buffer" << std::endl;
    abort();
  }
}

sha1Runner::~sha1Runner() {
}

cl_event sha1Runner::run(const unsigned int *buf, unsigned int *mds) {

  size_t w[] = {1};
  size_t g[] = {1};

  int err;

  err = clEnqueueWriteBuffer(mCommandQueue, mDevGBuf, CL_FALSE, 0,
                             CHANNELS*BLOCKS*64, buf,
                             0, NULL, &mEvents[0]);
  if(err != CL_SUCCESS) {
    std::cout << "Error: failed to Enqueue Write buffer! " <<  err << std::endl;
    abort();
  }

  err = clEnqueueWriteBuffer(mCommandQueue, mDevGState, CL_FALSE, 0,
                            CHANNELS*64, mds,
                            0, NULL, &mEvents[1]);
  if(err != CL_SUCCESS) {
    std::cout << "Error: failed to Enqueue Write buffer! " <<  err << std::endl;
    abort();
  }

  err = clSetKernelArg(mKernel, 0, sizeof(cl_mem), &mDevGBuf);
  if(err != CL_SUCCESS) {
    printf("Error: Failed to set kernel arg\n");
    abort();
  }

  err = clSetKernelArg(mKernel, 1, sizeof(cl_mem), &mDevGState);
  if(err != CL_SUCCESS) {
    printf("Error: Failed to set kernel arg\n");
    abort();
  }

  cout << "calling: clEnqueueNDRangeKernel" << endl;
  err = clEnqueueNDRangeKernel(mCommandQueue, mKernel,
                               1, NULL, g, w, 2, &mEvents[0], &mEvents[2]);
  if(err != CL_SUCCESS) {
    std::cout << "Error: failed to execute kernel! " <<  err << std::endl;
    abort();
  }

  err = clEnqueueReadBuffer(mCommandQueue, mDevGState, CL_FALSE, 0,
                            CHANNELS*64, mds,
                            1, &mEvents[2], &mEvents[3]);
  if(err != CL_SUCCESS) {
    std::cout << "Error: failed to Enqueue Read Buffer! " <<  err << std::endl;
    abort();
  }

  return mEvents[3];
}

sha1::sha1(std::string Vendor, std::string Device, const char* filename) {
  getVendorPlatform(Vendor);
  getDeviceIdByName(Device);
  createContext();
  createProgram(filename);
  createCommandQueue();
  createKernelByName("dev_sha1_update");
}

sha1::~sha1() {
  clReleaseKernel(mKernel);
  releaseCommandQueue();
  clReleaseProgram(mProgram);
  clReleaseContext(mContext);
}

void sha1::getVendorPlatform(std::string Vendor) {
  int err;
  cl_uint num_platforms;

  err = clGetPlatformIDs(0, NULL, &num_platforms);
  if (err != CL_SUCCESS) {
    std::cout << "ERROR: no platforms available or OpenCL install broken" << std::endl;
    abort();
  }

  cl_platform_id *platform_ids = (cl_platform_id *) malloc(sizeof(cl_platform_id) * num_platforms);
  if (platform_ids == NULL) {
    std::cout << "ERROR: Out of Memory" << std::endl;
    abort();
  }

  err = clGetPlatformIDs(num_platforms, platform_ids, NULL);
  if (err != CL_SUCCESS) {
    std::cout << "ERROR: Failed to find an OpenCL platform!" << std::endl;
    abort();
  }

  cl_platform_id platform_id = NULL;

  for(unsigned i = 0; i < num_platforms; i++) {
    size_t vendor_size;

    err = clGetPlatformInfo(platform_ids[i], CL_PLATFORM_VENDOR, 0, NULL, &vendor_size);
    if (err != CL_SUCCESS) {
      std::cout << "ERROR: Failed to get platform vendor size" << std::endl;
      abort();
    }

    char* vendor = (char*) malloc(sizeof(char) * vendor_size);
    if (vendor == NULL) {
      std::cout << "ERROR: Out of Memory" << std::endl;
      abort();
    }

    err = clGetPlatformInfo(platform_ids[i], CL_PLATFORM_VENDOR, vendor_size, vendor, NULL);
    if (err != CL_SUCCESS) {
      std::cout << "ERROR: Failed to get platform vendor" << std::endl;
      abort();
    }

    std::string cur_vendor = std::string(vendor);
    if (cur_vendor.find(Vendor) != std::string::npos )
    {
      cout << "platform vendor set to: " << cur_vendor << endl;
      free(vendor);
      platform_id = platform_ids[i];
      break;
    }

    free(vendor);
  }

  free(platform_ids);

  mPlatformId = platform_id;
}

void sha1::getDeviceIdByName(std::string Device) {
  int err;

  cl_uint num_device_ids;
  err = clGetDeviceIDs(mPlatformId, CL_DEVICE_TYPE_ALL,
                       0, NULL, &num_device_ids);
  if (err != CL_SUCCESS) {
    std::cout << "ERROR: Failed to get number of device ids" << std::endl;
    abort();
  }

  cl_device_id *device_ids = (cl_device_id*) malloc(sizeof(cl_device_id) * num_device_ids);
  if (device_ids == NULL) {
    std::cout << "ERROR: Out of Memory" << std::endl;
    abort();
  }

  err = clGetDeviceIDs(mPlatformId, CL_DEVICE_TYPE_ALL,
                       num_device_ids, device_ids, NULL);
  if (err != CL_SUCCESS) {
    std::cout << "ERROR: Failed to get device ids" << std::endl;
    abort();
  }

  cout << "Found: " << num_device_ids << " devices" << endl;
  for(unsigned i = 0; i < num_device_ids; i++) {
    size_t device_size;
    err = clGetDeviceInfo(device_ids[i], CL_DEVICE_NAME, 0, NULL, &device_size);
    if(err != CL_SUCCESS) {
      std::cout << "ERROR: Faild to get device name size" << std::endl;
      abort();
    }

    char *device = (char*) malloc(sizeof(char) * device_size);
    if(device == NULL) {
      std::cout << "ERROR: Out of Memory" << std::endl;
      abort();
    }

    err = clGetDeviceInfo(device_ids[i], CL_DEVICE_NAME, device_size, device, NULL);
    if(err != CL_SUCCESS) {
      std::cout << "ERROR: Faild to get device name size" << std::endl;
      abort();
    }

    std::string cur_device = std::string(device);
    std::cout << "Dev:   " << Device << std::endl;
    std::cout << "Match: " << std::string(device) << std::endl;
    if (cur_device.find(Device) != std::string::npos ) {
      mDeviceId = device_ids[i];
    }
    free(device);
  }

  free(device_ids);
}

void sha1::createContext() {
  int err;

  mContext = clCreateContext(0, 1, &mDeviceId,
                             NULL, NULL, &err);
  if (err != CL_SUCCESS) {
    std::cout << "ERROR: Failed to create a compute context" << std::endl;
    abort();
  }
}

void sha1::createProgram(const char* filename) {

  std::ifstream fs(filename, std::ifstream::binary);

  if(!fs) {
    std::cout << "ERROR: Could not open " << filename << std::endl;
    abort();
  }

  std::string bin;

  fs.seekg(0, std::ios::end);
  bin.reserve(1+fs.tellg());
  fs.seekg(0, std::ios::beg);

  bin.assign(std::istreambuf_iterator<char>(fs),
                std::istreambuf_iterator<char>());

  bin += '\0';

  size_t bin_size = bin.length()-1;
  const unsigned char* bin_ptr  = (const unsigned char*) bin.c_str();

  int err;
  std::string filename_string(filename);
  if(filename_string.find(".xclbin") != std::string::npos) {
    cout << "calling: clCreateProgramWithBinary" << endl;
    mProgram = clCreateProgramWithBinary(mContext, 1, &mDeviceId,
                                        &bin_size, &bin_ptr,
                                        NULL, &err);
    if ( !mProgram || err != CL_SUCCESS) {
      std::cout << "Error: Failed to create compute program from binary: " << err << std::endl;
      abort();
    }
  } else {
    cout << "calling: clCreateProgramWithSource" << endl;
    mProgram = clCreateProgramWithSource(mContext, 1,
                                        (const char**) &bin_ptr,
                                        NULL, &err);
    if ( !mProgram || err != CL_SUCCESS) {
      std::cout << "Error: Failed to create compute program from source: " << err << std::endl;
      abort();
    }
  }

  err = clBuildProgram(mProgram, 0, NULL, NULL, NULL, NULL);
  if (err != CL_SUCCESS) {
    std::cout << "Error: Failed to build program executable!" << std::endl;

    size_t len;
    /* Only look at the build log for the first device the others should be the same */
    err = clGetProgramBuildInfo(mProgram, mDeviceId, CL_PROGRAM_BUILD_LOG, 0, NULL, &len);
    if (err != CL_SUCCESS) {
      std::cout << "ERROR: could not get build log size" << std::endl;
      abort();
    }

    char *buffer = (char*) malloc(sizeof(char) * len);

    err = clGetProgramBuildInfo(mProgram, mDeviceId, CL_PROGRAM_BUILD_LOG,
                                len, buffer, NULL);
    if (err != CL_SUCCESS) {
       std::cout << "ERROR: could not get build log" << std::endl;
       abort();
    }

    std::cout << buffer << std::endl;

    free(buffer);

    abort();
  }
}

void sha1::createKernelByName(std::string kernel_name) {
  int err;

  mKernel = clCreateKernel(mProgram, kernel_name.c_str(), &err);
  if (!mKernel || err != CL_SUCCESS) {
    std::cout << "Error: Failed to create kernel for " << kernel_name << ": " << err << std::endl;
    abort();
  }
}

void sha1::createCommandQueue() {
  int err;

  mCommandQueue = clCreateCommandQueue(mContext, mDeviceId,
                                       CL_QUEUE_PROFILING_ENABLE | CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE,
                                       &err);
  if (err != CL_SUCCESS) {
    std::cout << "Error: Failed to create a command queue!" << std::endl;
    abort();
  }
}

void sha1::releaseCommandQueue() {
  clReleaseCommandQueue(mCommandQueue);
}

sha1Runner sha1::createRunner() {
  sha1Runner runner(mContext, mCommandQueue, mKernel);

  return runner;
}

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <streambuf>

#include "clSha1.h"

clSha1Runner::clSha1Runner(cl_context context, cl_command_queue command_queue, cl_kernel kernel) {
  mContext = context;
  mCommandQueue = command_queue;
  mKernel = kernel;

  mDone = true;

  int err;
  mDevGBuf = clCreateBuffer(mContext, CL_MEM_READ_ONLY, CHANNELS*BLOCKS*64L, NULL, &err);
  if (err != CL_SUCCESS) {
    std::cout << "ERROR: Could not create buffer" << std::endl;
    abort();
  }

  mDevGState = clCreateBuffer(mContext, CL_MEM_READ_WRITE, 64*CHANNELS, NULL, &err);
  if (err != CL_SUCCESS) {
    std::cout << "ERROR: Could not create buffer" << std::endl;
    abort();
  }

  for(size_t i = 0; i < 4; i++) {
    mEventStats[i].cnt = 0;
    mEventStats[i].max = 0;
  }
}

clSha1Runner::~clSha1Runner() {

  int err;

  err = clReleaseMemObject(mDevGBuf);
  if(err != CL_SUCCESS) {
    std::cout << "ERROR: Could not release Mem object mDevGbuf!" << std::endl;
    abort();
  }

  err = clReleaseMemObject(mDevGState);
  if(err != CL_SUCCESS) {
    std::cout << "ERROR: Could not release Mem object mDevGState!" << std::endl;
    abort();
  }

}

void CL_CALLBACK clSha1Runner_callback(cl_event event, cl_int status, void *user_data) {
	bool *mDone = (bool*) user_data;

	*mDone = true;
}

cl_event clSha1Runner::run(const uint32_t *buf, uint32_t *mds) {

  mDone = false;

  size_t w[] = {1};
  size_t g[] = {1};

  int err;

  err = clEnqueueWriteBuffer(mCommandQueue, mDevGBuf, CL_FALSE, 0,
                             CHANNELS*BLOCKS*64L, buf,
                             0, NULL, &mEvents[0]);
  if(err != CL_SUCCESS) {
    std::cout << "Error: failed to Enqueue Write buffer mDevGBuf! " <<  err << std::endl;
    abort();
  }

  err = clEnqueueWriteBuffer(mCommandQueue, mDevGState, CL_FALSE, 0,
                            CHANNELS*64, mds,
                            0, NULL, &mEvents[1]);
  if(err != CL_SUCCESS) {
    std::cout << "Error: failed to Enqueue Write buffer mDevGState! " <<  err << std::endl;
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

  err = clSetEventCallback(mEvents[3], CL_COMPLETE, clSha1Runner_callback, &mDone);
  if(err != CL_SUCCESS) {
    std::cout << "ERROR: Could not create callback" << std::endl;
    abort();
  }

  return mEvents[3];
}

bool clSha1Runner::isDone() {
  return mDone;
}

void clSha1Runner::initStats(size_t size) {
  for(size_t i = 0; i < 4; i++) {
    mEventStats[i].ent = (unsigned long*) malloc(sizeof(unsigned long) * size);
    if (mEventStats[i].ent == NULL) {
      std::cout << "ERROR: out of memory" << std::endl;
      abort();
    }

    mEventStats[i].cnt = 0;
    mEventStats[i].max = size;
  }
}

void clSha1Runner::updateStats() {
  for(size_t i = 0 ; i < 4; i++) {
    size_t cnt = mEventStats[i].cnt;
    size_t max = mEventStats[i].max;
    if (cnt < max) {
      unsigned long start, stop;
      clGetEventProfilingInfo(mEvents[i], CL_PROFILING_COMMAND_START,
                              sizeof(unsigned long), &start, NULL);
      clGetEventProfilingInfo(mEvents[i], CL_PROFILING_COMMAND_END,
                              sizeof(unsigned long), &stop, NULL);

      if (stop > start) {
        mEventStats[i].ent[cnt] = stop - start;
      } else {
        std::cout << "overflow" << std::endl;
        mEventStats[i].ent[cnt] = 0xFFFFFFFF - start  +  stop + 1;
      }

      //std::cout << start << " " << stop << " ";

      //mEventStats[i].ent[cnt] = 0xFFFFFFFF;

      mEventStats[i].cnt = cnt + 1;

      //double dur = mEventStats[i].ent[cnt] * 1.0;
      //dur /= 1000.0;  // us
      //dur /= 1000.0;  // ms

      //std::cout << dur << " ms ";
    }
  }
  //std::cout << std::endl;
}

void clSha1Runner::getStats(unsigned long min[4], unsigned long max[4], unsigned long avg[4], size_t cnt[4]) {
  for(size_t i = 0; i < 4; i++) {
    unsigned long long tot;

    min[i] = max[i] = tot = mEventStats[i].ent[0];

    for(size_t j = 1; j < mEventStats[i].cnt; j++) {
      unsigned long val = mEventStats[i].ent[j];
      if (val > max[i]) {
        max[i] = val;
      }
      if (val < min[i]) {
        min[i] = val;
      }
      tot += val;
    }
    if (mEventStats[i].cnt != 0) {
      avg[i] = tot / mEventStats[i].cnt;
      cnt[i] = mEventStats[i].cnt;
    } else {
      avg[i] = 0;
      cnt[i] = 0;
    }
  }
}

clSha1::clSha1(std::string Vendor, std::string Device, const char* filename) {
  getVendorPlatform(Vendor);
  getDeviceIdByName(Device);
  createContext();
  createProgram(filename);
  createCommandQueue();
  createKernelByName("dev_sha1_update");
}

clSha1::~clSha1() {
  clReleaseKernel(mKernel);
  releaseCommandQueue();
  clReleaseProgram(mProgram);
  clReleaseContext(mContext);
}

void clSha1::getVendorPlatform(std::string Vendor) {
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

    if(Vendor == std::string(vendor)) {
      free(vendor);
      platform_id = platform_ids[i];
      break;
    }

    free(vendor);
  }

  free(platform_ids);

  mPlatformId = platform_id;
}

void clSha1::getDeviceIdByName(std::string Device) {
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

    std::cout << "Dev:   " << Device << std::endl;
    std::cout << "Match: " << std::string(device) << std::endl;
    if (Device == std::string(device)) {
      mDeviceId = device_ids[i];
    }
    free(device);
  }

  free(device_ids);
}

void clSha1::createContext() {
  int err;

  mContext = clCreateContext(0, 1, &mDeviceId,
                             NULL, NULL, &err);
  if (err != CL_SUCCESS) {
    std::cout << "ERROR: Failed to create a compute context" << std::endl;
    abort();
  }
}

void clSha1::createProgram(const char* filename) {

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
    mProgram = clCreateProgramWithBinary(mContext, 1, &mDeviceId,
                                        &bin_size, &bin_ptr,
                                        NULL, &err);
    if ( !mProgram || err != CL_SUCCESS) {
      std::cout << "Error: Failed to create compute program from binary: " << err << std::endl;
      abort();
    }
  } else {
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

void clSha1::createKernelByName(std::string kernel_name) {
  int err;

  mKernel = clCreateKernel(mProgram, kernel_name.c_str(), &err);
  if (!mKernel || err != CL_SUCCESS) {
    std::cout << "Error: Failed to create kernel for " << kernel_name << ": " << err << std::endl;
    abort();
  }
}

void clSha1::createCommandQueue() {
  int err;

  mCommandQueue = clCreateCommandQueue(mContext, mDeviceId,
                                       CL_QUEUE_PROFILING_ENABLE | CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE,
                                       &err);
  if (err != CL_SUCCESS) {
    std::cout << "Error: Failed to create a command queue!" << std::endl;
    abort();
  }
}

void clSha1::releaseCommandQueue() {
  clReleaseCommandQueue(mCommandQueue);
}

clSha1Runner *clSha1::createRunner() {
  clSha1Runner *runner = new clSha1Runner(mContext, mCommandQueue, mKernel);

  return runner;
}

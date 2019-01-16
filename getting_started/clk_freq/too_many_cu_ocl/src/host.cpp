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

/*******************************************************************************
Description: 

    SDx Vector Addition example to show case effectiveness of using a heavier 
    single compute unit to achieve better performance than using lighter
    multiple compute units.

*******************************************************************************/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <unistd.h>

//OpenCL utility layer include
#include "xcl2.hpp"

#define DATA_SIZE 81920 
#define WORK_GROUP 8 
#define WORK_ITEM_PER_GROUP 1


bool run_opencl_vadd(
  std::vector<cl::Device> &devices,
  cl::CommandQueue &q,
  cl::Context &context,
  std::string &device_name,
  bool good,
  int size,
  std::vector<int, aligned_allocator<int>> &source_in1,
  std::vector<int, aligned_allocator<int>> &source_in2,
  std::vector<int, aligned_allocator<int>> &source_hw_results
)
{
    std::string binaryFile;
    cl_int err;

    if(good){
        binaryFile = xcl::find_binary_file(device_name,"vadd_GOOD");
    }
    else{
        binaryFile = xcl::find_binary_file(device_name,"vadd_BAD");
        if(access(binaryFile.c_str(), R_OK) != 0) {
            std::cout << "WARNING: vadd_BAD xclbin not built" << std::endl;
            return false;
        }
    }

    cl::Program::Binaries bins = xcl::import_binary_file(binaryFile);
    devices.resize(1);
    OCL_CHECK(err, cl::Program program(context, devices, bins, NULL, &err));
    cl::Kernel krnl_vector_add;
    if (good) {
    OCL_CHECK(err, krnl_vector_add = cl::Kernel(program,"vadd_GOOD", &err));
    }
    else {
    OCL_CHECK(err, krnl_vector_add = cl::Kernel(program, "vadd_BAD", &err));
    }

    std::cout << "Starting " << (good ? "GOOD" : "BAD") << " Kernel" << std::endl;

    size_t vector_size_bytes = sizeof(int) * size;
   
    //Allocate Buffer in Global Memory    
    std::vector<cl::Memory> inBufVec, outBufVec;
    OCL_CHECK(err, cl::Buffer buffer_in1 (context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY,
                            vector_size_bytes,source_in1.data(), &err));
    OCL_CHECK(err, cl::Buffer buffer_in2(context, CL_MEM_USE_HOST_PTR | CL_MEM_WRITE_ONLY,
            vector_size_bytes,source_in2.data(), &err));
    OCL_CHECK(err, cl::Buffer buffer_output(context, CL_MEM_USE_HOST_PTR | CL_MEM_WRITE_ONLY,
            vector_size_bytes,source_hw_results.data(), &err));

    inBufVec.push_back(buffer_in1);
    inBufVec.push_back(buffer_in2);
    outBufVec.push_back(buffer_output);

    //Copy input data to device global memory
    OCL_CHECK(err, err = q.enqueueMigrateMemObjects(inBufVec,0/* 0 means from host*/));

    auto krnl_vadd
        = cl::KernelFunctor<cl::Buffer&,cl::Buffer&,cl::Buffer&,int>(krnl_vector_add);

    if(good){
        std::cout << "Launching Kernel...." << std::endl;

        //Launch the Kernel
        krnl_vadd(cl::EnqueueArgs(q, cl::NDRange(1,1,1), cl::NDRange(1,1,1)),
            buffer_in1,buffer_in2,buffer_output, size);
        OCL_CHECK(err, err = q.finish());
        std::cout << "Kernel Execution Finished...." << std::endl;

        //Copy Result from Device Global Memory to Host Local Memory 
        OCL_CHECK(err, err = q.enqueueMigrateMemObjects(outBufVec,CL_MIGRATE_MEM_OBJECT_HOST));
        OCL_CHECK(err, err = q.finish());
    }

    else{
        // Launch 8 threads for the bad case for the whole data set
        // 8 Compute Units are created and one CU is allocated per thread
        
        //Launch the Kernel  
        krnl_vadd(cl::EnqueueArgs(q, cl::NDRange(WORK_GROUP,1,1), cl::NDRange(1,1,1)),
              buffer_in1,buffer_in2,buffer_output, size);
        OCL_CHECK(err, err = q.finish());
        std::cout << "Kernel Execution Finished...." << std::endl;

        //Copy Result from Device Global Memory to Host Local Memory
        OCL_CHECK(err, err = q.enqueueMigrateMemObjects(outBufVec,CL_MIGRATE_MEM_OBJECT_HOST));
        OCL_CHECK(err, err = q.finish());
    }
    return true;
}

int main(int argc, char** argv)
{
    //Amount of vector data to be processed by kernel
    int size = DATA_SIZE;
    cl_int err;

    std::vector<int, aligned_allocator<int>> source_in1(size);
    std::vector<int, aligned_allocator<int>> source_in2(size);
    std::vector<int, aligned_allocator<int>> source_hw_good_results(size);
    std::vector<int, aligned_allocator<int>> source_hw_bad_results(size);
    std::vector<int, aligned_allocator<int>> source_sw_results(size);

    // Create the test data and Software Result 
    for(int i = 0 ; i < DATA_SIZE ; i++){
        source_in1[i] = i;
        source_in2[i] = i * i;
        source_sw_results[i] = i * i + i;
        source_hw_good_results[i] = 0;
        source_hw_bad_results[i] = 0;
    }

//OPENCL HOST CODE AREA START
    //Create Program and Kernels
    std::vector<cl::Device> devices = xcl::get_xil_devices();
    cl::Device device = devices[0];

    OCL_CHECK(err, cl::Context context(device, NULL, NULL, NULL, &err));
    OCL_CHECK(err, cl::CommandQueue q(context, device, CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE | CL_QUEUE_PROFILING_ENABLE));
    std::string device_name = device.getInfo<CL_DEVICE_NAME>();

    run_opencl_vadd(devices,q,context,device_name, true, size, source_in1, source_in2, source_hw_good_results);
    bool bad_return = run_opencl_vadd(devices,q,context,device_name, false, size, source_in1, source_in2, source_hw_bad_results);

//OPENCL HOST CODE AREA END
    
    // Compare the results of the Device to the simulation
    bool match = true;
    for (int i = 0 ; i < DATA_SIZE ; i++){
        if (source_hw_good_results[i] != source_sw_results[i]){
            std::cout << "Error: Result mismatch in vadd_GOOD" << std::endl;
            std::cout << "i = " << i << " CPU result = " << source_sw_results[i]
                << " Device result = " << source_hw_good_results[i] << std::endl;
            match = false;
            break;
        }
        if(bad_return){
            if (source_hw_bad_results[i] != source_sw_results[i]){
                std::cout << "Error: Result mismatch in vadd_BAD" << std::endl;
                std::cout << "i = " << i << " CPU result = " << source_sw_results[i]
                     << " Device result = " << source_hw_bad_results[i] << std::endl;
                match = false;
                break;
            }
        }
    }
 
    std::cout << "TEST " << (match ? "PASSED" : "FAILED") << std::endl;
    return (match ? EXIT_SUCCESS :  EXIT_FAILURE);
}

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

#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <iostream>
#include <vector>

#include "xcl2.hpp"

//Number of HBM Banks required
#define MAX_HBM_BANKCOUNT 32
#define BANK_NAME(n) n | XCL_MEM_TOPOLOGY

bool verify (std::vector<int,aligned_allocator<int>> &source_sw_results, 
             std::vector<int,aligned_allocator<int>> &source_hw_results, unsigned int size) {
    bool check = true;
    for (size_t i = 0 ; i < size ; i++){
        if (source_hw_results[i] != source_sw_results[i]){
            std::cout << "Error: Result mismatch" << std::endl;
            std::cout << "i = " << i << " CPU result = " << source_sw_results[i]
                << " Device result = " << source_hw_results[i] << std::endl;
            check = false;
            break;
        }
    }
    return check;
}


double run_cu(cl::Context &context, cl::CommandQueue &q, cl::Kernel &kernel, cl_mem_ext_ptr_t &inBufExt1, 
                cl_mem_ext_ptr_t &inBufExt2, cl_mem_ext_ptr_t &outBufExt, unsigned int size) {
    cl_int err;

    // These commands will allocate memory on the FPGA. The cl::Buffer objects can
    // be used to reference the memory locations on the device.   
    //Creating Buffers
    OCL_CHECK(err, cl::Buffer buffer_input1 = cl::Buffer(context, CL_MEM_READ_ONLY | CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR, sizeof(uint32_t)*size, &inBufExt1, &err));
    OCL_CHECK(err, cl::Buffer buffer_input2 = cl::Buffer(context, CL_MEM_READ_ONLY | CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR, sizeof(uint32_t)*size, &inBufExt2, &err));
    OCL_CHECK(err, cl::Buffer buffer_output = cl::Buffer(context, CL_MEM_WRITE_ONLY | CL_MEM_EXT_PTR_XILINX | CL_MEM_USE_HOST_PTR, sizeof(uint32_t)*size, &outBufExt, &err));

    //Setting the kernel Arguments
    OCL_CHECK(err, err = (kernel).setArg(0, buffer_input1));
    OCL_CHECK(err, err = (kernel).setArg(1, buffer_input2));
    OCL_CHECK(err, err = (kernel).setArg(2, buffer_output));
    OCL_CHECK(err, err = (kernel).setArg(3, size));

    OCL_CHECK(err, err = q.enqueueMigrateMemObjects({buffer_input1, buffer_input2},0/* 0 means from host*/));
    q.finish();

    std::chrono::duration<double> kernel_time(0);

    auto kernel_start = std::chrono::high_resolution_clock::now();    
    OCL_CHECK(err, err = q.enqueueTask(kernel));
    q.finish();
    auto kernel_end = std::chrono::high_resolution_clock::now();
    
    kernel_time = std::chrono::duration<double>(kernel_end - kernel_start);
 
    OCL_CHECK(err, err = q.enqueueMigrateMemObjects({buffer_output},CL_MIGRATE_MEM_OBJECT_HOST));
    q.finish();

    return kernel_time.count();
}

int main(int argc, char* argv[]) {
    if (argc != 2 ) {
        printf("Usage: %s <XCLBIN> \n", argv[0]) ;
        return -1 ;
    }
    
    unsigned int dataSize;
    const char *xcl_emu = getenv("XCL_EMULATION_MODE");
    if(xcl_emu && (!strcmp(xcl_emu, "sw_emu") || !strcmp(xcl_emu, "hw_emu")) ) {
        //Original dataset is reduced for faster execution of hardware emulation flow
        dataSize = 1024;
    }
    else {
        dataSize = 64*1024*1024;
    }

    std::string binaryFile = argv[1];
    cl_int err;
    unsigned fileBufSize;
  
    std::vector<int,aligned_allocator<int>> source_in1(dataSize);
    std::vector<int,aligned_allocator<int>> source_in2(dataSize);
    std::vector<int,aligned_allocator<int>> source_hw_results(dataSize);
    std::vector<int,aligned_allocator<int>> source_sw_results(dataSize);    

    // Create the test data 
    for(size_t i = 0 ; i < dataSize ; i++){
        source_in1[i] = rand() % dataSize;
        source_in2[i] = rand() % dataSize;
        source_sw_results[i] = source_in1[i] + source_in2[i];
        source_hw_results[i] = 0;
    }

    int bank[MAX_HBM_BANKCOUNT] = {
	    BANK_NAME(0), BANK_NAME(1), BANK_NAME(2), BANK_NAME(3),
	    BANK_NAME(4), BANK_NAME(5), BANK_NAME(6), BANK_NAME(7),
        BANK_NAME(8), BANK_NAME(9), BANK_NAME(10), BANK_NAME(11),
        BANK_NAME(12), BANK_NAME(13), BANK_NAME(14), BANK_NAME(15),
        BANK_NAME(16), BANK_NAME(17), BANK_NAME(18), BANK_NAME(19),
        BANK_NAME(20), BANK_NAME(21), BANK_NAME(22), BANK_NAME(23),
        BANK_NAME(24), BANK_NAME(25), BANK_NAME(26), BANK_NAME(27),
        BANK_NAME(28), BANK_NAME(29), BANK_NAME(30), BANK_NAME(31)
    };
  
// OPENCL HOST CODE AREA START
    // The get_xil_devices will return vector of Xilinx Devices
    std::vector<cl::Device> devices = xcl::get_xil_devices();
    cl::Device device = devices[0];

    // Creating Context and Command Queue for selected Device
    OCL_CHECK(err, cl::Context context(device, NULL, NULL, NULL, &err));
    OCL_CHECK(err, cl::CommandQueue q(context, device, CL_QUEUE_PROFILING_ENABLE, &err));
  
    std::string device_name = device.getInfo<CL_DEVICE_NAME>();
    std::cout << "Found Device=" << device_name.c_str() << std::endl;

    // read_binary_file() command will find the OpenCL binary file created using the 
    // xocc compiler load into OpenCL Binary and return pointer to file buffer.
    char* fileBuf = xcl::read_binary_file(binaryFile, fileBufSize);
  
    cl::Program::Binaries bins{{fileBuf, fileBufSize}};
    devices.resize(1);
    OCL_CHECK(err, cl::Program program(context, devices, bins, NULL, &err));
    
    OCL_CHECK(err, cl::Kernel kernel_vadd(program, "krnl_vadd", &err));
    
    // For Allocating Buffer to specific Global Memory Bank, user has to use cl_mem_ext_ptr_t
    // and provide the Banks
    cl_mem_ext_ptr_t inBufExt1, inBufExt2, outBufExt;

    inBufExt1.obj = source_in1.data();
    inBufExt1.param = 0;
    inBufExt2.obj = source_in2.data();
    inBufExt2.param = 0;
    outBufExt.obj = source_hw_results.data();    
    outBufExt.param = 0;
    
    double res_time = 0;
    bool match = true;
    double result = 0;

// CASE 1 
    if(xcl_emu && (!strcmp(xcl_emu, "sw_emu") || !strcmp(xcl_emu, "hw_emu")) ) {
        dataSize = 1024;
    }
    else {
        dataSize = 16*1024*1024;
    }

    inBufExt1.flags = bank[0];
    inBufExt2.flags = bank[0];
    outBufExt.flags = bank[0];

    res_time = run_cu(context, q, kernel_vadd, inBufExt1, inBufExt2, outBufExt, dataSize);
    match = verify(source_sw_results, source_hw_results, dataSize);

    result = (3*dataSize*sizeof(uint32_t))/(1024*1024*1024*res_time);
    std::cout << "\n|----------------------------------------------------------------|\n" << std::endl;
    std::cout << "      [CASE 1] Total Performance = " << result << " GBps" << std::endl;
    std::cout << "\n|----------------------------------------------------------------|\n" << std::endl;

// CASE 2
    if(xcl_emu && (!strcmp(xcl_emu, "sw_emu") || !strcmp(xcl_emu, "hw_emu")) ) {
        dataSize = 1024;
    }
    else {
        dataSize = 64*1024*1024;
    }

    inBufExt1.flags = bank[1];
    inBufExt2.flags = bank[2];
    outBufExt.flags = bank[3];
    
    res_time = run_cu(context, q, kernel_vadd, inBufExt1, inBufExt2, outBufExt, dataSize);
    match = verify(source_sw_results, source_hw_results, dataSize);

    result = (3*dataSize*sizeof(uint32_t))/(1024*1024*1024*res_time);
    std::cout << "\n|----------------------------------------------------------------|\n" << std::endl;
    std::cout << "      [CASE 2] Total Performance = " << result << " GBps " << std::endl;
    std::cout << "\n|----------------------------------------------------------------|\n" << std::endl;

//OPENCL HOST CODE AREA ENDS

    delete[] fileBuf;

    std::cout << (match ? "TEST PASSED" : "TEST FAILED") << std::endl;
    return (match ? EXIT_SUCCESS : EXIT_FAILURE);
}

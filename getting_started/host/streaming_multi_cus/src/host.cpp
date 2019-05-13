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
*******************************************************************/
#include <iostream>
#include <cstring>
#include <thread>
#include <unistd.h>
#include <string>
#include <vector>
#include <algorithm>

// This extension file is required for stream APIs
#include "CL/cl_ext_xilinx.h"
// This file is required for OpenCL C++ wrapper APIs
#include "xcl2.hpp"

// Declaration of custom stream APIs that binds to Xilinx Streaming APIs.
decltype(&clCreateStream) xcl::Stream::createStream = nullptr;
decltype(&clReleaseStream) xcl::Stream::releaseStream = nullptr;
decltype(&clReadStream) xcl::Stream::readStream = nullptr;
decltype(&clWriteStream) xcl::Stream::writeStream = nullptr;
decltype(&clPollStreams) xcl::Stream::pollStreams = nullptr;

auto constexpr c_test_size = 1024 * 1024 * 1024; //1 GB data
auto constexpr NCU = 4;

////////////////////RESET FUNCTION//////////////////////////////////
int reset(int* a, int*b, int* sw_results, int* hw_results, unsigned int size)
{
    //Fill the input vectors with data
    for(size_t i = 0; i < size; i++)
    {
        a[i] = rand() % size;
        b[i] = rand() % size;
        hw_results[i] = 0;
        sw_results[i] = a[i] + b[i];
    }
    return 0;
}
////////MAIN FUNCTION//////////
int main(int argc, char** argv)
{
    unsigned int size = c_test_size;
    
    if(xcl::is_hw_emulation()){
        size = 4096; // 4KB for HW emulation
    }else if (xcl::is_emulation()){
        size = 2 * 1024 * 1024 ; // 4MB for sw emulation
    }
    
    // I/O Data Vectors
    std::vector<int,aligned_allocator<int>> h_a(size);
    std::vector<int,aligned_allocator<int>> h_b(size);
    std::vector<int,aligned_allocator<int>> hw_results(size);
    std::vector<int> sw_results(size);

    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <XCLBIN File>" << std::endl;
		return EXIT_FAILURE;
	}
    
    std::string binaryFile = argv[1];
    std::cout << "\n Vector Addition of elements " << size << std::endl;

    //Bytes per CU Stream
    int vector_size_bytes = sizeof(int) * size/NCU;

    // OpenCL Host Code Begins
    cl_int err;
    unsigned fileBufSize;

    //Fill the input vectors with data
    for (unsigned int i = 0; i < size; i++)
    {
        h_a[i] = rand() % size;
        h_b[i] = rand() % size;
        hw_results[i] = 0;
        sw_results[i] = h_a[i] + h_b[i];
    }

    int no_of_elem = size/NCU;

    std::vector<int,aligned_allocator<int>> h_a_sp[NCU];
    std::vector<int,aligned_allocator<int>> h_b_sp[NCU];
    std::vector<int,aligned_allocator<int>> hw_results_sp[NCU];
    std::vector<int,aligned_allocator<int>> sw_results_sp[NCU];

    // Dividing  the data-set for multiple CUs.
    for (int i=0; i < NCU; i++) { 
        auto start_h_a = std::next(h_a.cbegin(), i*no_of_elem);
        auto end_h_a   = std::next(h_a.cbegin(), i*no_of_elem + no_of_elem);
        h_a_sp[i].resize(no_of_elem);
        std::copy(start_h_a, end_h_a, h_a_sp[i].begin());

        auto start_h_b = std::next(h_b.cbegin(), i*no_of_elem);
        auto end_h_b   = std::next(h_b.cbegin(), i*no_of_elem + no_of_elem);
        h_b_sp[i].resize(no_of_elem);
        std::copy(start_h_b, end_h_b, h_b_sp[i].begin());

        auto start_hw_results = std::next(hw_results.cbegin(), i*no_of_elem);
        auto end_hw_results   = std::next(hw_results.cbegin(), i*no_of_elem + no_of_elem);
        hw_results_sp[i].resize(no_of_elem);
        std::copy(start_hw_results, end_hw_results, hw_results_sp[i].begin());

        auto start_sw_results = std::next(sw_results.cbegin(), i*no_of_elem);
        auto end_sw_results   = std::next(sw_results.cbegin(), i*no_of_elem + no_of_elem);
        sw_results_sp[i].resize(no_of_elem);
        std::copy(start_sw_results, end_sw_results, sw_results_sp[i].begin());
    }
   
    // get_xil_devices() is a utility API which will find the xilinx
    // platforms and will return list of devices connected to Xilinx platform
    auto devices = xcl::get_xil_devices();
    
    // Selecting the first available Xilinx device
    cl::Device device = devices[0];

    cl_platform_id platform_id = device.getInfo<CL_DEVICE_PLATFORM>(&err); 

    //Initialization of streaming class is needed before using it.
    xcl::Stream::init(platform_id);

    // Creating Context
    OCL_CHECK(err, cl::Context context(device, NULL, NULL, NULL, &err));

    // Creating Command Queue
    OCL_CHECK(err, cl::CommandQueue q(context, device, CL_QUEUE_PROFILING_ENABLE | CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE, &err));
    OCL_CHECK(err, std::string device_name = device.getInfo<CL_DEVICE_NAME>(&err));

    // read_binary_file() is a utility API which will load the binaryFile
    // and will return the pointer to file buffer.
    auto fileBuf = xcl::read_binary_file(binaryFile, fileBufSize);
    cl::Program::Binaries bins{ { fileBuf, fileBufSize } };
    devices.resize(1);

    // Creating Program
    OCL_CHECK(err, cl::Program program(context, devices, bins, NULL, &err));

    // Creating Kernel
    std::string cu_id;
    std::string krnl_name = "krnl_stream_vadd";
    std::vector<cl::Kernel> krnls(NCU);
    for (int i = 0; i < NCU; i++) {
        cu_id = std::to_string(i+1);
        std::string krnl_name_full = krnl_name + ":{" + krnl_name + "_" + cu_id + "}";
        printf("Creating a kernel [%s] for CU(%d)\n", krnl_name_full.c_str(), i);
        OCL_CHECK(err, krnls[i] = cl::Kernel(program, krnl_name_full.c_str(), &err));
    }

    // Streams
    std::array<cl_stream, NCU> write_stream_a;
    std::array<cl_stream, NCU> write_stream_b;
    std::array<cl_stream, NCU> read_stream;
    
    cl_int ret;

    for (int i = 0; i < NCU; i++) {
        // Device Connection specification of the stream through extension pointer  
        cl_mem_ext_ptr_t ext;
        ext.param = krnls[i].get();
        ext.obj = NULL;
        // The .flag should be used to denote the kernel argument
        // Create write stream for argument 0 and 1 of kernel
        std::cout << "\n Creating Stream for CU: " << i;
        ext.flags = 0;
        OCL_CHECK(ret, write_stream_a[i] = xcl::Stream::createStream(device.get(), CL_STREAM_WRITE_ONLY, CL_STREAM, &ext, &ret));
        ext.flags = 1;
        OCL_CHECK(ret, write_stream_b[i] = xcl::Stream::createStream(device.get(), CL_STREAM_WRITE_ONLY, CL_STREAM, &ext, &ret));

        //Create read stream for argument 2 of kernel
        ext.flags = 2;
        OCL_CHECK(ret, read_stream[i] = xcl::Stream::createStream(device.get(), CL_STREAM_READ_ONLY, CL_STREAM, &ext, &ret));
    }

    // Launch the Kernel
    for (int i = 0; i < NCU; i++) {
        std::cout << "\n Enqueuing Kernel " << i;
        OCL_CHECK(err, err = q.enqueueTask(krnls[i]));
    }
    
    // Initiating the READ and WRITE transfer
    for (int i = 0; i < NCU; i++) {
        cl_stream_xfer_req rd_req {0};
        cl_stream_xfer_req wr_req {0};

        rd_req.flags = CL_STREAM_EOT | CL_STREAM_NONBLOCKING;
        wr_req.flags = CL_STREAM_EOT | CL_STREAM_NONBLOCKING;
        
        auto write_tag_a = "write_a_" + std::to_string(i);
        wr_req.priv_data = (void*)write_tag_a.c_str();

        std::cout << "\n Writing Stream write_stream_a[" << i << "]";
        OCL_CHECK(ret, xcl::Stream::writeStream(write_stream_a[i], h_a_sp[i].data(), vector_size_bytes, &wr_req, &ret));

        auto write_tag_b = "write_b_" + std::to_string(i);
        wr_req.priv_data = (void*)write_tag_b.c_str();

        std::cout << "\n Writing Stream write_stream_b[" << i << "]";
        OCL_CHECK(ret, xcl::Stream::writeStream(write_stream_b[i], h_b_sp[i].data(), vector_size_bytes, &wr_req, &ret));

        auto read_tag = "read_" + std::to_string(i);
        rd_req.priv_data = (void*)read_tag.c_str();

        std::cout << "\n Reading Stream read_stream[" << i << "]";
        OCL_CHECK(ret, xcl::Stream::readStream(read_stream[i], hw_results_sp[i].data(), vector_size_bytes, &rd_req, &ret));
    }

    // Sync for the async streaming 
    int num_compl = 3 * NCU;
    
    // Checking the request completions
    cl_streams_poll_req_completions* poll_req;
    poll_req = (cl_streams_poll_req_completions*)malloc(sizeof(cl_streams_poll_req_completions)*num_compl);
    memset(poll_req, 0, sizeof(cl_streams_poll_req_completions)*num_compl);
    printf("\n clPollStreams for (%d) events (CU: %d, axis_in: 2, axis_out: 1)\n", num_compl, NCU);
    OCL_CHECK(ret, xcl::Stream::pollStreams(device.get(), poll_req, num_compl, num_compl, &num_compl, 50000, &ret));

    // Compare the device results with software results
    bool match = true;
    for (int i = 0; i < NCU; i++) {
        for (int j = 0; j < no_of_elem; j++) {
            if (sw_results_sp[i][j] != hw_results_sp[i][j]) {
            match = false;
            std::cout << "\n Compute Unit: " << i << "Failed for element " << j << " : " << sw_results_sp[i][j] << " and " << hw_results_sp[i][j] << std::endl;
            break;
        }
      }
    }
        
    // Releasing all OpenCL objects
    q.finish();
    for (int i = 0; i < NCU; i++)
    {
        xcl::Stream::releaseStream(read_stream[i]);
        xcl::Stream::releaseStream(write_stream_a[i]);
        xcl::Stream::releaseStream(write_stream_b[i]);
    }

    std::cout << "\n TEST " << (match ? "PASSED" : "FAILED") << std::endl;
    return (match ? EXIT_SUCCESS : EXIT_FAILURE);
}
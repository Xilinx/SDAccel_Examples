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

#include "xcl2.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "CL/cl_ext_xilinx.h"

auto constexpr DATA_SIZE = 4096;
auto constexpr NCU = 4;

int main(int argc, char** argv) {
    
    int size;
    size = DATA_SIZE;
    
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << "XCLBIN File" << std::endl;
        return EXIT_FAILURE;
    }

    std::string binaryFile = argv[1];
    std::cout << "\n Vector Addition of elements " << size << std::endl;

    //Bytes per CU Stream
    int vector_size_bytes = sizeof(int) * size/NCU;

    cl_int err;
    unsigned fileBufSize = 100;

    std::vector<int,aligned_allocator<int>> h_a(size);
    std::vector<int,aligned_allocator<int>> h_b(size);
    std::vector<int,aligned_allocator<int>> hw_results(size);
    std::vector<int,aligned_allocator<int>> sw_results(size);

    //Fill the input vectors with data
    for (int i = 0; i < size; i++)
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
   
    auto devices = xcl::get_xil_devices();
    cl::Device device = devices[0];

    OCL_CHECK(err, cl::Context context(device, NULL, NULL, NULL, &err));
    OCL_CHECK(err, cl::CommandQueue q(context, device, CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE, &err));
    OCL_CHECK(err, std::string device_name = device.getInfo<CL_DEVICE_NAME>(&err));

    auto fileBuf = xcl::read_binary_file(binaryFile, fileBufSize);
    cl::Program::Binaries bins{ { fileBuf, fileBufSize } };
    devices.resize(1);
    OCL_CHECK(err, cl::Program program(context, devices, bins, NULL, &err));
    OCL_CHECK(err, cl::Kernel krnl_vadd(program, "krnl_vadd"));

    // Streams
    std::array<cl_stream, NCU> write_stream_a;
    std::array<cl_stream, NCU> write_stream_b;
    std::array<cl_stream, NCU> read_stream;

    // Device Connection specification of the stream through extension pointer  
    cl_int ret;
    cl_mem_ext_ptr_t ext;
    ext.param = krnl_vadd.get();
    ext.obj = NULL;

    for (int i = 0; i < NCU; i++) {
        // The .flag should be used to denote the kernel argument
        // Create write stream for argument 0 and 1 of kernel
        std::cout << "\n Creating Stream for CU: " << i;
        ext.flags = 0;
        OCL_CHECK(ret, write_stream_a[i] = clCreateStream(device.get(), CL_STREAM_WRITE_ONLY, CL_STREAM, &ext, &ret));
        ext.flags = 1;
        OCL_CHECK(ret, write_stream_b[i] = clCreateStream(device.get(), CL_STREAM_WRITE_ONLY, CL_STREAM, &ext, &ret));

        //Create read stream for argument 2 of kernel
        ext.flags = 2;
        OCL_CHECK(ret, read_stream[i] = clCreateStream(device.get(), CL_STREAM_READ_ONLY, CL_STREAM, &ext, &ret));
    }

    // Launch the Kernel
    for (int i = 0; i < NCU; i++) {
        std::cout << "\n Enqueuing Kernel " << i;
        OCL_CHECK(err, err = q.enqueueTask(krnl_vadd));
    }    

    // Initiating the READ and WRITE transfer
    for (int i = 0; i < NCU; i++) {
        cl_stream_xfer_req rd_req {0};
        cl_stream_xfer_req wr_req {0};

        rd_req.flags = CL_STREAM_EOT;
        wr_req.flags = CL_STREAM_EOT;
        
        auto write_tag_a = "write_a_" + std::to_string(i);
        wr_req.priv_data = (void*)write_tag_a.c_str();

        std::cout << "\n Writing Stream write_stream_a[" << i << "]";
        OCL_CHECK(ret, clWriteStream(write_stream_a[i], h_a_sp[i].data(), vector_size_bytes, &wr_req, &ret));

        auto write_tag_b = "write_b_" + std::to_string(i);
        wr_req.priv_data = (void*)write_tag_b.c_str();

        std::cout << "\n Writing Stream write_stream_b[" << i << "]";
        OCL_CHECK(ret, clWriteStream(write_stream_b[i], h_b_sp[i].data(), vector_size_bytes, &wr_req, &ret));

        auto read_tag = "read_" + std::to_string(i);
        rd_req.priv_data = (void*)read_tag.c_str();

        std::cout << "\n Reading Stream read_stream[" << i << "]";
        OCL_CHECK(ret, clReadStream(read_stream[i], hw_results_sp[i].data(), vector_size_bytes, &rd_req, &ret));

    }

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
    
    for (int i = 0; i < NCU; i++)
    {
        clReleaseStream(read_stream[i]);
        clReleaseStream(write_stream_a[i]);
        clReleaseStream(write_stream_b[i]);
    }

    std::cout << "\n TEST " << (match ? "PASSED" : "FAILED") << std::endl;
    return (match ? EXIT_SUCCESS : EXIT_FAILURE);

}

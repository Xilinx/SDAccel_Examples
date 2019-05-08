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
*/
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

class xdevice_vadd
{
public:
    // OpenCL objects
    cl::Device m_device;
    cl::Context m_context;
    cl::CommandQueue m_q;
    cl::Program m_program;
    cl::Kernel m_krnl_vadd;
    
    // Error Status variable
    cl_int err;
    
    // Constructor
    xdevice_vadd(const char* binaryFile);

    // Application using blocking/non-blocking Stream APIs 
    void run_blocking    (int *A, int* B, int* result, size_t size);
    void run_non_blocking(int *A, int* B, int* result, size_t size);
};

//Constructor
xdevice_vadd::xdevice_vadd(const char* binaryFile){
    unsigned fileBufSize;
    // get_xil_devices() is a utility API which will find the xilinx
    // platforms and will return list of devices connected to Xilinx platform
    auto devices = xcl::get_xil_devices();

    // Selecting the first available Xilinx device
    m_device = devices[0];
    cl_platform_id platform_id = m_device.getInfo<CL_DEVICE_PLATFORM>(&err); 

    //Initialization of streaming class is needed before using it.
    xcl::Stream::init(platform_id);

    // Creating Context
    OCL_CHECK(err, m_context = cl::Context(m_device, NULL, NULL, NULL, &err));

    // Creating Command Queue
    OCL_CHECK(err, m_q = cl::CommandQueue(m_context, m_device, CL_QUEUE_PROFILING_ENABLE, &err));

    // read_binary_file() is a utility API which will load the binaryFile
    // and will return the pointer to file buffer.
    auto fileBuf = xcl::read_binary_file(binaryFile, fileBufSize);

    cl::Program::Binaries bins{{fileBuf, fileBufSize}};
    devices.resize(1);

    // Creating Program
    OCL_CHECK(err, m_program = cl::Program(m_context, devices, bins, NULL, &err));

    // Creating Kernel
    OCL_CHECK(err, m_krnl_vadd = cl::Kernel(m_program, "krnl_stream_vadd", &err));
};

// Application using blocking Stream APIs 
void xdevice_vadd::run_blocking(int* a, int*b, int*results, size_t size)
    {
    // Streams
    // Device Connection specification of the stream through extension pointer
    cl_int ret;
    cl_mem_ext_ptr_t ext;
    ext.param = m_krnl_vadd.get();
    ext.obj = NULL;

    //Create write stream for argument 0 and 1 of kernel
    cl_stream b_write_stream_a, b_write_stream_b;
    ext.flags = 0;
    OCL_CHECK(ret, b_write_stream_a = xcl::Stream::createStream(m_device.get(), CL_STREAM_WRITE_ONLY, CL_STREAM, &ext, &ret));
    ext.flags = 1;
    OCL_CHECK(ret, b_write_stream_b = xcl::Stream::createStream(m_device.get(), CL_STREAM_WRITE_ONLY, CL_STREAM, &ext, &ret));

    //Create read stream for argument 2 of kernel
    cl_stream b_read_stream;
    ext.flags = 2;
    OCL_CHECK(ret, b_read_stream = xcl::Stream::createStream(m_device.get(), CL_STREAM_READ_ONLY, CL_STREAM, &ext, &ret));

    // Launch the Kernel
    OCL_CHECK(err, err = m_q.enqueueTask(m_krnl_vadd));

    // Initiating the WRITE transfer
    cl_stream_xfer_req wr_req {0};

    size_t vector_size_bytes = size * sizeof(int);

    wr_req.flags = CL_STREAM_EOT;
    wr_req.priv_data = (void*)"b_write_a";

    // Thread 1 for writing data to input stream 1 independently in case of default blocking transfers.
    std::thread thr1(xcl::Stream::writeStream, b_write_stream_a, a, vector_size_bytes, &wr_req, &ret);

    wr_req.priv_data = (void*)"b_write_b";
    // Thread 2 for writing data to input stream 2 independently in case of default blocking transfers.
    std::thread thr2(xcl::Stream::writeStream, b_write_stream_b, b, vector_size_bytes, &wr_req, &ret);

    // Initiating the READ transfer
    cl_stream_xfer_req rd_req {0};
    rd_req.flags = CL_STREAM_EOT;
    rd_req.priv_data = (void*)"b_read";
    // Output thread to read the stream data independently in case of default blocking transfers.
    std::thread thr3(xcl::Stream::readStream, b_read_stream, results, vector_size_bytes, &rd_req, &ret);

    // Waiting for all the threads to complete their respective operations.
    thr1.join();
    thr2.join();
    thr3.join();

    // Ensuring all OpenCL objects are released.
    m_q.finish();

    xcl::Stream::releaseStream(b_read_stream);
    xcl::Stream::releaseStream(b_write_stream_a);
    xcl::Stream::releaseStream(b_write_stream_b);
}
    
// Application using non-blocking Stream APIs 
void xdevice_vadd::run_non_blocking(int* a, int*b, int*results, size_t size)
    {
    // Streams
    // Device Connection specification of the stream through extension pointer
    cl_int ret;
    cl_mem_ext_ptr_t ext;
    ext.param = m_krnl_vadd.get();
    ext.obj = NULL;

    //Create write stream for argument 0 and 1 of kernel
    cl_stream nb_write_stream_a, nb_write_stream_b;
    ext.flags = 0;
    OCL_CHECK(ret, nb_write_stream_a = xcl::Stream::createStream(m_device.get(), CL_STREAM_WRITE_ONLY, CL_STREAM, &ext, &ret));
    ext.flags = 1;
    OCL_CHECK(ret, nb_write_stream_b = xcl::Stream::createStream(m_device.get(), CL_STREAM_WRITE_ONLY, CL_STREAM, &ext, &ret));

    //Create read stream for argument 2 of kernel
    cl_stream nb_read_stream;
    ext.flags = 2;
    OCL_CHECK(ret, nb_read_stream = xcl::Stream::createStream(m_device.get(), CL_STREAM_READ_ONLY, CL_STREAM, &ext, &ret));

    // Launch the Kernel
    OCL_CHECK(err, err = m_q.enqueueTask(m_krnl_vadd));

    // Initiating the WRITE transfer
    cl_stream_xfer_req wr_req {0};

    wr_req.flags = CL_STREAM_EOT | CL_STREAM_NONBLOCKING;
    wr_req.priv_data = (void*)"nb_write_a";

    size_t vector_size_bytes = size * sizeof(int);
    // Thread 1 for writing data to input stream 1 independently in case of default blocking transfers.
    OCL_CHECK(ret, xcl::Stream::writeStream(nb_write_stream_a, a, vector_size_bytes, &wr_req, &ret));

    wr_req.priv_data = (void*)"nb_write_b";
    // Thread 2 for writing data to input stream 2 independently in case of default blocking transfers.
    OCL_CHECK(ret, xcl::Stream::writeStream(nb_write_stream_b, b, vector_size_bytes, &wr_req, &ret));

    // Initiating the READ transfer
    cl_stream_xfer_req rd_req {0};
    rd_req.flags = CL_STREAM_EOT | CL_STREAM_NONBLOCKING;
    rd_req.priv_data = (void*)"nb_read";
    // Output thread to read the stream data independently in case of default blocking transfers.
    OCL_CHECK(ret, xcl::Stream::readStream(nb_read_stream, results, vector_size_bytes, &rd_req, &ret));

    // Checking the request completion
    cl_streams_poll_req_completions poll_req[3] {0, 0, 0}; // 3 Requests
    auto num_compl = 3;
    OCL_CHECK(ret, xcl::Stream::pollStreams(m_device.get(), poll_req, 3, 3, &num_compl, 50000, &ret));
    // Blocking API, waits for 2 poll request completion or 50000ms, whichever occurs first.
            
    // Ensuring all OpenCL objects are released.
    m_q.finish();

    xcl::Stream::releaseStream(nb_read_stream);
    xcl::Stream::releaseStream(nb_write_stream_a);
    xcl::Stream::releaseStream(nb_write_stream_b);
}

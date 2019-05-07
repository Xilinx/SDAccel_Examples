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

#define DATA_SIZE 4096 
#define vector_size_bytes sizeof(int) * DATA_SIZE

class xdevice_vadd
{
public:
    // OpenCL objects
    cl::Device device;
    cl::Context context;
    cl::CommandQueue q;
    cl::Program program;
    cl::Kernel krnl;
    
    // Error Status variable
    cl_int err;
    
    // Constructor
    xdevice_vadd(const char* binaryFile){
        unsigned fileBufSize;
        // OPENCL HOST CODE AREA START
        // get_xil_devices() is a utility API which will find the xilinx
        // platforms and will return list of devices connected to Xilinx platform
        auto devices = xcl::get_xil_devices();
        // Selecting the first available Xilinx device
        device = devices[0];

        // Creating Context
        OCL_CHECK(err, context = cl::Context(device, NULL, NULL, NULL, &err));
        // Creating Command Queue
        OCL_CHECK(err, q = cl::CommandQueue(context, device, CL_QUEUE_PROFILING_ENABLE, &err));

        // read_binary_file() is a utility API which will load the binaryFile
        // and will return the pointer to file buffer.
        auto fileBuf = xcl::read_binary_file(binaryFile, fileBufSize);
        cl::Program::Binaries bins{{fileBuf, fileBufSize}};
        devices.resize(1);
        // Creating Program
        OCL_CHECK(err, program = cl::Program(context, devices, bins, NULL, &err));
        // Creating Kernel
        OCL_CHECK(err, krnl = cl::Kernel(program, "krnl_stream_vadd", &err));
    };

    // Application using blocking/non-blocking Stream APIs 
    void run_blocking(int*, int*, int*);
    void run_non_blocking(int*, int*, int*);
};

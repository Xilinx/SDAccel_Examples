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

/*
  Stream_access Host Code
  There are many applications where all of the data cannot reside in an FPGA.
  For example, the data is too big to fit in an FPGA or the data is being
  streamed from a sensor or the network. In these situations data must be
  transferred as chunks from the host memory to FPGA before the computation can be
  performed on FPGA and vice-versa to copy back the result.
  Because PCIe is an full-duplex interconnect, you can transfer data to and from
  the FPGA simultaneously. Xilinx FPGAs can also perform computations during
  these data transfers. Performing all three of these operations at the same
  time allows you to keep the FPGA busy and take full advantage of all of the
  hardware on your system.
  Many OpenCL commands are asynchronous. This means that whenever you call an
  OpenCL function, the function will return before the operation has completed.
  Asynchronous nature of OpenCL allows you to simultaneously perform tasks on
  the host CPU as well as the FPGA.
 */

#include "xcl2.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <CL/cl_ext_xilinx.h>

auto constexpr DATA_SIZE = 4096;

int main(int argc, char** argv){
    
    int size = DATA_SIZE;
    
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << "XCLBIN File" << std::endl;
        return EXIT_FAILURE;
    }

    std::string binaryFile = argv[1];
    std::cout << "\n Vector Addition of elements " << size << std::endl;

    //Allocate memory in Host Memory
    int vector_size_bytes = sizeof(int) * size;
    cl_int err;
    unsigned fileBufSize;

    std::vector<int,aligned_allocator<int>> h_a(vector_size_bytes);
    std::vector<int,aligned_allocator<int>> h_b(vector_size_bytes);
    std::vector<int,aligned_allocator<int>> hw_results(vector_size_bytes);
    std::vector<int,aligned_allocator<int>> sw_results(vector_size_bytes);

    //Fill the input vectors with data
    for(int i = 0; i < size; i++)
    {
        h_a[i] = rand() % size;
        h_b[i] = rand() % size;
        hw_results[i] = 0;
        sw_results[i] = h_a[i] + h_b[i];
    }

    auto devices = xcl::get_xil_devices();
    cl::Device device = devices[0];

    OCL_CHECK(err, cl::Context context(device, NULL, NULL, NULL, &err));
    OCL_CHECK(err, cl::CommandQueue q(context, device, CL_QUEUE_PROFILING_ENABLE, &err));
    OCL_CHECK(err, std::string device_name = device.getInfo<CL_DEVICE_NAME>(&err));

    auto fileBuf = xcl::read_binary_file(binaryFile, fileBufSize);
    cl::Program::Binaries bins{ { fileBuf, fileBufSize } };
    devices.resize(1);
    OCL_CHECK(err, cl::Program program(context, devices, bins, NULL, &err));
    OCL_CHECK(err, cl::Kernel krnl_vadd(program, "krnl_vadd"));

    // Streams
    // Device Connection specification of the stream through extension pointer
    cl_int ret;
    cl_mem_ext_ptr_t ext;
    ext.param = krnl_vadd.get();
    ext.obj = NULL;

    //Create write stream for argument 0 and 1 of kernel
    cl_stream write_stream_a, write_stream_b;
    ext.flags = 0;
    OCL_CHECK(ret, write_stream_a = clCreateStream(device.get(), CL_STREAM_WRITE_ONLY, CL_STREAM, &ext, &ret));
    ext.flags = 1;
    OCL_CHECK(ret, write_stream_b = clCreateStream(device.get(), CL_STREAM_WRITE_ONLY, CL_STREAM, &ext, &ret));

    //Create read stream for argument 2 of kernel
    cl_stream read_stream;
    ext.flags = 2;
    OCL_CHECK(ret, read_stream = clCreateStream(device.get(), CL_STREAM_READ_ONLY, CL_STREAM, &ext, &ret));
    
    // Launch the Kernel
    OCL_CHECK(err, err = q.enqueueTask(krnl_vadd));

    // Initiating the WRITE transfer
    cl_stream_xfer_req wr_req {0};

    wr_req.flags = CL_STREAM_EOT;
    wr_req.priv_data = (void*)"write_a";
    clWriteStream(write_stream_a, h_a.data(), vector_size_bytes, &wr_req, &ret);

    wr_req.priv_data = (void*)"write_b";
    clWriteStream(write_stream_b, h_b.data(), vector_size_bytes, &wr_req, &ret);

    // Initiating the READ transfer
    cl_stream_xfer_req rd_req {0};
    rd_req.flags = CL_STREAM_EOT;
    rd_req.priv_data = (void*)"read";
    clReadStream(read_stream, hw_results.data(), vector_size_bytes, &rd_req, &ret);

    // Compare the device results with software results
    bool match = true;
    for (int i = 0; i < size; i++){
        printf("%d a = %d b = %d \t sw = %d \t hw = %d\n", i, h_a[i], h_b[i], sw_results[i], hw_results[i]);
        if(sw_results[i] != hw_results[i]){
            match = false;
            break;
        }
    }
    
    clReleaseStream(read_stream);
    clReleaseStream(write_stream_a);
    clReleaseStream(write_stream_b);

    std::cout << "TEST " << (match ? "PASSED" : "FAILED") << std::endl;
    return (match ? EXIT_SUCCESS : EXIT_FAILURE);
}

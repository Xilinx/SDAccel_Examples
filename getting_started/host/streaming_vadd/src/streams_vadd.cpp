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
#include "streams_vadd.h"

// Application using blocking Stream APIs 
void xdevice_vadd::run_blocking(int* a, int*b, int*results)
    {
    // Streams
    // Device Connection specification of the stream through extension pointer
    cl_int ret;
    cl_mem_ext_ptr_t ext;
    ext.param = krnl.get();
    ext.obj = NULL;

    //Create write stream for argument 0 and 1 of kernel
    cl_stream b_write_stream_a, b_write_stream_b;
    ext.flags = 0;
    OCL_CHECK(ret, b_write_stream_a = clCreateStream(device.get(), CL_STREAM_WRITE_ONLY, CL_STREAM, &ext, &ret));
    ext.flags = 1;
    OCL_CHECK(ret, b_write_stream_b = clCreateStream(device.get(), CL_STREAM_WRITE_ONLY, CL_STREAM, &ext, &ret));

    //Create read stream for argument 2 of kernel
    cl_stream b_read_stream;
    ext.flags = 2;
    OCL_CHECK(ret, b_read_stream = clCreateStream(device.get(), CL_STREAM_READ_ONLY, CL_STREAM, &ext, &ret));

    // Launch the Kernel
    OCL_CHECK(err, err = q.enqueueTask(krnl));

    // Initiating the WRITE transfer
    cl_stream_xfer_req wr_req {0};

    wr_req.flags = CL_STREAM_EOT;
    wr_req.priv_data = (void*)"b_write_a";

    // Thread 1 for writing data to input stream 1 independently in case of default blocking transfers.
    std::thread thr1(clWriteStream, b_write_stream_a, a, vector_size_bytes, &wr_req, &ret);

    wr_req.priv_data = (void*)"b_write_b";
    // Thread 2 for writing data to input stream 2 independently in case of default blocking transfers.
    std::thread thr2(clWriteStream, b_write_stream_b, b, vector_size_bytes, &wr_req, &ret);

    // Initiating the READ transfer
    cl_stream_xfer_req rd_req {0};
    rd_req.flags = CL_STREAM_EOT;
    rd_req.priv_data = (void*)"b_read";
    // Output thread to read the stream data independently in case of default blocking transfers.
    std::thread thr3(clReadStream, b_read_stream, results, vector_size_bytes, &rd_req, &ret);

    // Waiting for all the threads to complete their respective operations.
    thr1.join();
    thr2.join();
    thr3.join();

    // Ensuring all OpenCL objects are released.
    q.finish();

    clReleaseStream(b_read_stream);
    clReleaseStream(b_write_stream_a);
    clReleaseStream(b_write_stream_b);
}
    
// Application using non-blocking Stream APIs 
void xdevice_vadd::run_non_blocking(int* a, int*b, int*results)
    {
    // Streams
    // Device Connection specification of the stream through extension pointer
    cl_int ret;
    cl_mem_ext_ptr_t ext;
    ext.param = krnl.get();
    ext.obj = NULL;

    //Create write stream for argument 0 and 1 of kernel
    cl_stream nb_write_stream_a, nb_write_stream_b;
    ext.flags = 0;
    OCL_CHECK(ret, nb_write_stream_a = clCreateStream(device.get(), CL_STREAM_WRITE_ONLY, CL_STREAM, &ext, &ret));
    ext.flags = 1;
    OCL_CHECK(ret, nb_write_stream_b = clCreateStream(device.get(), CL_STREAM_WRITE_ONLY, CL_STREAM, &ext, &ret));

    //Create read stream for argument 2 of kernel
    cl_stream nb_read_stream;
    ext.flags = 2;
    OCL_CHECK(ret, nb_read_stream = clCreateStream(device.get(), CL_STREAM_READ_ONLY, CL_STREAM, &ext, &ret));

    // Launch the Kernel
    OCL_CHECK(err, err = q.enqueueTask(krnl));

    // Initiating the WRITE transfer
    cl_stream_xfer_req wr_req {0};

    wr_req.flags = CL_STREAM_EOT | CL_STREAM_NONBLOCKING;
    wr_req.priv_data = (void*)"nb_write_a";

    // Thread 1 for writing data to input stream 1 independently in case of default blocking transfers.
    OCL_CHECK(ret, clWriteStream(nb_write_stream_a, a, vector_size_bytes, &wr_req, &ret));

    wr_req.priv_data = (void*)"nb_write_b";
    // Thread 2 for writing data to input stream 2 independently in case of default blocking transfers.
    OCL_CHECK(ret, clWriteStream(nb_write_stream_b, b, vector_size_bytes, &wr_req, &ret));

    // Initiating the READ transfer
    cl_stream_xfer_req rd_req {0};
    rd_req.flags = CL_STREAM_EOT | CL_STREAM_NONBLOCKING;
    rd_req.priv_data = (void*)"nb_read";
    // Output thread to read the stream data independently in case of default blocking transfers.
    OCL_CHECK(ret, clReadStream(nb_read_stream, results, vector_size_bytes, &rd_req, &ret));

    // Checking the request completion
    cl_streams_poll_req_completions poll_req[3] {0, 0, 0}; // 3 Requests
    auto num_compl = 3;
    OCL_CHECK(ret, clPollStreams(device.get(), poll_req, 3, 3, &num_compl, 50000, &ret));
    // Blocking API, waits for 2 poll request completion or 50000ms, whichever occurs first.
            
    // Ensuring all OpenCL objects are released.
    q.finish();

    clReleaseStream(nb_read_stream);
    clReleaseStream(nb_write_stream_a);
    clReleaseStream(nb_write_stream_b);
}

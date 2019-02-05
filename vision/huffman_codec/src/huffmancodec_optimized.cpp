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
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "logger.h"
#include "huffmancodec_optimized.h"
#include "simplebmp.h"
#include "xcl2.hpp"

#if defined(__linux__) || defined(linux)
    #include "sys/time.h"
#elif defined(WIN32)
    #include "windows.h"
#endif


#define ROUNDS 10
//ROUNDS <= 10 valid

using namespace sda;

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
//load_file_to_memory



HuffmanOptimized::HuffmanOptimized() {
    // TODO Auto-generated constructor stub

}

HuffmanOptimized::HuffmanOptimized(string& strBitmapFP)
{
    //store path to input bitmap
    m_strBitmapFP = strBitmapFP;

    std::vector<cl::Device> devices = xcl::get_xil_devices();
    cl::Device device = devices[0];

    //Creating Context and Command Queue for selected Device
    OCL_CHECK(err, context = cl::Context(device, NULL, NULL, NULL, &err));
    OCL_CHECK(err, q = cl::CommandQueue(context, device, CL_QUEUE_PROFILING_ENABLE, &err));
    OCL_CHECK(err, std::string deviceName = device.getInfo<CL_DEVICE_NAME>(&err));
    
    std::string xclBinFile = xcl::find_binary_file(deviceName, "krnl_huffman");
    fileBuf = xcl::read_binary_file(xclBinFile, fileBufSize);
    cl::Program::Binaries bins{{fileBuf, fileBufSize}};
    
    devices.resize(1);
    OCL_CHECK(err, m_program = cl::Program(context, devices, bins, NULL, &err));

    //kernels
    OCL_CHECK(err, m_clKernelHuffmanEncoder = cl::Kernel(m_program, "encode", &err));
    OCL_CHECK(err, m_clKernelHuffmanDecoder = cl::Kernel(m_program, "decode", &err));

}

HuffmanOptimized::~HuffmanOptimized() {
    // TODO Auto-generated destructor stub
    delete[] fileBuf;
}

double HuffmanOptimized::timestamp() {
    double ms = 0.0;
    #if  defined(__linux__) || defined(linux)
        timeval time;
        gettimeofday(&time, NULL);
        ms = (time.tv_sec * 1000.0) + (time.tv_usec / 1000.0);
    #elif defined(WIN32)
        SYSTEMTIME time;
        GetSystemTime(&time);
        ms = (time.wSeconds * 1000) + time.wMilliseconds;
    #endif
    return ms;
}

double HuffmanOptimized::computeEventDurationInMS(const cl::Event& event) {
    cl_ulong ts_start = 0, ts_end = 0;
    cl_int err;
    double duration = 0;
    OCL_CHECK(err, err = event.getProfilingInfo<uint64_t>(CL_PROFILING_COMMAND_START, &ts_start));
    OCL_CHECK(err, err = event.getProfilingInfo<uint64_t>(CL_PROFILING_COMMAND_END, &ts_end));
    duration += (cl_double)(ts_end-ts_start)*(cl_double)(1e-06);

    return duration;
}

bool HuffmanOptimized::invoke_kernel(cl::Kernel krnl,
                               const vector<u8>& vec_input,
                               vector<u8>& vec_output,
                               cl::Event events[evtCount]) {
    if(vec_input.size() == 0)
        return false;

    u32 sz_input = vec_input.size();
    u32 sz_output = 0;

    LogInfo("Creating input/output buffers");

//    __kernel
//    __attribute__ ((reqd_work_group_size(1,1,1)))
//    void encode(__global uchar* in_data, uint size_in_data, __global uchar* out_data, __global uint* size_out_data, uchar fetch_size_only)
//    void decode(__global uchar* in_data, uint size_in_data, __global uchar* out_data, __global uint* size_out_data, uchar fetch_size_only) {

    //create input and output buffers size for 24 bpp image

    OCL_CHECK(err, cl::Buffer mem_input(context, CL_MEM_READ_WRITE,
                    sz_input, NULL, &err));

    OCL_CHECK(err, cl::Buffer mem_output(context, CL_MEM_READ_WRITE,
                sz_input, NULL, &err));

    OCL_CHECK(err, cl::Buffer mem_sz_output(context, CL_MEM_READ_WRITE,
                sizeof(u32), NULL, &err));

    //execute kernel
    /*!
     * void encode(__global uchar* in_data, uint size_in_data,
     *                __global uchar* out_data, __global uint* size_out_data,
     *                uchar fetch_size_only)
     *
     * void decode(__global uchar* in_data, uint size_in_data,
     *                __global uchar* out_data, __global uint* size_out_data,
     *                uchar fetch_size_only)
     */

    OCL_CHECK(err, err = krnl.setArg( 0, sizeof(cl_mem), &mem_input));
    OCL_CHECK(err, err = krnl.setArg(1, sizeof(u32), &sz_input));
    OCL_CHECK(err, err = krnl.setArg(2, sizeof(cl_mem), &mem_output));
    OCL_CHECK(err, err = krnl.setArg(3, sizeof(cl_mem), &mem_sz_output));

    //enable fetch size
    u8 fetch_size_only = 1;
    OCL_CHECK(err, err = krnl.setArg(4, sizeof(u8), &fetch_size_only));

    LogInfo("Write input data to device buffer");

    //copy input dataset to OpenCL buffer
    OCL_CHECK(err, err = q.enqueueWriteBuffer(mem_input, CL_TRUE, 0,
                               sz_input, vec_input.data(), NULL, NULL));

    //finish all memory writes
    q.finish();

    cl::size_type global;
    cl::size_type local;
    global = 1;
    local = 1;

    LogInfo("EX1: to make sure all buffers are migrated to device");

    //call once to guarentee that all buffers are migrated to device memory
    OCL_CHECK(err, err = q.enqueueNDRangeKernel(krnl, 0, global,
            local, NULL, &events[evtHostWrite]));
    q.finish();


    LogInfo("EX1: Readback the output size required for the actual kernel execution");

    //read output size
    OCL_CHECK(err, err = q.enqueueReadBuffer(mem_sz_output, CL_TRUE, 0,
            sizeof(u32), (void *) &sz_output, NULL, NULL));
    q.finish();


    LogInfo("EX1: sz_input = %u, sz_output = %u", sz_input, sz_output);

    vec_output.resize(sz_output);
    std::fill(vec_output.begin(), vec_output.end(), 0);

    OCL_CHECK(err, cl::Buffer mem_output_sz(context, CL_MEM_READ_WRITE,
                    sz_output, NULL, &err));

    //set output again
    OCL_CHECK(err, err = krnl.setArg(2, sizeof(cl_mem), &mem_output_sz));

    //set output size again
    OCL_CHECK(err, err = krnl.setArg(3, sizeof(cl_mem), &mem_sz_output));

    //disable fetch size
    fetch_size_only = 0;
    OCL_CHECK(err, err = krnl.setArg(4, sizeof(u8), &fetch_size_only));

    LogInfo("Write output data to device buffer");

    //copy input dataset to OpenCL buffer
    OCL_CHECK(err, err = q.enqueueWriteBuffer(mem_output_sz, CL_TRUE, 0,
                               sz_output, vec_output.data(), NULL, NULL));

    LogInfo("EX2: Real execution of the algorithm to fill the output");

    //call a second time to measure on-chip throughput
    OCL_CHECK(err, err = q.enqueueNDRangeKernel(krnl, 0, global,
            local, NULL, &events[evtKernelExec]));

    q.finish();


    LogInfo("EX2: Readback the results from codec");
    //copy results back from OpenCL buffer
    OCL_CHECK(err, err = q.enqueueReadBuffer(mem_output_sz, CL_TRUE, 0,
            sz_output, (void *) vec_output.data(), NULL, &events[evtHostRead]));

    q.finish();

    return true;
}

int HuffmanOptimized::enc(const vector<u8>& in_data, vector<u8>& out_data) {
    //timings
    cl::Event events[evtCount];
    double durations[evtCount];
    for(int i=0; i < evtCount; i++)
        durations[i] = 0.0;

    //start time stamps
    double startMS = timestamp();

    //encode image
    LogInfo("Invoking encoder");
    bool res = invoke_kernel(m_clKernelHuffmanEncoder, in_data, out_data, &events[0]);
    if(!res) {
        LogError("Failed to encode the input. Test Failed");
        return false;
    }

    //collect times
    for(int i=0; i < evtCount; i++) {
        durations[i] += computeEventDurationInMS(events[i]);
    }

    LogInfo("Total time in [ms] = %f", timestamp() - startMS);
    LogInfo("Host write [ms] = %f", durations[evtHostWrite]);
    LogInfo("Kernel exec [ms] = %f", durations[evtKernelExec]);
    LogInfo("Host read [ms] = %f", durations[evtHostRead]);

    return true;
}

int HuffmanOptimized::dec(const vector<u8>& in_data, vector<u8>& out_data) {
    //timings
    cl::Event events[evtCount];
    double durations[evtCount];
    for(int i=0; i < evtCount; i++)
        durations[i] = 0.0;

    //start time stamps
    double startMS = timestamp();

    //encode image
    LogInfo("Invoking encoder");
    bool res = invoke_kernel(m_clKernelHuffmanDecoder, in_data, out_data, &events[0]);
    if(!res) {
        LogError("Failed to encode the input. Test Failed");
        return false;
    }

    //collect times
    for(int i=0; i < evtCount; i++) {
        durations[i] += computeEventDurationInMS(events[i]);
    }

    LogInfo("Total time in [ms] = %f", timestamp() - startMS);
    LogInfo("Host write [ms] = %f", durations[evtHostWrite]);
    LogInfo("Kernel exec [ms] = %f", durations[evtKernelExec]);
    LogInfo("Host read [ms] = %f", durations[evtHostRead]);

    return true;
}

bool HuffmanOptimized::run(int idevice, int nruns) {
    if (nruns <= 0)
        return false;

    //read input
    LogInfo("Reading input image = %s", m_strBitmapFP.c_str());

    int err;
    struct bmp_t inputbmp;
    err = readbmp((char*)m_strBitmapFP.c_str(), &inputbmp);
    if (err != 0) {
        LogError("Unable to read bitmap file: [%s]", m_strBitmapFP.c_str());
        return false;
    }


    //input buffer size
    u32 szInputBuffer = inputbmp.height * inputbmp.width * 3;
    u8* buffer = reinterpret_cast<u8*>(inputbmp.pixels);
    LogInfo("Read input data successfully. size = %u", szInputBuffer);

    //timings
    cl::Event events[evtCount];
    double durations[evtCount];
    for(int i=0; i < evtCount; i++)
        durations[i] = 0.0;

    //start time stamps
    double startMS = timestamp();

    vector<u8> vec_in(buffer, buffer + szInputBuffer);
    vector<u8> vec_encoded_data;
    vector<u8> vec_decoded_data;

    //encode image
    LogInfo("Invoking encoder");
    bool res = invoke_kernel(m_clKernelHuffmanEncoder, vec_in, vec_encoded_data, &events[0]);
    if(!res) {
        LogError("Failed to encode the input. Test Failed");
        return false;
    }

    //collect times
    for(int i=0; i < evtCount; i++) {
        durations[i] += computeEventDurationInMS(events[i]);
    }


    //decode image
    LogInfo("Invoking decoder");
    res |= invoke_kernel(m_clKernelHuffmanDecoder, vec_encoded_data, vec_decoded_data, &events[0]);
    if(!res) {
        LogError("Failed to decode the output. Test Failed");
        return false;
    }

    //collect times
    for(int i=0; i < evtCount; i++) {
        durations[i] += computeEventDurationInMS(events[i]);
    }

    double h2d_rate = 0.0;
    double d2h_rate = 0.0;

    //compute transfer rate for host write
    if(durations[evtHostWrite] > 0) {
        u32 sz_bytes = vec_in.size() + vec_encoded_data.size();

        //bits per second
        double tmp = (sz_bytes * 8.0) / (durations[evtHostWrite] / 1000.0);

        //mega-bits per second
        h2d_rate = tmp / (1024.0 * 1024.0);
    }

    //compute transfer rate for host read
    if(durations[evtHostRead] > 0) {
        u32 sz_bytes = vec_encoded_data.size() + vec_decoded_data.size();

        //bits per second
        double tmp = (sz_bytes * 8.0) / (durations[evtHostRead] / 1000.0);

        //mega-bits per second
        d2h_rate = tmp / (1024.0 * 1024.0);
    }


    //set stats to valid data
    LogInfo("Number of runs = %d", nruns);
    LogInfo("Total time in [ms] = %f", timestamp() - startMS);
    LogInfo("Host write [ms] = %f", durations[evtHostWrite]);
    LogInfo("Kernel exec [ms] = %f", durations[evtKernelExec]);
    LogInfo("Host read [ms] = %f", durations[evtHostRead]);
    LogInfo("TX rate host --> device [mbps] = %f", h2d_rate);
    LogInfo("TX rate device --> host [mbps] = %f", d2h_rate);


    //write decoded bmp
    string strOutputFP = "decoded.bmp";
    LogInfo("Image decoded OK. Check the output image file: %s", strOutputFP.c_str());
    inputbmp.pixels = reinterpret_cast<uint32_t*>(&vec_decoded_data[0]);
    writebmp((char*)strOutputFP.c_str(), &inputbmp);


    return true;
}


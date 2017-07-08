/**********
Copyright (c) 2017, Xilinx, Inc.
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
#include <vector>
#include "host.h"

int main(int argc, char* argv[])
{
    // Allocate result buffer on host memory 
    size_t vector_size_bytes = sizeof(int) * LENGTH;
    std::vector<int,aligned_allocator<int>> source_a(4 * LENGTH);
    std::vector<int,aligned_allocator<int>> result_sim(LENGTH);
    std::vector<int,aligned_allocator<int>> result_krnl(LENGTH);

    // Create the test data and run the vector addition locally 
    for(int i=0; i < LENGTH; i++){
        source_a[4*i] = i;
        source_a[4*i+1] = 2*i;
        source_a[4*i+2] = 3*i;
        source_a[4*i+3] = 4*i;
        result_sim[i] = source_a[4*i] + source_a[4*i+1] + source_a[4*i+2] + source_a[4*i+3];
    }

// OPENCL HOST CODE AREA START
    std::vector<cl::Device> devices = xcl::get_xil_devices();
    cl::Device device = devices[0];

    cl::Context context(device);
    cl::CommandQueue q(context, device, CL_QUEUE_PROFILING_ENABLE);
    std::string device_name = device.getInfo<CL_DEVICE_NAME>(); 

    std::string binaryFile = xcl::find_binary_file(device_name,"vadd");
    cl::Program::Binaries bins = xcl::import_binary_file(binaryFile);
    devices.resize(1);
    cl::Program program(context, devices, bins);
    cl::Kernel krnl(program,"krnl_vadd");
 
    std::vector<cl::Memory> inBufVec,outBufVec;
    cl::Buffer buffer_a(context,CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, 
            4*vector_size_bytes,source_a.data());
    cl::Buffer buffer_e(context,CL_MEM_USE_HOST_PTR | CL_MEM_WRITE_ONLY,  
            vector_size_bytes,result_krnl.data());
    inBufVec.push_back(buffer_a);
    outBufVec.push_back(buffer_e);

    // Copy input vectors to memory 
    q.enqueueMigrateMemObjects(inBufVec,0/* 0 means from host*/);

    // Set the kernel arguments 
    int vector_length = LENGTH;

    krnl.setArg(0, buffer_a);
    krnl.setArg(1, buffer_e);
    krnl.setArg(2, vector_length);

    // Launch the kernel and get profile data (stop-start)
    uint64_t nstimestart, nstimeend;
    cl::Event event;
    q.enqueueTask(krnl,NULL,&event);
    q.finish();
    event.getProfilingInfo<uint64_t>(CL_PROFILING_COMMAND_START,&nstimestart);
    event.getProfilingInfo<uint64_t>(CL_PROFILING_COMMAND_END,&nstimeend);
    auto duration_nanosec = nstimeend-nstimestart;
    std::cout << " **** Duration returned by profile API is " << (duration_nanosec * (1.0e-6) ) << " ms **** " << std::endl;

    // Copy result to local buffer 
    q.enqueueMigrateMemObjects(outBufVec,CL_MIGRATE_MEM_OBJECT_HOST);
    q.finish();

// OPENCL HOST CODE AREA END

    // Compare the results of the kernel to the simulation 
    int krnl_match = 0;
    for(int i = 0; i < LENGTH; i++){
        if(result_sim[i] != result_krnl[i]){
            std::cout <<"Error: Result mismatch" << std::endl;
            std::cout <<"i = " << i << " CPU result = " << result_sim[i] << " Krnl Result = " << result_krnl[i] << std::endl;
            krnl_match = 1;
            break;
        }
        else{
            ; // nothing...Or you could print additional debug message with result matched
        }
    }

    std::cout << "TEST " << (krnl_match ? "FAILED" : "PASSED") << std::endl; 
    return (krnl_match ? EXIT_FAILURE :  EXIT_SUCCESS);
}

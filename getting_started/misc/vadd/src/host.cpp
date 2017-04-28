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
#include "vadd.h"

int main(int argc, char* argv[]) {

    size_t vector_size_bytes = sizeof(int) * LENGTH;
    std::vector<int,aligned_allocator<int>> source_a   (LENGTH);
    std::vector<int,aligned_allocator<int>> source_b   (LENGTH);
    std::vector<int,aligned_allocator<int>> result_sim (LENGTH);
    std::vector<int,aligned_allocator<int>> result_krnl (LENGTH);

    /* Create the test data and run the vector addition locally */
    for(int i=0; i < LENGTH; i++){
        source_a[i] = i;
        source_b[i] = 2*i;
        result_sim[i] = source_a[i] + source_b[i];
    }

    std::vector<cl::Device> devices = xcl::get_xil_devices();
    cl::Device device = devices[0];

    cl::Context context(device);
    cl::CommandQueue q(context, device, CL_QUEUE_PROFILING_ENABLE);
    std::string device_name = device.getInfo<CL_DEVICE_NAME>(); 

    std::string binaryFile = xcl::find_binary_file(device_name,"krnl_vadd");
    cl::Program::Binaries bins = xcl::import_binary_file(binaryFile);
    devices.resize(1);
    cl::Program program(context, devices, bins);
    cl::Kernel krnl(program,"krnl_vadd");

    std::vector<cl::Memory> inBufVec, outBufVec;
    cl::Buffer buffer_a(context,CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, 
            vector_size_bytes, source_a.data());
    cl::Buffer buffer_b(context,CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, 
            vector_size_bytes, source_b.data());
    cl::Buffer buffer_c(context,CL_MEM_USE_HOST_PTR | CL_MEM_WRITE_ONLY, 
            vector_size_bytes, result_krnl.data());
    inBufVec.push_back(buffer_a);
    inBufVec.push_back(buffer_b);
    outBufVec.push_back(buffer_c);

   
    /* Copy input vectors to memory */
    q.enqueueMigrateMemObjects(inBufVec,0/* 0 means from host*/);

    /* Set the kernel arguments */
    int vector_length = LENGTH;
    krnl.setArg(0, buffer_a);
    krnl.setArg(1, buffer_b);
    krnl.setArg(2, buffer_c);
    krnl.setArg(3, vector_length);

    /* Launch the kernel */
    q.enqueueTask(krnl);

     /* Copy result to local buffer */
    q.enqueueMigrateMemObjects(outBufVec,CL_MIGRATE_MEM_OBJECT_HOST);
    q.finish();


    /* Compare the results of the kernel to the simulation */
    int krnl_match = 0;
    for(int i = 0; i < LENGTH; i++){
        if(result_sim[i] != result_krnl[i]){
            printf("Error: Result mismatch\n");
            printf("i = %d CPU result = %d Krnl Result = %d\n", i, result_sim[i], result_krnl[i]);
            krnl_match = 1;
            break;
        } else{
            printf("Result Match: i = %d CPU result = %d Krnl Result = %d\n", i, result_sim[i], result_krnl[i]);
        }
    }

    std::cout << "TEST " << (krnl_match ? "FAILED" : "PASSED") << std::endl; 
    return (krnl_match ? EXIT_FAILURE :  EXIT_SUCCESS);
}

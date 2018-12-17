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
#include <vector>
#include "vdotprod.h"

int main(int argc, char* argv[]) {
    cl_int err;
    int nhalf = NPOINTS >> 1;
    size_t input_size_bytes = sizeof(int) * NPOINTS;
    size_t output_size_bytes = sizeof(int) * nhalf;
    std::vector<int, aligned_allocator<int>> source_x(NPOINTS);
    std::vector<int, aligned_allocator<int>> source_y(NPOINTS);
    std::vector<int, aligned_allocator<int>> source_z(NPOINTS);
    std::vector<int, aligned_allocator<int>> result_sim(nhalf);
    std::vector<int, aligned_allocator<int>> result_krnl(nhalf);

    /* Create the test data and run the vector addition locally */
    for(int i=0; i < NPOINTS; i++) {
        source_x[i] = i;
        source_y[i] = 2*i;
        source_z[i] = 2*i - NPOINTS;
    }

    int j = 0;
    for(int i=0; i < nhalf; i++) {
        j = i + nhalf;
        result_sim[i] = source_x[i] * source_x[j] + 
                        source_y[i] * source_y[j] + 
                        source_z[i] * source_z[j];
    }

//OPENCL HOST CODE AREA START
    std::vector<cl::Device> devices = xcl::get_xil_devices();
    cl::Device device = devices[0];

    OCL_CHECK(err, cl::Context context(device, NULL, NULL, NULL, &err));
    OCL_CHECK(err, cl::CommandQueue q(context, device, CL_QUEUE_PROFILING_ENABLE));
    std::string device_name = device.getInfo<CL_DEVICE_NAME>(); 

    std::string binaryFile = xcl::find_binary_file(device_name,"krnl_vdotprod");
    cl::Program::Binaries bins = xcl::import_binary_file(binaryFile);
    devices.resize(1);
    OCL_CHECK(err, cl::Program program(context, devices, bins, NULL, &err));
    OCL_CHECK(err, cl::Kernel krnl(program,"krnl_vdotprod", &err));

    std::vector<cl::Memory> inBufVec, outBufVec;
    OCL_CHECK(err, cl::Buffer buffer_x(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, 
            input_size_bytes,source_x.data(), &err));
    OCL_CHECK(err, cl::Buffer buffer_y(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, 
            input_size_bytes,source_y.data(), &err));
    OCL_CHECK(err, cl::Buffer buffer_z(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, 
            input_size_bytes,source_z.data(), &err));
    OCL_CHECK(err, cl::Buffer buffer_d(context, CL_MEM_USE_HOST_PTR | CL_MEM_WRITE_ONLY, 
            output_size_bytes, result_krnl.data(), &err));
    inBufVec.push_back(buffer_x);
    inBufVec.push_back(buffer_y);
    inBufVec.push_back(buffer_z);
    outBufVec.push_back(buffer_d);
    
    /* Copy input vectors to memory */
    OCL_CHECK(err, err = q.enqueueMigrateMemObjects(inBufVec,0/* 0 means from host*/));

    /* Set the kernel arguments */
    OCL_CHECK(err, err = krnl.setArg( 0, buffer_x));
    OCL_CHECK(err, err = krnl.setArg( 1, buffer_y));
    OCL_CHECK(err, err = krnl.setArg( 2, buffer_z));
    OCL_CHECK(err, err = krnl.setArg( 3, buffer_d));
    OCL_CHECK(err, err = krnl.setArg( 4, nhalf));

    /* Launch the kernel */
    OCL_CHECK(err, err = q.enqueueTask(krnl));

     /* Copy result to local buffer */
    OCL_CHECK(err, err = q.enqueueMigrateMemObjects(outBufVec,CL_MIGRATE_MEM_OBJECT_HOST));
    OCL_CHECK(err, err = q.finish());

// OPENCL HOST CODE AREA END

    /* Compare the results of the kernel to the simulation */
    int krnl_match = 0;
    for(int i = 0; i < nhalf; i++){
        if(result_sim[i] != result_krnl[i]){
            printf("Error: Result mismatch");
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

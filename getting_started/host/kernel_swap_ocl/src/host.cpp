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

#define LENGTH 1024

int main(int argc, char** argv)
{
    std::vector<int,aligned_allocator<int>> h_a(LENGTH);//host memory for a vector
    std::vector<int,aligned_allocator<int>> h_b(LENGTH);//host memory for b vector
    std::vector<int,aligned_allocator<int>> h_temp(LENGTH);//host memory for temp vector
    std::vector<int,aligned_allocator<int>> h_c(LENGTH);//host memory for c vector

    //Fill our data sets with pattern
    int i = 0;
    for (i = 0; i < LENGTH; i++) {
        h_a[i] = i;
        h_b[i] = i;
        h_temp[i] = 0;
        h_c[i] = 0;
    }

    std::vector<cl::Device> devices = xcl::get_xil_devices();
    cl::Device device = devices[0];

    //Creating Context and Command Queue for selected Device 
    cl::Context context(device);
    cl::CommandQueue q(context, device, CL_QUEUE_PROFILING_ENABLE);
    std::string device_name = device.getInfo<CL_DEVICE_NAME>(); 
    std::cout << "Found Device=" << device_name.c_str() << std::endl;

    int vector_length = LENGTH;
    bool match = true;

    //The temporary pointer(h_temp) is created mainly for the dynamic platforms, 
    //since in the dynamic platforms we will not be able to load a second xclbin 
    //unless all the cl buffers are released before calling cl::Program a second 
    //time in the same process. The code block below is in braces because the cl objects
    //are automatically released once the block ends
    {
        printf("INFO: loading vmul kernel\n");
        std::string vmulBinaryFile = xcl::find_binary_file(device_name,"krnl_vmul");
        cl::Program::Binaries vmul_bins = xcl::import_binary_file(vmulBinaryFile);
        devices.resize(1);
        cl::Program program(context, devices, vmul_bins);
        cl::Kernel krnl_vmul(program, "krnl_vmul");
    
        cl::Buffer d_a(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY,  
                   sizeof(int) * LENGTH, h_a.data());
        cl::Buffer d_b(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY,  
                   sizeof(int) * LENGTH, h_b.data());
        cl::Buffer d_mul(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_WRITE, 
                   sizeof(int) * LENGTH, h_temp.data());

        q.enqueueMigrateMemObjects({d_a, d_b},0/* 0 means from host*/);

        krnl_vmul.setArg(0, d_a);
        krnl_vmul.setArg(1, d_b);
        krnl_vmul.setArg(2, d_mul);
        krnl_vmul.setArg(3,vector_length);

        // This function will execute the kernel on the FPGA
        q.enqueueTask(krnl_vmul);

        q.enqueueMigrateMemObjects({d_mul},CL_MIGRATE_MEM_OBJECT_HOST);
        q.finish();
    
        // Check Results
        for(int i = 0; i < LENGTH; i++) {
            if ((h_a[i] * h_b[i]) != h_temp[i]) {
                printf("ERROR in vmul - %d - a=%d, b=%d, c=%d\n", i, h_a[i], h_b[i], h_c[i]);
                match = false;
                break;
            }
        }
    }

    if(match){
        printf("INFO: loading vadd_krnl\n");
        std::string vaddBinaryFile = xcl::find_binary_file(device_name,"krnl_vadd");
        cl::Program::Binaries vadd_bins = xcl::import_binary_file(vaddBinaryFile);
        cl::Program program(context, devices, vadd_bins);
        cl::Kernel krnl_vadd(program, "krnl_vadd");
   
        //Need to create the buffer and allocate the memory for the dynamic platforms 
        cl::Buffer d_temp(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY,  
                sizeof(int) * LENGTH, h_temp.data());
        cl::Buffer d_add(context, CL_MEM_WRITE_ONLY | CL_MEM_USE_HOST_PTR, 
                sizeof(int) * LENGTH, h_c.data());

        q.enqueueMigrateMemObjects({d_temp}, 0/* 0 means from host*/);

        krnl_vadd.setArg(0,d_temp);
        krnl_vadd.setArg(1,d_temp);
        krnl_vadd.setArg(2,d_add);
        krnl_vadd.setArg(3,vector_length);

        //This function will execute the kernel on the FPGA
        q.enqueueTask(krnl_vadd);

        q.enqueueMigrateMemObjects({d_add}, CL_MIGRATE_MEM_OBJECT_HOST);
        q.finish();

        //Check Results
        for (int i = 0; i < LENGTH; i++) {
            if ((2*(h_a[i] * h_b[i])) != h_c[i]) {
                printf("ERROR in vadd - %d - c=%d\n", i, h_c[i]);
                match = false;
                break;
            }
        }
    }

    std::cout << "TEST " << (match ? "PASSED" : "FAILED") << std::endl; 
    return (match ? EXIT_SUCCESS :  EXIT_FAILURE);
}

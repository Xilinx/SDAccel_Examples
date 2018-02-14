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

#define TEST_MATRIX_DIM 256 
#define MAX_MATRIX_DIM 256

void mmult_sw(  std::vector<int,aligned_allocator<int>> &a, 
                std::vector<int,aligned_allocator<int>> &b, 
                std::vector<int,aligned_allocator<int>> &c, int size)
{
  for (int row = 0; row < size; row++) {
    for (int col = 0; col < size; col++) {
      int result = 0;
      for (int k = 0; k < size; k++) {
        result += a[row * size + k] * b[k * size  + col];
      }
      c[row * size + col] = result;
    }
  }
}

int main(int argc, char** argv)
{   
    int test_matrix_dim = TEST_MATRIX_DIM;
    const char *xcl_emu = getenv("XCL_EMULATION_MODE");
    if(xcl_emu && !strcmp(xcl_emu, "hw_emu")){
        test_matrix_dim = 16;
        std::cout << "Data Size Reduced to  "<< test_matrix_dim << " for Hardware Emulation" << std::endl;
    }
    int dim = test_matrix_dim;
    int matrix_size = dim * dim;
    if (dim > MAX_MATRIX_DIM) {
        std::cout << "Size is bigger than internal buffer size, please use a size smaller than 256!" << std::endl;
        return EXIT_FAILURE;
    }
    //Allocate Memory in Host Memory
    size_t matrix_size_in_bytes = sizeof(int) * matrix_size;
    std::vector<int,aligned_allocator<int>> source_input_a   (matrix_size);
    std::vector<int,aligned_allocator<int>> source_input_b   (matrix_size);
    std::vector<int,aligned_allocator<int>> source_hw_results(matrix_size);
    std::vector<int,aligned_allocator<int>> source_sw_results(matrix_size);

    // Create the test data and Software Result 
    for(int i = 0 ; i < matrix_size ; i++){
        source_input_a[i] = i;
        source_input_b[i] = i;
        source_hw_results[i] = 0;
    }
    mmult_sw(source_input_a, source_input_b, source_sw_results, dim);

//OPENCL HOST CODE AREA START
    std::vector<cl::Device> devices = xcl::get_xil_devices();
    cl::Device device = devices[0];

    cl::Context context(device);
    cl::CommandQueue q(context, device, CL_QUEUE_PROFILING_ENABLE);
    std::string device_name = device.getInfo<CL_DEVICE_NAME>(); 

    std::string binaryFile = xcl::find_binary_file(device_name,"mmult");
    cl::Program::Binaries bins = xcl::import_binary_file(binaryFile);
    devices.resize(1);
    cl::Program program(context, devices, bins);
    cl::Kernel kernel(program,"mmult");

    //Allocate Buffer in Global Memory
    cl::Buffer buffer_a(context,CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY,  
            matrix_size_in_bytes,source_input_a.data());
    cl::Buffer buffer_b(context,CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY,  
            matrix_size_in_bytes,source_input_b.data());
    cl::Buffer buffer_c(context,CL_MEM_USE_HOST_PTR | CL_MEM_WRITE_ONLY, 
            matrix_size_in_bytes, source_hw_results.data());

    std::vector<cl::Memory> writeBufVec;
    writeBufVec.push_back(buffer_a);
    writeBufVec.push_back(buffer_b);
    //Migrate  input data to device global memory
    q.enqueueMigrateMemObjects(writeBufVec,0/* 0 means from host*/);

    auto krnl_mmult 
        = cl::KernelFunctor<cl::Buffer&,cl::Buffer&,cl::Buffer&,int>(kernel);

    //Launch the Kernel
    krnl_mmult(cl::EnqueueArgs(q,cl::NDRange(1,1,1), cl::NDRange(1,1,1)), 
            buffer_a,buffer_b,buffer_c, dim);

    std::vector<cl::Memory> readBufVec;
    readBufVec.push_back(buffer_c);
    //Copy Result from Device Global Memory to Host Local Memory
    q.enqueueMigrateMemObjects(readBufVec,CL_MIGRATE_MEM_OBJECT_HOST);
    q.finish();
//OPENCL HOST CODE AREA END
    
    // Compare the results of the Device to the simulation
    int match = 0;
    for (int i = 0 ; i < matrix_size ; i++){
        if (source_hw_results[i] != source_sw_results[i]){
            std::cout << "Error: Result mismatch" << std::endl;
            std::cout << "i = " << i << " CPU result = " << source_sw_results[i]
                << " Device result = " << source_hw_results[i] << std::endl;
            match = 1;
            break;
        }
    }

    std::cout << "TEST " << (match ? "FAILED" : "PASSED") << std::endl; 
    return (match ? EXIT_FAILURE :  EXIT_SUCCESS);
}

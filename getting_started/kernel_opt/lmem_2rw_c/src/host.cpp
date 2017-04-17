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

/*******************************************************************************
Description: SDx Vector Addition to utilize both Ports of BRAM memory 
*******************************************************************************/
#include "xcl2.hpp"
#include <vector>

#define DATA_SIZE 4096

int main(int argc, char** argv)
{
    //Allocate Memory in Host Memory
    size_t vector_size_bytes = sizeof(int) * DATA_SIZE;

    std::vector<int> source_in1       (DATA_SIZE);
    std::vector<int> source_in2       (DATA_SIZE);
    std::vector<int> source_hw_results(DATA_SIZE);
    std::vector<int> source_sw_results(DATA_SIZE);

    // Create the test data and Software Result 
    for(int i = 0 ; i < DATA_SIZE ; i++){
        source_in1[i] = i;
        source_in2[i] = i * i;
        source_sw_results[i] = i * i + i;
        source_hw_results[i] = 0;
    }

//OPENCL HOST CODE AREA START
    std::vector<cl::Device> devices = xcl::get_xil_devices();
    cl::Device device = devices[0];

    cl::Context context(device);
    cl::CommandQueue q(context, device);
    std::string device_name = device.getInfo<CL_DEVICE_NAME>(); 

    std::string binaryFile = xcl::find_binary_file(device_name,"vadd");
    cl::Program::Binaries bins = xcl::import_binary_file(binaryFile);
    devices.resize(1);
    cl::Program program(context, devices, bins);
    cl::Kernel kernel(program,"vadd");

    //Allocate Buffer in Global Memory
    cl::Buffer buffer_in1   (context, CL_MEM_READ_ONLY, vector_size_bytes);
    cl::Buffer buffer_in2   (context, CL_MEM_READ_ONLY, vector_size_bytes);
    cl::Buffer buffer_output(context, CL_MEM_WRITE_ONLY, vector_size_bytes);

    //Copy input data to device global memory
    q.enqueueWriteBuffer(buffer_in1,CL_TRUE,0,vector_size_bytes,source_in1.data());
    q.enqueueWriteBuffer(buffer_in2,CL_TRUE,0,vector_size_bytes,source_in2.data());

    int size = DATA_SIZE;
    auto krnl_vector_add = cl::KernelFunctor<cl::Buffer&, cl::Buffer&, 
         cl::Buffer&, int>(kernel);

    //Launch the Kernel
    krnl_vector_add(cl::EnqueueArgs(q,cl::NDRange(1,1,1), cl::NDRange(1,1,1)), 
            buffer_in1, buffer_in2, buffer_output, size);

    //Copy Result from Device Global Memory to Host Local Memory
    q.enqueueReadBuffer(buffer_output,CL_TRUE, 0, vector_size_bytes, 
            source_hw_results.data());
//OPENCL HOST CODE AREA END
    
    // Compare the results of the Device to the simulation
    int match = 0;
    for (int i = 0 ; i < DATA_SIZE ; i++){
        if (source_hw_results[i] != source_sw_results[i]){
            std::cout << "Error: Result mismatch" << std::endl;
            std::cout << "i = " << i << " CPU result = " << source_sw_results[i]
                << " Device result = " << source_hw_results[i] << std::endl;
            match = 1;
            break;
        }
    }

    if (match){
        std::cout << "TEST FAILED" << std::endl; 
        return EXIT_FAILURE;
    }
    std::cout << "TEST PASSED" << std::endl;
    return EXIT_SUCCESS;
}

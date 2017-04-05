/**********
Copyright (c) 2016, Xilinx, Inc.
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

using std::vector;

static const int DATA_SIZE = 256;
static const std::string error_message =
    "Error: Result mismatch:\n"
    "i = %d CPU result = %d Device result = %d\n";

// This example illustrates the very simple OpenCL example that performs
// an addition on two vectors
int main(int argc, char **argv) {
    // compute the size of array in bytes
    int size_in_bytes = DATA_SIZE * sizeof(int);

    // Creates a vector of DATA_SIZE elements with an initial value of 10 and 32
    vector<int> source_a(DATA_SIZE, 10);
    vector<int> source_b(DATA_SIZE, 32);
    vector<int> source_results(DATA_SIZE);


    // The get_xil_devices will return vector of Xilinx Devices 
    std::vector<cl::Device> devices = xcl::get_xil_devices();
    cl::Device device = devices[0];

    //Creating Context and Command Queue for selected Device 
    cl::Context context(device);
    cl::CommandQueue q(context, device);
    std::string device_name = device.getInfo<CL_DEVICE_NAME>(); 
    std::cout << "Found Device=" << device_name.c_str() << std::endl;

    // import_binary() command will find the OpenCL binary file created using the 
    // xocc compiler load into OpenCL Binary and return as Binaries
    // OpenCL and it can contain many functions which can be executed on the
    // device.
    cl::Program::Binaries bins = xcl::import_binary(device_name,"vector_addition");
    devices.resize(1);
    cl::Program program(context, devices, bins);

    // These commands will allocate memory on the FPGA. The cl::Buffer objects can
    // be used to reference the memory locations on the device. The cl::Buffer
    // object cannot be referenced directly and must be passed to other OpenCL
    // functions.
    cl::Buffer buffer_a(context, CL_MEM_READ_ONLY,  size_in_bytes);
    cl::Buffer buffer_b(context, CL_MEM_READ_ONLY,  size_in_bytes);
    cl::Buffer buffer_result(context, CL_MEM_WRITE_ONLY, size_in_bytes);

    // These commands will load the source_a and source_b vectors from the host
    // application and into the buffer_a and buffer_b cl::Buffer objects. The data
    // will be be transferred from system memory over PCIe to the FPGA on-board
    // DDR memory.
    q.enqueueWriteBuffer(buffer_a, CL_TRUE, 0, size_in_bytes, source_a.data());
    q.enqueueWriteBuffer(buffer_b, CL_TRUE, 0, size_in_bytes, source_b.data());
    q.finish();

    // This call will extract a kernel out of the program we loaded in the
    // previous line. A kernel is an OpenCL function that is executed on the
    // FPGA. This function is defined in the src/vetor_addition.cl file.
    cl::Kernel kernel(program,"vector_add");
    auto krnl_vector_add = cl::KernelFunctor<cl::Buffer&, cl::Buffer&, cl::Buffer&, 
         int>(kernel);

    // This function will execute the kernel on the FPGA
    krnl_vector_add(cl::EnqueueArgs(q, cl::NDRange(1,1,1), cl::NDRange(1,1,1)), 
            buffer_result, buffer_a,buffer_b,DATA_SIZE);
    q.finish();

    // The result of the previous kernel execution will need to be retrieved in
    // order to view the results. This call will write the data from the
    // buffer_result cl_mem object to the source_results vector
    q.enqueueReadBuffer(buffer_result, CL_TRUE, 0, size_in_bytes, 
            source_results.data());
    q.finish();


    int match = 0;
    printf("Result = \n");
    for (int i = 0; i < DATA_SIZE; i++) {
        int host_result = source_a[i] + source_b[i];
        if (source_results[i] != host_result) {
            printf(error_message.c_str(), i, host_result, source_results[i]);
            match = 1;
            break;
        } else {
          printf("%d ", source_results[i]);
          if (((i + 1) % 16) == 0) printf("\n");
        }
    }

    if (match) {
        printf("TEST FAILED.\n");
        return EXIT_FAILURE;
    } else {
        printf("TEST PASSED.\n");
        return EXIT_SUCCESS;
    }
}

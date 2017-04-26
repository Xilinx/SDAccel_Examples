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

int main(int argc, char** argv)
{

    //Allocate Memory in Host Memory
    size_t vector_size_bytes = sizeof(DTYPE) * BLOCK_SIZE;
    std::vector<DTYPE> a   (BLOCK_SIZE);// original data set given to device
    std::vector<DTYPE> c   (BLOCK_SIZE);// results returned from device
    std::vector<DTYPE> sw_c(BLOCK_SIZE);// results returned from software

    // Create the test data and Software Result 
    int alpha = 3;
    for(int i = 0; i < BLOCK_SIZE; i++) {
      a[i] = i;
      c[i] = 0;
      sw_c[i] = alpha*a[i];
    }

//OPENCL HOST CODE AREA START

    std::vector<cl::Device> devices = xcl::get_xil_devices();
    cl::Device device = devices[0];

    cl::Context context(device);
    cl::CommandQueue q(context, device, CL_QUEUE_PROFILING_ENABLE);
    std::string device_name = device.getInfo<CL_DEVICE_NAME>(); 

    std::string binaryFile = xcl::find_binary_file(device_name,"row_array_2d");
    cl::Program::Binaries bins = xcl::import_binary_file(binaryFile);
    devices.resize(1);
    cl::Program program(context, devices, bins);
    cl::Kernel krnl_row_array_2d(program,"row_array_2d");

    //Allocate Buffer in Global Memory
    cl::Buffer buffer_a(context, CL_MEM_READ_ONLY, vector_size_bytes);
    cl::Buffer buffer_c(context, CL_MEM_WRITE_ONLY,vector_size_bytes);

    //Copy input data to device global memory
    q.enqueueWriteBuffer(buffer_a,CL_TRUE, 0,vector_size_bytes, a.data());

    int nargs=0;
    krnl_row_array_2d.setArg(nargs++,buffer_a);
    krnl_row_array_2d.setArg(nargs++,buffer_c);
    krnl_row_array_2d.setArg(nargs++,alpha);

    //Launch the Kernel
    q.enqueueTask(krnl_row_array_2d);

    //Copy Result from Device Global Memory to Host Local Memory
    q.enqueueReadBuffer(buffer_c,CL_TRUE, 0, vector_size_bytes, c.data());

//OPENCL HOST CODE AREA END

    // Validate
    unsigned int correct = 0;              // number of correct results returned
    for (int i = 0;i < BLOCK_SIZE; i++) {
      if(c[i] == sw_c[i]) {
        correct++; 
      } else { 
          std::cout << std::endl << " wrong sw " << sw_c[i] 
              << " hw " << c[i] << " index " << i << std::endl;
      }
    }
    
    // Print a brief summary detailing the results
    std::cout << "Computed '" << correct << "/" << BLOCK_SIZE 
        << "' correct values!" << std::endl;

    if(correct == BLOCK_SIZE){
        std::cout << "TEST PASSED." << std::endl; 
        return EXIT_SUCCESS;
    }
    else{
        std::cout << "TEST FAILED." << std::endl; 
        return EXIT_FAILURE;
    }
}

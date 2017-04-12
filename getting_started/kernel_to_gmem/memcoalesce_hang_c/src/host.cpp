/**********
Copyright (c) 2017, Xilinx, Inc.
All rights reserved.

Redistribution and use in source and binary forms, with or withdout modification,
are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice,
this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice,
this list of conditions and the following disclaimer in the documentation
and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors
may be used to endorse or promote products derived from this software
withdout specific prior written permission.

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

#define LENGTH 8
#define ITERATION 64
void dummy_op(std::vector<int> & din1,std::vector<int> &din2, 
        std::vector<int> &din3,std::vector<int> &dout)
{
    for (int i = 0; i < ITERATION; i++) {
        int sum = 0;
        for (int j = 0; j < LENGTH; j++){
            sum +=  din1[i*LENGTH+ j] + din2[i*LENGTH+ j] + din3[j];
        }
        dout[i] = sum;
    }
}

int main(int argc, char* argv[]) {

    if (argc != 2) {
        printf("Usage: %s "
               "<dummy_op_GOOD/dummy_op_BAD>\n",
               argv[0]);
        return EXIT_FAILURE;
    }
    std::string binary_name = argv[1];

    int total_size = (LENGTH) * (ITERATION);
    //Allocate Memory in Host Memory
    std::vector<int> din1(total_size);
    std::vector<int> din2(total_size);
    std::vector<int> din3(ITERATION);
    std::vector<int> dout(ITERATION);
    std::vector<int> result_krnl(ITERATION);

    for (int i = 0 ; i < total_size; i++ ){
        din1[i] = i; 
        din2[i] = i + 2;
        if (i < ITERATION){
            din3[i]  = i + 3;
            dout[i] = 0;
        }
    }
    dummy_op(din1,din2,din3,dout);


//OPENCL HOST CODE AREA START
    std::vector<cl::Device> devices = xcl::get_xil_devices();
    cl::Device device = devices[0];

    cl::Context context(device);
    cl::CommandQueue q(context, device);
    std::string device_name = device.getInfo<CL_DEVICE_NAME>(); 

    cl::Program::Binaries bins = xcl::import_binary(device_name,binary_name.c_str());
    devices.resize(1);
    cl::Program program(context, devices, bins);
    cl::Kernel krnl(program,"dummy_op");

    cl::Buffer buffer_din1  (context,CL_MEM_READ_ONLY, sizeof(int) * total_size);
    cl::Buffer buffer_vedin2(context,CL_MEM_READ_ONLY, sizeof(int) * total_size);
    cl::Buffer buffer_din3  (context,CL_MEM_READ_ONLY, sizeof(int) * (ITERATION));
    cl::Buffer buffer_dout  (context,CL_MEM_WRITE_ONLY,sizeof(int) * (ITERATION));

    q.enqueueWriteBuffer(buffer_din1,  CL_TRUE,0,sizeof(int) * total_size,din1.data());
    q.enqueueWriteBuffer(buffer_vedin2,CL_TRUE,0,sizeof(int) * total_size,din2.data());
    q.enqueueWriteBuffer(buffer_din3,  CL_TRUE,0,sizeof(int) * ITERATION ,din3.data());

    /* Set the kernel arguments */
    int nargs=0;
    krnl.setArg(nargs++,buffer_din1);
    krnl.setArg(nargs++,buffer_vedin2);
    krnl.setArg(nargs++,buffer_din3);
    krnl.setArg(nargs++,buffer_dout);

    /* Launch the kernel */
    q.enqueueTask(krnl);

     /* Copy result to local buffer */
    q.enqueueReadBuffer(buffer_dout,CL_TRUE, 0, sizeof(int) * ITERATION, result_krnl.data());

    /* Compare the results of the kernel to the simulation */
    int krnl_match = 0;
    for(int i = 0; i < ITERATION; i++){
        if(dout[i] != result_krnl[i]){
            std::cout << "Error: Result mismatch" << std::endl;
            std::cout << "i = " << i << " CPU result = " << dout[i]
                << " Krnl Result = " << result_krnl[i] << std::endl;
            krnl_match = 1;
            break;
        }
    }

    if(krnl_match){
        std::cout << "TEST FAILED." << std::endl; 
        return EXIT_FAILURE;
    }
    std::cout << "TEST PASSED." << std::endl; 
    return EXIT_SUCCESS; 
}

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
#include <math.h>
#include <fenv.h>
#include "xcl2.hpp"
#include <vector>

float get_rand() {
    float ret = ((float) rand() / (float)(RAND_MAX)) * 1.0f - 0.5f;

    union {
        float f;
        unsigned u;
    } x = {ret};

    /* Check if the number is subnormal if so change it to zero */
    if ((x.u & 0x7f800000) == 0) {
        x.f = 0.0;
    }

    return x.f;
}

int main(int argc, char* argv[]) {
    if(argc != 1 && argc != 2 && argc !=3 && argc !=4) {
        printf("Usage: %s [length] [max relative error] [rand seed]\n", argv[0]);
        return EXIT_FAILURE;
    }

    unsigned length = 1000;
    unsigned seed = 0;
    float max_relative_error =  0.05;

    if(argc > 1) {
        length = atoi(argv[1]);
    }

    if (argc > 2) {
        max_relative_error = atof(argv[2]);
    }

    if(argc > 3) {
        seed = atoi(argv[3]);
    }

    printf("length = %d\n", length);
    printf("seed = %d\n", seed);
    printf("max_relative_error = %f\n", max_relative_error);

    srand(seed);
    fesetround(FE_TOWARDZERO);

    int size =  ((length-1)/16 + 1) * 16;
    size_t vector_size_bytes = sizeof(float) * size;

    std::vector<float,aligned_allocator<float>> in (size);
    std::vector<float,aligned_allocator<float>> out(size);
    std::vector<float,aligned_allocator<float>> out_fpga(size);

    float sum = 0;
    /* Create the test data and run the vector addition locally */
    for(unsigned i=0; i < length; i++) {
        in[i] = get_rand();
        out[i] = (sum += in[i]);
    }


//OPENCL HOST CODE AREA START
    std::vector<cl::Device> devices = xcl::get_xil_devices();
    cl::Device device = devices[0];

    cl::Context context(device);
    cl::CommandQueue q(context, device, CL_QUEUE_PROFILING_ENABLE);
    std::string device_name = device.getInfo<CL_DEVICE_NAME>(); 

    std::string binaryFile = xcl::find_binary_file(device_name,"krnl_sum_scan");
    cl::Program::Binaries bins = xcl::import_binary_file(binaryFile);
    devices.resize(1);
    cl::Program program(context, devices, bins);
    cl::Kernel krnl(program,"krnl_sum_scan");

    std::vector<cl::Memory> inBufVec, outBufVec;
    cl::Buffer dev_in (context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, 
            vector_size_bytes,in.data());
    cl::Buffer dev_out(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, 
            vector_size_bytes,out_fpga.data());
    inBufVec.push_back(dev_in);
    outBufVec.push_back(dev_out);

    
    /* Copy input vectors to memory */
    q.enqueueMigrateMemObjects(inBufVec,0/* 0 means from host*/);

    /* Set the kernel arguments */
    krnl.setArg(0, dev_in);
    krnl.setArg(1, dev_out);
    krnl.setArg(2, length);

    /* Launch the kernel */
    cl::Event event;
    q.enqueueTask(krnl,NULL,&event);
    q.finish();

     /* Copy result to local buffer */
    q.enqueueMigrateMemObjects(outBufVec,CL_MIGRATE_MEM_OBJECT_HOST);
    q.finish();

    uint64_t nstimestart, nstimeend;
    event.getProfilingInfo<uint64_t>(CL_PROFILING_COMMAND_START,&nstimestart);
    event.getProfilingInfo<uint64_t>(CL_PROFILING_COMMAND_END,&nstimeend);
    auto duration = nstimeend-nstimestart;

//OPENCL HOST CODE AREA END

    /* Compare the results of the kernel to the simulation */
    size_t krnl_match = 0;
    for(unsigned i = 0; i < length; i++){
#if DEBUG
        printf("i = %d CPU result = %f(%a) Krnl Result = %f(%a) : in = %f(%a)\n", i, out[i], out[i], out_fpga[i],out_fpga[i], in[i], in[i]);
#endif
        float relative_error = fabs(out[i] - out_fpga[i]) / fabs(out[i]);
        if(relative_error  > max_relative_error){
            printf("Error: Result mismatch (relative_error = %f)\n", relative_error);
            printf("i = %d CPU result = %f(%a) Krnl Result = %f(%a)\n", i, out[i], out[i], out_fpga[i],out_fpga[i]);
            krnl_match = 1;
            break;
        }
    }

    if(krnl_match == 1) {
        printf("Fail! kernel results do not match cpu results\n");
        printf("TEST FAILED\n");
        return EXIT_FAILURE;
    } else{
        printf("Success! Kernel took %ld ns to execute\n", duration);
        printf("TEST PASSED\n");
        return EXIT_SUCCESS;
    }
}

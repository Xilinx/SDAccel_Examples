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

void idct(const int16_t block[64], const uint16_t q[64], int16_t outp[64], bool ignore_dc);

typedef short int16_t;
typedef unsigned short uint16_t;

int main(int argc, char* argv[]) {

    unsigned int blocks = 10;

    bool ignore_dc = true;

    std::vector<int16_t, aligned_allocator<int16_t>> source_block(64*blocks);
    std::vector<uint16_t,aligned_allocator<uint16_t>> source_q    (64*blocks);
    std::vector<int16_t, aligned_allocator<int16_t>> golden_vpout(64*blocks);
    std::vector<int16_t, aligned_allocator<int16_t>> result_vpout(64*blocks);

    /* Create the test data and run the vector addition locally */
    for(size_t i = 0; i < blocks; i++){
        for(size_t j = 0; j < 64; j++) {
           source_block[i*64 + j] = j;
           source_q    [i*64 + j] = j;
        }
        idct(&source_block[i*64], &source_q[i*64], &golden_vpout[i*64], ignore_dc);
    }

    std::vector<cl::Device> devices = xcl::get_xil_devices();
    cl::Device device = devices[0];

    cl::Context context(device);
    cl::CommandQueue q(context, device, CL_QUEUE_PROFILING_ENABLE);
    std::string device_name = device.getInfo<CL_DEVICE_NAME>(); 

    std::string binaryFile = xcl::find_binary_file(device_name,"krnl_idct");
    cl::Program::Binaries bins = xcl::import_binary_file(binaryFile);
    devices.resize(1);
    cl::Program program(context, devices, bins);
    cl::Kernel krnl(program,"krnl_idct");

    cl::Buffer dev_block(context,CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, 
            64*blocks*sizeof(int16_t), source_block.data());
    cl::Buffer dev_q(context,CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, 
            64*blocks*sizeof(uint16_t), source_q.data());
    cl::Buffer dev_vpout(context,CL_MEM_USE_HOST_PTR | CL_MEM_WRITE_ONLY, 
            64*blocks*sizeof(int16_t), result_vpout.data());

    std::vector<cl::Memory> inBufVec, outBufVec;

    inBufVec.push_back(dev_block);
    inBufVec.push_back(dev_q);
    outBufVec.push_back(dev_vpout);

   
    /* Copy input vectors to memory */
    q.enqueueMigrateMemObjects(inBufVec,0/* 0 means from host*/);

   int dev_ignore_dc = ignore_dc ? 1 : 0;

    /* Set the kernel arguments */
    krnl.setArg(0, dev_block);
    krnl.setArg(1, dev_q);
    krnl.setArg(2, dev_vpout);
    krnl.setArg(3, dev_ignore_dc);
    krnl.setArg(4, blocks);

    /* Launch the kernel */
    q.enqueueTask(krnl);

     /* Copy result to local buffer */
    q.enqueueMigrateMemObjects(outBufVec,CL_MIGRATE_MEM_OBJECT_HOST);
    q.finish();


    /* Compare the results of the kernel to the simulation */
    int krnl_match = 0;
    for(size_t i = 0; i < 64*blocks; i++){
        if(result_vpout[i] != golden_vpout[i]){
            printf("Error: Result mismatch\n");
            printf("i = %d CPU result = %d Krnl Result = %d\n", (int) i, result_vpout[i], golden_vpout[i]);
            krnl_match = 1;
            break;
        } else{
            printf("Result Match: i = %d CPU result = %d Krnl Result = %d\n",(int) i, result_vpout[i], golden_vpout[i]);
        }
    }

    std::cout << "TEST " << (krnl_match ? "FAILED" : "PASSED") << std::endl;
    return (krnl_match ? EXIT_FAILURE :  EXIT_SUCCESS);
}

void idct(const int16_t block[64], const uint16_t q[64], int16_t outp[64], bool ignore_dc) {
    int32_t intermed[64];

    const uint16_t w1 = 2841; // 2048*sqrt(2)*cos(1*pi/16)
    const uint16_t w2 = 2676; // 2048*sqrt(2)*cos(2*pi/16)
    const uint16_t w3 = 2408; // 2048*sqrt(2)*cos(3*pi/16)
    const uint16_t w5 = 1609; // 2048*sqrt(2)*cos(5*pi/16)
    const uint16_t w6 = 1108; // 2048*sqrt(2)*cos(6*pi/16)
    const uint16_t w7 = 565;  // 2048*sqrt(2)*cos(7*pi/16)

    const uint16_t w1pw7 = w1 + w7;
    const uint16_t w1mw7 = w1 - w7;
    const uint16_t w2pw6 = w2 + w6;
    const uint16_t w2mw6 = w2 - w6;
    const uint16_t w3pw5 = w3 + w5;
    const uint16_t w3mw5 = w3 - w5;

    const uint16_t r2 = 181; // 256/sqrt(2)

    // Horizontal 1-D IDCT.
    for (int y = 0; y < 8; ++y) {
        int y8 = y * 8;
        int32_t x0 = (((ignore_dc && y == 0)
                       ? 0 : (block[y8 + 0] * q[y8 + 0]) << 11)) + 128;
        int32_t x1 = (block[y8 + 4] * q[y8 + 4]) << 11;
        int32_t x2 = block[y8 + 6] * q[y8 + 6];
        int32_t x3 = block[y8 + 2] * q[y8 + 2];
        int32_t x4 = block[y8 + 1] * q[y8 + 1];
        int32_t x5 = block[y8 + 7] * q[y8 + 7];
        int32_t x6 = block[y8 + 5] * q[y8 + 5];
        int32_t x7 = block[y8 + 3] * q[y8 + 3];
        // If all the AC components are zero, then the IDCT is trivial.
        if (x1 ==0 && x2 == 0 && x3 == 0 && x4 == 0 && x5 == 0 && x6 == 0 && x7 == 0) {
            int32_t dc = (x0 - 128) >> 8; // coefficients[0] << 3
            intermed[y8 + 0] = dc;
            intermed[y8 + 1] = dc;
            intermed[y8 + 2] = dc;
            intermed[y8 + 3] = dc;
            intermed[y8 + 4] = dc;
            intermed[y8 + 5] = dc;
            intermed[y8 + 6] = dc;
            intermed[y8 + 7] = dc;
            continue;
        }
        
        // Prescale.
        
        // Stage 1.
        int32_t x8 = w7 * (x4 + x5);
        x4 = x8 + w1mw7*x4;
        x5 = x8 - w1pw7*x5;
        x8 = w3 * (x6 + x7);
        x6 = x8 - w3mw5*x6;
        x7 = x8 - w3pw5*x7;
        
        // Stage 2.
        x8 = x0 + x1;
        x0 -= x1;
        x1 = w6 * (x3 + x2);
        x2 = x1 - w2pw6*x2;
        x3 = x1 + w2mw6*x3;
        x1 = x4 + x6;
        x4 -= x6;
        x6 = x5 + x7;
        x5 -= x7;
        
        // Stage 3.
        x7 = x8 + x3;
        x8 -= x3;
        x3 = x0 + x2;
        x0 -= x2;
        x2 = (r2*(x4+x5) + 128) >> 8;
        x4 = (r2*(x4-x5) + 128) >> 8;
        
        // Stage 4.
        intermed[y8+0] = (x7 + x1) >> 8;
        intermed[y8+1] = (x3 + x2) >> 8;
        intermed[y8+2] = (x0 + x4) >> 8;
        intermed[y8+3] = (x8 + x6) >> 8;
        intermed[y8+4] = (x8 - x6) >> 8;
        intermed[y8+5] = (x0 - x4) >> 8;
        intermed[y8+6] = (x3 - x2) >> 8;
        intermed[y8+7] = (x7 - x1) >> 8;
    }
    
    // Vertical 1-D IDCT.
    for (int32_t x = 0; x < 8; ++x) {
        // Similar to the horizontal 1-D IDCT case, if all the AC components are zero, then the IDCT is trivial.
        // However, after performing the horizontal 1-D IDCT, there are typically non-zero AC components, so
        // we do not bother to check for the all-zero case.
        
        // Prescale.
        int32_t y0 = (intermed[8*0+x] << 8) + 8192;
        int32_t y1 = intermed[8*4+x] << 8;
        int32_t y2 = intermed[8*6+x];
        int32_t y3 = intermed[8*2+x];
        int32_t y4 = intermed[8*1+x];
        int32_t y5 = intermed[8*7+x];
        int32_t y6 = intermed[8*5+x];
        int32_t y7 = intermed[8*3+x];
        
        // Stage 1.
        int32_t y8 = w7*(y4+y5) + 4;
        y4 = (y8 + w1mw7*y4) >> 3;
        y5 = (y8 - w1pw7*y5) >> 3;
        y8 = w3*(y6+y7) + 4;
        y6 = (y8 - w3mw5*y6) >> 3;
        y7 = (y8 - w3pw5*y7) >> 3;
        
        // Stage 2.
        y8 = y0 + y1;
        y0 -= y1;
        y1 = w6*(y3+y2) + 4;
        y2 = (y1 - w2pw6*y2) >> 3;
        y3 = (y1 + w2mw6*y3) >> 3;
        y1 = y4 + y6;
        y4 -= y6;
        y6 = y5 + y7;
        y5 -= y7;
        
        // Stage 3.
        y7 = y8 + y3;
        y8 -= y3;
        y3 = y0 + y2;
        y0 -= y2;
        y2 = (r2*(y4+y5) + 128) >> 8;
        y4 = (r2*(y4-y5) + 128) >> 8;
        
        // Stage 4.
        outp[8*0+x] = (y7 + y1) >> 11;
        outp[8*1+x] = (y3 + y2) >> 11;
        outp[8*2+x] = (y0 + y4) >> 11;
        outp[8*3+x] = (y8 + y6) >> 11;
        outp[8*4+x] = (y8 - y6) >> 11;
        outp[8*5+x] = (y0 - y4) >> 11;
        outp[8*6+x] = (y3 - y2) >> 11;
        outp[8*7+x] = (y7 - y1) >> 11;
    }
}

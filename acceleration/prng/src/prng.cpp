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

// pseudo random number generator Example

#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <assert.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <vector>
#include <time.h>

#include "xcl2.hpp"
#include "dma.h"
#include "prng.h"


#if defined(__linux__) || defined(linux)
    #include "sys/time.h"
#elif defined(WIN32)
    #include "windows.h"
#endif


double timestamp() {
    double ms = 0.0;
    #if  defined(__linux__) || defined(linux)
        timeval time;
        gettimeofday(&time, NULL);
        ms = (time.tv_sec * 1000.0) + (time.tv_usec / 1000.0);
    #elif defined(WIN32)
        SYSTEMTIME time;
        GetSystemTime(&time);
        ms = (time.wSeconds * 1000) + time.wMilliseconds;
    #endif
    return ms;
}

//______________________________________________________________________________
// initialize the seed table

void initCMWC(data_t* Q, int NC) {
    for (int i = 0; i < CMWC_CYCLE; i++)
        Q[i] = (i << 16) | NC;
}

//______________________________________________________________________________
int nofBlock;
int nofSample;

void parseArguments(int argc, char** argv) {
    if (argc==2) {
        nofBlock = 1024;
    } else if (argc==3) {
        nofBlock = atoi(argv[2]);
        if (nofBlock > maxNofBlock) {
            cout << "max number of block must be < " << maxNofBlock <<endl;
            exit(0);
        }
    } else {
        cout << "USAGE: " << argv[0] << " <XCLBIN File>" << " <number of blocks>" <<endl;
        exit(0);
    }

    nofSample =  nofBlock * maxSizeOfBlock * nofPRNG;
    cout << endl << ">>>> total number of samples (32bit) = " << nofSample << endl;

}


void processInCPU ( data_t* Dout_sw, data_t* Q);
void checkResults( dout_t* Dout_hw, data_t* Dout_sw);

//______________________________________________________________________________
int main(int argc, char** argv) {

    parseArguments(argc, argv);
    std::string binaryFile = argv[1];

// seed table    
    std::vector<data_t> Q_sw(nofPRNG*CMWC_CYCLE);
    std::vector<data_t,aligned_allocator<data_t>> Q_hw(nofPRNG*CMWC_CYCLE);

// results from SW, 32 bit each
    std::vector<data_t> Dout_sw(nofSample);

// results from HW, (32 * number of PRNG) per sample
    std::vector<dout_t,aligned_allocator<dout_t>> Dout_hw(nofBlock*maxSizeOfBlock);

// SW processing
    processInCPU ( Dout_sw.data(), Q_sw.data());

// initialize seed table
    for (int j=0; j<nofPRNG; j++ ) {
        initCMWC (&Q_hw[j*CMWC_CYCLE], j);
    }

    std::cout << "Creating context..." << std::endl;

    cl_int err;
    unsigned fileBufSize;
    std::vector<cl::Device> devices = xcl::get_xil_devices();
    cl::Device device = devices[0];

    OCL_CHECK(err, cl::Context context(device, NULL, NULL, NULL, &err));
    OCL_CHECK(err, cl::CommandQueue q(context, device, CL_QUEUE_PROFILING_ENABLE, &err));
    OCL_CHECK(err, std::string device_name = device.getInfo<CL_DEVICE_NAME>(&err));

    char* fileBuf = xcl::read_binary_file(binaryFile, fileBufSize);
    cl::Program::Binaries bins{{fileBuf, fileBufSize}};
    devices.resize(1);
    OCL_CHECK(err, cl::Program program(context, devices, bins, NULL, &err));
    OCL_CHECK(err, cl::Kernel krnl(program,"dma", &err));

    std::cout << "Creating Buffers..." << std::endl;
    OCL_CHECK(err, cl::Buffer cmem_Q(context,CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY,
                            sizeof(data_t) * CMWC_CYCLE * nofPRNG, Q_hw.data(), &err));

    OCL_CHECK(err, cl::Buffer cmem_output(context,CL_MEM_USE_HOST_PTR | CL_MEM_WRITE_ONLY,
                            sizeof(dout_t) * nofBlock * maxSizeOfBlock, Dout_hw.data(), &err));

    std::cout << "Starting Kernel..." << std::endl;
    OCL_CHECK(err, err = krnl.setArg(0, cmem_output));
    OCL_CHECK(err, err = krnl.setArg(1, cmem_Q));
    OCL_CHECK(err, err = krnl.setArg(2, sizeof(int), &nofBlock));

    std::cout << "Copying Buffers to device...." << std::endl;
    OCL_CHECK(err, err = q.enqueueMigrateMemObjects({cmem_Q}, 0/* 0 means from host*/));

    cl::Event event;
    unsigned long start = 0, stop = 0;

    OCL_CHECK(err, err = q.enqueueTask(krnl, NULL, &event));
    q.finish();

    OCL_CHECK(err, err = event.getProfilingInfo<unsigned long>(CL_PROFILING_COMMAND_START, &start));
    OCL_CHECK(err, err = event.getProfilingInfo<unsigned long>(CL_PROFILING_COMMAND_END, &stop));
    unsigned long duration = (stop - start);

    std::cout << "Kernel Duration: " << duration/1000000.0 << " ms" << std::endl;

    std::cout << "Copying results to host...." << std::endl;

    OCL_CHECK(err, err = q.enqueueMigrateMemObjects({cmem_output}, CL_MIGRATE_MEM_OBJECT_HOST))
    q.finish();

// check results
    checkResults( Dout_hw.data(), Dout_sw.data());

    delete[] fileBuf;

    std::cout << "Completed Successfully" << std::endl;

    return EXIT_SUCCESS;
}

//______________________________________________________________________________
void processInCPU ( data_t* Dout_sw, data_t* Q_sw ) {

    static randCMWC<CMWC_CYCLE, data_t> R_sw[nofPRNG];

    double startMS = timestamp();

    for (int j=0; j<nofPRNG; j++ ) {
        initCMWC (&Q_sw[j*CMWC_CYCLE], j);
        R_sw[j].init(&Q_sw[j*CMWC_CYCLE]);
    }

    for (int i=0; i< nofSample; i++ ) {
        int i_unit = i % nofPRNG;
        Dout_sw[i] = R_sw[i_unit].makeOne();
    }

    cout << endl << ">>>> CPU kernel: elapsed time (ms) = "<< timestamp() - startMS << endl;

}


//______________________________________________________________________________
void checkResults(dout_t *Dout_hw, data_t *Dout_sw) {

  // compare
    int err_cnt = 0;
    int i_word  = 0;
    int i_part  = 0;
    dout_t word_whole;
    data_t word_part;

#ifdef DEBUG
    for (int i=0; i<32; i++) {
        i_word = i / nofPRNG;
        i_part = i % nofPRNG;

        cout <<"i = "<< i <<" = (" << i_word <<", "<< i_part;
        word_whole = Dout_hw[i_word];
        word_part  = word_whole(32*i_part+31, 32*i_part);
        cout <<" whole/part/sw = " << hex << word_whole <<" / "<< word_part <<" / "<<Dout_sw[i] <<endl;
        if (word_part != Dout_sw[i]) err_cnt++;
  }
#else
    for (int i=0; i<nofSample; i++) {
        i_word = i / nofPRNG;
        i_part = i % nofPRNG;
        word_whole = Dout_hw[i_word];
        word_part  = word_whole(32*i_part+31, 32*i_part);
        if (word_part != Dout_sw[i]) err_cnt++;
  }
#endif

    cout << "<<<<<<<<<<<<< error count = " << err_cnt << endl;

}


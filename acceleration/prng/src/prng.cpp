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
#include <time.h>
#include <CL/opencl.h>

#include "xcl.h"
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
	if (argc==1) {
		nofBlock = 1024;
	} else if (argc==2) {
		nofBlock = atoi(argv[2]);
		if (nofBlock > maxNofBlock) {
			cout << "max number of block must be < " << maxNofBlock <<endl;
			exit(0);
		}
	} else {
		cout << "USAGE: ./prng <number of blocks>" <<endl;
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

// seed table
	data_t Q_sw[nofPRNG*CMWC_CYCLE];
	data_t Q_hw[nofPRNG*CMWC_CYCLE];

// results from SW, 32 bit each
	data_t *Dout_sw;
	Dout_sw = new data_t[nofSample];

// results from HW, (32 * number of PRNG) per sample
	dout_t *Dout_hw;
	Dout_hw = new dout_t[nofBlock*maxSizeOfBlock];

// SW processing
	processInCPU ( Dout_sw, Q_sw);

	std::cout << "Creating context..." << std::endl;
	xcl_world world = xcl_world_single();
	cl_program program = xcl_import_binary(world, "dma");
	cl_kernel krnl = xcl_get_kernel(program, "dma");

	std::cout << "Creating Buffers..." << std::endl;
	cl_mem cmem_Q = xcl_malloc(world, CL_MEM_READ_ONLY,sizeof(data_t) * CMWC_CYCLE * nofPRNG);
	cl_mem cmem_output = xcl_malloc(world,CL_MEM_WRITE_ONLY, sizeof(dout_t) * nofBlock * maxSizeOfBlock);


// initialize seed table
	for (int j=0; j<nofPRNG; j++ ) {
		initCMWC (&Q_hw[j*CMWC_CYCLE], j);
	}

	std::cout << "Copying Buffers to device...." << std::endl;
	xcl_memcpy_to_device(world, cmem_Q,Q_hw,sizeof(data_t) * CMWC_CYCLE * nofPRNG);


	std::cout << "Starting Kernel..." << std::endl;
	xcl_set_kernel_arg(krnl, 0, sizeof(cl_mem), &cmem_output);
	xcl_set_kernel_arg(krnl, 1, sizeof(cl_mem), &cmem_Q);
	xcl_set_kernel_arg(krnl, 2, sizeof(int),    &nofBlock);

	unsigned long duration = xcl_run_kernel3d(world, krnl, 1, 1, 1);
	std::cout << "Kernel Duration: " << duration/1000000.0 << " ms" << std::endl;

	std::cout << "Copying results to host...." << std::endl;
	xcl_memcpy_from_device(world, Dout_hw, cmem_output, sizeof(dout_t) * nofBlock * maxSizeOfBlock);

// check results
	checkResults( Dout_hw, Dout_sw );

	delete[] Dout_hw;
	delete[] Dout_sw;


	clReleaseMemObject(cmem_Q);
	clReleaseMemObject(cmem_output);
	clReleaseKernel(krnl);
	clReleaseProgram(program);
	xcl_release_world(world);

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

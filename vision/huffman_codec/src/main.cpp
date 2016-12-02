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
#include <iostream>
#include <assert.h>
#include "cmdlineparser.h"
#include "logger.h"
#include "huffmancodec_naive.h"
#include "huffmancodec_optimized_cpuonly.h"
#include "huffmancodec_optimized.h"

using namespace std;
using namespace sda;
using namespace sda::cl;
using namespace sda::utils;


static bool unit_test_codec(ICodec* pHuffmanCodec) {
	if(pHuffmanCodec == NULL)
		return false;

	string msgs[] = {"AABBCCCC",
					 "Xilinx SDAccel Benchmarking",
					 "Hello Pourya Shirazian",
					 "The quick brown fox jumps over the lazy dog."};

	u32 total = sizeof(msgs) / sizeof(msgs[0]);
	u32 ctPassed = 0;
	for(u32 i = 0; i < total; i++) {
		vector<u8> encoded_data;
		string out_str;

		int res = pHuffmanCodec->enc_str(msgs[i], encoded_data);
		res &= pHuffmanCodec->dec_str(encoded_data, out_str);

		if(msgs[i] == out_str) {
			LogInfo("Test [%u of %u] PASS", i+1, total);
			ctPassed++;
		}
		else
		{
			LogError("Test [%u of %u] Failed! (input: %s, output: %s)", msgs[i].c_str(), out_str.c_str());
		}
	}

	LogInfo("End unit tests for kernels on the CPU");

	return(ctPassed == total);
}


int main(int argc, char* argv[]) {
	LogInfo("Xilinx Canonical Huffman Codec Application");

	{
	//we don't need this 
	/*	LogInfo("Unit test naive impl");
		HuffmanNaiveImpl naive;
		assert(unit_test_codec(&naive));*/


	/*	LogInfo("Unit test optimized cpu-only");
		HuffmanOptimizedCPUOnly cpuonly;
		assert(unit_test_codec(&cpuonly));*/
	}




	string strKernelFullPath = sda::GetApplicationPath() + "/";

	//parse commandline
	CmdLineParser parser;
	parser.addSwitch("--bitmap", "-b", "input bitmap file path", "rect_1024.bmp");
	parser.addSwitch("--platform-name", "-p", "OpenCl platform vendor name", "xilinx");
	parser.addSwitch("--device-name", "-d", "OpenCl device name", "fpga0");
	parser.addSwitch("--kernel-file", "-k", "OpenCl kernel file to use");
	parser.addSwitch("--select-device", "-s", "Select from multiple matched devices [0-based index]", "0");
	parser.addSwitch("--number-of-runs", "-n", "Number of times the kernel runs on the device to compute the average.", "1");
	parser.setDefaultKey("--kernel-file");
	parser.parse(argc, argv);

	if(parser.isValid("kernel-file"))
		strKernelFullPath += parser.value("kernel-file");
	else {
		LogError("Please pass in a valid kernel file path relative to the exe file path.");
		parser.printHelp();
		return -1;
	}

	//bitmap file exist?
	if(!is_file(parser.value("bitmap"))) {
		LogError("Input bitmap file: %s does not exist!", parser.value("bitmap").c_str());
		parser.printHelp();
		return -1;
	}

	//read settings
	string strBitmapFP = parser.value("bitmap");
	string strPlatformName = parser.value("platform-name");
	string strDeviceName = parser.value("device-name");

	int nruns = parser.value_to_int("number-of-runs");
	int idxSelectedDevice = parser.value_to_int("select-device");
  
  	LogInfo("Chosen bitmap file is %s",strBitmapFP.c_str());
	LogInfo("Chosen kernel file is %s", strKernelFullPath.c_str());
	LogInfo("Chosen Platform = %s, Device Name: %s, Device Index: [%d]", strPlatformName.c_str(), strDeviceName.c_str(), idxSelectedDevice);
	HuffmanOptimized huffman();//strPlatformName, strDeviceName, idxSelectedDevice, strKernelFullPath, strBitmapFP);

	//LogInfo("Perform some unit tests before the actual image decode, encode");
	//unit_test_codec(&huffman);

	//Execute benchmark application
	/*LogInfo("Run HUFFMAN on FPGA with an image dataset. nruns = [%d]", nruns);
	bool res = huffman.run(0, nruns);
	if(!res) {
		LogError("An error occurred when running benchmark on device 0");
		return -1;
	}*/


	LogInfo("finished");

	return 0;
}



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
#include <iostream>
#include <assert.h>
#include "cmdlineparser.h"
#include "logger.h"
#include "huffmancodec_naive.h"
#include "huffmancodec_optimized_cpuonly.h"
#include "huffmancodec_optimized.h"

using namespace std;
using namespace sda;
using namespace sda::utils;

static void print_huffman_encoded_data(vector<u8> data) {

	u32 msg_len = (data[0]) |
	              (data[1] << 4) |
	              (data[2] << 8) |
	              (data[3] << 16);

	size_t s = data[4];

	std::cout << std::dec << "MSG_LEN: " << msg_len << std::endl;
	std::cout << std::dec << "S: " << s << std::endl;

	size_t bitcode_bits = 0;


	for(size_t i = 0; i < s; i++) {
		char sym = data[5+2*i];
		size_t len = data[5+2*i+1];
		bitcode_bits += len;

		std::cout << "\t" << sym << ": " << len << std::endl;
	}

	size_t bitcode_bytes = (bitcode_bits + 7) / 8;

	std::cout << "BITCODE: ";
	for(size_t i = 0; i < bitcode_bytes; i++) {
		std::cout << std::hex << std::setfill('0') << std::setw(2) << (unsigned) data[5+2*s+i];
	}
	std::cout << std::endl;

	size_t o = 5+2*s+bitcode_bytes;
	u32 payload_size = (data[o+0]) |
	                   (data[o+1] << 4) |
	                   (data[o+2] << 8) |
	                   (data[o+3] << 16);
	size_t payload_rem = data[o+4];

	std::cout << std::dec << "Payload Size: " << payload_size-1 << " bytes + " << payload_rem << " bits" << std::endl;

	std::cout << "PAYLOAD: ";
	for(size_t i = 0; i < payload_size-1; i++) {
		std::cout << std::hex << std::setfill('0') << std::setw(2) << (unsigned) data[o+4+i];
	}
	u8 mask = 0xFF >> (8 - payload_rem);
	u8 last = data[o+4+payload_size-1] & mask;

	std::cout << std::hex << (unsigned) last << " (" << (unsigned) mask << ")" << std::endl;

}

static bool unit_test_codec(ICodec* pHuffmanCodec, ICodec* pHuffmanCodecGold) {
	if(pHuffmanCodec == NULL)
		return false;

	string msgs[] = {"AABBCCCC",
					 "Xilinx SDAccel Benchmarking",
					 "Hello Pourya Shirazian",
					 "The quick brown fox jumps over the lazy dog."};

	u32 total = sizeof(msgs) / sizeof(msgs[0]);
	u32 ctPassed = 0;
	for(u32 i = 0; i < total; i++) {
		vector<u8> gold_data;
		vector<u8> encoded_data;
		string out_str;
		string gold_str;

		pHuffmanCodecGold->enc_str(msgs[i], gold_data);
		int res = pHuffmanCodec->enc_str(msgs[i], encoded_data);
		res &= pHuffmanCodecGold->dec_str(encoded_data, out_str);

		std::cout << "Encoded Data" << std::endl;
		print_huffman_encoded_data(encoded_data);

		std::cout << "Golden Data" << std::endl;
		print_huffman_encoded_data(gold_data);

		if(msgs[i] == out_str) {
			LogInfo("Test [%u of %u] PASS (%s)", i+1, total, out_str.c_str());
			ctPassed++;
		} else {
			LogError("Test [%u of %u] Failed! (input: %s, output: %s)", i+1, total, msgs[i].c_str(), out_str.c_str());
		}
	}

	LogInfo("End unit tests for kernels on the CPU");

	return(ctPassed == total);
}


int main(int argc, char* argv[]) {
	LogInfo("Xilinx Canonical Huffman Codec Application");

	LogInfo("Unit test optimized cpu-only");
	HuffmanOptimizedCPUOnly cpuonly;

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
	HuffmanOptimized huffman(strPlatformName, strDeviceName, idxSelectedDevice, strKernelFullPath, strBitmapFP);

	LogInfo("Perform some unit tests before the actual image decode, encode");
	unit_test_codec(&huffman,&cpuonly);

	//Execute benchmark application
	LogInfo("Run huffman on FPGA with an image dataset. nruns = [%d]", nruns);
	bool res = huffman.run(0, nruns);
	if(!res) {
		LogError("An error occurred when running benchmark on device 0");
		return -1;
	}

	LogInfo("finished");

	return 0;
}


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
#include "aes_app.h"
#include "cmdlineparser.h"
#include "logger.h"

using namespace std;
using namespace sda;
using namespace sda::cl;
using namespace sda::utils;


//pass cmd line options to select opencl device
int main(int argc, char* argv[]) {

	LogInfo("Xilinx AES-Decrypt Application started");
	string strKernelFullPath = sda::GetApplicationPath() + "/";

	//parse commandline
	CmdLineParser parser;
	parser.addSwitch("--bitmap", "-b", "input bitmap file path", "input.bmp");
	parser.addSwitch("--platform-name", "-p", "OpenCl platform vendor name", "xilinx");
	parser.addSwitch("--device-name", "-d", "OpenCl device name", "fpga0");
	parser.addSwitch("--kernel-file", "-k", "OpenCl kernel file to use");
	parser.addSwitch("--select-device", "-s", "Select from multiple matched devices [0-based index]", "0");
	parser.addSwitch("--number-of-runs", "-n", "Number of times the kernel runs on the device to compute the average.", "1");
	parser.addSwitch("--output", "-o", "results output file", "result.json");
	parser.setDefaultKey("--kernel-file");
	parser.parse(argc, argv);

	//bitmap file exist?
	if(!is_file(parser.value("bitmap"))) {
		LogError("Input bitmap file: %s does not exist!", parser.value("bitmap").c_str());
		return -1;
	}

	string strPlatformName = parser.value("platform-name");
	string strDeviceName = parser.value("device-name");
	string strBitmapFP = parser.value("bitmap");
	int nruns = parser.value_to_int("number-of-runs");
	int idxSelectedDevice = parser.value_to_int("select-device");

	AesApp aesapp(strPlatformName, strDeviceName, idxSelectedDevice, strKernelFullPath, strBitmapFP);

	//Execute benchmark application
	bool res = aesapp.run(0, nruns);
	if(!res) {
		LogError("An error occurred when running benchmark on device 0");
		return -1;
	}

	LogInfo("finished");

	return 0;
}

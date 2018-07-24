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
#include "aes_app.h"
#include "cmdlineparser.h"
#include "logger.h"


//pass cmd line options to select opencl device
int main(int argc, char* argv[]) {

	LogInfo("Xilinx AES-Decrypt Application started");
	string strKernelFullPath = sda::GetApplicationPath() + "/";
	bool validateGoldFile = false;
	//parse commandline
	sda::utils::CmdLineParser parser;
	parser.addSwitch("--inputfile", "-b", "input file path", "test.txt");
	parser.addSwitch("--goldFile", "-g", "gold file path", "goldfile.txt");
	parser.setDefaultKey("--kernel-file");
	parser.parse(argc, argv);

	//input file exist?
	if(!sda::utils::is_file(parser.value("inputfile"))) {
		LogError("Input file: %s does not exist!", parser.value("inputfile").c_str());
		return -1;
	}
	
	if(sda::utils::is_file(parser.value("goldFile"))) {
		validateGoldFile = true;
	}
	std::string strfileFP = parser.value("inputfile");
	std::string strGoldFileFP = parser.value("goldFile");
	
	AesApp aesapp(strfileFP, validateGoldFile, strGoldFileFP);

	//Execute benchmark application
	bool res = aesapp.run();
	if(!res) {
		LogError("An error occurred when running benchmark on device 0");
		return -1;
	}

	LogInfo("finished");

	return 0;
}

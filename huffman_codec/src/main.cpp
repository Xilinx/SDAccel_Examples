//============================================================================
// Name        : main.cpp
// Author      : Pourya Shirazian
// Version     : 0.1
// Copyright   : Xilinx 2015
// Description : Huffman Based on Gauntlet Foundation code for development of benchmark apps in C++, Ansi-style
//============================================================================

#include <iostream>
#include <assert.h>
#include "huffmanapp.h"
#include "cmdlineparser.h"
#include "logger.h"

using namespace std;
using namespace sda;
using namespace sda::cl;
using namespace sda::utils;


int main(int argc, char* argv[]) {
	LogInfo("Xilinx Canonical Huffman Codec Application");
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

	LogInfo("Chosen kernel file is %s", strKernelFullPath.c_str());
	LogInfo("Chosen Platform = %s, Device Name: %s, Device Index: [%d]", strPlatformName.c_str(), strDeviceName.c_str(), idxSelectedDevice);
	HuffmanApp huffman(strPlatformName, strDeviceName, idxSelectedDevice, strKernelFullPath, strBitmapFP);

	//Execute benchmark application
	bool res = huffman.run(0, nruns);
	if(!res) {
		LogError("An error occurred when running benchmark on device 0");
		return -1;
	}


	LogInfo("finished");

	return 0;
}



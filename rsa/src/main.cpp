/*******************************************************************************
Vendor: Xilinx
Associated Filename: xcl.cpp
Purpose: SDAccel rsa example
Revision History: December 6, 2015

*******************************************************************************
Copyright (C) 2015 XILINX, Inc.

This file contains confidential and proprietary information of Xilinx, Inc. and
is protected under U.S. and international copyright and other intellectual
property laws.

DISCLAIMER
This disclaimer is not a license and does not grant any rights to the materials
distributed herewith. Except as otherwise provided in a valid license issued to
you by Xilinx, and to the maximum extent permitted by applicable law:
(1) THESE MATERIALS ARE MADE AVAILABLE "AS IS" AND WITH ALL FAULTS, AND XILINX
HEREBY DISCLAIMS ALL WARRANTIES AND CONDITIONS, EXPRESS, IMPLIED, OR STATUTORY,
INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, NON-INFRINGEMENT, OR
FITNESS FOR ANY PARTICULAR PURPOSE; and (2) Xilinx shall not be liable (whether
in contract or tort, including negligence, or under any other theory of
liability) for any loss or damage of any kind or nature related to, arising under
or in connection with these materials, including for any direct, or any indirect,
special, incidental, or consequential loss or damage (including loss of data,
profits, goodwill, or any type of loss or damage suffered as a result of any
action brought by a third party) even if such damage or loss was reasonably
foreseeable or Xilinx had been advised of the possibility of the same.

CRITICAL APPLICATIONS
Xilinx products are not designed or intended to be fail-safe, or for use in any
application requiring fail-safe performance, such as life-support or safety
devices or systems, Class III medical devices, nuclear facilities, applications
related to the deployment of airbags, or any other applications that could lead
to death, personal injury, or severe property or environmental damage
(individually and collectively, "Critical Applications"). Customer assumes the
sole risk and liability of any use of Xilinx products in Critical Applications,
subject only to applicable laws and regulations governing limitations on product
liability.

THIS COPYRIGHT NOTICE AND DISCLAIMER MUST BE RETAINED AS PART OF THIS FILE AT
ALL TIMES.

*******************************************************************************/


#include <CL/cl.h>
#include "common.h"
#include <openssl/bn.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <iostream>
#include <assert.h>
#include "rsa_app.h"
#include "cmdlineparser.h"
#include "logger.h"

using namespace std;
using namespace sda;
using namespace sda::cl;
using namespace sda::utils;


int main(int argc, char* argv[]) {
	LogInfo("Xilinx 1024 bit RSA Application");
	string strKernelFullPath = sda::GetApplicationPath() + "/";

	//parse commandline
	CmdLineParser parser;
	parser.addSwitch("--in", "-i", "input ciphertext file path", "0_0_1024_key.cip");
	parser.addSwitch("--out", "-o", "output plaintext file path", "0_out.msg");
	parser.addSwitch("--key", "-y", "rsa key file path", "0_1024_key.pem");
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

	//read settings
	string strInputFP = parser.value("in");
	string strOutputFP = parser.value("out");
	string strKeyFP = parser.value("key");
	string strPlatformName = parser.value("platform-name");
	string strDeviceName = parser.value("device-name");

	int nruns = parser.value_to_int("number-of-runs");
	int idxSelectedDevice = parser.value_to_int("select-device");

	LogInfo("Chosen kernel file is %s", strKernelFullPath.c_str());
	LogInfo("Chosen Platform = %s, Device Name: %s, Device Index: [%d]", strPlatformName.c_str(), strDeviceName.c_str(), idxSelectedDevice);
	RSAApp rsa(strPlatformName, strDeviceName, idxSelectedDevice, strKernelFullPath, strInputFP, strOutputFP, strKeyFP);

	//Execute benchmark application
	bool res = rsa.run(0, nruns);
	if(!res) {
		LogError("An error occurred when running benchmark on device 0");
		return -1;
	}


	LogInfo("finished");

	return 0;
}



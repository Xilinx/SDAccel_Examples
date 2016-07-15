/*******************************************************************************
Vendor: Xilinx
Associated Filename: logger.h
Purpose: SDAccel Applications Framework
Revision History: January 29, 2016

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

#ifndef LOGGER_H_
#define LOGGER_H_

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>


#define ENABLE_LOG_TOFILE 1
#define ENABLE_LOG_TIME 1

//global logging
#define LogInfo(desc, ...) sda::LogWrapper(0, __FILE__, __LINE__, desc, ##__VA_ARGS__)
#define LogWarn(desc, ...) sda::LogWrapper(1, __FILE__, __LINE__, desc, ##__VA_ARGS__)
#define LogError(desc, ...) sda::LogWrapper(2, __FILE__, __LINE__, desc, ##__VA_ARGS__)

using namespace std;

namespace sda {

	enum LOGTYPE {etInfo, etWarning, etError};

	//string
	string& ltrim(string& s);
	string& rtrim(string& s);
	string& trim(string& s);
	string GetFileExt(const string& s);
	string GetFileTitleOnly(const string& s);

	string ToLower(const string& s);
	string ToUpper(const string& s);

	//time
	string GetTimeStamp();

	//paths
	string GetApplicationPath();


	//debug
	template<typename T>
	void PrintPOD(const vector<T>& pod, size_t display_count = 0, const int precision = 4) {

		size_t count = pod.size();
		if(display_count > 0)
			count = std::min<size_t>(pod.size(), display_count);

		for(size_t i = 0; i < count; i++) {
			cout << std::setprecision(precision) << pod[i] << ", ";
		}
		cout << endl;
	}

	//logging
	void LogWrapper(int etype, const char* file, int line, const char* desc, ...);

}



#endif /* LOGGER_H_ */

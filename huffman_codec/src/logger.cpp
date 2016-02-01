/*******************************************************************************
Vendor: Xilinx
Associated Filename: logger.cpp
Purpose: SDAccel huffman codec example
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

#include <time.h>
#include <stdarg.h>
#include <functional>
#include <algorithm>
#include <fstream>
#include "logger.h"
#ifdef WINDOWS
		#include <direct.h>
#else
	#include <unistd.h>
#endif

using namespace std;

namespace sda {

///////////////////////////////////////////////////////////////////////
string GetApplicationPath() {
	#ifdef WINDOWS
		#define GetCurrentDir _getcwd
	#else
		#define GetCurrentDir getcwd
	#endif

	char strCurrentPath[FILENAME_MAX];

	if (!GetCurrentDir(strCurrentPath, sizeof(strCurrentPath))) {
		return string("");
	}

	/* not really required */
	strCurrentPath[sizeof(strCurrentPath) - 1] = '\0';
	return string(strCurrentPath);
}

string ToLower(const string& s) {
	string result = s;
	std::transform(result.begin(), result.end(), result.begin(), ::tolower);
	return result;
}

string ToUpper(const string& s) {
	string result = s;
	std::transform(result.begin(), result.end(), result.begin(), ::toupper);
	return result;
}

string GetTimeStamp() {
	return "";
}


// trim from start
string& ltrim(std::string &s) {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
        return s;
}

// trim from end
string& rtrim(std::string &s) {
        s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
        return s;
}

// trim from both ends
string& trim(std::string &s) {
	return ltrim(rtrim(s));
}

string GetFileExt(const string& s) {
	string strext = s.substr(s.find_last_of(".") + 1);
	return strext;
}

string GetFileTitleOnly(const string& s) {

	string temp = s;
	string::size_type d = temp.find_last_of("//");
	if(d == string::npos)
		d = temp.find_last_of("\\");
	if(d != string::npos)
		temp = temp.substr(d + 1);

	d = temp.find_last_of(".");
	if(d != string::npos)
		temp = temp.substr(0, d);

	return temp;
}


void LogWrapper(int etype, const char* file, int line, const char* desc, ...) {

	//crop file name from full path
	string strFileLoc(file);
	strFileLoc = strFileLoc.substr(strFileLoc.find_last_of("\\/") + 1);

	string strHeader = "";
	{
		char header[512];
		//source
		switch(etype) {
			case(sda::etError): {
				snprintf(header, sizeof(header), "ERROR: [%s:%d]", strFileLoc.c_str(), line);
				break;
			}
			case(sda::etInfo): {
				snprintf(header, sizeof(header), "INFO: [%s:%d]", strFileLoc.c_str(), line);
				break;
			}
			case(sda::etWarning): {
				snprintf(header, sizeof(header), "WARN: [%s:%d]", strFileLoc.c_str(), line);
				break;
			}
		}
		strHeader = string(header);
	}

	//time
	string strTime = "";
#ifdef ENABLE_LOG_TIME
	{
		time_t rawtime;
		time (&rawtime);
	#ifdef ENABLE_SECURE_API
		char buffer[64];
		struct tm timeinfo;
		localtime_s(&timeinfo, &rawtime);
		asctime_s(timeinfo, buffer, sizeof(buffer))
		snprintf(buffer, sizeof(buffer), "TIME: [%s]", asctime(timeinfo));
		strTime = string(buffer);
	#else
		char buffer[64];
		struct tm * timeinfo = localtime ( &rawtime );
		string temp = string(asctime(timeinfo));
		temp = trim(temp);

//		strftime(buffer, sizeof(buffer), "TIME: []")
		snprintf(buffer, sizeof(buffer), "TIME: [%s]", temp.c_str());
		strTime = string(buffer);
	#endif
	}
#endif

	//format the message itself
	string strMsg = "";
	{
		char msg[512];
		va_list args;
		va_start(args, desc);
		vsnprintf(msg, sizeof(msg), desc, args);
		va_end(args);
		strMsg = string(msg);
	}

	//combine
	string strOut = strHeader + string(" ") + strTime + string(" ") + strMsg + string("\n");

	//display
	cout << strOut;

	//store
#ifdef ENABLE_LOG_TOFILE
	std::ofstream outfile;
	outfile.open("benchapp.log", std::ios_base::app);
	outfile << strOut;
#endif

	return;
}

}





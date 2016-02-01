/*******************************************************************************
Vendor: Xilinx
Associated Filename: cmdlineparser.h
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


#ifndef CMDLINEPARSER_H_
#define CMDLINEPARSER_H_

#include <map>
#include <string>
#include <vector>

using namespace std;

namespace sda {
namespace utils {

bool is_file(const std::string& name);

/*!
 * Synopsis:
 * 1.Parses the command line passed in from the user and stores all enabled
 * 	 system options.
 * 2.Prints help for the user if an option is not valid.
 * 3.Stores options and provides a mechanism to read those options
 */
class CmdLineParser {
public:
	class CmdSwitch {
	public:
		CmdSwitch() {}
		CmdSwitch(const CmdSwitch& rhs) {
			copyfrom(rhs);
		}

		void copyfrom(const CmdSwitch& rhs) {
			this->key = rhs.key;
			this->shortcut = rhs.shortcut;
			this->default_value = rhs.default_value;
			this->value = rhs.value;
			this->desc = rhs.desc;
			this->istoggle = rhs.istoggle;
			this->isvalid = rhs.isvalid;
		}

		CmdSwitch& operator=(const CmdSwitch& rhs) {
			this->copyfrom(rhs);
			return *this;
		}
	public:
		string key;
		string shortcut;
		string default_value;
		string value;
		string desc;
		bool istoggle;
		bool isvalid;
	};

public:
	CmdLineParser();
	//CmdLineParser(int argc, char* argv[]);
	virtual ~CmdLineParser();


	bool addSwitch(const CmdSwitch& s);
	bool addSwitch(const string& name, const string& shortcut,
					const string& desc, const string& default_value = "",
					bool istoggle = false);

	/*!
	 * sets default key to be able to read a 2 argumented call
	 */
	bool setDefaultKey(const char* key);

	/*!
	 * parse and store command line
	 */
	int parse(int argc, char* argv[]);

	/*!
	 * retrieve value using a key
	 */
	string value(const char* key);

	int value_to_int(const char* key);


	double value_to_double(const char* key);

	/*!
	 * Returns true if a valid value is supplied by user
	 */
	bool isValid(const char* key);

	/*!
	 * prints the help menu in case the options are not correct.
	 */
	virtual void printHelp();

protected:
	/*!
	 * Retrieve command switch
	 */
	CmdSwitch* getCmdSwitch(const char* key);

	bool token_to_fullkeyname(const string& token, string& fullkey);


private:
	map<string, CmdSwitch*> m_mapKeySwitch;
	map<string, string> m_mapShortcutKeys;
	vector<CmdSwitch*> m_vSwitches;
	string m_strDefaultKey;
	string m_appname;
};

//bool starts_with(const string& src, const string& sub);

}
}
#endif /* CMDLINEPARSER_H_ */

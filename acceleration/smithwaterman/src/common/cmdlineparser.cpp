/*******************************************************************************
Vendor: Xilinx
Associated Filename: cmdlineparser.cpp
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

#include <assert.h>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include "cmdlineparser.h"
#include "logger.h"

namespace sda {
namespace utils {

bool is_file (const std::string& name) {
    ifstream f(name.c_str());
    if (f.good()) {
        f.close();
        return true;
    } else {
        f.close();
        return false;
    }
}

bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

bool starts_with(const string& src, const string& sub) {
	return (src.find(sub) == 0);
}

CmdLineParser::CmdLineParser() {
	// TODO Auto-generated constructor stub
	m_strDefaultKey = "";
	m_appname = "application.exe";
	addSwitch("--help", "-h", "prints this help list", "", true);
}

/*
CmdLineParser::CmdLineParser(int argc, char* argv[]) {
	// TODO Auto-generated constructor stub
	assert(parse(argc, argv) > 0);

}
*/

CmdLineParser::~CmdLineParser() {
	// TODO Auto-generated destructor stub
	for(size_t i = 0; i < m_vSwitches.size(); i++) {
		delete m_vSwitches[i];
		m_vSwitches[i] = NULL;
	}

	m_vSwitches.resize(0);
}

bool CmdLineParser::addSwitch(const CmdSwitch& s) {

	CmdSwitch cmd = s;

	if(cmd.desc.length() == 0) {
		LogError("No description provided!");
		return false;
	}

	//check input
	if(cmd.key.find("--") != 0 || cmd.key.length() < 3) {
		LogError("The input key is invalid. Please start with -- and keep a length >= 3");
		return false;
	}

	if(m_mapKeySwitch.find(cmd.key) != m_mapKeySwitch.end()) {
		LogError("This key %s is taken already!", cmd.key.c_str());
		return false;
	}

	if(cmd.shortcut.length() == 0) {

		string temp = "-" + cmd.key[2];

		int i = 3;
		while(m_mapShortcutKeys.find(temp) != m_mapShortcutKeys.end() && (size_t)i < cmd.key.length()) {
			temp = "-" + s.key[i];
			i++;
		}

		cmd.shortcut = temp;
		LogInfo("Automatic shortcut assigned %s to %s", temp.c_str(), cmd.key.c_str());
	}

	if(s.istoggle) {
		cmd.default_value = string("false");
		cmd.value = cmd.default_value;
		cmd.isvalid = true;
	}
	else {
		cmd.value = cmd.default_value;
		cmd.isvalid = false;
	}

	//add
	CmdSwitch* pcmd = new CmdSwitch(cmd);
	m_vSwitches.push_back(pcmd);
	m_mapShortcutKeys[s.shortcut] = cmd.key;
	m_mapKeySwitch[s.key] = pcmd;

	return true;
}


bool CmdLineParser::addSwitch(const string& name, const string& shortcut,
				const string& desc, const string& default_value,
				bool istoggle) {

	CmdSwitch s;
	s.key = name;
	s.shortcut = shortcut;
	s.desc = desc;
	s.default_value = default_value;
	s.istoggle = istoggle;

	return addSwitch(s);
}

bool CmdLineParser::setDefaultKey(const char* key) {
	string strKey(key);
	if(!starts_with(strKey, "--"))
		strKey = "--" + strKey;

	if(m_mapKeySwitch.find(strKey) != m_mapKeySwitch.end()) {
		CmdSwitch* pcmd = m_mapKeySwitch[m_strDefaultKey];
		if(pcmd != NULL) {
			if(pcmd->istoggle) {
				LogError("Boolean command line options can not be used as default keys");
				return false;
			}
		}

		//set default key
		m_strDefaultKey = strKey;
		return true;
	}
	else
		return false;
}

int CmdLineParser::parse(int argc, char* argv[]) {

	int i = 0;
	int ctOptions = 0;
	while(i < argc) {
		string key, val;
		bool iskey = false;
		string token = string(argv[i]);

		bool isNextTokenKey = false;
		if(i + 1 < argc) {
			 string peeknext = string(argv[i+1]);
			 if(starts_with(peeknext, "-") || starts_with(peeknext, "--")) {
				 string fullkey;
				 isNextTokenKey = token_to_fullkeyname(peeknext, fullkey);
			 }
		}




		//full-key
		if(starts_with(token, string("--"))) {
			if(m_mapKeySwitch.find(token) == m_mapKeySwitch.end()) {
				LogError("Unrecognized key passed %s", token.c_str());
				printHelp();
				return -1;
			}

			key = token;
			iskey = true;
		}
		//shortcut
		else if(starts_with(token, "-")) {
			if(m_mapShortcutKeys.find(token) == m_mapShortcutKeys.end()) {
				LogError("Unrecognized shortcut key passed %s", token.c_str());
				printHelp();
				return -1;
			}

			key = m_mapShortcutKeys[token];
			iskey = true;
		}
		//default key, the value for default key is the last argument
		else if(isNextTokenKey == false && m_strDefaultKey.length() > 0 && i == argc - 2) {
			if(m_mapKeySwitch.find(m_strDefaultKey) == m_mapKeySwitch.end()) {
				LogError("Unrecognized default key %s", m_strDefaultKey.c_str());
				printHelp();
				return -1;
			}

			LogInfo("Using default key: %s", m_strDefaultKey.c_str());
			key = m_strDefaultKey;
			iskey = true;
		}

		//if iskey and needs param then read it
		if(iskey) {
			ctOptions++;

			if(key == "--help") {
				printHelp();
				return 1;
			}

			//fetch value
			CmdSwitch* pcmd = m_mapKeySwitch[key];

			//read next
			if(pcmd->istoggle) {
				pcmd->value = string("true");
				pcmd->isvalid = true;
			}
			else {
				i++;
				pcmd->value = string(argv[i]);
				pcmd->isvalid = true;
			}

		}

		//next token
		i++;
	}

	//capture real app name
	if(argc > 0) {
		m_appname = string(argv[0]);
	}

	return ctOptions;
}

bool CmdLineParser::token_to_fullkeyname(const string& token, string& fullkey) {

	fullkey = "";
	int ctDashes = 0;
	if(starts_with(token, string("--")))
		ctDashes = 2;
	else if(starts_with(token, string("-")))
		ctDashes = 1;

	if(ctDashes == 0)
		return false;

	if(ctDashes == 2) {
		if(m_mapKeySwitch.find(token) == m_mapKeySwitch.end()) {
			LogError("Unrecognized key passed %s", token.c_str());
			return false;
		}
		fullkey = token;
	}
	else if(ctDashes == 1) {
		if(m_mapShortcutKeys.find(token) == m_mapShortcutKeys.end()) {
			LogError("Unrecognized shortcut key passed %s", token.c_str());
			return false;
		}

		fullkey = m_mapShortcutKeys[token];
	}

	return (fullkey.length() > 0);
}


string CmdLineParser::value(const char* key) {

	string strKey(key);
	if(!starts_with(strKey, "--"))
		strKey = "--" + strKey;

	if(m_mapKeySwitch.find(strKey) != m_mapKeySwitch.end())
		return m_mapKeySwitch[strKey]->value;
	else {
		LogWarn("The input key %s is not recognized!", strKey.c_str());
		return string("");
	}
}

int CmdLineParser::value_to_int(const char* key) {
	string strVal = value(key);
	if(strVal.length() == 0 || !is_number(strVal))
		return -1;
	return atoi(strVal.c_str());
}


double CmdLineParser::value_to_double(const char* key) {
	string strVal = value(key);
	if(strVal.length() == 0)
		return -1;
	return atof(strVal.c_str());
}

bool CmdLineParser::isValid(const char* key) {
	string strKey(key);
	if(!starts_with(strKey, "--"))
		strKey = "--" + strKey;

	if(m_mapKeySwitch.find(strKey) != m_mapKeySwitch.end())
		return m_mapKeySwitch[strKey]->isvalid;
	else {
		LogWarn("The input key %s is not recognized!", strKey.c_str());
		return false;
	}

}

void CmdLineParser::printHelp() {
	printf("===========================================================\n");
	string strAllShortcuts = "";
	for(size_t i=0; i < m_vSwitches.size(); i++) {
		CmdSwitch* pcmd = m_vSwitches[i];
		if(pcmd && pcmd->shortcut.length() > 0)
			strAllShortcuts = strAllShortcuts + pcmd->shortcut;
	}
	//example
	printf("Usage: %s -[%s]\n\n", m_appname.c_str(), strAllShortcuts.c_str());

	//row by row
	for(size_t i=0; i < m_vSwitches.size(); i++) {
		CmdSwitch* pcmd = m_vSwitches[i];

		if(pcmd->default_value.length() > 0)
			printf("\t%s, %s\t\t%s\t Default: [%s]\n", pcmd->key.c_str(), pcmd->shortcut.c_str(), pcmd->desc.c_str(), pcmd->default_value.c_str());
		else
			printf("\t%s, %s\t\t%s\n", pcmd->key.c_str(), pcmd->shortcut.c_str(), pcmd->desc.c_str());
	}
}

CmdLineParser::CmdSwitch* CmdLineParser::getCmdSwitch(const char* key) {
	string strKey(key);
	if(!starts_with(strKey, "--"))
		strKey = "--" + strKey;

	if(m_mapKeySwitch.find(strKey) != m_mapKeySwitch.end())
		return m_mapKeySwitch[strKey];
	else
		return NULL;

}


}
}

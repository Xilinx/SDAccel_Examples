/*******************************************************************************
Vendor: Xilinx 
Associated Filename: matcharray.cpp
Purpose: SWAN-HLS Sample - Dumps FPGA results
Revision History: February 12, 2016 - initial release
                                                
*******************************************************************************
Copyright (C) 2016 XILINX, Inc.

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
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <fstream>
#include "matcharray.h"
#include "logger.h"
#include "sw.h"

using namespace sda;
using namespace std;

#ifdef PUB_ZMQ
	#include "3rdparty/jsonxx/jsonxx.h"
	using namespace jsonxx;
#endif



extern void uintTouint2Array(int bufferSz, unsigned int *buffer, short *buffer2b);

#ifdef PUB_ZMQ
MatchArray::MatchArray(int nSamples, int rdSz, int rfSz, const zmq::socket_t* ppub)
#else
MatchArray::MatchArray(int nSamples, int rdSz, int rfSz)
#endif
{
    readSize = rdSz;
    refSize =  rfSz;
    numSamples = nSamples;

    readStrings = new char *[numSamples];
    for(int i = 0; i < numSamples; ++i){
        readStrings[i] = new char[rdSz+1];
    }
    refStrings = new char *[nSamples];
    for(int i = 0; i < numSamples; ++i){
        refStrings[i] = new char[rfSz+1];
    }
    maxv = new short[nSamples];
    maxr = new short[nSamples];
    maxc = new short[nSamples];

    m_counter = 0;

#ifdef PUB_ZMQ
    //publisher
    m_ppub = const_cast<zmq::socket_t*>(ppub);
#endif

}

MatchArray::~MatchArray(){
    delete [] maxv;
    delete [] maxr;
    delete [] maxc;
}

void MatchArray::populateArray(unsigned int *pairs, unsigned int *maxval){
    int numInt = READREFUINTSZ(readSize, refSize);
    short *readSeqT = new short[readSize];
    short *refSeqT  = new short[refSize];
    for(int i = 0; i < numSamples; ++i){
        unsigned int *onepair = pairs + numInt*i;
        uintTouint2Array(readSize/UINTNUMBP, onepair, readSeqT);
        uintTouint2Array(refSize/UINTNUMBP, onepair + readSize/UINTNUMBP, refSeqT);
        for(int j = 0; j < readSize; ++j){
            readStrings[i][j] = bases[readSeqT[j]];
            
        }
        readStrings[i][readSize] = '\0';
        for(int j = 0; j < refSize; ++j){
            refStrings[i][j] = bases[refSeqT[j]];
        }
        refStrings[i][refSize] = '\0';
        unsigned int *oneval = maxval + 3*i;
        maxr[i] = oneval[0];
        maxc[i] = oneval[1];
        maxv[i] = oneval[2];
    }
    delete [] readSeqT;
    delete [] refSeqT;
    
}


void MatchArray::populateArray(char **rd, char **rf, unsigned int *mr, unsigned int *mc, unsigned int *mv){
    for(int i = 0; i < numSamples; ++i){
        strcpy(readStrings[i], rd[i]);
        strcpy(refStrings[i], rf[i]);
        maxr[i] = mr[i];
        maxc[i] = mc[i];
        maxv[i] = mv[i];
    }
}

void MatchArray::dumpArray(){

#ifdef PUB_ZMQ
    //push samples to gateway
    jsonxx::Array root;

    for(int i = 0; i < numSamples; ++i){
    	jsonxx::Object current;

    	std::ostringstream ss;

    	ss << "V" << i;
    	current << ss.str();
    	ss.str(std::string());

    	ss << maxv[i];
        current << ss.str();
    	ss.str(std::string());
    	
        //add to root
        root << current;
    }

    //convert to string and dump the object
	std::string str = root.json();
	m_ppub->send((const void*) str.c_str(), str.length());

	m_counter++;
	std::cout << m_counter << ", ";
#endif
}

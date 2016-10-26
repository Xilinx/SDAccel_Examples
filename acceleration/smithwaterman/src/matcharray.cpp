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
	#include <jsonxx.h>
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

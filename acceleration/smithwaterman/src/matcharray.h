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

#ifndef __MATCH_ARRAY__
#define __MATCH_ARRAY__

#include <string>

#ifdef PUB_ZMQ
	#include "zmq.hpp"
#endif

using namespace std;

class MatchArray {
public:
#ifdef PUB_ZMQ
	MatchArray(int numSamples, int readSz, int refSz, const zmq::socket_t* ppub);
#else
	MatchArray(int numSamples, int readSz, int refSz);
#endif

	~MatchArray();
	void populateArray(unsigned int *pairs, unsigned int *maxval);
	void populateArray(char **rd, char **rf, unsigned int *mr, unsigned int *mc,
			unsigned int *mv);
	void dumpArray();

private:
#ifdef PUB_ZMQ
	zmq::socket_t* m_ppub;
#endif

	int m_counter;

	char **readStrings;
	char **refStrings;
	short *maxv;
	short *maxc;
	short *maxr;
	int numSamples;
	int readSize;
	int refSize;
};
#endif

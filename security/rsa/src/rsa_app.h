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

#ifndef RSAAPP_H_
#define RSAAPP_H_

#include <string>
#include <vector>
#include "common.h"
#include "xcl2.hpp"
#include <openssl/bn.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>

#define COMPUTE_UNITS 1

using namespace std;

class RSAApp {
public:
	RSAApp();
	RSAApp(const string& vendor_name,
	      const string& device_name,
	      int selected_device,
	      const string& strKernelFP,
	      const string& strInputFP,
	      const string& strOutputFP,
              const string& strKeyFP);
	virtual ~RSAApp();

	enum EvBreakDown {evtHostWrite = 0, evtKernelExec = 1, evtHostRead = 2, evtCount = 3};

	bool run(int idevice, int nruns);

	bool invoke_kernel(cl::Kernel kernel, cl_uint *message, cl_uint *Cp, cl_uint *Cq, cl_uint *p, cl_uint *q, cl_uint *dmp1, cl_uint *dmq1, cl_uint *iqmp,          cl_uint *r2p, cl_uint *r2q, cl::Event events[evtCount]);

	static double timestamp();
	static double computeEventDurationInMS(const cl::Event& event);

private:
	string m_strInputFP;
    string m_strOutputFP;
    string m_strKeyFP;
	
    cl::Context m_context;
    cl::CommandQueue m_q; 
	cl::Program m_program; 
	cl::Kernel m_clKernelRSA;
};

#endif /* RSAAPP_H_ */

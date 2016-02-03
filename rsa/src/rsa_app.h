/*******************************************************************************
Vendor: Xilinx
Associated Filename: cmdlineparser.cpp
Purpose: SDAccel rsa example
Revision History: Feb 2, 2016

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

#ifndef RSAAPP_H_
#define RSAAPP_H_

#include <string>
#include <vector>
#include "common.h"
#include "xcl.h"
#include <CL/cl.h>
#include <openssl/bn.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>


#define COMPUTE_UNITS 1

using namespace std;

namespace sda {
namespace cl {

/*!
 *
 */
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

	bool invoke_kernel(cl_kernel kernel, uint *message, uint * ciphertext, uint * d, uint * n,uint * r2, cl_event events[evtCount]);

	static double timestamp();
	static double computeEventDurationInMS(const cl_event& event);



protected:
	void cleanup();
	bool releaseMemObject(cl_mem &obj);

private:
	string m_strInputFP;
        string m_strOutputFP;
        string m_strKeyFP;
	xcl_world m_world;
	cl_kernel m_clKernelRSA;
};

}
}

#endif /* RSAAPP_H_ */

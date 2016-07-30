/*******************************************************************************
Vendor: Xilinx 
Associated Filename: smithwaterman.h
Purpose: SWAN-HLS Sample - Creates Classes for SWAN
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
#include <assert.h>
#ifndef SWAPP_H_
#define SWAPP_H_

#include "xcl.h"
#include "matcharray.h"

#define COMPUTE_UNITS 1

typedef unsigned char		u8;
typedef unsigned short		u16;
typedef unsigned int		u32;
typedef			 char		i8;
typedef			 short		i16;
typedef			 int		i32;


namespace sda {
namespace cl {

    /*!
 *
 */

    class SmithWatermanApp {
    public:        
        SmithWatermanApp(const string& vendor_name,
            const string& device_name,
            int selected_device,
            const string& strKernelFP,
            const string& strSampleFPi,
            const int numBlocks,
            const int blkSz,
            const bool doubleBuffered,
            const bool verifyMode,
            const bool writeMatchArray,
            MatchArray* pm);
        virtual ~SmithWatermanApp();

        enum EvBreakDown { evtHostWrite = 0,
            evtKernelExec = 1,
            evtHostRead = 2,
            evtCount = 3 };

        bool run(int idevice, int nruns);

        bool invoke_kernel(unsigned int* input, unsigned int* output, int* iterNum, int sz_input, int sz_output, int sz_sz, cl_event events[evtCount], double eTotal[evtCount]);
        bool invoke_kernel_blocking(unsigned int* input, unsigned int* output, int* iterNum, int sz_input, int sz_output, int sz_sz, cl_event events[evtCount], double eTotal[evtCount]);
        bool invoke_kernel_doublebuffered(unsigned int* input, unsigned int* output, int* iterNum, int sz_input, int sz_output, int sz_sz, cl_event events[evtCount], double eTotal[evtCount]);

        static bool unit_test_kernel_cpu();
        static bool unit_test_naive();

    protected:
        bool releaseMemObject(cl_mem& obj);

    private:
		
        string m_strSampleFP;
        bool m_useDoubleBuffered;
        int m_numSamples;
        int m_numBlocks;
        int m_blockSz;
        bool m_verifyMode; //true == verify, false is not verify
        bool m_writeMatchArray; //true == writeMatchArray
        cl_kernel m_clKernelSmithWaterman;
		xcl_world m_world;

        MatchArray* m_pMatchInfo;
    };
}
}

#endif /* SWAPP_H_ */

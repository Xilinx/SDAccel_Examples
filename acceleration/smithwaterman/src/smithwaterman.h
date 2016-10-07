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

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
#include <memory>
#include <string>
#include <iostream>
#include <assert.h>
#include <unistd.h>
#include "smithwaterman.h"
#include "cmdlineparser.h"
#include "logger.h"

using namespace std;
using namespace sda;
using namespace sda::cl;
using namespace sda::utils;

#include "sw.h"

extern int SSW_par(int, int, int, char**, char**, unsigned int*, unsigned int*, unsigned int*);

void intelImpl(int nBlocks, int blkSz, int nThreads, int writeMatchArray, MatchArray* pm)
{
    int totalSz = nBlocks * NUMPACKED * blkSz;
    unsigned int* maxr = new unsigned int[totalSz];
    unsigned int* maxc = new unsigned int[totalSz];
    unsigned int* maxv = new unsigned int[totalSz];
    char** rd = new char*[totalSz];
    char** rf = new char*[totalSz];
    for (int i = 0; i < totalSz; ++i) {
        rd[i] = new char[MAXROW + 1];
        rf[i] = new char[MAXCOL + 1];
    }
    SSW_par(nBlocks, NUMPACKED * blkSz, nThreads, rd, rf, maxr, maxc, maxv);
    if (writeMatchArray && pm) {
        pm->populateArray(rd, rf, maxr, maxc, maxv);
        pm->dumpArray();
    }
    for (int i = 0; i < totalSz; ++i) {
        delete[] rd[i];
        delete[] rf[i];
    }
    delete[] rd;
    delete[] rf;
    delete[] maxv;
    delete[] maxr;
    delete[] maxc;
}

//pass cmd line options to select opencl device
int main(int argc, char* argv[])
{
    LogInfo("\nXilinx Smith Waterman benchmark started");
    string strKernelFullPath = sda::GetApplicationPath() + "/";

    //parse commandline
    CmdLineParser parser;
    parser.addSwitch("--sample-file", "-f", "input sample file path", "ref.txt");
    parser.addSwitch("--platform-name", "-p", "OpenCl platform vendor name", "xilinx");
    parser.addSwitch("--device-name", "-d", "OpenCl device name", "fpga0");
    parser.addSwitch("--kernel-file", "-k", "OpenCl kernel file to use");
    parser.addSwitch("--select-device", "-s", "Select from multiple matched devices [0-based index]", "0");
    parser.addSwitch("--number-of-runs", "-n", "Number of times the kernel runs on the device to compute the average.", "1");
    parser.addSwitch("--block-size", "-bz", "Number of samples in a block for SmithWaterman", "-1");
    parser.addSwitch("--number-of-blocks", "-nb", "Number of blocks of samples for SmithWaterman", "1");
    parser.addSwitch("--number-of-threads", "-nt", "Number of threads for striped SmitWaterman", "1");
    parser.addSwitch("--double-buffered", "-db", "Double buffred host to fpga communication(now working)", "0");
    parser.addSwitch("--verify-mode", "-vm", "Verify output of FPGA using precomputed ref.txt", "0");
    parser.addSwitch("--write-match-array", "-wm", "Write match array", "0");
    parser.addSwitch("--zmq-pub-port", "-z", "ZeroMQ publisher port for web visualization. FPGA=5020, CPU=5021", "5020");
    parser.addSwitch("--output", "-o", "results output file", "result.json");
    parser.setDefaultKey("--kernel-file");
    parser.parse(argc, argv);

    //read settings
    string strSampleFP = parser.value("sample-file");
    string strPlatformName = parser.value("platform-name");
    string strDeviceName = parser.value("device-name");
    string strKernelRelFP = parser.value("kernel-file");
    string zmq_port = parser.value("zmq-pub-port");

    int nRuns = parser.value_to_int("number-of-runs");
    int nBlocks = parser.value_to_int("number-of-blocks");
    int blkSz = parser.value_to_int("block-size");

    if (blkSz < 1) {
        blkSz = NUMITER;
    }
    int doubleBuffered = parser.value_to_int("double-buffered");
    int idxSelectedDevice = parser.value_to_int("select-device");
    int nThreads = parser.value_to_int("number-of-threads");
    int verifyMode = parser.value_to_int("verify-mode");
    int writeMatchArray = parser.value_to_int("write-match-array");

    string str_zmq_port = parser.value("zmq-pub-port");
    LogInfo("Platform: %s, Device: %s", strPlatformName.c_str(), strDeviceName.c_str());
    LogInfo("Kernel FP: %s", strKernelRelFP.c_str());
    LogInfo("ZMQ PORT: %s", str_zmq_port.c_str());

    //MatchInfo: fetch results and forwards them
    int totalSz = nBlocks * NUMPACKED * blkSz;

    //Setup zeromq publisher
#ifdef PUB_ZMQ
    LogInfo("Setup zeromq publisher");
    zmq::context_t context(1);
    zmq::socket_t publisher(context, ZMQ_PUB);
    string zmq_url = "tcp://*:" + zmq_port;
    publisher.bind(zmq_url);

    const std::unique_ptr<MatchArray> pMatchInfo(new MatchArray(totalSz, MAXROW, MAXCOL, &publisher));
#else
	const std::unique_ptr<MatchArray> pMatchInfo(new MatchArray(totalSz, MAXROW, MAXCOL));
#endif

    //SWAN Execution 
    if (strPlatformName == string("intel")) {
        for (int r = 0; r < nRuns; r++) {
	    //SWAN-CPU Intel Intrinsic flow	
            intelImpl(nBlocks, blkSz, nThreads, writeMatchArray, pMatchInfo.get());
        }
    }
    else {
        if (parser.isValid("kernel-file"))
            strKernelFullPath += parser.value("kernel-file");
        else {
            LogError("Please pass in a valid kernel file path relative to the exe file path.");
            return -1;
        }
        if (verifyMode) {
            if (!is_file(parser.value("sample-file"))) {
                LogError("Input sample file: %s does not exist!", parser.value("sample-file").c_str());
                return -1;
            }
        }
        LogInfo("Chosen kernel file is %s", strKernelFullPath.c_str());
        LogInfo("Chosen Platform = %s, Device Name: %s, Device Index: [%d]", strPlatformName.c_str(), strDeviceName.c_str(), idxSelectedDevice);
        SmithWatermanApp smithwaterman(strPlatformName, strDeviceName, idxSelectedDevice,
            strKernelFullPath, strSampleFP, nBlocks, blkSz,
            doubleBuffered == 0 ? false : true,
            verifyMode == 0 ? false : true,
            writeMatchArray == 0 ? false : true,
            pMatchInfo.get());

        //SWAN-HLS Xilinx SDAccel flow
        bool res = smithwaterman.run(0, nRuns);
        if (!res) {
            LogError("An error occurred when running benchmark on device 0");
            return -1;
        }

        LogInfo("finished");
    }

    return 0;
}


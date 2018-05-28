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
#include <unistd.h>
#include <signal.h>
#include <cstdlib>

#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <vector>
#include <string>
#include <cstring>

#include "sha1.h"
#include "clSha1.h"
#include "cmdlineparser.h"
#include "logger.h"

//#define SHA1_PUB 1
typedef unsigned char u8;

//graceful close
volatile sig_atomic_t g_done = 0;

#ifdef SHA1_PUB
	#include "zmq.hpp"
	#include <jsonxx.h>
#endif

void term(int signum) {
    g_done = 1;
}

void init_mds(unsigned int *mds) {
	for (unsigned i = 0; i < CHANNELS; i++) {
		mds[i * 16 + 0] = 0x67452301;
		mds[i * 16 + 1] = 0xEFCDAB89;
		mds[i * 16 + 2] = 0x98BADCFE;
		mds[i * 16 + 3] = 0x10325476;
		mds[i * 16 + 4] = 0xC3D2E1F0;
		for(unsigned j = 5; j < 16; j++) {
		  mds[i*16 + j] = 0x0;
		}
	}
}

void init_buf_0(unsigned int *buf) {
	unsigned long int ml = 64;

	unsigned long int ml0 = (ml & 0x00000000000000FF) << 56;
	unsigned long int ml1 = (ml & 0x000000000000FF00) << 40;
	unsigned long int ml2 = (ml & 0x0000000000FF0000) << 24;
	unsigned long int ml3 = (ml & 0x00000000FF000000) << 8;
	unsigned long int ml4 = (ml & 0x000000FF00000000) >> 8;
	unsigned long int ml5 = (ml & 0x0000FF0000000000) >> 24;
	unsigned long int ml6 = (ml & 0x00FF000000000000) >> 40;
	unsigned long int ml7 = (ml & 0xFF00000000000000) >> 56;

	unsigned long int mlbe = ml0 | ml1 | ml2 | ml3 | ml4 | ml5 | ml6 | ml7;

	unsigned int mlbe0 = (mlbe & 0xFFFFFFFF00000000) >> 32;
	unsigned int mlbe1 = (mlbe & 0x00000000FFFFFFFF) >> 0;

	for (unsigned i = 0; i < CHANNELS; i++) {
		buf[i * 16 + 0] = 0;
		buf[i * 16 + 1] = 0;
		buf[i * 16 + 2] = 0x80;
		buf[i * 16 + 3] = 0;
		buf[i * 16 + 4] = 0;
		buf[i * 16 + 5] = 0;
		buf[i * 16 + 6] = 0;
		buf[i * 16 + 7] = 0;
		buf[i * 16 + 8] = 0;
		buf[i * 16 + 9] = 0;
		buf[i * 16 + 10] = 0;
		buf[i * 16 + 11] = 0;
		buf[i * 16 + 12] = 0;
		buf[i * 16 + 13] = 0;
		buf[i * 16 + 14] = mlbe1;
		buf[i * 16 + 15] = mlbe0;
	}
}

void init_buf_count(uint32_t *buf, uint32_t start) {

	uint64_t ml = 512 * (BLOCKS - 1) + 32;

	uint64_t ml0 = (ml & 0x00000000000000FF) << 56;
	uint64_t ml1 = (ml & 0x000000000000FF00) << 40;
	uint64_t ml2 = (ml & 0x0000000000FF0000) << 24;
	uint64_t ml3 = (ml & 0x00000000FF000000) << 8;
	uint64_t ml4 = (ml & 0x000000FF00000000) >> 8;
	uint64_t ml5 = (ml & 0x0000FF0000000000) >> 24;
	uint64_t ml6 = (ml & 0x00FF000000000000) >> 40;
	uint64_t ml7 = (ml & 0xFF00000000000000) >> 56;

	uint64_t mlbe = ml0 | ml1 | ml2 | ml3 | ml4 | ml5 | ml6 | ml7;

	uint32_t mlbe0 = (mlbe & 0xFFFFFFFF00000000) >> 32;
	uint32_t mlbe1 = (mlbe & 0x00000000FFFFFFFF) >> 0;

	std::memset(buf, 0, CHANNELS * (BLOCKS - 1L) * 64L);

	for (size_t i = 0; i < CHANNELS; i++) {
		buf[CHANNELS * (BLOCKS - 1) * 16L + i * 16L + 0]  = i + start;
		buf[CHANNELS * (BLOCKS - 1) * 16L + i * 16L + 1]  = 0x80;
		buf[CHANNELS * (BLOCKS - 1) * 16L + i * 16L + 2]  = 0;
		buf[CHANNELS * (BLOCKS - 1) * 16L + i * 16L + 3]  = 0;
		buf[CHANNELS * (BLOCKS - 1) * 16L + i * 16L + 4]  = 0;
		buf[CHANNELS * (BLOCKS - 1) * 16L + i * 16L + 5]  = 0;
		buf[CHANNELS * (BLOCKS - 1) * 16L + i * 16L + 6]  = 0;
		buf[CHANNELS * (BLOCKS - 1) * 16L + i * 16L + 7]  = 0;
		buf[CHANNELS * (BLOCKS - 1) * 16L + i * 16L + 8]  = 0;
		buf[CHANNELS * (BLOCKS - 1) * 16L + i * 16L + 9]  = 0;
		buf[CHANNELS * (BLOCKS - 1) * 16L + i * 16L + 10] = 0;
		buf[CHANNELS * (BLOCKS - 1) * 16L + i * 16L + 11] = 0;
		buf[CHANNELS * (BLOCKS - 1) * 16L + i * 16L + 12] = 0;
		buf[CHANNELS * (BLOCKS - 1) * 16L + i * 16L + 13] = 0;
		buf[CHANNELS * (BLOCKS - 1) * 16L + i * 16L + 14] = mlbe1;
		buf[CHANNELS * (BLOCKS - 1) * 16L + i * 16L + 15] = mlbe0;
	}
}

void verify_sha1(uint32_t start, uint32_t *mds) {
	unsigned char ibuf[(BLOCKS - 1) * 64 + 4];
	std::cout << "VERIFYING" << std::endl;

	for (int i = 0; i < CHANNELS; i++) {
		uint32_t val = i + start;
		std::memset(ibuf, 0, (BLOCKS - 1) * 64);
		ibuf[(BLOCKS - 1) * 64 + 0] = (val & 0x000000FF) >> 0;
		ibuf[(BLOCKS - 1) * 64 + 1] = (val & 0x0000FF00) >> 8;
		ibuf[(BLOCKS - 1) * 64 + 2] = (val & 0x00FF0000) >> 16;
		ibuf[(BLOCKS - 1) * 64 + 3] = (val & 0xFF000000) >> 24;

		unsigned char obuf[20];
		SHA1(ibuf, (BLOCKS - 1) * 64 + 4, obuf);

		for (int j = 0; j < 5; j++) {
			unsigned int ref_mds = (unsigned) obuf[j * 4 + 0] << 24
					| (unsigned) obuf[j * 4 + 1] << 16
					| (unsigned) obuf[j * 4 + 2] << 8
					| (unsigned) obuf[j * 4 + 3] << 0;

			if (ref_mds != mds[i * 16 + j]) {
				std::cout << "ERROR: Mismatch on Chan " << i << "!: " << std::hex << std::setw(8)
						<< std::setfill('0') << (uint) ref_mds << " != "
						<< (uint) mds[i * 16 + j] << std::endl;

				std::cout << "mds = ";
				for (unsigned k = 0; k < 5; k++) {
					std::cout << std::hex << std::setw(8) << std::setfill('0')
							<< (uint) mds[i * 16 + k];
				}
				std::cout << std::dec << std::endl;

				std::cout << "ref = ";
				for (unsigned k = 0; k < 20; k++) {
					std::cout << std::hex << std::setw(2) << std::setfill('0')
							<< (uint) obuf[k];
				}
				std::cout << std::dec << std::endl;

				/* Stop */
				j = 5;
			}
		}

	}
}

/* sha1_single - run SHA1 once
 */
void sha1_single(clSha1 &host) {
	unsigned int *buf = (unsigned int*) malloc(CHANNELS * BLOCKS * 64L);
	unsigned int *mds = (unsigned int*) malloc(CHANNELS * 64L);

	if (!buf || !mds) {
		std::cout << "ERROR: Out of Memory!" << std::endl;
		abort();
	}

	init_mds(mds);
	init_buf_count(buf, 0);
	//init_buf_0(buf);

	clSha1Runner *runner = host.createRunner();

	cl_event event = runner->run(buf, mds);

	clWaitForEvents(1, &event);

	//verify_sha1_0(mds);
	verify_sha1(0, mds);

	delete runner;

	free(mds);
	free(buf);
}

/* sha1_parallel - run SHA1 for timelimit seconds check performance
 */
void sha1_parallel(clSha1 &host, double timelimit, size_t runners, const string& zmq_port) {

#ifdef SHA1_PUB
	std::cout << "Setup zeromq publisher" << std::endl;
	zmq::context_t context(1);
	zmq::socket_t publisher(context, ZMQ_PUB);
	string zmq_url = "tcp://*:" + zmq_port;
	publisher.bind(zmq_url);
#endif
	uint32_t *start = new uint32_t[runners];
	uint32_t **buf = new uint32_t*[runners];
	uint32_t **mds = new uint32_t*[runners];

	if (!buf || !mds) {
		std::cout << "ERROR: Out of Memory!" << std::endl;
		abort();
	}

	std::vector<clSha1Runner*> clRunners(runners);
	for (size_t i = 0; i < runners; i++) {
		buf[i] = new uint32_t[CHANNELS * BLOCKS * 64L];
		mds[i] = new uint32_t[CHANNELS * 64L];

		clRunners[i] = host.createRunner();
	}

	bool done = false;

	std::cout << "INFO: Starting Timer" << std::endl;
	struct timespec to;
	clock_gettime(CLOCK_MONOTONIC, &to);
	to.tv_sec += (long) timelimit;

	for(size_t i = 0; i < runners; i++) {
		start[i] = (i) * CHANNELS;
		init_mds(mds[i]);
		init_buf_count(buf[i], start[i]);
		clRunners[i]->run(buf[i], mds[i]);
	}

	size_t complete = 0;

	while(!done) {
		for(size_t j = 0; j < runners; j++) {
			if (clRunners[j]->isDone()) {
				std::cout << "INFO: Runner " << j << " complete (" << start[j] << ")" << std::endl;
#ifdef SHA1_PUB
				// output to zmq for web viz
				u8 zmq_output[CHANNELS];
				for (int k = 0; k < CHANNELS; k++) {
					zmq_output[k] = (unsigned char) (mds[j][k*16 + 4] & 0x1F);
				}

				jsonxx::Array a;
				for (int k = 0; k < CHANNELS; k++)
					a << zmq_output[k];

				std::string str = a.json();
				//std::cout << "output: " << str << std::endl;
				publisher.send((const void*) str.c_str(), str.length());
#endif

				complete++;
				//verify_sha1(start[j], mds[j]);

				start[j] = (complete + runners - 1) * CHANNELS;
				init_mds(mds[j]);
				init_buf_count(buf[j], start[j]);
				clRunners[j]->run(buf[j], mds[j]);
			}
		}

		usleep(10);

		 /* After timeout stop */
		struct timespec cur;
		clock_gettime(CLOCK_MONOTONIC, &cur);

		if (cur.tv_sec >= to.tv_sec && timelimit > 0.0) {
			 std::cout << "INFO: Test complete ran for " << timelimit << " seconds! Stopping..." << std::endl;
			 done = true;
		}

		if (g_done) {
			std::cout << "INFO: Signal detected! Stopping..." << std::endl;
			done = true;
		}
	}

	double jsize = 64.0 * BLOCKS / 1024.0 / 1024.0;
	double jcompleted = CHANNELS * complete * 1.0;
	double rate = jcompleted * jsize / timelimit;

	std::cout << "INFO: Job Size: " << jsize << " MB" << std::endl;
	std::cout << "INFO: Jobs Processed: " << jcompleted << std::endl;
	std::cout << "INFO: Rate = " << rate << " MB/s" << std::endl;

	for(size_t i = 0; i < runners; i++) {
		while(!clRunners[i]->isDone());

		delete clRunners[i];
		delete mds[i];
		delete buf[i];
	}

	delete mds;
	delete buf;
}

/* Run SHA1 in a single and parallel mode */
int main(int argc, char** argv) {
	//parse commandline
	LogInfo("Xilinx SHA1 Example Application");

	// Create sig handler to quit gracefully
	struct sigaction action;
	std::memset(&action, 0, sizeof(struct sigaction));
	action.sa_handler = term;
	sigaction(SIGTERM, &action, NULL);

	//parse commandline
	sda::utils::CmdLineParser parser;
	parser.addSwitch("--platform-name", "-p", "OpenCl platform vendor name", "Xilinx");
	parser.addSwitch("--device-name", "-d", "OpenCl device name", "");
	parser.addSwitch("--kernel-file", "-k", "OpenCl kernel file to use");
	parser.addSwitch("--select-device", "-s", "Select from multiple matched devices [0-based index]", "0");
	parser.addSwitch("--time-limit", "-t", "Time limit in seconds, -1 means run forever", "20");
	parser.addSwitch("--runners", "-r", "Runners to execute concurrently", "2");
	parser.addSwitch("--zmq-pub-port", "-z", "ZeroMQ publisher port for web visualization", "5010");
	parser.setDefaultKey("--kernel-file");

	//parse all command line options
	parser.parse(argc, argv);

	double timelimit = parser.value_to_double("time-limit");
	string str_platform = parser.value("platform-name");
	string str_device = parser.value("device-name");
	string str_kernel = parser.value("kernel-file");
	string str_zmq_port = parser.value("zmq-pub-port");
	size_t runners = parser.value_to_double("runners");

	size_t memused = runners*(CHANNELS*BLOCKS*64L + CHANNELS*64L);

	LogInfo("Platform: %s, Device: %s", str_platform.c_str(), str_device.c_str());
	LogInfo("Kernel FP: %s", str_kernel.c_str());
	LogInfo("Runners: %lld (%f MB)", runners, (float) memused  / 1024.0 / 1024.0);
	LogInfo("ZMQ PORT: %s", str_zmq_port.c_str());
	LogInfo("Running for [%f] seconds...", timelimit);

	clSha1 host(str_platform, str_device, str_kernel.c_str());
	//sha1_single(host);
	std::cout << "INFO: FPGA Start" << std::endl;
	sha1_parallel(host, timelimit, runners, str_zmq_port);
	std::cout << "INFO: FPGA Done" << std::endl;

	std::cout << "INFO: DONE" << std::endl;

}

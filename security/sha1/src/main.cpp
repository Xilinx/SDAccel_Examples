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
#include <cmdlineparser.h>
#include <logger.h>

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

void init_buf_count(unsigned int *buf, unsigned int start) {

	uint64_t ml = 512 * (BLOCKS - 1) + 64;

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

	std::memset(buf, 0, CHANNELS * (BLOCKS - 1) * 64);

	for (size_t i = 0; i < CHANNELS; i++) {
		buf[CHANNELS * (BLOCKS - 1) * 16 + i * 16 + 0] = i;
		buf[CHANNELS * (BLOCKS - 1) * 16 + i * 16 + 1] = start;
		buf[CHANNELS * (BLOCKS - 1) * 16 + i * 16 + 2] = 0x80;
		buf[CHANNELS * (BLOCKS - 1) * 16 + i * 16 + 3] = 0;
		buf[CHANNELS * (BLOCKS - 1) * 16 + i * 16 + 4] = 0;
		buf[CHANNELS * (BLOCKS - 1) * 16 + i * 16 + 5] = 0;
		buf[CHANNELS * (BLOCKS - 1) * 16 + i * 16 + 6] = 0;
		buf[CHANNELS * (BLOCKS - 1) * 16 + i * 16 + 7] = 0;
		buf[CHANNELS * (BLOCKS - 1) * 16 + i * 16 + 8] = 0;
		buf[CHANNELS * (BLOCKS - 1) * 16 + i * 16 + 9] = 0;
		buf[CHANNELS * (BLOCKS - 1) * 16 + i * 16 + 10] = 0;
		buf[CHANNELS * (BLOCKS - 1) * 16 + i * 16 + 11] = 0;
		buf[CHANNELS * (BLOCKS - 1) * 16 + i * 16 + 12] = 0;
		buf[CHANNELS * (BLOCKS - 1) * 16 + i * 16 + 13] = 0;
		buf[CHANNELS * (BLOCKS - 1) * 16 + i * 16 + 14] = mlbe1;
		buf[CHANNELS * (BLOCKS - 1) * 16 + i * 16 + 15] = mlbe0;
	}
}

void verify_sha1_0(unsigned int *mds) {
	unsigned char ibuf[8];
	std::cout << "VERIFYING" << std::endl;

	for (int i = 0; i < CHANNELS; i++) {
		std::memset(ibuf, 0, 8);

		unsigned char obuf[20];
		SHA1(ibuf, 8, obuf);

		for (int j = 0; j < 5; j++) {
			unsigned int ref_mds = (unsigned) obuf[j * 4 + 0] << 24
					| (unsigned) obuf[j * 4 + 1] << 16
					| (unsigned) obuf[j * 4 + 2] << 8
					| (unsigned) obuf[j * 4 + 3] << 0;

			if (ref_mds != mds[i * 16 + j]) {
				std::cout << "ERROR: Mismatch!: " << std::hex << std::setw(8)
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

void verify_sha1(unsigned int start, unsigned int *mds) {
	unsigned char ibuf[(BLOCKS - 1) * 64 + 8];
	std::cout << "VERIFYING" << std::endl;

	for (int i = 0; i < CHANNELS; i++) {
		std::memset(ibuf, 0, (BLOCKS - 1) * 64);
		std::memcpy(&ibuf[(BLOCKS - 1) * 64 + 0], &i, 4);
		std::memcpy(&ibuf[(BLOCKS - 1) * 64 + 4], &start, 4);

		unsigned char obuf[20];
		SHA1(ibuf, (BLOCKS - 1) * 64 + 8, obuf);

		for (int j = 0; j < 5; j++) {
			unsigned int ref_mds = (unsigned) obuf[j * 4 + 0] << 24
					| (unsigned) obuf[j * 4 + 1] << 16
					| (unsigned) obuf[j * 4 + 2] << 8
					| (unsigned) obuf[j * 4 + 3] << 0;

			if (ref_mds != mds[i * 16 + j]) {
				std::cout << "ERROR: Mismatch!: " << std::hex << std::setw(8)
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
	unsigned int *buf = (unsigned int*) malloc(CHANNELS * BLOCKS * 64);
	unsigned int *mds = (unsigned int*) malloc(CHANNELS * 64);

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

/* Call back used for keeping the update kernel constantly active */
void CL_CALLBACK single_callback(cl_event event, cl_int status,
		void *user_data) {
	long long unsigned *blocks = (long long unsigned *) user_data;

	//clReleaseEvent(event);
	__sync_fetch_and_add(blocks, CHANNELS * BLOCKS); /* Atomic add */
}

/* sha1_parallel - run SHA1 for timelimit seconds check performance
 */
void sha1_parallel(clSha1 &host, double timelimit, size_t runners, const string& zmq_port) {
	uint32_t **buf = (uint32_t**) malloc(sizeof(uint32_t*) * runners*2);
	uint32_t **mds = (uint32_t**) malloc(sizeof(uint32_t*) * runners*2);

#ifdef SHA1_PUB
	std::cout << "Setup zeromq publisher" << std::endl;
	zmq::context_t context(1);
	zmq::socket_t publisher(context, ZMQ_PUB);
	string zmq_url = "tcp://*:" + zmq_port;
	publisher.bind(zmq_url);
#endif

	if (!buf || !mds) {
		std::cout << "ERROR: Out of Memory!" << std::endl;
		abort();
	}

	for (size_t i = 0; i < runners*2; i++) {
		buf[i] = (uint32_t*) malloc(CHANNELS * BLOCKS * 64);
		mds[i] = (uint32_t*) malloc(CHANNELS * 64);

		init_mds(mds[i]);
		init_buf_count(buf[i], i * CHANNELS);

		if (!buf[i] || !mds[i]) {
			std::cout << "ERROR: Out of Memory!" << std::endl;
			abort();
		}
	}

	uint64_t completions = 0;
	uint64_t completed = 0;

	cl_event events[runners*2];
	std::vector<clSha1Runner*> clRunners(runners*2);
	for(size_t i = 0; i < runners*2; i++) {
		clRunners[i] = host.createRunner();
	}

	std::clock_t timeout = std::clock() + (double) CLOCKS_PER_SEC * timelimit;

	size_t i;
	for (i = 0;; i++) {

		//break gracefully
		if(g_done) {
			LogInfo("Caught SIGTERM...");
			break;
		}
		usleep(10);

		if (i % runners == 0 && i >= runners*2) {
			size_t j = ((i - runners*2) / runners) % 2;
			clWaitForEvents(runners, &events[j * runners]);

#ifdef SHA1_PUB
			// output to zmq for web viz
			u8 zmq_output[CHANNELS * runners];
			for (int k = 0; k < CHANNELS * runners; k++) {
				zmq_output[k] = (unsigned char) (mds[j * runners + (k / CHANNELS)][(k % CHANNELS) * 16] & 0x1F);
			}

			jsonxx::Array a;
			for (int k = 0; k < CHANNELS * runners; k++)
				a << zmq_output[k];

			std::string str = a.json();
			//std::cout << "output: " << str << std::endl;
			publisher.send((const void*) str.c_str(), str.length());
#endif

			/* Re-init with new data */
			for (int k = 0; k < runners; k++) {
				init_mds(mds[j * runners + k]);
				init_buf_count(buf[j * runners + k], (i + k) * CHANNELS);
			}
		}

		 /* After timeout stop */
		 if (std::clock() > timeout && timelimit > 0.0) {
			 //Stop counting blocks immediately
			 LogInfo("Timeout reached! Stopping...");
			 completed = completions;
			 g_done = 1;
			 break;
		 }

		events[i % (runners*2)] = clRunners[i % (runners*2)]->run(buf[i % (runners*2)], mds[i % (runners*2)]);

		int err = clSetEventCallback(events[i % (runners*2)], CL_COMPLETE,
				single_callback, &completions);
		if (err != CL_SUCCESS) {
			std::cout << "ERROR: Could not create callback" << std::endl;
			abort();
		}
	}

	if (i >= runners) {
		size_t j = (i / runners - 2) % 2;
		if (j == 0) {
			clWaitForEvents(runners, &events[runners]);
			clWaitForEvents(i % runners, &events[0]);
		} else {
			clWaitForEvents(runners, &events[0]);
			clWaitForEvents(i % runners, &events[runners]);
		}
	} else {
		clWaitForEvents(i, &events[0]);
	}

	double dcompleted = completed * 1.0;
	double dsize = 64.0;

	double rate = dcompleted * dsize / timelimit * (8.0 / 1024.0 / 1024.0);
	std::cout << "INFO: Block Size: " << 64 * 8 << " bits" << std::endl;
	std::cout << "INFO: Blocks Processed: " << completed << std::endl;
	std::cout << "INFO: Rate = " << rate << " MBit/s" << std::endl;

	free(mds);
	free(buf);
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
	parser.addSwitch("--device-name", "-d", "OpenCl device name", "fpga0");
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

	size_t memused = runners*2*CHANNELS*BLOCKS*65;

	LogInfo("Platform: %s, Device: %s", str_platform.c_str(), str_device.c_str());
	LogInfo("Kernel FP: %s", str_kernel.c_str());
	LogInfo("Runners: %lld (%f MB)", runners, (float) memused  / 1024.0 / 1024.0);
	LogInfo("ZMQ PORT: %s", str_zmq_port.c_str());
	LogInfo("Running for [%f] seconds...", timelimit);

	clSha1 fpga(str_platform, str_device, str_kernel.c_str());
	sha1_single(fpga);
	std::cout << "INFO: FPGA Start" << std::endl;
	sha1_parallel(fpga, timelimit, runners, str_zmq_port);
	std::cout << "INFO: FPGA Done" << std::endl;

	std::cout << "INFO: DONE" << std::endl;

}

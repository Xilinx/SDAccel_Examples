/*******************************************************************************
Vendor: Xilinx
Associated Filename: krnl_sum_scan.cl
Purpose: SDAccel Sum Scan
Revision History: January 28, 2016

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

#define LOG2_B (4)
#define B (1<<(LOG2_B))
#define M(x) (((x)-1)/(B) + 1)

#if(B == 16)
typedef float16 bus_t;
#elif(B == 8)
typedef float8 bus_t;
#elif(B == 4)
typedef float4 bus_t;
#elif(B == 2)
typedef float2 bus_t;
#elif(B == 1)
typedef float bus_t;
#endif

#define LOG2_HIST_LENGTH 8
#define HIST_LENGTH ((1<<LOG2_HIST_LENGTH)/(B))

typedef union {
	bus_t b;
	float f[B];
} bus_to_float_t;

bus_t array_to_bus(float *in) {
	bus_to_float_t out;

	for(uint i = 0; i < B; i++) {
		out.f[i] = in[i];
	}

	return out.b;
}

void bus_to_array(bus_t g_in, float *out) {
	bus_to_float_t in;

	in.b = g_in;

	for(uint i = 0; i < B; i++) {
		out[i] = in.f[i];
	}
}

bus_t sum_scan(float *sum, bus_t g_in[HIST_LENGTH+1], uint i) {
	float in[(HIST_LENGTH+1)*B] __attribute__((xcl_array_partition(complete, 0)));

	for(uint j = 0; j < HIST_LENGTH+1; j++) {
		bus_t tmp;
		if(HIST_LENGTH - j > i)
			tmp = 0.0f;
		else
			tmp = g_in[j];

		bus_to_array(tmp, &in[B*j]);
	}
/*
	for(uint j = 0; j < (HIST_LENGTH+1)*B; j++) {
		printf("%7.3f ", in[B+j]);
	}
	printf("\n");
*/
	/* Tree based sumation of history */
	for(uint d = 0; d < LOG2_HIST_LENGTH; d++) {
		uint o1 = 1<<d;
		uint o2 = 1<<(d+1);

		for(uint k = 1; k <= (1<<(LOG2_HIST_LENGTH-1-d)); k++) {
			in[k*o2-1] = in[k*o2-1] + in[k*o2-o1-1];
		}
	}
	
	/* Sum Scan for incoming block */
	for(uint d = 0; d < 4; d++) {
		uint o0 = B*HIST_LENGTH;
		uint o1 = 1<<d;
		uint o2 = 1<<(d+1);

		for(uint k = 1; k <= (1<<(4-1-d)); k++) {
			for(uint j =  0; j < (1<<d); j++) {
				in[o0+k*o2-j-1] = in[o0+k*o2-j-1] + in[o0+k*o2-o1-1];
			}
		}
	}

	*sum += in[HIST_LENGTH*B-1];

	for(uint j = 0; j < B; j++) {
		in[B*HIST_LENGTH+j] += *sum;
	}
/*
	for(uint j = 0; j < B; j++) {
		printf("%7.3f ", in[B*HIST_LENGTH+j]);
	}

	printf("[%7.3f] (%d)", *sum, i % (HIST_LENGTH+1));
	printf("\n");
*/
	return array_to_bus(&in[B*HIST_LENGTH]);
}

__kernel void __attribute__ ((reqd_work_group_size(1, 1, 1)))
krnl_sum_scan(
	__global bus_t *in,
	__global bus_t *out,
	uint length
) {
	float sums[HIST_LENGTH];
	bus_t hist[HIST_LENGTH + 1] __attribute__((xcl_array_partition(complete, 0)));

	uint n = M(length);

	__attribute__((xcl_pipeline_loop))
	for(uint i = 0; i < n; i++){
		float sum;

		if(i < HIST_LENGTH+1) {
			sum = 0.0f;
		} else {
			sum = sums[i%(HIST_LENGTH)];
		}

		for(uint j = 0; j < HIST_LENGTH; j++) {
			hist[j] = hist[j+1];
		}
		hist[HIST_LENGTH] = in[i];

		out[i] = sum_scan(&sum, hist, i);

		sums[i%(HIST_LENGTH)] = sum;
	}
}


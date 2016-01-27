/*******************************************************************************
Vendor: Xilinx
Associated Filename: krnl_equalizer.cl
Purpose: SDAccel histogram equalization example
Revision History: December 6, 2015

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

#include "equalizer.h"

void uint16_to_short_array(ushort out[32], uint16 in) {
	out[0]  = (in.s0 >> 0)  & 0xFFFF;
	out[1]  = (in.s0 >> 16) & 0xFFFF;
	out[2]  = (in.s1 >> 0)  & 0xFFFF;
	out[3]  = (in.s1 >> 16) & 0xFFFF;
	out[4]  = (in.s2 >> 0)  & 0xFFFF;
	out[5]  = (in.s2 >> 16) & 0xFFFF;
	out[6]  = (in.s3 >> 0)  & 0xFFFF;
	out[7]  = (in.s3 >> 16) & 0xFFFF;
	out[8]  = (in.s4 >> 0)  & 0xFFFF;
	out[9]  = (in.s4 >> 16) & 0xFFFF;
	out[10] = (in.s5 >> 0)  & 0xFFFF;
	out[11] = (in.s5 >> 16) & 0xFFFF;
	out[12] = (in.s6 >> 0)  & 0xFFFF;
	out[13] = (in.s6 >> 16) & 0xFFFF;
	out[14] = (in.s7 >> 0)  & 0xFFFF;
	out[15] = (in.s7 >> 16) & 0xFFFF;
	out[16] = (in.s8 >> 0)  & 0xFFFF;
	out[17] = (in.s8 >> 16) & 0xFFFF;
	out[18] = (in.s9 >> 0)  & 0xFFFF;
	out[19] = (in.s9 >> 16) & 0xFFFF;
	out[20] = (in.sA >> 0)  & 0xFFFF;
	out[21] = (in.sA >> 16) & 0xFFFF;
	out[22] = (in.sB >> 0)  & 0xFFFF;
	out[23] = (in.sB >> 16) & 0xFFFF;
	out[24] = (in.sC >> 0)  & 0xFFFF;
	out[25] = (in.sC >> 16) & 0xFFFF;
	out[26] = (in.sD >> 0)  & 0xFFFF;
	out[27] = (in.sD >> 16) & 0xFFFF;
	out[28] = (in.sE >> 0)  & 0xFFFF;
	out[29] = (in.sE >> 16) & 0xFFFF;
	out[30] = (in.sF >> 0)  & 0xFFFF;
	out[31] = (in.sF >> 16) & 0xFFFF;
}

void short_array_to_uint16(uint16 *out, ushort in[32]) {
	out->s0  = (((uint) in[0] )  & 0xFFFF) | (((uint) in[1]  << 16) & 0xFFFF0000);
	out->s1  = (((uint) in[2] )  & 0xFFFF) | (((uint) in[3]  << 16) & 0xFFFF0000);
	out->s2  = (((uint) in[4] )  & 0xFFFF) | (((uint) in[5]  << 16) & 0xFFFF0000);
	out->s3  = (((uint) in[6] )  & 0xFFFF) | (((uint) in[7]  << 16) & 0xFFFF0000);
	out->s4  = (((uint) in[8] )  & 0xFFFF) | (((uint) in[9]  << 16) & 0xFFFF0000);
	out->s5  = (((uint) in[10])  & 0xFFFF) | (((uint) in[11] << 16) & 0xFFFF0000);
	out->s6  = (((uint) in[12])  & 0xFFFF) | (((uint) in[13] << 16) & 0xFFFF0000);
	out->s7  = (((uint) in[14])  & 0xFFFF) | (((uint) in[15] << 16) & 0xFFFF0000);
	out->s8  = (((uint) in[16])  & 0xFFFF) | (((uint) in[17] << 16) & 0xFFFF0000);
	out->s9  = (((uint) in[18])  & 0xFFFF) | (((uint) in[19] << 16) & 0xFFFF0000);
	out->sA  = (((uint) in[20])  & 0xFFFF) | (((uint) in[21] << 16) & 0xFFFF0000);
	out->sB  = (((uint) in[22])  & 0xFFFF) | (((uint) in[23] << 16) & 0xFFFF0000);
	out->sC  = (((uint) in[24])  & 0xFFFF) | (((uint) in[25] << 16) & 0xFFFF0000);
	out->sD  = (((uint) in[26])  & 0xFFFF) | (((uint) in[27] << 16) & 0xFFFF0000);
	out->sE  = (((uint) in[28])  & 0xFFFF) | (((uint) in[29] << 16) & 0xFFFF0000);
	out->sF  = (((uint) in[30])  & 0xFFFF) | (((uint) in[31] << 16) & 0xFFFF0000);
}

inline ushort eq_func(ushort val, ushort min) {
	uint eq_val;
	if(val == 0) {
		eq_val = 0;
	} else {
		eq_val = val - min;
		eq_val *= (IMAGE_WIDTH_PIXELS - 1);
		eq_val /= (1+IMAGE_WIDTH_PIXELS - min);
	}
	return eq_val;
}


__attribute__((reqd_work_group_size(1,1,1)))
kernel void krnl_equalizer(
	global uint16 *image,
	global uint16 *eqimage
	) {

	for(uint n = 0; n < IMAGE_HEIGHT_PIXELS/32; n++) {
		ushort line[32][IMAGE_WIDTH_PIXELS] __attribute__((xcl_array_partition(complete, 1)));
		ushort hist[32][HISTOGRAM_DEPTH] __attribute__((xcl_array_partition(complete, 1)));

		__attribute__((xcl_pipeline_loop))
		for(uint i = 0; i < HISTOGRAM_DEPTH; i++) {
			for(uint k = 0; k < 32; k++) {
				hist[k][i] = 0;
			}
		}

		ushort old[32] __attribute__((xcl_array_partition(complete,1)));
		ushort acc[32] __attribute__((xcl_array_partition(complete,1)));

		__attribute__((xcl_dependence(type="intra", direction="RAW", dependent="false")))
		__attribute__((xcl_pipeline_loop))
		for (uint i = 0; i < IMAGE_WIDTH_PIXELS; i++) {
			ushort pline[32] __attribute__((xcl_array_partition(complete,1)));
			uint16 pline_raw = image[n*IMAGE_WIDTH_PIXELS + i];

			uint16_to_short_array(pline, pline_raw);

			if (i == 0) {
				for(uint k = 0; k < 32; k++) {
					old[k] = 0;
					acc[k] = 0;
				}
			}

			for(uint k = 0; k < 32; k++) {
				ushort val = (pline[k] & 0xFFF0) >> 4;
				line[k][i] = val;

				if(old[k] == val) {
					acc[k]++;
				} else {
					hist[k][old[k]] = acc[k];
					acc[k] = hist[k][val] + 1;
				}

				old[k] = val;
			}
		}

		/* CDF */
		ushort max[32] __attribute__((xcl_array_partition(complete,1)));
		ushort min[32] __attribute__((xcl_array_partition(complete,1)));
		ushort cdf[32][HISTOGRAM_DEPTH] __attribute__((xcl_array_partition(complete,1)));

		__attribute__((xcl_pipeline_loop))
		for(uint i = 0; i < HISTOGRAM_DEPTH; i++) {
			for(int j = 0; j < 32; j++) {
				if ( i == 0) {
					max[j] = 0;
					min[j] = IMAGE_WIDTH_PIXELS;
					hist[j][old[j]] = acc[j];
				}
				ushort val = hist[j][i];

				if(val != 0 && val < min[j]) {
					min[j] = val;
				}

				max[j] += val;

				cdf[j][i] = max[j];
			}
		}

		/* Match */
		__attribute__((xcl_pipeline_loop))
		for (uint i = 0; i < IMAGE_WIDTH_PIXELS; i++) {
			ushort bucket_out[32] __attribute__((xcl_array_partition(complete,1)));

			for(uint k = 0; k < 32; k++) {
				ushort val = line[k][i];
				bucket_out[k] = eq_func(cdf[k][val], min[k]) << 4;
			}

			uint16 bucket_out_raw;
			short_array_to_uint16(&bucket_out_raw, bucket_out);

			eqimage[n*IMAGE_WIDTH_PIXELS + i] = bucket_out_raw;
		}
	}
}

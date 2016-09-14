/*******************************************************************************
Vendor: Xilinx
Associated Filename: linear_search.c
Purpose: SDAccel Nearest Neighbor Linear Search example
Revision History: January 28, 2016

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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <ap_fixed.h>
#include <xcl.h>

#include "linear_search.h"

#define KRNL_NAME "krnl_linear_search"

void linear_search_read_datafile(char* filename, float* data, size_t size) {
	FILE* fp = fopen(filename, "r");
	if( fp == NULL) {
		printf("ERROR: Could not open file\n");
		exit(EXIT_FAILURE);
	}

	for (size_t i = 0; i < size; i++) {
		fscanf (fp, "%f\n", &data[i]);
	}
	fclose(fp);
}

void linear_search_init( xcl_world *world, cl_kernel *krnl,
	cl_mem *dev_targets, cl_mem *dev_queries, cl_mem *dev_indices
) {

	*world = xcl_world_single();
	cl_program program = xcl_import_binary(*world, "krnl_nearest");
	*krnl = xcl_get_kernel(program, KRNL_NAME);

	/* Create Buffers padded to 512 bit boundry */
	*dev_targets = xcl_malloc(*world, CL_MEM_READ_ONLY, ((TARGETS * DIMS - 1) / 16 + 1) * 16 * sizeof(float));
	*dev_queries = xcl_malloc(*world, CL_MEM_READ_ONLY, ((QUERIES * DIMS - 1) / 16 + 1) * 16 * sizeof(float));
	*dev_indices = xcl_malloc(*world, CL_MEM_READ_ONLY, ((QUERIES - 1) / 16 + 1) * 16 * sizeof(unsigned int));

}

void linear_search_exit(
	xcl_world *world, cl_kernel *krnl,
	cl_mem *dev_targets, cl_mem *dev_queries, cl_mem *dev_indices
) {
	clReleaseMemObject(*dev_targets);
	clReleaseMemObject(*dev_queries);
	clReleaseMemObject(*dev_indices);

	clReleaseKernel(*krnl);
	xcl_release_world(*world);
}

unsigned long linear_search_exec(
		xcl_world *world, cl_kernel *krnl,
		float *targets, float *queries, unsigned int *indices,
		cl_mem *dev_targets, cl_mem *dev_queries, cl_mem *dev_indices
) {
	xcl_memcpy_to_device(*world, *dev_targets, targets, (TARGETS * DIMS) * sizeof(float));
	xcl_memcpy_to_device(*world, *dev_queries, queries, (QUERIES * DIMS) * sizeof(float));

	xcl_set_kernel_arg(*krnl, 0, sizeof(cl_mem), dev_targets);
	xcl_set_kernel_arg(*krnl, 1, sizeof(cl_mem), dev_queries);
	xcl_set_kernel_arg(*krnl, 2, sizeof(cl_mem), dev_indices);

	unsigned long duration = xcl_run_kernel3d(*world, *krnl, 1, 1, 1);

	xcl_memcpy_from_device(*world, indices, *dev_indices, (QUERIES) * sizeof(unsigned int));

	return duration;
}

int main(int argc, char** argv) {
	if (!(argc == 3 || argc == 4)) {
		printf("usage: %s <queries.txt> <targets.txt> [<ref.txt>]\n", argv[0]);
		return EXIT_FAILURE;
	}

	char *queries_filename = argv[1];
	char *targets_filename = argv[2];
	char *refs_filename = NULL;

	int check_results = 0;

	if (argc == 4) {
		refs_filename = argv[3];
		check_results = 1;
	}

	float* queries = (float*) malloc(QUERIES * DIMS * sizeof(float));
	float* targets = (float*) malloc(TARGETS * DIMS * sizeof(float));
	unsigned int* indices = (unsigned int*) malloc(QUERIES * sizeof(unsigned int));

	if (!queries || !targets || !indices) {
		printf("ERROR: Could not allocate memory!\n");
		return EXIT_FAILURE;
	}

	    
	linear_search_read_datafile(queries_filename, queries, QUERIES*DIMS);

	for(size_t i = 0; i < QUERIES*DIMS; i++) {
		if (!isfinite(queries[i])) {
			printf("ERROR: Non finite value specified at queries[%ld]\n", i);
			exit(-1);
		}
	}

	linear_search_read_datafile(targets_filename, targets, TARGETS*DIMS);

	for(size_t i = 0; i < TARGETS*DIMS; i++) {
		if (!isfinite(targets[i])) {
			printf("ERROR: Non Finite value specified at targets[%ld]\n", i);
			exit(-1);
		}
	}

	xcl_world world;
	cl_kernel krnl;

	cl_mem dev_targets, dev_queries, dev_indices;

	linear_search_init(&world, &krnl,
	    &dev_targets, &dev_queries, &dev_indices);

	unsigned long duration = linear_search_exec(
	    &world, &krnl, targets, queries, indices,
	    &dev_targets, &dev_queries, &dev_indices);

	linear_search_exit(&world, &krnl,
	    &dev_targets, &dev_queries, &dev_indices);

	printf("Kernel Execution Time: %ld ns\n", duration);

	float *refs;

	if(check_results == 1) {
		refs = (float*) malloc(sizeof(float) * QUERIES);
		if(!refs) {
			printf("ERROR: Failed to allocate memory!\n");
			return EXIT_FAILURE;
		}
		linear_search_read_datafile(refs_filename, refs, QUERIES);
	}

	int pass = 1;

	for (size_t i = 0; i < QUERIES; i++) {
		size_t j = indices[i];

		if(j > TARGETS) {
			printf("ERROR: target[%lu] invalid\n", j);
			continue;
		}

		float dist_x = queries[DIMS*i + 0] - targets[DIMS*j + 0];
		float dist_y = queries[DIMS*i + 1] - targets[DIMS*j + 1];
		float dist_z = queries[DIMS*i + 2] - targets[DIMS*j + 2];

		float dist = dist_x * dist_x + dist_y * dist_y + dist_z * dist_z;

		printf ("Closest to queries[%5lu] = [% 6.2f % 6.2f % 6.2f] is targets[%5lu] = [% 6.2f % 6.2f % 6.2f] : distance = % 7.2f\n",
		        i, queries[DIMS*i + 0],  queries[DIMS*i + 1], queries[DIMS*i + 2],
		        j, targets[DIMS*j + 0], targets[DIMS*j + 1], targets[DIMS*j +2],
		        dist);

		if (check_results == 1) {
			size_t k = (size_t) refs[i];
			if (j != k) {
				float dist_rx = queries[DIMS*i + 0] - targets[DIMS*k + 0];
				float dist_ry = queries[DIMS*i + 1] - targets[DIMS*k + 1];
				float dist_rz = queries[DIMS*i + 2] - targets[DIMS*k + 2];

				float dist_r = dist_rx * dist_rx + dist_ry * dist_ry + dist_rz * dist_rz;

				if (dist_r < dist) {
					printf("ERROR: Closer target at targets[%5lu] = [% 6.2f % 6.2f % 6.2f] : distance = % 7.2f\n",
					       k, targets[DIMS*k + 0], targets[DIMS*k + 1], targets[DIMS*k + 2], dist_r);
					pass = 0;
				}
			}
		}
	}

	if(pass != 1) {
		printf("ERROR: Test Failed\n");
		return EXIT_FAILURE;
	}

	free(queries);
	free(targets);
	free(indices);

	if(check_results == 1) {
		free(refs);
	}

	printf("INFO: Test Passed\n");

	return EXIT_SUCCESS;
}

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

#include <ap_int.h>
#include <float.h>
#include <math.h>
#include <stdio.h>

#include "linear_search.h"

#ifndef COMPUTE_TARGETS
#define COMPUTE_TARGETS (16)
#endif

#ifndef COMPUTE_QUERIES
#define COMPUTE_QUERIES (16)
#endif

#define QUERY_BLOCKS ((QUERIES - 1) / COMPUTE_QUERIES + 1)
#define TARGET_BLOCKS ((TARGETS - 1) / COMPUTE_TARGETS + 1)

typedef ap_ufixed<38, 20> diff_t;

diff_t linear_search_compute_elem(unsigned int target_x,
                                  unsigned int target_y,
                                  unsigned int target_z,
                                  unsigned int query_x,
                                  unsigned int query_y,
                                  unsigned int query_z) {
   #pragma HLS INLINE

    ap_fixed<32, 16> target_x_fixed, target_y_fixed, target_z_fixed,
        query_x_fixed, query_y_fixed, query_z_fixed;
    target_x_fixed.range(31, 0) = target_x;
    target_y_fixed.range(31, 0) = target_y;
    target_z_fixed.range(31, 0) = target_z;
    query_x_fixed.range(31, 0) = query_x;
    query_y_fixed.range(31, 0) = query_y;
    query_z_fixed.range(31, 0) = query_z;

    ap_fixed<17, 8, AP_TRN, AP_SAT> target_x_trn, target_y_trn, target_z_trn,
        query_x_trn, query_y_trn, query_z_trn;
    target_x_trn = target_x_fixed;
    target_y_trn = target_y_fixed;
    target_z_trn = target_z_fixed;
    query_x_trn = query_x_fixed;
    query_y_trn = query_y_fixed;
    query_z_trn = query_z_fixed;

    ap_fixed<18, 9, AP_TRN> dist_x, dist_y, dist_z;
    dist_x = target_x_trn - query_x_trn;
    dist_y = target_y_trn - query_y_trn;
    dist_z = target_z_trn - query_z_trn;
   #pragma HLS RESOURCE variable=dist_x core=AddSub_DSP
   #pragma HLS RESOURCE variable=dist_y core=AddSub_DSP
   #pragma HLS RESOURCE variable=dist_z core=AddSub_DSP

    ap_ufixed<36, 18, AP_TRN> pair_dist_x, pair_dist_y, pair_dist_z;
    pair_dist_x = dist_x * dist_x;
    pair_dist_y = dist_y * dist_y;
    pair_dist_z = dist_z * dist_z;

    diff_t pair_dist = pair_dist_x;
    pair_dist += pair_dist_y;
    pair_dist += pair_dist_z;
   #pragma HLS RESOURCE variable=pair_dist core=AddSub_DSP

    return pair_dist;
}

void linear_search_compute(
#ifdef __SYNTHESIS__
    unsigned int targets[TARGET_BLOCKS][COMPUTE_TARGETS][DIMS],
    unsigned int queries[QUERY_BLOCKS][COMPUTE_QUERIES][DIMS],
    unsigned int indices[QUERY_BLOCKS][COMPUTE_QUERIES]
#else
    unsigned int ***targets, unsigned int ***queries, unsigned int **indices
#endif
) {
   #pragma HLS INLINE

    diff_t dists[QUERY_BLOCKS][COMPUTE_QUERIES];
   #pragma HLS ARRAY_PARTITION variable=dists complete dim=2

    //#define BUGFIX_LOOP_FLATTEN

#ifdef BUGFIX_LOOP_FLATTEN
COMPUTE_TARGETS_LOOP:
    for (size_t t = 0; t < TARGET_BLOCKS; t++) {
    COMPUTE_QUERIES_LOOP:
        for (size_t q = 0; q < QUERY_BLOCKS; q++) {
#else
COMPUTE_LOOP:
    for (size_t i = 0; i < TARGET_BLOCKS * QUERY_BLOCKS; i++) {
        {
            size_t t = i / QUERY_BLOCKS;
            size_t q = i % QUERY_BLOCKS;
#endif
           #pragma HLS PIPELINE II=1
#ifndef __SYNTHESIS__
            if (t % 1000 == 0 && q % 1000 == 0) {
                printf("COMPUTE [ %d, %d ]\n", q, t);
            }
#endif
            diff_t ldists[COMPUTE_QUERIES][COMPUTE_TARGETS];
           #pragma HLS ARRAY_PARTITION variable=ldists complete dim=0

            diff_t min_dist[COMPUTE_QUERIES];
            unsigned int min_indices[COMPUTE_QUERIES];
           #pragma HLS ARRAY_PARTITION variable=min_dist complete
           #pragma HLS ARRAY_PARTITION variable=min_indices complete

            for (size_t j = 0; j < COMPUTE_QUERIES; j++) {
                if (t == 0) {
                    min_dist[j].range(37, 0) = 0x3FFFFFFFFL;
                    min_indices[j] = -1;
                } else {
                    min_dist[j] = dists[q][j];
                    min_indices[j] = indices[q][j];
                }
            }

            unsigned int lqueries[COMPUTE_QUERIES][DIMS];
           #pragma HLS ARRAY_PARTITION variable=lqueries complete dim=0

            for (size_t j = 0; j < COMPUTE_QUERIES; j++) {
                for (size_t k = 0; k < DIMS; k++) {
                    lqueries[j][k] = queries[q][j][k];
                }
            }

            unsigned int ltargets[COMPUTE_TARGETS][DIMS];
           #pragma HLS ARRAY_PARTITION variable=ltargets complete dim=0

            for (size_t j = 0; j < COMPUTE_TARGETS; j++) {
               #pragma HLS UNROLL
                for (size_t k = 0; k < DIMS; k++) {
                   #pragma HLS UNROLL
                    ltargets[j][k] = targets[t][j][k];
                }
            }

            for (size_t j = 0; j < COMPUTE_QUERIES; j++) {
                for (size_t k = 0; k < COMPUTE_TARGETS; k++) {
                    if (t * COMPUTE_TARGETS + k < TARGETS &&
                        q * COMPUTE_QUERIES + j < QUERIES) {
                        ldists[j][k] =
                            linear_search_compute_elem(ltargets[k][0],
                                                       ltargets[k][1],
                                                       ltargets[k][2],
                                                       lqueries[j][0],
                                                       lqueries[j][1],
                                                       lqueries[j][2]);
                    } else {
                        /* Set to positive infinity */
                        ldists[j][k].range(37, 0) = 0x3FFFFFFFFFL;
                    }
                }
            }

            for (size_t j = 0; j < COMPUTE_QUERIES; j++) {
                for (size_t k = 0; k < COMPUTE_TARGETS; k++) {
                    if (ldists[j][k] < min_dist[j]) {
                        min_dist[j] = ldists[j][k];
                        min_indices[j] = t * COMPUTE_TARGETS + k;
                    }
                }
            }

            for (size_t j = 0; j < COMPUTE_QUERIES; j++) {
                dists[q][j] = min_dist[j];
                indices[q][j] = min_indices[j];
            }
        }
    }
}

void linear_search(float *targets, float *queries, unsigned int *indices) {
   #pragma HLS INLINE

#ifdef __SYNTHESIS__
    unsigned int queries_buf[QUERY_BLOCKS][COMPUTE_QUERIES][DIMS];
#pragma HLS ARRAY_PARTITION variable = queries_buf complete dim = 2
#pragma HLS ARRAY_PARTITION variable = queries_buf complete dim = 3
#else
    unsigned int ***queries_buf =
        (unsigned int ***)malloc(sizeof(unsigned int **) * QUERY_BLOCKS);
    for (int i = 0; i < QUERY_BLOCKS; i++) {
        queries_buf[i] =
            (unsigned int **)malloc(sizeof(unsigned int *) * COMPUTE_QUERIES);
        for (int j = 0; j < COMPUTE_QUERIES; j++) {
            queries_buf[i][j] =
                (unsigned int *)malloc(sizeof(unsigned int) * DIMS);
        }
    }
#endif

QUERIES_LOOP:
    for (size_t i = 0; i < QUERIES * DIMS; i++) {
       #pragma HLS PIPELINE II=1
        size_t x = i % DIMS;
        size_t y = (i / DIMS) % COMPUTE_QUERIES;
        size_t z = i / DIMS / COMPUTE_QUERIES;
        ap_fixed<32, 16, AP_TRN, AP_SAT> tfixed = queries[i];
        queries_buf[z][y][x] = tfixed.range(31, 0);
    }

#ifdef __SYNTHESIS__
    unsigned int targets_buf[TARGET_BLOCKS][COMPUTE_TARGETS][DIMS];
#pragma HLS ARRAY_PARTITION variable = targets_buf complete dim = 2
#pragma HLS ARRAY_PARTITION variable = targets_buf complete dim = 3
#else
    unsigned int ***targets_buf =
        (unsigned int ***)malloc(sizeof(unsigned int **) * TARGET_BLOCKS);
    for (int i = 0; i < TARGET_BLOCKS; i++) {
        targets_buf[i] =
            (unsigned int **)malloc(sizeof(unsigned int *) * COMPUTE_TARGETS);
        for (int j = 0; j < COMPUTE_TARGETS; j++) {
            targets_buf[i][j] =
                (unsigned int *)malloc(sizeof(unsigned int) * DIMS);
        }
    }
#endif

TARGETS_LOOP:
    for (size_t i = 0; i < TARGETS * DIMS; i++) {
       #pragma HLS PIPELINE II=1
        size_t x = i % DIMS;
        size_t y = (i / DIMS) % COMPUTE_TARGETS;
        size_t z = i / DIMS / COMPUTE_TARGETS;
        ap_fixed<32, 16, AP_TRN, AP_SAT> tfixed = targets[i];
        targets_buf[z][y][x] = tfixed.range(31, 0);
    }

#ifdef __SYNTHESIS__
    unsigned int indices_buf[QUERY_BLOCKS][COMPUTE_QUERIES];
#pragma HLS ARRAY_PARTITION variable = indices_buf complete dim = 2
#else
    unsigned int **indices_buf =
        (unsigned int **)malloc(sizeof(unsigned int *) * QUERY_BLOCKS);
    for (int i = 0; i < QUERY_BLOCKS; i++) {
        indices_buf[i] =
            (unsigned int *)malloc(sizeof(unsigned int) * COMPUTE_QUERIES);
    }
#endif

#ifndef __SYNTHESIS__
    printf("START COMPUTE\n");
#endif
    linear_search_compute(targets_buf, queries_buf, indices_buf);
#ifndef __SYNTHESIS__
    printf("FINISHED COMPUTE\n");
#endif

INDICES_LOOP:
    for (size_t i = 0; i < QUERIES; i++) {
       #pragma HLS PIPELINE II=1
        size_t x = i % COMPUTE_QUERIES;
        size_t y = i / COMPUTE_QUERIES;
        indices[i] = indices_buf[y][x];
    }
}

extern "C" {
void krnl_linear_search(
    // inputs
    float *targets,
    float *queries,
    // outputs
    unsigned int *indices) {
   #pragma HLS INTERFACE m_axi port=targets offset=slave bundle=gmem
   #pragma HLS INTERFACE s_axilite port=targets bundle=control
   #pragma HLS INTERFACE m_axi port=queries offset=slave bundle=gmem
   #pragma HLS INTERFACE s_axilite port=queries bundle=control
   #pragma HLS INTERFACE m_axi port=indices offset=slave bundle=gmem1
   #pragma HLS INTERFACE s_axilite port=indices bundle=control
   #pragma HLS INTERFACE s_axilite port=return bundle=control

    linear_search(targets, queries, indices);
}
}

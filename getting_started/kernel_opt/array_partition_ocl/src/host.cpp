/*******************************************************************************
Copyright (c) 2016, Xilinx, Inc.
All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice,
this list of conditions and the following disclaimer in the documentation and/or
other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors
may be used to endorse or promote products derived from this software without
specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*******************************************************************************/

#include "CL/cl.h"
#include "xcl.h"

#include <algorithm>
#include <cstdio>
#include <random>
#include <vector>

using std::default_random_engine;
using std::generate;
using std::uniform_int_distribution;
using std::vector;

// row major
void matmul(vector<int> &C, vector<int> &A, vector<int> &B, int M) {
    for (int k = 0; k < M; k++) {
        for (int j = 0; j < M; j++) {
            for (int i = 0; i < M; i++) {
                C[k * M + j] += A[k * M + i] * B[i * M + j];
            }
        }
    }
}

int gen_random() {
  static default_random_engine e;
  static uniform_int_distribution<int> dist(0, 10);

  return dist(e);
}


void print(vector<int> &data, int columns, int rows) {
    vector<int> out(columns * rows);
    for (int r = 0; r < 10; r++) {
        for (int c = 0; c < 10; c++) {
            printf("%4d ", data[r * columns + c]);
        }
        printf("…\n");
    }
    for (int r = 0; r < 10; r++) {
      printf("   %s ", "…");
    }
    printf("⋱\n\n");
}

void verify(vector<int> &gold, vector<int> &output) {
    for (int i = 0; i < (int)output.size(); i++) {
        if (output[i] != gold[i]) {
            printf("Mismatch %d: gold: %d device: %d\n", i, gold[i], output[i]);
            print(output, 16, 16);
            exit(EXIT_FAILURE);
        }
    }
}

// This example illustrates how to use array partitioning attributes in OpenCL
// kernels for FPGA devices using matmul.
int main(int argc, char **argv) {
    static const int columns = 64;
    static const int rows = 64;

    vector<int> A(columns * rows);
    vector<int> B(columns * rows);
    vector<int> gold(columns * rows, 0);
    vector<int> C(columns * rows, 0);
    generate(begin(A), end(A), gen_random);
    generate(begin(B), end(B), gen_random);

    printf("A:\n");
    print(A, columns, rows);
    printf("B:\n");
    print(B, columns, rows);
    matmul(gold, A, B, columns);

    printf("Gold:\n");
    print(gold, columns, rows);

    xcl_world world = xcl_world_single();
    cl_program program = xcl_import_binary(world, "matmul");

    // compute the size of array in bytes
    size_t array_size_bytes = columns * rows * sizeof(int);

    cl_mem buffer_a = xcl_malloc(world, CL_MEM_READ_ONLY, array_size_bytes);
    cl_mem buffer_b = xcl_malloc(world, CL_MEM_READ_ONLY, array_size_bytes);
    cl_mem buffer_c = xcl_malloc(world, CL_MEM_WRITE_ONLY, array_size_bytes);

    xcl_memcpy_to_device(world, buffer_a, A.data(), array_size_bytes);
    xcl_memcpy_to_device(world, buffer_b, B.data(), array_size_bytes);

  printf( "|-------------------------+-------------------------|\n"
          "| Kernel                  |    Wall-Clock Time (ns) |\n"
          "|-------------------------+-------------------------|\n");
    cl_kernel matmul_kernel = xcl_get_kernel(program, "matmul");
    xcl_set_kernel_arg(matmul_kernel, 0, sizeof(cl_mem), &buffer_a);
    xcl_set_kernel_arg(matmul_kernel, 1, sizeof(cl_mem), &buffer_b);
    xcl_set_kernel_arg(matmul_kernel, 2, sizeof(cl_mem), &buffer_c);
    xcl_set_kernel_arg(matmul_kernel, 3, sizeof(cl_int), &columns);

    auto matmul_time = xcl_run_kernel3d(world, matmul_kernel, 1, 1, 1);
    xcl_memcpy_from_device(world, C.data(), buffer_c, array_size_bytes);
    verify(gold, C);
    printf("| %-23s | %23lu |\n", "matmul: ", matmul_time);

    cl_kernel matmul_partition_kernel =
        xcl_get_kernel(program, "matmul_partition");
    xcl_set_kernel_arg(matmul_partition_kernel, 0, sizeof(cl_mem), &buffer_a);
    xcl_set_kernel_arg(matmul_partition_kernel, 1, sizeof(cl_mem), &buffer_b);
    xcl_set_kernel_arg(matmul_partition_kernel, 2, sizeof(cl_mem), &buffer_c);
    xcl_set_kernel_arg(matmul_partition_kernel, 3, sizeof(cl_int), &columns);

    auto matmul_partition_time =
        xcl_run_kernel3d(world, matmul_partition_kernel, 1, 1, 1);
    xcl_memcpy_from_device(world, C.data(), buffer_c, array_size_bytes);
    verify(gold, C);
    printf("| %-23s | %23lu |\n", "matmul: partition", matmul_partition_time);

    printf("|-------------------------+-------------------------|\n");
    printf("Note: Wall Clock Time is meaningful for real hardware execution only, not for emulation.\n");
    printf("Please refer to profile summary for kernel execution time for hardware emulation.\n");
    printf("TEST PASSED\n\n");

    return EXIT_SUCCESS;
}

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

const int DATA_SIZE = 1<<10;

int gen_random() {
  static default_random_engine e;
  static uniform_int_distribution<int> dist(0, 100);

  return dist(e);
}

void verify(const vector<int> &gold, const vector<int> &out) {
  if (!equal(begin(gold), end(gold), begin(out))) {
    printf("TEST FAILED\n");
    exit(EXIT_FAILURE);
  }
}

int main(int argc, char** argv)
{
    // compute the size of array in bytes
    int size_in_bytes = DATA_SIZE * sizeof(int);

    xcl_world world = xcl_world_single();
    cl_program program = xcl_import_binary(world, "vector_addition");

    cl_mem buffer_a = xcl_malloc(world, CL_MEM_READ_ONLY, size_in_bytes);
    cl_mem buffer_b = xcl_malloc(world, CL_MEM_READ_ONLY, size_in_bytes);
    cl_mem buffer_result = xcl_malloc(world, CL_MEM_WRITE_ONLY, size_in_bytes);

    // Creates a vector of DATA_SIZE elements with an initial value of 10 and 32
    vector<int> source_a(DATA_SIZE);
    vector<int> source_b(DATA_SIZE);
    vector<int> source_results(DATA_SIZE);
    generate(begin(source_a), end(source_a), gen_random);
    generate(begin(source_b), end(source_b), gen_random);

    vector<int> gold(DATA_SIZE);
    transform(begin(source_a), end(source_a),
              begin(source_b), begin(gold), std::plus<int>());

    xcl_memcpy_to_device(world, buffer_a, source_a.data(), size_in_bytes);
    xcl_memcpy_to_device(world, buffer_b, source_b.data(), size_in_bytes);

    printf( "|-------------------------+-----------------|\n"
            "| Kernel                  |    Runtime (ns) |\n"
            "|-------------------------+-----------------|\n");

    cl_kernel kernel_vadd = xcl_get_kernel(program, "vadd");

    xcl_set_kernel_arg(kernel_vadd, 0, sizeof(cl_mem), &buffer_result);
    xcl_set_kernel_arg(kernel_vadd, 1, sizeof(cl_mem), &buffer_a);
    xcl_set_kernel_arg(kernel_vadd, 2, sizeof(cl_mem), &buffer_b);
    xcl_set_kernel_arg(kernel_vadd, 3, sizeof(int), &DATA_SIZE);

    auto simple_time = xcl_run_kernel3d(world, kernel_vadd, 1, 1, 1);
    printf("| %-22s  | %15lu |\n", "vadd: simple", simple_time);

    xcl_memcpy_from_device(world, source_results.data(), buffer_result,
                           size_in_bytes);
    verify(gold, source_results);

    cl_kernel kernel_pipelined = xcl_get_kernel(program, "vadd_pipelined");

    xcl_set_kernel_arg(kernel_pipelined, 0, sizeof(cl_mem), &buffer_result);
    xcl_set_kernel_arg(kernel_pipelined, 1, sizeof(cl_mem), &buffer_a);
    xcl_set_kernel_arg(kernel_pipelined, 2, sizeof(cl_mem), &buffer_b);
    xcl_set_kernel_arg(kernel_pipelined, 3, sizeof(int), &DATA_SIZE);

    auto pipelined_time = xcl_run_kernel3d(world, kernel_pipelined, 1, 1, 1);
    printf("| %-22s  | %15lu |\n", "vadd: pipelined", pipelined_time);
    printf("|-------------------------+-----------------|\n");

    xcl_memcpy_from_device(world, source_results.data(), buffer_result,
                           size_in_bytes);
    verify(gold, source_results);

    // These functions will release the OpenCL resources.
    clReleaseMemObject(buffer_a);
    clReleaseMemObject(buffer_b);
    clReleaseMemObject(buffer_result);
    clReleaseKernel(kernel_vadd);
    clReleaseProgram(program);
    xcl_release_world(world);

    printf("TEST PASSED.\n");
    return EXIT_SUCCESS;
}

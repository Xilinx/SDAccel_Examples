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
#include <fstream>
#include <random>
#include <tuple>
#include <utility>
#include <vector>

using std::default_random_engine;
using std::equal;
using std::generate;
using std::ifstream;
using std::ignore;
using std::make_pair;
using std::numeric_limits;
using std::uniform_int_distribution;
using std::vector;

// Wrap any OpenCL API calls that return error code(cl_int)
// with the below macro to quickly check for an error
#define OCL_CHECK(call)                                                        \
  do {                                                                         \
    cl_int err = call;                                                         \
    if (err != CL_SUCCESS) {                                                   \
      printf("Error from " #call ", error code is %d\n", err);                 \
      exit(1);                                                                 \
    }                                                                          \
  } while (0);

void find_nearest_neighbor(vector<int> &out, const int dim,
                           const vector<int> &search_points,
                           const vector<int> &points, const int len);

int gen_random() {
  static default_random_engine e;
  static uniform_int_distribution<int> dist(0, 100);

  return dist(e);
}

void verify(vector<int> gold, vector<int> test) {
  bool match = true;
  match = equal(begin(gold), end(gold), begin(test));

  if (!match) {
    printf("\n TEST FAILED\n");
    exit(EXIT_FAILURE);
  }
}

void
print_point(vector<int>& point) {
  for (int element : point) printf("%d ", element);
  printf("\n");
}

// This example illustrates the algorithm of nearest neighbor search for a given
// point (x, y) from a list of points.
int main(int argc, char **argv) {

  static const int num_points = 512;
  static const int num_dims = 2;

  vector<int> data(num_points * num_dims);
  vector<int> input(1 * num_dims);
  vector<int> out(input.size());
  generate(begin(data), end(data), gen_random);
  generate(begin(input), end(input), gen_random);

  printf("Number Of Points: %d\n", num_points);
  printf("Dimensions: %d\n", num_dims);
  printf("\nInput Point:      ");
  print_point(input);

  vector<int> gold;
  find_nearest_neighbor(gold, num_dims, input, data, num_points);
  printf("Nearest Neighbor: ");
  print_point(gold);

  size_t array_size_bytes = num_points * num_dims * sizeof(int);

  xcl_world world = xcl_world_single();
  cl_program program = xcl_import_binary(world, "nearest_neighbor");

  cl_mem buffer_out =
      xcl_malloc(world, CL_MEM_WRITE_ONLY, num_dims * sizeof(int));
  cl_mem buffer_points = xcl_malloc(world, CL_MEM_READ_ONLY, array_size_bytes);
  cl_mem buffer_in =
      xcl_malloc(world, CL_MEM_READ_ONLY, num_dims * sizeof(int));

  // copy the input arrays to memories allocated on the device
  xcl_memcpy_to_device(world, buffer_points, data.data(), array_size_bytes);
  xcl_memcpy_to_device(world, buffer_in, input.data(), num_dims * sizeof(int));

  printf( "|--------------------------------+-------------------------|\n"
          "| Kernel                         |    Wall-Clock Time (ns) |\n"
          "|--------------------------------+-------------------------|\n");

  // set kernel parameters
  cl_kernel kernel = xcl_get_kernel(program, "nearest_neighbor");
  xcl_set_kernel_arg(kernel, 0, sizeof(cl_mem), &buffer_out);
  xcl_set_kernel_arg(kernel, 1, sizeof(cl_mem), &buffer_points);
  xcl_set_kernel_arg(kernel, 2, sizeof(cl_mem), &buffer_in);
  xcl_set_kernel_arg(kernel, 3, sizeof(cl_int), &num_points);
  xcl_set_kernel_arg(kernel, 4, sizeof(cl_int), &num_dims);

  auto simple_time = xcl_run_kernel3d(world, kernel, 1, 1, 1);
  printf("| %-30s | %23lu |\n", "Nearest Neighbor: simple", simple_time);

  xcl_memcpy_from_device(world, out.data(), buffer_out, num_dims * sizeof(int));
  verify(gold, out);

  // set kernel parameters
  cl_kernel kernel_loop = xcl_get_kernel(program, "nearest_neighbor_loop_fusion");
  xcl_set_kernel_arg(kernel_loop, 0, sizeof(cl_mem), &buffer_out);
  xcl_set_kernel_arg(kernel_loop, 1, sizeof(cl_mem), &buffer_points);
  xcl_set_kernel_arg(kernel_loop, 2, sizeof(cl_mem), &buffer_in);
  xcl_set_kernel_arg(kernel_loop, 3, sizeof(cl_int), &num_points);
  xcl_set_kernel_arg(kernel_loop, 4, sizeof(cl_int), &num_dims);

  auto loop_time = xcl_run_kernel3d(world, kernel_loop, 1, 1, 1);
  printf("| %-30s | %23lu |\n", "Nearest Neighbor: loop fusion", loop_time);

  xcl_memcpy_from_device(world, out.data(), buffer_out, num_dims * sizeof(int));
  verify(gold, out);
  printf("|--------------------------------+-------------------------|\n");
  printf("Note: Wall Clock Time is meaningful for real hardware execution only, not for emulation.\n");
  printf("Please refer to profile summary for kernel execution time for hardware emulation.\n");

  // free memory buffers allocated on the accelerator device
  OCL_CHECK(clReleaseMemObject(buffer_out));
  OCL_CHECK(clReleaseMemObject(buffer_points));
  OCL_CHECK(clReleaseMemObject(buffer_in));

  // release other opencl objects
  clReleaseKernel(kernel);
  xcl_release_world(world);

  printf("TEST PASSED\n");
  return EXIT_SUCCESS;
}

void find_nearest_neighbor(vector<int> &out, const int dim,
                           const vector<int> &search_points,
                           const vector<int> &points, const int num_points) {
  // points is the list of data points that need to be searched for the given
  // point (x, y)
  //
  // output array out has two values - the closest point to given input point
  int best_i = 0;
  int best_dist = numeric_limits<int>::max();

  for (int p = 0; p < num_points; ++p) {
    int dist = 0;

    for (int c = 0; c < dim; ++c) {
      int dx = abs(points[dim * p + c] - search_points[c]);
      dist += dx * dx;
    }

    if (dist < best_dist) {
      best_i = p;
      best_dist = dist;
    }
  }

  out.resize(dim);
  for (int c = 0; c < dim; ++c) {
    out[c] = points[best_i * dim + c];
  }
}

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

const int VERTEX_COUNT = 512;

struct vertex {
  int x;
  int y;
  int z;
  int w; // This element is used for alignment purposes
};

// Each struct represents several vertices. The data is organized as a
// structure of arrays. This means that each element of the arrays represents
// one vertix in a triangle.
struct vertex_array {
  vector<int> x;
  vector<int> y;
  vector<int> z;
  vertex_array(int count) : x(count), y(count), z(count) {}
};

// Returns an integer in the range [0, n)
int randint(int n) { return rand() % n; }

int gen_random() {
  static default_random_engine e;
  static uniform_int_distribution<int> dist(0, 100);

  return dist(e);
}

void compute_dot(vector<int> &result, const vector<int> &X,
                 const vector<int> &Y, const vector<int> &Z,
                 const int num_vertices) {
  for (int t = 0; t < num_vertices; ++t) {
    result[t] = X[t] * X[t];
    result[t] += Y[t] * Y[t];
    result[t] += Z[t] * Z[t];
  }
}

void verify (const vector<int>& gold, const vector<int>& results) {
  if(!equal(begin(gold), end(gold), begin(results))) {
    printf("TEST FAILED\n");
    exit(EXIT_FAILURE);
  }
}

// Array of Structures vs. Structure of Arrays
//
// This example explores the affect of data layout on performance. Typically
// data parallel computations benefit from the Structure layout. In this example
// we will explore the performance of dot product using Structure of Arrays and
// Array of Structures.
int main(int argc, char **argv) {
  char *binary_file_path = argv[1];

  // allocate memory on host to store input arrays and the output array
  vector<int> results(VERTEX_COUNT);

  vertex_array soa_vertices(VERTEX_COUNT);
  generate(begin(soa_vertices.x), end(soa_vertices.x), gen_random);
  generate(begin(soa_vertices.y), end(soa_vertices.y), gen_random);
  generate(begin(soa_vertices.z), end(soa_vertices.z), gen_random);

  vector<vertex> aos_vertices(VERTEX_COUNT);
  for (int i = 0; i < (int)aos_vertices.size(); i++) {
    aos_vertices[i].x = soa_vertices.x[i];
    aos_vertices[i].y = soa_vertices.y[i];
    aos_vertices[i].z = soa_vertices.z[i];
  }
  // Calculate gold result
  vector<int> gold(VERTEX_COUNT);
  compute_dot(gold, soa_vertices.x, soa_vertices.y, soa_vertices.z,
              VERTEX_COUNT);

  // Initialize OpenCL context and load xclbin binary
  xcl_world world = xcl_world_single();
  cl_program program = xcl_import_binary(world, "dot");

  // Allocate memory on the FPGA
  cl_mem buffer_result =
      xcl_malloc(world, CL_MEM_READ_WRITE, results.size() * sizeof(int));
  cl_mem buffer_x =
      xcl_malloc(world, CL_MEM_READ_ONLY, soa_vertices.x.size() * sizeof(int));
  cl_mem buffer_y =
      xcl_malloc(world, CL_MEM_READ_ONLY, soa_vertices.y.size() * sizeof(int));
  cl_mem buffer_z =
      xcl_malloc(world, CL_MEM_READ_ONLY, soa_vertices.z.size() * sizeof(int));

  // Transfer data from host to the FPGA
  xcl_memcpy_to_device(world, buffer_x, soa_vertices.x.data(),
                       soa_vertices.x.size() * sizeof(int));
  xcl_memcpy_to_device(world, buffer_y, soa_vertices.y.data(),
                       soa_vertices.y.size() * sizeof(int));
  xcl_memcpy_to_device(world, buffer_z, soa_vertices.z.data(),
                       soa_vertices.z.size() * sizeof(int));
  printf( "|-------------------------+-------------------------|\n"
          "| Kernel                  |    Wall-Clock Time (ns) |\n"
          "|-------------------------+-------------------------|\n");

  // Allocate memory for the array of struct data structure
  cl_mem buffer_pts =
      xcl_malloc(world, CL_MEM_READ_ONLY, aos_vertices.size() * sizeof(vertex));

  // Transfer the entire array to the FPGA
  xcl_memcpy_to_device(world, buffer_pts, aos_vertices.data(),
                       aos_vertices.size() * sizeof(vertex));
  cl_kernel kernel_aos = xcl_get_kernel(program, "dot_aos");

  // Set the kernel parameters and launch the kernel. Reuse the buffer_result.
  xcl_set_kernel_arg(kernel_aos, 0, sizeof(cl_mem), &buffer_result);
  xcl_set_kernel_arg(kernel_aos, 1, sizeof(cl_mem), &buffer_pts);
  xcl_set_kernel_arg(kernel_aos, 2, sizeof(cl_int), &VERTEX_COUNT);
  auto aos_time = xcl_run_kernel3d(world, kernel_aos, 1, 1, 1);
  printf("| %-22s  | %23lu |\n", "dot: Array of Structs", aos_time);

  // Transfer the results back from the GPU
  xcl_memcpy_from_device(world, results.data(), buffer_result,
                         results.size() * sizeof(int));
  verify(gold, results);

  cl_kernel kernel_soa = xcl_get_kernel(program, "dot_soa");

  // Set the kernel parameters and launch the kernel
  xcl_set_kernel_arg(kernel_soa, 0, sizeof(cl_mem), &buffer_result);
  xcl_set_kernel_arg(kernel_soa, 1, sizeof(cl_mem), &buffer_x);
  xcl_set_kernel_arg(kernel_soa, 2, sizeof(cl_mem), &buffer_y);
  xcl_set_kernel_arg(kernel_soa, 3, sizeof(cl_mem), &buffer_z);
  xcl_set_kernel_arg(kernel_soa, 4, sizeof(cl_int), &VERTEX_COUNT);
  auto soa_time = xcl_run_kernel3d(world, kernel_soa, 1, 1, 1);
  printf("| %-22s  | %23lu |\n", "dot: Struct of Arrays", soa_time);

  // Get the results from the FPGA
  xcl_memcpy_from_device(world, results.data(), buffer_result,
                         results.size() * sizeof(int));
  verify(gold, results);
  printf("|-------------------------+-------------------------|\n");
  printf("Note: Wall Clock Time is meaningful for real hardware execution only, not for emulation.\n");
  printf("Please refer to profile summary for kernel execution time for hardware emulation.\n");
  printf("TEST PASSED\n\n");
  return EXIT_SUCCESS;
}

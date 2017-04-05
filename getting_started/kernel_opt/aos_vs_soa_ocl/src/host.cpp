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
#include "xcl2.hpp"
#include <vector>
#include <random>
#include <algorithm>

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

  std::vector<cl::Device> devices = xcl::get_xil_devices();
  cl::Device device = devices[0];
  //Creating Context and Command Queue for selected Device 
  cl::Context context(device);
  cl::CommandQueue q(context, device);
  std::string device_name = device.getInfo<CL_DEVICE_NAME>(); 
  std::cout << "Found Device=" << device_name.c_str() << std::endl;
  cl::Program::Binaries bins = xcl::import_binary(device_name,"dot");
  devices.resize(1);
  cl::Program program(context, devices, bins);
 
  // Allocate memory on the FPGA
  cl::Buffer buffer_result(context, CL_MEM_READ_WRITE, results.size() * sizeof(int));
  cl::Buffer buffer_x(context, CL_MEM_READ_ONLY, soa_vertices.x.size() * sizeof(int));
  cl::Buffer buffer_y(context, CL_MEM_READ_ONLY, soa_vertices.y.size() * sizeof(int));
  cl::Buffer buffer_z(context, CL_MEM_READ_ONLY, soa_vertices.z.size() * sizeof(int));

  // Transfer data from host to the FPGA
  q.enqueueWriteBuffer(buffer_x,CL_TRUE,0,soa_vertices.x.size() * sizeof(int),
          soa_vertices.x.data());
  q.enqueueWriteBuffer(buffer_y,CL_TRUE,0,soa_vertices.y.size() * sizeof(int),
          soa_vertices.y.data());
  q.enqueueWriteBuffer(buffer_z,CL_TRUE,0,soa_vertices.z.size() * sizeof(int),
          soa_vertices.z.data());
  q.finish();
  printf( "|-------------------------+-------------------------|\n"
          "| Kernel                  |    Wall-Clock Time (ns) |\n"
          "|-------------------------+-------------------------|\n");

  // Allocate memory for the array of struct data structure
  cl::Buffer buffer_pts(context, CL_MEM_READ_ONLY, aos_vertices.size() * sizeof(vertex));

  // Transfer the entire array to the FPGA
  q.enqueueWriteBuffer(buffer_pts,CL_TRUE,0,
          aos_vertices.size() * sizeof(vertex),aos_vertices.data());

  cl::Event event;
  int nargs=0;
  uint64_t nstimestart, nstimeend;
  cl::Kernel kernel_aos(program,"dot_aos");
  kernel_aos.setArg(nargs++,buffer_result);
  kernel_aos.setArg(nargs++,buffer_pts);
  kernel_aos.setArg(nargs++,VERTEX_COUNT);
  q.enqueueTask(kernel_aos,NULL,&event);
  q.finish();
  event.getProfilingInfo<uint64_t>(CL_PROFILING_COMMAND_START,&nstimestart);
  event.getProfilingInfo<uint64_t>(CL_PROFILING_COMMAND_END,&nstimeend);
  auto aos_time = nstimeend-nstimestart;
  printf("| %-22s  | %23lu |\n", "dot: Array of Structs", aos_time);

  // Transfer the results back from the FPGA
  q.enqueueReadBuffer(buffer_result, CL_TRUE, 0, results.size() * sizeof(int), results.data());
  q.finish();
  verify(gold, results);

  cl::Kernel kernel_soa(program,"dot_soa");
  nargs=0;
  kernel_soa.setArg(nargs++,buffer_result);
  kernel_soa.setArg(nargs++,buffer_x);
  kernel_soa.setArg(nargs++,buffer_y);
  kernel_soa.setArg(nargs++,buffer_z);
  kernel_soa.setArg(nargs++,VERTEX_COUNT);
  q.enqueueTask(kernel_soa,NULL,&event);
  q.finish();
  event.getProfilingInfo<uint64_t>(CL_PROFILING_COMMAND_START,&nstimestart);
  event.getProfilingInfo<uint64_t>(CL_PROFILING_COMMAND_END,&nstimeend);
  auto soa_time = nstimeend-nstimestart;
  printf("| %-22s  | %23lu |\n", "dot: Struct of Arrays", soa_time);

  // Get the results from the FPGA
  q.enqueueReadBuffer(buffer_result, CL_TRUE, 0, results.size() * sizeof(int),results.data());
  q.finish();
  verify(gold, results);
  printf("|-------------------------+-------------------------|\n");
  printf("Note: Wall Clock Time is meaningful for real hardware execution only, not for emulation.\n");
  printf("Please refer to profile summary for kernel execution time for hardware emulation.\n");
  printf("TEST PASSED\n\n");
  return EXIT_SUCCESS;
}

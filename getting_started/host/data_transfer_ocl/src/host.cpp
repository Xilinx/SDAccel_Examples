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
#include <cstdlib>
#include <string>
#include <vector>

using std::vector;
using std::find;

static const int elements = 1e8;

void check(cl_int err) {
  if (err) {
    printf("ERROR: Operation Failed: %d\n", err);
    exit(EXIT_FAILURE);
  }
}

void verify(const xcl_world &world, const cl_mem mem, const int value) {
  vector<int> values(elements, 0);
  clEnqueueReadBuffer(world.command_queue, mem, CL_TRUE, 0,
                      elements * sizeof(int), values.data(), 0, nullptr,
                      nullptr);
  if (find(begin(values), end(values), value) == end(values)) {
    printf("TEST FAILED\n");
    exit(EXIT_FAILURE);
  }
}

// This example illustrates how to transfer data back and forth
// between host and device
int main(int argc, char **argv) {
  vector<int> host_memory(elements, 42);
  vector<int> host_memory2(elements, 15);

  size_t size_in_bytes = host_memory.size() * sizeof(int);
  cl_int err;

  xcl_world world = xcl_world_single();

  printf("Allocating and transferring data to %s\n", world.device_name);
  // There are several ways to transfer data to the FPGA. The most
  // straightforward way is to transfer the data during the creation of the
  // cl_mem object using the CL_MEM_COPY_HOST_PTR flag
  cl_mem during_allocation =
      clCreateBuffer(world.context, CL_MEM_COPY_HOST_PTR, size_in_bytes,
                     host_memory.data(), &err);
  verify(world, during_allocation, 42);

  // Normally you will be reading and writing to a cl_mem object. The following
  // examples will make use of this buffer object.
  //
  // NOTE: The CL_MEM_READ_ONLY flag indicates that the FPGA can only read from
  // this location. The host can read and write to this buffer at any time
  cl_mem buffer = xcl_malloc(world, CL_MEM_READ_ONLY, size_in_bytes);

  cl_event blocking_call_event = 0;
  printf("Writing %.1e elements to buffer using a blocking transfer\n",
         (float)elements);
  // Copying data to the FPGA is done using an enqueue write operation.
  err = clEnqueueWriteBuffer(world.command_queue, // command queue
                             buffer,              // buffer on the FPGA
                             CL_TRUE,             // blocking call
                             0,                   // buffer offset in bytes
                             size_in_bytes,       // Size in bytes
                             host_memory.data(),  // Pointer to the data to copy
                             0, nullptr, &blocking_call_event);
  verify(world, buffer, 42);

  cl_event async_event = 0;
  printf("Writing %.1e elements to buffer using a non-blocking transfer\n",
         (float)elements);
  // Data can also be copied asynchronously with respect to the main thread by
  // sending CL_FALSE as the second parameter
  err = clEnqueueWriteBuffer(
      world.command_queue, buffer,
      CL_FALSE, // false indicates this is asynchronous call
      0, size_in_bytes, host_memory2.data(), 0, nullptr, &async_event);

  printf("Write Enqueued. Waiting to complete.\n");
  // It is the user's responsibility to make sure the data does not change
  // between the call and the actual operation. This can be ensured using OpenCL
  // events
  clWaitForEvents(1, &async_event);
  verify(world, buffer, 15);
  printf("Write operation completed successfully\n");

  cl_event read_event = 0;
  printf("Reading %.1e elements from buffer\n", (float)elements);
  // Data can be transferred back to the host using the read buffer operation
  clEnqueueReadBuffer(world.command_queue,
                      buffer,  // This buffers data will be read
                      CL_TRUE, // blocking call
                      0,       // offset
                      size_in_bytes,
                      host_memory.data(), // Data will be stored here
                      0, nullptr, &read_event);

  printf("Mapping %.1e elements of buffer\n", (float)elements);
  // Mapping and unmapping buffers is another way to transfer memory to and from
  // the FPGA. This operation gives you a pointer that can be freely modified by
  // your host application
  void *ptr = clEnqueueMapBuffer(world.command_queue, // command queue
                                 buffer,              // buffer
                                 CL_TRUE,             // blocking call
                                 CL_MAP_WRITE,  // Indicates we will be writing
                                                //   to this location
                                 0,             // buffer offset
                                 size_in_bytes, // size in bytes
                                 0, nullptr, nullptr,
                                 &err); // error code
  check(err);

  printf("Modifying elements of buffer\n");
  // You can now assign values to the pointer just like a regular pointer.
  int *data_ptr = reinterpret_cast<int *>(ptr);
  for (int i = 0; i < elements; i++) {
    data_ptr[i] = 33;
  }

  printf("Unmapping elements of buffer\n");
  // The buffer must be unmapped before it can be used in other operations
  clEnqueueUnmapMemObject(world.command_queue, // command queue
                          buffer,
                          ptr, // pointer returned by Map call
                          0, nullptr, nullptr);
  verify(world, buffer, 33);

  printf("Using host pointer\n");
  // You can also instruct OpenCL to use the host pointer using the
  // CL_MEM_USE_HOST_PTR flag. This type of allocation can be useful
  // when the host and the FPGA share the same memory space (e.g. ZYNQ)
  //
  // NOTE: The OpenCL implementation may copy these values into a buffer
  // allocated on the FPGA.
  cl_mem buffer2 = clCreateBuffer(world.context, CL_MEM_USE_HOST_PTR,
                                  size_in_bytes, host_memory2.data(), &err);
  ptr = clEnqueueMapBuffer(world.command_queue, buffer2, CL_TRUE, CL_MAP_READ,
                           0, size_in_bytes, 0, nullptr, nullptr, nullptr);
  clEnqueueUnmapMemObject(world.command_queue, buffer2, ptr, 0, nullptr,
                          nullptr);
  verify(world, buffer2, 15);

  check(clReleaseMemObject(during_allocation));
  check(clReleaseMemObject(buffer));
  check(clReleaseMemObject(buffer2));

  check(clReleaseEvent(blocking_call_event));
  check(clReleaseEvent(async_event));
  check(clReleaseEvent(read_event));
  xcl_release_world(world);

  printf("TEST PASSED\n");

  return EXIT_SUCCESS;
}

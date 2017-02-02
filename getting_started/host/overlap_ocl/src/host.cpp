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

/*
  Overlap Host Code

  There are many applications where all of the data cannot reside in an FPGA.
  For example, the data is too big to fit in an FPGA or the data is being
  streamed from a sensor or the network. In these situations data must be
  transferred to the host memory to the FPGA before the computation can be
  performed.

  Because PCIe is an full-duplex interconnect, you can transfer data to and from
  the FPGA simultaneously. Xilinx FPGAs can also perform computations during
  these data transfers. Performing all three of these operations at the same
  time allows you to keep the FPGA busy and take full advantage of all of the
  hardware on your system.

  In this example, we will demonstrate how to perform this using an out of order
  command queue.

  +---------+---------+---------+----------+---------+---------+---------
  | WriteA1 | WriteB1 | WriteA2 | Write B2 | WriteA1 | WriteB1 |   Wri...
  +---------+---------+---------+----------+---------+---------+---------
                      |       Compute1     |     Compute2      |  Compu...
                      +--------------------+-------------------+--------+
                                           | ReadC1 |          | ReadC2 |
                                           +--------+          +--------+

  Many OpenCL commands are asynchronous. This means that whenever you call an
  OpenCL function, the function will return before the operation has completed.
  Asynchronous nature of OpenCL allows you to simultaneously perform tasks on
  the host CPU as well as the FPGA.

  Memory transfer operations are asynchronous when the blocking_read,
  blocking_write parameters are set to CL_FALSE. These operations are behaving
  on host memory so it is important to make sure that the command has completed
  before that memory is used.

  You can make sure an operation has completed by querying events returned by
  these commands. Events are OpenCL objects that track the status of operations.
  Event objects are created by kernel execution commands, read, write, map, copy
  commands on memory objects or user events created using clCreateUserEvent.

  Events can be used to synchronize operations between the host thread and the
  device or between two operations in the same context. You can also use events
  to time a particular operation if the command queue was created using the
  CL_QUEUE_PROFILING_ENABLE flag.

  Most enqueuing commands return events by accepting a cl_event pointer as their
  last argument of the call. These events can be queried using the
  clGetEventInfo function to get the status of a particular operation.

  Many functions also accept event lists that can be used to enforce ordering in
  an OpenCL context. These events lists are especially important in the context
  of out of order command queues as they are the only way specify dependency.
  Normal in-order command queues do not need this because dependency is enforced
  in the order the operation was enqueued. See the concurrent execution example
  for additional details on how create an use these types of command queues.
 */

#include "CL/cl.h"
#include "oclHelper.h"
#include "xcl.h"

#include <algorithm>
#include <array>
#include <chrono>
#include <cstdio>
#include <random>
#include <vector>

using std::array;
using std::chrono::duration;
using std::chrono::nanoseconds;
using std::chrono::seconds;
using std::default_random_engine;
using std::generate;
using std::uniform_int_distribution;
using std::vector;

const int ARRAY_SIZE = 1 << 14;
static const char *error_message =
    "Error: Result mismatch:\n"
    "i = %d CPU result = %d Device result = %d\n";

// Wrap any OpenCL API calls that return error code(cl_int) with the below macro
// to quickly check for an error
#define OCL_CHECK(call)                                                        \
  do {                                                                         \
    cl_int err = call;                                                         \
    if (err != CL_SUCCESS) {                                                   \
      printf("Error calling " #call ", error: %s\n", oclErrorCode(err));       \
      exit(EXIT_FAILURE);                                                      \
    }                                                                          \
  } while (0);

int gen_random() {
  static default_random_engine e;
  static uniform_int_distribution<int> dist(0, 100);

  return dist(e);
}

// An event callback function that prints the operations performed by the OpenCL
// runtime.
void event_cb(cl_event event, cl_int cmd_status, void *data) {
  cl_command_type command;
  clGetEventInfo(event, CL_EVENT_COMMAND_TYPE, sizeof(cl_command_type),
                 &command, nullptr);
  cl_int status;
  clGetEventInfo(event, CL_EVENT_COMMAND_EXECUTION_STATUS, sizeof(cl_int),
                 &status, nullptr);
  const char *command_str;
  const char *status_str;
  switch (command) {
  case CL_COMMAND_READ_BUFFER:
    command_str = "buffer read";
    break;
  case CL_COMMAND_WRITE_BUFFER:
    command_str = "buffer write";
    break;
  case CL_COMMAND_NDRANGE_KERNEL:
    command_str = "kernel";
    break;
  case CL_COMMAND_MAP_BUFFER:
    command_str = "kernel";
    break;
  case CL_COMMAND_COPY_BUFFER:
    command_str = "kernel";
    break;
  case CL_COMMAND_MIGRATE_MEM_OBJECTS:
        command_str = "buffer migrate";
      break;
  default:
    command_str = "unknown";
  }
  switch (status) {
  case CL_QUEUED:
    status_str = "Queued";
    break;
  case CL_SUBMITTED:
    status_str = "Submitted";
    break;
  case CL_RUNNING:
    status_str = "Executing";
    break;
  case CL_COMPLETE:
    status_str = "Completed";
    break;
  }
  printf("[%s]: %s %s\n", reinterpret_cast<char *>(data), status_str,
         command_str);
  fflush(stdout);
}

// Sets the callback for a particular event
void set_callback(cl_event event, const char *queue_name) {
  OCL_CHECK(
      clSetEventCallback(event, CL_COMPLETE, event_cb, (void *)queue_name));
}

int main(int argc, char **argv) {
  cl_int err;

  xcl_world world = xcl_world_single();
  cl_program program = xcl_import_binary(world, "vector_addition");

  // We will break down our problem into multiple iterations. Each iteration
  // will perform computation on a subset of the entire data-set.
  size_t elements_per_iteration = 2048;
  size_t bytes_per_iteration = elements_per_iteration * sizeof(int);
  size_t num_iterations = ARRAY_SIZE / elements_per_iteration;

  // This example will use an out of order command queue. The default command
  // queue created by xcl_world_single is an inorder command queue. Here we will
  // release the original queue and replace it with an out of order queue.
  clReleaseCommandQueue(world.command_queue);
  world.command_queue =
      clCreateCommandQueue(world.context, world.device_id,
                           CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE, &err);

  // Allocate memory on the host and fill with random data.
  vector<int> A(ARRAY_SIZE);
  vector<int> B(ARRAY_SIZE);
  generate(begin(A), end(A), gen_random);
  generate(begin(B), end(B), gen_random);
  vector<int> device_result(ARRAY_SIZE);

  cl_kernel kernel = xcl_get_kernel(program, "vadd");

  // This pair of events will be used to track when a kernel is finished with
  // the input buffers. Once the kernel is finished processing the data, a new
  // set of elements will be written into the buffer.
  array<cl_event, 2> kernel_events;
  array<cl_event, 2> read_events;
  array<cl_event, 2> map_events;
  cl_mem buffer_a[2], buffer_b[2], buffer_c[2];
  size_t global = 1, local = 1;
  for (size_t iteration_idx = 0; iteration_idx < num_iterations; iteration_idx++) {
    int flag = iteration_idx % 2;

    if (iteration_idx >= 2) {
        clWaitForEvents(1, &map_events[flag]);
        OCL_CHECK(clReleaseMemObject(buffer_a[flag]));
        OCL_CHECK(clReleaseMemObject(buffer_b[flag]));
        OCL_CHECK(clReleaseMemObject(buffer_c[flag]));
        OCL_CHECK(clReleaseEvent(read_events[flag]));
        OCL_CHECK(clReleaseEvent(kernel_events[flag]));
    }

    buffer_a[flag] = clCreateBuffer(world.context,  
            CL_MEM_READ_ONLY | CL_MEM_USE_HOST_PTR,
           bytes_per_iteration, &A[iteration_idx * elements_per_iteration], NULL);
    buffer_b[flag] = clCreateBuffer(world.context,  
            CL_MEM_READ_ONLY | CL_MEM_USE_HOST_PTR,
           bytes_per_iteration, &B[iteration_idx * elements_per_iteration], NULL);
    buffer_c[flag] = clCreateBuffer(world.context,  
            CL_MEM_WRITE_ONLY | CL_MEM_USE_HOST_PTR,
           bytes_per_iteration, &device_result[iteration_idx * elements_per_iteration], NULL);
    array<cl_event, 2> write_events;
    printf("Enqueueing Migrate Mem Object (Host to Device) calls\n");
    // These calls are asynchronous with respect to the main thread because we
    // are passing the CL_FALSE as the third parameter. Because we are passing
    // the events from the previous kernel call into the wait list, it will wait
    // for the previous operations to complete before continuing
    OCL_CHECK(clEnqueueMigrateMemObjects(
        world.command_queue, 1, &buffer_a[iteration_idx % 2],
        0 /* flags, 0 means from host */,
        0, NULL, 
        &write_events[0]));
    set_callback(write_events[0], "ooo_queue");

    OCL_CHECK(clEnqueueMigrateMemObjects(
        world.command_queue, 1, &buffer_b[iteration_idx % 2],
        0 /* flags, 0 means from host */,
        0, NULL, 
        &write_events[1]));
    set_callback(write_events[1], "ooo_queue");

    xcl_set_kernel_arg(kernel, 0, sizeof(cl_mem), &buffer_c[iteration_idx % 2]);
    xcl_set_kernel_arg(kernel, 1, sizeof(cl_mem), &buffer_a[iteration_idx % 2]);
    xcl_set_kernel_arg(kernel, 2, sizeof(cl_mem), &buffer_b[iteration_idx % 2]);
    xcl_set_kernel_arg(kernel, 3, sizeof(int), &elements_per_iteration);

    printf("Enqueueing NDRange kernel.\n");
    // This event needs to wait for the write buffer operations to complete
    // before executing. We are sending the write_events into its wait list to
    // ensure that the order of operations is correct.
    OCL_CHECK(clEnqueueNDRangeKernel(world.command_queue, kernel, 1, nullptr,
                                     &global, &local, 2 , write_events.data(),
                                     &kernel_events[flag]));
    set_callback(kernel_events[flag], "ooo_queue");

    printf("Enqueueing Migrate Mem Object (Device to Host) calls\n");
    // This operation only needs to wait for the kernel call. This call will
    // potentially overlap the next kernel call as well as the next read
    // operations
    OCL_CHECK( clEnqueueMigrateMemObjects(world.command_queue, 1, &buffer_c[iteration_idx % 2], 
                CL_MIGRATE_MEM_OBJECT_HOST, 1, &kernel_events[flag], &read_events[flag]));

    set_callback(read_events[flag], "ooo_queue");
    clEnqueueMapBuffer(world.command_queue, buffer_c[flag], CL_FALSE, CL_MAP_READ, 0, 
            bytes_per_iteration, 1, &read_events[flag], &map_events[flag], 0);
    set_callback(map_events[flag], "ooo_queue");

    OCL_CHECK(clReleaseEvent(write_events[0]));
    OCL_CHECK(clReleaseEvent(write_events[1]));
  }
  // Wait for all of the OpenCL operations to complete
  printf("Waiting...\n");
  clFlush(world.command_queue);
  clFinish(world.command_queue);

  //Releasing mem objects and events
  for(int i = 0 ; i < 2 ; i++){
    OCL_CHECK(clWaitForEvents(1, &map_events[i]));
    OCL_CHECK(clReleaseMemObject(buffer_a[i]));
    OCL_CHECK(clReleaseMemObject(buffer_b[i]));
    OCL_CHECK(clReleaseMemObject(buffer_c[i]));
    OCL_CHECK(clReleaseEvent(read_events[i]));
    OCL_CHECK(clReleaseEvent(kernel_events[i]));
  }

  int match = 0;
  // verify the results
  for (int i = 0; i < ARRAY_SIZE; i++) {
    int host_result = A[i] + B[i];
    if (device_result[i] != host_result) {
      printf(error_message, i, host_result, device_result[i]);
      match = 1;
      // break;
    }
  }

  OCL_CHECK(clReleaseKernel(kernel));
  OCL_CHECK(clReleaseProgram(program));
  xcl_release_world(world);

  if (match) {
    printf("TEST FAILED.\n");
    return EXIT_FAILURE;
  }

  printf("TEST PASSED.\n");
  return EXIT_SUCCESS;
}

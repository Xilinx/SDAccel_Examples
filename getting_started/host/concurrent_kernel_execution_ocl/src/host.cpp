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
 Out of order kernel execution

 Command queues are an OpenCL construct that manages the execution of memory
 transfers and kernel execution. Tasks are inserted into the queue using
 clEnqueue* operations. The device executes these operations in the order they
 are inserted into the queue.

 One of the many advantages of an FPGA is that all kernels are implemented in
 dedicated hardware. These regions can execute two different tasks in parallel
 without effecting the performance or resources of the other operations.

            +------------------------------+
            |           Xilinx FPGA        |
            |  +----------+  +----------+  |
            |  |          |  |          |  |
            |  | kernel 1 |  | kernel 2 |  |
            |  |          |  |          |  |
            |  |          |  |          |  |
            |  +----------+  +----------+  |
            |       ↑             ↑        |
            +-------|-------------|--------+
                    |             |
                 Task 1        Task 2

 An application can take advantage of this feature of the FPGA by creating
 multiple command queues. Independent tasks can be scheduled into different
 command queues which can be executed on the FPGA as the modules become
 available.

 An application can also create out of order command queues to execute tasks in
 parallel. Tasks queued on an out of order command queue can be executed in any
 order by the OpenCL implementation. Out of order queues are created by passing
 the CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE to the clCreateCommandQueue
 function. These types of queues executes tasks as resources become available at
 runtime.

 Events objects can be used to synchronize command queues or tasks in an out of
 order command queue. See the events example for additional details regarding
 the proper use of events in OpenCL.

 This example will demonstrate how to execute multiple kernels in parallel on an
 FPGA. We will create three kernels that will perform scaling, matrix addition
 and matrix multiplication. The Matrix multiplication is independent of the
 scaling and addition operation so we will execute independently of the other
 kernels.

 The following operations will be performed:

  A = 2 * A (scale A by 2)
  C = A + B (Add A and B)
  F = D * E (Matrix multiplication on D and E)

 NOTE: Normally calculating the C matrix can be performed by one kernel. We are
 splitting this task in the examples to illustrate the execution concepts.

  - Task flow (1): Matrix Scaling <------ Matrix Addition
  - Task flow (2): Matrix Multiplication
 */

#include "CL/cl.h"
#include "oclHelper.h"
#include "xcl.h"

#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>

using std::vector;
using std::find;

const int MAT_DIM0 = 16;
const int MAT_DIM1 = 16;
size_t offset[1] = {0};
size_t global[1] = {1};
size_t local[1] = {1};

// Wrap any OpenCL API calls that return error code(cl_int) with the below macro
// to quickly check for an error
#define OCL_CHECK(call)                                                        \
  do {                                                                         \
    cl_int err = call;                                                         \
    if (err != CL_SUCCESS) {                                                   \
      printf(__FILE__ ":%d: [ERROR] " #call " returned %s\n", __LINE__,        \
             oclErrorCode(err));                                               \
      exit(EXIT_FAILURE);                                                      \
    }                                                                          \
  } while (0);

// Checks OpenCL error codes
void check(cl_int err_code) {
  if (err_code != CL_SUCCESS) {
    printf("ERROR: %d\n", err_code);
    exit(EXIT_FAILURE);
  }
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
  printf("%s %s %s\n", status_str, reinterpret_cast<char *>(data), command_str);
  fflush(stdout);
}

// Sets the callback for a particular event
void set_callback(cl_event event, const char *queue_name) {
  OCL_CHECK(
      clSetEventCallback(event, CL_COMPLETE, event_cb, (void *)queue_name));
}

// Verify the result of the out put buffers
void verify_results(const vector<int> &C, const vector<int> &F) {
  if (find(begin(C), end(C), 0) != end(C)) {
    printf("\nC = 2*A + B computation FAILED\n");
    exit(EXIT_FAILURE);
  }
  if (find(begin(F), end(F), 0) != end(F)) {
    printf("\nF = matmul(D, E) computation FAILED\n");
    exit(EXIT_FAILURE);
  }
}

void multiple_command_queues(xcl_world &world, cl_kernel kernel_mscale,
                             cl_kernel kernel_madd, cl_kernel kernel_mmult,
                             cl_mem buffer_a, cl_mem buffer_b, cl_mem buffer_c,
                             cl_mem buffer_d, cl_mem buffer_e, cl_mem buffer_f,
                             size_t size_in_bytes) {
  cl_int err;
  cl_command_queue ordered_queue1 = clCreateCommandQueue(
      world.context, world.device_id, CL_QUEUE_PROFILING_ENABLE, &err);
  check(err);
  cl_command_queue ordered_queue2 = clCreateCommandQueue(
      world.context, world.device_id, CL_QUEUE_PROFILING_ENABLE, &err);
  check(err);

  // copy the input arrays to input memory allocated on the accelerator
  // devices
  const int matrix_scale_factor = 2;
  xcl_set_kernel_arg(kernel_mscale, 0, sizeof(cl_mem), &buffer_a);
  xcl_set_kernel_arg(kernel_mscale, 1, sizeof(cl_int), &matrix_scale_factor);
  xcl_set_kernel_arg(kernel_mscale, 2, sizeof(cl_int), &MAT_DIM0);
  xcl_set_kernel_arg(kernel_mscale, 3, sizeof(cl_int), &MAT_DIM1);

  vector<cl_event> kernel_events(3);

  printf("[Ordered Queue 1]: Enqueueing scale kernel\n");
  OCL_CHECK(clEnqueueNDRangeKernel(ordered_queue1, kernel_mscale, 1, offset,
                                   global, local, 0, nullptr,
                                   &kernel_events[0]));
  set_callback(kernel_events[0], "scale");

  // set OpenCL kernel parameters to add scaled matrix A and matrix B
  xcl_set_kernel_arg(kernel_madd, 0, sizeof(cl_mem), &buffer_c);
  xcl_set_kernel_arg(kernel_madd, 1, sizeof(cl_mem), &buffer_a);
  xcl_set_kernel_arg(kernel_madd, 2, sizeof(cl_mem), &buffer_b);
  xcl_set_kernel_arg(kernel_madd, 3, sizeof(cl_int), &MAT_DIM0);
  xcl_set_kernel_arg(kernel_madd, 4, sizeof(cl_int), &MAT_DIM1);

  printf("[Ordered Queue 1]: Enqueueing addition kernel\n");
  OCL_CHECK(clEnqueueNDRangeKernel(ordered_queue1, kernel_madd, 1, offset,
                                   global, local, 0, nullptr,
                                   &kernel_events[1]));
  set_callback(kernel_events[1], "addition");

  // set OpenCL kernel parameters to multiply matrix D and E */
  xcl_set_kernel_arg(kernel_mmult, 0, sizeof(cl_mem), &buffer_f);
  xcl_set_kernel_arg(kernel_mmult, 1, sizeof(cl_mem), &buffer_d);
  xcl_set_kernel_arg(kernel_mmult, 2, sizeof(cl_mem), &buffer_e);
  xcl_set_kernel_arg(kernel_mmult, 3, sizeof(cl_int), &MAT_DIM0);
  xcl_set_kernel_arg(kernel_mmult, 4, sizeof(cl_int), &MAT_DIM1);

  printf("[Ordered Queue 2]: Enqueueing matrix multiplication kernel\n");
  OCL_CHECK(clEnqueueNDRangeKernel(ordered_queue2, kernel_mmult, 1, offset,
                                   global, local, 0, nullptr,
                                   &kernel_events[2]));
  set_callback(kernel_events[2], "matrix multiplication");

  const size_t array_size = MAT_DIM0 * MAT_DIM1;
  vector<int> A(array_size);
  vector<int> C(array_size);
  vector<int> F(array_size);

  vector<cl_event> transfer_events(3);
  printf("[Ordered Queue 1]: Enqueueing Read Buffer A\n");
  OCL_CHECK(clEnqueueReadBuffer(ordered_queue1, buffer_a, CL_FALSE, 0,
                                size_in_bytes, A.data(), 0, nullptr,
                                &transfer_events[0]));
  set_callback(transfer_events[0], "A");
  printf("[Ordered Queue 1]: Enqueueing Read Buffer C\n");
  OCL_CHECK(clEnqueueReadBuffer(ordered_queue1, buffer_c, CL_FALSE, 0,
                                size_in_bytes, C.data(), 0, nullptr,
                                &transfer_events[1]));
  set_callback(transfer_events[1], "C");

  printf("[Ordered Queue 2]: Enqueueing Read Buffer F\n");
  OCL_CHECK(clEnqueueReadBuffer(ordered_queue2, buffer_f, CL_FALSE, 0,
                                size_in_bytes, F.data(), 0, nullptr,
                                &transfer_events[2]));
  set_callback(transfer_events[2], "F");

  printf("[Ordered Queue 1]: Waiting\n");
  printf("[Ordered Queue 2]: Waiting\n");
  clWaitForEvents(3, transfer_events.data());
  for (auto event : kernel_events)
    clReleaseEvent(event);
  for (auto event : transfer_events)
    clReleaseEvent(event);
  OCL_CHECK(clReleaseCommandQueue(ordered_queue1));
  OCL_CHECK(clReleaseCommandQueue(ordered_queue2));
  verify_results(C, F);
}

void out_of_order_queue(xcl_world &world, cl_kernel kernel_mscale,
                        cl_kernel kernel_madd, cl_kernel kernel_mmult,
                        cl_mem buffer_a, cl_mem buffer_b, cl_mem buffer_c,
                        cl_mem buffer_d, cl_mem buffer_e, cl_mem buffer_f,
                        size_t size_in_bytes) {
  cl_int err;
  vector<cl_event> ooo_events(6);

  // We are creating an out of order queue here.
  cl_command_queue ooo_queue = clCreateCommandQueue(
      world.context, world.device_id,
      CL_QUEUE_PROFILING_ENABLE | CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE, &err);
  check(err);

  // Clear values in the result buffers
  {
    int zero = 0;
    int one = 1;
    vector<cl_event> fill_events(3);
    clEnqueueFillBuffer(ooo_queue, buffer_a, &one, sizeof(int), 0,
                        size_in_bytes, 0, nullptr, &fill_events[0]);
    clEnqueueFillBuffer(ooo_queue, buffer_c, &zero, sizeof(int), 0,
                        size_in_bytes, 0, nullptr, &fill_events[1]);
    clEnqueueFillBuffer(ooo_queue, buffer_f, &zero, sizeof(int), 0,
                        size_in_bytes, 0, nullptr, &fill_events[2]);
    clWaitForEvents(3, fill_events.data());
    for (auto event : fill_events)
      clReleaseEvent(event);
  }

  // copy the input arrays to input memory allocated on the accelerator
  // devices
  const int matrix_scale_factor = 2;
  xcl_set_kernel_arg(kernel_mscale, 0, sizeof(cl_mem), &buffer_a);
  xcl_set_kernel_arg(kernel_mscale, 1, sizeof(cl_int), &matrix_scale_factor);
  xcl_set_kernel_arg(kernel_mscale, 2, sizeof(cl_int), &MAT_DIM0);
  xcl_set_kernel_arg(kernel_mscale, 3, sizeof(cl_int), &MAT_DIM1);

  printf("[OOO Queue]: Enqueueing scale kernel\n");
  OCL_CHECK(clEnqueueNDRangeKernel(ooo_queue, kernel_mscale, 1, offset, global,
                                   local, 0, nullptr, &ooo_events[0]));
  set_callback(ooo_events[0], "scale");

  // set OpenCL kernel parameters to add scaled matrix A and matrix B
  xcl_set_kernel_arg(kernel_madd, 0, sizeof(cl_mem), &buffer_c);
  xcl_set_kernel_arg(kernel_madd, 1, sizeof(cl_mem), &buffer_a);
  xcl_set_kernel_arg(kernel_madd, 2, sizeof(cl_mem), &buffer_b);
  xcl_set_kernel_arg(kernel_madd, 3, sizeof(cl_int), &MAT_DIM0);
  xcl_set_kernel_arg(kernel_madd, 4, sizeof(cl_int), &MAT_DIM1);

  // This is an out of order queue, events can be executed in any order. Since
  // this call depends on the results of the previous call we must pass the
  // event object from the previous call to this kernel's event wait list.
  printf("[OOO Queue]: Enqueueing addition kernel (Depends on scale)\n");
  OCL_CHECK(clEnqueueNDRangeKernel(ooo_queue, kernel_madd, 1, offset, global,
                                   local, 1,
                                   &ooo_events[0], // Event from previous call
                                   &ooo_events[1]));
  set_callback(ooo_events[1], "addition");

  // set OpenCL kernel parameters to multiply matrix D and E */
  xcl_set_kernel_arg(kernel_mmult, 0, sizeof(cl_mem), &buffer_f);
  xcl_set_kernel_arg(kernel_mmult, 1, sizeof(cl_mem), &buffer_d);
  xcl_set_kernel_arg(kernel_mmult, 2, sizeof(cl_mem), &buffer_e);
  xcl_set_kernel_arg(kernel_mmult, 3, sizeof(cl_int), &MAT_DIM0);
  xcl_set_kernel_arg(kernel_mmult, 4, sizeof(cl_int), &MAT_DIM1);

  // This call does not depend on previous calls so we are passing nullptr
  // into the event wait list. The runtime should schedule this kernel in
  // parallel to the previous calls.
  printf("[OOO Queue]: Enqueueing matrix multiplication kernel\n");
  OCL_CHECK(clEnqueueNDRangeKernel(ooo_queue, kernel_mmult, 1, offset, global,
                                   local, 0,
                                   nullptr, // Does not depend on previous call
                                   &ooo_events[2]));
  set_callback(ooo_events[2], "matrix multiplication");

  const size_t array_size = MAT_DIM0 * MAT_DIM1;
  vector<int> A(array_size);
  vector<int> C(array_size);
  vector<int> F(array_size);

  // Depends on the addition kernel
  printf("[OOO Queue]: Enqueueing Read Buffer A (depends on addition)\n");
  OCL_CHECK(clEnqueueReadBuffer(ooo_queue, buffer_a, CL_FALSE, 0, size_in_bytes,
                                A.data(), 1, &ooo_events[1], &ooo_events[3]));
  set_callback(ooo_events[3], "A");
  printf("[OOO Queue]: Enqueueing Read Buffer C (depends on addition)\n");
  OCL_CHECK(clEnqueueReadBuffer(ooo_queue, buffer_c, CL_FALSE, 0, size_in_bytes,
                                C.data(), 1, &ooo_events[1], &ooo_events[4]));
  set_callback(ooo_events[4], "C");

  // Depends on the matrix multiplication kernel
  printf("[OOO Queue]: Enqueueing Read Buffer F (depends on matrix "
         "multiplication)\n");
  OCL_CHECK(clEnqueueReadBuffer(ooo_queue, buffer_f, CL_FALSE, 0, size_in_bytes,
                                F.data(), 1, &ooo_events[2], &ooo_events[5]));
  set_callback(ooo_events[5], "F");

  // Block until all operations have completed
  clFlush(ooo_queue);
  clFinish(ooo_queue);
  verify_results(C, F);

  for (auto event : ooo_events)
    clReleaseEvent(event);

  OCL_CHECK(clReleaseCommandQueue(ooo_queue));
}

int main(int argc, char **argv) {

  const size_t array_size = MAT_DIM0 * MAT_DIM1;
  const size_t size_in_bytes = array_size * sizeof(int);
  cl_int err;

  // allocate memory on host for input and output matrices
  vector<int> A(array_size, 1);
  vector<int> B(array_size, 1);
  vector<int> D(array_size, 1);
  vector<int> E(array_size, 1);

  cl_kernel kernel_madd = 0;
  cl_kernel kernel_mscale = 0;
  cl_kernel kernel_mmult = 0;

  // Called to set environment variables
  xcl_world world = xcl_world_single();
  cl_program program = xcl_import_binary(world, "matrix_ops");

  kernel_madd = xcl_get_kernel(program, "madd");
  kernel_mscale = xcl_get_kernel(program, "mscale");
  kernel_mmult = xcl_get_kernel(program, "mmult");

  cl_mem buffer_a = xcl_malloc(world, CL_MEM_READ_WRITE, size_in_bytes);
  cl_mem buffer_b = xcl_malloc(world, CL_MEM_READ_ONLY, size_in_bytes);
  cl_mem buffer_c = xcl_malloc(world, CL_MEM_WRITE_ONLY, size_in_bytes);
  cl_mem buffer_d = xcl_malloc(world, CL_MEM_READ_ONLY, size_in_bytes);
  cl_mem buffer_e = xcl_malloc(world, CL_MEM_READ_ONLY, size_in_bytes);
  cl_mem buffer_f = xcl_malloc(world, CL_MEM_WRITE_ONLY, size_in_bytes);

  xcl_memcpy_to_device(world, buffer_a, A.data(), size_in_bytes);
  xcl_memcpy_to_device(world, buffer_b, B.data(), size_in_bytes);
  xcl_memcpy_to_device(world, buffer_d, D.data(), size_in_bytes);
  xcl_memcpy_to_device(world, buffer_e, E.data(), size_in_bytes);

  // Use multiple command queues to execute the kernels
  multiple_command_queues(world, kernel_mscale, kernel_madd, kernel_mmult,
                          buffer_a, buffer_b, buffer_c, buffer_d, buffer_e,
                          buffer_f, size_in_bytes);

  // Use out of order command queue to execute the kernels
  out_of_order_queue(world, kernel_mscale, kernel_madd, kernel_mmult, buffer_a,
                     buffer_b, buffer_c, buffer_d, buffer_e, buffer_f,
                     size_in_bytes);

  // Release OpenCL objects
  OCL_CHECK(clReleaseMemObject(buffer_a));
  OCL_CHECK(clReleaseMemObject(buffer_b));
  OCL_CHECK(clReleaseMemObject(buffer_c));
  OCL_CHECK(clReleaseMemObject(buffer_d));
  OCL_CHECK(clReleaseMemObject(buffer_e));
  OCL_CHECK(clReleaseMemObject(buffer_f));

  OCL_CHECK(clReleaseKernel(kernel_mscale));
  OCL_CHECK(clReleaseKernel(kernel_madd));
  OCL_CHECK(clReleaseKernel(kernel_mmult));
  OCL_CHECK(clReleaseProgram(program));
  xcl_release_world(world);

  printf(
      "View the timeline trace in SDx for a visual overview of the\n"
      "execution of this example. Refer to the \"Timeline Trace\" section of\n"
      "the SDx Development Environment Methodology Guide for additional\n"
      "details.\n");

  printf("TEST PASSED\n");
  return EXIT_SUCCESS;
}

/**********
Copyright (c) 2017, Xilinx, Inc.
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
  Stream_access Host Code

  There are many applications where all of the data cannot reside in an FPGA.
  For example, the data is too big to fit in an FPGA or the data is being
  streamed from a sensor or the network. In these situations data must be
  transferred as chunks from the host memory to FPGA before the computation can be
  performed on FPGA and vice-versa to copy back the result.

  Because PCIe is an full-duplex interconnect, you can transfer data to and from
  the FPGA simultaneously. Xilinx FPGAs can also perform computations during
  these data transfers. Performing all three of these operations at the same
  time allows you to keep the FPGA busy and take full advantage of all of the
  hardware on your system.

  In this example, we will demonstrate how to perform/handle this using an out of order
  command queue and how to process this streaming data in chunks.

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

  Events can be used to synchronize operations between the host thread and the
  device or between two operations in the same context. Events are OpenCL objects
  that track the status of operations. 
  Most enqueuing commands return events by accepting a cl_event pointer as their
  last argument of the call. Event objects are created by kernel execution commands
  read, write and map commands on memory objects. 

  Many functions also accept event lists that can be used to enforce ordering in
  an OpenCL context. These events lists are especially important in the context
  of out of order command queues as they are the only way specify dependency.
  Normal in-order command queues do not need this because dependency is enforced
  in the order the operation was enqueued. See the concurrent execution example
  for additional details on how create an use these types of command queues.
 */

#include "CL/cl.h"
#include "xcl.h"

#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include <array>
#include <vector>
#include<cstdio>

#define CHUNK_SIZE 1024 

using std::array;
using std::vector;

//Allocator template to align buffer to Page boundary for better data transfer
template <typename T>
struct aligned_allocator
{
  using value_type = T;
  T* allocate(std::size_t num)
  {
    void* ptr = nullptr;
    if (posix_memalign(&ptr,4096,num*sizeof(T)))
      throw std::bad_alloc();
    return reinterpret_cast<T*>(ptr);
  }
  void deallocate(T* p, std::size_t num)
  {
    free(p);
  }
};

// Wrap any OpenCL API calls that return error code(cl_int) with the below macros
// to quickly check for an error
#define OCL_CHECK(call)                                                        \
  do {                                                                         \
    cl_int err = call;                                                         \
    if (err != CL_SUCCESS) {                                                   \
      printf("Error calling " #call ", error code is: %d\n", err);       \
      exit(EXIT_FAILURE);                                                      \
    }                                                                          \
  } while (0);

//Compare the CPU and FPGA results
bool verify( int *in1,
             int *in2,
             int *out
)
{
    bool match = true;
    //verify the results
    for (int i = 0; i < CHUNK_SIZE; i++) {
        int host_result = in1[i] + in2[i];
        if (out[i] != host_result) {
            std::cout << "Error: Result mismatch" << std::endl;
            std::cout << "i = " << i << "In1 = " << in1[i] << "In2 = "
                        << in2[i] << " CPU result = " << host_result 
                        << " Hardware result = " << out[i] << std::endl;
            match = false;
            break;
        }
    }
    return match;
}

int main(int argc, char **argv) {
    if (argc != 3){
        std::cout << "Usage: " << argv[0] << " <Input File1>" << " <Input File2>" << std::endl;
        return EXIT_FAILURE ;
    }

    std::string in1Filename = argv[1];
    std::string in2Filename = argv[2];

    std::string in1_data, in2_data;

    std::ifstream in1_stream(in1Filename);
    std::ifstream in2_stream(in2Filename);
    std::ofstream out_stream("output_vector.txt");

    cl_int err;

    xcl_world world = xcl_world_single();
    cl_program program = xcl_import_binary(world, "vector_addition");

    // We will break down our problem into multiple iterations. Each iteration
    // will perform computation on a subset of the entire data-set. Each iteration
    // is based on the outermost while loop.
    size_t elements_per_iteration = CHUNK_SIZE;
    size_t bytes_per_iteration = elements_per_iteration * sizeof(int);

    bool match = true;

    // This example will use an out of order command queue. The default command
    // queue created by xcl_world_single is an inorder command queue. Here we will
    // release the original queue and replace it with an out of order queue.
    clReleaseCommandQueue(world.command_queue);
    world.command_queue =
        clCreateCommandQueue(world.context, world.device_id,
                                CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE, &err);

    cl_kernel kernel = xcl_get_kernel(program, "vec_add");

    // Allocate memory on the host 
    array<vector<int,aligned_allocator<int>>, 2> A;
    array<vector<int,aligned_allocator<int>>, 2> B;
    array<vector<int,aligned_allocator<int>>, 2> device_result;

    // Create buffers with the vector size data
    cl_mem buffer_a[2], buffer_b[2], buffer_c[2];
    for (int i = 0 ; i < 2 ; i++){
        A[i].resize(bytes_per_iteration);
        B[i].resize(bytes_per_iteration);
        device_result[i].resize(bytes_per_iteration);
        buffer_a[i] = clCreateBuffer(world.context, CL_MEM_READ_ONLY | CL_MEM_USE_HOST_PTR,
                        bytes_per_iteration, A[i].data(), NULL);
        buffer_b[i] = clCreateBuffer(world.context, CL_MEM_READ_ONLY | CL_MEM_USE_HOST_PTR,
                        bytes_per_iteration, B[i].data(), NULL);
        buffer_c[i] = clCreateBuffer(world.context, CL_MEM_WRITE_ONLY | CL_MEM_USE_HOST_PTR,
                    bytes_per_iteration, device_result[i].data(), NULL);
    }

    int in1_buffer_counter, in2_buffer_counter, flag;

    // This pair of events will be used to track when a kernel is finished with
    // the input buffers. Once the kernel is finished processing the data, a new
    // set of elements will be written into the buffer.
    array<cl_event, 2> kernel_events;
    array<cl_event, 2> read_events;
    array<cl_event, 2> map_events;

    // Four write events are created because when the next write (WriteA2 & WriteB2) happens the 
    // current write events (WriteA1 & WriteB1) may not be released. So to avoid the overwrite
    // in the buffers, four write events are created.
    array<array<cl_event, 2> , 2> write_events;

    for(int num_iters = 0 ; !in1_stream.eof() && !in2_stream.eof(); num_iters++){
        flag = num_iters % 2;
        in1_buffer_counter = in2_buffer_counter = 0;

        // Release the events once the result is available
        if(num_iters >= 2){
            clWaitForEvents(1, &map_events[flag]);
            OCL_CHECK(clReleaseEvent(write_events[flag][0]));
            OCL_CHECK(clReleaseEvent(write_events[flag][1]));
            OCL_CHECK(clReleaseEvent(kernel_events[flag]));
            OCL_CHECK(clReleaseEvent(read_events[flag]));
            // Verify results and out stream the data to a file
            match = verify(A[flag].data(), B[flag].data(), device_result[flag].data());
            if(match){
                for(size_t i = 0; i < elements_per_iteration; i++){
                    out_stream << std::to_string(device_result[flag][i]);
                    out_stream << "\n";
                }
            }
        }
        // Read a KB of data from input stream and store it in a vector
        while(in1_buffer_counter < CHUNK_SIZE){
            if(getline(in1_stream, in1_data)){
                std::stringstream(in1_data) >> A[flag][in1_buffer_counter];
                in1_buffer_counter++;
            }
            else{
                break;
            }
        }
        // Read a KB of data from input stream and store it in a vector
        while(in2_buffer_counter < CHUNK_SIZE){
            if(getline(in2_stream, in2_data)){
                std::stringstream(in2_data) >> B[flag][in2_buffer_counter];
                in2_buffer_counter++;
            }
            else{
                break;
            }
        }

        // Assuming both the file sizes are same
        // To take care of the last iteration elements (which can be less than a KB)
        if(in1_buffer_counter < CHUNK_SIZE){
            elements_per_iteration = in1_buffer_counter;
        }

        size_t global = 1, local = 1;
       
        std::cout <<"Enqueueing Migrate Mem Object (Host to Device) calls" << std::endl;
        // These calls are asynchronous with respect to the main thread
        OCL_CHECK(clEnqueueMigrateMemObjects(
                world.command_queue, 1, &buffer_a[flag],
                0 /* flags, 0 means from host */,
                0, NULL, 
                &write_events[flag][0]));

        OCL_CHECK(clEnqueueMigrateMemObjects(
                world.command_queue, 1, &buffer_b[flag],
                0 /* flags, 0 means from host */,
                0, NULL, 
                &write_events[flag][1]));

        xcl_set_kernel_arg(kernel, 0, sizeof(cl_mem), &buffer_c[flag]);
        xcl_set_kernel_arg(kernel, 1, sizeof(cl_mem), &buffer_a[flag]);
        xcl_set_kernel_arg(kernel, 2, sizeof(cl_mem), &buffer_b[flag]);
        xcl_set_kernel_arg(kernel, 3, sizeof(int), &elements_per_iteration);

        std::cout << "Enqueueing NDRange kernel." << std::endl;
        // This event needs to wait for the write buffer operations to complete
        // before executing. We are sending the write_events into its wait list to
        // ensure that the order of operations is correct.
        OCL_CHECK(clEnqueueNDRangeKernel(world.command_queue, kernel, 1, nullptr,
                    &global, &local, 2 , write_events[flag].data(),
                    &kernel_events[flag]));

        std::cout << "Enqueueing Migrate Mem Object (Device to Host) calls" << std::endl;
        // This operation only needs to wait for the kernel call. This call will
        // potentially overlap the next kernel call as well as the next read
        // operations
        OCL_CHECK(clEnqueueMigrateMemObjects(world.command_queue, 1, &buffer_c[flag], 
                    CL_MIGRATE_MEM_OBJECT_HOST, 1, &kernel_events[flag], &read_events[flag]));

        clEnqueueMapBuffer(world.command_queue, buffer_c[flag], CL_FALSE, CL_MAP_READ, 0, 
                    bytes_per_iteration, 1, &read_events[flag], &map_events[flag], 0);
    }
    // Wait for all of the OpenCL operations to complete
    std::cout << "Waiting..." << std::endl;
    clFlush(world.command_queue);
    clFinish(world.command_queue);

    size_t elements_last_iteration = elements_per_iteration;
    // Releasing mem objects and events
    for(int i = 0 ; i < 2 ; i++){
        OCL_CHECK(clWaitForEvents(1, &map_events[i]));
        OCL_CHECK(clReleaseEvent(read_events[i]));
        OCL_CHECK(clReleaseEvent(kernel_events[i]));
        OCL_CHECK(clReleaseMemObject(buffer_a[flag]));
        OCL_CHECK(clReleaseMemObject(buffer_b[flag]));
        OCL_CHECK(clReleaseMemObject(buffer_c[flag]));

        flag = !flag;
        // Need to verify and write the last two buffer data
        // For first buffer it will be chunk size but for the 
        // second buffer it depends on the last iteration
        // can be chunk size or less than that
        if(i == 0){
            elements_per_iteration = CHUNK_SIZE;
        }
        else{
            elements_per_iteration = elements_last_iteration;
        }
        // Verify results and out stream the data to file
        match = verify(A[flag].data(), B[flag].data(), device_result[flag].data());
        if(match){
            for(size_t j = 0; j < elements_per_iteration; j++){
                out_stream << std::to_string(device_result[flag][j]);
                out_stream << "\n";
            }
        }
    }
    in1_stream.close();
    in2_stream.close();
    out_stream.close();

    OCL_CHECK(clReleaseKernel(kernel));
    OCL_CHECK(clReleaseProgram(program));
    xcl_release_world(world);

    std::cout << "TEST " <<  ((match) ? "PASSED" : "FAILED") << std::endl;;
    return ((match) ? EXIT_SUCCESS :  EXIT_FAILURE);
}

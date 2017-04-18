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

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <assert.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <CL/opencl.h>

#include "xcl.h"

int main(int argc, char** argv) {

    xcl_world world = xcl_world_single();
    clReleaseCommandQueue(world.command_queue);

    int err;
    world.command_queue = clCreateCommandQueue(world.context, world.device_id,
                                               CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE | CL_QUEUE_PROFILING_ENABLE,
                                               &err);
    if (err != CL_SUCCESS) {
        printf("Error: Failed to create a command queue!\n");
        exit(EXIT_FAILURE);
    }

    cl_program program = xcl_import_binary(world, "krnl_host_global");
    cl_kernel krnl = xcl_get_kernel(program, "bandwidth");

    size_t globalbuffersize = 1024 * 1024 * 1024;  // 1 GB

    /* Reducing the data size for emulation mode */
    char *xcl_mode = getenv("XCL_EMULATION_MODE");
    if (xcl_mode != NULL){
        globalbuffersize = 1024 * 1024;  /* 1MB */
    }

    //--------------------------------------------------------------------------
    //Measure PCIe read bandwidth (clEnqueueMapBuffer)
    //--------------------------------------------------------------------------
    char* map_buffer0;
    char* map_buffer1;

    // Create buffers in the context
    cl_mem dev_buffer0 = xcl_malloc(world, CL_MEM_READ_WRITE, globalbuffersize);
    cl_mem dev_buffer1 = xcl_malloc(world, CL_MEM_READ_WRITE, globalbuffersize);

    // Copy test data into the buffers
    char* buffer0 = (char*) malloc(globalbuffersize);
    char* buffer1 = (char*) malloc(globalbuffersize);

    // Set all bits to an alternating pattern of 10 and 01
    memset(buffer0, 0xAA, globalbuffersize);
    memset(buffer1, 0x55, globalbuffersize);
    xcl_memcpy_to_device(world, dev_buffer0, buffer0, globalbuffersize);
    xcl_memcpy_to_device(world, dev_buffer1, buffer1, globalbuffersize);

    free(buffer0);
    free(buffer1);

    // Migrate buffers to device by running a kernel on the device
    xcl_set_kernel_arg(krnl, 0, sizeof(cl_mem), &dev_buffer0);
    xcl_set_kernel_arg(krnl, 1, sizeof(cl_mem), &dev_buffer1);
    xcl_run_kernel3d(world, krnl, 1, 1, 1);


    cl_event event0, event1;
    // Map buffer so it is visible on the host
    map_buffer0 = (char*) clEnqueueMapBuffer(world.command_queue,
                                             dev_buffer0,
                                             CL_FALSE,
                                             CL_MAP_READ | CL_MAP_WRITE,
                                             0,
                                             globalbuffersize,
                                             0,
                                             NULL,
                                             &event0,
                                             &err);
    if (err != CL_SUCCESS) {
        printf("Error: Failed to clEnqueueMapBuffer OpenCL buffer\n");
        printf("Error: Test failed\n");
        return EXIT_FAILURE;
    }
    clFinish(world.command_queue);

    unsigned long nsduration = xcl_get_event_duration(event0);
    double dnsduration = nsduration;
    double dsduration = dnsduration / (double) 1000000000.0;
    double dmbytes = (double) globalbuffersize / (((double)1024) * ((double)1024));
    double dmbpersec = (dmbytes/dsduration);

    printf("PCIe read only:%.1lf MB, duration %lf sec, bandwidth %lf MB/sec\n", dmbytes, dsduration, dmbpersec);

    //--------------------------------------------------------------------------
    //Measure PCIe write bandwidth (clEnqueueUnmapMemObject)
    //--------------------------------------------------------------------------

    err = clEnqueueUnmapMemObject(world.command_queue,
                                  dev_buffer0,
                                  map_buffer0,
                                  0,
                                  NULL,
                                  &event0);
    if (err != CL_SUCCESS) {
        printf("Error: Failed to clEnqueueUnmapMemObject OpenCL buffer\n");
        printf("Error: Test failed\n");
        return -1;
    }
    clFinish(world.command_queue);

    nsduration = xcl_get_event_duration(event0);
    dnsduration = nsduration;
    dsduration = dnsduration / (double) 1000000000.0;
    dmbytes = (double) globalbuffersize / (((double)1024) * ((double)1024));
    dmbpersec = (dmbytes/dsduration);

    printf("PCIe write only:%.1lf MB, duration %lf sec, bandwidth %lf MB/sec\n", dmbytes, dsduration, dmbpersec);

    //--------------------------------------------------------------------------
    //Measure concurrent PCIe write/read bandwidth (clEnqueueMapBuffer + clEnqueueUnmapMemObject)
    //--------------------------------------------------------------------------
    
    // Map buffer0 for PCIe write
    map_buffer0 = (char*) clEnqueueMapBuffer(world.command_queue,
                                             dev_buffer0,
                                             CL_FALSE,
                                             CL_MAP_READ | CL_MAP_WRITE,
                                             0,
                                             globalbuffersize,
                                             0,
                                             NULL,
                                             &event0,
                                             &err);
    if (err != CL_SUCCESS) {
        printf("Error: Failed to clEnqueueMapBuffer OpenCL buffer\n");
        printf("Error: Test failed\n");
        return -1;
    }
    clFinish(world.command_queue);

    //unmap buffer0 (PCIe write buffer0)
    err = clEnqueueUnmapMemObject(world.command_queue,
                                  dev_buffer0,
                                  map_buffer0,
                                  0,
                                  NULL,
                                  &event0);
    if (err != CL_SUCCESS) {
        printf("Error: Failed to clEnqueueUnmapMemObject OpenCL buffer\n");
        printf("Error: Test failed\n");
        return -1;
    }

    // map buffer1 (PCIe read buffer1) in parallel to unmap buffer0
    map_buffer1 = (char*) clEnqueueMapBuffer(world.command_queue,
                                             dev_buffer1,
                                             CL_FALSE,
                                             CL_MAP_READ | CL_MAP_WRITE,
                                             0,
                                             globalbuffersize,
                                             0,
                                             NULL,
                                             &event1,
                                             &err);
    if (err != CL_SUCCESS) {
        printf("Error: Failed to clEnqueueMapBuffer OpenCL buffer\n");
        printf("Error: Test failed\n");
        return -1;
    }
    clFinish(world.command_queue);

    unsigned long nstimequeued, nstimequeued0, nstimequeued1, nstimeend, nstimeend0, nstimeend1;

    //map buffer1 and unmap buffer0 are completed.
    //get profiling info for unmap buffer0
    err = clGetEventProfilingInfo(event0, CL_PROFILING_COMMAND_START, sizeof(uint64_t),((void *)(&nstimequeued0)),NULL);
    if (err != CL_SUCCESS) {
        printf("Error: Failed to clGetEventProfilingInfo\n");
        printf("Error: Test failed\n");
        return -1;
    }

    err = clGetEventProfilingInfo(event0, CL_PROFILING_COMMAND_END,    sizeof(uint64_t),((void *)(&nstimeend0)),   NULL);
    if (err != CL_SUCCESS) {
        printf("Error: Failed to clGetEventProfilingInfo\n");
        printf("Error: Test failed\n");
        return -1;
    }

    // Get profiling info for map buffer1
    err = clGetEventProfilingInfo(event1, CL_PROFILING_COMMAND_START, sizeof(uint64_t), ((void *)(&nstimequeued1)), NULL);
    if (err != CL_SUCCESS) {
        printf("Error: Failed to clGetEventProfilingInfo\n");
        printf("Error: Test failed\n");
        return -1;
    }

    err = clGetEventProfilingInfo(event1, CL_PROFILING_COMMAND_END,    sizeof(uint64_t), ((void *)(&nstimeend1)),    NULL);
    if (err != CL_SUCCESS) {
        printf("Error: Failed to clGetEventProfilingInfo\n");
        printf("Error: Test failed\n");
        return -1;
    }

    if (nstimequeued0 < nstimequeued1)
        nstimequeued = nstimequeued0;
    else
        nstimequeued = nstimequeued1;

    if (nstimeend0 < nstimeend1)
        nstimeend = nstimeend1;
    else
        nstimeend = nstimeend0;

    nsduration = nstimeend - nstimequeued;
    dnsduration = nsduration;
    dsduration = dnsduration / ((double) 1000000000);
    dmbytes = globalbuffersize / (((double)1024) * ((double)1024));
    dmbpersec = (dmbytes/dsduration);

    printf("PCIe concurrent write/read:%.1lf MB, duration %lf sec, bandwidth %lf MB/sec\n", dmbytes, dsduration, dmbpersec);
  
    for(size_t i = 0; i < globalbuffersize; i++) {
        if(map_buffer0[i] != (char) 0xAA || map_buffer1[i] != (char) 0x55) {
            printf("ERROR: Failed to validate data transfers: %lu %02x %02x\n", i , map_buffer0[i], map_buffer1[i]);
            exit(EXIT_FAILURE);
        }
    }

    // Free memory for all objects
    clReleaseEvent(event0);
    clReleaseEvent(event1);
    clReleaseMemObject(dev_buffer0);
    clReleaseMemObject(dev_buffer1);
    clReleaseKernel(krnl);
    clReleaseProgram(program);
    xcl_release_world(world);

    printf("------------------------------------------------------\n");
    printf("Test passed!\n");
    return EXIT_SUCCESS;
}

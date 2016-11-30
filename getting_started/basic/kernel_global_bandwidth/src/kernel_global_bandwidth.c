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
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include <xcl.h>
#include <CL/cl_ext.h>

uint8_t get_ddr_banks(xcl_world world) {
    char* ddr_loc = strstr(world.device_name, "ddr");

    /* if the ddr identifier is at the front of the string or NULL is returned
      * then reading the previous char is dangerous so just assume 1 bank */
    if(ddr_loc == NULL || ddr_loc == world.device_name) {
        return 1;
    }

    /* The letter before contains the number of banks */
    ddr_loc--;

    /* Subtract from '0' to find the number of banks in uint8_t */
    return (uint8_t) *ddr_loc - (uint8_t) '0';
}

int main(int argc, char** argv) {

    if(argc != 1) {
        printf("Usage: %s\n", argv[0]);
        return EXIT_FAILURE;
    }

    xcl_world world = xcl_world_single();
    cl_program program = xcl_import_binary(world, "krnl_kernel_global");
    cl_kernel krnl = xcl_get_kernel(program, "bandwidth");

    int err;

    size_t globalbuffersize = 1024*1024*1024;    //1GB

    //variables for profiling
    uint64_t nsduration;

    //input buffer
    unsigned char *input_host = ((unsigned char *) malloc(globalbuffersize));
    if(input_host==NULL) {
        printf("Error: Failed to allocate host side copy of OpenCL source buffer of size %ld\n",globalbuffersize);
        return -1;
    }

    for(size_t i=0; i<globalbuffersize; i++) {
        input_host[i] = i % 256;
    }

    // input buffer
    cl_mem input_buffer;

    if (get_ddr_banks(world) == 1) {
        input_buffer = clCreateBuffer(world.context,
                                      CL_MEM_READ_WRITE,
                                      globalbuffersize,
                                      NULL,
                                      &err);

    } else {
        cl_mem_ext_ptr_t input_buffer_ext;
        input_buffer_ext.flags = XCL_MEM_DDR_BANK0;
        input_buffer_ext.obj = NULL;
        input_buffer_ext.param = 0;

        input_buffer = clCreateBuffer(world.context,
                                      CL_MEM_READ_WRITE | CL_MEM_EXT_PTR_XILINX,
                                      globalbuffersize,
                                      &input_buffer_ext,
                                      &err);
    }

    if(err != CL_SUCCESS) {
        printf("Error: Failed to allocate OpenCL source buffer of size %ld\n", globalbuffersize);
        return -1;
    }

    //output buffer
    cl_mem output_buffer;

    if (get_ddr_banks(world) == 1) {
        output_buffer = clCreateBuffer(world.context,
                                       CL_MEM_READ_WRITE,
                                       globalbuffersize,
                                       NULL,
                                       &err);
    } else {
        cl_mem_ext_ptr_t output_buffer_ext;
        output_buffer_ext.flags = XCL_MEM_DDR_BANK1;
        output_buffer_ext.obj = NULL;
        output_buffer_ext.param = 0;

        output_buffer = clCreateBuffer(world.context,
                                       CL_MEM_READ_WRITE | CL_MEM_EXT_PTR_XILINX,
                                       globalbuffersize,
                                       &output_buffer_ext,
                                       &err);
    }

    if (err != CL_SUCCESS) {
        printf("Error: Failed to allocate worst case OpenCL output buffer of size %ld\n", globalbuffersize);
        return -1;
    }

    cl_ulong num_blocks = globalbuffersize/64;
    double dbytes = globalbuffersize;
    double dmbytes = dbytes / (((double)1024) * ((double)1024));
    printf("Starting kernel to read/write %.0lf MB bytes from/to global memory... \n", dmbytes);

    //Write input buffer
    //Map input buffer for PCIe write
    unsigned char *map_input_buffer;
    map_input_buffer = (unsigned char *) clEnqueueMapBuffer(world.command_queue,
                                                            input_buffer, 
                                                            CL_FALSE, 
                                                            CL_MAP_WRITE_INVALIDATE_REGION,
                                                            0, 
                                                            globalbuffersize, 
                                                            0, 
                                                            NULL, 
                                                            NULL, 
                                                            &err);
    if (err != CL_SUCCESS) {
        printf("Error: Failed to clEnqueueMapBuffer OpenCL buffer\n");
        printf("Error: Test failed\n");
        return -1;
    }
    clFinish(world.command_queue);

    //prepare data to be written to the device
    for(size_t i=0; i<globalbuffersize; i++) {
        map_input_buffer[i] = input_host[i];
    }

    cl_event event1;
    err = clEnqueueUnmapMemObject(world.command_queue,
                                  input_buffer,
                                  map_input_buffer,
                                  0,
                                  NULL,
                                  &event1);
    if (err != CL_SUCCESS) {
        printf("Error: Failed to copy input dataset to OpenCL buffer\n");
        printf("Error: Test failed\n");
        return -1;
    }

    //execute kernel
    err = 0;
    err = clSetKernelArg(krnl, 0, sizeof(cl_mem), &output_buffer);
    err |= clSetKernelArg(krnl, 1, sizeof(cl_mem), &input_buffer);
    err |= clSetKernelArg(krnl, 2, sizeof(cl_ulong), &num_blocks);

    if (err != CL_SUCCESS) {
        printf("ERROR: Failed to set kernel arguments! %d\n", err);
        printf("ERROR: Test failed\n");
        return EXIT_FAILURE;
    }

    size_t global[1];
    size_t local[1];
    global[0]=1;
    local[0]=1;

    cl_event ndrangeevent;
    err = clEnqueueNDRangeKernel(world.command_queue, krnl, 1, NULL, global, local, 0, NULL, &ndrangeevent);
    if (err != CL_SUCCESS) {
        printf("ERROR: Failed to execute krnl %d\n", err);
        printf("ERROR: Test failed\n");
        return EXIT_FAILURE;
    }
    
    clFinish(world.command_queue);

    //copy results back from OpenCL buffer
    unsigned char *map_output_buffer;
    map_output_buffer = (unsigned char *)clEnqueueMapBuffer(world.command_queue,
                                                            output_buffer,
                                                            CL_FALSE,
                                                            CL_MAP_READ,
                                                            0,
                                                            globalbuffersize,
                                                            0,
                                                            NULL,
                                                            &event1,
                                                            &err);

    if (err != CL_SUCCESS) {
        printf("ERROR: Failed to read output size buffer %d\n", err);
        printf("ERROR: Test failed\n");
        return EXIT_FAILURE;
    }
    clFinish(world.command_queue);

    //check
    for (size_t i=0; i<globalbuffersize; i++) {
        if (map_output_buffer[i] != input_host[i]) {
            printf("ERROR : kernel failed to copy entry %ld input %i output %i\n",i,input_host[i], map_output_buffer[i]);
            return EXIT_FAILURE;
        }
    }

    //profiling information
    uint64_t nstimestart, nstimeend;
    clGetEventProfilingInfo(ndrangeevent, CL_PROFILING_COMMAND_START, sizeof(uint64_t), ((void *)(&nstimestart)), NULL);
    clGetEventProfilingInfo(ndrangeevent, CL_PROFILING_COMMAND_END,    sizeof(uint64_t), ((void *)(&nstimeend)),    NULL);
    nsduration = nstimeend-nstimestart;

    double dnsduration = ((double)nsduration);
    double dsduration = dnsduration / ((double) 1000000000);

    double bpersec = (dbytes/dsduration);
    double mbpersec = bpersec / ((double) 1024*1024 );

    printf("Kernel completed read/write %.0lf MB bytes from/to global memory.\n", dmbytes);
    printf("Execution time = %f (sec) \n", dsduration);
    printf("Concurrent Read and Write Throughput = %f (MB/sec) \n", mbpersec);

    return EXIT_SUCCESS;
}


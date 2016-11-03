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

int load_file_to_memory(const char *filename, char **result)
{ 
    size_t size = 0;
    FILE *f = fopen(filename, "rb");
    if (f == NULL) 
        { 
            *result = NULL;
            return -1; // -1 means file opening fail 
        } 
    fseek(f, 0, SEEK_END);
    size = ftell(f);
    fseek(f, 0, SEEK_SET);
    *result = (char *)malloc(size+1);
    if (size != fread(*result, sizeof(char), size, f)) 
        { 
            free(*result);
            return -2; // -2 means file reading fail 
        } 
    fclose(f);
    (*result)[size] = 0;
    return size;
}

int main(int argc, char** argv)
{
    int err;                            // error code returned from api calls
     
    size_t global[1];                   // global domain size for our calculation
    size_t local[1];                    // local domain size for our calculation

    cl_platform_id platform_id;         // platform id
    cl_device_id devices[16];  // compute device id 
    cl_device_id device_id;             // compute device id 
    cl_context context;                 // compute context
    cl_command_queue command_queue;          // compute command queue
    cl_program program;                 // compute program
    cl_kernel kernel;       

    cl_uint num_devices;
    unsigned int device_found = 0;            // compute kernel
   
    char cl_platform_vendor[1001];
    char cl_platform_name[1001];
    char cl_device_name[1001];
    char target_device_name[1001] = "xilinx:adm-pcie-ku3:2ddr:3.1";//"xilinx:adm-pcie-7v3:1ddr:2.1";

    cl_mem buffer0, buffer1;
    void *map_buffer0, *map_buffer1;
    cl_event event0, event1;
    size_t globalbuffersize = 1 << 30;  //1GB
    uint64_t nsduration, nstimequeued, nstimeend;
    uint64_t nstimequeued0, nstimeend0, nstimequeued1, nstimeend1;

    double dnsduration;
    double dsduration;
    double dmbytes;
    double dmbpersec;

    if (argc != 2){
        printf("%s <inputfile>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Connect to first platform
    err = clGetPlatformIDs(1,&platform_id,NULL);
    if (err != CL_SUCCESS) {
            printf("Error: Failed to find an OpenCL platform!\n");
            printf("Test failed\n");
            return EXIT_FAILURE;
    }
    err = clGetPlatformInfo(platform_id,CL_PLATFORM_VENDOR,1000,(void *)cl_platform_vendor,NULL);
    if (err != CL_SUCCESS) {
        printf("Error: clGetPlatformInfo(CL_PLATFORM_VENDOR) failed!\n");
        printf("Test failed\n");
        return EXIT_FAILURE;
    }

    printf("CL_PLATFORM_VENDOR %s\n", cl_platform_vendor);
    err = clGetPlatformInfo(platform_id, CL_PLATFORM_NAME, 1000, (void *)cl_platform_name, NULL);
    if (err != CL_SUCCESS) {
            printf("Error: clGetPlatformInfo(CL_PLATFORM_NAME) failed!\n");
            printf("Test failed\n");
            return EXIT_FAILURE;
    }
    printf("CL_PLATFORM_NAME %s\n",cl_platform_name);
 
    // Connect to a compute device
    err = clGetDeviceIDs(platform_id, CL_DEVICE_TYPE_ACCELERATOR,
                         16, devices, &num_devices);
    if (err != CL_SUCCESS) {
            printf("Error: Failed to create a device group!\n");
            printf("Test failed\n");
            return EXIT_FAILURE;
    }

    //iterate all devices to select the target device. 
    for (int i=0; i<num_devices; i++) {
        err = clGetDeviceInfo(devices[i], CL_DEVICE_NAME, 1024, cl_device_name, 0);
        if (err != CL_SUCCESS) {
            printf("Error: Failed to get device name for device %d!\n", i);
            printf("Test failed\n");
            return EXIT_FAILURE;
        }
        //printf("CL_DEVICE_NAME %s\n", cl_device_name);
        if(strcmp(cl_device_name, target_device_name) == 0) {
            device_id = devices[i];
            device_found = 1;
            printf("Selected %s as the target device\n", cl_device_name);
        }
    }
    
    if (!device_found) {
        printf("Target device %s not found. Exit.\n", target_device_name);
        return EXIT_FAILURE;
    }

    // Create a compute context 
    context = clCreateContext(0, 1, &device_id, NULL, NULL, &err);
    if (!context)
        {
            printf("Error: Failed to create a compute context!\n");
            printf("Test failed\n");
            return EXIT_FAILURE;
        }

    // Create a command command_queue
    command_queue = clCreateCommandQueue(context, 
                                         device_id, 
                                         CL_QUEUE_PROFILING_ENABLE | CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE,
                                         &err);
    if (!command_queue) {
            printf("Error: Failed to create a command command_queue!\n");
            printf("Error: code %i\n",err);
            printf("Test failed\n");
            return EXIT_FAILURE;
    }

    int status;

    // Create Program Objects
    // Load binary from disk
    unsigned char *kernelbinary;
    char *xclbin=argv[1];
    printf("loading %s\n", xclbin);
    int n_i = load_file_to_memory(xclbin, (char **) &kernelbinary);
    if (n_i < 0) {
        printf("failed to load kernel from xclbin: %s\n", xclbin);
        printf("Test failed\n");
        return EXIT_FAILURE;
    }
    size_t n = n_i;
    // Create the compute program from offline
    program = clCreateProgramWithBinary(context, 1, &device_id, &n,
                                        (const unsigned char **) &kernelbinary, &status, &err);
    if ((!program) || (err!=CL_SUCCESS)) {
        printf("Error: Failed to create compute program from binary %d!\n", err);
        printf("Test failed\n");
        return EXIT_FAILURE;
    }

    // Build the program executable
    //
    err = clBuildProgram(program, 0, NULL, NULL, NULL, NULL);
    if (err != CL_SUCCESS) {
        size_t len;
        char buffer[2048];

        printf("Error: Failed to build program executable!\n");
        clGetProgramBuildInfo(program, device_id, CL_PROGRAM_BUILD_LOG, sizeof(buffer), buffer, &len);
        printf("%s\n", buffer);
        printf("Test failed\n");
        return EXIT_FAILURE;
    }

    // Create the compute kernel in the program we wish to run
    kernel = clCreateKernel(program, "bandwidth", &err);
    if (!kernel || err != CL_SUCCESS) {
        printf("Error: Failed to create compute kernel!\n");
        printf("Test failed\n");
        return EXIT_FAILURE;
    }

    printf("------------------------------------------------------\n");
    //--------------------------------------------------------------------------
    //Measure PCIe read bandwidth (clEnqueueMapBuffer)
    //--------------------------------------------------------------------------
    // Create buffers in the contex
    buffer0 = clCreateBuffer(context,  CL_MEM_READ_WRITE,  globalbuffersize, NULL, NULL);
    buffer1 = clCreateBuffer(context,  CL_MEM_READ_WRITE,  globalbuffersize, NULL, NULL);
    if (!buffer0 || !buffer1) {
        printf("Error: Failed to allocate device memory!\n");
        printf("Test failed\n");
        return EXIT_FAILURE;
    }    
    
    // Migrate buffers to device
    err = 0;
    err  = clSetKernelArg(kernel, 0, sizeof(cl_mem), &buffer0);
    err |= clSetKernelArg(kernel, 1, sizeof(cl_mem), &buffer1);
    if (err != CL_SUCCESS) {
        printf("Error: Failed to set kernel arguments! %d\n", err);
        printf("Test failed\n");
        return EXIT_FAILURE;
    }
    
    global[0] = 1;
    local[0] = 1;
    err = clEnqueueNDRangeKernel(command_queue, 
                                 kernel, 
                                 1, 
                                 NULL, 
                                 global, 
                                 local, 
                                 0, 
                                 NULL, 
                                 NULL);
    if (err) {
        printf("Error: Failed to execute kernel! %d\n", err);
        printf("Test failed\n");
        return EXIT_FAILURE;
    }
    clFinish(command_queue);

    //Map buffer
    map_buffer0 = clEnqueueMapBuffer(command_queue, 
                                     buffer0, 
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
    clFinish(command_queue);
    err = clGetEventProfilingInfo(event0, CL_PROFILING_COMMAND_QUEUED, sizeof(uint64_t), ((void *)(&nstimequeued)), NULL);
    if (err != CL_SUCCESS) {
        printf("Error: Failed to clGetEventProfilingInfo\n");
        printf("Error: Test failed\n");
        return -1;
    }

    err = clGetEventProfilingInfo(event0, CL_PROFILING_COMMAND_END,    sizeof(uint64_t), ((void *)(&nstimeend)),    NULL);
    if (err != CL_SUCCESS) {
        printf("Error: Failed to clGetEventProfilingInfo\n");
        printf("Error: Test failed\n");
        return -1;
    }

    nsduration = nstimeend - nstimequeued;
    dnsduration = nsduration;
    dsduration = (dnsduration / ((double) 1000000000));
    dmbytes = globalbuffersize / (((double)1024) * ((double)1024));
    dmbpersec = (dmbytes/dsduration);

    printf("PCIe read only:%.1lf MB, duration %lf sec, bandwidth %lf MB/sec\n", dmbytes, dsduration, dmbpersec);

    //--------------------------------------------------------------------------
    //Measure PCIe write bandwidth (clEnqueueUnmapMemObject)
    //--------------------------------------------------------------------------
    err = clEnqueueUnmapMemObject(command_queue, 
                                  buffer0, 
                                  map_buffer0, 
                                  0, 
                                  NULL,
                                  &event1);
    if (err != CL_SUCCESS)
    {
        printf("Error: Failed to clEnqueueUnmapMemObject OpenCL buffer\n");
        printf("Error: Test failed\n");
        return -1;
    }
    clFinish(command_queue);
    err = clGetEventProfilingInfo(event1, CL_PROFILING_COMMAND_QUEUED, sizeof(uint64_t),((void *)(&nstimequeued)),NULL);
    if (err != CL_SUCCESS) {
        printf("Error: Failed to clGetEventProfilingInfo\n");
        printf("Error: Test failed\n");
        return -1;
    }

    err = clGetEventProfilingInfo(event1, CL_PROFILING_COMMAND_END,    sizeof(uint64_t),((void *)(&nstimeend)),   NULL);
    if (err != CL_SUCCESS) {
        printf("Error: Failed to clGetEventProfilingInfo\n");
        printf("Error: Test failed\n");
        return -1;
    }

    nsduration = nstimeend - nstimequeued;
    dnsduration = nsduration;
    dsduration = (dnsduration / ((double) 1000000000));
    dmbytes = globalbuffersize / (((double)1024) * ((double)1024));
    dmbpersec = (dmbytes/dsduration);

    printf("PCIe write only:%.1lf MB, duration %lf sec, bandwidth %lf MB/sec\n", dmbytes, dsduration, dmbpersec);

    //--------------------------------------------------------------------------
    //Measure concurrent PCIe write/read bandwidth (clEnqueueMapBuffer + clEnqueueUnmapMemObject)
    //--------------------------------------------------------------------------
    //Map buffer0 for PCIe write
    map_buffer0 = clEnqueueMapBuffer(command_queue, 
                                     buffer0, 
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
    clFinish(command_queue);

    //Measurement start here
    //unmap buffer0 (PCIe write buffer0)
    err = clEnqueueUnmapMemObject(command_queue, 
                                  buffer0, 
                                  map_buffer0, 
                                  0, 
                                  NULL,
                                  &event0);
    if (err != CL_SUCCESS)
    {
        printf("Error: Failed to clEnqueueUnmapMemObject OpenCL buffer\n");
        printf("Error: Test failed\n");
        return -1;
    }

    //map buffer1 (PCIe read buffer1) in parallel to unmap buffer0
    map_buffer1 = clEnqueueMapBuffer(command_queue, 
                                     buffer1, 
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
    clFinish(command_queue);

    //map buffer1 and unmap buffer0 are completed.
    //get profiling info for unmap buffer0
    err = clGetEventProfilingInfo(event0, CL_PROFILING_COMMAND_QUEUED, sizeof(uint64_t),((void *)(&nstimequeued0)),NULL);
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

    //get profiling info for map buffer1
    err = clGetEventProfilingInfo(event1, CL_PROFILING_COMMAND_QUEUED, sizeof(uint64_t), ((void *)(&nstimequeued1)), NULL);
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
    dsduration = (dnsduration / ((double) 1000000000));
    dmbytes = globalbuffersize / (((double)1024) * ((double)1024));
    dmbpersec = (dmbytes/dsduration);

    printf("PCIe concurrent write/read:%.1lf MB, duration %lf sec, bandwidth %lf MB/sec\n", dmbytes, dsduration, dmbpersec);


    //free memory for all objects
    clReleaseMemObject(buffer0);
    clReleaseMemObject(buffer1);
    clReleaseProgram(program);
    clReleaseKernel(kernel);
    clReleaseCommandQueue(command_queue);
    clReleaseContext(context);

    printf("------------------------------------------------------\n");
    printf("Test passed!\n");
    return EXIT_SUCCESS;
}

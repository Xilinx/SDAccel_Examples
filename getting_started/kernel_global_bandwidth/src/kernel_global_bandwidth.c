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
#include <CL/opencl.h>
#define KU3_2DDR
#ifdef KU3_2DDR
#include <CL/cl_ext.h>
#endif

/////////////////////////////////////////////////////////////////////////////////
//load_file_to_memory
//Allocated memory for and load file from disk memory
//Return value 
// 0   Success
//-1   Failure to open file
//-2   Failure to allocate memory
int load_file_to_memory(const char *filename, char **result,size_t *inputsize)
{ 
    int size = 0;
    FILE *f = fopen(filename, "rb");
    if (f == NULL) { 
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
    if(inputsize!=NULL) (*inputsize)=size;
    return 0;
}


/////////////////////////////////////////////////////////////////////////////////
//opencl_setup
//Create context for Xilinx platform, Accelerator device
//Create single command queue for accelerator device
//Create program object with clCreateProgramWithBinary using given xclbin file name
//Return value
// 0    Success
//-1    Error
//-2    Failed to load XCLBIN file from disk
//-3    Failed to clCreateProgramWithBinary
int opencl_setup(const char *xclbinfilename, cl_platform_id *platform_id, 
                 cl_device_id *devices, cl_device_id *device_id, cl_context  *context, 
                 cl_command_queue *command_queue, cl_program *program, 
                 char *cl_platform_name, const char *target_device_name) {

    char cl_platform_vendor[1001];
    char cl_device_name[1001];
    cl_int err;
    cl_uint num_devices;
    unsigned int device_found = 0;

    // Get first platform
    err = clGetPlatformIDs(1,platform_id,NULL);
    if (err != CL_SUCCESS) {
        printf("ERROR: Failed to find an OpenCL platform!\n");
        printf("ERROR: Test failed\n");
        return -1;
    }
    err = clGetPlatformInfo(*platform_id,CL_PLATFORM_VENDOR,1000,(void *)cl_platform_vendor,NULL);
    if (err != CL_SUCCESS) {
        printf("ERROR: clGetPlatformInfo(CL_PLATFORM_VENDOR) failed!\n");
        printf("ERROR: Test failed\n");
        return -1;
    }
    printf("CL_PLATFORM_VENDOR %s\n",cl_platform_vendor);
    err = clGetPlatformInfo(*platform_id,CL_PLATFORM_NAME,1000,(void *)cl_platform_name,NULL);
    if (err != CL_SUCCESS) {
            printf("ERROR: clGetPlatformInfo(CL_PLATFORM_NAME) failed!\n");
            printf("ERROR: Test failed\n");
            return -1;
    }
    printf("CL_PLATFORM_NAME %s\n",cl_platform_name);

    // Get Accelerator compute device
    int accelerator = 1;
    err = clGetDeviceIDs(*platform_id, CL_DEVICE_TYPE_ACCELERATOR, 16, devices, &num_devices);
    if (err != CL_SUCCESS) {
        printf("ERROR: Failed to create a device group!\n");
        printf("ERROR: Test failed\n");
        return -1;
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
            *device_id = devices[i];
            device_found = 1;
            printf("Selected %s as the target device\n", cl_device_name);
        }
    }
    
    if (!device_found) {
        printf("Target device %s not found. Exit.\n", target_device_name);
        return EXIT_FAILURE;
    }

    // Create a compute context containing accelerator device
    (*context)= clCreateContext(0, 1, device_id, NULL, NULL, &err);
    if (!(*context))
        {
            printf("ERROR: Failed to create a compute context!\n");
            printf("ERROR: Test failed\n");
            return -1;
        }

    // Create a command queue for accelerator device
    (*command_queue) = clCreateCommandQueue(*context, *device_id, CL_QUEUE_PROFILING_ENABLE, &err);
    if (!(*command_queue))
        {
            printf("ERROR: Failed to create a command commands!\n");
            printf("ERROR: code %i\n",err);
            printf("ERROR: Test failed\n");
            return -1;
        }

    // Load XCLBIN file binary from disk
    int status;
    unsigned char *kernelbinary;
    printf("loading %s\n", xclbinfilename);
    size_t xclbinlength;
    err = load_file_to_memory(xclbinfilename, (char **) &kernelbinary,&xclbinlength);
    if (err != 0) {
        printf("ERROR: failed to load kernel from xclbin: %s\n", xclbinfilename);
        printf("ERROR: Test failed\n");
        return -2;
    }

    // Create the program from XCLBIN file, configuring accelerator device
    (*program) = clCreateProgramWithBinary(*context, 1, device_id, &xclbinlength, (const unsigned char **) &kernelbinary, &status, &err);
    if ((!(*program)) || (err!=CL_SUCCESS)) {
        printf("ERROR: Failed to create compute program from binary %d!\n", err);
        printf("ERROR: Test failed\n");
        return -3;
    }

    // Build the program executable (no-op)
    err = clBuildProgram(*program, 0, NULL, NULL, NULL, NULL);
    if (err != CL_SUCCESS) {
            size_t len;
            char buffer[2048];
            printf("ERROR: Failed to build program executable!\n");
            clGetProgramBuildInfo(*program, *device_id, CL_PROGRAM_BUILD_LOG, sizeof(buffer), buffer, &len);
            printf("%s\n", buffer);
            printf("ERROR: Test failed\n");
            return -1;
    }

    return 0;
}



/////////////////////////////////////////////////////////////////////////////////
//main

int main(int argc, char** argv)
{

    //change the line below to match the target device
#ifdef KU3_2DDR
    const char *target_device_name = "xilinx:adm-pcie-ku3:2ddr:3.0";
#else
    const char *target_device_name = "xilinx:adm-pcie-7v3:1ddr:3.0";
#endif

    // binary container name is bin_bandwidth unless path is provided on command line
    const char *binary_container_name = argc > 1 ? argv[1] : "bin_bandwidth.xclbin";

    int err;

    size_t globalbuffersize = 1024*1024*1024;    //1GB

    //opencl setup
    cl_platform_id platform_id;
    cl_device_id device_id;
    cl_device_id devices[16];  // compute device id 
    cl_context context;
    cl_command_queue command_queue;
    cl_program program;
    char cl_platform_name[1001];

    //variables for profiling
    uint64_t nsduration;
    uint64_t tenseconds = ((uint64_t) 10) * ((uint64_t) 1000000000);

    err = opencl_setup(binary_container_name, &platform_id, devices, &device_id, 
                       &context, &command_queue, &program, cl_platform_name, 
                       target_device_name);
    if(err==-1){
        printf("Error : general failure setting up opencl context\n");
        return -1;
    }
    if(err==-2) {
        printf("Error : failed to bandwidth.xclbin from disk\n");
        return -1;
    }
    if(err==-3) {
        printf("Error : failed to clCreateProgramWithBinary with contents of xclbin\n");
    }

    //access the ACCELERATOR kernel
    cl_int clstatus;
    cl_kernel kernel = clCreateKernel(program, "bandwidth", &clstatus);
    if (!kernel || clstatus != CL_SUCCESS) {
        printf("Error: Failed to create compute kernel!\n");
        printf("Error: Test failed\n");
        return -1;
    }

    //input buffer
    unsigned char *input_host = ((unsigned char *)malloc(globalbuffersize));
    if(input_host==NULL) {
        printf("Error: Failed to allocate host side copy of OpenCL source buffer of size %i\n",globalbuffersize);
        return -1;
    }
    unsigned int i;
    for(i=0; i<globalbuffersize; i++) 
        input_host[i]=i%256;
    cl_mem input_buffer;
#ifdef KU3_2DDR
    cl_mem_ext_ptr_t input_buffer_ext;
    input_buffer_ext.flags = XCL_MEM_DDR_BANK0;
    input_buffer_ext.obj = NULL;
    input_buffer_ext.param = 0;

    input_buffer = clCreateBuffer(context, 
                                  CL_MEM_READ_WRITE | CL_MEM_EXT_PTR_XILINX, 
                                  globalbuffersize, 
                                  &input_buffer_ext, 
                                  &err);
#else
    input_buffer = clCreateBuffer(context, 
                                  CL_MEM_READ_WRITE, 
                                  globalbuffersize, 
                                  NULL, 
                                  &err);
#endif
    if(err != CL_SUCCESS) {
        printf("Error: Failed to allocate OpenCL source buffer of size %i\n", globalbuffersize);
        return -1;
    }

    //output buffer
    cl_mem output_buffer;
#ifdef KU3_2DDR
    cl_mem_ext_ptr_t output_buffer_ext;
    output_buffer_ext.flags = XCL_MEM_DDR_BANK1;
    output_buffer_ext.obj = NULL;
    output_buffer_ext.param = 0;

    output_buffer = clCreateBuffer(context, 
                                   CL_MEM_READ_WRITE | CL_MEM_EXT_PTR_XILINX, 
                                   globalbuffersize, 
                                   &output_buffer_ext, 
                                   &err);
#else
    output_buffer = clCreateBuffer(context, 
                                   CL_MEM_READ_WRITE, 
                                   globalbuffersize, 
                                   NULL, 
                                   &err);
#endif
    if (err != CL_SUCCESS) {
        printf("Error: Failed to allocate worst case OpenCL output buffer of size %i\n",globalbuffersize);
        return -1;
    }

    //
    cl_ulong num_blocks = globalbuffersize/64;
    double dbytes = globalbuffersize;
    double dmbytes = dbytes / (((double)1024) * ((double)1024));
    printf("Starting kernel to read/write %.0lf MB bytes from/to global memory... \n", dmbytes);

    //Write input buffer
    //Map input buffer for PCIe write
    unsigned char *map_input_buffer;
    map_input_buffer = (unsigned char *) clEnqueueMapBuffer(command_queue, 
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
    clFinish(command_queue);

    //prepare data to be written to the device
    for(i=0; i<globalbuffersize; i++) 
        map_input_buffer[i] = input_host[i];

    cl_event event1;
    err = clEnqueueUnmapMemObject(command_queue, 
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
    err = clSetKernelArg(kernel, 0, sizeof(cl_mem), &output_buffer);
    err |= clSetKernelArg(kernel, 1, sizeof(cl_mem), &input_buffer);
    err |= clSetKernelArg(kernel, 2, sizeof(cl_ulong), &num_blocks);

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
    err = clEnqueueNDRangeKernel(command_queue, kernel, 1, NULL, global, local, 0, NULL, &ndrangeevent);
    if (err != CL_SUCCESS) {
        printf("ERROR: Failed to execute kernel %d\n", err);
        printf("ERROR: Test failed\n");
        return EXIT_FAILURE;
    }
    
    clFinish(command_queue);

    //copy results back from OpenCL buffer
    unsigned char *map_output_buffer;
    map_output_buffer = (unsigned char *)clEnqueueMapBuffer(command_queue, 
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
    clFinish(command_queue);

    //check
    for (i=0; i<globalbuffersize; i++) {
        if (map_output_buffer[i] != input_host[i]) {
            printf("ERROR : kernel failed to copy entry %i input %i output %i\n",i,input_host[i], map_output_buffer[i]);
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


    //add clena up code
    //

    return EXIT_SUCCESS;

}


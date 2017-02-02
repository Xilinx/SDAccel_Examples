/*******************************************************************************
Copyright (c) 2017, Xilinx, Inc.
All rights reserved.
Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice,
this list of conditions and the following disclaimer in the documentation and/or
other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors
may be used to endorse or promote products derived from this software without
specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "kmeans.h"

#include <CL/cl.h>

#ifndef FLT_MAX
#define FLT_MAX 3.40282347e+38
#endif

int detect_device() {
    cl_int status;
    // Discover and initialise platform
    cl_uint numPlatforms = 1;
    cl_platform_id *platforms = NULL;

    // Retrieve number of platforms
    status = clGetPlatformIDs(0, NULL, &numPlatforms);
    verify_success(status);
    // Allocate space for platforms and acquire their IDs
    platforms = (cl_platform_id*) malloc(sizeof(*platforms) * numPlatforms);
    status = clGetPlatformIDs(numPlatforms, platforms, NULL);
    verify_success(status);
    /*********************************************************/
    // Discover and initialise devices
    cl_uint numDevices = 0;
    cl_device_id *devices = NULL;
    unsigned int i, j=0;
    for(i=0; i < numPlatforms; i++ ) {
        static cl_uint pNumDevices = 0;
        status = clGetDeviceIDs(platforms[i], CL_DEVICE_TYPE_ALL, 0, NULL, &pNumDevices);
        verify_success(status);
        numDevices += pNumDevices;
        devices = (cl_device_id*) realloc(devices, sizeof(*devices) * numDevices);
        status = clGetDeviceIDs(platforms[i], CL_DEVICE_TYPE_ALL, pNumDevices, devices, NULL);
        verify_success(status);
        char *platname;
        size_t pstrlen;
        status = clGetPlatformInfo(platforms[i], CL_PLATFORM_NAME, 0, NULL, &pstrlen);
        verify_success(status);
        platname = (char*)malloc(sizeof(platname)* pstrlen);
        status = clGetPlatformInfo(platforms[i], CL_PLATFORM_NAME, pstrlen, platname, NULL);
        verify_success(status);
        for(j=0; j < pNumDevices; j++) {
            // CL_DEVICE_NAME
            size_t dstrlen;
            // Acquire the length of the string to be returned.
            status =  clGetDeviceInfo( devices[j],
                CL_DEVICE_NAME,
                0,
                NULL,
                &dstrlen);
            verify_success(status);
            // Allocate enough space to hold the string.
            void *devname = malloc(sizeof(devname)*dstrlen);
            // Retrieve the string and store it in devname.
            status =  clGetDeviceInfo( devices[j],
                CL_DEVICE_NAME,
                dstrlen,
                devname,
                NULL);
            verify_success(status);
            printf("Platform Name: %s\tDevice Name: %s\n", platname, (char*)devname);
            free(devname);
            /*************************************************/
            // CL_DEVICE_GLOBAL_MEM_SIZE
            cl_ulong memsize;
            status =  clGetDeviceInfo( devices[j],
                CL_DEVICE_GLOBAL_MEM_SIZE,
                sizeof(memsize),
                &memsize,
                NULL);
            verify_success(status);
            printf("\tMemory size: %lluMB\n", (unsigned long long)memsize/1024/1024);
            /*************************************************/
            // CL_DEVICE_MAX_MEM_ALLOC_SIZE
            cl_ulong allocsize;
            status =  clGetDeviceInfo( devices[j],
                    CL_DEVICE_MAX_MEM_ALLOC_SIZE,
                sizeof(allocsize),
                &allocsize,
                NULL);
            verify_success(status);
            printf("\tMax allocatable memory size: %lluMB\n", (unsigned long long)allocsize/1024/1024);
            /************************************************/
            // CL_DEVICE_MAX_COMPUTE_UNITS
            cl_uint computecores;
            status =  clGetDeviceInfo( devices[j],
                CL_DEVICE_MAX_COMPUTE_UNITS,
                sizeof(computecores),
                &computecores,
                NULL);
            verify_success(status);
            printf("\tNumber of compute cores: %u\n", (unsigned int) computecores);
            /************************************************/
            // CL_DEVICE_MAX_CLOCK_FREQUENCY
            cl_uint freq = 0;
            status =  clGetDeviceInfo( devices[j],
                CL_DEVICE_MAX_CLOCK_FREQUENCY,
                sizeof(freq),
                &freq,
                NULL);
            verify_success(status);
            printf("\tCompute clock frequency: %uMhz\n", (unsigned int) freq);
            /***********************************************/
            // CL_DEVICE_GLOBAL_MEM_CACHE_SIZE
            size_t memcache = 0;
            status =  clGetDeviceInfo( devices[j],
                CL_DEVICE_GLOBAL_MEM_CACHE_SIZE,
                sizeof(memcache),
                &memcache,
                NULL);
            verify_success(status);
            printf("\tGlobal Memory Cache line size: %uKb\n", (unsigned int) memcache/1024);

            /***********************************************/
            // CL_DEVICE_LOCAL_MEM_SIZE
            size_t local_mem = 0;
            status =  clGetDeviceInfo( devices[j],
                CL_DEVICE_LOCAL_MEM_SIZE,
                sizeof(local_mem),
                &local_mem,
                NULL);
            verify_success(status);
            printf("\tLocal memory size: %uKb\n", (unsigned int) local_mem/1024);
            /***********************************************/
            // CL_DEVICE_MAX_CONSTANT_BUFFER_SIZE
            size_t const_mem = 0;
            status =  clGetDeviceInfo( devices[j],
                CL_DEVICE_MAX_CONSTANT_BUFFER_SIZE,
                sizeof(const_mem),
                &const_mem,
                NULL);
            verify_success(status);
            printf("\tConstant memory size: %uKb\n", (unsigned int) const_mem/1024);
            /***********************************************/
            // CL_DEVICE_EXTENSIONS 
            size_t numExt = 0;
            status =  clGetDeviceInfo( devices[j],
                CL_DEVICE_EXTENSIONS,
                0,
                NULL,
                &numExt);
            char extensions[numExt];
            status =  clGetDeviceInfo( devices[j],
                CL_DEVICE_EXTENSIONS,
                sizeof(char)*numExt,
                &extensions,
                NULL);
            verify_success(status);
            printf("\tExtensions supported: %s\n", extensions);
            puts("");
        }
        free(platname);
    }

    /*********************************************************/

    free(platforms);
    free(devices);
    return 0;
}

int main( int argc, char** argv) 
{
    detect_device();
	setup(argc, &argv[0]);
    return 0;
}

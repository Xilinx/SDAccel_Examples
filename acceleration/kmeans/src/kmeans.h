/*******************************************************************************
IMPORTANT:  READ BEFORE DOWNLOADING, COPYING, INSTALLING OR USING.         
By downloading, copying, installing or using the software you agree        
to this license.  If you do not agree to this license, do not download,    
install, copy or use the software.                                         
                                                                           
Copyright (c) 2005 Northwestern University                                 
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
#ifndef _H_FUZZY_KMEANS
#define _H_FUZZY_KMEANS

#ifndef FLT_MAX
#define FLT_MAX 3.40282347e+38
#endif
#include <string.h>
#include <time.h>
#include <CL/cl.h>
enum enum_device_type {
   DEVICE_TYPE_FPGA,
   DEVICE_TYPE_GPU,
   DEVICE_TYPE_CPU,
   DEVICE_TYPE_APU
};
/* rmse.c */
float   euclid_dist_2        (float*, float*, int);
int     find_nearest_point   (float* , int, float**, int);
float	rms_err(float**, int, int, float**, int);
int     cluster(int, int, float**, int, int, float, int*, float***, float*, int, int, const char* goldenFile = NULL);
int setup(int argc, char** argv);

float** kmeans_clustering_cmodel(float **feature, int nfeatures, int npoints, int nclusters, float threshold, 
        int* iteration, int *membership); 
//return elapsed time in ms from t0 to t1
inline double time_elapsed(struct timespec t0, struct timespec t1){
  double result = ((double)t1.tv_sec - (double)t0.tv_sec) * 1.0E9 + ((double)t1.tv_nsec - (double)t0.tv_nsec);
  result = result / 1.0E6;
  return (result);
}
inline void verify_success(cl_int status) {
    if(status != CL_SUCCESS) {
        printf("OpenCL api call failed with error code %d.\nPlease refer to http://www.khronos.org/registry/cl/api/1.2/cl.h for error code definitions.\n", status);
        exit(EXIT_FAILURE);
    }
}

char* get_file_name();
inline float getExecutionTime(cl_event event) {
     cl_ulong time_start = 0;
     cl_ulong time_end = 0;
     float total_time = 0.0f;

     clGetEventProfilingInfo(event,
                             CL_PROFILING_COMMAND_START,
                             sizeof(time_start),
                             &time_start,
                             NULL);
     clGetEventProfilingInfo(event,
                             CL_PROFILING_COMMAND_END,
                             sizeof(time_end),
                             &time_end,
                             NULL);

     total_time = (time_end - time_start) / 1E6; // Nanoseconds to Milliseconds
     return total_time;
}
inline int get_platform_num(enum_device_type type)
{
    bool fpga=false;
    cl_device_type device_type;
    switch(type){
        case DEVICE_TYPE_FPGA:
            device_type = CL_DEVICE_TYPE_ACCELERATOR;
            fpga=true;
            break;
        case DEVICE_TYPE_APU:
            device_type = CL_DEVICE_TYPE_ACCELERATOR;
            break;
        case DEVICE_TYPE_GPU:
            device_type = CL_DEVICE_TYPE_GPU;
            break;
        case DEVICE_TYPE_CPU:
            device_type = CL_DEVICE_TYPE_CPU;
            break;
        default:
            exit(-1);
    };

    cl_int status;
    // Discover and initialise platform
    cl_uint numPlatforms = 1;
    char cl_platform_name[1001];
    cl_platform_id *platforms = NULL;
    // Retrieve number of platforms
    status = clGetPlatformIDs(0, NULL, &numPlatforms);
    verify_success(status);

     // Allocate space for platforms and acquire their IDs
    platforms = (cl_platform_id*) malloc(sizeof(*platforms) * numPlatforms);
    status = clGetPlatformIDs(numPlatforms, platforms, NULL);
    verify_success(status);
    /*********************************************************/
    int platform_num = -1;
    unsigned int i;
    for(i=0; i < numPlatforms; i++ ) {
        static cl_uint pNumDevices = 0;
        status = clGetDeviceIDs(platforms[i], device_type, 0, NULL, &pNumDevices);
        if (pNumDevices){
            if (fpga){
                clGetPlatformInfo(platforms[i],CL_PLATFORM_NAME,1000,(void *)cl_platform_name,NULL);
                platform_num = i;
                break;
            }else{
                platform_num = i;
                break;
            }
        }
    }

    /*********************************************************/
    free(platforms);
    return platform_num;
}
#endif

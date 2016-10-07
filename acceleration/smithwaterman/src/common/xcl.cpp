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
#include <unistd.h>

#include <string.h>
#include <math.h>

#include <xcl.h>

static void* smalloc(size_t size) {
	void* ptr;

	ptr = malloc(size);

	if (ptr == NULL) {
		printf("Error: Cannot allocate memory\n");
		printf("Test failed\n");
		exit(EXIT_FAILURE);
	}

	return ptr;
}

static int load_file_to_memory(const char *filename, char **result) {
	unsigned int size;

	FILE *f = fopen(filename, "rb");
	if (f == NULL) {
		*result = NULL;
		printf("Error: Could not read file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	fseek(f, 0, SEEK_END);
	size = ftell(f);
	fseek(f, 0, SEEK_SET);

	*result = (char *) smalloc(sizeof(char)*(size+1));

	if (size != fread(*result, sizeof(char), size, f)) {
		free(*result);
		printf("Error: read of kernel failed\n");
		exit(EXIT_FAILURE);
	}

	fclose(f);
	(*result)[size] = 0;

	return size;
}


int xcl_list_platforms() {

	char buffer[256];
	cl_uint num_platforms;
	cl_platform_id* clPlatformIDs;
	cl_int ciErrNum;

	printf("===========================================\n");
	printf("[%s]\n", __func__);

	//Get OpenCL platform count
	ciErrNum = clGetPlatformIDs(0, NULL, &num_platforms);
	if (ciErrNum != CL_SUCCESS) {
		printf("Error: no platforms available or OpenCL install broken");
		printf("Test failed\n");
		return -1;
	}

	//if no platform found then return
	if (num_platforms == 0) {
		printf("Error: no platforms available or OpenCL install broken");
		printf("Test failed\n");
		return -1;
	}

	printf("Number of platforms installed = [%i]\n", num_platforms);

	//if there's a platform or more, make space for ID's
	clPlatformIDs = (cl_platform_id*) malloc(num_platforms * sizeof(cl_platform_id));
	if (clPlatformIDs == NULL) {
		printf("Error: Failed to allocate memory for cl_platform IDs");
		printf("Test failed\n");
		return -1;
	}

	//get platform info for each platform
	ciErrNum = clGetPlatformIDs(num_platforms, clPlatformIDs, NULL);
	for (cl_uint i = 0; i < num_platforms; i++) {
		ciErrNum = clGetPlatformInfo(clPlatformIDs[i], CL_PLATFORM_NAME, 256,
				&buffer, NULL);
		if (ciErrNum == CL_SUCCESS) {
			printf("platform [%i] vendor = [%s]\n", i, buffer);

		}
	}

	return num_platforms;
}


int xcl_list_devices(const char* vendor_name, cl_platform_id* p_matched_platform_id) {
	char buffer[256];
	cl_uint num_platforms;
	cl_platform_id* clPlatformIDs;
	cl_int ciErrNum;
	cl_platform_id matched_platform_id = 0;

	printf("===========================================\n");
	printf("[%s] vendor_name = [%s] \n", __func__, vendor_name);

	//Get OpenCL platform count
	ciErrNum = clGetPlatformIDs(0, NULL, &num_platforms);
	if (ciErrNum != CL_SUCCESS) {
		printf("Error: no platforms available or OpenCL install broken");
		printf("Test failed\n");
		return -1;
	}

	//if no platform found then return
	if (num_platforms == 0) {
		printf("Error: no platforms available or OpenCL install broken");
		printf("Test failed\n");
		return -1;
	}

	printf("Number of platforms installed = [%i]\n", num_platforms);

	//if there's a platform or more, make space for ID's
	clPlatformIDs = (cl_platform_id*) malloc(num_platforms * sizeof(cl_platform_id));
	if (clPlatformIDs == NULL) {
		printf("Error: Failed to allocate memory for cl_platform IDs");
		printf("Test failed\n");
		return -1;
	}

	//get platform info for each platform
	ciErrNum = clGetPlatformIDs(num_platforms, clPlatformIDs, NULL);
	for (cl_uint i = 0; i < num_platforms; i++) {
		ciErrNum = clGetPlatformInfo(clPlatformIDs[i], CL_PLATFORM_NAME, 256,
				&buffer, NULL);
		if (ciErrNum == CL_SUCCESS) {
			printf("platform [%i] vendor = [%s]\n", i, buffer);

			if (strstr(buffer, vendor_name) != NULL) {
				printf("platform [%i] matched! vendor = [%s] query = [%s]\n", i, buffer, vendor_name);
				matched_platform_id = clPlatformIDs[i];

				if(p_matched_platform_id) {
					*p_matched_platform_id = matched_platform_id;
				}
				break;
			}
		}
	}

	if(matched_platform_id == 0) {
		printf("Error: Failed to match the requested platform vendor name");
		printf("Test failed\n");
		return -1;
	}

	cl_uint num_device_ids = 0;
	ciErrNum = clGetDeviceIDs(matched_platform_id, CL_DEVICE_TYPE_ALL, 0, NULL,
							  &num_device_ids);
	if (ciErrNum != CL_SUCCESS) {
		printf("Error: Failed to get number of device ids.");
		printf("Test failed\n");
		return -1;
	}

	//holds all devices
	cl_device_id* device_ids = (cl_device_id*) malloc(sizeof(cl_device_id) * num_device_ids);

	ciErrNum = clGetDeviceIDs(matched_platform_id, CL_DEVICE_TYPE_ALL, num_device_ids,
			device_ids, NULL);
	if (ciErrNum != CL_SUCCESS) {
		free(device_ids);
		printf("Error: Failed to get device ids.");
		printf("Test failed\n");
		return -1;
	}

	//iterate over devices
	for (int i = 0; i < (int)num_device_ids; i++) {
		size_t device_name_size;
		ciErrNum = clGetDeviceInfo(device_ids[i], CL_DEVICE_NAME, 0, NULL, &device_name_size);
		if (ciErrNum != CL_SUCCESS) {
			printf("Error: Failed to get device name size.");
			printf("Test failed\n");
			return -1;
		}

		char *pStrDeviceName = (char*) malloc(sizeof(char) * device_name_size);
		if (pStrDeviceName == NULL) {
			printf("Error: Failed to allocate memory to hold device name.");
			printf("Test failed\n");
			return -1;
		}

		ciErrNum = clGetDeviceInfo(device_ids[i], CL_DEVICE_NAME, device_name_size,
				pStrDeviceName, NULL);
		if (ciErrNum != CL_SUCCESS) {
			free(pStrDeviceName);
			printf("Error: Failed to get device name");
			printf("Test failed\n");
			return -1;
		}


		printf("Device [%i] name = [%s]\n", i, pStrDeviceName);

		free(pStrDeviceName);
	}

	return num_device_ids;
}


bool xcl_world_vendor_devtype(const char* vendor_name, cl_device_type device_type, xcl_world& world) {

	int num_device_ids = 0;

	printf("===========================================\n");
	printf("[%s] vendor_name = [%s] \n", __func__, vendor_name);

	num_device_ids = xcl_list_devices(vendor_name, &world.platform_id);
	if(num_device_ids <= 0) {
		printf("Error: Failed to get devices for platform: %s\n", vendor_name);
		printf("Test failed\n");
		return false;
	}

	//holds all devices
	cl_device_id* device_ids = (cl_device_id*) malloc(sizeof(cl_device_id) * num_device_ids);

	cl_int ciErrNum = clGetDeviceIDs(world.platform_id, device_type, num_device_ids, device_ids, NULL);
	if (ciErrNum != CL_SUCCESS) {
		free(device_ids);
		printf("Error: Failed to get device ids.");
		printf("Test failed\n");
		return false;
	}

	//iterate over devices
	for (int i = 0; i < (int)num_device_ids; i++) {
		size_t device_name_size;
		ciErrNum = clGetDeviceInfo(device_ids[i], CL_DEVICE_NAME, 0, NULL, &device_name_size);
		if (ciErrNum != CL_SUCCESS) {
			printf("Error: Failed to get device name size.");
			printf("Test failed\n");
			return false;
		}

		char *pStrDeviceName = (char*) malloc(sizeof(char) * device_name_size);
		if (pStrDeviceName == NULL) {
			printf("Error: Failed to allocate memory to hold device name.");
			printf("Test failed\n");
			return false;
		}

		ciErrNum = clGetDeviceInfo(device_ids[i], CL_DEVICE_NAME, device_name_size,
				pStrDeviceName, NULL);
		if (ciErrNum != CL_SUCCESS) {
			free(pStrDeviceName);
			printf("Error: Failed to get device name");
			printf("Test failed\n");
			return false;
		}


		printf("Matching Device [%i] name = %s\n", i, pStrDeviceName);
		world.device_id = device_ids[i];

		free(pStrDeviceName);

		break;
	}

	//create context
	world.context = clCreateContext(0, 1, &world.device_id,
	                                NULL, NULL, &ciErrNum);
	if (ciErrNum != CL_SUCCESS) {
		printf("Error: Failed to create a compute context!\n");
		printf("Test failed\n");
		return false;
	}

	//create command q
	world.command_queue = clCreateCommandQueue(world.context,
	                                           world.device_id,
	                                           CL_QUEUE_PROFILING_ENABLE,
	                                           &ciErrNum);
	if (ciErrNum != CL_SUCCESS) {
		printf("Error: Failed to create a command queue!\n");
		printf("Test failed\n");
		return false;
	}


	return true;
}


bool xcl_world_vendor_devname(const char* vendor_name, const char* device_name, xcl_world& world) {
	int num_device_ids = 0;
	world.platform_id = 0;
	world.device_id = 0;

	printf("===========================================\n");
	printf("[%s] vendor_name = [%s], device_name = [%s]\n", __func__, vendor_name, device_name);

	num_device_ids = xcl_list_devices(vendor_name, &world.platform_id);
	if(num_device_ids <= 0) {
		printf("Error: Failed to get devices for platform: %s\n", vendor_name);
		printf("Test failed\n");
		return false;
	}

	//holds all devices
	cl_device_id* device_ids = (cl_device_id*) malloc(sizeof(cl_device_id) * num_device_ids);

	cl_int ciErrNum = clGetDeviceIDs(world.platform_id, CL_DEVICE_TYPE_ALL, num_device_ids, device_ids, NULL);
	if (ciErrNum != CL_SUCCESS) {
		free(device_ids);
		printf("Error: Failed to get device ids.");
		printf("Test failed\n");
		return false;
	}

	//iterate over devices
	for (int i = 0; i < (int)num_device_ids; i++) {
		size_t device_name_size;
		ciErrNum = clGetDeviceInfo(device_ids[i], CL_DEVICE_NAME, 0, NULL, &device_name_size);
		if (ciErrNum != CL_SUCCESS) {
			printf("Error: Failed to get device name size.");
			printf("Test failed\n");
			return false;
		}

		char *pStrDeviceName = (char*) malloc(sizeof(char) * device_name_size);
		if (pStrDeviceName == NULL) {
			printf("Error: Failed to allocate memory to hold device name.");
			printf("Test failed\n");
			return false;
		}

		ciErrNum = clGetDeviceInfo(device_ids[i], CL_DEVICE_NAME, device_name_size,
				pStrDeviceName, NULL);
		if (ciErrNum != CL_SUCCESS) {
			free(pStrDeviceName);
			printf("Error: Failed to get device name");
			printf("Test failed\n");
			return false;
		}

		if(strstr(pStrDeviceName, device_name) != NULL) {
			printf("Matching Device [%i] name = %s\n", i, pStrDeviceName);
			world.device_id = device_ids[i];
			free(pStrDeviceName);

			break;
		}


		free(pStrDeviceName);

		break;
	}

	//create context
	world.context = clCreateContext(0, 1, &world.device_id,
	                                NULL, NULL, &ciErrNum);
	if (ciErrNum != CL_SUCCESS) {
		printf("Error: Failed to create a compute context!\n");
		printf("Test failed\n");
		return false;
	}

	//create command q
	world.command_queue = clCreateCommandQueue(world.context,
	                                           world.device_id,
	                                           CL_QUEUE_PROFILING_ENABLE,
	                                           &ciErrNum);
	if (ciErrNum != CL_SUCCESS) {
		printf("Error: Failed to create a command queue!\n");
		printf("Test failed\n");
		return false;
	}


	return true;
}


xcl_world xcl_world_single(cl_device_type device_type) {
	int err;
	xcl_world world;
	cl_uint num_platforms;

	printf("===========================================\n");
	printf("[%s]\n", __func__);

	err = clGetPlatformIDs(0, NULL, &num_platforms);
	if (err != CL_SUCCESS) {
		printf("Error: no platforms available or OpenCL install broken");
		printf("Test failed\n");
		exit(EXIT_FAILURE);
	}

	cl_platform_id *platform_ids = (cl_platform_id *) malloc(sizeof(cl_platform_id) * num_platforms);

	if (platform_ids == NULL) {
		printf("Error: Out of Memory\n");
		printf("Test failed\n");
		exit(EXIT_FAILURE);
	}

	err = clGetPlatformIDs(num_platforms, platform_ids, NULL);
	if (err != CL_SUCCESS) {
		printf("Error: Failed to find an OpenCL platform!\n");
		printf("Test failed\n");
		exit(EXIT_FAILURE);
	}

	int i;
	for(i = 0; i < (int)num_platforms; i++) {
		err = clGetDeviceIDs(platform_ids[i], device_type,
							 1, &world.device_id, NULL);
		if (err == CL_SUCCESS) {
			world.platform_id = platform_ids[i];
			break;
		}
	}

	free(platform_ids);

	if (i == (int)num_platforms) {
		printf("Error: Failed to create a device group\n");
		printf("Test failed\n");
		exit(EXIT_FAILURE);
	}

	world.context = clCreateContext(0, 1, &world.device_id,
	                                NULL, NULL, &err);
	if (err != CL_SUCCESS) {
		printf("Error: Failed to create a compute context!\n");
		printf("Test failed\n");
		exit(EXIT_FAILURE);
	}

	world.command_queue = clCreateCommandQueue(world.context,
	                                           world.device_id,
	                                           CL_QUEUE_PROFILING_ENABLE,
	                                           &err);
	if (err != CL_SUCCESS) {
		printf("Error: Failed to create a command queue!\n");
		printf("Test failed\n");
		exit(EXIT_FAILURE);
	}

	return world;
}


void xcl_release_world(xcl_world world) {
	clReleaseCommandQueue(world.command_queue);
	clReleaseContext(world.context);
}

cl_kernel xcl_import_binary(xcl_world world,
                            const char *krnl_file,
                            const char *krnl_name)
{
	int err;

	char *krnl_bin;
	const size_t krnl_size = load_file_to_memory(krnl_file, &krnl_bin);

	cl_program program = clCreateProgramWithBinary(world.context, 1,
	                                    &world.device_id, &krnl_size,
	                                    (const unsigned char**) &krnl_bin,
	                                    NULL, &err);
	if ((!program) || (err!=CL_SUCCESS)) {
		printf("Error: Failed to create compute program from binary %d!\n",
		       err);
		printf("Test failed\n");
		exit(EXIT_FAILURE);
	}

	err = clBuildProgram(program, 0, NULL, NULL, NULL, NULL);
	if (err != CL_SUCCESS) {
		size_t len;
		char buffer[2048];

		printf("Error: Failed to build program executable!\n");
		clGetProgramBuildInfo(program, world.device_id, CL_PROGRAM_BUILD_LOG,
		                      sizeof(buffer), buffer, &len);
		printf("%s\n", buffer);
		printf("Test failed\n");
		exit(EXIT_FAILURE);
	}

	cl_kernel kernel = clCreateKernel(program, krnl_name, &err);
	if (!kernel || err != CL_SUCCESS) {
		printf("Error: Failed to create kernel for %s: %d\n", krnl_name, err);
		printf("Test failed\n");
		exit(EXIT_FAILURE);
	}

	/* if program is released, then EnqueueNDRangeKernel fails with
	 * INVALID_KERNEL */
	/* clReleaseProgram(program); */
	free(krnl_bin);

	return kernel;
}

cl_kernel xcl_import_source(xcl_world world,
                            const char *krnl_file,
                            const char *krnl_name)
{
	int err;

	char *krnl_bin;
	load_file_to_memory(krnl_file, &krnl_bin);

	cl_program program = clCreateProgramWithSource(world.context, 1,
	                                               (const char**) &krnl_bin,
	                                               0, &err);
	if ((err!=CL_SUCCESS) || (!program))  {
		printf("Error: Failed to create compute program from binary %d!\n",
		       err);
		printf("Test failed\n");
		exit(EXIT_FAILURE);
	}

	err = clBuildProgram(program, 0, NULL, NULL, NULL, NULL);
	if (err != CL_SUCCESS) {
		size_t len;
		char buffer[2048];

		printf("Error: Failed to build program executable!\n");
		clGetProgramBuildInfo(program, world.device_id, CL_PROGRAM_BUILD_LOG,
		                      sizeof(buffer), buffer, &len);
		printf("%s\n", buffer);
		printf("Test failed\n");
		exit(EXIT_FAILURE);
	}

	cl_kernel kernel = clCreateKernel(program, krnl_name, &err);
	if (!kernel || err != CL_SUCCESS) {
		printf("Error: Failed to create kernel for %s: %d\n", krnl_name, err);
		printf("Test failed\n");
		exit(EXIT_FAILURE);
	}

	/* if program is released, then EnqueueNDRangeKernel fails with
	 * INVALID_KERNEL */
	/* clReleaseProgram(program); */
	free(krnl_bin);

	return kernel;
}

void xcl_set_kernel_arg(cl_kernel krnl, cl_uint num, size_t size, const void *ptr) {
	int err = clSetKernelArg(krnl, num, size, ptr);

	if(err != CL_SUCCESS) {
		printf("Error: Failed to set kernel arg\n");
		printf("Test failed\n");
		exit(EXIT_FAILURE);
	}
}

cl_mem xcl_malloc(xcl_world world, cl_mem_flags flags, size_t size) {
	cl_mem mem = clCreateBuffer(world.context, flags, size, NULL, NULL);

	if (!mem) {
		printf("Error: Failed to allocate device memory!\n");
		printf("Test failed\n");
		exit(EXIT_FAILURE);
	}

	return mem;
}

void xcl_memcpy_to_device(xcl_world world, cl_mem dest, void* src,
                          size_t size) {
	int err = clEnqueueWriteBuffer(world.command_queue, dest, CL_TRUE, 0, size,
	                               src, 0, NULL, NULL);
	if (err != CL_SUCCESS) {
		printf("Error: Failed to write to source array a!\n");
		printf("Test failed\n");
		exit(EXIT_FAILURE);
	}
}

void xcl_memcpy_from_device(xcl_world world, void* dest, cl_mem src,
                            size_t size) {
	int err = clEnqueueReadBuffer(world.command_queue, src, CL_TRUE, 0, size,
	                              dest, 0, NULL, NULL);
	if (err != CL_SUCCESS) {
		printf("Error: Failed to read output array! %d\n", err);
		printf("Test failed\n");
		exit(EXIT_FAILURE);
	}
}

unsigned long xcl_run_kernel3d(xcl_world world, cl_kernel krnl,
                               size_t x, size_t y, size_t z) {
	size_t size[3] = {x, y, z};
	cl_event event;
	unsigned long start, stop;

	int err = clEnqueueNDRangeKernel(world.command_queue, krnl, 3,
	                                 NULL, size, size, 0, NULL, &event);
	if( err != CL_SUCCESS) {
		printf("Error: failed to execute kernel! %d\n", err);
		printf("Test failed\n");
		exit(EXIT_FAILURE);
	}

	clFinish(world.command_queue);

	clGetEventProfilingInfo(event, CL_PROFILING_COMMAND_START,
	                        sizeof(unsigned long), &start, NULL);
	clGetEventProfilingInfo(event, CL_PROFILING_COMMAND_END,
	                        sizeof(unsigned long), &stop, NULL);

	return stop - start;
}

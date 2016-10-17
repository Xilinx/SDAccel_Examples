#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#ifdef APPLE
#include <OpenCL/opencl.h>
#else
#include <CL/opencl.h>
#endif
#define MAXSOURCE 2048
#define MAX_DEVICE_NAME_SIZE 100
void print_opencl_error(FILE* fh, cl_int err);

int main( int argc, char* argv[] )
{
	// Length of vectors
	unsigned int n = 10;

	// Host input vectors
	float *h_a;
	float *h_b;
	// Host output vector
	float *h_c;

	char *kernelSource = (char *) malloc(MAXSOURCE*sizeof(char));
	// Open kernel file
	FILE * file = fopen("opencl-app-kernel.cl","r");
	if(file == NULL)
	{
		printf("Error: open the kernel file (vec-add-opencl-kernel.cl)\n");
		exit(1);
	}
	// Read kernel code
	size_t source_size = fread(kernelSource, 1, MAXSOURCE, file);
	// Device input buffers
	cl_mem d_a;
	cl_mem d_b;
	// Device output buffer
	cl_mem d_c;
	char deviceName[MAX_DEVICE_NAME_SIZE];
	cl_platform_id cpPlatform;        // OpenCL platform
	cl_device_id device_id;           // device ID
	cl_context context;               // context
	cl_command_queue queue;           // command queue
	cl_program program;               // program
	cl_kernel kernel;                 // kernel
	cl_platform_id* platforms;
	cl_uint platformCount;
	// Size, in bytes, of each vector
	size_t bytes = n*sizeof(float);

	// Allocate memory for each vector on host
	h_a = (float*)malloc(bytes);
	h_b = (float*)malloc(bytes);
	h_c = (float*)malloc(bytes);

	// Initialize vectors on host
	int i;
	for( i = 0; i < n; i++ )
	{
		h_a[i] = sinf(i)*sinf(i);
		h_b[i] = cosf(i)*cosf(i);
	}

	size_t globalSize, localSize;
	cl_int err;

	// Number of work items in each local work group
	localSize = 64;

	// Number of total work items - localSize must be devisor
	globalSize = ceil(n/(float)localSize)*localSize;

	// Bind to platforms
	clGetPlatformIDs(0, NULL, &platformCount);
	if (platformCount == 0) {
	  printf("Error, cound not find any OpenCL platforms on the system.\n");
	  exit (2);
	}
	platforms = (cl_platform_id*) malloc(sizeof(cl_platform_id) * platformCount);
	clGetPlatformIDs(platformCount,platforms, NULL);
	// Find first device that works
	err = 1;
	for (i = 0; i < platformCount && err !=CL_SUCCESS; i++) {
		// Get ID for the device (CL_DEVICE_TYPE_ALL, CL_DEVICE_TYPE_GPU, ...)
		err = clGetDeviceIDs(platforms[i], CL_DEVICE_TYPE_CPU, 1, &device_id, NULL);
	}

	if (err !=CL_SUCCESS) {
	  printf("Error, could not find a valid device.");
	  exit (3);
	}

	err = clGetDeviceInfo(device_id, CL_DEVICE_NAME,MAX_DEVICE_NAME_SIZE, deviceName, NULL);

	if (err !=CL_SUCCESS) {
	  printf("Error, could not read the info for device.");
	  exit (4);
	}
	
	printf("Device: %s\n",deviceName);
	
	// Create a context
	context = clCreateContext(0, 1, &device_id, NULL, NULL, &err);
	print_opencl_error(stderr, err);
	// Create a command queue
	queue = clCreateCommandQueue(context, device_id, 0, &err);

	// Create the compute program from the source buffer
	program = clCreateProgramWithSource(context, 1,
			(const char **) & kernelSource,(const size_t *) &source_size, &err);
	print_opencl_error(stderr, err);
	// Build the program executable

	err = clBuildProgram(program, 0,NULL, NULL, NULL, NULL);
	if (err == CL_BUILD_PROGRAM_FAILURE) {
		cl_int logStatus;
		char* buildLog = NULL;
		size_t buildLogSize = 0;
		logStatus = clGetProgramBuildInfo (program, device_id, CL_PROGRAM_BUILD_LOG, buildLogSize, buildLog, &buildLogSize);
		buildLog = (char*)malloc(buildLogSize);
		memset(buildLog, 0, buildLogSize);
		logStatus = clGetProgramBuildInfo (program, device_id, CL_PROGRAM_BUILD_LOG, buildLogSize, buildLog, NULL);
		printf("%s", buildLog);
		free(buildLog);
		return err;
	} else if (err!=0) {
		print_opencl_error(stderr, err);
		return err;
	}
	// Create the compute kernel in the program we wish to run
	kernel = clCreateKernel(program, "misterious_kernel", &err);
	print_opencl_error(stderr, err);
	// Create the input and output arrays in device memory for our calculation
	d_a = clCreateBuffer(context, CL_MEM_READ_ONLY, bytes, NULL, NULL);
	d_b = clCreateBuffer(context, CL_MEM_READ_ONLY, bytes, NULL, NULL);
	d_c = clCreateBuffer(context, CL_MEM_WRITE_ONLY, bytes, NULL, NULL);

	// Write our data set into the input array in device memory
	err = clEnqueueWriteBuffer(queue, d_a, CL_TRUE, 0,
			bytes, h_a, 0, NULL, NULL);
	err |= clEnqueueWriteBuffer(queue, d_b, CL_TRUE, 0,
			bytes, h_b, 0, NULL, NULL);
	// Set the arguments to our compute kernel
	err  = clSetKernelArg(kernel, 0, sizeof(cl_mem), &d_a);
	err |= clSetKernelArg(kernel, 1, sizeof(cl_mem), &d_b);
	err |= clSetKernelArg(kernel, 2, sizeof(cl_mem), &d_c);
	err |= clSetKernelArg(kernel, 3, sizeof(unsigned int), &n);
	// Execute the kernel over the entire range of the data set
	err = clEnqueueNDRangeKernel(queue, kernel, 1, NULL, &globalSize, &localSize, 0, NULL, NULL);
	print_opencl_error(stderr, err);

	// Wait for the command queue to get serviced before reading back results
	clFinish(queue);

	// Read the results from the device
	clEnqueueReadBuffer(queue, d_c, CL_TRUE, 0,
			bytes, h_c, 0, NULL, NULL );

	//Sum up vector c and print result divided by n, this should equal 1 within error
	float sum = 0;
	for(i=0; i<n; i++)
	  sum += h_c[i];
	printf("final result: %f\n", sum/n);

	// release OpenCL resources
	clReleaseMemObject(d_a);
	clReleaseMemObject(d_b);
	clReleaseMemObject(d_c);
	clReleaseProgram(program);
	clReleaseKernel(kernel);
	clReleaseCommandQueue(queue);
	clReleaseContext(context);

	//release host memory
	free(h_a);
	free(h_b);
	free(h_c);

	return 0;
}

void print_opencl_error(FILE* fh, cl_int err)
{
#define PRINT_ERR(code) case code : fprintf(fh, #code); break
	switch(err) {
	PRINT_ERR(CL_INVALID_PROGRAM);
	PRINT_ERR(CL_INVALID_VALUE);
	PRINT_ERR(CL_INVALID_DEVICE);
	PRINT_ERR(CL_INVALID_BINARY);
	PRINT_ERR(CL_INVALID_BUILD_OPTIONS);
	PRINT_ERR(CL_INVALID_OPERATION);
	PRINT_ERR(CL_COMPILER_NOT_AVAILABLE);
	PRINT_ERR(CL_BUILD_PROGRAM_FAILURE);
	PRINT_ERR(CL_OUT_OF_RESOURCES);
	PRINT_ERR(CL_OUT_OF_HOST_MEMORY);
	default:
		if(err!=CL_SUCCESS)
			fprintf(fh, "unknown code");
		break;
	};
	return;
}



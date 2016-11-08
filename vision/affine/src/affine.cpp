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
#include <sys/time.h>
#include <string>
#include <iostream>
#include <fstream>
#include <time.h>
#include <CL/opencl.h>

#ifdef USE_GUI
#include <gtk/gtk.h>
#include <gdk-pixbuf/gdk-pixbuf.h>
#endif

#define SUCCESS             0
#define FAILURE             1

#define TOTAL_ITERATIONS  100
#define TIME_BINS         200

#define X_SIZE            512
#define Y_SIZE            512


using namespace std;


#ifndef USE_OPENCL
#include "krnl_affine.cl"
#endif


int load_file_to_memory(const char *filename, char **result)
{
   int size = 0;
   FILE *f  = fopen(filename, "rb");

   if (f == NULL)
   {
      *result = NULL;
      return -1; // -1 means file opening fail
   }

   fseek(f, 0, SEEK_END);
   size = ftell(f);
   fseek(f, 0, SEEK_SET);
   *result = (char *)malloc(size+1);
   if (size != (int)(fread(*result, sizeof(char), size, f)))
   {
      free(*result);
      return -2; // -2 means file reading fail
   }
   fclose(f);
   (*result)[size] = 0;
   return size;
}


// Function to start a nanosecond-resolution timer
struct timespec timer_start()
{
    struct timespec  start_time;

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start_time);

    return start_time;
}


// Function to end a timer, returning nanoseconds elapsed as a long
long timer_end(struct timespec start_time)
{
   struct timespec  end_time;
   long             diffInNanos;

   clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end_time);

   if ((end_time.tv_nsec - start_time.tv_nsec) < 0)
   {
		diffInNanos   = 1000000000 + end_time.tv_nsec - start_time.tv_nsec;
	}
   else
   {
		diffInNanos   = end_time.tv_nsec - start_time.tv_nsec;
	}

    return diffInNanos;
}


int main(int argc, char** argv)
{

#ifdef USE_OPENCL

   int               err;                       // error code returned from api calls

   size_t            global[1];                 // global domain size for our calculation
   size_t            local[1];                  // local domain size for our calculation

   cl_platform_id   *platform_id;               // platform id
   cl_uint           num_platforms;             // number of platforms found
   int               target_platform;
   char              platform_name[128];
   char              platform_vendor[128];
   char              platform_version[128];

   cl_device_id      device_id = 0;             // compute device id, we only use the first device
   cl_context        context;                   // compute context
   cl_command_queue  commands;                  // compute command queue
   cl_program        program;                   // compute programs
   cl_kernel         kernel;                    // compute kernel

#ifdef XILINX
   char              target_platform_str[256] = "Xilinx";
#else
   char              target_platform_str[256] = "NVIDIA Corporation";
#endif

#ifndef XILINX
   const char       *filename = "krnl_affine.cl";
#endif

#endif // ifdef USE_OPENCL

   float             x_rot    = 0.0;   
   float             y_rot    = 0.0;
   float             x_expan  = 0.0;
   float             y_expan  = 0.0;
   int               x_move   = 0;
   int               y_move   = 0;

   FILE             *input_file;

   unsigned short    input_image[Y_SIZE][X_SIZE];
   unsigned char     input_image_rgb[Y_SIZE * X_SIZE * 3];

   FILE             *output_file;

   unsigned short    output_image[Y_SIZE][X_SIZE];
   unsigned char     output_image_rgb[Y_SIZE * X_SIZE * 3];

   struct timespec   AffineTransformTimer;

   long              time_to_enqueue;
   long              time_to_process;
   long              time_to_dequeue;
   long              max_time;

   cl_event          enqueue_completion_event;
   cl_event          kernel_completion_event;
   cl_event          dequeue_completion_event;

#ifdef USE_OPENCL

   printf("\n");

#ifdef XILINX

   if (argc != 2)
   {
      printf("   Usage: %s xclbin\n", argv[0]);
      return EXIT_FAILURE;
   }

#endif

   // Discover the number of platforms:
   err = clGetPlatformIDs(0, NULL, &num_platforms);
   printf("   INFO: %d OpenCL Platforms found\n\n", num_platforms);

   // Now ask OpenCL for the platform IDs:
   platform_id = (cl_platform_id *)(malloc(sizeof(cl_platform_id) * num_platforms));
   err = clGetPlatformIDs(num_platforms, platform_id, NULL);
  
   // Display platform info 
   for (int platform_index = 0; platform_index < (int)(num_platforms); platform_index++)
   {
      err |= clGetPlatformInfo(platform_id[platform_index], CL_PLATFORM_VENDOR,  128, platform_vendor,  NULL);
      err |= clGetPlatformInfo(platform_id[platform_index], CL_PLATFORM_NAME,    128, platform_name,    NULL);
      err |= clGetPlatformInfo(platform_id[platform_index], CL_PLATFORM_VERSION, 128, platform_version, NULL);

      printf("      Platform number: %d Vendor: %-24.24s Name: %-16.16s Version: %-16.16s\n", platform_index, platform_vendor, platform_name, platform_version);

      if (strcmp(platform_vendor, target_platform_str) == 0)
      {
         target_platform = platform_index;
      }
   }

   printf("\n");
   printf("   INFO: Using platform %d\n", target_platform);

   // Connect to a compute device
#ifdef XILINX
   err = clGetDeviceIDs(platform_id[target_platform], CL_DEVICE_TYPE_ACCELERATOR, 1, &device_id, NULL);
#else
   err = clGetDeviceIDs(platform_id[target_platform], CL_DEVICE_TYPE_GPU, 1, &device_id, NULL);
#endif
   if (err != CL_SUCCESS)
   {
      printf("   Error: Failed to create a device group!\n");
      printf("   Test failed\n");
      return EXIT_FAILURE;
   }

   // Create a compute context
   context = clCreateContext(0, 1, &device_id, NULL, NULL, &err);
   if (!context)
   {
      printf("   Error: Failed to create a compute context!\n");
      printf("   Test failed\n");
      return EXIT_FAILURE;
   }

   // Create a command commands
   commands = clCreateCommandQueue(context, device_id, CL_QUEUE_PROFILING_ENABLE, &err);
   if (!commands)
   {
      printf("   Error: Failed to create a command commands!\n");
      printf("   Error: code %i\n",err);
      printf("   Test failed\n");
      return EXIT_FAILURE;
   }

   // Create Program Objects

#ifdef XILINX

   // Load binary from disk
   unsigned char *kernelbinary;
   char          *xclbin = argv[1];
   cl_int         status;

   printf("   INFO: loading xclbin %s\n", xclbin);
   int n_i0 = load_file_to_memory(xclbin, (char **) &kernelbinary);
   if (n_i0 < 0) 
   {
     printf("   failed to load kernel from xclbin: %s\n", xclbin);
     printf("   Test failed\n");
     return EXIT_FAILURE;
   }

   size_t n0 = n_i0;

   // Create the compute program from offline compile
   program = clCreateProgramWithBinary(context, 1, &device_id, &n0, (const unsigned char **) &kernelbinary, &status, &err);
   if ((!program) || (err!=CL_SUCCESS))
    {
     printf("   Error: Failed to create compute program from binary %d!\n", err);
     printf("   Test failed\n");
     return EXIT_FAILURE;
   }

#else

   // Create the compute program from source
   printf("   Compiling kernel source.\n");

   char        source_array[8192];
   const char *srcptr[] = {source_array};
   size_t      sourceSize;
   FILE       *source_file;

   source_file = fopen(filename, "r");
   if (source_file == NULL)
   {
      fputs("ERROR: Unable to open kernel source", stderr);
      exit(1);
   }

   // Obtain file size:
   fseek(source_file, 0 , SEEK_END);
   sourceSize = ftell(source_file);
   rewind(source_file);
   
   fread(source_array, sourceSize, 1, source_file);
   fclose(source_file);

   program = clCreateProgramWithSource(context, 1, srcptr, &sourceSize, &err);
   if ((!program) || (err != CL_SUCCESS))
   {
     printf("   Error: Failed to create compute program from source %d!\n", err);
     printf("   Test failed\n");
     return EXIT_FAILURE;
   }

#endif

   // Build the program executable
   //
   err = clBuildProgram(program, 0, NULL, NULL, NULL, NULL);
   if (err != CL_SUCCESS)
    {
     size_t len;
     char buffer[2048];

     printf("   Error: Failed to build program executable!\n");
     clGetProgramBuildInfo(program, device_id, CL_PROGRAM_BUILD_LOG, sizeof(buffer), buffer, &len);
     printf("   %s\n", buffer);
     printf("   Test failed\n");
     return EXIT_FAILURE;
   }

   // Create the compute kernel in the program we wish to run
   kernel = clCreateKernel(program, "affine_kernel", &err);
   if (!kernel || err != CL_SUCCESS)
    {
     printf("   Error: Failed to create compute kernel!\n");
     printf("   Test failed\n");
     return EXIT_FAILURE;
   }

   // Create the input and output arrays in device memory for our calculation
   //
   cl_mem inputBuffer = clCreateBuffer(context,  CL_MEM_READ_ONLY,  sizeof(input_image), NULL, NULL);
   if (!inputBuffer)
   {
     printf("   Error: Failed to allocate device memory for input buffer!\n");
     printf("   Test failed\n");
     return EXIT_FAILURE;
   }

   cl_mem outputBuffer = clCreateBuffer(context, CL_MEM_WRITE_ONLY,  sizeof(output_image), NULL, NULL);
   if (!outputBuffer)
   {
     printf("   Error: Failed to allocate device memory for output buffer!\n");
     printf("   Test failed\n");
     return EXIT_FAILURE;
   }

   // Set the arguments to our compute kernel
   //
   err = clSetKernelArg(kernel, 0, sizeof(inputBuffer), (void *) &inputBuffer);
   if (err != CL_SUCCESS)
   {
      printf("Error: Failed to set kernel argument 0! %d\n", err);
      printf("Test failed\n");
      return EXIT_FAILURE;
   }

   err = clSetKernelArg(kernel, 1, sizeof(outputBuffer), (void *) &outputBuffer);
   if (err != CL_SUCCESS)
   {
      printf("Error: Failed to set kernel argument 1! %d\n", err);
      printf("Test failed\n");
      return EXIT_FAILURE;
   }

   global[0]   = 1;
   local[0]    = 1;

#endif   // #ifdef USE_OPENCL

   // Load the input image
   input_file = fopen("CT-MONO2-16-brain.raw", "rb");
   if (!input_file)
   {
      printf("Error: Unable to open input image file!\n");
      return 1;
   }

   printf("\n");
   printf("   Reading RAW Image\n");
   size_t items_read = fread(input_image, sizeof input_image, 1, input_file);
   printf("   Bytes read = %d\n\n", (int)(items_read * sizeof input_image));

#ifdef USE_GUI

   // Make a copy of the input image in RGB format
   unsigned char pixel_char;

   for (int y = 0; y < Y_SIZE; y++)
   {
      for (int x = 0; x < X_SIZE; x++)
      {
         pixel_char = input_image[y][x];
         
         input_image_rgb[((y * X_SIZE) + x) * 3]       = pixel_char;   // Initialize the R value
         input_image_rgb[((y * X_SIZE) + x) * 3 + 1]   = pixel_char;   // Initialize the G value
         input_image_rgb[((y * X_SIZE) + x) * 3 + 2]   = pixel_char;   // Initialize the B value
      }
   }
 
   gtk_init(&argc, &argv);

   GdkPixbuf  *input_image_rgb_Pixbuf;

   input_image_rgb_Pixbuf = gdk_pixbuf_new_from_data(input_image_rgb,
                                                     GDK_COLORSPACE_RGB,
                                                     FALSE,
                                                     8,
                                                     X_SIZE,
                                                     Y_SIZE,
                                                     X_SIZE * 3,
                                                     NULL,
                                                     NULL
                                                    );

   GtkWidget *input_image_window;
   GtkWidget *input_image_rgb_Pixbuf_image;

   input_image_window =	gtk_window_new(GTK_WINDOW_TOPLEVEL);
   input_image_rgb_Pixbuf_image = gtk_image_new_from_pixbuf(input_image_rgb_Pixbuf);
   gtk_container_add(GTK_CONTAINER(input_image_window), input_image_rgb_Pixbuf_image);
   gtk_widget_set_size_request(input_image_window, X_SIZE, Y_SIZE);
   gtk_window_set_title((GtkWindow *)input_image_window, "Input Image");
   gtk_window_move((GtkWindow *)input_image_window, 200, 200);
   gtk_widget_show_all(input_image_window);

   // Transfer control to the GTK event loop to display the window
   while (gtk_events_pending ()) gtk_main_iteration();

#endif

#ifdef USE_OPENCL

   AffineTransformTimer = timer_start();

   err = clEnqueueWriteBuffer(commands, inputBuffer, CL_FALSE, 0, sizeof input_image, (void *)(&input_image), 0, NULL, &enqueue_completion_event);
   if (err != CL_SUCCESS)
   {
      printf("Error: Failed to enqueue input data\n");
      printf("Test failed\n");
      return EXIT_FAILURE;
   }
   else
   {
      printf("   Enqueuing Input image\n\n");

      clWaitForEvents(1, &enqueue_completion_event);

      time_to_enqueue = timer_end(AffineTransformTimer);
      printf("   Image data enqueued elapsed time (nanoseconds): %ld\n", time_to_enqueue);
      printf("\n");
   }


   // Execute the kernel over the entire range of our 1d input data set
   // using the maximum number of work group items for this device
   //
   AffineTransformTimer = timer_start();

   err = clEnqueueNDRangeKernel(commands, kernel, 1, NULL, (size_t*)&global, (size_t*)&local, 0, NULL, &kernel_completion_event);
   if (err)
   {
      printf("Error: Failed to execute kernel! %d\n", err);
      printf("Test failed\n");
      return EXIT_FAILURE;
   }
   else
   {
      printf("   Executing kernel\n\n");

      clWaitForEvents(1, &kernel_completion_event);

      time_to_process = timer_end(AffineTransformTimer);
      printf("   Image data transform elapsed time (nanoseconds): %ld\n", time_to_process);
      printf("\n");
   }


   AffineTransformTimer = timer_start();

   err = clEnqueueReadBuffer(commands, outputBuffer, CL_FALSE, 0, sizeof output_image, (void *)(&output_image), 0, NULL, &dequeue_completion_event);
   if (err != CL_SUCCESS) 
   {
      printf("Error: Failed to dequeue output data\n");
      printf("Test failed\n");
   }
   else
   {
      printf("   Dequeuing Output image\n\n");

      clWaitForEvents(1, &dequeue_completion_event);

      time_to_dequeue = timer_end(AffineTransformTimer);
      printf("   Image data dequeued elapsed time (nanoseconds): %ld\n", time_to_dequeue);
      printf("\n");
   }

#else

   x_rot    = 30.0;
   y_rot    = 0.0;
   x_expan  = 0.5;
   y_expan  = 0.5;
   x_move   = 0;
   x_move   = 0;

   affine_kernel(&x_rot, &y_rot, &x_expan, &y_expan, &x_move, &y_move, (unsigned short *)input_image, (unsigned short *)output_image);

#endif

   max_time = time_to_enqueue;
   max_time = (time_to_process > max_time) ? time_to_process : max_time;
   max_time = (time_to_dequeue > max_time) ? time_to_dequeue : max_time;

   printf("   Frames per second: %2.2f\n", 1/(max_time * 10e-10));
   printf("\n");

   // Save the output image
   output_file = fopen("transformed_image.raw", "wb");
   if (!output_file)
   {
      printf("Error: Unable to open output image file!\n");
      return 1;
   }

   printf("   Writing RAW Image\n");
   size_t items_written = fwrite(output_image, sizeof output_image, 1, output_file);
   printf("   Bytes written = %d\n\n", (int)(items_read * sizeof output_image));

   

#ifdef USE_GUI

   // Make a copy of the output image in RGB format
   for (int y = 0; y < Y_SIZE; y++)
   {
      for (int x = 0; x < X_SIZE; x++)
      {
         pixel_char = output_image[y][x];
         
         output_image_rgb[((y * X_SIZE) + x) * 3]       = pixel_char;   // Initialize the R value
         output_image_rgb[((y * X_SIZE) + x) * 3 + 1]   = pixel_char;   // Initialize the G value
         output_image_rgb[((y * X_SIZE) + x) * 3 + 2]   = pixel_char;   // Initialize the B value
      }
   }
 
   gtk_init(&argc, &argv);

   GdkPixbuf  *output_image_rgb_Pixbuf;

   output_image_rgb_Pixbuf = gdk_pixbuf_new_from_data(output_image_rgb,
                                                     GDK_COLORSPACE_RGB,
                                                     FALSE,
                                                     8,
                                                     X_SIZE,
                                                     Y_SIZE,
                                                     X_SIZE * 3,
                                                     NULL,
                                                     NULL
                                                    );

   GtkWidget         *output_image_window;
   GtkWidget         *output_image_rgb_Pixbuf_image;

   output_image_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
   output_image_rgb_Pixbuf_image = gtk_image_new_from_pixbuf(output_image_rgb_Pixbuf);
   gtk_container_add(GTK_CONTAINER(output_image_window), output_image_rgb_Pixbuf_image);
   gtk_widget_set_size_request (output_image_window, X_SIZE, Y_SIZE);
   gtk_window_set_title((GtkWindow *)output_image_window, "Output Image");
   gtk_window_move((GtkWindow *)output_image_window, 900, 200);
   gtk_widget_show_all(output_image_window);

   while (1)
   {
      // Transfer control to the GTK event loop to display the window
      while (gtk_events_pending()) gtk_main_iteration();
   }

#endif

   //--------------------------------------------------------------------------
   // Shutdown and cleanup
   //--------------------------------------------------------------------------
//   clReleaseMemObject(inputBuffer);
//   clReleaseMemObject(outputBuffer);
//   clReleaseProgram(program);
//   clReleaseKernel(kernel);
//   clReleaseCommandQueue(commands);
//   clReleaseContext(context);

   return EXIT_SUCCESS;
}

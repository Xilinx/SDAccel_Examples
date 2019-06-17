/**********
Copyright (c) 2018, Xilinx, Inc.
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
#define CL_USE_DEPRECATED_OPENCL_1_2_APIS
#include "CL/opencl.h"
#include <algorithm>
#include <assert.h>
#include <chrono>
#include <iostream>
#include <math.h>
#include <omp.h>
#include <string.h>
#include <thread>
#include <utility>
#include <vector>

typedef short int16_t;
typedef unsigned short uint16_t;

void idctSoft(const int16_t block[64],
              const uint16_t q[64],
              int16_t outp[64],
              bool ignore_dc);

/* *************************************************************************** 

aligned_allocator

This struct provides an 4k alligned memory allocator. Using this
allocator allows data objects to be aligned for efficient data
transfer to the kernel.

The struct provides an allocate and deallocate function

*************************************************************************** */
template <typename T> struct aligned_allocator {
    using value_type = T;
    T *allocate(std::size_t num) {
        void *ptr = nullptr;
        if (posix_memalign(&ptr, 4096, num * sizeof(T)))
            throw std::bad_alloc();
        return reinterpret_cast<T *>(ptr);
    }
    void deallocate(T *p, std::size_t num) { free(p); }
};

/* *************************************************************************** 

smalloc

Simple helper function to malloc memory of a specifc size. The
function will throw an error if the memory can not be successfully
allocated.

*************************************************************************** */
static void *smalloc(size_t size) {
    void *ptr;

    ptr = malloc(size);

    if (ptr == NULL) {
        printf("Error: Cannot allocate memory\n");
        exit(EXIT_FAILURE);
    }

    return ptr;
}

/* *************************************************************************** 

load_file_to_memory

This function reads from the file (filename) an xclbin into
memory. This binary information is returned in the argument result.

*************************************************************************** */
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

    *result = (char *)smalloc(sizeof(char) * (size + 1));

    if (size != fread(*result, sizeof(char), size, f)) {
        free(*result);
        printf("Error: read of kernel failed\n");
        exit(EXIT_FAILURE);
    }

    fclose(f);
    (*result)[size] = 0;

    return size;
}

/* *************************************************************************** 

oclDct

This class encapsulates all runtime kernel interaction through openCL.
After the class is constructed, the objects are supposed to be
initialized (init), before kernel communication and execution can be
triggered through calls to write, run, and read. Once all transactions
are enqueued, the user is expected to call finish to ensure all
transactions are completed.

The class manages the synchronization events and allows to bulk
enqueue transactions. All buffer management is performed in the oclDct
class.

*************************************************************************** */
class oclDct {

#define NUM_SCHED 6

  public:
    oclDct();
    ~oclDct();

    void init(cl_context context,
              cl_device_id device,
              cl_kernel krnl,
              cl_command_queue q,
              size_t blocks);

    void write(size_t start,
               std::vector<int16_t, aligned_allocator<int16_t>> *blocks,
               std::vector<uint16_t, aligned_allocator<uint16_t>> *q,
               std::vector<int16_t, aligned_allocator<int16_t>> *out,
               bool ignore_dc);
    void run();
    void read();
    void finish();

  private:
    cl_context mContext;
    cl_device_id mDevice;
    cl_kernel mKernel;
    cl_command_queue mQ;

    unsigned int mNumBlocks64;
    bool mInit;
    unsigned int mCount;
    bool mHasRun;

    cl_mem mInBufferVec[NUM_SCHED][2];
    cl_mem mOutBufferVec[NUM_SCHED][1];

    cl_mem *mInBuffer;
    cl_mem *mOutBuffer;
    int m_dev_ignore_dc;

    cl_event inEvVec[NUM_SCHED];
    cl_event runEvVec[NUM_SCHED];
    cl_event outEvVec[NUM_SCHED];
};

/* *************************************************************************** 

oclDct Constructor

*************************************************************************** */
oclDct::oclDct() {
    mInit = false;
    mNumBlocks64 = 0;
}

/* *************************************************************************** 

oclDct Destructor

*************************************************************************** */
oclDct::~oclDct() {}

/* *************************************************************************** 

oclDct::init

OclDct object initialization. This sets the internal state of the
kernel interaction class. All general openCL objects are expected to
be allocated externally and provided to the kernel interaction class.

*************************************************************************** */
void oclDct::init(cl_context context,
                  cl_device_id device,
                  cl_kernel krnl,
                  cl_command_queue q,
                  size_t numBlocks64) {
    mContext = context;
    mDevice = device;
    mKernel = krnl;
    mQ = q;

    mNumBlocks64 = numBlocks64;

    assert(mNumBlocks64 ==
           numBlocks64); // check that there was not a truncation
    mInit = true;
    mCount = 0;
    mHasRun = false;

    mInit = true;
}

/* *************************************************************************** 

oclDct::write

This function manages the buffer allocation for the openCL kernel
interaction before actually enqueuing the operands for kernel
processing. Note all buffer and event management for a complete
transaction is managed in this function.

*************************************************************************** */
void oclDct::write(size_t start,
                   std::vector<int16_t, aligned_allocator<int16_t>> *blocks,
                   std::vector<uint16_t, aligned_allocator<uint16_t>> *q,
                   std::vector<int16_t, aligned_allocator<int16_t>> *out,
                   bool ignore_dc) {

    if (mCount == NUM_SCHED) {
        mHasRun = true;
        mCount = 0;
    }

    if (mHasRun) {
        clWaitForEvents(1, &outEvVec[mCount]);

        clReleaseMemObject(mOutBufferVec[mCount][0]);
        clReleaseMemObject(mInBufferVec[mCount][0]);
        clReleaseMemObject(mInBufferVec[mCount][1]);

        clReleaseEvent(outEvVec[mCount]);
        clReleaseEvent(inEvVec[mCount]);
        clReleaseEvent(runEvVec[mCount]);
    }

    mInBuffer = &(mInBufferVec[mCount][0]);
    mOutBuffer = &(mOutBufferVec[mCount][0]);

    cl_int err;
    // Move Buffer over input vector
    mInBuffer[0] = clCreateBuffer(mContext,
                                  CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY,
                                  mNumBlocks64 * 64 * sizeof(int16_t),
                                  blocks->data() + mNumBlocks64 * 64 * start,
                                  &err);

    mInBuffer[1] = clCreateBuffer(mContext,
                                  CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY,
                                  64 * sizeof(uint16_t),
                                  q->data(),
                                  &err);

    // Move Buffer over output vector
    mOutBuffer[0] = clCreateBuffer(mContext,
                                   CL_MEM_USE_HOST_PTR | CL_MEM_WRITE_ONLY,
                                   mNumBlocks64 * 64 * sizeof(int16_t),
                                   out->data() + mNumBlocks64 * 64 * start,
                                   &err);

    // Prepare Kernel to run
    m_dev_ignore_dc = ignore_dc ? 1 : 0;
}

/* *************************************************************************** 

oclDct::run

This function sets the kernel arguments and enqueues the kernel
execution.

*************************************************************************** */
void oclDct::run() {
    // Set the kernel arguments
    clSetKernelArg(mKernel, 0, sizeof(cl_mem), &mInBuffer[0]);
    clSetKernelArg(mKernel, 1, sizeof(cl_mem), &mInBuffer[1]);
    clSetKernelArg(mKernel, 2, sizeof(cl_mem), &mOutBuffer[0]);
    clSetKernelArg(mKernel, 3, sizeof(int), &m_dev_ignore_dc);
    clSetKernelArg(mKernel, 4, sizeof(unsigned int), &mNumBlocks64);

    // Schedule actual writing of data
    clEnqueueMigrateMemObjects(
        mQ, 2, mInBuffer, 0, 0, nullptr, &inEvVec[mCount]);

    clEnqueueTask(mQ, mKernel, 1, &inEvVec[mCount], &runEvVec[mCount]);
}

/* *************************************************************************** 

oclDct::read

This function enqueues the read back operation of the results of the idct.

*************************************************************************** */
void oclDct::read() {
    clEnqueueMigrateMemObjects(mQ,
                               1,
                               mOutBuffer,
                               CL_MIGRATE_MEM_OBJECT_HOST,
                               1,
                               &runEvVec[mCount],
                               &outEvVec[mCount]);
    mCount++;
}

/* *************************************************************************** 

oclDct::finish

This function ensures kernel processing has completed for all
transactions and it releases the allocated opencl objects.

*************************************************************************** */
void oclDct::finish() {
    clFinish(mQ);
    unsigned int delCount = mCount - 1;
    if (mHasRun) {
        delCount = NUM_SCHED;
    }
    for (unsigned int i = 0; i < delCount; i++) {
        clReleaseMemObject(mOutBufferVec[i][0]);
        clReleaseMemObject(mInBufferVec[i][0]);
        clReleaseMemObject(mInBufferVec[i][1]);

        clReleaseEvent(inEvVec[i]);
        clReleaseEvent(runEvVec[i]);
        clReleaseEvent(outEvVec[i]);
    }
}

/* *************************************************************************** 

runFPGA

This function guides the kernel execution of the idct algorithm.

*************************************************************************** */
void runFPGA(size_t blocks,
             std::vector<int16_t, aligned_allocator<int16_t>> &source_block,
             std::vector<uint16_t, aligned_allocator<uint16_t>> &source_q,
             std::vector<int16_t, aligned_allocator<int16_t>> &result_vpout,
             cl_command_queue q,
             bool ignore_dc,
             oclDct &cu,
             unsigned int numBlocks64) {
    for (size_t j = 0; j < blocks / numBlocks64; j++) {
        cu.write(j, &source_block, &source_q, &result_vpout, ignore_dc);
        cu.run();
        cu.read();
    }

    cu.finish();
}

/* *************************************************************************** 

runCPU

This function performs the host code computation of the idct
algorithm.

*************************************************************************** */
void runCPU(size_t blocks,
            std::vector<int16_t, aligned_allocator<int16_t>> &source_block,
            std::vector<uint16_t, aligned_allocator<uint16_t>> &source_q,
            std::vector<int16_t, aligned_allocator<int16_t>> &golden_vpout,
            bool ignore_dc) {
    for (size_t i = 0; i < blocks; i++) {
        idctSoft(&source_block[i * 64],
                 &source_q[0],
                 &golden_vpout[i * 64],
                 ignore_dc);
    }
}

/* *************************************************************************** 

main

This function is the main function of the idct program. It illustrates
the basic opencl hostcode setup, followed by the idct execution on
host (CPU) and an accelerated flow (FPGA). With a functional
comparison between host and fpga exectuion.

*************************************************************************** */
int main(int argc, char *argv[]) {

    char *xcl_mode = getenv("XCL_EMULATION_MODE");

    if (argc != 2) {
        printf("Usage: %s <XCLBIN File>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *binaryName = argv[1];

    // *********** Allocate and initialize test vectors **********

    // Blocks of 64 of int16_t
    size_t blocks = 1024 * 1024 * 4;

    // Limit blocks for emulation modes
    if (xcl_mode != NULL) {
        blocks = 1024;
    }

    bool ignore_dc = true;

    // Create input
    std::vector<int16_t, aligned_allocator<int16_t>> source_block(64 * blocks);
    std::vector<uint16_t, aligned_allocator<uint16_t>> source_q(64);
    std::vector<int16_t, aligned_allocator<int16_t>> golden_vpout(64 * blocks);
    std::vector<int16_t, aligned_allocator<int16_t>> result_vpout(64 * blocks);

    for (size_t i = 0; i < blocks; i++) {
        for (size_t j = 0; j < 64; j++) {
            source_block[i * 64 + j] = j;
        }
    }

    for (size_t j = 0; j < 64; j++) {
        source_q[j] = j;
    }

    // *********** Communication Parameters **********
    int banks = 1;
    const size_t cus = banks;
    const size_t threads = cus;
    size_t numBlocks64 = 512;

    if (xcl_mode != NULL) {
        numBlocks64 = 256;
    }

    std::cout << "FPGA number of 64*int16_t blocks per transfer: "
              << numBlocks64 << std::endl;
    if (blocks % (threads * numBlocks64) != 0) {
        std::cout << "Error: The current implementation supports only full "
                     "banks to be transfered"
                  << " per thread" << std::endl;
        exit(1);
    }

    // *********** OpenCL Host Code Setup **********

    // Connect to first platform
    int err;
    char cl_platform_vendor[1001];
    char cl_platform_name[1001];
    char cl_device_name[1001];

    cl_platform_id platform_id; // platform id
    cl_device_id device_id;     // compute device id
    cl_context context;         // compute context

    // Get number of platforms
    cl_uint platform_count;
    clGetPlatformIDs(0, nullptr, &platform_count);

    // get all platforms
    std::vector<cl_platform_id> platforms(platform_count);
    clGetPlatformIDs(platform_count, platforms.data(), nullptr);

    bool found = false;
    for (int p = 0; p < (int)platform_count; ++p) {
        platform_id = platforms[p];
        clGetPlatformInfo(platform_id,
                          CL_PLATFORM_VENDOR,
                          1000,
                          (void *)cl_platform_vendor,
                          NULL);
        clGetPlatformInfo(platform_id,
                          CL_PLATFORM_NAME,
                          1000,
                          (void *)cl_platform_name,
                          NULL);
        if (!strcmp(cl_platform_vendor, "Xilinx")) {
            found = true;
            break;
        }
    }
    if (!found) {
        std::cout << "Platform Not Found\n";
        return err;
    }

    err = clGetDeviceIDs(
        platform_id, CL_DEVICE_TYPE_ACCELERATOR, 1, &device_id, NULL);
    if (err != CL_SUCCESS) {
        std::cout << "FAILED TEST - Device\n";
        return err;
    }

    context = clCreateContext(0, 1, &device_id, NULL, NULL, &err);
    if (!context || (err != CL_SUCCESS)) {
        std::cout << "FAILED TEST - Context \n";
        return err;
    }

    clGetDeviceInfo(
        device_id, CL_DEVICE_NAME, 1000, (void *)cl_device_name, NULL);

    std::cout << "DEVICE: " << cl_device_name << std::endl;

    std::cout << "Loading Bitstream: " << binaryName << std::endl;
    char *krnl_bin;
    size_t krnl_size;
    krnl_size = load_file_to_memory(binaryName, &krnl_bin);

    printf("INFO: Loaded file\n");

    cl_program program =
        clCreateProgramWithBinary(context,
                                  1,
                                  (const cl_device_id *)&device_id,
                                  &krnl_size,
                                  (const unsigned char **)&krnl_bin,
                                  NULL,
                                  &err);

    // Create Kernel
    std::cout << "Create Kernel: krnl_idct" << std::endl;
    auto krnl = clCreateKernel(program, "krnl_idct", &err);

    // Create Command Queue
    auto q = clCreateCommandQueue(context,
                                  device_id,
                                  CL_QUEUE_PROFILING_ENABLE |
                                      CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE,
                                  &err);

    // Create compute units
    std::cout << "Create Compute Unit" << std::endl;
    oclDct cu;
    cu.init(context, device_id, krnl, q, numBlocks64);

    std::cout << "Setup complete" << std::endl;

    // *********** Host (CPU) execution **********
    std::cout << "Running CPU version" << std::endl;
    auto cpu_begin = std::chrono::high_resolution_clock::now();
    runCPU(blocks, source_block, source_q, golden_vpout, ignore_dc);
    auto cpu_end = std::chrono::high_resolution_clock::now();

    // *********** Accelerator execution **********
    std::cout << "Running FPGA version" << std::endl;
    auto fpga_begin = std::chrono::high_resolution_clock::now();
    runFPGA(blocks,
            source_block,
            source_q,
            result_vpout,
            q,
            ignore_dc,
            cu,
            numBlocks64);
    auto fpga_end = std::chrono::high_resolution_clock::now();

    // *********** OpenCL Host Code cleanup **********

    clReleaseCommandQueue(q);
    clReleaseKernel(krnl);
    clReleaseProgram(program);
    clReleaseContext(context);

    // *********** Comparison (Host to Acceleration)  **********

    std::cout << "Runs complete validating results" << std::endl;

    int krnl_match = 0;
    for (size_t i = 0; i < 64 * blocks; i++) {
        if (result_vpout[i] != golden_vpout[i]) {
            printf("Error: Result mismatch\n");
            printf("i = %d CPU result = %d Krnl Result = %d\n",
                   (int)i,
                   golden_vpout[i],
                   result_vpout[i]);
            krnl_match = 1;
            break;
        }
    }

    std::cout << "TEST " << (krnl_match ? "FAILED" : "PASSED") << std::endl;

    // *********** Computational Statistics  **********
    //
    // Only reported in the HW execution mode as wall clock time is meaningless in
    // emulation.
    //
    if (xcl_mode == NULL) {
        std::chrono::duration<double> cpu_duration = cpu_end - cpu_begin;
        std::chrono::duration<double> fpga_duration = fpga_end - fpga_begin;

        std::cout << "CPU Time:        " << cpu_duration.count() << " s"
                  << std::endl;
        std::cout << "CPU Throughput:  "
                  << (double)blocks * 128 / cpu_duration.count() /
                         (1024.0 * 1024.0)
                  << " MB/s" << std::endl;
        std::cout << "FPGA Time:       " << fpga_duration.count() << " s"
                  << std::endl;
        std::cout << "FPGA Throughput: "
                  << (double)blocks * 128 / fpga_duration.count() /
                         (1024.0 * 1024.0)
                  << " MB/s" << std::endl;
        std::cout << "FPGA PCIe Throughput: "
                  << (2 * (double)blocks * 128 + 128) / fpga_duration.count() /
                         (1024.0 * 1024.0)
                  << " MB/s" << std::endl;
    } else {
        std::cout << "RUN COMPLETE" << std::endl;
    }

    return (krnl_match ? EXIT_FAILURE : EXIT_SUCCESS);
}

/* *************************************************************************** 

idctSoft

Original software implementation of IDCT algorithm used to generate
golden reference data.

*************************************************************************** */
void idctSoft(const int16_t block[64],
              const uint16_t q[64],
              int16_t outp[64],
              bool ignore_dc) {
    int32_t intermed[64];

    const uint16_t w1 = 2841; // 2048*sqrt(2)*cos(1*pi/16)
    const uint16_t w2 = 2676; // 2048*sqrt(2)*cos(2*pi/16)
    const uint16_t w3 = 2408; // 2048*sqrt(2)*cos(3*pi/16)
    const uint16_t w5 = 1609; // 2048*sqrt(2)*cos(5*pi/16)
    const uint16_t w6 = 1108; // 2048*sqrt(2)*cos(6*pi/16)
    const uint16_t w7 = 565;  // 2048*sqrt(2)*cos(7*pi/16)

    const uint16_t w1pw7 = w1 + w7;
    const uint16_t w1mw7 = w1 - w7;
    const uint16_t w2pw6 = w2 + w6;
    const uint16_t w2mw6 = w2 - w6;
    const uint16_t w3pw5 = w3 + w5;
    const uint16_t w3mw5 = w3 - w5;

    const uint16_t r2 = 181; // 256/sqrt(2)

    // Horizontal 1-D IDCT.
    for (int y = 0; y < 8; ++y) {
        int y8 = y * 8;
        int32_t x0 =
            (((ignore_dc && y == 0) ? 0 : (block[y8 + 0] * q[y8 + 0]) << 11)) +
            128;
        int32_t x1 = (block[y8 + 4] * q[y8 + 4]) << 11;
        int32_t x2 = block[y8 + 6] * q[y8 + 6];
        int32_t x3 = block[y8 + 2] * q[y8 + 2];
        int32_t x4 = block[y8 + 1] * q[y8 + 1];
        int32_t x5 = block[y8 + 7] * q[y8 + 7];
        int32_t x6 = block[y8 + 5] * q[y8 + 5];
        int32_t x7 = block[y8 + 3] * q[y8 + 3];
        // If all the AC components are zero, then the IDCT is trivial.
        if (x1 == 0 && x2 == 0 && x3 == 0 && x4 == 0 && x5 == 0 && x6 == 0 &&
            x7 == 0) {
            int32_t dc = (x0 - 128) >> 8; // coefficients[0] << 3
            intermed[y8 + 0] = dc;
            intermed[y8 + 1] = dc;
            intermed[y8 + 2] = dc;
            intermed[y8 + 3] = dc;
            intermed[y8 + 4] = dc;
            intermed[y8 + 5] = dc;
            intermed[y8 + 6] = dc;
            intermed[y8 + 7] = dc;
            continue;
        }

        // Prescale.

        // Stage 1.
        int32_t x8 = w7 * (x4 + x5);
        x4 = x8 + w1mw7 * x4;
        x5 = x8 - w1pw7 * x5;
        x8 = w3 * (x6 + x7);
        x6 = x8 - w3mw5 * x6;
        x7 = x8 - w3pw5 * x7;

        // Stage 2.
        x8 = x0 + x1;
        x0 -= x1;
        x1 = w6 * (x3 + x2);
        x2 = x1 - w2pw6 * x2;
        x3 = x1 + w2mw6 * x3;
        x1 = x4 + x6;
        x4 -= x6;
        x6 = x5 + x7;
        x5 -= x7;

        // Stage 3.
        x7 = x8 + x3;
        x8 -= x3;
        x3 = x0 + x2;
        x0 -= x2;
        x2 = (r2 * (x4 + x5) + 128) >> 8;
        x4 = (r2 * (x4 - x5) + 128) >> 8;

        // Stage 4.
        intermed[y8 + 0] = (x7 + x1) >> 8;
        intermed[y8 + 1] = (x3 + x2) >> 8;
        intermed[y8 + 2] = (x0 + x4) >> 8;
        intermed[y8 + 3] = (x8 + x6) >> 8;
        intermed[y8 + 4] = (x8 - x6) >> 8;
        intermed[y8 + 5] = (x0 - x4) >> 8;
        intermed[y8 + 6] = (x3 - x2) >> 8;
        intermed[y8 + 7] = (x7 - x1) >> 8;
    }

    // Vertical 1-D IDCT.
    for (int32_t x = 0; x < 8; ++x) {
        // Similar to the horizontal 1-D IDCT case, if all the AC components are zero, then the IDCT is trivial.
        // However, after performing the horizontal 1-D IDCT, there are typically non-zero AC components, so
        // we do not bother to check for the all-zero case.

        // Prescale.
        int32_t y0 = (intermed[8 * 0 + x] << 8) + 8192;
        int32_t y1 = intermed[8 * 4 + x] << 8;
        int32_t y2 = intermed[8 * 6 + x];
        int32_t y3 = intermed[8 * 2 + x];
        int32_t y4 = intermed[8 * 1 + x];
        int32_t y5 = intermed[8 * 7 + x];
        int32_t y6 = intermed[8 * 5 + x];
        int32_t y7 = intermed[8 * 3 + x];

        // Stage 1.
        int32_t y8 = w7 * (y4 + y5) + 4;
        y4 = (y8 + w1mw7 * y4) >> 3;
        y5 = (y8 - w1pw7 * y5) >> 3;
        y8 = w3 * (y6 + y7) + 4;
        y6 = (y8 - w3mw5 * y6) >> 3;
        y7 = (y8 - w3pw5 * y7) >> 3;

        // Stage 2.
        y8 = y0 + y1;
        y0 -= y1;
        y1 = w6 * (y3 + y2) + 4;
        y2 = (y1 - w2pw6 * y2) >> 3;
        y3 = (y1 + w2mw6 * y3) >> 3;
        y1 = y4 + y6;
        y4 -= y6;
        y6 = y5 + y7;
        y5 -= y7;

        // Stage 3.
        y7 = y8 + y3;
        y8 -= y3;
        y3 = y0 + y2;
        y0 -= y2;
        y2 = (r2 * (y4 + y5) + 128) >> 8;
        y4 = (r2 * (y4 - y5) + 128) >> 8;

        // Stage 4.
        outp[8 * 0 + x] = (y7 + y1) >> 11;
        outp[8 * 1 + x] = (y3 + y2) >> 11;
        outp[8 * 2 + x] = (y0 + y4) >> 11;
        outp[8 * 3 + x] = (y8 + y6) >> 11;
        outp[8 * 4 + x] = (y8 - y6) >> 11;
        outp[8 * 5 + x] = (y0 - y4) >> 11;
        outp[8 * 6 + x] = (y3 - y2) >> 11;
        outp[8 * 7 + x] = (y7 - y1) >> 11;
    }
}

Host Examples
==================================
OpenCL host code for optimized interfacing with Xilinx Devices

 __Examples Table__ 

Example        | Description           | Key Concepts / Keywords 
---------------|-----------------------|-------------------------
[concurrent_kernel_execution_ocl/][]|This example will demonstrate how to use multiple and out of order command queues to simultaneously execute multiple kernels on an FPGA.|__Key__ __Concepts__<br> - Concurrent execution<br> - Out of Order Command Queues<br> - Multiple Command Queues<br>__Keywords__<br> - CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE<br> - clSetEventCallback()
[copy_buffer_ocl/][]|This Copy Buffer example demonstrate how one buffer can be copied from another buffer.|__Key__ __Concepts__<br> - Copy Buffer<br>__Keywords__<br> - cl::CommandQueue::enqueueCopyBuffer()
[data_transfer_ocl/][]|This example illustrates several ways to use the OpenCL API to transfer data to and from the FPGA|__Key__ __Concepts__<br> - OpenCL API<br> - Data Transfer<br> - Write Buffers<br> - Read Buffers<br> - Map Buffers<br> - Async Memcpy<br>__Keywords__<br> - clEnqueueWriteBuffer()<br> - clEnqueueReadBuffer()<br> - clEnqueueMapBuffer()<br> - clEnqueueUnmapMemObject()
[device_query_ocl/][]|This example prints the OpenCL properties of the platform and its devices. It also displays the limits and capabilities of the hardware.|__Key__ __Concepts__<br> - OpenCL API<br> - Querying device properties<br>__Keywords__<br> - clGetPlatformIDs()<br> - clGetPlatformInfo()<br> - clGetDeviceIDs()<br> - clGetDeviceInfo()
[errors_ocl/][]|This example discuss the different reasons for errors in OpenCL and how to handle them at runtime.|__Key__ __Concepts__<br> - OpenCL API<br> - Error handling<br>__Keywords__<br> - CL_SUCCESS<br> - CL_DEVICE_NOT_FOUND<br> - CL_DEVICE_NOT_AVAILABLE
[helloworld_ocl/][]|This example is a simple OpenCL application. It will highlight the basic flow of an OpenCL application.|__Key__ __Concepts__<br> - OpenCL API<br>
[host_global_bandwidth/][]|Host to global memory bandwidth test|
[kernel_swap_ocl/][]|This example shows how host can swap the kernels and share same buffer between two kernels exist in separate binary containers. For Non-XPR(Extended Partial Reconfiguration) Specific Devices, device memory can persist buffer data so both kernels can share data directly. Whereas in XPR devices, device memory does not persist the buffer data so host has to migrate data from device to host memory before swapping the next kernel. After kernel swap, host has to migrate the buffer back to device.|__Key__ __Concepts__<br> - Handling Buffer sharing across multiple binaries for XPR-NON_XPR Platform<br> - Multiple Kernel Binaries<br> __Keywords__<br> - clEnqueueMigrateMemObjects()<br> - CL_MIGRATE_MEM_OBJECT_HOST
[multiple_devices_ocl/][]|This example show how to take advantage of multiple FPGAs on a system. It will show how to initialized an OpenCL context, allocate memory on the two devices and execute a kernel on each FPGA.|__Key__ __Concepts__<br> - OpenCL API<br> - Multi-FPGA Execution<br> - Event Handling<br>__Keywords__<br> - cl_device_id<br> - clGetDeviceIDs()
[overlap_ocl/][]|This examples demonstrates techniques that allow user to overlap Host(CPU) and FPGA computation in an application. It will cover asynchronous operations and event object.|__Key__ __Concepts__<br> - OpenCL API<br> - Synchronize Host and FPGA<br> - Asynchronous Processing<br> - Events<br> - Asynchronous memcpy<br>__Keywords__<br> - cl_event<br> - clCreateCommandQueue<br> - CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE<br> - clEnqueueMigrateMemObjects

[stream_access_ocl/][]|This is a simple example that demonstrates on how to process an input stream of data for computation in an application. It shows how to perform asynchronous operations and event handling.|__Key__ __Concepts__<br> - OpenCL API<br> - Synchronize Host and FPGA<br> - Asynchronous Processing<br> - Events<br> - Asynchronous Data Transfer<br>__Keywords__<br> - cl_event<br> - CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE
[.]:.
[concurrent_kernel_execution_ocl/]:concurrent_kernel_execution_ocl/
[copy_buffer_ocl/]:copy_buffer_ocl/
[data_transfer_ocl/]:data_transfer_ocl/
[device_query_ocl/]:device_query_ocl/
[errors_ocl/]:errors_ocl/
[helloworld_ocl/]:helloworld_ocl/
[host_global_bandwidth/]:host_global_bandwidth/
[kernel_swap_ocl/]:kernel_swap_ocl/
[multiple_devices_ocl/]:multiple_devices_ocl/
[overlap_ocl/]:overlap_ocl/
[stream_access_ocl/]:stream_access_ocl/

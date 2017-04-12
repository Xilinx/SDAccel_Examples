Getting Started Examples
==================================
This page contains examples for users who are new to Xilinx SDx OpenCL Flows. The focus of the examples is towards code optimization for Xilinx devices.The table lists various categories of examples in suggested order which users can follow.


__Prerequisites__
 - User is familiar with basics of OpenCL flow.
 - User has gone through SDx tutorial and is familiar with basics of tool functionality and terminology.

S.No.   | Category  | Description 
--------|-----------|-----------------------------------------
1 | [host][]      |OpenCL host code for optimized interfacing with Xilinx Devices
2 | [kernel_to_gmem][]      |Kernel to Global Memory Access Optimization.
3 | [kernel_opt][]      |Kernel Optimization for performance
4 | [dataflow][]      |Kernel Optimization through Macro Level Pipelining
5 | [clk_freq][]      |Improving Kernel Clock Frequency through Optimized code.
6 | [debug][]      |Debugging and Profiling of Kernel.
7 | [rtl_kernel][]      |RTL Kernel Based Examples
8 | [basic][]      |OpenCL miscellaneous Examples

 __Examples Table__ 

Example        | Description           | Key Concepts / Keywords 
---------------|-----------------------|-------------------------
[host/concurrent_kernel_execution_ocl/][]|This example will demonstrate how to use multiple and out of order command queues to simultaneously execute multiple kernels on an FPGA.|__Key__ __Concepts__<br> - Concurrent execution<br> - Out of Order Command Queues<br> - Multiple Command Queues<br>__Keywords__<br> - CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE<br> - clSetEventCallback()
[host/data_transfer_ocl/][]|This example illustrates several ways to use the OpenCL API to transfer data to and from the FPGA|__Key__ __Concepts__<br> - OpenCL API<br> - Data Transfer<br> - Write Buffers<br> - Read Buffers<br> - Map Buffers<br> - Async Memcpy<br>__Keywords__<br> - clEnqueueWriteBuffer()<br> - clEnqueueReadBuffer()<br> - clEnqueueMapBuffer()<br> - clEnqueueUnmapMemObject()
[host/device_query_ocl/][]|This example prints the OpenCL properties of the platform and its devices. It also displays the limits and capabilities of the hardware.|__Key__ __Concepts__<br> - OpenCL API<br> - Querying device properties<br>__Keywords__<br> - clGetPlatformIDs()<br> - clGetPlatformInfo()<br> - clGetDeviceIDs()<br> - clGetDeviceInfo()
[host/errors_ocl/][]|This example discuss the different reasons for errors in OpenCL and how to handle them at runtime.|__Key__ __Concepts__<br> - OpenCL API<br> - Error handling<br>__Keywords__<br> - CL_SUCCESS<br> - CL_DEVICE_NOT_FOUND<br> - CL_DEVICE_NOT_AVAILABLE
[host/helloworld_ocl/][]|This example is a simple OpenCL application. It will highlight the basic flow of an OpenCL application.|__Key__ __Concepts__<br> - OpenCL API<br>__Keywords__<br> - NA
[host/multiple_devices_ocl/][]|This example show how to take advantage of multiple FPGAs on a system. It will show how to initialized an OpenCL context, allocate memory on the two devices and execute a kernel on each FPGA.|__Key__ __Concepts__<br> - OpenCL API<br> - Multi-FPGA Execution<br> - Event Handling<br>__Keywords__<br> - cl_device_id<br> - clGetDeviceIDs()
[host/overlap_ocl/][]|This examples demonstrates techniques that allow user to overlap Host(CPU) and FPGA computation in an application. It will cover asynchronous operations and event object.|__Key__ __Concepts__<br> - OpenCL API<br> - Synchronize Host and FPGA<br> - Asynchronous Processing<br> - Events<br> - Asynchronous memcpy<br>__Keywords__<br> - cl_event<br> - clCreateCommandQueue<br> - CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE<br> - clEnqueueMigrateMemObjects
[host/copy_buffer_ocl/][]|This Copy Buffer example demonstrate how one buffer can be copied from another buffer.|__Key__ __Concepts__<br> - Copy Buffer<br>__Keywords__<br> - cl::CommandQueue::enqueueCopyBuffer()
[kernel_to_gmem/burst_rw_c/][]|This is simple example of using AXI4-master interface for burst read and write|__Key__ __Concepts__<br> - burst access<br>__Keywords__<br> - memcpy
[kernel_to_gmem/burst_rw_ocl/][]|This is simple example of using AXI4-master interface for burst read and write|__Key__ __Concepts__<br> - burst access<br>__Keywords__<br> - NA
[kernel_to_gmem/custom_datatype_c/][]|This is simple example of RGB to HSV conversion to demonstrate Custom DATA Type usages in C Based Kernel. Xilinx HLS Compiler Supports Custom Data Type to use for operation as well as Memory Interface between Kernel and Global Memory.|__Key__ __Concepts__<br> - Dataflow<br> - Custom Datatype<br>__Keywords__<br> - struct<br> - #pragma HLS data_pack<br> - #pragma HLS LOOP_TRIPCOUNT
[kernel_to_gmem/custom_datatype_ocl/][]|This is simple example of RGB to HSV conversion to demonstrate Custom DATA Type usages in OpenCL Based Kernel. Xilinx HLS Compiler Supports Custom Data Type to use for operation as well as Memory Interface between Kernel and Global Memory.|__Key__ __Concepts__<br> - dataflow<br> - Custom Datatype<br>__Keywords__<br> - struct
[kernel_to_gmem/full_array_2d_c/][]|This is a simple example of accessing full data from 2d array|__Key__ __Concepts__<br> - 2D data full array Access<br>__Keywords__<br> - NA
[kernel_to_gmem/full_array_2d_ocl/][]|This is a simple example of accessing full data from 2d array|__Key__ __Concepts__<br> - 2D data full array Access<br>__Keywords__<br> - NA
[kernel_to_gmem/gmem_2banks_c/][]|This example of 2ddr to demonstrate on how to use 2ddr DSA. How to create buffers in each DDR.|__Key__ __Concepts__<br> - Multiple Banks<br>__Keywords__<br> - max_memory_ports<br> - misc:map_connect<br> - cl_mem_ext_ptr_t<br> - XCL_MEM_DDR_BANK0<br> - XCL_MEM_DDR_BANK1<br> - XCL_MEM_DDR_BANKx<br> - CL_MEM_EXT_PTR_XILINX<br> - HLS Interface m_axi bundle
[kernel_to_gmem/gmem_2banks_ocl/][]|This example of 2ddr to demonstrate on how to use 2ddr DSA. How to create buffers in each DDR.|__Key__ __Concepts__<br> - Multiple Banks<br>__Keywords__<br> - max_memory_ports<br> - misc:map_connect<br> - cl_mem_ext_ptr_t<br> - XCL_MEM_DDR_BANK0<br> - XCL_MEM_DDR_BANK1<br> - XCL_MEM_DDR_BANKx<br> - CL_MEM_EXT_PTR_XILINX
[kernel_to_gmem/row_array_2d_c/][]|This is a simple example of accessing each row of data from 2d array|__Key__ __Concepts__<br> - Row of 2D data array access<br>__Keywords__<br> - hls::stream
[kernel_to_gmem/row_array_2d_ocl/][]|This is a simple example of accessing each row of data from 2d array|__Key__ __Concepts__<br> - Row of 2D data array access<br>__Keywords__<br> - xcl_dataflow<br> - xcl_pipeline_loop
[kernel_to_gmem/wide_mem_rw_c/][]|This is simple example of vector addition to demonstrate Wide Memory Access using ap_uint<512> data type. Based on input argument type, xocc compiler will figure our the memory datawidth between Global Memory and Kernel. For this example, ap_uint<512> datatype is used, so Memory datawidth will be 16 x (integer bit size) = 16 x 32 = 512 bit.|__Key__ __Concepts__<br> - Kernel to DDR<br> - wide memory access<br> - burst read and write<br>__Keywords__<br> - ap_uint<><br> - ap_int.h
[kernel_to_gmem/wide_mem_rw_ocl/][]|This is simple example of vector addition to demonstrate Wide Memory Access using uint16 data type. Based on input argument type, xocc compiler will figure our the memory datawidth between Global Memory and Kernel. For this example, uint16 datatype is used, so Memory datawidth will be 16 x (integer bit size) = 16 x 32 = 512 bit.|__Key__ __Concepts__<br> - Kernel to DDR<br> - wide memory access<br> - burst read and write<br>__Keywords__<br> - uint16<br> - xcl_pipeline_loop
[kernel_to_gmem/window_array_2d_c/][]|This is a simple example of accessing each window of data from 2d array|__Key__ __Concepts__<br> - window of 2D data array access<br>__Keywords__<br> - #pragma HLS DATAFLOW<br> - #pragma HLS PIPELINE<br> - #pragma HLS stream
[kernel_to_gmem/window_array_2d_ocl/][]|This is a simple example of accessing each window of data from 2d array|__Key__ __Concepts__<br> - window/tile of 2D data array access<br>__Keywords__<br> - pipe<br> - xcl_pipeline_loop<br> - xcl_reqd_pipe_depth
[kernel_to_gmem/memcoalesce_hang_c/][]|This example shows Memory Coalesce Deadlock/Hand situation and how to handle it. User can switch between BAD and GOOD case using makefile variable KFLOW.|__Key__ __Concepts__<br> - Memory Coalesce<br> - Memory Deadlock/Hang<br> - Multiple Interfaces<br>__Keywords__<br> - HLS INTERFACE<br> - bundle<br> - m_axi
[kernel_opt/aos_vs_soa_ocl/][]|This example demonstrates how data layout can impact the performance of certain kernels. The example we will demonstrate how using the Structure of Array data layout can impact certain data parallel problems.|__Key__ __Concepts__<br> - Kernel Optimization<br> - Data Layout<br>__Keywords__<br> - NA
[kernel_opt/array_partition_ocl/][]|This example shows how to use array partitioning to improve performance of a kernel|__Key__ __Concepts__<br> - Kernel Optimization<br> - Array Partitioning<br>__Keywords__<br> - xcl_array_partition<br> - complete
[kernel_opt/dependence_inter_c/][]|This Example to demonstrate HLS pragma 'DEPENDENCE'. Using 'DEPENDENCE' pragma, user can provide additional dependency details to compiler which allow compiler to perform unrolling/pipelining to get better performance.|__Key__ __Concepts__<br> - Inter Dependence<br>__Keywords__<br> - DEPENDENCE<br> - inter
[kernel_opt/lmem_2rw_c/][]|This is simple example of vector addition to demonstrate how to utilized both ports of Local Memory memory.|__Key__ __Concepts__<br> - Kernel Optimization<br> - 2port BRAM Utilization<br> - two read/write Local Memory<br>__Keywords__<br> - #pragma HLS UNROLL FACTOR=2
[kernel_opt/lmem_2rw_ocl/][]|This is simple example of vector addition to demonstrate how to utilized both ports of Local Memory.|__Key__ __Concepts__<br> - Kernel Optimization<br> - 2port BRAM Utilization<br> - two read/write Local Memory<br>__Keywords__<br> - opencl_unroll_hint(2)
[kernel_opt/loop_fusion_ocl/][]|This example will demonstrate how to fuse two loops into one to improve the performance of an OpenCL kernel.|__Key__ __Concepts__<br> - Kernel Optimization<br> - Loop Fusion<br> - Loop Pipelining<br>__Keywords__<br> - xcl_pipeline_loop
[kernel_opt/loop_perfect_c/][]|This nearest neighbor example is to demonstrate how to achieve better performance using perfect loop.|
[kernel_opt/loop_perfect_ocl/][]|This nearest neighbor example is to demonstrate how to achieve better performance using loop perfect.|
[kernel_opt/loop_pipeline_ocl/][]|This example demonstrates how loop pipelining can be used to improve the performance of a kernel.|__Key__ __Concepts__<br> - Kernel Optimization<br> - Loop Pipelining<br>__Keywords__<br> - xcl_pipeline_loop
[kernel_opt/loop_reorder_c/][]|This is a simple example of matrix multiplication (Row x Col) to demonstrate how to achieve better pipeline II factor by loop reordering.|__Key__ __Concepts__<br> - Kernel Optimization<br> - Loop reorder to improve II<br>__Keywords__<br> - #pragma HLS PIPELINE<br> - #pragma HLS ARRAY_PARTITION
[kernel_opt/loop_reorder_ocl/][]|This is a simple example of matrix multiplication (Row x Col) to demonstrate how to achieve better pipeline II factor by loop reordering.|__Key__ __Concepts__<br> - Kernel Optimization<br> - Loop reorder to improve II<br>__Keywords__<br> - xcl_pipeline_loop<br> - xcl_array_partition(complete, 2)
[kernel_opt/shift_register_ocl/][]|This example demonstrates how to shift values in registers in each clock cycle|__Key__ __Concepts__<br> - Kernel Optimization<br> - Shift Register<br> - FIR<br>__Keywords__<br> - xcl_array_partition
[kernel_opt/systolic_array_c/][]|This is a simple example of matrix multiplication (Row x Col) to help developers learn systolic array based algorithm design. Note : Systolic array based algorithm design is well suited for FPGA.|
[kernel_opt/systolic_array_ocl/][]|This is a simple example of matrix multiplication (Row x Col) to help developers learn systolic array based algorithm design. Note: Systolic array based algorithm design is well suited for FPGA.|
[dataflow/dataflow_func_ocl/][]|This is simple example of vector addition to demonstrate Dataflow functionality in OpenCL Kernel. OpenCL Dataflow allows user to run multiple functions together to achieve higher throughput.|__Key__ __Concepts__<br> - Function/Task Level Parallelism<br>__Keywords__<br> - xcl_dataflow<br> - xclDataflowFifoDepth
[dataflow/dataflow_loop_c/][]|This is simple example of vector addition to demonstrate Loops Dataflow functionality of HLS. HLS Dataflow allows user to schedule multiple sequential loops concurrently to achieve higher throughput.|__Key__ __Concepts__<br> - Loop Dataflow<br>__Keywords__<br> - dataflow<br> - hls::stream<>
[dataflow/dataflow_pipes_ocl/][]|This is simple example of vector addition to demonstrate OpenCL Pipe Memory usage. OpenCL PIPE memory functionality allows user to achieve kernel-to-kernel data transfer without using global memory.|__Key__ __Concepts__<br> - Dataflow<br> - kernel to kernel pipes<br>__Keywords__<br> - pipe<br> - xcl_reqd_pipe_depth<br> - read_pipe_block()<br> - write_pipe_block()
[dataflow/dataflow_stream_array_c/][]|This is simple example of Multiple Stages Vector Addition to demonstrate Array of Stream usage in HLS C Kernel Code.|__Key__ __Concepts__<br> - Array of Stream<br>__Keywords__<br> - dataflow<br> - hls::stream<>
[dataflow/dataflow_stream_c/][]|This is simple example of vector addition to demonstrate Dataflow functionality of HLS. HLS Dataflow allows user to schedule multiple task together to achieve higher throughput.|__Key__ __Concepts__<br> - Task Level Parallelism<br>__Keywords__<br> - dataflow<br> - hls::stream<>
[clk_freq/large_loop_c/][]|This is a CNN (Convolutional Neural Network) based example which mainly focuses on Convolution operation of a CNN network. The goal of this example is to demonstrate a method to overcome kernel design timing failure issue. It also presents the effectiveness of using multiple compute units to improve performance.|__Key__ __Concepts__<br> - Clock Frequency<br> - Multiple Compute Units<br> - Convolutional Neural Networks<br>__Keywords__<br> - #pragma HLS ARRAY_PARTITION<br> - #pragma HLS PIPELINE
[clk_freq/large_loop_ocl/][]|This is a CNN (Convolutional Neural Network) based example which mainly focuses on Convolution operation of a CNN network. The goal of this example is to demonstrate a method to overcome kernel design timing failure issue. It also presents the effectiveness of using multiple compute units to improve performance.|__Key__ __Concepts__<br> - Clock Frequency<br> - Multiple Compute Units<br> - Convolutional Neural Networks<br>__Keywords__<br> - xcl_array_partition<br> - xcl_pipeline_loop
[clk_freq/split_kernel_c/][]|This is a multi-filter image processing application to showcase effectiveness of Dataflow/Streams usage. This examples is intended to help developers to break down the complex kernels into multiple sub-functions using HLS Dataflow/Streams. It presents a way to concurrently execute multiple functions with better area utilization compared to a complex single kernel implementation. The main objective of this example is to showcase a way to build a optimal FPGA design which achieves maximum frequency with optimal resource utilization and achieves better performance compared to single complex kernel implementations.|__Key__ __Concepts__<br> - Dataflow<br> - Stream<br>__Keywords__<br> - #pragma HLS DATAFLOW<br> - hls::stream<br> - #pragma HLS INLINE<br> - #pragma HLS ARRAY_PARTITION<br> - #pragma HLS PIPELINE
[clk_freq/split_kernel_ocl/][]|This is a multi-filter image processing application to showcase effectiveness of Dataflow/Streams usage. This examples is intended to help developers to break down the complex kernel into multiple sub-functions using OpenCL Dataflow. It presents a way to concurrently execute multiple functions with better area utilization compared to a complex single kernel implementation. The main objective of this example is to showcase a way to build a optimal FPGA design which achieves maximum frequency with optimal resource utilization and achieves better performance compared to single kernel implementations.|__Key__ __Concepts__<br> - Dataflow<br> - Stream<br>__Keywords__<br> - xcl_dataflow<br> - xcl_array_partition<br> - xcl_pipeline_loop
[clk_freq/too_many_cu_c/][]|This is simple example of vector addition to demonstrate effectiveness of using single compute unit with heavy work load to achieve better performance. Bad example uses multiple compute units to achieve good performance but it results in heavy usage of FPGA resources and area due to which design fails timing. Good example uses single compute unit to compute with heavier work load, it helps in less resource utilization and also helps in kernel scalability. To switch between Good/Bad cases use the flag provided in makefile.|__Key__ __Concepts__<br> - Clock Frequency<br> - Data Level Parallelism<br> - Multiple Compute Units<br>__Keywords__<br> - #pragma HLS PIPELINE<br> - #pragma HLS ARRAY_PARTITION
[clk_freq/too_many_cu_ocl/][]|This is simple example of vector addition to demonstrate effectiveness of using single compute unit with heavy work load to achieve better performance. Bad example uses multiple compute units to achieve good performance but it results in heavy usage of FPGA resources and area due to which design fails timing. Good example uses single compute unit to compute with heavier work load, it helps in less resource utilization and also helps in kernel scalability. To switch between Good/Bad cases use the flag provided in makefile.|__Key__ __Concepts__<br> - Clock Frequency<br> - Data Level Parallelism<br> - Multiple Compute Units<br>__Keywords__<br> - xcl_array_partition(complete, 1)<br> - xcl_pipeline_loop
[debug/debug_printf_ocl/][]|This is simple example of vector addition and printing of data that is computational result (addition). It is based on vectored addition that demonstrates printing of work item data (integer product in this case)|__Key__ __Concepts__<br> - Use of print statements for debugging<br>__Keywords__<br> - printf<br> - param:compiler.enableAutoPipelining=false
[debug/debug_profile_ocl/][]|This is simple example of vector addition and printing profile data (wall clock time taken between start and stop). It also dump a waveform file which can be reloaded to vivado to see the waveform. Run command 'vivado -source ./scripts/open_waveform.tcl -tclargs <device_name>-<kernel_name>.<target>.<device_name>.wdb' to launch waveform viewer. User can also update batch to gui in sdaccel.ini file to see the live waveform while running application.|__Key__ __Concepts__<br> - Use of Profile API<br> - Waveform Dumping and loading<br>__Keywords__<br> - xcl_get_event_duration()
[rtl_kernel/rtl_adder_pipes/][]|This example shows an adder with pipes using 3 RTL kernels.|__Key__ __Concepts__<br> - RTL Kernel<br> - Multiple RTL Kernels<br>
[rtl_kernel/rtl_vadd/][]|Simple example of vector addition using RTL Kernel|__Key__ __Concepts__<br> - RTL Kernel<br>
[rtl_kernel/rtl_vadd_2clks/][]|This example shows vector addition with 2 kernel clocks using RTL Kernel. Design contains two compute units of kernel. One compute unit is running at 150MHz and another compute unit is running at 250MHz.|__Key__ __Concepts__<br> - RTL Kernel<br> - Multiple Kernel Clocks<br>__Keywords__<br> - --kernel_frequency
[basic/hello/][]|The hello world example is a simple design which tests the correct installation of the FPGA acceleration boards. The example uses the printf function call inside of the kernel code to report on the values provided from the host to the kernel.|
[basic/host_global_bandwidth/][]|Host to global memory bandwidth test|
[basic/kernel_global_bandwidth/][]|Bandwidth test of global to local memory.|
[basic/sum_scan/][]|Example of parallel prefix sum|
[basic/vadd/][]|Simple example of vector addition.|
[basic/vdotprod/][]|Simple example of vector dot-product.|
[basic/vmul_vadd/][]|This example shows how data stored in global memory can be shared between kernels in different binary containers. This functionality is available only for non-XPR Devices.|__Key__ __Concepts__<br> - Multiple Kernel Binaries<br> - Buffer sharing across Multiple binaries<br> - Multiple Kernels in different Binaries<br>__Keywords__<br> - NA
[basic/vmul_vadd_xpr/][]|This example shows how data stored in global memory should be migrated from device to host and later from host to device to share between kernels in different binary containers. This buffer migration is only needed for XPR(Extended Partial Reconfiguration) Specific Devices. As XPR devices do not persist data when user reload another binary container.|__Key__ __Concepts__<br> - Handling Buffer sharing across multiple binaries for XPR Platform<br> - Multiple Kernel Binaries<br> - Buffer sharing across Multiple binaries<br>__Keywords__<br> - clEnqueueMigrateMemObjects()<br> - CL_MIGRATE_MEM_OBJECT_HOST

[host]:host
[host/concurrent_kernel_execution_ocl/]:host/concurrent_kernel_execution_ocl/
[host/data_transfer_ocl/]:host/data_transfer_ocl/
[host/device_query_ocl/]:host/device_query_ocl/
[host/errors_ocl/]:host/errors_ocl/
[host/helloworld_ocl/]:host/helloworld_ocl/
[host/multiple_devices_ocl/]:host/multiple_devices_ocl/
[host/overlap_ocl/]:host/overlap_ocl/
[host/copy_buffer_ocl/]:host/copy_buffer_ocl/
[kernel_to_gmem]:kernel_to_gmem
[kernel_to_gmem/burst_rw_c/]:kernel_to_gmem/burst_rw_c/
[kernel_to_gmem/burst_rw_ocl/]:kernel_to_gmem/burst_rw_ocl/
[kernel_to_gmem/custom_datatype_c/]:kernel_to_gmem/custom_datatype_c/
[kernel_to_gmem/custom_datatype_ocl/]:kernel_to_gmem/custom_datatype_ocl/
[kernel_to_gmem/full_array_2d_c/]:kernel_to_gmem/full_array_2d_c/
[kernel_to_gmem/full_array_2d_ocl/]:kernel_to_gmem/full_array_2d_ocl/
[kernel_to_gmem/gmem_2banks_c/]:kernel_to_gmem/gmem_2banks_c/
[kernel_to_gmem/gmem_2banks_ocl/]:kernel_to_gmem/gmem_2banks_ocl/
[kernel_to_gmem/row_array_2d_c/]:kernel_to_gmem/row_array_2d_c/
[kernel_to_gmem/row_array_2d_ocl/]:kernel_to_gmem/row_array_2d_ocl/
[kernel_to_gmem/wide_mem_rw_c/]:kernel_to_gmem/wide_mem_rw_c/
[kernel_to_gmem/wide_mem_rw_ocl/]:kernel_to_gmem/wide_mem_rw_ocl/
[kernel_to_gmem/window_array_2d_c/]:kernel_to_gmem/window_array_2d_c/
[kernel_to_gmem/window_array_2d_ocl/]:kernel_to_gmem/window_array_2d_ocl/
[kernel_to_gmem/memcoalesce_hang_c/]:kernel_to_gmem/memcoalesce_hang_c/
[kernel_opt]:kernel_opt
[kernel_opt/aos_vs_soa_ocl/]:kernel_opt/aos_vs_soa_ocl/
[kernel_opt/array_partition_ocl/]:kernel_opt/array_partition_ocl/
[kernel_opt/dependence_inter_c/]:kernel_opt/dependence_inter_c/
[kernel_opt/lmem_2rw_c/]:kernel_opt/lmem_2rw_c/
[kernel_opt/lmem_2rw_ocl/]:kernel_opt/lmem_2rw_ocl/
[kernel_opt/loop_fusion_ocl/]:kernel_opt/loop_fusion_ocl/
[kernel_opt/loop_perfect_c/]:kernel_opt/loop_perfect_c/
[kernel_opt/loop_perfect_ocl/]:kernel_opt/loop_perfect_ocl/
[kernel_opt/loop_pipeline_ocl/]:kernel_opt/loop_pipeline_ocl/
[kernel_opt/loop_reorder_c/]:kernel_opt/loop_reorder_c/
[kernel_opt/loop_reorder_ocl/]:kernel_opt/loop_reorder_ocl/
[kernel_opt/shift_register_ocl/]:kernel_opt/shift_register_ocl/
[kernel_opt/systolic_array_c/]:kernel_opt/systolic_array_c/
[kernel_opt/systolic_array_ocl/]:kernel_opt/systolic_array_ocl/
[dataflow]:dataflow
[dataflow/dataflow_func_ocl/]:dataflow/dataflow_func_ocl/
[dataflow/dataflow_loop_c/]:dataflow/dataflow_loop_c/
[dataflow/dataflow_pipes_ocl/]:dataflow/dataflow_pipes_ocl/
[dataflow/dataflow_stream_array_c/]:dataflow/dataflow_stream_array_c/
[dataflow/dataflow_stream_c/]:dataflow/dataflow_stream_c/
[clk_freq]:clk_freq
[clk_freq/large_loop_c/]:clk_freq/large_loop_c/
[clk_freq/large_loop_ocl/]:clk_freq/large_loop_ocl/
[clk_freq/split_kernel_c/]:clk_freq/split_kernel_c/
[clk_freq/split_kernel_ocl/]:clk_freq/split_kernel_ocl/
[clk_freq/too_many_cu_c/]:clk_freq/too_many_cu_c/
[clk_freq/too_many_cu_ocl/]:clk_freq/too_many_cu_ocl/
[debug]:debug
[debug/debug_printf_ocl/]:debug/debug_printf_ocl/
[debug/debug_profile_ocl/]:debug/debug_profile_ocl/
[rtl_kernel]:rtl_kernel
[rtl_kernel/rtl_adder_pipes/]:rtl_kernel/rtl_adder_pipes/
[rtl_kernel/rtl_vadd/]:rtl_kernel/rtl_vadd/
[rtl_kernel/rtl_vadd_2clks/]:rtl_kernel/rtl_vadd_2clks/
[basic]:basic
[basic/hello/]:basic/hello/
[basic/host_global_bandwidth/]:basic/host_global_bandwidth/
[basic/kernel_global_bandwidth/]:basic/kernel_global_bandwidth/
[basic/sum_scan/]:basic/sum_scan/
[basic/vadd/]:basic/vadd/
[basic/vdotprod/]:basic/vdotprod/
[basic/vmul_vadd/]:basic/vmul_vadd/
[basic/vmul_vadd_xpr/]:basic/vmul_vadd_xpr/

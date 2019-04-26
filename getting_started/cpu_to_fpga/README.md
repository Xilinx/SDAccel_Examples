CPU to FPGA Examples
==================================
Labs to showcase the cpu to fpga conversion with kernel optimizations.

 __Examples Table__ 

Example        | Description           | Key Concepts / Keywords 
---------------|-----------------------|-------------------------
[00_cpu/][]|This is a simple example of matrix multiplication (Row x Col).|
[01_kernel_c/][]|This is a simple example of HLS matrix multiplication (Row x Col).|__Key__ __Concepts__<br> - OpenCL APIs<br>
[02_local_mem_c/][]|This is a simple example of matrix multiplication (Row x Col) to demonstrate how to reduce number of memory accesses using local memory.|__Key__ __Concepts__<br> - Kernel Optimization<br> - Local Memory<br>
[03_burst_rw_c/][]|This is a simple example of matrix multiplication (Row x Col) to demonstrate how to achieve better pipeline with burst read and write to/from local memory from/to DDR.|__Key__ __Concepts__<br> - Kernel Optimization<br> - Burst Read/Write<br>
[04_partition_c/][]|This is a simple example of matrix multiplication (Row x Col) to demonstrate how to achieve better performance by array partitioning and loop unrolling.|__Key__ __Concepts__<br> - Array Partition<br> - Loop Unroll<br>__Keywords__<br> - pragma HLS PIPELINE<br> - pragma HLS ARRAY_PARTITION complete<br> - pragma HLS UNROLL

[.]:.
[00_cpu/]:00_cpu/
[01_kernel_c/]:01_kernel_c/
[02_local_mem_c/]:02_local_mem_c/
[03_burst_rw_c/]:03_burst_rw_c/
[04_partition_c/]:04_partition_c/

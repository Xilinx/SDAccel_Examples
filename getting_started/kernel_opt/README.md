Kernel Optimization Examples
==================================
Kernel Optimization for performance

 __Examples Table__ 

Example        | Description           | Key Concepts / Keywords 
---------------|-----------------------|-------------------------
[dependence_inter_c/][]|"This Example to demostrate OpenCL xcl_dependence attribute. Using xcl_dependence user can provide additional dependency details to compiler which allow compiler to perform unrolling/pipelining to get better performance."|__Key__ __Concepts__<br> - Inter Dependence<br>__Keywords__<br> - DEPENDENCE<br> - inter
[lmem_2rw_c/][]|"This is simple example of vector addition to demonstrate how to utilized both ports of Local Memory memory."|__Key__ __Concepts__<br> - Kernel Optimization<br> - 2port BRAM Utilization<br> - two read/write Local Memory<br>__Keywords__<br> - #pragma HLS UNROLL FACTOR=2
[lmem_2rw_ocl/][]|"This is simple example of vector addition to demonstrate how to utilized both ports of Local Memory."|__Key__ __Concepts__<br> - Kernel Optimization<br> - 2port BRAM Utilization<br> - two read/write Local Memory<br>__Keywords__<br> - opencl_unroll_hint(2)
[loop_reorder_c/][]|"This is a simple example of matrix multiplication (Row x Col) to demonstrate how to achieve better pipeline II factor by loop reordering."|__Key__ __Concepts__<br> - Kernel Optimization<br> - Loop reorder to improve II<br>__Keywords__<br> - #pragma HLS PIPELINE<br> - #pragma HLS ARRAY_PARTITION
[loop_reorder_ocl/][]|"This is a simple example of matrix multiplication (Row x Col) to demonstrate how to achieve better pipeline II factor by loop reordering."|__Key__ __Concepts__<br> - Kernel Optimization<br> - Loop reorder to improve II<br>__Keywords__<br> - xcl_pipeline_loop<br> - xcl_array_partition(complete, 2)

[.]:.
[dependence_inter_c/]:dependence_inter_c/
[lmem_2rw_c/]:lmem_2rw_c/
[lmem_2rw_ocl/]:lmem_2rw_ocl/
[loop_reorder_c/]:loop_reorder_c/
[loop_reorder_ocl/]:loop_reorder_ocl/

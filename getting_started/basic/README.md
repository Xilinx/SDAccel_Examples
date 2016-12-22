Basic Examples
==================================
OpenCL Basic Examples

 __Examples Table__ 

Example        | Description           | Key Concepts / Keywords 
---------------|-----------------------|-------------------------
[hello/][]|"The hello world example is a simple design which tests the correct installation of the FPGA acceleration boards. The example uses the printf function call inside of the kernel code to report on the values provided from the host to the kernel."|
[host_global_bandwidth/][]|"Host to global memory bandwidth test"|
[kernel_global_bandwidth/][]|"Bandwidth test of global to local memory"|
[sum_scan/][]|"Example of parallel prefix sum"|
[vadd/][]|"Simple example of vector addition."|
[vdotprod/][]|"Simple example of vector dot-product."|
[vmul_vadd/][]|"This example shows how data stored in global memory can be shared between kernels in different binary containers. This functionality is available only for non-XPR Devices."|__Key__ __Concepts__<br> - Multiple Kernel Binaries<br> - Buffer sharing across Multiple binaries<br> - Multiple Kernels in different Binaries<br>__Keywords__<br> - NA
[vmul_vadd_xpr/][]|"This example shows how data stored in global memory should be migrated from device to host and later from host to device to share between kernels in different binary containers. This buffer migration is only needed for XPR(Extended Partial Reconfiguration) Specific Devices. As XPR devices do not persist data when user reload another binary container."|__Key__ __Concepts__<br> - Handling Buffer sharing across multiple binaries for XPR Platform<br> - Multiple Kernel Binaries<br> - Buffer sharing across Multiple binaries<br>__Keywords__<br> - clEnqueueMigrateMemObjects()<br> - CL_MIGRATE_MEM_OBJECT_HOST

[.]:.
[hello/]:hello/
[host_global_bandwidth/]:host_global_bandwidth/
[kernel_global_bandwidth/]:kernel_global_bandwidth/
[sum_scan/]:sum_scan/
[vadd/]:vadd/
[vdotprod/]:vdotprod/
[vmul_vadd/]:vmul_vadd/
[vmul_vadd_xpr/]:vmul_vadd_xpr/

Vector Multiplication Addition Example
===============================

This example shows how data can in DDR can be shared between kernels in
different binary containers.

This example is targeting the Alpha Data ADM-PCIe-7v3 card.

Changelog
----------
2/1/2016 - Initial Release

Compiling the Application
---------------------------
This application is compiled using the SDAccel script mode.
To compile the application:

```
sdaccel vadd_vmul.tcl
```
The target board can be changed by editing *vadd_vmul.tcl*

Executing the Application
---------------------------
```
vector_mult_add.exe bin_vmul.xclbin bin_vadd.xclbin
```

Files in the Example
---------------------
Application host code
- main.c

Kernel code
- krnl_vadd.cl
- krnl_vmul.cl

Compilation Script
- vadd_vmul.tcl

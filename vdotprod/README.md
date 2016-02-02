Vector Dot-Product Example
===============================

This is a simple example of vector dotproduct operation.
The purpose of this code is to introduce the user to application development
in SDAccel.

This example is targeting the Alpha Data ADM-PCIe-7v3 card. 

Changelog
----------
1/28/2016 - Initial Release

Compiling the Application
---------------------------
This application is compiled using the SDAccel script mode.
To compile the application:

```
sdaccel vdotprod.tcl
```
The target board can be changed by editing *vdotprod.tcl*

Executing the Application
---------------------------
```
vector_dotproduct.exe bin_vdotprod.xclbin
```

Files in the Example
---------------------
Application host code
- vdotprod.cpp
- vdotprod.h
- xcl.cpp
- xcl.h

Kernel code
- krnl_vdotprod.cl

Compilation Script
- vdotprod.tcl

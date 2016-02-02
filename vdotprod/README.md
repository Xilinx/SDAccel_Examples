Vector Addition Example
===============================

This is a simple example of vector addition.
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
sdaccel vadd.tcl
```
The target board can be changed by editing *vadd.tcl*

Executing the Application
---------------------------
```
vector_addition.exe bin_vadd.xclbin
```

Files in the Example
---------------------
Application host code
- vadd.cpp
- vadd.h
- xcl.c
- xcl.h

Kernel code
- krnl_vadd.cl

Compilation Script
- vadd.tcl

Hello Example
===============================

This example introduces the usage of printf calls inside of kernel code.
The purpose of this code is to introduce the user to application development
in SDAccel.

This example is targeting the Alpha Data ADM-PCIe-7v3 card.

Changelog
----------
2/2/2016 - Initial Release

Compiling the Application
---------------------------
This application is compiled using the SDAccel script mode.
To compile the application:

```
sdaccel hello.tcl
```
The target board can be changed by editing *hello.tcl*

Executing the Application
---------------------------
```
hello_app.exe bin_hello.xclbin
```

Files in the Example
---------------------
Application host code
- hello.cpp
- hello.h
- xcl.c
- xcl.h

Kernel code
- krnl_hello.cl

Compilation Script
- hello.tcl

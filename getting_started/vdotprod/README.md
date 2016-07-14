Vector Dot-Product Example
===============================

This is a simple example of vector dotproduct operation.
The purpose of this code is to introduce the user to application development
in SDAccel.

This example is targeting the Alpha Data ADM-PCIe-7v3 card.

Changelog
----------
1/28/2016 - Initial Release
7/5/2016  - Conversion to Makefile based execution

Compiling the Application
---------------------------
This application is compiled using the SDAccel Makefile flow

To compile the application for execution on x86 servers/cloud:

```
make all
```

To compile the application for execution on POWER8 servers/cloud:
```
make sv_all
```

The target board and platforms are available in the utility/boards.mk file. The utility directory is located at the root of this repository.

Executing the Application
---------------------------
```
vdotprod.exe krnl_vdotprod.<flow>.<target device>.xclbin
```

Files in the Example
---------------------
Application code is located in the src directory.
Accelerator binary files are located in the xclbin directory. This directory is required by the Makefile. The contents of the directory are generated during compilation.

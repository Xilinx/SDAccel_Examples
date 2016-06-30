Hello Example
===============================

This example introduces the usage of printf calls inside of kernel code.
The purpose of this code is to introduce the user to application development
in SDAccel.

This example is targeting the Alpha Data ADM-PCIe-7v3 card.

Changelog
----------
2/2/2016 - Initial Release
6/30/2016 - Conversion to Makefile based execution

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
hello_app.exe bin_hello.xclbin
```

Files in the Example
---------------------
Application code is located in the src directory.
Accelerator binary files are located in the xclbin directory. This directory is required by the Makefile. The contents of the directory are generated during compilation.

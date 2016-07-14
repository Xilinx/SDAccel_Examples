Vector Multiplication Addition Example
===============================

This example shows how data can in DDR can be shared between kernels in
different binary containers.

This example is targeting the Alpha Data ADM-PCIe-7v3 card.

Changelog
----------
2/1/2016 - Initial Release
7/14/2016 - Conversion to Makefile based execution

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
vmulvadd.exe krnl_vmul.<flow>.<target device>.xclbin krnl_vadd.<flow>.<target device>.xclbin

```

Files in the Example
---------------------
Application code is located in the src directory.
Accelerator binary files are located in the xclbin directory. This directory is required by the Makefile. The contents of the directory are generated during compilation.

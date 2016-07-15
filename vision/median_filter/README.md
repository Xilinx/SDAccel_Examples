median filter Example
===============================

This is an optimized implementation of a median filter being used to remove noise in images
targeting execution on an SDAccel supported FPGA acceleration card.

The main algorithm characteristics of this application are
1. 3x3 median filter
2. Input image size of 128 x 128
3. Achieved performance = 0.045ms on image size 128x128

Achieved performance was measured on an Alpha Data ADM-PCI-7v3 card.

Changelog
----------
1/27/2016 - Initial Release
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
medianFilter_example.exe data/inputImage.bmp medianFilter.xclbin
```

Files in the Example
---------------------
Application code is located in the src directory.
Accelerator binary files are located in the xclbin directory. This directory is required by the Makefile. The contents of the directory are generated during compilation.

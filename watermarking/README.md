watermarking Example
===============================

This is an optimized implementation of a watermarking application to add watermarking to images
targeting execution on an SDAccel supported FPGA acceleration card.

The main algorithm characteristics of this application are
1. watermarking windown 10x10
2. Input image size of 64x64
3. Achieved performance = 0.163ms on image size 64x64

Achieved performance was measured on an Alpha Data ADM-PCI-7v3 card.

Changelog
----------
1/27/2016 - Initial Release

Compiling the Application
---------------------------
This application is compiled using the SDAccel script mode.
To compile the application:

```
sdaccel watermarking.tcl
```
The target board can be changed by editing *watermarking.tcl*

Executing the Application
---------------------------
```
watermarking_example.exe data/inputImage.bmp watermarking.xclbin 
```

Files in the Example
---------------------
Example data
- data/inputImage.bmp

Application host code
- watermarking.cpp
- oclErrorCodes.cpp
- bitmap.cpp
- oclHelper.cpp
- oclHelper.h
- bitmap.h

Kernel code
- krnl_watermarking.cl

Compilation Script
- watermarking.tcl

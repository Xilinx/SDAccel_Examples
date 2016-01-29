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

Compiling the Application
---------------------------
This application is compiled using the SDAccel script mode.
To compile the application:

```
sdaccel medianFilter.tcl
```
The target board can be changed by editing *medianFilter.tcl*

Executing the Application
---------------------------
```
medianFilter_example.exe data/inputImage.bmp medianFilter.xclbin 
```

Files in the Example
---------------------
Example data
- data/inputImage.bmp

Application host code
- medianFilter.cpp
- oclErrorCodes.cpp
- bitmap.cpp
- oclHelper.cpp
- oclHelper.h
- bitmap.h

Kernel code
- krnl_medianFilter.cl

Compilation Script
- medianFilter.tcl

Tiny Encryption Algorithm Example
===============================

This is an optimized implementation of a tiny encryption algorithm
targeting execution on an SDAccel supported FPGA acceleration card.

The main algorithm characteristics of this application are
1. uses 128-bit key to operate on two unsigned 32-bit integers
2. Achieved performance = 1.569ms on image size 128x128

Achieved performance was measured on an Alpha Data ADM-PCI-7v3 card.

Changelog
----------
1/27/2016 - Initial Release

Compiling the Application
---------------------------
This application is compiled using the SDAccel script mode.
To compile the application:

```
sdaccel tinyEncryption.tcl
```
The target board can be changed by editing *tinyEncryption.tcl*

Executing the Application
---------------------------
```
tinyEncryption_example.exe data/image1.bmp data/image2.bmp tinyEncryption.xclbin 
```

Files in the Example
---------------------
Example data
- data/image1.bmp
- data/image2.bmp

Application host code
- tinyEncryption.cpp
- oclErrorCodes.cpp
- bitmap.cpp
- oclHelper.cpp
- oclHelper.h
- bitmap.h

Kernel code
- krnl_tinyEncryption.cl

Compilation Script
- tinyEncryption.tcl

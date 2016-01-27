Histogram Equalization Example
===============================

This is an optimized implementation of a 12-bit histogram equalizer
targeting execution on an SDAccel supported FPGA acceleration card.

The main algorithm characteristics of this application are
1. 12-bit grayscale histrogram depth
2. Input image size of 2048 x 1080
3. Target performance = 120 frames / second
4. Achieved performance = 333 frames / second

Achieved performance was measured on an Alpha Data ADM-PCI-7v3 card.

Changelog
----------
1/27/2016 - Initial Release

Compiling the Application
---------------------------
This application is compiled using the SDAccel script mode.
To compile the application:

```
sdaccel equalizer.tcl
```
The target board can be changed by editing *equalizer.tcl*

Executing the Application
---------------------------
```
histogram_example.exe bin_equalizer.xclbin data/race_2k.bmp
```

Files in the Example
---------------------
Example data
- data/race_2k.bmp

Application host code
- equalizer.cpp
- equalizer.h
- xcl.c
- xcl.h

Kernel code
- krnl_equalizer.cl

Compilation Script
- equalizer.tcl

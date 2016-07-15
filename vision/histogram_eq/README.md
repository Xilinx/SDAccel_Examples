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
histogram_example.exe bin_equalizer.xclbin data/race_2k.bmp
```

Files in the Example
---------------------
Application code is located in the src directory.
Accelerator binary files are located in the xclbin directory. This directory is required by the Makefile. The contents of the directory are generated during compilation.

Edge Detection Example
===============================

This is an optimized implementation of a Sobel Filter for edge detection.


Achieved performance was measured on an Alpha Data ADM-PCI-ku3 card.
Average roundtrip time per image is 250 (ms).

Output
----------
![alt tag](https://raw.gitenterprise.xilinx.com/SDx-Hub/apps/master/edge_detection/data/input/lola.bmp)
![alt tag](https://raw.gitenterprise.xilinx.com/SDx-Hub/apps/master/edge_detection/data/output/lola.bmp)

Changelog
----------
1/29/2016 - Initial Release
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
edgedetection_example.exe --platform Xilinx --device xilinx:adm-pcie-ku3:2ddr:2.1 --kernel bin_sobelfilter.xclbin data/lola.bmp
```

Files in the Example
---------------------
Application code is located in the src directory.
Accelerator binary files are located in the xclbin directory. This directory is required by the Makefile. The contents of the directory are generated during compilation.

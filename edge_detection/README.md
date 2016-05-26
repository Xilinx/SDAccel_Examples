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

Compiling the Application
---------------------------
This application is compiled using the SDAccel script mode.
To compile the application:

```
sdaccel edge_detection_ku3_dsa2.1.tcl
```
The target board can be changed by editing *edge_detection.tcl*

Executing the Application
---------------------------
```
edgedetection_example.exe --platform Xilinx --device fpga0 --kernel bin_sobelfilter.xclbin data/lola.bmp
```

Files in the Example
---------------------
Example data
- data/lola.bmp
- data/vase.bmp
- data/eiffel.bmp

Application host code
- edgedetection_app.cpp
- edgedetection_app.h
- sobel_cpuonly.cpp
- sobel_cpuonly.h
- main.cpp
- common/xcl.cpp
- common/xcl.h
- common/logger.cpp
- common/logger.h
- common/cmdlineparser.cpp
- common/cmdlineparser.h
- common/simplebmp.cpp
- common/simplebmp.h

Kernel code
- krnl_sobelfilter_pipelined_asyncmem.cl

Compilation Script
- edge_detection_ku3_dsa2.1.tcl

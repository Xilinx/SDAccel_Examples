SHA1 Example
===============================

This is an optimized implementation of SHA1 secure hash algorithm targeting 
execution on an SDAccel supported FPGA acceleration card. 

Achieved performance was measured on an Alpha Data ADM-PCI-7v3 card.

Changelog
----------
1/29/2016 - Initial Release

Compiling the Application
---------------------------
This application is compiled using the SDAccel script mode.
To compile the application:

```
sdaccel sha1.tcl
```
The target board can be changed by editing *sha1.tcl*

Executing the Application
---------------------------
```
sha1_example.exe --platform Xilinx --device fpga0 --kernel bin_sha1.xclbin
```

Files in the Example
---------------------

Application host code
- sha1_app.cpp
- sha1_app.h
- sha1.c
- sha1.h
- main.cpp
- common/xcl.cpp
- common/xcl.h
- common/logger.cpp
- common/logger.h
- common/cmdlineparser.cpp
- common/cmdlineparser.h

Kernel code
- krnl_sha1.cl

Compilation Script
- sha1.tcl

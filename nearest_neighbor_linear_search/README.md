Nearest Neighbor Linear Search Example
===============================

This is an optimized implementation of a nearest neighbor linear search
algorithm targeting execution on a SDAccel supported FPGA acceleration card.
The main algorithm characteristics of this application are

1. 256 distance measurements per cycle (compile time configurable)
2. Achieved performance = 37.5 Gigameasurements / second <sup>1</sup>

<sup>1</sup> This is an O(n<sup>2</sup>) algorithm the measurement is the value of n .

Achieved performance was measured on an Alpha Data ADM-PCI-7v3 card.

Changelog
----------
1/28/2016 - Initial Release

Compiling the Application
---------------------------
This application is compiled using the SDAccel script mode.
To compile the application:

```
sdaccel linear_search.tcl
```

The target board can be changed by editing *linear_search.tcl*

Executing the Application
---------------------------
```
./linear_search.tcl bin_linear_search.xclbin queries.txt queries.txt
```

Files in the Example
---------------------
Example data
- queries.txt

Application host code
- linear_search.c
- linear_search.h
- xcl.c
- xcl.h

Kernel code
- krnl_linear_search.cpp

Compilation Script
- Makefile
- linear_search.tcl

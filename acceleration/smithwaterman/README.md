Smithwaterman Example
===============================

This is an optimized implementation of the smithwaterman algorithm
targeting execution on an SDAccel supported FPGA acceleration card.

The main algorithm characteristics of this application are

1. Compute MaxScore
2. Systolic array implementation
3. Target performance = 
4. Achieved performance = 

Achieved performance was measured on an Alpha Data ADM-PCI-7v3 card.

Changelog
----------
1/29/2016 - Initial Release

Compiling the Application
---------------------------
This application is compiled using the SDAccel script mode.
To compile the kernel:

```
sdaccel smithwaterman_hw_systolic.tcl
```

To compile the host:
```
./build_host.sh
```

The target board can be changed by editing *smithwaterman_hw_systolic.tcl*

Executing the Application
---------------------------
```
smithwaterman_host.exe --platform Xilinx --device fpga0 --kernel opencl_sw_maxscore.xclbin
```

Files in the Example
---------------------

Application host code
- genseq.cpp
- matcharray.cpp
- matcharray.h
- smithwaterman.cpp
- smithwaterman.h
- main.cpp

Kernel code
- src/opencl_sw_maxscore_basic.cpp
- src/opencl_sw_maxscore_systolic.cpp

Compilation Script
- smithwaterman_hw_systolic.tcl

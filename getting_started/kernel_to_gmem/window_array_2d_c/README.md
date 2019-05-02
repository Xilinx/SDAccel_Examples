Read/Write Window of 2D Array (C)
======================

This is a simple example of accessing each window of data from 2d array

***KEY CONCEPTS:*** window of 2D data array access

***KEYWORDS:*** #pragma HLS DATAFLOW, #pragma HLS PIPELINE, #pragma HLS stream

## SUPPORTED PLATFORMS
Board | Software Version
------|-----------------
Xilinx Alveo U200|SDx 2018.3
Xilinx Virtex UltraScale+ VCU1525|SDx 2018.3
Xilinx Alveo U250|SDx 2018.3


##  DESIGN FILES
Application code is located in the src directory. Accelerator binary files will be compiled to the xclbin directory. The xclbin directory is required by the Makefile and its contents will be filled during compilation. A listing of all the files in this example is shown below

```
src/host.cpp
src/host.h
src/window_array_2d.cpp
```

##  COMMAND LINE ARGUMENTS
Once the environment has been configured, the application can be executed by
```
./host <window_array_2d XCLBIN>
```


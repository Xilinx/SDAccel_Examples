Clock Frequency ~ Large Loop Count (C)
======================

This is a CNN (Convolutional Neural Network) based example which mainly focuses on Convolution operation of a CNN network. The goal of this example is to demonstrate a method to overcome kernel design timing failure issue. It also presents the effectiveness of using multiple compute units to improve performance.

***KEY CONCEPTS:*** Clock Frequency, Multiple Compute Units, Convolutional Neural Networks

***KEYWORDS:*** #pragma HLS ARRAY_PARTITION, #pragma HLS PIPELINE, #pragma HLS INLINE

## SUPPORTED PLATFORMS
Board | Software Version
------|-----------------
Xilinx Alveo U250|SDx 2018.3
Xilinx Alveo U200|SDx 2018.3
Xilinx Alveo U280 ES|SDx 2018.3
Xilinx Virtex UltraScale+ VCU1525|SDx 2018.3


##  DESIGN FILES
Application code is located in the src directory. Accelerator binary files will be compiled to the xclbin directory. The xclbin directory is required by the Makefile and its contents will be filled during compilation. A listing of all the files in this example is shown below

```
src/cnn_convolution.cpp
src/cnn_convolution_bad.cpp
src/defns.h
src/host.cpp
```

##  COMMAND LINE ARGUMENTS
Once the environment has been configured, the application can be executed by
```
./host <cnn_GOOD XCLBIN> <cnn_BAD XCLBIN>
```


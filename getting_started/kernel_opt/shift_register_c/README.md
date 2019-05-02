Shift Register (C)
======================

This example demonstrates how to shift values in registers in each clock cycle

***KEY CONCEPTS:*** Kernel Optimization, Shift Register, FIR

***KEYWORDS:*** #pragma HLS ARRAY_PARTITION

## SUPPORTED PLATFORMS
Board | Software Version
------|-----------------
Xilinx Alveo U200|SDx 2018.3
Xilinx Virtex UltraScale+ VCU1525|SDx 2018.3
Xilinx Alveo U250|SDx 2018.3


##  DESIGN FILES
Application code is located in the src directory. Accelerator binary files will be compiled to the xclbin directory. The xclbin directory is required by the Makefile and its contents will be filled during compilation. A listing of all the files in this example is shown below

```
src/fir_naive.cpp
src/fir_shift_register.cpp
src/host.cpp
```

##  COMMAND LINE ARGUMENTS
Once the environment has been configured, the application can be executed by
```
./host <fir XCLBIN>
```


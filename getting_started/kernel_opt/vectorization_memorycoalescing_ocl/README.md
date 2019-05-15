Vectorization (CL)
======================

This example is a simple OpenCL application which highlights the vectorization concept. It provides a basis for calculating the bandwidth utilization when the compiler looking to vectorize.

***KEY CONCEPTS:*** Vectorization, Memory Coalescing

***KEYWORDS:*** vec_type_hint

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
src/host.cpp
src/vector_addition.cl
```

##  COMMAND LINE ARGUMENTS
Once the environment has been configured, the application can be executed by
```
./host <vector_addition XCLBIN>
```


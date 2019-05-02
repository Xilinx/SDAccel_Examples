HBM Simple Vector Addition
======================

This is a simple example of vector addition to describe how to use HLS kernels with HBM (High Bandwidth Memory) for achieving high throughput.

***KEY CONCEPTS:*** SDx Memory Hierarchy, HBM Banks

***KEYWORDS:*** HBM

## SUPPORTED PLATFORMS
Board | Software Version
------|-----------------
Xilinx Alveo U280 ES|SDx 2018.3


##  DESIGN FILES
Application code is located in the src directory. Accelerator binary files will be compiled to the xclbin directory. The xclbin directory is required by the Makefile and its contents will be filled during compilation. A listing of all the files in this example is shown below

```
src/host.cpp
src/krnl_vadd.cpp
```

##  COMMAND LINE ARGUMENTS
Once the environment has been configured, the application can be executed by
```
./host <krnl_vadd XCLBIN>
```


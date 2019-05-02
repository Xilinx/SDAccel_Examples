Stream Access (C)
======================

This is a simple example that demonstrates on how to process an input stream of data for computation in an application. It shows how to perform asynchronous operations and event handling.

***KEY CONCEPTS:*** OpenCL API, Synchronize Host and FPGA, Asynchronous Processing, Events, Asynchronous Data Transfer

***KEYWORDS:*** cl::event, CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE

## SUPPORTED PLATFORMS
Board | Software Version
------|-----------------
Xilinx Alveo U200|SDx 2018.3
Xilinx Virtex UltraScale+ VCU1525|SDx 2018.3
Xilinx Alveo U250|SDx 2018.3


##  DESIGN FILES
Application code is located in the src directory. Accelerator binary files will be compiled to the xclbin directory. The xclbin directory is required by the Makefile and its contents will be filled during compilation. A listing of all the files in this example is shown below

```
data/input1.txt
data/input2.txt
src/host.cpp
src/vector_addition.cpp
```

##  COMMAND LINE ARGUMENTS
Once the environment has been configured, the application can be executed by
```
./stream_access <vector_addition XCLBIN> ./data/input1.txt ./data/input2.txt
```


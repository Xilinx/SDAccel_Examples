Data Transfer (C)
======================

This example illustrates several ways to use the OpenCL API to transfer data to and from the FPGA

***KEY CONCEPTS:*** OpenCL API, Data Transfer, Write Buffers, Read Buffers, Map Buffers, Async Memcpy

***KEYWORDS:*** enqueueWriteBuffer(), enqueueReadBuffer(), enqueueMapBuffer(), enqueueUnmapMemObject(), enqueueMigrateMemObjects()

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
src/dummy_kernel.cpp
src/host.cpp
```

##  COMMAND LINE ARGUMENTS
Once the environment has been configured, the application can be executed by
```
./data_transfer <dummy_kernel XCLBIN>
```


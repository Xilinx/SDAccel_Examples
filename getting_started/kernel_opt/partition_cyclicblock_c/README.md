Array Block and Cyclic Partitioning (C)
======================

This example shows how to use array block and cyclic partitioning to improve performance of a kernel

***KEY CONCEPTS:*** Kernel Optimization, Array Partitioning, Block Partition, Cyclic Partition

***KEYWORDS:*** #pragma HLS ARRAY_PARTITION, cyclic, block, factor, dim

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
src/matmul.cpp
src/matmul_partition.cpp
```

##  COMMAND LINE ARGUMENTS
Once the environment has been configured, the application can be executed by
```
./array_partition <matmul XCLBIN>
```


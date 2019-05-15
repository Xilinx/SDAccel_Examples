Clock Frequency ~ Too Many Compute Units (C) 
======================

This is simple example of vector addition to demonstrate effectiveness of using single compute unit with heavy work load to achieve better performance. Bad example uses multiple compute units to achieve good performance but it results in heavy usage of FPGA resources and area due to which design fails timing. Good example uses single compute unit to compute with heavier work load, it helps in less resource utilization and also helps in kernel scalability. To switch between Good/Bad cases use the flag provided in makefile.

***KEY CONCEPTS:*** Clock Frequency, Data Level Parallelism, Multiple Compute Units

***KEYWORDS:*** #pragma HLS PIPELINE, #pragma HLS ARRAY_PARTITION

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
src/vadd.cpp
src/vadd_bad.cpp
```

##  COMMAND LINE ARGUMENTS
Once the environment has been configured, the application can be executed by
```
./host <vadd_GOOD XCLBIN> <vadd_BAD XCLBIN>
```


Global Memory Two Banks (CL)
======================

This example of 2ddr to demonstrate on how to use 2ddr DSA. How to create buffers in each DDR.

***KEY CONCEPTS:*** Multiple Banks

***KEYWORDS:*** max_memory_ports, misc:map_connect, XCL_MEM_DDR_BANK0, XCL_MEM_DDR_BANK1, XCL_MEM_DDR_BANKx

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
data/golden.bmp
data/input.bmp
src/apply_watermark.cl
src/host.cpp
```

##  COMMAND LINE ARGUMENTS
Once the environment has been configured, the application can be executed by
```
./host <apply_watermark XCLBIN> ./data/input.bmp ./data/golden.bmp
```


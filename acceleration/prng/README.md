pseudo random number generator
======================

This is an optimized implementation of the pseudo random number generator algorithm
The method used to generate a random number sequence is called complementary multiply with carry (CMWC)
targeting exection on an SDAccel support FPGA acceleration card

### PERFORMANCE
Board|Total Number of Samples|Kernel Duration
-----|-----|-----
xilinx:adm-pcie-ku3:2ddr-xpr|16777216|59.1ms
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
src/dma.cpp
src/dma.h
src/prng.cpp
src/prng.h
```

##  COMMAND LINE ARGUMENTS
Once the environment has been configured, the application can be executed by
```
./prng <dma XCLBIN>
```


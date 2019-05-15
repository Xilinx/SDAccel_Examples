Histogram Equalization
======================

This is an optimized implementation of a 12-bit histogram equalizer targeting execution on an SDAccel supported FPGA acceleration card.

### PERFORMANCE
Board|Image Size|Frames per Second
-----|-----|-----
xilinx:adm-pcie-7v3:1ddr|2,048 x 1,080|333
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
data/race_2k.bmp
src/equalizer.cpp
src/equalizer.h
src/krnl_equalizer.cl
```

##  COMMAND LINE ARGUMENTS
Once the environment has been configured, the application can be executed by
```
./equalizer <krnl_equalizer XCLBIN> ./data/race_2k.bmp
```


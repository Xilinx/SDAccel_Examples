Nearest Neighbor Linear Search
======================

This is an optimized implementation of a nearest neighbor linear search algorithm targeting execution on a SDAccel supported FPGA acceleration card.

### PERFORMANCE
Board|Measurements per Cycle|Gigameasurements / Second
-----|-----|-----
xilinx:adm-pcie-ku3:2ddr-xpr|256|37.5
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
data/queries.txt
data/targets.txt
src/krnl_linear_search.cpp
src/linear_search.cpp
src/linear_search.h
```

##  COMMAND LINE ARGUMENTS
Once the environment has been configured, the application can be executed by
```
./nearest <krnl_nearest XCLBIN> ./data/queries.txt ./data/targets.txt
```


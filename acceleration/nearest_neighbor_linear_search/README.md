Nearest Neighbor Linear Search
======================

This is an optimized implementation of a nearest neighbor linear search algorithm targeting execution on a SDAccel supported FPGA acceleration card.

### PERFORMANCE
Board|Measurements per Cycle|Gigameasurements / Second
-----|-----|-----
xilinx:adm-pcie-ku3:2ddr-xpr|256|37.5
## SUPPORTED PLATFORMS
Platform | Board             | Software Version
---------|-------------------|-----------------
xilinx_u200_qdma|Xilinx Alveo U200|SDx 2019.1
xilinx_u50_xdma|Xilinx Alveo U50|SDx 2019.1
xilinx_u250_qdma|Xilinx Alveo U250|SDx 2019.1
xilinx_u200_xdma|Xilinx Alveo U200|SDx 2019.1
xilinx_u280_xdma|Xilinx Alveo U280|SDx 2019.1
xilinx_u250_xdma|Xilinx Alveo U250|SDx 2019.1


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


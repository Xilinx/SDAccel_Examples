Inverse Discrete Cosine Transform for 5.0 shell
======================

Example shows an optimized Inverse Discrete Cosine Transfom. Optimizations are applied to the kernel as well as the host code.

## SUPPORTED PLATFORMS
Platform | Board             | Software Version
---------|-------------------|-----------------
xilinx_u280_xdma|Xilinx Alveo U280|SDx 2019.1
xilinx_u250_qdma|Xilinx Alveo U250|SDx 2019.1


##  DESIGN FILES
Application code is located in the src directory. Accelerator binary files will be compiled to the xclbin directory. The xclbin directory is required by the Makefile and its contents will be filled during compilation. A listing of all the files in this example is shown below

```
src/hls_config.tcl
src/idct.cpp
src/krnl_idct.cpp
```

##  COMMAND LINE ARGUMENTS
Once the environment has been configured, the application can be executed by
```
./idct <krnl_idct XCLBIN>
```


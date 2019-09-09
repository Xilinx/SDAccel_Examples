Edge Detection
======================

Implementation of a Sobel Filter for edge detection.

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
data/input/CF000221.jpg
data/input/eiffel.bmp
data/input/lola.bmp
data/input/vase.bmp
data/output/lola.bmp
src/edge.cpp
src/edge.h
src/krnl_sobelfilter.cl
```

##  COMMAND LINE ARGUMENTS
***OpenCV for Example Applications***

This application requires OpenCV runtime libraries. If the host does not have OpenCV installed use the Xilinx included libraries with the following command:

`export LD_LIBRARY_PATH=$XILINX_SDX/lnx64/tools/opencv/:$LD_LIBRARY_PATH`

Once the environment has been configured, the application can be executed by
```
./edge <krnl_edge XCLBIN> ./data/input/eiffel.bmp
```


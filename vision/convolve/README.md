Convolve
======================

The convolve example is a performant design which showcases convolutional image filtering. The example processes the image 8 pixels at a time.

### PERFORMANCE
Board|Image Size|Frames / Second
-----|-----|-----
xilinx:adm-pcie-7v3:1ddr|1,024 x 1,024|1,000
xilinx:adm-pcie-ku3:2ddr-xpr|1,024 x 1,024|1,000
## SUPPORTED PLATFORMS
Platform | Board             | Software Version
---------|-------------------|-----------------
xilinx_u200_qdma|Xilinx Alveo U200|SDx 2019.1
xilinx_u280_xdma|Xilinx Alveo U280|SDx 2019.1
xilinx_u250_qdma|Xilinx Alveo U250|SDx 2019.1
xilinx_u200_xdma|Xilinx Alveo U200|SDx 2019.1
xilinx_u250_xdma|Xilinx Alveo U250|SDx 2019.1
xilinx_u280-es1_xdma|Xilinx Alveo U280|SDx 2019.1


##  DESIGN FILES
Application code is located in the src directory. Accelerator binary files will be compiled to the xclbin directory. The xclbin directory is required by the Makefile and its contents will be filled during compilation. A listing of all the files in this example is shown below

```
data/filter_buffer_raw.txt
data/input_buffer_raw.txt
data/output_buffer_raw.txt
src/convolve.cpp
src/krnl_convolve.cl
```

##  COMMAND LINE ARGUMENTS
***OpenCV for Example Applications***

This application requires OpenCV runtime libraries. If the host does not have OpenCV installed use the Xilinx included libraries with the following command:

`export LD_LIBRARY_PATH=$XILINX_SDX/lnx64/tools/opencv/:$LD_LIBRARY_PATH`

Once the environment has been configured, the application can be executed by
```
./convolve <krnl_convolve XCLBIN> ./data/input_buffer_raw.txt ./data/filter_buffer_raw.txt ./data/output_buffer_raw.txt
```


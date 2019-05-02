Convolve
======================

The convolve example is a performant design which showcases convolutional image filtering. The example processes the image 8 pixels at a time.

### PERFORMANCE
Board|Image Size|Frames / Second
-----|-----|-----
xilinx:adm-pcie-7v3:1ddr|1,024 x 1,024|1,000
xilinx:adm-pcie-ku3:2ddr-xpr|1,024 x 1,024|1,000
## SUPPORTED PLATFORMS
Board | Software Version
------|-----------------
Xilinx Alveo U200|SDx 2018.3
Xilinx Virtex UltraScale+ VCU1525|SDx 2018.3
Xilinx Alveo U250|SDx 2018.3


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
Once the environment has been configured, the application can be executed by
```
./convolve <krnl_convolve XCLBIN> ./data/input_buffer_raw.txt ./data/filter_buffer_raw.txt ./data/output_buffer_raw.txt
```


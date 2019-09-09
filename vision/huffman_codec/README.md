Huffman Encoding/Decoding
======================

This is an implementation of a huffman encoding/decoding algorithm targeting execution on an SDAccel supported FPGA acceleration card.

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
data/input.bmp
data/rect_1024.bmp
data/rect_32.bmp
data/rect_512.bmp
data/rect_64.bmp
data/sdaccel.bmp
src/bit_io.cpp
src/bit_io.h
src/huffmancodec_naive.cpp
src/huffmancodec_naive.h
src/huffmancodec_optimized.cpp
src/huffmancodec_optimized.h
src/huffmancodec_optimized_cpuonly.cpp
src/huffmancodec_optimized_cpuonly.h
src/krnl_huffman.cl
src/krnl_huffman_singleptr.cl
src/main.cpp
```

##  COMMAND LINE ARGUMENTS
Once the environment has been configured, the application can be executed by
```
./huffman <krnl_huffman XCLBIN> -b ./data/rect_1024.bmp
```


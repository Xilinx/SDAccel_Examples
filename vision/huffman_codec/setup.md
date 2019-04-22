Huffman Encoding/Decoding
======================

This file contains the following sections:

1. SUPPORTED PLATFORMS
2. DESIGN FILES
3. COMMAND LINE ARGUMENTS


## 1. SUPPORTED PLATFORMS
Board | Device Name | Software Version
------|-------------|-----------------
Xilinx Alveo U250|xilinx_u250_xdma_201820_1|SDx 2018.3
Xilinx Virtex UltraScale+ VCU1525|xilinx_vcu1525_dynamic|SDx 2018.3
Xilinx Alveo U200|xilinx_u200_xdma_201820_1|SDx 2018.3


## 2. DESIGN FILES
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

## 3. COMMAND LINE ARGUMENTS
Once the environment has been configured, the application can be executed by
```
./huffman <krnl_huffman XCLBIN> -b ./data/rect_1024.bmp
```


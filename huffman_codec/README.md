Huffman Codec Example
===============================

This is an optimized implementation of a huffman encoding/decoding algorithm
targeting execution on an SDAccel supported FPGA acceleration card.

The main algorithm characteristics of this application are

1. Huffman Encoding/Decoding [https://en.wikipedia.org/wiki/Huffman_coding]
2. Input is in the format a bitmap image
3. Target performance = 
4. Achieved performance = 

Achieved performance was measured on an Alpha Data ADM-PCI-7v3 card.

Changelog
----------
1/29/2016 - Initial Release

Compiling the Application
---------------------------
This application is compiled using the SDAccel script mode.
To compile the application:

```
sdaccel huffman.tcl
```
The target board can be changed by editing *huffman.tcl*

Executing the Application
---------------------------
```
huffman_host.exe --platform Xilinx --device fpga0 --kernel bin_huffman.xclbin data/rect_1024.bmp
```

Files in the Example
---------------------
Example data
- data/race_1024.bmp

Application host code
- huffmanapp.cpp
- huffmanapp.h
- huffmancodec.cpp
- huffmancodec.h
- main.cpp
- xcl.c
- xcl.h

Kernel code
- krnl_huffman_singleptr.cl

Compilation Script
- huffman.tcl

Global Memory Two Banks (C) for 5.0 shell
======================

This example of 2ddr to demonstrate on how to use 2ddr DSA. How to create buffers in each DDR.

***KEY CONCEPTS:*** Multiple Banks

***KEYWORDS:*** max_memory_ports, misc:map_connect, HLS Interface m_axi bundle

## SUPPORTED PLATFORMS
Board | Software Version
------|-----------------
Xilinx Only 5.0 Shell|SDx 2018.3


##  DESIGN FILES
Application code is located in the src directory. Accelerator binary files will be compiled to the xclbin directory. The xclbin directory is required by the Makefile and its contents will be filled during compilation. A listing of all the files in this example is shown below

```
```

##  COMMAND LINE ARGUMENTS
Once the environment has been configured, the application can be executed by
```
./host <apply_watermark XCLBIN> ./data/input.bmp ./data/golden.bmp
```


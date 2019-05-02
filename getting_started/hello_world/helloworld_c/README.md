Hello World (HLS C/C++ Kernel)
======================

This is simple example of vector addition to describe how to use HLS kernels in Sdx Environment. This example highlights the concepts like PIPELINE which increases the kernel performance 

***KEY CONCEPTS:*** HLS C Kernel, OpenCL Host APIs

***KEYWORDS:*** gmem, bundle, #pragma HLS INTERFACE, m_axi, s_axi4lite

## SUPPORTED PLATFORMS
Board | Software Version
------|-----------------
Xilinx Alveo U200|SDx 2018.3
Xilinx Virtex UltraScale+ VCU1525|SDx 2018.3
Xilinx Alveo U250|SDx 2018.3


##  DESIGN FILES
Application code is located in the src directory. Accelerator binary files will be compiled to the xclbin directory. The xclbin directory is required by the Makefile and its contents will be filled during compilation. A listing of all the files in this example is shown below

```
src/host.cpp
src/vadd.cpp
```

##  COMMAND LINE ARGUMENTS
Once the environment has been configured, the application can be executed by
```
./host <vadd XCLBIN>
```


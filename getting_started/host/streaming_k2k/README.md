Stream Kernel to Kernel Vector Addition and Multiplication
======================

This is a simple kernel to kernel streaming Vector Add and Vector Multiply C Kernel that demonstrates on how to process a stream of data for computation between two kernels.

***KEY CONCEPTS:*** Read/Write Stream, Create/Release Stream

***KEYWORDS:*** cl_stream, CL_STREAM_EOT, CL_STREAM_NONBLOCKING

## SUPPORTED PLATFORMS
Board | Software Version
------|-----------------
Xilinx Alveo U200|SDx 2019.1

##  DESIGN FILES
Application code is located in the src directory. Accelerator binary files will be compiled to the xclbin directory. The xclbin directory is required by the Makefile and its contents will be filled during compilation. A listing of all the files in this example is shown below

```
```

##  COMMAND LINE ARGUMENTS
Once the environment has been configured, the application can be executed by
```
./vadd_stream <krnl_stream_vadd_vmult XCLBIN>
```


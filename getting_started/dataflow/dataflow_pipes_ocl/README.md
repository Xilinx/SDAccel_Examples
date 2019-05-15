Blocking Pipes (CL)
======================

This is simple example of vector addition to demonstrate OpenCL Pipe Memory usage. OpenCL PIPE memory functionality allows user to achieve kernel-to-kernel data transfer without using global memory.

***KEY CONCEPTS:*** Dataflow, kernel to kernel pipes

***KEYWORDS:*** pipe, xcl_reqd_pipe_depth, read_pipe_block(), write_pipe_block()

## SUPPORTED PLATFORMS
Board | Software Version
------|-----------------
Xilinx Alveo U250|SDx 2018.3
Xilinx Alveo U200|SDx 2018.3
Xilinx Alveo U280 ES|SDx 2018.3
Xilinx Virtex UltraScale+ VCU1525|SDx 2018.3


##  DESIGN FILES
Application code is located in the src directory. Accelerator binary files will be compiled to the xclbin directory. The xclbin directory is required by the Makefile and its contents will be filled during compilation. A listing of all the files in this example is shown below

```
src/adder.cl
src/host.cpp
```

##  COMMAND LINE ARGUMENTS
Once the environment has been configured, the application can be executed by
```
./host <adder XCLBIN>
```


Large application Splits into Multiple Kernels(CL)
======================

This is a multi-filter image processing application to showcase effectiveness of Dataflow/Streams usage. This examples is intended to help developers to break down the complex kernel into multiple sub-functions using OpenCL Dataflow. It presents a way to concurrently execute multiple functions with better area utilization compared to a complex single kernel implementation. The main objective of this example is to showcase a way to build a optimal FPGA design which achieves maximum frequency with optimal resource utilization and achieves better performance compared to single kernel implementations.

***KEY CONCEPTS:*** Dataflow, Stream

***KEYWORDS:*** xcl_dataflow, xcl_array_partition, xcl_pipeline_loop

## SUPPORTED PLATFORMS
Board | Software Version
------|-----------------
Xilinx Alveo U200|SDx 2018.3
Xilinx Virtex UltraScale+ VCU1525|SDx 2018.3
Xilinx Alveo U250|SDx 2018.3


##  DESIGN FILES
Application code is located in the src directory. Accelerator binary files will be compiled to the xclbin directory. The xclbin directory is required by the Makefile and its contents will be filled during compilation. A listing of all the files in this example is shown below

```
data/car_128x128.bmp
data/car_480x640.bmp
src/boost_helper.h
src/defns.h
src/host.cpp
src/median_helper.h
src/sketch.cl
src/sketch_bad.cl
src/sketch_helper.h
```

##  COMMAND LINE ARGUMENTS
Once the environment has been configured, the application can be executed by
```
./host <sketch_GOOD XCLBIN> <sketch_BAD XCLBIN> ./data/car_128x128.bmp
```


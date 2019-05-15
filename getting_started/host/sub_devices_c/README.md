Sub Devices (C)
======================

This example demonstrates how to create OpenCL subdevices which uses a single kernel multiple times in order to show how to handle each instance independently including independent buffers, command queues and sequencing.

***KEY CONCEPTS:*** Sub Devices

***KEYWORDS:*** cl_device_partition_property, createSubDevices, CL_DEVICE_PARTITION_EQUALLY

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
src/host.cpp
src/krnl_vadd.cpp
```

##  COMMAND LINE ARGUMENTS
Once the environment has been configured, the application can be executed by
```
./sub_devices <krnl_vadd XCLBIN>
```


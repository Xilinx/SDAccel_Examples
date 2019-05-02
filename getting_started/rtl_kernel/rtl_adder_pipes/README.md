Adder With Pipes (RTL)
======================

This example shows an adder with pipes using 3 RTL kernels.

***KEY CONCEPTS:*** RTL Kernel, Multiple RTL Kernels

## SUPPORTED PLATFORMS
Board | Software Version
------|-----------------
Xilinx Alveo U200|SDx 2018.3
Xilinx Virtex UltraScale+ VCU1525|SDx 2018.3
Xilinx Alveo U250|SDx 2018.3


##  DESIGN FILES
Application code is located in the src directory. Accelerator binary files will be compiled to the xclbin directory. The xclbin directory is required by the Makefile and its contents will be filled during compilation. A listing of all the files in this example is shown below

```
src/adder_stage/hdl/krnl_adder_stage_rtl.v
src/adder_stage/hdl/krnl_adder_stage_rtl_adder.sv
src/adder_stage/hdl/krnl_adder_stage_rtl_control_s_axi.v
src/adder_stage/hdl/krnl_adder_stage_rtl_counter.sv
src/adder_stage/hdl/krnl_adder_stage_rtl_int.sv
src/host.cpp
src/input_stage/hdl/krnl_input_stage_rtl.v
src/input_stage/hdl/krnl_input_stage_rtl_axi_read_master.sv
src/input_stage/hdl/krnl_input_stage_rtl_control_s_axi.v
src/input_stage/hdl/krnl_input_stage_rtl_counter.sv
src/input_stage/hdl/krnl_input_stage_rtl_int.sv
src/kernel_adder_stage.xml
src/kernel_input_stage.xml
src/kernel_output_stage.xml
src/output_stage/hdl/krnl_output_stage_rtl.v
src/output_stage/hdl/krnl_output_stage_rtl_axi_write_master.sv
src/output_stage/hdl/krnl_output_stage_rtl_control_s_axi.v
src/output_stage/hdl/krnl_output_stage_rtl_counter.sv
src/output_stage/hdl/krnl_output_stage_rtl_int.sv
src/output_stage/hdl/krnl_output_stage_rtl_register_slice.sv
```

##  COMMAND LINE ARGUMENTS
Once the environment has been configured, the application can be executed by
```
./host <adder XCLBIN>
```


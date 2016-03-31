# SDAccel Application Example - SHA1
create_solution -name sha1_example -dir . -force

# Target a Xilinx FPGA board
add_device -vbnv xilinx:adm-pcie-7v3:1ddr:2.1

# Execution arguments for the application
set args "-p Xilinx -d fpga0 -k bin_sha1.xclbin"

# Host Compiler Flags
set_property -name host_cflags -value "-g -O0 -std=c++0x -I$::env(PWD)/src -I$::env(PWD)/src/common -I$::env(XILINX_SDACCEL)/include" -objects [current_solution]

# Host common source files
add_files "src/common/xcl.h src/common/xcl.cpp  src/common/cmdlineparser.h src/common/cmdlineparser.cpp src/common/logger.h src/common/logger.cpp"

add_files "src/sha1_app.h src/sha1_app.cpp src/oswendian.h src/sha1.h src/sha1.c src/main.cpp"
set_property file_type "c header files" [get_files "src/common/xcl.h"]
set_property file_type "c header files" [get_files "src/sha1_app.h"]


# Kernel Definitions
create_kernel -type clc dev_sha1_update
add_files -kernel [get_kernels dev_sha1_update] "src/krnl_sha1.cl"


# Define Binary Containers
create_opencl_binary bin_sha1
set_property region "OCL_REGION_0" [get_opencl_binary bin_sha1]

# Compute Units [1 per kernel]
create_compute_unit -opencl_binary [get_opencl_binary bin_sha1] -kernel [get_kernels dev_sha1_update] -name cu_sha10

# Compile the design for CPU based emulation
compile_emulation -flow cpu -opencl_binary [get_opencl_binary bin_sha1]
run_emulation -flow cpu -args $args

# Create estimated resource usage and latency report
report_estimate

# Compile the design for Hardware Emulation
compile_emulation -flow hardware -opencl_binary [get_opencl_binary bin_sha1]
run_emulation -flow hardware -args $args

# Compile the design for execution on the FPGA board
build_system

# Create the board deployment package for the application
package_system

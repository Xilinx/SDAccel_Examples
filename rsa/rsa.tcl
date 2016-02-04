# SDAccel Application Example - RSA decryption
# 1024 bits decryption
create_solution -name rsa_example -dir . -force
# Target a Xilinx FPGA board
add_device -vbnv xilinx:adm-pcie-7v3:1ddr:2.0

# Execution arguments for the application
set args "-p Xilinx -d fpga0 -k bin_rsa.xclbin -i $::env(PWD)/data/0_0_1024_key.cip -o $::env(PWD)/data/0_out.msg -y $::env(PWD)/data/0_1024_key.pem"

# Host Compiler Flags
set_property -name host_cflags -value "-DRSA_1024 -g -O3 -Wall -std=c++0x  -I$::env(PWD)/src -I$::env(XILINX_SDACCEL)/include -lssl -lcrypto -ldl" -objects [current_solution]

# Host source files
add_files "src/cmdlineparser.h src/cmdlineparser.cpp src/rsa_app.h src/rsa_app.cpp"
add_files "src/common.cpp src/common.h"
add_files "src/logger.cpp src/logger.h src/main.cpp src/xcl.h src/xcl.cpp"
set_property file_type "c header files" [get_files "src/xcl.h"]
set_property file_type "c header files" [get_files "common.h"]

# Kernel Definitions
create_kernel -type clc rsa
add_files -kernel [get_kernels rsa] "src/krnl_rsa.cl"


# Define Binary Containers
create_opencl_binary bin_rsa
set_property region "OCL_REGION_0" [get_opencl_binary bin_rsa]

# Compute Units [1 per kernel]
create_compute_unit -opencl_binary [get_opencl_binary bin_rsa] -kernel [get_kernels rsa] -name cu_rsa0


# Compile the design for CPU based emulation
compile_emulation -flow cpu -opencl_binary [get_opencl_binary bin_rsa]
run_emulation -flow cpu -args $args

# Create estimated resource usage and latency report
report_estimate

# Compile the design for Hardware Emulation
compile_emulation -flow hardware -opencl_binary [get_opencl_binary bin_rsa]
run_emulation -flow hardware -args $args

# Compile the design for execution on the FPGA board
build_system

# Create the board deployment package for the application
package_system

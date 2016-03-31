# SDAccel Application Example - Tiny Encryption
# 128-bit key size

create_solution -name tinyEncryption_example -dir . -force
# Target a Xilinx FPGA board
add_device -vbnv xilinx:adm-pcie-7v3:1ddr:2.1

# Execution arguments for the application
set args "$::env(PWD)/data/image1.bmp $::env(PWD)/data/image2.bmp bin_tinyEncryption.xclbin"

# Host source files
add_files "tinyEncryption.cpp"
add_files "bitmap.cpp"
add_files "oclErrorCodes.cpp"
add_files "oclHelper.cpp"
add_files "bitmap.h"
set_property file_type "c header files" [get_files "bitmap.h"]
add_files "oclHelper.h"
set_property file_type "c header files" [get_files "oclHelper.h"]

# Kernel Definition
create_kernel tinyEncryption -type clc
add_files -kernel [get_kernels tinyEncryption] "krnl_tinyEncryption.cl"

# Define Binary Containers
create_opencl_binary bin_tinyEncryption
set_property region "OCL_REGION_0" [get_opencl_binary bin_tinyEncryption]
create_compute_unit -opencl_binary [get_opencl_binary bin_tinyEncryption] -kernel [get_kernels tinyEncryption] -name cu_tinyEncryption0

# Compile the design for CPU based emulation
compile_emulation -flow cpu -opencl_binary [get_opencl_binary bin_tinyEncryption]
run_emulation -flow cpu -args $args

# Create estimated resource usage and latency report
report_estimate

# Compile the design for Hardware Emulation
compile_emulation -flow hardware -opencl_binary [get_opencl_binary bin_tinyEncryption]
run_emulation -flow hardware -args $args

# Compile the design for execution on the FPGA board
build_system

# Create the board deployment package for the application
package_system

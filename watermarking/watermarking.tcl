# SDAccel Application Example - watermarking
# 64 x 64 image size

create_solution -name watermarking_example -dir . -force
# Target a Xilinx FPGA board
add_device -vbnv xilinx:adm-pcie-7v3:1ddr:2.1

# Execution arguments for the application
set args "$::env(PWD)/data/inputImage.bmp bin_watermarking.xclbin"

# Host source files
add_files "watermarking.cpp"
add_files "bitmap.cpp"
add_files "oclErrorCodes.cpp"
add_files "oclHelper.cpp"
add_files "bitmap.h"
set_property file_type "c header files" [get_files "bitmap.h"]
add_files "oclHelper.h"
set_property file_type "c header files" [get_files "oclHelper.h"]

# Kernel Definition
create_kernel applyWatermark -type clc
add_files -kernel [get_kernels applyWatermark] "krnl_watermarking.cl"

# Define Binary Containers
create_opencl_binary bin_watermarking
set_property region "OCL_REGION_0" [get_opencl_binary bin_watermarking]
create_compute_unit -opencl_binary [get_opencl_binary bin_watermarking] -kernel [get_kernels applyWatermark] -name cu_watermarking0

# Compile the design for CPU based emulation
compile_emulation -flow cpu -opencl_binary [get_opencl_binary bin_watermarking]
run_emulation -flow cpu -args $args

# Create estimated resource usage and latency report
report_estimate

# Compile the design for Hardware Emulation
#compile_emulation -flow hardware -opencl_binary [get_opencl_binary bin_watermarking]
#run_emulation -flow hardware -args $args

# Compile the design for execution on the FPGA board
build_system

# Create the board deployment package for the application
package_system

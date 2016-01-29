# SDAccel Application Example - Histogram Equalization
# 12-Bit image resolution
# 2048 x 1080 image size
create_solution -name histogram_example -dir . -force
# Target a Xilinx FPGA board
add_device -vbnv xilinx:adm-pcie-7v3:1ddr:2.0

# Execution arguments for the application
set args "bin_equalizer.xclbin $::env(PWD)/data/race_2k.bmp"

# Host Compiler Flags
set_property -name host_cflags -value "-g -O0 -std=c++0x -I$::env(PWD) -I$::env(XILINX_SDACCEL)/include -L/$::env(XILINX_SDACCEL)/lnx64/tools/opencv -lopencv_core -lopencv_highgui -lopencv_imgproc" -objects [current_solution]

# Host source files
add_files "equalizer.cpp"
add_files "xcl.c"
add_files "equalizer.h"
set_property file_type "c header files" [get_files "equalizer.h"]
add_files "xcl.h"
set_property file_type "c header files" [get_files "xcl.h"]

# Kernel Definition
create_kernel krnl_equalizer -type clc
add_files -kernel [get_kernels krnl_equalizer] "krnl_equalizer.cl"

# Define Binary Containers
create_opencl_binary bin_equalizer
set_property region "OCL_REGION_0" [get_opencl_binary bin_equalizer]
create_compute_unit -opencl_binary [get_opencl_binary bin_equalizer] -kernel [get_kernels krnl_equalizer] -name cu_equalizer0

# Compile the design for CPU based emulation
compile_emulation -flow cpu -opencl_binary [get_opencl_binary bin_equalizer]
run_emulation -flow cpu -args $args

# Create estimated resource usage and latency report
report_estimate

# Compile the design for Hardware Emulation
compile_emulation -flow hardware -opencl_binary [get_opencl_binary bin_equalizer]
run_emulation -flow hardware -args $args

# Compile the design for execution on the FPGA board
build_system

# Create the board deployment package for the application
package_system

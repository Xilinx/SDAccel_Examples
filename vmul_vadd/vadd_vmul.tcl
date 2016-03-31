# SDAccel Application Example - Vector Addition

create_solution -name vector_mult_add -dir . -force
# Target a Xilinx FPGA board
add_device -vbnv xilinx:adm-pcie-7v3:1ddr:2.1

# Execution arguments for the application
set args "bin_vmul.xclbin bin_vadd.xclbin"

# Host Compiler Flags
set_property -name host_cflags -value "-g -O0 -std=c++0x -I$::env(PWD)" -objects [current_solution]

# Host source files
add_files "main.c"

# Kernel Definition
create_kernel krnl_vadd -type clc
add_files -kernel [get_kernels krnl_vadd] "krnl_vadd.cl"

create_kernel krnl_vmul -type clc
add_files -kernel [get_kernels krnl_vmul] "krnl_vmul.cl"

# Define Binary Containers
create_opencl_binary bin_vadd
set_property region "OCL_REGION_0" [get_opencl_binary bin_vadd]
create_compute_unit -opencl_binary [get_opencl_binary bin_vadd] -kernel [get_kernels krnl_vadd] -name cu_vadd0

create_opencl_binary bin_vmul
set_property region "OCL_REGION_0" [get_opencl_binary bin_vmul]
create_compute_unit -opencl_binary [get_opencl_binary bin_vmul] -kernel [get_kernels krnl_vmul] -name cu_vmul0


# Compile the design for CPU based emulation
compile_emulation -flow cpu
run_emulation -flow cpu -args $args

# Create estimated resource usage and latency report
report_estimate

# Compile the design for Hardware Emulation
compile_emulation -flow hardware
run_emulation -flow hardware -args $args

# Compile the design for execution on the FPGA board
build_system

# Create the board deployment package for the application
package_system

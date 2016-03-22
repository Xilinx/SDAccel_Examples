# SDAccel Application Example - AESDecrypt
create_solution -name aesdecrypt_example -dir . -force
# Target a Xilinx FPGA board
add_device -vbnv xilinx:adm-pcie-7v3:1ddr:2.1

# Execution arguments for the application
set args "-p Xilinx -d fpga0 -k bin_aes_decrypt.xclbin -b $::env(PWD)/data/input.bmp"

# Host Compiler Flags
set_property -name host_cflags -value "-g -O0 -std=c++0x -I$::env(PWD)/src -I$::env(PWD)/src/common -I$::env(XILINX_SDACCEL)/include" -objects [current_solution]

# Host common source files
add_files "src/common/xcl.h src/common/xcl.cpp  src/common/cmdlineparser.h src/common/cmdlineparser.cpp src/common/logger.h src/common/logger.cpp src/common/simplebmp.h src/common/simplebmp.cpp"

add_files "src/aes_ecb.h src/aes_ecb.cpp src/aes_app.h src/aes_app.cpp src/main.cpp"
set_property file_type "c header files" [get_files "src/common/xcl.h"]
set_property file_type "c header files" [get_files "src/aes_ecb.h"]


# Kernel Definitions
create_kernel -type clc krnl_aes_decrypt
add_files -kernel [get_kernels krnl_aes_decrypt] "src/krnl_aes.cl"


# Define Binary Containers
create_opencl_binary bin_aes_decrypt
set_property region "OCL_REGION_0" [get_opencl_binary bin_aes_decrypt]

# Compute Units [1 per kernel]
create_compute_unit -opencl_binary [get_opencl_binary bin_aes_decrypt] -kernel [get_kernels krnl_aes_decrypt] -name cu_aes_decrypt0

# Compile the design for CPU based emulation
compile_emulation -flow cpu -opencl_binary [get_opencl_binary bin_aes_decrypt]
run_emulation -flow cpu -args $args

# Create estimated resource usage and latency report
report_estimate

# Compile the design for Hardware Emulation
compile_emulation -flow hardware -opencl_binary [get_opencl_binary bin_aes_decrypt]
run_emulation -flow hardware -args $args

# Compile the design for execution on the FPGA board
build_system

# Create the board deployment package for the application
package_system

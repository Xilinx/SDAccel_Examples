# SDAccel Application Example - Huffman Encode/Decoder
# 12-Bit image resolution
# 2048 x 1080 image size
create_solution -name huffman_example -dir . -force
# Target a Xilinx FPGA board
add_device -vbnv xilinx:adm-pcie-7v3:1ddr:2.0

# Execution arguments for the application
set args "-p Xilinx -d fpga0 -k bin_huffman.xclbin -b $::env(PWD)/data/rect_32.bmp"

# Host Compiler Flags
set_property -name host_cflags -value "-g -O0 -std=c++0x -I$::env(PWD)/src -I$::env(XILINX_SDACCEL)/include" -objects [current_solution]

# Host source files
add_files "src/bit_io.h src/bit_io.cpp src/cmdlineparser.h src/cmdlineparser.cpp src/huffmancodec_naive.h src/huffmancodec_naive.cpp"
add_files "src/huffmancodec_optimized_cpuonly.cpp src/huffmancodec_optimized_cpuonly.h src/huffmancodec_optimized.cpp src/huffmancodec_optimized.h"
add_files "src/logger.cpp src/logger.h src/main.cpp src/simplebmp.cpp src/simplebmp.h src/xcl.h src/xcl.cpp"
set_property file_type "c header files" [get_files "src/xcl.h"]
set_property file_type "c header files" [get_files "src/bit_io.h"]
#set_property file_type "c header files" [get_files "equalizer.h"]

# Kernel Definitions
create_kernel -type clc encode
add_files -kernel [get_kernels encode] "src/krnl_huffman_singleptr.cl"

create_kernel -type clc decode
add_files -kernel [get_kernels decode] "src/krnl_huffman_singleptr.cl"


# Define Binary Containers
create_opencl_binary bin_huffman
set_property region "OCL_REGION_0" [get_opencl_binary bin_huffman]

# Compute Units [1 per kernel]
create_compute_unit -opencl_binary [get_opencl_binary bin_huffman] -kernel [get_kernels encode] -name cu_huffman_encode0
create_compute_unit -opencl_binary [get_opencl_binary bin_huffman] -kernel [get_kernels decode] -name cu_huffman_decode0

# Compile the design for CPU based emulation
compile_emulation -flow cpu -opencl_binary [get_opencl_binary bin_huffman]
#run_emulation -flow cpu -args $args

# Create estimated resource usage and latency report
report_estimate

# Compile the design for Hardware Emulation
#compile_emulation -flow hardware -opencl_binary [get_opencl_binary bin_huffman]
#run_emulation -flow hardware -args $args

# Compile the design for execution on the FPGA board
build_system

# Create the board deployment package for the application
package_system

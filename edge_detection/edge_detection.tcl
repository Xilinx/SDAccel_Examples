# SDAccel Application Example - Edge Detection
create_solution -name edgedetection_example -dir . -force
# Target a Xilinx FPGA board
add_device -vbnv xilinx:adm-pcie-7v3:1ddr:2.0

# Execution arguments for the application
set args "-p Xilinx -d fpga0 -k bin_sobelfilter.xclbin -b $::env(PWD)/data/eiffel.bmp"

# Host Compiler Flags
set_property -name host_cflags -value "-g -O0 -std=c++0x -I$::env(PWD)/src -I$::env(PWD)/src/common -I$::env(XILINX_SDACCEL)/include" -objects [current_solution]

# Host common source files
add_files "src/common/xcl.h src/common/xcl.cpp  src/common/cmdlineparser.h src/common/cmdlineparser.cpp src/common/logger.h src/common/logger.cpp src/common/simplebmp.h src/common/simplebmp.cpp"

add_files "src/edgedetection_app.h src/edgedetection_app.cpp src/main.cpp"
add_files "src/sobel_cpuonly.h src/sobel_cpuonly.cpp"
set_property file_type "c header files" [get_files "src/common/xcl.h"]
set_property file_type "c header files" [get_files "src/edgedetection_app.h"]

# Kernel Definitions
create_kernel -type clc krnl_sobel
add_files -kernel [get_kernels krnl_sobel] "src/krnl_sobelfilter.cl"

# Define Binary Containers
create_opencl_binary bin_sobelfilter
set_property region "OCL_REGION_0" [get_opencl_binary bin_sobelfilter]

# Compute Units [1 per kernel]
create_compute_unit -opencl_binary [get_opencl_binary bin_sobelfilter] -kernel [get_kernels krnl_sobel] -name cu_sobelfilter0

# Compile the design for CPU based emulation
compile_emulation -flow cpu -opencl_binary [get_opencl_binary bin_sobelfilter]
run_emulation -flow cpu -args $args

# Create estimated resource usage and latency report
report_estimate

# Compile the design for Hardware Emulation
compile_emulation -flow hardware -opencl_binary [get_opencl_binary bin_sobelfilter]
run_emulation -flow hardware -args $args

# Compile the design for execution on the FPGA board
build_system

# Create the board deployment package for the application
package_system

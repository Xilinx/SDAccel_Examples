# Define the solution for SDAccel
create_solution -name sol_linear_search -dir . -force
add_device -vbnv xilinx:adm-pcie-7v3:1ddr:2.0

set args "bin_linear_search.xclbin $::env(PWD)/queries.txt $::env(PWD)/queries.txt"

# Host Compiler Flags
set_property -name host_cflags -value "-g -O0 -Wall -Werror -I$env(SDACCEL_VIVADO_HLS)/include/" -objects [current_solution]

puts "Add files"
# Host Source Files
add_files "linear_search.c"
add_files "linear_search.h"
add_files "xcl.c"
add_files "xcl.h"
set_property file_type "c header files" [get_files "linear_search.h"]
set_property file_type "c header files" [get_files "xcl.h"]

puts "create kernel"
# Kernel Definition
create_kernel krnl_linear_search -type c
add_files -kernel [get_kernels krnl_linear_search] "krnl_linear_search.cpp"

puts "create xclbin"
# Define Binary Containers
create_opencl_binary bin_linear_search
set_property region "OCL_REGION_0" [get_opencl_binary bin_linear_search]
create_compute_unit -opencl_binary [get_opencl_binary bin_linear_search] -kernel [get_kernels krnl_linear_search] -name cu_linear_search0

puts "cpu emulation"
# Compile the design for CPU based emulation
#compile_emulation -flow cpu -opencl_binary [get_opencl_binary bin_linear_search]

# Run the compiled application in CPU based emulation mode
#run_emulation -flow cpu -args $args

puts "estimate"
# Create estimate of resource usage
#report_estimate

puts "hw emulation"
# Compile the design for XSIM base emulation
#compile_emulation -flow hardware -opencl_binary [get_opencl_binary bin_linear_search]

# Run the XSIM emulation
#run_emulation -flow hardware -args $args

puts "build hw"
# Compile the application to run on the accelerator card
build_system

# Package the application binaries
package_system


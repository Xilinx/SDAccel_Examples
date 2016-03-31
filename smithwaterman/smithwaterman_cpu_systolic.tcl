# 1. Create solution
create_solution -name opencl_sw_maxscore_systolic_cpu -dir . -force

# 1a. Set the fpga_device for the solution (Virtex7 FPGA)
add_device xilinx:adm-pcie-7v3:1ddr:2.1

set currdir [pwd]
set commondir ${currdir}/common
set jsondir ${commondir}/3rdparty/jsonxx

# 1b. Set any special host compilation flags
set_property -name host_cflags -value "-I $jsondir -I $commondir -std=c++0x -g -Wall -DFPGA_DEVICE" -objects [current_project]

# 3. Create a binary container
create_opencl_binary opencl_sw_maxscore
set_property region "OCL_REGION_0" [get_opencl_binary opencl_sw_maxscore]

# 4. Create kernel opencl_sw_maxscore
create_kernel -type c opencl_sw_maxscore

add_files "src/sw.h"
set_property file_type "c header files" [get_files "src/sw.h"]

# 4b. Add kernel files
add_files -kernel [get_kernels opencl_sw_maxscore] "src/opencl_sw_maxscore_systolic.cpp"

# 5. Create kernel compute instance cu_opencl_sw_maxscore_0
create_compute_unit -opencl_binary [get_opencl_binary opencl_sw_maxscore] -kernel [get_kernels opencl_sw_maxscore] -name cu_opencl_sw_maxscore_0

# 5b. Set a property on the compute_unit
set_property debug true [get_compute_units -of_object [get_opencl_binary opencl_sw_maxscore] cu_opencl_sw_maxscore_0]

# 6. Compile kernel for software simulation 
compile_emulation -flow cpu -opencl_binary [get_opencl_binary opencl_sw_maxscore]




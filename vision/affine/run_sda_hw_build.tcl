#Create solution
create_solution -name prj_affine_build -force
add_device -vbnv xilinx:adm-pcie-7v3:1ddr:2.0

#Add host code
add_files affine_raw_host.cpp
set_property -name host_cflags -value "-g -Wall -DFPGA_DEVICE -DUSE_OPENCL -DXILINX" -objects [current_solution]

#Create binary, kernel, compute unit
create_opencl_binary bin_affine
set_property region OCL_REGION_0 [get_opencl_binary bin_affine]
#set_property -name kernel_flags -value "-DXILINX" -objects [get_kernels affine_kernel]
create_kernel -type clc affine_kernel
add_files -kernel [get_kernels affine_kernel] affine_kernel.cl
create_compute_unit -opencl_binary [get_opencl_binary bin_affine] -kernel [get_kernels affine_kernel] -name affine0

#Build and package system
build_system
package_system

# Copy the test image to the run directory
file copy CT-MONO2-16-brain.raw prj_affine_build/pkg/pcie

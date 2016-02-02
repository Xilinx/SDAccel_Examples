create_solution -name sha1_sc15_7v3 -force
add_device -vbnv xilinx:adm-pcie-7v3:1ddr:2.0

set_param compiler.generateExtraRunData true
set_param compiler.preserveHlsOutput 1

set currdir [pwd]
set commondir ${currdir}/src
set jsondir ${commondir}/3rdparty/jsonxx
set zmqdir /opt/platform/machine
set env(LD_LIBRARY_PATH) ${zmqdir}/lib:$env(LD_LIBRARY_PATH)

set_property -name host_cflags -value "-std=c++0x -g -O0 -Wall -I $zmqdir/include -I $jsondir -I $commondir -I/usr/include -lcrypto -lssl -L $zmqdir/lib -lzmq" -objects [current_solution]
add_files "src/main.cpp src/sha1.h src/sha1.cpp"
add_files "src/benchapp.cpp src/cmdlineparser.cpp src/logger.cpp src/profiler.cpp src/3rdparty/jsonxx/jsonxx.cc"
set_property file_type "c header files" [get_files "src/sha1.h"]

create_opencl_binary sha1
set_property region "OCL_REGION_0" [get_opencl_binary sha1]

create_kernel -type clc dev_sha1_update
add_files -kernel [get_kernels dev_sha1_update] "src/krnl_sha1.cl"

create_compute_unit -opencl_binary [get_opencl_binary sha1] -kernel [get_kernels dev_sha1_update] -name sha1_update0
create_compute_unit -opencl_binary [get_opencl_binary sha1] -kernel [get_kernels dev_sha1_update] -name sha1_update1

compile_emulation -flow cpu -opencl_binary [get_opencl_binary sha1]
run_emulation -flow cpu -args "sha1.xclbin"

report_estimate

compile_emulation -flow hardware -opencl_binary [get_opencl_binary sha1]
#run_emulation -flow hardware -args "sha1.xclbin"

#build_system
#package_system


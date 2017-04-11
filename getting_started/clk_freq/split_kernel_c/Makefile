COMMON_REPO := ../../../
#Common Includes
include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/xcl/xcl.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk
include $(COMMON_REPO)/libs/bitmap/bitmap.mk

# Host Application
host_SRCS=./src/host.cpp $(bitmap_SRCS) $(xcl_SRCS)
host_CXXFLAGS=-I./src/ $(xcl_CXXFLAGS) $(opencl_CXXFLAGS) $(bitmap_CXXFLAGS)
host_LDFLAGS=$(opencl_LDFLAGS)
host_CXXFLAGS+=-Wall

EXES=host

# Kernel
sketch_GOOD_SRCS=./src/sketch.cpp
sketch_GOOD_CLFLAGS=-k process_image -I./src/
sketch_GOOD_DEVICES=xilinx:adm-pcie-7v3:1ddr xilinx:adm-pcie-ku3:2ddr-xpr

sketch_BAD_SRCS=./src/sketch_bad.cpp
sketch_BAD_CLFLAGS=-k process_image -I./src/
sketch_BAD_DEVICES=xilinx:adm-pcie-7v3:1ddr xilinx:adm-pcie-ku3:2ddr-xpr

XOS=sketch_GOOD sketch_BAD

# xclbin
sketch_GOOD_XOS=sketch_GOOD
sketch_GOOD_DEVICES=xilinx:adm-pcie-7v3:1ddr xilinx:adm-pcie-ku3:2ddr-xpr

sketch_BAD_XOS=sketch_BAD
sketch_BAD_DEVICES=xilinx:adm-pcie-7v3:1ddr xilinx:adm-pcie-ku3:2ddr-xpr

XCLBINS=sketch_GOOD sketch_BAD

EXTRA_CLEAN=./output.bmp

# check
check_EXE=host
check_XCLBINS=sketch_GOOD sketch_BAD
check_ARGS=./data/car_128x128.bmp
check_DEVICES=$(sketch_GOOD_DEVICES)

CHECKS=check

DEVICES=xilinx:adm-pcie-ku3:2ddr-xpr

include $(COMMON_REPO)/utility/rules.mk

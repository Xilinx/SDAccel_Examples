# Watermarking Application

include ../../utility/boards.mk
include ../../libs/oclHelper/oclHelper.mk
include ../../libs/bitmap/bitmap.mk
include ../../libs/opencl/opencl.mk

# Watermarking Host Application
watermark_SRCS=./src/watermarking.cpp $(bitmap_SRCS) $(oclHelper_SRCS)
watermark_HDRS=$(bitmap_HDRS) $(oclHelper_HDRS)
watermark_CXXFLAGS=-I./src/ $(opencl_CXXFLAGS) $(bitmap_CXXFLAGS) $(oclHelper_CXXFLAGS)
watermark_LDFLAGS=$(opencl_LDFLAGS)

# Watermark Kernel
krnl_watermark_SRCS=./src/krnl_watermarking.cl

EXES=watermark
XCLBINS=krnl_watermark

# check
check_EXE=watermark
check_XCLBINS=krnl_watermark
check_sw_emu_ARGS=data/inputImage.bmp xclbin/krnl_watermark.sw_emu.xilinx_adm-pcie-ku3_2ddr_3_1.xclbin

CHECKS=check

include ../../utility/rules.mk


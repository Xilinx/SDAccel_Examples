# Watermarking Application

include ../../utility/boards.mk
include ../../libs/oclHelper/oclHelper.mk
include ../../libs/bitmap/bitmap.mk
include ../../libs/opencl/opencl.mk

# Watermarking Host Application
watermark_SRCS=./src/watermarking.cpp $(bitmap_SRCS) $(oclHelper_SRCS)
watermark_HDRS=$(bitmap_HDRS) $(oclHelper_HDRS)
watermark_CXXFLAGS=-I./src/ $(opencl_CXXFLAGS) $(bitmap_CXXFLAGS) $(oclHelper_CXXFLAGS)
watermark_X86_LDFLAGS=$(opencl_X86_LDFLAGS)
watermark_POWER_LDFLAGS=$(opencl_POWER_LDFLAGS)

# Watermark Kernel
krnl_watermark_SRCS=./src/krnl_watermarking.cl

EXES=watermark
XCLBINS=krnl_watermark

include ../../utility/rules.mk

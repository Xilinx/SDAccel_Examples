# Tiny Encription Application

include ../../utility/boards.mk
include ../../libs/bitmap/bitmap.mk
include ../../libs/oclHelper/oclHelper.mk
include ../../libs/opencl/opencl.mk

# Tiny Encryption Host Application
tiny_SRCS=./src/tinyEncryption.cpp $(bitmap_SRCS) $(oclHelper_SRCS)
tiny_HDRS=$(bitmap_HDRS) $(oclHelper_HDRS)
tiny_CXXFLAGS=-I./src/ $(bitmap_CXXFLAGS) $(oclHelper_CXXFLAGS) $(opencl_CXXFLAGS)
tiny_LDFLAGS=$(opencl_LDFLAGS)

# Tiny Encryption Kernel
krnl_tiny_SRCS=./src/krnl_tinyEncryption.cl

EXES=tiny
XCLBINS=krnl_tiny

# check
check_EXE=tiny
check_XCLBINS=krnl_tiny

CHECKS=check

include ../../utility/rules.mk


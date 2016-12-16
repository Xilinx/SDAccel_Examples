# AES Decrypt Application

# Supported devices
include ../../utility/boards.mk
include ../../libs/xcl/xcl.mk
include ../../libs/logger/logger.mk
include ../../libs/cmdparser/cmdparser.mk
include ../../libs/simplebmp/simplebmp.mk
include ../../libs/opencl/opencl.mk

# hello Host Application
aes_SRCS=./src/aes_ecb.cpp ./src/aes_app.cpp ./src/main.cpp $(xcl_SRCS) $(cmdparser_SRCS) $(logger_SRCS) $(simplebmp_SRCS)
aes_HDRS=./src/aes_app.h $(xcl_HDRS) $(cmdparser_HDRS) $(logger_HDRS) $(simplebmp_HDRS)
aes_CXXFLAGS=-I./src/ $(opencl_CXXFLAGS) $(xcl_CXXFLAGS) $(cmdparser_CXXFLAGS) $(logger_CXXFLAGS) $(simplebmp_CXXFLAGS)
aes_LDFLAGS=$(opencl_LDFLAGS)

# AES Kernel
krnl_aes_SRCS=./src/krnl_aes.cl
krnl_aes_DEVICES=xilinx:adm-pcie-7v3:1ddr:3.0

EXES=aes
XCLBINS=krnl_aes

# check
check_EXE=aes
check_XCLBINS=krnl_aes
check_ARGS=-b data/input.bmp
check_DEVICES=xilinx:adm-pcie-7v3:1ddr:3.0

CHECKS=check

include ../../utility/rules.mk


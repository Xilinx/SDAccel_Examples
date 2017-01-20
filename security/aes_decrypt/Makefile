# AES Decrypt Application
COMMON_REPO =../../

# Supported devices
include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/xcl/xcl.mk
include $(COMMON_REPO)/libs/logger/logger.mk
include $(COMMON_REPO)/libs/cmdparser/cmdparser.mk
include $(COMMON_REPO)/libs/simplebmp/simplebmp.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

# hello Host Application
aes_SRCS=./src/aes_ecb.cpp ./src/aes_app.cpp ./src/main.cpp $(xcl_SRCS) $(cmdparser_SRCS) $(logger_SRCS) $(simplebmp_SRCS)
aes_HDRS=./src/aes_app.h $(xcl_HDRS) $(cmdparser_HDRS) $(logger_HDRS) $(simplebmp_HDRS)
aes_CXXFLAGS=-I./src/ $(opencl_CXXFLAGS) $(xcl_CXXFLAGS) $(cmdparser_CXXFLAGS) $(logger_CXXFLAGS) $(simplebmp_CXXFLAGS)
aes_LDFLAGS=$(opencl_LDFLAGS)

# AES Kernel
krnl_aes_SRCS=./src/krnl_aes.cl

EXES=aes
XCLBINS=krnl_aes

# check
check_EXE=aes
check_XCLBINS=krnl_aes
check_ARGS=-b data/input.bmp

CHECKS=check

include $(COMMON_REPO)/utility/rules.mk


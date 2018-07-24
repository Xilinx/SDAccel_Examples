# AES Decrypt Application
COMMON_REPO =../../

# Supported devices
include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/xcl2/xcl2.mk
include $(COMMON_REPO)/libs/logger/logger.mk
include $(COMMON_REPO)/libs/cmdparser/cmdparser.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

# hello Host Application
aes_SRCS=./src/aes_ecb.cpp ./src/aes_app.cpp ./src/main.cpp $(xcl2_SRCS) $(cmdparser_SRCS) $(logger_SRCS)
aes_HDRS=./src/aes_app.h $(xcl2_HDRS) $(cmdparser_HDRS) $(logger_HDRS)
aes_CXXFLAGS=-I./src/ $(opencl_CXXFLAGS) $(xcl2_CXXFLAGS) $(cmdparser_CXXFLAGS) $(logger_CXXFLAGS) 
aes_LDFLAGS=$(opencl_LDFLAGS)

EXES=aes

# AES Kernel
krnl_aes_SRCS=./src/krnl_aes.cl

XOS=krnl_aes

# AES xclbin
krnl_aes_XOS=krnl_aes

XCLBINS=krnl_aes

# check
check_EXE=aes
check_XCLBINS=krnl_aes
check_ARGS=-b data/test.txt -g data/goldFile.txt

CHECKS=check

include $(COMMON_REPO)/utility/rules.mk


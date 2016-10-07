# AES Decrypt Application

# Supported devices
include ../../utility/boards.mk
include ../../libs/xcl_cpp/xcl_cpp.mk
include ../../libs/logger/logger.mk
include ../../libs/cmdparser/cmdparser.mk
include ../../libs/simplebmp/simplebmp.mk
include ../../libs/opencl/opencl.mk

# hello Host Application
aes_SRCS=./src/aes_ecb.cpp ./src/aes_app.cpp ./src/main.cpp $(xcl_cpp_SRCS) $(cmdparser_SRCS) $(logger_SRCS) $(simplebmp_SRCS)
aes_HDRS=./src/aes_app.h $(xcl_cpp_HDRS) $(cmdparser_HDRS) $(logger_HDRS) $(simplebmp_HDRS)
aes_CXXFLAGS=-I./src/ $(opencl_CXXFLAGS) $(xcl_cpp_CXXFLAGS) $(cmdparser_CXXFLAGS) $(logger_CXXFLAGS) $(simplebmp_CXXFLAGS)
aes_LDFLAGS=$(opencl_LDFLAGS)

# AES Kernel
krnl_aes_SRCS=./src/krnl_aes.cl

EXES=aes
XCLBINS=krnl_aes

include ../../utility/rules.mk


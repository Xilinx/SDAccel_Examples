# RSA Application

include ../../utility/boards.mk
include ../../libs/logger/logger.mk
include ../../libs/cmdparser/cmdparser.mk
include ../../libs/xcl/xcl.mk
include ../../libs/opencl/opencl.mk

# hello Host Application
rsa_SRCS=./src/rsa_app.cpp ./src/common.cpp ./src/main.cpp $(cmdparser_SRCS) $(xcl_SRCS) $(logger_SRCS)
rsa_HDRS=./src/rsa_app.h ./src/common.h $(cmdparser_HDRS) $(logger_HDRS) $(xcl_HDRS)
rsa_CXXFLAGS=-DRSA_2048 -g -O3 -Wall -I./src/ $(opencl_CXXFLAGS) $(cmdparser_CXXFLAGS) $(logger_CXXFLAGS) $(xcl_CXXFLAGS) -lssl -lcrypto -ldl
rsa_LDFLAGS=$(opencl_LDFLAGS)

# RSA Kernel
krnl_rsa_SRCS=./src/krnl_rsa.cpp
krnl_rsa_CLFLAGS=--kernel rsa

EXES=rsa
XCLBINS=krnl_rsa

# check
check_EXE=rsa
check_XCLBINS=krnl_rsa
check_ARGS=--in data/0_0_2048_key.cip --out data/0_out.msg --key data/0_2048_key.pem

CHECKS=check

include ../../utility/rules.mk


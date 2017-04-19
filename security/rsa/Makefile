# RSA Application
COMMON_REPO =../../

include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/logger/logger.mk
include $(COMMON_REPO)/libs/cmdparser/cmdparser.mk
include $(COMMON_REPO)/libs/xcl/xcl.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

# hello Host Application
rsa_SRCS=./src/rsa_app.cpp ./src/common.cpp ./src/main.cpp $(cmdparser_SRCS) $(xcl_SRCS) $(logger_SRCS)
rsa_HDRS=./src/rsa_app.h ./src/common.h $(cmdparser_HDRS) $(logger_HDRS) $(xcl_HDRS)
rsa_CXXFLAGS=-DRSA_2048 -O3 -Wall -I./src/ $(opencl_CXXFLAGS) $(cmdparser_CXXFLAGS) $(logger_CXXFLAGS) $(xcl_CXXFLAGS) -lssl -lcrypto -ldl
rsa_LDFLAGS=$(opencl_LDFLAGS)

EXES=rsa

# RSA Kernel
krnl_rsa_SRCS=./src/krnl_rsa.cpp
krnl_rsa_CLFLAGS=--kernel rsa
krnl_rsa_NDEVICES=xilinx:adm-pcie-ku3:2ddr-xpr:3.3 xilinx:xil-accel-rd-ku115:4ddr-xpr:3.3

XOS=krnl_rsa

# RSA xclbin
krnl_rsa_XOS=krnl_rsa
krnl_rsa_NDEVICES=xilinx:adm-pcie-ku3:2ddr-xpr:3.3 xilinx:xil-accel-rd-ku115:4ddr-xpr:3.3

XCLBINS=krnl_rsa

# check
check_EXE=rsa
check_XCLBINS=krnl_rsa
check_ARGS=--in data/0_0_2048_key.cip --out data/0_out.msg --key data/0_2048_key.pem
check_NDEVICES=$(krnl_rsa_NDEVICES)

CHECKS=check

DEVICES=xilinx:adm-pcie-7v3:1ddr:3.0

include $(COMMON_REPO)/utility/rules.mk


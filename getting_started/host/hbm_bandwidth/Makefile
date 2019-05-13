.PHONY: help

help::
	$(ECHO) "Makefile Usage:"
	$(ECHO) "  make all TARGET=<sw_emu/hw_emu/hw> DEVICE=<FPGA platform>"
	$(ECHO) "      Command to generate the design for specified Target and Device."
	$(ECHO) ""
	$(ECHO) "  make clean "
	$(ECHO) "      Command to remove the generated non-hardware files."
	$(ECHO) ""
	$(ECHO) "  make cleanall"
	$(ECHO) "      Command to remove all the generated files."
	$(ECHO) ""
	$(ECHO) "  make check TARGET=<sw_emu/hw_emu/hw> DEVICE=<FPGA platform>"
	$(ECHO) "      Command to run application in emulation."
	$(ECHO) ""
	$(ECHO) "  make build TARGET=<sw_emu/hw_emu/hw> DEVICE=<FPGA platform>"
	$(ECHO) "      Command to build xclbin application."
	$(ECHO) ""
	$(ECHO) "  make run_nimbix DEVICE=<FPGA platform>"
	$(ECHO) "      Command to run application on Nimbix Cloud."
	$(ECHO) ""
	$(ECHO) "  make aws_build DEVICE=<FPGA platform>"
	$(ECHO) "      Command to build AWS xclbin application on AWS Cloud."
	$(ECHO) ""

# Points to Utility Directory
COMMON_REPO = ../../../
ABS_COMMON_REPO = $(shell readlink -f $(COMMON_REPO))

TARGETS := hw
TARGET := $(TARGETS)
DEVICE := $(DEVICES)
XCLBIN := ./xclbin

include ./utils.mk

DSA := $(call device2sandsa, $(DEVICE))
BUILD_DIR := ./_x.$(TARGET).$(DSA)

BUILD_DIR_krnl_vaddmul = $(BUILD_DIR)/krnl_vaddmul

CXX := $(XILINX_SDX)/bin/xcpp
XOCC := $(XILINX_SDX)/bin/xocc

#Include Libraries
include $(ABS_COMMON_REPO)/libs/opencl/opencl.mk
include $(ABS_COMMON_REPO)/libs/xcl2/xcl2.mk
CXXFLAGS += $(xcl2_CXXFLAGS)
LDFLAGS += $(xcl2_LDFLAGS)
HOST_SRCS += $(xcl2_SRCS)
CXXFLAGS += $(opencl_CXXFLAGS) -Wall -O0 -g -std=c++14
LDFLAGS += $(opencl_LDFLAGS)

HOST_SRCS += src/host.cpp

# Host compiler global settings
CXXFLAGS += -fmessage-length=0
LDFLAGS += -lrt -lstdc++ 

# Kernel compiler global settings
CLFLAGS += -t $(TARGET) --platform $(DEVICE) --save-temps 
CLFLAGS += --kernel_frequency 300

# Kernel linker flags
LDCLFLAGS += --sp krnl_vaddmul_1.m_axi_gmem0:HBM[0:31] --sp krnl_vaddmul_1.m_axi_gmem1:HBM[0:31] --sp krnl_vaddmul_1.m_axi_gmem2:HBM[0:31] --sp krnl_vaddmul_1.m_axi_gmem3:HBM[0:31] --sp krnl_vaddmul_2.m_axi_gmem0:HBM[0:31] --sp krnl_vaddmul_2.m_axi_gmem1:HBM[0:31] --sp krnl_vaddmul_2.m_axi_gmem2:HBM[0:31] --sp krnl_vaddmul_2.m_axi_gmem3:HBM[0:31] --sp krnl_vaddmul_3.m_axi_gmem0:HBM[0:31] --sp krnl_vaddmul_3.m_axi_gmem1:HBM[0:31] --sp krnl_vaddmul_3.m_axi_gmem2:HBM[0:31] --sp krnl_vaddmul_3.m_axi_gmem3:HBM[0:31] --sp krnl_vaddmul_4.m_axi_gmem0:HBM[0:31] --sp krnl_vaddmul_4.m_axi_gmem1:HBM[0:31] --sp krnl_vaddmul_4.m_axi_gmem2:HBM[0:31] --sp krnl_vaddmul_4.m_axi_gmem3:HBM[0:31] --sp krnl_vaddmul_5.m_axi_gmem0:HBM[0:31] --sp krnl_vaddmul_5.m_axi_gmem1:HBM[0:31] --sp krnl_vaddmul_5.m_axi_gmem2:HBM[0:31] --sp krnl_vaddmul_5.m_axi_gmem3:HBM[0:31] --sp krnl_vaddmul_6.m_axi_gmem0:HBM[0:31] --sp krnl_vaddmul_6.m_axi_gmem1:HBM[0:31] --sp krnl_vaddmul_6.m_axi_gmem2:HBM[0:31] --sp krnl_vaddmul_6.m_axi_gmem3:HBM[0:31] --sp krnl_vaddmul_7.m_axi_gmem0:HBM[0:31] --sp krnl_vaddmul_7.m_axi_gmem1:HBM[0:31] --sp krnl_vaddmul_7.m_axi_gmem2:HBM[0:31] --sp krnl_vaddmul_7.m_axi_gmem3:HBM[0:31] --sp krnl_vaddmul_8.m_axi_gmem0:HBM[0:31] --sp krnl_vaddmul_8.m_axi_gmem1:HBM[0:31] --sp krnl_vaddmul_8.m_axi_gmem2:HBM[0:31] --sp krnl_vaddmul_8.m_axi_gmem3:HBM[0:31]

EXECUTABLE = host
CMD_ARGS = $(XCLBIN)/krnl_vaddmul.$(TARGET).$(DSA).xclbin

EMCONFIG_DIR = $(XCLBIN)/$(DSA)

BINARY_CONTAINERS += $(XCLBIN)/krnl_vaddmul.$(TARGET).$(DSA).xclbin
BINARY_CONTAINER_krnl_vaddmul_OBJS += $(XCLBIN)/krnl_vaddmul.$(TARGET).$(DSA).xo

CP = cp -rf

.PHONY: all clean cleanall docs emconfig
all: check-devices $(EXECUTABLE) $(BINARY_CONTAINERS) emconfig

.PHONY: exe
exe: $(EXECUTABLE)

.PHONY: build
build: $(BINARY_CONTAINERS)

# Building kernel
$(XCLBIN)/krnl_vaddmul.$(TARGET).$(DSA).xo: src/krnl_vaddmul.cpp
	mkdir -p $(XCLBIN)
	$(XOCC) $(CLFLAGS) --temp_dir $(BUILD_DIR_krnl_vaddmul) -c -k krnl_vaddmul -I'$(<D)' -o'$@' '$<'
$(XCLBIN)/krnl_vaddmul.$(TARGET).$(DSA).xclbin: $(BINARY_CONTAINER_krnl_vaddmul_OBJS)
	mkdir -p $(XCLBIN)
	$(XOCC) $(CLFLAGS) --temp_dir $(BUILD_DIR_krnl_vaddmul) -l $(LDCLFLAGS) --nk krnl_vaddmul:8 -o'$@' $(+)

# Building Host
$(EXECUTABLE): check-xrt $(HOST_SRCS) $(HOST_HDRS)
	$(CXX) $(CXXFLAGS) $(HOST_SRCS) $(HOST_HDRS) -o '$@' $(LDFLAGS)

emconfig:$(EMCONFIG_DIR)/emconfig.json
$(EMCONFIG_DIR)/emconfig.json:
	emconfigutil --platform $(DEVICE) --od $(EMCONFIG_DIR)

check: all
ifeq ($(findstring xilinx_u200_xdma, $(DEVICE)), xilinx_u200_xdma)
$(error Nothing to be done for make)
endif
ifeq ($(findstring xilinx_u200_qdma, $(DEVICE)), xilinx_u200_qdma)
$(error Nothing to be done for make)
endif
ifeq ($(findstring xilinx_u250_xdma, $(DEVICE)), xilinx_u250_xdma)
$(error Nothing to be done for make)
endif
ifeq ($(findstring xilinx_u250_qdma, $(DEVICE)), xilinx_u250_qdma)
$(error Nothing to be done for make)
endif
ifeq ($(findstring xilinx_vcu1525_dynamic, $(DEVICE)), xilinx_vcu1525_dynamic)
$(error Nothing to be done for make)
endif

ifeq ($(TARGET),$(filter $(TARGET),sw_emu hw_emu))
	$(CP) $(EMCONFIG_DIR)/emconfig.json .
	XCL_EMULATION_MODE=$(TARGET) ./$(EXECUTABLE) $(XCLBIN)/krnl_vaddmul.$(TARGET).$(DSA).xclbin
else
	 ./$(EXECUTABLE) $(XCLBIN)/krnl_vaddmul.$(TARGET).$(DSA).xclbin
endif
	sdx_analyze profile -i profile_summary.csv -f html

run_nimbix: all
	$(COMMON_REPO)/utility/nimbix/run_nimbix.py $(EXECUTABLE) $(CMD_ARGS) $(DSA)

aws_build: check-aws_repo $(BINARY_CONTAINERS)
	$(COMMON_REPO)/utility/aws/run_aws.py $(BINARY_CONTAINERS)

# Cleaning stuff
clean:
	-$(RMDIR) $(EXECUTABLE) $(XCLBIN)/{*sw_emu*,*hw_emu*} 
	-$(RMDIR) profile_* TempConfig system_estimate.xtxt *.rpt *.csv 
	-$(RMDIR) src/*.ll _xocc_* .Xil emconfig.json dltmp* xmltmp* *.log *.jou *.wcfg *.wdb

cleanall: clean
	-$(RMDIR) $(XCLBIN)
	-$(RMDIR) _x.*


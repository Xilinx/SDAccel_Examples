#+-------------------------------------------------------------------------------
# The following parameters are assigned with default values. These parameters can
# be overridden through the make command line
#+-------------------------------------------------------------------------------

# Run Target:
#   hw  - Compile for hardware
#   sw_emu/hw_emu - Compile for software/hardware emulation
# FPGA Board Platform (Default ~ ku115)

REPORT := no
PROFILE := no
DEBUG := no

TARGETS := hw
TARGET := $(TARGETS)
DEVICES := xilinx_kcu1500_dynamic_5_0
DEVICE := $(DEVICES)
XCLBIN := ./xclbin

CXX := $(XILINX_SDX)/bin/xcpp
XOCC := $(XILINX_SDX)/bin/xocc

# Points to Utility Directory
COMMON_REPO = ../../../
ABS_COMMON_REPO = $(shell readlink -f $(COMMON_REPO))

CXXFLAGS := -Wall -O0 -g -std=c++14

HOST_SRCS = src/host.cpp

# Host compiler global settings

# Kernel compiler global settings
CLFLAGS = -t $(TARGET) --platform $(DEVICE) --save-temps 
CLFLAGS += --xp "param:compiler.preserveHlsOutput=1" --xp "param:compiler.generateExtraRunData=true"


#'estimate' for estimate report generation
#'system' for system report generation
ifneq ($(REPORT), no)
CLFLAGS += --report estimate
CLLDFLAGS += --report system
endif

#Generates profile summary report
ifeq ($(PROFILE), yes)
CLFLAGS += --profile_kernel data:all:all:all
endif

#Generates debug summary report
ifeq ($(DEBUG), yes)
CLFLAGS += --dk protocol:all:all:all
endif

EXECUTABLE = host

BINARY_CONTAINERS += $(XCLBIN)/mmult.xclbin
BINARY_CONTAINER_1_OBJS += $(XCLBIN)/mmult.xo
ALL_KERNEL_OBJS += $(XCLBIN)/mmult.xo

#Include Libraries
include $(ABS_COMMON_REPO)/libs/xcl2/xcl2.mk
include $(ABS_COMMON_REPO)/libs/opencl/opencl.mk
CXXFLAGS += $(xcl2_CXXFLAGS) $(opencl_CXXFLAGS)
LDFLAGS += $(xcl2_LDFLAGS) $(opencl_LDFLAGS)
HOST_SRCS += $(xcl2_SRCS)

CP = cp -rf

.PHONY: all clean cleanall docs
all: $(EXECUTABLE) $(BINARY_CONTAINERS)

.PHONY: exe
exe: $(EXECUTABLE)

# Building kernel
$(XCLBIN)/mmult.xo: ./src/mmult.cl
	mkdir -p $(XCLBIN)
	$(XOCC) $(CLFLAGS) -c -k mmult -I'$(<D)' -o'$@' '$<'

$(XCLBIN)/mmult.xclbin: $(BINARY_CONTAINER_1_OBJS)
	$(XOCC) $(CLFLAGS) -l $(LDCLFLAGS) --nk mmult:1 -o'$@' $(+)

# Building Host
$(EXECUTABLE): $(HOST_SRCS)
	mkdir -p $(XCLBIN)
	$(CXX) $(CXXFLAGS) $(HOST_SRCS) -o '$@' $(LDFLAGS)

check: all
ifeq ($(TARGET),$(filter $(TARGET),sw_emu hw_emu))
	emconfigutil --platform $(DEVICE) --od .
	XCL_EMULATION_MODE=$(TARGET) ./$(EXECUTABLE)
endif

# Cleaning stuff
RM = rm -f
RMDIR = rm -rf
clean:
	-$(RMDIR) $(EXECUTABLE) $(XCLBIN)/{*sw_emu*,*hw_emu*} 
	-$(RMDIR) sdaccel_* TempConfig system_estimate.xtxt *.rpt
	-$(RMDIR) src/*.ll _xocc_* .Xil emconfig.json dltmp* xmltmp* *.log *.jou *.wcfg *.wdb

cleanall: clean
	-$(RMDIR) $(XCLBIN)

ECHO:= @echo

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

docs: README.md

README.md: description.json
	$(ABS_COMMON_REPO)/utility/readme_gen/readme_gen.py description.json


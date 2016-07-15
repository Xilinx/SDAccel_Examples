# Nearest Neighbor Search Application
CXXFLAGS:=-O0 -g
XOCCFLAGS:=-g --xp "param:compiler.preserveHlsOutput=1" --xp "param:compiler.generateExtraRunData=true" -s

XOCCFLAGS+= -t $(XMODE) --xdevice $(XDEVICE)
CXXFLAGS+= -std=c++0x

# Kernel Binary Build Types
XMODES:=sw_emu hw_emu hw

# Supported devices
include ../../utility/boards.mk

#XDEVICES:=xilinx:adm-pcie-7v3:1ddr:2.1 xilinx:adm-pcie-ku3:1ddr:2.1 xilinx:adm-pcie-ku3:2ddr:2.1
# Directory for Kernel Binary Files
XCLBIN_DIR=xclbin

# Tool locations
CXX:=$(XILINX_SDACCEL)/Vivado_HLS/lnx64/tools/gcc/bin/g++
CLC:=$(XILINX_SDACCEL)/bin/xocc
CPOWER := $(XILINX_SDACCEL)/gnu/ppc64le/4.9.3/lnx64/bin/powerpc64le-linux-gnu-g++

# Definition of include file locations
OPENCL12_INCLUDE:= $(XILINX_SDACCEL)/runtime/include/1_2

# Library directories
SDA_LIB:=$(XILINX_SDACCEL)/lib/lnx64.o
OPENCL_LIB:=$(XILINX_SDACCEL)/runtime/lib/x86_64
OPENCL_POWER_LIB:=$(XILINX_SDACCEL)/runtime/lib/ppc64le

# Nearest Neighbor Search Application
nearest_SRCS=./src/linear_search.c ./src/xcl.c
nearest_HDRS=./src/linear_search.h ./src/xcl.h
nearest_EXE=nearest
nearest_CXXFLAGS:=-I./src/ -I$(OPENCL12_INCLUDE)
nearest_LDFLAGS:=-L$(SDA_LIB) -L$(OPENCL_LIB) -lOpenCL -pthread
nearest_PLDFLAGS:= -L$(OPENCL_POWER_LIB) -lxilinxopencl -llmx6.0


# Nearest Neighbor  Kernel
krnl_nearest_SRCS=./src/krnl_linear_search.cpp
krnl_nearest_HDRS=
krnl_nearest_XCLBIN=nearest
krnl_nearest_XFLAGS=

EXES=nearest
XCLBINS=krnl_nearest


define mk_power

$(2): $($(1)_SRCS) $($(1)_HDRS)
	$(CPOWER) $($(1)_CXXFLAGS) -o $$@ $($(1)_SRCS) $($(1)_PLDFLAGS)

POWER_GOALS+=$(2)

endef

define mk_exe

$(2): $($(1)_SRCS) $($(1)_HDRS)
	$(CXX) $($(1)_CXXFLAGS) -o $$@ $($(1)_SRCS) $($(1)_LDFLAGS)

EXE_GOALS+=$(2)

endef

COLON=:
UNDERSCORE=_
X86:= X86
POWER:= POWER

define mk_xclbin

ifeq ($(4),X86)
	XCLBIN_GOALS+= $(XCLBIN_DIR)/$(1).$(2).$(subst $(COLON),$(UNDERSCORE),$(3)).xclbin
else
	SV_XCLBIN_GOALS+= $(XCLBIN_DIR)/$(1).$(2).$(subst $(COLON),$(UNDERSCORE),$(3)).xclbin
endif

$(XCLBIN_DIR)/$(1).$(2).$(subst $(COLON),$(UNDERSCORE),$(3)).xclbin: $($(1)_SRCS) $($(1)_HDRS)
	$(CLC) $($(1)_FLAGS) -o $$@ -t $(2) --xdevice $(3) $($(1)_SRCS)

endef

.PHONY: all
all: all-x86

$(foreach exe,$(EXES),$(eval $(call mk_exe,$(exe),$(exe).exe)))

$(foreach exe,$(EXES),$(eval $(call mk_power,$(exe),$(exe)_power.exe)))

$(foreach xclbin,$(XCLBINS),$(foreach xmode, $(XMODES),$(foreach xdevice,$(X86_DEVICES),$(eval $(call mk_xclbin,$(xclbin),$(xmode),$(xdevice),$(X86))))))

$(foreach xclbin,$(XCLBINS),$(foreach xmode, $(XMODES),$(foreach xdevice,$(POWER_DEVICES),$(eval $(call mk_xclbin,$(xclbin),$(xmode),$(xdevice),$(POWER))))))

.PHONY: all-x86
all-x86: $(XCLBIN_GOALS) $(EXE_GOALS)

.PHONY: sv_all
sv_all: $(SV_XCLBIN_GOALS) $(POWER_GOALS) $(EXE_GOALS)

.PHONY: clean
clean:
	rm -rf $(EXE_GOALS) $(XCLBIN_GOALS) $(SV_XCLBIN_GOALS) sdaccel* *.ll

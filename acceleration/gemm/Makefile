# the General Matrix Multiply Application
COMMON_REPO =../..

include $(COMMON_REPO)/utility/boards.mk
include $(COMMON_REPO)/libs/xcl/xcl.mk
include $(COMMON_REPO)/libs/opencl/opencl.mk

# General Matrix Multiply  Host Application
gemm_SRCS=src/gemm.cpp $(xcl_SRCS)
gemm_CXXFLAGS=-Wall -I./src/ -I$(XILINX_SDACCEL)/Vivado_HLS/include/ $(opencl_CXXFLAGS) $(xcl_CXXFLAGS)
gemm_LDFLAGS=$(opencl_LDFLAGS)

EXES=gemm

# General Matrix Multiply xclbin
gemm0_XOS=gemm0
gemm0_LDCLFLAGS= -I./src/ --xp misc:map_connect=add.kernel.krnl_0.m00_axi.core.OCL_REGION_0.M00_AXI  --xp misc:map_connect=add.kernel.krnl_0.m01_axi.core.OCL_REGION_0.M01_AXI --xp vivado_prop:run.dr_krnl_0_0_synth_1.STEPS.SYNTH_DESIGN.TCL.PRE=$(PWD)/src/presynth.tcl --xp vivado_prop:run.impl_1.STEPS.OPT_DESIGN.TCL.PRE=$(PWD)/src/ku115-constraints-pblock-1kernel.tcl --xp vivado_prop:run.impl_1.STEPS.OPT_DESIGN.ARGS.DIRECTIVE=Explore --xp vivado_prop:run.impl_1.STEPS.PLACE_DESIGN.ARGS.DIRECTIVE=Explore --xp vivado_prop:run.impl_1.STEPS.PHYS_OPT_DESIGN.IS_ENABLED=true --xp vivado_prop:run.impl_1.STEPS.PHYS_OPT_DESIGN.ARGS.DIRECTIVE=AggressiveExplore --xp vivado_prop:run.impl_1.STEPS.ROUTE_DESIGN.ARGS.DIRECTIVE=Explore --nk kernelSgemm_0:1:krnl_0 
gemm0_NDEVICES=xilinx:xil-accel-rd-vu9p:4ddr-xpr xilinx:adm-pcie-ku3:2ddr-xpr xilinx:adm-pcie-7v3:1ddr
gemm0_NTARGETS=sw_emu

XCLBINS=gemm0

# check
check_EXE=gemm
check_XCLBINS=gemm0
check_ARGS=64 64 64
check_NDEVICES=$(gemm0_NDEVICES)

CHECKS=check

#Reporting warning if targeting for sw_emu
ifneq (,$(findstring sw_emu,$(TARGETS)))
$(warning WARNING:RTL Kernels do not support sw_emu TARGETS. Please use hw_emu for running RTL kernel Emulation)
endif

include $(COMMON_REPO)/utility/rules.mk

xclbin/gemm0.hw.xilinx_xil-accel-rd-ku115_4ddr-xpr.xo: src/kernelSgemm_0.xo
	mkdir xclbin 2>/dev/null || true
	cp src/kernelSgemm_0.xo xclbin/gemm0.hw.xilinx_xil-accel-rd-ku115_4ddr-xpr.xo

xclbin/gemm0.hw_emu.xilinx_xil-accel-rd-ku115_4ddr-xpr.xo: src/kernelSgemm_0.xo
	mkdir xclbin 2>/dev/null || true
	cp src/kernelSgemm_0.xo xclbin/gemm0.hw_emu.xilinx_xil-accel-rd-ku115_4ddr-xpr.xo


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

# General Matrix Multiply Kernel
gemm0_SRCS=src/gemm.cpp
gemm0_CLFLAGS= -I./src/ --xp \
misc:map_connect=add.kernel.krnl_0.m00_axi.core.OCL_REGION_0.M00_AXI  --xp misc:map_connect=add.kernel.krnl_0.m01_axi.core.OCL_REGION_0.M01_AXI --xp vivado_prop:run.dr_krnl_0_0_synth_1.STEPS.SYNTH_DESIGN.TCL.PRE=presynth.tcl --xp vivado_prop:run.impl_1.STEPS.OPT_DESIGN.TCL.PRE=ku115-constraints-pblock-1kernel.tcl --xp vivado_prop:run.impl_1.STEPS.OPT_DESIGN.ARGS.DIRECTIVE=Explore --xp vivado_prop:run.impl_1.STEPS.PLACE_DESIGN.ARGS.DIRECTIVE=Explore --xp vivado_prop:run.impl_1.STEPS.PHYS_OPT_DESIGN.IS_ENABLED=true --xp vivado_prop:run.impl_1.STEPS.PHYS_OPT_DESIGN.ARGS.DIRECTIVE=AggressiveExplore--xp vivado_prop:run.impl_1.STEPS.ROUTE_DESIGN.ARGS.DIRECTIVE=Explore --nk kernelSgemm_0:1:krnl_0 --save-temps -l --debug --platform xilinx:xil-accel-rd-ku115:4ddr-xpr_4_0.xpfm kernelSgemm_0.xo

XOS=gemm0

# General Matrix Multiply xclbin
gemm0_XOS=gemm0

XCLBINS=gemm0

# check
check_EXE=gemm
check_XCLBINS=gemm0

CHECKS=check

include $(COMMON_REPO)/utility/rules.mk

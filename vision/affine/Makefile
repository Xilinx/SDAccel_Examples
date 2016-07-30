DSA				   			:= xilinx:adm-pcie-7v3:1ddr:2.0

XILINX_CXX					:= $(XILINX_OPENCL)/lnx64/tools/gcc/bin/g++
XILINX_CC					:= $(XILINX_OPENCL)/lnx64/tools/gcc/bin/gcc
XOCC						:= $(XILINX_OPENCL)/bin/xocc

XILINX_CXXFLAGS			:= -g -Wall -std=c++0x -lrt -D XILINX


GTK_LIBS						= -pthread -lgtk-x11-2.0 -lgdk-x11-2.0 -latk-1.0 -lgio-2.0 -lpangoft2-1.0 -lpangocairo-1.0 -lgdk_pixbuf-2.0 -lcairo -lpango-1.0 -lfreetype -lfontconfig -lgobject-2.0			\
                          -lgmodule-2.0 -lgthread-2.0 -lrt -lglib-2.0

MINCS							= -I/usr/include/atk-1.0 -I/usr/include/gtk-2.0 -I/usr/lib64/gtk-2.0/include -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/glib-2.0 -I/usr/lib64/glib-2.0/include \
						        -I/usr/include/cairo -I/usr/include/pango-1.0 -Iinclude -Imodded_include -Ilibs/dicom -Ilibs/tpc -Ilibs/nifti -I.

XILINX_OPENCL_INC 		:= $(XILINX_OPENCL)/runtime/include/1_2
XILINX_OPENCL_LIB			:= $(XILINX_OPENCL)/runtime/lib/x86_64

XILINX_CCFLAGS    		:= -g -std=c99 -DHAVE_CONFIG_H -DHAVE_ZLIB -Wall -lrt -lm -Wno-write-strings -D XILINX


CLFLAGS_HW					:= -g --xdevice $(DSA) -D USE_OPENCL -t hw
CLFLAGS_EM					:= -g --xdevice $(DSA) -D USE_OPENCL -t sw_emu




xilinx_sw:		affine_raw_xilinx_sw

xilinx_em: 		affine_raw_xilinx xclbin_em

xilinx_em_gui:	affine_raw_xilinx_gui xclbin_em

xilinx_hw: 		affine_raw_xilinx xclbin_hw

xilinx_hw_gui: affine_raw_xilinx_gui xclbin_hw


xclbin_hw: affine_kernel.cl
	$(XOCC) $(CLFLAGS_HW) $< -o $@

xclbin_em: affine_kernel.cl
	$(XOCC) $(CLFLAGS_EM) $< -o $@


affine_raw_xilinx_sw: affine_raw_host.cpp affine_kernel.cl
	$(XILINX_CXX) $(XILINX_CXXFLAGS) -D C_COMPILE -I$(XILINX_OPENCL_INC) -L$(XILINX_OPENCL_LIB) -lOpenCL -o $@ affine_raw_host.cpp

affine_raw_xilinx: affine_raw_host.cpp
	$(XILINX_CXX) $(XILINX_CXXFLAGS) -DUSE_OPENCL -I$(XILINX_OPENCL_INC) -L$(XILINX_OPENCL_LIB) -lOpenCL -o $@ affine_raw_host.cpp

affine_raw_xilinx_gui: affine_raw_host.cpp
	$(XILINX_CXX) $(XILINX_CXXFLAGS) -DUSE_OPENCL -DUSE_GUI -I$(XILINX_OPENCL_INC) -L$(XILINX_OPENCL_LIB) $(MINCS) $(GTK_LIBS) -lOpenCL -o $@ affine_raw_host.cpp


clean: clean_xilinx

clean_xilinx:
	rm -rf affine_raw_xilinx affine_raw_xilinx_gui prj_affine_build kernel.xclbin affine xocc*.log sdaccel* .Xil _xocc_affine_kernel_affine_kernel.dir _xocc__temp_affine.dir *~ xclbin* shared*



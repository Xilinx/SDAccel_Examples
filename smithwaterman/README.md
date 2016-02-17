						+++++++++++++++++++++++++++++++++++++++++++++++++
   				    		    XILINX Smtih-Waterman HLS SDAccel Sample
						+++++++++++++++++++++++++++++++++++++++++++++++++



---------------------
   Pre-Requisities
---------------------

1. ZeroMQ - 4.0.5 (Source Build) 
2. Xilinx - SDAccel 2015.3
3. Zlib-devel  


Note :

	a. "Login as a root user to use this source"
	b. cd smithwaterman/


---------------------
  Environment Setup
---------------------

1. To setup system environment 

	a. Run -  source install.sh   
   
    "This script installs ZeroMQ-4.0.5 library and initializes SDAccel system environment using setenv.sh (Interactive Script)"

2.  zlib1g-dev library (By default this library exists), in case of build errors during host compilation, follow below instructions.
	
	a. yum install zlib-devel (CentOS)

				
---------------------
   Host Source
---------------------

FPGA FLOW :

1. src/main.cpp - (Entry point to SWAN-HLS intel/fpga execution)
2. src/smithwaterman.cpp - (Triggers DNA generation and kernel invokation)
3. src/genseq.cpp - (Generates reference & read DNA sequences)
4. src/matcharray.cpp - (Processes maxscore matrix)

INTEL FLOW:

1. src/intel/sc_demo.c - (Entry point for SWAN intel intrinsic flow)
2. src/intel/ssw.c - (SWAN intrinsic implementaiton)



---------------------
   Kernel Source
--------------------- 

1. src/opencl_sw_maxscore_systolic.cpp - (SWAN C/C++ HLS Systolic kernel implementation) 
2. src/opencl_sw_maxscore_basic.cpp -    (SWAN C/C++ HLS Basic kernel implementation) 



---------------------
  Build & Execution
---------------------

1. To build SWAN-HLS host executable  

	a. Run - source clean.sh
	b. Run - source build_host.sh 

    "This script builds host executable "opencl_sw_maxscore.exe , this script can be used to build executable in case of modifications pertains to host source code"

 
2. To build SWAN-HLS kernel binary 

	a. Run - source build_kernel.sh  (Interactive Script)

	   CLI Output : "Choose SDAccel Kernel Build Target (CPU|FPGA)"

	b. Select the flow CPU/FPGA
	   b.i.  CLI Output : "SWAN-HLS Basic kernel or Systolic kernel (Choose (Basic/Systolic))"
	   b.ii. Choose Basic version or Systolic version of the SWAN algorithm
	 

Note : SWAN-HLS kernel has two flows,
         
         a. Basic flow - Naive Smith-Waterman HLS kernel which takes around 1182ms kernel execution time on FPGA.
	 b. Systolic flow - This is an optimized Smith-Waterman HLS kernel which takes around 10ms kernel execution time on FPGA.  

	 

3. To execute/run SWAN-HLS SDAccel Sample

	a. Run - ./opencl_sw_maxscore.exe opencl_sw_maxscore_basic_cpu.xclbin (CPU Basic Flow)
	b. Run - ./opencl_sw_maxscore.exe opencl_sw_maxscore_systolic_cpu.xclbin (CPU Systolic Flow)
	c. Run - ./opencl_sw_maxscore.exe opencl_sw_maxscore_basic_fpga.xclbin (FPGA Basic Flow)
	c. Run - ./opencl_sw_maxscore.exe opencl_sw_maxscore_systolic_fpga.xclbin (FPGA Systolic Flow)
	d. Run - ./opencl_sw_maxscore.exe -h (Prints various options)










Affine Transform
======================================

This readme file contains these sections:

1. OVERVIEW
2. SOFTWARE TOOLS AND SYSTEM REQUIREMENTS
3. DESIGN FILE HIERARCHY
4. INSTALLATION AND OPERATING INSTRUCTIONS
5. OTHER INFORMATION (OPTIONAL)
6. SUPPORT
7. LICENSE
8. CONTRIBUTING
9. Acknowledgements
10. REVISION HISTORY

## 1. OVERVIEW

Affine transformation is a linear mapping method that preserves points, straight lines, and planes. Sets of parallel lines remain parallel after an affine transformation. The affine transformation technique is typically used to correct for geometric distortions or deformations that occur with non-ideal camera angles.

The demo performs the following transformation on a 512 by 512, 16 bits per pixels grayscale, raw MRI image:
– 30 degree X rotation
– 50% X and Y scaling

## 2. SOFTWARE TOOLS AND SYSTEM REQUIREMENTS
Tested on: 
* Alpha Data ADM-PCIE-7V3
* SDAccel 2015.4

## 3. DESIGN FILE HIERARCHY
```
	|   affine_kernel.cl							: Original Source Code
	|   affine_kernel_baseline.cl					: Non-optimized SDAccel 
	|   affine_kernel_inner_loop_unroll.cl			: First Opitmization: Loop Unrolling
	|   affine_kernel_output_line_buffer.cl			: Second Optimization: Output Line Buffers. 
	|   affine_raw_host.cpp							: Host Code
	|   CONTRIBUTING.md								: Contributing Instructions
	|   CT-MONO2-16-brain.raw						: Input Test Image, Raw format MRI scan. 
	|   LICENSE.md									: Lincese File
	|   Makefile									: Makefile Build Script
	|   README.md									: Readme
	|   run_sda_em_build.tcl						: SDAccel TCL script to build emulation.
	|   run_sda_hw_build.tcl						: SDAccel TCL script to build hw binary. 
```

## 4. INSTALLATION AND OPERATING INSTRUCTIONS

1. Set the `$XILINX_OPENCL` to your SDAccel installation path.

2. Makefile Flow
Run `make xilinx_em` to execute a software cpu emulation 
Run `make xilinx_hw` to complile the binaries for HW run. 

3. TCL Flow
Run `sdaccel run_sda_em_build` to execute a software cpu emulation 
Run `sdaccel run_sda_hw_build` to complile the binaries for HW run. 

## 5. OTHER INFORMATION

For more information check here: 
[SDAccel User Guides][]

#### Performance Results: 

**Unoptimized Results** 

Task			|	Xilinx Execution Time (in ns)	|	GTX 780 Execution Time (in ns)
------------------------|---------------------------------------|------------------------------------
Host to Device		|	1,009,806			|	1,841,513
Device to Host		|	1,593,508			|	8,305,993
Device Kernel 		|	456,671,835			|	145,980,292
Total Execution 	|	459,275,151			|	156,127,805
Frames per Sec		|	2.2				|	6.9

**Optimized Results** 

Task			|	Xilinx Execution Time (in ns)	|	GTX 780 Execution Time (in ns)
------------------------|---------------------------------------|------------------------------------
Host to Device		|	1,009,087			|	1,828,606
Device to Host		|	774,714				|	563,740
Device Kernel 		|	46,460,532			|	195,938,535
Total Execution 	|	48,244,355			|	198,330,886
Frames per Sec		|	21.5				|	5.1

*Benchmarks taken against a GTX 780, using CUDA 7.5

## 6. SUPPORT
For questions and to get help on this project or your own projects, visit the [SDAccel Forums][]. 

## 7. License
The source for this project is licensed under the [3-Clause BSD License][]

## 8. Contributing code
Please refer to and read the [Contributing][] document for guidelines on how to contribute code to this open source project. The code in the `/master` branch is considered to be stable, and all pull-requests should be made against the `/develop` branch.

## 9. Acknowledgements
The Library is written by developers at [Xilinx](http://www.xilinx.com/) with other contributors listed below:
http://cis.k.hosei.ac.jp/~wakahara  

## 10. REVISION HISTORY

Date		|	Readme Version	|	Revision Description
----------------|-----------------------|-------------------------
MAR2016		|	1.0		|	Initial Xilinx release




[Contributing]: CONTRIBUTING.md 
[3-Clause BSD License]: LICENSE.md
[SDAccel Forums]: https://forums.xilinx.com/t5/SDAccel/bd-p/SDx
[SDAccel User Guides]: http://www.xilinx.com/support/documentation-navigation/development-tools/software-development/sdaccel.html?resultsTablePreSelect=documenttype:SeeAll#documentation 

Affine Example 
======================

This README file contains the following sections:

1. OVERVIEW
2. SOFTWARE TOOLS AND SYSTEM REQUIREMENTS
3. DESIGN FILE HIERARCHY
4. INSTALLATION AND OPERATING INSTRUCTIONS
5. SUPPORT
6. LICENSE
7. ACKNOWLEDGEMENTS
8. REVISION HISTORY


## 1. OVERVIEW
Affine transformation is a linear mapping method that preserves points, straight lines, and planes. Sets of parallel lines remain parallel after an affine transformation. The affine transformation technique is typically used to correct for geometric distortions or deformations that occur with non-ideal camera angles. The demo performs a 30 degree X rotation and a 50% X and Y scaling on a 512 by 512, 16 bits per pixels grayscale, raw MRI image.

### PERFORMANCE
Task|Xilinx Execution Time (in ns)|GTX 780 Execution Time (in ns)
----|-----|-----
Host to Device|1,009,087|1,828,606
Device to Host|774,714|563,740
Device to Kernel|46,460,532|195,938,535
Total Execution|48,244,355|198,330,886
Frames per Second|21.5|5.1
## 2. SOFTWARE AND SYSTEM REQUIREMENTS
Board | Software Version
------|---------
Alpha Data ADM-PCIE-7V3|SDAccel 2016.2


## 3. DESIGN FILE HIERARCHY
Application code is located in the src directory. Accelerator binary files will be compiled to the xclbin directory. The xclbin directory is required by the Makefile and its contents will be filled during compilation.

## 4. INSTALLATION AND OPERATING INSTRUCTIONS
### Compilation for x86 based servers
1. make all

	Launches compilation both emulation and board execution modes of the application for all supported boards.To limit or change the boards for compilation, edit the utility/boards.mk file located at the top level of this repository.

2. Executing emulation flows
Set the following environment variable to create a emconfig.json file
```
export LD_LIBRARY_PATH=$XILINX_SDACCEL/runtime/lib/x86_64/:$LD_LIBRARY_PATH
export XCL_EMULATION_MODE=true
emconfigutil --xdevice 'xilinx:adm-pcie-ku3:2ddr:3.1' --nd 1
```
Run the application as
```
make xilinx_em
```
The choices for emulation flow are
		- sw_emu = software emulation
		- hw_emu = hardware emulation
*NOTE:* The software emulation flow is a functional correctness check only. It does not estimate the performance of the application in hardware.
The hardware emulation flow is a cycle accurate simulation of the hardware generated for the application. As such, it is expected for this simulation to take a long time.
It is recommended that for this example the user skips running hardware emulation or modifies the example to work on a reduced data set.
3. Running the application on a board hosted by Nimbix from a remote system

	Install the Xilinx Runtime for board in Nimbix using the xbinst utility in SDAccel
```
xbinst -x 'xilinx:adm-pcie-ku3:2ddr:3.1' -d .
mv xbinst/pkg/pcie/runtime . 
rm -rf xbinst
```
Run the nimbix-run.py script provided in the utility/nimbix directory at the top level of this repository
```
make xilinx_hw
```

	Only the Alpha Data ADM-PCIE-KU3 card is supported by this method.
4. Running the application from within Nimbix

	Follow the instructions in the [Nimbix Getting Started Guide][]

### Compilation for IBM POWER servers
1. View the SuperVessel [Walkthrough Video][]

2. make all-POWER
	Launches compilation both emulation and board execution modes of the application for all supported boards.

## 5. SUPPORT
For more information about SDAccel check the [SDAccel User Guides][]

For questions and to get help on this project or your own projects, visit the [SDAccel Forums][].

## 6. LICENSE
The source for this project is licensed under the [3-Clause BSD License][]

## 7. ACKNOWLEDGEMENTS
This example is written by developers at
- [Xilinx](http://www.xilinx.com)
- [Wakahara Project](http://cis.k.hosei.ac.jp/~wakahara)

## 8. REVISION HISTORY
Date | README Version | Description
-----|----------------|------------
MAR2016|1.0|Initial Xilinx release
[3-Clause BSD License]: LICENSE.md
[SDAccel Forums]: https://forums.xilinx.com/t5/SDAccel/bd-p/SDx
[SDAccel User Guides]: http://www.xilinx.com/support/documentation-navigation/development-tools/software-development/sdaccel.html?resultsTablePreSelect=documenttype:SeeAll#documentation
[Nimbix Getting Started Guide]: http://www.xilinx.com/member/sdaccel_ea_40hr/Getting_Started_with_SDAccel_on_Nimbix_cloud.pdf
[Walkthrough Video]: http://bcove.me/6pp0o482
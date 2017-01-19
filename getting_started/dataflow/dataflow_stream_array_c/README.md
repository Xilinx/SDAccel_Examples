Dataflow Using HLS Stream
======================

This README file contains the following sections:

1. OVERVIEW
2. HOW TO DOWLOAD THE REPOSITORY
3. SOFTWARE TOOLS AND SYSTEM REQUIREMENTS
4. DESIGN FILE HIERARCHY
5. COMPILATION AND EXECUTION ON X86 SERVERS
6. COMPILATION AND EXECUTION ON IBM POWER SERVERS
7. SUPPORT
8. LICENSE AND CONTRIBUTING TO THE REPOSITORY
9. ACKNOWLEDGEMENTS
10. REVISION HISTORY


## 1. OVERVIEW
This is simple example of Multiple Stages Vector Addition to demonstrate Array of Stream usage in HLS C Kernel Code.

***KEY CONCEPTS:*** Array of Stream

***KEYWORDS:*** dataflow, hls::stream<>

## 2. HOW TO DOWNLOAD THE REPOSITORY
To get a local copy of the SDAccel example repository, clone this repository to the local system with the following command:
```
git clone https://github.com/Xilinx/SDAccel_Examples examples
```
where examples is the name of the directory where the repository will be stored on the local system.This command needs to be executed only once to retrieve the latest version of all SDAccel examples. The only required software is a local installation of git.

*NOTE: If the destination of the repository is the user home directory in the Nimbix SDAccel developer instance, the command will need to be executed for every session. Contents of the user home directory in the Nimbix SDAccel developer instance are not preserved between user sessions. Only files placed in the /data directory are kept between SDAccel development sessions.*
## 3. SOFTWARE AND SYSTEM REQUIREMENTS
Board | Device Name | Software Version | NIMBIX Machine Type
------|-------------|------------------|--------------------
Alpha Data ADM-PCIE-7V3|xilinx:adm-pcie-7v3:1ddr:3.0|SDAccel 2016.3|nx2
Alpha Data ADM-PCIE-KU3|xilinx:adm-pcie-ku3:2ddr-xpr:3.2|SDAccel 2016.3|nx1
Xilinx KU115|xilinx:xil-accel-rd-ku115:4ddr-xpr:3.2|SDAccel 2016.3|nx3


Board targeted by default = ***xilinx:xil-accel-rd-ku115:4ddr-xpr:3.2***

*NOTE:* The board/device used for compilation can be changed by adding the DEVICES variable to the make command as shown below
```
make DEVICES=<device name>
```
where the *DEVICES* variable accepts either 1 device from the table above or a comma separated list of device names.
## 4. DESIGN FILE HIERARCHY
Application code is located in the src directory. Accelerator binary files will be compiled to the xclbin directory. The xclbin directory is required by the Makefile and its contents will be filled during compilation. A listing of all the files in this example is shown below

```
.
├── description.json
├── Makefile
├── README.md
├── src
│   ├── host.cpp
│   └── N_stage_adders.cpp
└── xclbin

2 directories, 5 files
```

## 5. COMPILATION AND EXECUTION FOR X86 SERVERS
### Compiling for Application Emulation
As part of the capabilities available to an application developer, SDAccel includes environments to test the correctness of an application at both a software functional level and a hardware emulated level.
These modes, which are named sw_emu and hw_emu, allow the developer to profile and evaluate the performance of a design before compiling for board execution.
It is recommended that all applications are executed in at least the sw_emu mode before being compiled and executed on an FPGA board.
```
make TARGETS=<sw_emu|hw_emu> all
```
where
```
	sw_emu = software emulation
	hw_emu = hardware emulation
```
*NOTE:* The software emulation flow is a functional correctness check only. It does not estimate the performance of the application in hardware.
The hardware emulation flow is a cycle accurate simulation of the hardware generated for the application. As such, it is expected for this simulation to take a long time.
It is recommended that for this example the user skips running hardware emulation or modifies the example to work on a reduced data set.
### Executing Emulated Application 
***Recommended Execution Flow for Example Applications in Emulation*** 

The makefile for the application can directly executed the application with the following command:
```
make TARGETS=<sw_emu|hw_emu> check

```
where
```
	sw_emu = software emulation
	hw_emu = hardware emulation
```
If the application has not been previously compiled, the check makefile rule will compile and execute the application in the emulation mode selected by the user.

***Alternative Execution Flow for Example Applications in Emulation*** 

An emulated application can also be executed directly from the command line without using the check makefile rule as long as the user environment has been properly configured.
To manually configure the environment to run the application, set the following
```
export LD_LIBRARY_PATH=$XILINX_SDX/runtime/lib/x86_64/:$LD_LIBRARY_PATH
export XCL_EMULATION_MODE=<sw_emu|hw_emu>
emconfigutil --xdevice 'xilinx:xil-accel-rd-ku115:4ddr-xpr:3.2' --nd 1
```
Once the environment has been configured, the application can be executed by
```
./host
```
This is the same command executed by the check makefile rule
### Compiling for Application Execution in the FPGA Accelerator Card
The command to compile the application for execution on the FPGA acceleration board is
```
make all
```
The default target for the makefile is to compile for hardware. Therefore, setting the TARGETS option is not required.
*NOTE:* Compilation for application execution in hardware generates custom logic to implement the functionality of the kernels in an application.It is typical for hardware compile times to range from 30 minutes to a couple of hours.
### Executing the Application in the FPGA Accelerator Card
The developer instance hosting the SDAccel tools on Nimbix is not directly connected to an FPGA accelerator card.
FPGA Accelerator cards are available as part of the SDAccel Runtime application. There are several ways of executing an application on the available cards:

***Submit the application from the developer to runtime instances (recommended flow)***
* Create a credentials file for the runtime machine based on your Nimbix username and API key. For more information on how to obtain the API key, refer to [Nimbix Application Submission README][]. The credentials file ( ~/.nimbix_creds.json ) should look like
```
{
	"username": "<username>",
	"api-key": "<apikey>"
}
```

where the values for username and apikey have been set to the values from your Nimbix account.

*NOTE:* The home directory of a SDAccel developer instance is not persistent across sessions. Only files stored in the /data directory are kept between sessions.It is recommended that a copy of the nimbix_creds.json file be stored in the /data directory and copied to the appropriate location in the home directory at the start of each development session.
* Launch the application
```
make check
```
***Launch the application from a remote system outside of the Nimbix environment***
* Follow the instructions in [Nimbix Application Submission README][]

* Use the following command to launch the application from the users terminal (on a system outside of the Nimbix environment)
```
../../../utility/nimbix/nimbix-run.py -- ./host
```

***Copy the application files from the Developer to Runtime instances on Nimbix***
* Copy the application *.exe file and xclbin directory to the /data directory
* Launch the application using the Nimbix web interface as described in [Nimbix Getting Started Guide][]
* Make sure that the application launch options in the Nimbix web interface reflect the applications command line syntax
```
./host
```

## 6. COMPILATION AND EXECUTION FOR IBM POWER SERVERS
View the SuperVessel [Walkthrough Video][] to become familiar with the environment.

Compile the application with the following command
```
make ARCH=POWER all
```

## 7. SUPPORT
For more information about SDAccel check the [SDAccel User Guides][]

For questions and to get help on this project or your own projects, visit the [SDAccel Forums][].

To execute this example using the SDAccel GUI, follow the setup instructions in [SDAccel GUI README][]


## 8. LICENSE AND CONTRIBUTING TO THE REPOSITORY
The source for this project is licensed under the [3-Clause BSD License][]

To contribute to this project, follow the guidelines in the [Repository Contribution README][]

## 9. ACKNOWLEDGEMENTS
This example is written by developers at
- [Xilinx](http://www.xilinx.com)

## 10. REVISION HISTORY
Date | README Version | Description
-----|----------------|------------
DEC2016|1.0|Initial Xilinx Release

[3-Clause BSD License]:../../../LICENSE.txt
[SDAccel Forums]: https://forums.xilinx.com/t5/SDAccel/bd-p/SDx
[SDAccel User Guides]: http://www.xilinx.com/support/documentation-navigation/development-tools/software-development/sdaccel.html?resultsTablePreSelect=documenttype:SeeAll#documentation
[Nimbix Getting Started Guide]: http://www.xilinx.com/support/documentation/sw_manuals/xilinx2016_2/ug1240-sdaccel-nimbix-getting-started.pdf
[Walkthrough Video]: http://bcove.me/6pp0o482
[Nimbix Application Submission README]:../../../utility/nimbix/README.md
[Repository Contribution README]:../../../CONTRIBUTING.md
[SDaccel GUI README]:../../../GUIREADME.md

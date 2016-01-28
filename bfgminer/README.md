Bfgminer Bitcoin Mining Application
===============================

This is a patch and build infrastructure for building the bfgminer
application.  It includes one pre-built binary for the
xilinx:adm-pcie-7v3:1ddr:2.1 dsa and SDAccel 2015.4.

The main algorithm characteristics of this application are
1. SHA256 double hashing with poclbm kernel
4. Achieved performance = 80 Megahashes / second

Changelog
----------
1/28/2016 - Initial Release

Compiling the Application
---------------------------
This application is compiled using the a build script.
To compile the application:

```
$ cd <path-to-bfgminer>
$ ./build.sh
```

Executing the Application
---------------------------

```
$ source <path-to>/setup.sh # Setup Xilinx Environment
$ export LD_LIBRARY_PATH=$PWD/build/jansson-2.7/lib:$LD_LIBRARY_PATH
$ cd build/bfgminer-5.4.1/
$ ./bfgminer -S opencl:auto --set OCL:goffset=false -w2048 -v4 \
    --benchmark --debug --text-only
```

Additional Information
------------------------

The precompiled kernel was created with the following xocc invocation.

```
xocc -o poclbm-69ce3afpga0v4w2048l8pOpenCL1_0.bin opencl/poclbm.cl \ 
  -t hw --xdevice xilinx:adm-pcie-7v3:1ddr:2.1 --nk search:3 \
  -D WORKSIZE=2048 -DVECTORS=VECTORS4
```

To build additional kernels set the vector width to environment variable Z, the
worksize to environment variable Y and the the number of compute units to
environment variable X.

```
xocc -o poclbm-69ce3afpga0v${Z}w${Y}l8pOpenCL1_0.bin opencl/poclbm.cl \ 
  -t hw --xdevice xilinx:adm-pcie-7v3:1ddr:2.1 --nk search:${X} \
  -D WORKSIZE=${Y} -DVECTORS=${Z}
```

To run additional kernels

```
$ ./bfgminer -S opencl:auto --set OCL:goffset=false -w${Y} -v{Z} \
    --benchmark --debug --text-only
```

Files in the Example
---------------------
Tarballs and Patches
- src/bfgminer-5.4.1.zip
- src/jansson-2.7.tar.gz
- src/uthash-044474afe5a57db4302cc722de476d20d1ab70c7.zip
- src/ocl.c
- src/poclbm-69ce3afpga0v4w2048l8pOpenCL1_0.bin

Build Script
- build.sh

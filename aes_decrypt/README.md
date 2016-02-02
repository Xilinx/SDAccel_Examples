AES Decryption Example
===============================

This is an optimized implementation of an AES-128 ECB Encrypt in Software, followed 
by OpenCL Decryption targeting execution on an SDAccel supported FPGA acceleration card.


Achieved performance was measured on an Alpha Data ADM-PCI-7v3 card.

Changelog
----------
1/29/2016 - Initial Release

Compiling the Application
---------------------------
This application is compiled using the SDAccel script mode.
To compile the application:

```
sdaccel aes_decrypt.tcl
```
The target board can be changed by editing *huffman.tcl*

Executing the Application
---------------------------
```
aesdecrypt_example.exe --platform Xilinx --device fpga0 --kernel bin_aes_decrypt.xclbin data/input.bmp
```

Files in the Example
---------------------
Example data
- data/input.bmp

Application host code
- aes_app.cpp
- aes_app.h
- aes_ecb.cpp
- aes_ecb.h
- main.cpp
- common/xcl.cpp
- common/xcl.h
- common/logger.cpp
- common/logger.h
- common/cmdlineparser.cpp
- common/cmdlineparser.h
- common/simplebmp.cpp
- common/simplebmp.h

Kernel code
- krnl_aes.cl

Compilation Script
- aes_decrypt.tcl

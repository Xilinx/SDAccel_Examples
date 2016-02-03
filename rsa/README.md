RSA Decryption Example
===============================

This is an optimized implementation of a RSA Decryption algorithm
targeting execution on an SDAccel supported FPGA acceleration card.

The main algorithm characteristics of this application are

1. RSA Decryption [https://en.wikipedia.org/wiki/RSA_%28cryptosystem%29]
2. Input includes 1024 bits ciphertext, key
3. Target performance = 0.47 ms

Achieved performance was measured on an Alpha Data ADM-PCI-7v3 card.

Changelog
----------
1/29/2016 - Initial Release

Compiling the Application
---------------------------
This application is compiled using the SDAccel script mode.
To compile the application:

```
sdaccel rsa.tcl
```
The target board can be changed by editing *rsa.tcl*

Executing the Application
---------------------------
```
rsa_example.exe --platform Xilinx --device fpga0 --kernel bin_rsa.xclbin --in data/0_0_1024_key.cip --out data/0_out.msg --key data/0_1024_key.pem
```

Files in the Example
---------------------
Example data
- data/0_0_1024_key.cip 
- data/0_out.msg 
- data/0_1024_key.pem

Application host code
- rsa_app.cpp
- rsa_app.h
- main.cpp
- common.cpp
- common.h
- cmdlineparser.cpp
- cmdlineparser.h
- logger.cpp
- logger.h
- xcl.c
- xcl.h

Kernel code
- krnl_rsa.cl

Compilation Script
- rsa.tcl

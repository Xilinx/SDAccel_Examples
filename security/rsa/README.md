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
7/5/2016  - Conversion to Makefile based execution

Compiling the Application
---------------------------
his application is compiled using the SDAccel Makefile flow

To compile the application for execution on x86 servers/cloud:

```
make all
```

To compile the application for execution on POWER8 servers/cloud:
```
make sv_all
```

The target board and platforms are available in the utility/boards.mk file. The utility directory is located at the root of this repository.

Executing the Application
---------------------------
```
rsa_example.exe --platform Xilinx --device fpga0 --kernel bin_rsa.xclbin --in data/0_0_1024_key.cip --out data/0_out.msg --key data/0_1024_key.pem
```

Files in the Example
---------------------
Application code is located in the src directory.
Accelerator binary files are located in the xclbin directory. This directory is required by the Makefile. The contents of the directory are generated during compilation.

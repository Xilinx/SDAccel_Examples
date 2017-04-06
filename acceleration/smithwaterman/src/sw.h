/**********
Copyright (c) 2017, Xilinx, Inc.
All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice,
this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice,
this list of conditions and the following disclaimer in the documentation
and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors
may be used to endorse or promote products derived from this software
without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**********/
#include <string.h>
#ifndef _SW_H
#define _SW_H

#define GAP -1
#define MATCH 2
#define MISS_MATCH -1
#define ABSMAXCOST MATCH

#define MINVAL -32000


#define UINTSZ sizeof(unsigned int)
#define BPSZ 2
#define UINTNUMBP ((UINTSZ*8)/(BPSZ))

#define LOG2MAXPE 5
#define MAXPE (1<<LOG2MAXPE)
#define MAXROW 128
#define MAXCOL 256
#define NUMPACKED 16
#define PACKEDSZ ((MAXROW + MAXCOL)) / (UINTNUMBP)
#define READREFUINTSZ(X, Y) ((((X) + (Y)))/(UINTNUMBP))
#define NUMITER 1024

//A-0, C-1, G-2, T-3
const char bases[5] = "ACGT";
#endif


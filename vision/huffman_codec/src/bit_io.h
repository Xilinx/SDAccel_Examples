/*******************************************************************************
Vendor: Xilinx
Associated Filename: bit_io.h
Purpose: SDAccel huffman codec example
Revision History: January 29, 2016

*******************************************************************************
Copyright (C) 2015 XILINX, Inc.

This file contains confidential and proprietary information of Xilinx, Inc. and
is protected under U.S. and international copyright and other intellectual
property laws.

DISCLAIMER
This disclaimer is not a license and does not grant any rights to the materials
distributed herewith. Except as otherwise provided in a valid license issued to
you by Xilinx, and to the maximum extent permitted by applicable law:
(1) THESE MATERIALS ARE MADE AVAILABLE "AS IS" AND WITH ALL FAULTS, AND XILINX
HEREBY DISCLAIMS ALL WARRANTIES AND CONDITIONS, EXPRESS, IMPLIED, OR STATUTORY,
INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, NON-INFRINGEMENT, OR
FITNESS FOR ANY PARTICULAR PURPOSE; and (2) Xilinx shall not be liable (whether
in contract or tort, including negligence, or under any other theory of
liability) for any loss or damage of any kind or nature related to, arising under
or in connection with these materials, including for any direct, or any indirect,
special, incidental, or consequential loss or damage (including loss of data,
profits, goodwill, or any type of loss or damage suffered as a result of any
action brought by a third party) even if such damage or loss was reasonably
foreseeable or Xilinx had been advised of the possibility of the same.

CRITICAL APPLICATIONS
Xilinx products are not designed or intended to be fail-safe, or for use in any
application requiring fail-safe performance, such as life-support or safety
devices or systems, Class III medical devices, nuclear facilities, applications
related to the deployment of airbags, or any other applications that could lead
to death, personal injury, or severe property or environmental damage
(individually and collectively, "Critical Applications"). Customer assumes the
sole risk and liability of any use of Xilinx products in Critical Applications,
subject only to applicable laws and regulations governing limitations on product
liability.

THIS COPYRIGHT NOTICE AND DISCLAIMER MUST BE RETAINED AS PART OF THIS FILE AT
ALL TIMES.

*******************************************************************************/


#ifndef BIT_IO_H_
#define BIT_IO_H_

#include <string>
#include <vector>

typedef unsigned char		u8;
typedef unsigned char		uchar;
typedef unsigned short		u16;
typedef unsigned int		u32;
typedef unsigned int		uint;
typedef			 char		i8;
typedef			 short		i16;
typedef			 int		i32;

using namespace std;

//BitStorage
class BitStorage {
public:
	BitStorage();
	BitStorage(const BitStorage& rhs);
	BitStorage(const string& str);
	BitStorage(const vector<u8>& bits, u32 count_bits);
	virtual ~BitStorage();


	//read
	int read(int count_bits) const;

	//write
	bool write_bit(u8 bit);
	bool write_multiple_bits(u32 bits, u32 length);
	bool write_multiple_bits(const string& str);


	//access
	vector<u8>& data() {return m_storage;}
	const vector<u8>& cdata() const {return m_storage;}

	//stats
	void begin() { m_bitwise_index = 0;}
	bool is_end() const;
	u32 count_total_bits() const {return m_bitwise_count;}

	//total size in bytes
	u32 size() const { return m_storage.size();}

	//serialize
	int from_string(const string& bitstring);
	string to_string() const;


	static bool is_bit_set(u8 byte, u8 index);

protected:
	void copyfrom(const BitStorage& other);
	void appendfrom(const BitStorage& other);
	void reset();

protected:
	mutable u32 m_bitwise_index;
	u32 m_bitwise_count;
	vector<u8> m_storage;
};


#endif /* BIT_IO_H_ */

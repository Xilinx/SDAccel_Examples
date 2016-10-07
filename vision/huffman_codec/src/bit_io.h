/**********
Copyright (c) 2016, Xilinx, Inc.
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

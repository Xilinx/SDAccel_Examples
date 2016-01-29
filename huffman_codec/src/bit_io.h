/*
 * bit_io.h
 *
 *  Created on: Sep 4, 2015
 *      Author: pouryas
 */

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

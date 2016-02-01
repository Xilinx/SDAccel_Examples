/*******************************************************************************
Vendor: Xilinx
Associated Filename: huffmancodec.h
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

#ifndef HUFFMANCODEC_H_
#define HUFFMANCODEC_H_

#include <map>
#include <vector>
#include <string>
#include <iostream>
#include "bit_io.h"


using namespace std;

namespace sda {


/*!
 * CPU based decoded/encoder for Canonical Huffman implementation
 */
class HuffmanCodec {
public:
	HuffmanCodec();
	virtual ~HuffmanCodec();

	//HTree<data, weight, code>
	typedef u8 Symbol;
	typedef u32 BitCodeType;
	typedef vector<Symbol> VecSymbols;

	//bitlen = [0..255]
	//code can be up to 32 bits
	struct BitCode {
		BitCodeType code;
		u8 bitlen;
	};

	//HTree<data, weight, code>
	template <typename SymbolsContainerType, typename WeightType>
	struct TreeNode {
		TreeNode* left;
		TreeNode* right;
		BitCode bitcode;
		SymbolsContainerType symbols;
		WeightType weight;
	};

	//Combinatorial types
	typedef TreeNode<VecSymbols, float> HTreeNode;
	typedef std::map<Symbol, BitCode> CodeBook;

	struct LessThanByWeight {
		bool operator()(const HTreeNode* lhs, const HTreeNode* rhs) const {
			return lhs->weight < rhs->weight;
		}
	};

	struct GreaterThanByWeight {
		bool operator()(const HTreeNode* lhs, const HTreeNode* rhs) const {
			return lhs->weight > rhs->weight;
		}
	};


	//kernel in c
	static int kernel_decode_string(const vector<u8>& in_data, string& out_str);
	static int kernel_encode_string(const string& in_str, vector<u8>& out_data);

	//int kernel_decode_test(const vector<u8>& out_data, string& out_str);

	/*!
	 * Encodes canonical huffman
	 */
	int encode_naive(const vector<u8>& in_data, vector<u8>& out_data);
	int encode_naive(const string& in_str, vector<u8>& out_data);

	/*!
	 * Decodes canonical huffman
	 */
	int decode_naive(const vector<u8>& in_data, vector<u8>& out_data);
	int decode_naive(const vector<u8>& in_data, string& out_str);

	//verbose
	void set_verbose(bool enable) { m_verbose = true;}
	bool verbose() const { return m_verbose;}

	static bool write_binary_file(const vector<u8>& data, const string& strFP);

	//utils
	static void vector_to_string(const vector<u8>& in_vec, string& out_str);
	static void string_to_vector(const string& in_str, vector<u8>& out_vec);

	static string binary_string(u8 value);
	static int bit_length(u8 value);

	static void print_huffman_tree(const HTreeNode* root);
protected:
	static int compute_huffmancodes_recursive(HTreeNode* parent);
	static string htree_symbols_tostring(const HTreeNode* pnode, bool inhex= true);
	static void print_codebook(const CodeBook& book);
	static string bitcode_to_string(const BitCode& code);
	static int htree_depth_recursive(const HTreeNode* root, int current_depth);



protected:
	vector<HTreeNode*> m_leaves;
	bool m_verbose;

};

}


#endif /* HUFFMANCODEC_H_ */


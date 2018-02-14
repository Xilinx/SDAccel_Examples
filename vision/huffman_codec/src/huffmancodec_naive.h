/**********
Copyright (c) 2018, Xilinx, Inc.
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
#ifndef HUFFMANCODEC_H_
#define HUFFMANCODEC_H_

#include <map>
#include <vector>
#include <string>
#include <iostream>
#include "bit_io.h"


using namespace std;

namespace sda {

class ICodec {
public:
	virtual int enc(const vector<u8>& in_data, vector<u8>& out_data) = 0;
	virtual int dec(const vector<u8>& in_data, vector<u8>& out_data) = 0;

	int enc_str(const string& in_str, vector<u8>& out_data);
	int dec_str(const vector<u8>& in_data, string& out_str);

	//utils
	static void vector_to_string(const vector<u8>& in_vec, string& out_str);
	static void string_to_vector(const string& in_str, vector<u8>& out_vec);

	static string binary_string(u8 value);
	static int bit_length(u8 value);
};

/*!
 * CPU based decoded/encoder for Canonical Huffman implementation
 */
class HuffmanNaiveImpl : public ICodec {
public:
	HuffmanNaiveImpl();
	virtual ~HuffmanNaiveImpl();

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


	/*!
	 * Encodes canonical huffman
	 */
	int enc(const vector<u8>& in_data, vector<u8>& out_data);

	/*!
	 * Decodes canonical huffman
	 */
	int dec(const vector<u8>& in_data, vector<u8>& out_data);

	//verbose
	void set_verbose(bool enable) { m_verbose = true;}
	bool verbose() const { return m_verbose;}


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


/*
 * HuffmanCodec.h
 *
 *  Created on: Sep 3, 2015
 *      Author: pouryas
 */

#ifndef HUFFMANCODEC_H_
#define HUFFMANCODEC_H_

#include "base.h"
#include <map>
#include <vector>
#include <string>
#include <iostream>


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


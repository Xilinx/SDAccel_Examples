/*
 * huffmancodec_opencl_cpu.c
 *
 *  Created on: Sep 17, 2015
 *      Author: pouryas
 */
#include <limits.h>
#include <iostream>
#include "huffmancodec_opencl_cpu.h"


#define OFFSET_WEIGHT 0
#define OFFSET_CHILDREN 1
#define OFFSET_CODE 2
#define OFFSET_SYM_BITLEN 3
#define ENTRY_STRIDE 4

//2N - 1 where N is number of leaves
//N = 256 leaves
#define MAX_TREE_LEAVES 256

//unbalanced tree has a depth of N - 1
#define MAX_TREE_DEPTH MAX_TREE_LEAVES

//Max nodes count = 2N-1
#define MAX_TREE_NODES MAX_TREE_LEAVES * 2

const u16 C_INVALID_LINK = (u16)-1;

struct FLAT_HTREE {
	u32 weight;
	u16 lc;
	u16 rc;
	u32 code;
	u8 symbol;
	u8 bitlen;
};

void write_ht_node(u32* pht_current, const struct FLAT_HTREE* pnode) {
	pht_current[OFFSET_WEIGHT] = pnode->weight;
	pht_current[OFFSET_CHILDREN] = (u32)((u32)(pnode->lc << 16) | pnode->rc);
	pht_current[OFFSET_CODE] = pnode->code;
	pht_current[OFFSET_SYM_BITLEN] = (u32)((u32)(pnode->symbol << 16) | pnode->bitlen);
}


void read_ht_node(const u32* pht_current, struct FLAT_HTREE* pnode) {
	pnode->weight = pht_current[OFFSET_WEIGHT];
	pnode->lc = (u16)((pht_current[OFFSET_CHILDREN] >> 16) & 0xFFFF);
	pnode->rc = (u16)(pht_current[OFFSET_CHILDREN] & 0xFFFF);
	pnode->code = pht_current[OFFSET_CODE];
	pnode->symbol = (u8)((u8)(pht_current[OFFSET_SYM_BITLEN] >> 16) & 0xFF);
	pnode->bitlen = (u16)(pht_current[OFFSET_SYM_BITLEN] & 0xFFFF);
}


int find_next_min(u32* pht, u32 count, const u8* visited) {
	if(count == 0)
		return -1;

	//loop over unvisited entries only
	u32 idx_min = -1;
	u32 min_usage = UINT_MAX;
	for(u32 i=0; i < count; i++) {

		if(visited[i] > 0)
			continue;

		struct FLAT_HTREE node;
		read_ht_node(&pht[i * ENTRY_STRIDE], &node);

		if(node.weight < min_usage) {
			idx_min = i;
			min_usage = node.weight;
		}
	}

	return (int)idx_min;
}

//returns 1 if the pointer is incremented otherwise 0
u8 bit_writer(/* __global */ u8** pptr, u32* p_total_bit_count, u8 bit) {
	u8 bit_index = (*p_total_bit_count) % 8;

	if(bit == 1)
		(**pptr) |= (1 << bit_index);

	(*p_total_bit_count)++;

	//push new byte
	if(bit_index == 7) {
		(*pptr)++;
		**pptr = 0;
		return 1;
	}

	return 0;
}

u8 is_bit_set(u8 byte, u8 index) {
	return  ((byte & (1 << index)) & 0xFF) != 0;
}


u8 multiple_bits_writer(/* __global */ u8** pptr, u32* p_total_bit_count, u32 bits, u32 len) {
	u8 bytes_written = 0;
	if(len == 0)
		return 0;

	//order is msb to lsb
	for(int i = (int)len - 1; i >= 0; i--)
	//for(int i = 0; i < (int)len; i++)
	{
		u8 b = (bits >> i) & 0x01;
		bytes_written += bit_writer(pptr, p_total_bit_count, b);
	}

	return bytes_written;
}


int bit_reader(/* __global */ u8** pptr, u32* p_total_bits_read, u32 count_bits) {
	if(count_bits == 0)
		return 0;

	int output = 0;
	for(u32 i = 0; i < count_bits; i++) {
		//u32 byte_index = (*p_total_bits_read) >> 3;
		u32 bit_index = (*p_total_bits_read) % 8;
		(*p_total_bits_read) ++;

		u8 msb = is_bit_set(**pptr, bit_index);
		output = (output << 1) + msb;

		if(bit_index == 7) {
			(*pptr)++;
		}
	}

	return output;
}


void write_word(/* __global */ u8** pptr, u32 word) {
	//u8* ptr = *pptr;
	for(int i=0; i < 4; i++) {
		**pptr = (u8)(word >> (i * 8)) & 0xffff;
		(*pptr)++;
	}
}

inline void read_word(/* __global */ u8** pptr, u32* pword) {
	//u8* ptr = *pptr;
	*pword = 0;
	for(int i=0; i < 4; i++) {
		(*pword) |= ((**pptr) << (i * 8));
		(*pptr)++;
	}
}



//__kernel
//__attribute__ ((reqd_work_group_size(1,1,1)))
void encode(/* __global */ uchar* in_data, uint size_in_data, /* __global */ uchar* out_data, /* __global */ uint* size_out_data, uchar fetch_size_only)
{
	//storage for huffman tree
	u32 ht[MAX_TREE_NODES * ENTRY_STRIDE];
	u32 ht_current = 0;

	u8 visited[MAX_TREE_NODES];
	for(u32 i=0; i < MAX_TREE_NODES; i++) {
		visited[i] = 0;
	}

	//define alphabet map and fill with zeroes
	u32 alphabet_usage[MAX_TREE_LEAVES];
	u16 alphabet_to_htree_node[MAX_TREE_LEAVES];
	for(u32 i=0; i < MAX_TREE_LEAVES; i++) {
	  alphabet_usage[i] = 0;
	  alphabet_to_htree_node[i] = C_INVALID_LINK;
	}

	for(u32 i=0; i < size_in_data; i++) {
		u8 d = in_data[i];
		alphabet_usage[d] ++;
	}

	u8 ctLeaves = 0;
	for(u16 i=0; i < MAX_TREE_LEAVES; i++) {
	  if(alphabet_usage[i] > 0) {
		  ctLeaves ++;

		  //HTREE leaf node
		  struct FLAT_HTREE node;
		  node.lc = node.rc = C_INVALID_LINK;
		  node.code = node.bitlen = 0;
		  node.symbol = (u16)i;
		  node.weight = alphabet_usage[i];

		  //final codebook lut
		  alphabet_to_htree_node[i] = ht_current;

		  //write ht node
		  write_ht_node(&ht[ht_current * ENTRY_STRIDE], &node);
		  ht_current++;
	  }
	}

	//now
	//u32 nMaxTreeNodes = ctLeaves * 2 - 1;
	//printf("There are %u unique symbols\n", ctLeaves);


	u32 ctUnvisited = ctLeaves;
	while(ctUnvisited > 1) {

		int idxS0 = find_next_min(&ht[0], ht_current, &visited[0]);
		//assert(idxS0 >= 0 && idxS0 < (int)ht_current);
		visited[idxS0] = 1;

		int idxS1 = find_next_min(&ht[0], ht_current, &visited[0]);
		//assert(idxS1 >= 0 && idxS1 < (int)ht_current);
		visited[idxS1] = 1;

		struct FLAT_HTREE lc_node;
		read_ht_node(&ht[idxS0 * ENTRY_STRIDE], &lc_node);

		struct FLAT_HTREE rc_node;
		read_ht_node(&ht[idxS1 * ENTRY_STRIDE], &rc_node);

		//create the combined node
		//htreenode
		struct FLAT_HTREE node;
		node.lc = idxS0;
		node.rc = idxS1;
		node.code = 0;
		node.bitlen = 0;
		node.symbol = rc_node.symbol;
		node.weight = lc_node.weight + rc_node.weight;

		//write ht node
		write_ht_node(&ht[ht_current * ENTRY_STRIDE], &node);
		ht_current++;

		ctUnvisited--;
	}


	//now compute bit-codes
	u32 idxRoot = ht_current - 1;

	//TODO: use a stack-less traversal such as:
	//https://software.intel.com/sites/default/files/managed/10/af/dynamic-stackless-binary-tree-traversal.pdf
	u16 stk_nodes[MAX_TREE_DEPTH];
	int top = 0;

	stk_nodes[top] = idxRoot;

	//pop till stack is empty
	while(top >= 0) {
		struct FLAT_HTREE node;
		struct FLAT_HTREE left_child;
		struct FLAT_HTREE right_child;

		u32 index = stk_nodes[top--];
		read_ht_node(&ht[index * ENTRY_STRIDE], &node);

		if(node.lc != C_INVALID_LINK) {
			read_ht_node(&ht[node.lc * ENTRY_STRIDE], &left_child);
			left_child.code = (node.code << 1);
			left_child.bitlen = node.bitlen + 1;
			write_ht_node(&ht[node.lc * ENTRY_STRIDE], &left_child);

			stk_nodes[++top] = node.lc;
		}

		if(node.rc != C_INVALID_LINK) {
			read_ht_node(&ht[node.rc * ENTRY_STRIDE], &right_child);
			right_child.code = (node.code << 1) + 1;
			right_child.bitlen = node.bitlen + 1;
			write_ht_node(&ht[node.rc * ENTRY_STRIDE], &right_child);

			stk_nodes[++top] = node.rc;
		}
	}

	//output = header + payload
	/*!
	 * Byte Count 			| Description
	 * ============================================
	 * 4 				    | MSG LEN
	 * 1		  			| S
	 * S + S      			| Symbol + BitLens Interlaced
	 * BitCodes Size		| Bit Codes
	 * 4					| Payload SIZE
	 * 1					| Payload REM
	 * Payload Size			| Payload
	 */
	//BitCodes Size = (Sum(Bit-Lens) + 7) / 8
	//Payload bits = (Payload Size - 1)* 8 + Payload REM
	//total = 5 + 2S + BitCodes Size + 5 + Payload Size
	//total = 10 + 2S + BitCodes Size + Payload Size

	u32 total_bitcode_dict_bits = 0;
	for(u32 i=0; i < ctLeaves; i++) {
		struct FLAT_HTREE node;
		read_ht_node(&ht[i * ENTRY_STRIDE], &node);
		total_bitcode_dict_bits += node.bitlen;
	}

	u32 total_bitcode_dict_bytes = (total_bitcode_dict_bits + 7) / 8;


	//estimate total size
	u32 total_payload_bits = 0;
	for(u32 i=0; i < size_in_data; i++) {
		u16 ht_index = alphabet_to_htree_node[ in_data[i] ];
		struct FLAT_HTREE node;

		//fetch corresponding htree node
		read_ht_node(&ht[ht_index * ENTRY_STRIDE], &node);

		//count the output bits
		total_payload_bits += node.bitlen;
	}

	u32 total_payload_bytes = (total_payload_bits + 7) / 8;

	//compute estimate based on our formula
	u32 estimate_total = 10 + 2 * ctLeaves + total_bitcode_dict_bytes + total_payload_bytes + 2;

	//return size if this is the first pass
	if(fetch_size_only == 1) {
		*size_out_data = estimate_total;
		return;
	}
	else if(*size_out_data < estimate_total) {
		printf("Not enough output memory!");
		return;
	}

	//encode data

	//MSG LEN
	/* __global */ u8* ptr = &out_data[0];
	write_word(&ptr, size_in_data);

	//S
	*ptr = ctLeaves;
	ptr++;

	//Symbols + BitLens Interlaced
	for(int i=0; i < ctLeaves; i++) {
		struct FLAT_HTREE node;
		read_ht_node(&ht[i * ENTRY_STRIDE], &node);

		*ptr = node.symbol;
		ptr++;
		*ptr = node.bitlen;
		ptr++;
	}


	//Bit-Codes
	u32 total_bits_written = 0;
	u32 total_bytes = 0;
	for(int i=0; i < ctLeaves; i++) {
		struct FLAT_HTREE node;
		read_ht_node(&ht[i * ENTRY_STRIDE], &node);

		total_bytes += multiple_bits_writer(&ptr, &total_bits_written, node.code, node.bitlen);
	}

	//check if need to increment
	if(total_bits_written % 8 != 0) {
		ptr++;
	}

	/*
	 * 4					| Payload SIZE
	 * 1					| Payload REM
	 * Payload Size			| Payload
	 */
	u8 payload_rem = total_payload_bits % 8;

	//Payload SIZE
	write_word(&ptr, total_payload_bytes);

	//Payload REM
	*ptr = payload_rem;
	ptr++;

	//Payload
	total_bits_written = 0;
	total_bytes = 0;
	for(u32 i=0; i < size_in_data; i++) {
		u16 ht_index = alphabet_to_htree_node[ in_data[i] ];
		struct FLAT_HTREE node;

		//fetch corresponding htree node
		read_ht_node(&ht[ht_index * ENTRY_STRIDE], &node);

		//count the output bits
		total_bytes += multiple_bits_writer(&ptr, &total_bits_written, node.code, node.bitlen);
	}
}

/*!
 * kernel to decode huffman
 */
//__kernel
//__attribute__ ((reqd_work_group_size(1,1,1)))
void decode(/* __global */ uchar* in_data, uint size_in_data, /* __global */ uchar* out_data, /* __global */ uint* size_out_data, uchar fetch_size_only) {
	//output = header + payload
	/*!
	 * Byte Count 			| Description
	 * ============================================
	 * 4 				    | MSG LEN
	 * 1		  			| S
	 * S + S      			| Symbol + BitLens Interlaced
	 * BitCodes Size		| Bit Codes
	 * 4					| Payload SIZE
	 * 1					| Payload REM
	 * Payload Size			| Payload
	 */
	//BitCodes Size = (Sum(Bit-Lens) + 7) / 8
	//Payload bits = (Payload Size - 1)* 8 + Payload REM
	//total = 5 + 2S + BitCodes Size + 5 + Payload Size
	//total = 10 + 2S + BitCodes Size + Payload Size

	//storage for huffman tree
	u32 ht[MAX_TREE_NODES * ENTRY_STRIDE];
	u32 ht_current = 0;


	u8 leaf_symbols[MAX_TREE_LEAVES];
	u8 leaf_bitlen[MAX_TREE_LEAVES];
	u32 leaf_bitcodes[MAX_TREE_LEAVES];

	//define alphabet map and fill with zeroes
	/*
	u16 symbol_to_htreenode[MAX_TREE_LEAVES];
	for(u32 i=0; i < MAX_TREE_LEAVES; i++) {
		symbol_to_htreenode[i] = C_INVALID_LINK;
	}

	//define alphabet map and fill with zeroes
	u16 bitcode_to_htree_node[MAX_TREE_NODES];
	for(u32 i=0; i < MAX_TREE_NODES; i++) {
	  bitcode_to_htree_node[i] = C_INVALID_LINK;
	}
	*/

	//MSG_LEN
	/* __global */ u8* ptr = &in_data[0];
	u32 msg_len = 0;
	read_word(&ptr, &msg_len);

	//return outsize
	if(fetch_size_only) {
		*size_out_data = msg_len;
		return;
	}
	else if(*size_out_data < msg_len) {
		printf("Not enough memory\n");
	}

	u8 ctLeaves = *ptr;
	ptr++;

	//Read Symbols
	u32 total_bitcodes_bits = 0;
	for(u32 i=0; i<ctLeaves; i++) {
	  leaf_symbols[i] = *ptr;
	  ptr++;

	  leaf_bitlen[i] = *ptr;
	  ptr++;

	  //increment bits
	  total_bitcodes_bits += leaf_bitlen[i];
	}

	//Read Bit-Codes
	u32 total_bits_read = 0;
	for(u32 i=0; i<ctLeaves; i++) {
		//read bitcode
		leaf_bitcodes[i] = bit_reader(&ptr, &total_bits_read, leaf_bitlen[i]);

		//check
		if(total_bits_read >= total_bitcodes_bits)
			break;
	}

	//increment in case at middle byte
	if(total_bits_read % 8 != 0)
		ptr++;


	u32 ht_root = ht_current;
	//Create a root node now
	{
		struct FLAT_HTREE root_node;
		root_node.lc = root_node.rc = C_INVALID_LINK;
		root_node.code = 0;
		root_node.weight = 0;
		root_node.symbol = 0;
		root_node.bitlen = 0;

		//write node
		write_ht_node(&ht[ht_current * ENTRY_STRIDE], &root_node);
		ht_current++;
	}


	//create all intermediate nodes
	for(u32 i=0; i < ctLeaves; i++) {

		u8 bitlen = leaf_bitlen[i];
		u32 bitcode = leaf_bitcodes[i];

		//create all missing tree nodes
		u32 current = ht_root;

		u8 processed_bitlen = 0;
		u8 processed_code = 0;
		for(u32 j = 0; j < bitlen; j++) {

			//flat tree node
			struct FLAT_HTREE node;

			//read
			read_ht_node(&ht[current * ENTRY_STRIDE], &node);

			//
			u8 msb = (bitcode >> (bitlen - j - 1)) & 0x1;
			processed_code = (processed_code << 1) + msb;
			processed_bitlen++;

			bool is_leaf = (j == (u32)(bitlen - 1));
			bool need_new_node = false;
			bool new_node_on_left = false;

			if((msb == 0) && (node.lc == C_INVALID_LINK)) {
				need_new_node = true;
				new_node_on_left = true;
			}
			else if((msb == 1) && (node.rc == C_INVALID_LINK)) {
				need_new_node = true;
			}

			//add missing node
			if(need_new_node) {
				struct FLAT_HTREE child_node;
				child_node.lc = child_node.rc = C_INVALID_LINK;
				child_node.weight = 0;
				child_node.code = processed_code;
				child_node.bitlen = processed_bitlen;

				if(is_leaf)
					child_node.symbol = leaf_symbols[i];

				//write the new node
				write_ht_node(&ht[ht_current * ENTRY_STRIDE], &child_node);

				if(new_node_on_left)
					node.lc = ht_current;
				else
					node.rc = ht_current;

				//write original node
				write_ht_node(&ht[current * ENTRY_STRIDE], &node);

				//increment for next
				ht_current++;
			}

			//break at leaf
			if(is_leaf)
				break;

			//if 0 goto left otherwise right
			if(msb)
				current = node.rc;
			else
				current = node.lc;
		}
	}

	//Payload Size
	u32 total_payload_bytes = 0;
	read_word(&ptr, &total_payload_bytes);

	u8 payload_rem = *ptr;
	ptr++;

	u32 total_payload_bits = (total_payload_bytes - 1) * 8 + payload_rem;

	total_bits_read = 0;

	u32 current = ht_root;
	u32 index_out_buf = 0;

	//flat tree node
	struct FLAT_HTREE node;

	//read
	read_ht_node(&ht[current * ENTRY_STRIDE], &node);

	while(total_bits_read < total_payload_bits) {
		u8 bit = bit_reader(&ptr, &total_bits_read, 1);

		//pick direction
		if (bit && (node.rc != C_INVALID_LINK))
			current = node.rc;
		else if(node.lc != C_INVALID_LINK)
			current = node.lc;

		//read
		read_ht_node(&ht[current * ENTRY_STRIDE], &node);

		bool isleaf = (node.rc == C_INVALID_LINK) && (node.lc == C_INVALID_LINK);
		if(isleaf) {
			out_data[index_out_buf++] = node.symbol;
			current = ht_root;
			read_ht_node(&ht[current * ENTRY_STRIDE], &node);

			if(index_out_buf >= msg_len)
				return;
		}
	}

}


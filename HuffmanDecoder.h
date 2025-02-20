#ifndef HUFFMAN_DECODER_H
#define HUFFMAN_DECODER_H

#include "HuffmanTree.h"  
#include "BitStream.h"    
#include <fstream>

class HuffmanDecoder 
{
public:
    void decodeFile(const std::string& inputFile, const std::string& outputFile, HuffmanTree& tree);
};

#endif

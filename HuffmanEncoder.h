#ifndef HUFFMAN_ENCODER_H
#define HUFFMAN_ENCODER_H

#include "HuffmanTree.h"
#include "BitStream.h"
#include <fstream>

class HuffmanEncoder {
public:
    void encodeFile(const std::string& inputFile, const std::string& outputFile, HuffmanTree& tree);
};

#endif
#include "HuffmanEncoder.h"
#include "BitStream.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <unordered_map>
void HuffmanEncoder::encodeFile(const std::string& inputFile, const std::string& outputFile, HuffmanTree& tree) {
    std::ifstream input(inputFile, std::ios::binary);
    if (!input) {
        std::cerr << "Ошибка открытия входного файла!\n";
        return;
    }
    std::unordered_map<unsigned char, unsigned int> frequencies;
    unsigned char ch;
    while (input.read(reinterpret_cast<char*>(&ch), 1)) {
        frequencies[ch]++;
    }
    tree.buildTree(frequencies);
    auto codes = tree.getCodes();
    input.clear();
    input.seekg(0, std::ios::beg);
    std::fstream output(outputFile, std::ios::in | std::ios::out | std::ios::binary | std::ios::trunc);
    if (!output) {
        std::cerr << "Ошибка открытия выходного файла!\n";
        return;
    }
    output.put(0);
    BitWriter writer(output);
    unsigned long long totalBits = 0;
    while (input.read(reinterpret_cast<char*>(&ch), 1)) {
        std::string code = codes[ch];
        for (char bit : code) {
            writer.writeBit(bit == '1');
            totalBits++;
        }
    }
    writer.flush();
    unsigned char tail = 0;
    if (totalBits > 0) {
        tail = totalBits % 8;
        if (tail == 0) tail = 8;
    }
    output.seekp(0, std::ios::beg);
    output.put(tail);
    output.flush();
    input.close();
    output.close();
}

#include "HuffmanDecoder.h"
#include "BitStream.h"
#include <fstream>
#include <sstream>
#include <iostream>

    
void HuffmanDecoder::decodeFile(const std::string& inputFile, const std::string& outputFile, HuffmanTree& tree) 
{
    
    std::ifstream input(inputFile, std::ios::binary);
    if (!input) 
    {
        std::cerr << "Ошибка открытия сжатого файла!\n";
        return;
    }
    unsigned char tail = 0;
    input.get(reinterpret_cast<char&>(tail));
    input.seekg(0, std::ios::end); 
    std::streampos fileSize = input.tellg(); 
    long dataBytes = static_cast<long>(fileSize) - 1;
    if (dataBytes <= 0) 
    {
        std::cerr << "Нет данных для декодирования!\n";
        return;
    }
    unsigned long long totalBits = dataBytes * 8; 
    if (tail != 8) 
    {
        totalBits -= (8 - tail); 
    }
    input.seekg(1, std::ios::beg); 
    BitReader reader(input);
    std::ofstream output(outputFile, std::ios::binary | std::ios::trunc);
    if (!output) 
    {
        std::cerr << "Ошибка открытия выходного файла!\n";
        return;
    }
    Node* node = tree.getRoot();
    if (!node) 
    {
        std::cerr << "Ошибка: Дерево Хаффмана не инициализировано!\n";
        return;
    }
    unsigned long long bitsRead = 0; 
    while (bitsRead < totalBits) 
    {
        bool bit = reader.readBit();
        bitsRead++;
        node = bit ? node->right : node->left;
        if (!node->left && !node->right) 
        {
            output.put(node->symbol); 
            node = tree.getRoot();    
        }
    }
    output.close();
    input.close();
}

#ifndef HUFFMAN_TREE_H
#define HUFFMAN_TREE_H

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

struct Node 
{
    unsigned char symbol;  
    unsigned int frequency; 
    Node *left, *right;  
    Node(unsigned char s, unsigned int f)
    : symbol(s), frequency(f), left(nullptr), right(nullptr) {}
    struct Compare 
    {
        bool operator()(Node* l, Node* r) 
        {
            return l->frequency > r->frequency; 
        }
    };
};

class HuffmanTree 
{
public:
    HuffmanTree();  
    ~HuffmanTree(); 
    void buildTree(const std::unordered_map<unsigned char, unsigned int>& frequencies);
    void generateCodes(Node* node, std::string code);
    std::unordered_map<unsigned char, std::string> getCodes();
    Node* getRoot();
private:
    Node* root; 
    std::unordered_map<unsigned char, std::string> codes; 
    void freeTree(Node* node);
};

#endif 

#include "HuffmanTree.h"

HuffmanTree::HuffmanTree() : root(nullptr) {}

HuffmanTree::~HuffmanTree() 
{
    freeTree(root);
}

void HuffmanTree::freeTree(Node* node) 
{
    if (node) 
    {
        freeTree(node->left);  
        freeTree(node->right); 
        delete node;           
    }
}

    
void HuffmanTree::buildTree(const std::unordered_map<unsigned char, unsigned int>& frequencies) 
{
    std::priority_queue<Node*, std::vector<Node*>, Node::Compare> pq;
    for (auto pair : frequencies) 
    {
        pq.push(new Node(pair.first, pair.second));
    }
    while (pq.size() > 1) 
    {
        Node* left = pq.top(); pq.pop();  
        Node* right = pq.top(); pq.pop(); 
        Node* newNode = new Node(0, left->frequency + right->frequency);
        newNode->left = left;  
        newNode->right = right; 
        pq.push(newNode);
    }
    root = pq.top();
    generateCodes(root, "");
}

void HuffmanTree::generateCodes(Node* node, std::string code) 
{
    if (!node) return; 
    if (!node->left && !node->right) 
    {
        codes[node->symbol] = code;
    }
    generateCodes(node->left, code + "0");
    generateCodes(node->right, code + "1");
}

std::unordered_map<unsigned char, std::string> HuffmanTree::getCodes() 
{
    return codes;
}

Node* HuffmanTree::getRoot() 
{
    return root;
}

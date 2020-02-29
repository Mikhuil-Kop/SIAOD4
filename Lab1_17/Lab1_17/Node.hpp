#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>
#include "string"
using namespace std;
class Tree;

class Node{
public:
    Node* left, *right;
    int val = 0;
    
    Node(int val, Node* left = nullptr, Node* right = nullptr);
    Node();
    ~Node();
    
    Node* GetLeft();
    Node* GetRight();
    int GetVal();
    
    void Calculate(int& treeDepth, int& childsCount, vector<int>* vec);
    string ToString(string tabs);
};


#endif /* Node_hpp */

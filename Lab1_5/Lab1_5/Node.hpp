#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>
#include "string"
using namespace std;
class Tree;

class Node{
public:
    Node* left, *right;
    int val;
    
    Node(int val, Node* left = nullptr, Node* right = nullptr);
    Node(int min, int max, int depth);
    ~Node();
    
    Node* GetLeft();
    Node* GetRight();
    int GetVal();
    
    void CalculateDepths(int depth, vector<int>*& vec);
    void FindFatherOfNode(int number, Node *&father, Node *&deleting, Node **&cell);
    
    string ToString(string tabs);
};


#endif /* Node_hpp */

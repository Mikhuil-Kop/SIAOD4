#include "Node.hpp"
#include "Tree.hpp"
#include <vector>
#include "stack"

Node::Node(){
    val = rand()%1000;
    
    if(rand()%100 > 60)
        left = new Node();
    else
        left = nullptr;
    
    if(rand()%100 > 60)
        right = new Node();
    else
        right = nullptr;
}

Node::~Node(){
    if(left != nullptr)
        delete left;
    if(right != nullptr)
        delete right;
}

void Node::Calculate(int& treeDepth, int& childsCount, vector<int>* vec){
    int leftDepth = 0, leftCount = 0;
    int rightDepth = 0, rightCount = 0;
    
    if(left != nullptr)
        left->Calculate(leftDepth, leftCount, vec);
    if(right != nullptr)
        right->Calculate(rightDepth, rightCount, vec);
    
    if(leftDepth > rightDepth)
        treeDepth = leftDepth;
    else
        treeDepth = rightDepth;
}

string Node:: ToString(string tabs){
    string s = to_string(val) + ":\n";
    
    string a;
    if(left != nullptr) a = left->ToString(tabs + "\t|");
    else a =  "-";
    
    string b;
    if(right != nullptr) b = right->ToString(tabs + "\t|");
    else b = "-";
    
    s += tabs + a + "\n";
    s += tabs + b;
    
    return s;
}

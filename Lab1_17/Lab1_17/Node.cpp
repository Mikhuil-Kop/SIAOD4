#include "Node.hpp"
#include "Tree.hpp"
#include <vector>
#include <ostream>
#include <istream>
using namespace std;

Node::Node(int val, istream& in, ostream& out){
    this->val = val;
    
    int v1, v2;
    out << "Введите наследников " << val << " 0 = NULL\n";
    in >> v1 >> v2;
    if(v1 != 0)
        left = new Node(v1, in, out);
    else
        left = nullptr;
    
    if(v2 != 0)
        right = new Node(v2, in, out);
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
        treeDepth = leftDepth + 1;
    else
        treeDepth = rightDepth + 1;
    
    childsCount = leftCount + rightCount + 1;
    
    //добавление
    if(leftCount != rightCount && leftDepth == rightDepth)
        vec->push_back(this->val);
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

//1 2 3 5 6 0 0 0 0 7 0 0 0
//100 10 10 2 3 5 6 0 0 0 0 7 0 0 0 2 3 5 6 0 0 0 0 7 0 0 0

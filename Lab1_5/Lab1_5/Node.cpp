#include "Node.hpp"
#include "Tree.hpp"
#include <vector>
#include "stack"
//Оказался ненужным. Всё влезло в Node.h

Node::Node(int min, int max, int depth){
    //конец рекурсии
    val = (min+max)/2;
    //если должны быть потомки
    if(depth){
        left = new Node(min, val, depth-1);
        right = new Node(val, max, depth-1);
    }
    //если потомков не должно быть
}

Node::Node(int val, Node* left, Node* right){
    this->val = val;
    this->left = left;
    this->right = right;
}

Node::~Node(){
    if(left != nullptr)
        delete left;
    if(right != nullptr)
        delete right;
}

Node *Node::GetLeft(){
    return left;
}

Node *Node::GetRight(){
    return right;
}

int Node::GetVal(){
    return val;
}


void Node::FindFatherOfNode(int number, Node *&father, Node *&deleting, Node **&cell){
    
    if(left != nullptr){
        if(left->val == number){
            father = this;
            deleting = left;
            cell = &left;
            return;
        }
        left->FindFatherOfNode(number, father, deleting, cell);
    }
    
    if(right != nullptr){
        if(right->val == number){
            father = this;
            deleting = right;
            cell = &right;
            return;
        }
        right->FindFatherOfNode(number, father, deleting, cell);
    }
    
}

void Node::CalculateDepths(int depth, vector<int>*& vec){
    if(vec->size() <= depth){
        vec->resize(depth + 1);
        vec->at(depth) = 0;
    }
    vec->at(depth)++;
    if(left != nullptr)
        left->CalculateDepths(depth + 1, vec);
    if(right != nullptr)
        right->CalculateDepths(depth + 1, vec);
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

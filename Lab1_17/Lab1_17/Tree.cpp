#include "Tree.hpp"
#include "Node.hpp"

Tree::Tree(){
    srand(time(0));
    Father = new Node();
}

Tree::~Tree(){
    delete Father;
}

string Tree::ToString(){
    return Father->ToString("\t|");
}

vector<int>* Tree::Calculate(){
    vector<int>* vec = new vector<int>();
    int treeDepth, childsCount;
    Father->Calculate(treeDepth, childsCount, vec);
    return vec;
}

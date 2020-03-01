#include "Tree.hpp"
#include "Node.hpp"
#include <ostream>
#include <istream>
using namespace std;

Tree::Tree(istream& in, ostream& out){
    int val;
    out << "Введите номер корня:\n";
    in >> val;
    Father = new Node(val, in, out);
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

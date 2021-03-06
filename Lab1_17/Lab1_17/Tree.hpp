#ifndef Tree_hpp
#define Tree_hpp

#include <stdio.h>
#include "vector"

using namespace std;
class Node;

class Tree{
private:
    Node* Father;
public:
    Tree(istream& in, ostream& out);
    ~Tree();
    
    vector<int>* Calculate();
    
    string ToString();
};


#endif /* Tree_hpp */

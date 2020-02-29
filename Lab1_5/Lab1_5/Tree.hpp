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
    Tree(int min, int max, int depth);
    ~Tree();
    
    bool Delete(int number);
    vector<int>* CalculateDepths();
    
    string ToString();
};


#endif /* Tree_hpp */

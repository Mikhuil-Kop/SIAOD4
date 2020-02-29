#include "Tree.hpp"
#include "Node.hpp"

Tree::Tree(int min, int max, int depth){
    Father = new Node(min, max, depth);
}

Tree::~Tree(){
    delete Father;
}

string Tree::ToString(){
    return Father->ToString("\t|");
}


bool Tree::Delete(int number){
    Node *father, *deleting;
    Node **cell;
    Father->FindFatherOfNode(number, father, deleting, cell);
    if(father == nullptr)
        return false;
    
    //1) Если удаляется конец дерева
    if(deleting->left == nullptr)
    {
        *cell = deleting->right;
        deleting->right = nullptr;
        delete deleting;
        return true;
    }
    else if(deleting->right == nullptr)
    {
        *cell = deleting->left;
        deleting->left = nullptr;
        delete deleting;
        return true;
    }
    
    //2) Удаляется почти из конца
    if(deleting->right->left == nullptr){
        deleting->right->left = deleting->left;
        *cell = deleting->right;
        
        deleting->right = nullptr;
        deleting->left = nullptr;
        delete deleting;
        return true;
    }
    
    //3) Если удаляется из центра дерева
    Node* change, *changeFather;
    changeFather = deleting->right;
    while(changeFather->left->left != nullptr)
        changeFather = changeFather->left;
    change = changeFather->left;
    
    changeFather->left = change->right;
    
    change->right = deleting->right;
    change->left = deleting->left;
    *cell = change;
    
    deleting->right = nullptr;
    deleting->left = nullptr;
    delete deleting;
    
    return true;
}


vector<int>* Tree::CalculateDepths(){
    vector<int>* vec = new vector<int>();
    Father->CalculateDepths(0, vec);
    return vec;
}




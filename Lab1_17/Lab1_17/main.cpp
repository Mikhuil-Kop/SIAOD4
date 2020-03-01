/*
Найдите вершины, у которых высоты поддеревьев равны,
а количество потомков в правом и левом поддеревьях не равны.
 */
#include <iostream>
#include "Tree.hpp"
#include "Node.hpp"
#include <vector>
using namespace std;


int main(int argc, const char * argv[]) {
    Tree* tree = new Tree(cin, cout);
    cout << "Получившееся дерево:\n" + tree->ToString() + "\n";
    
    vector<int> *vec = tree->Calculate();
    cout << "Результат второй задачи:\n";
    for(int i = 0; i < vec->size(); i++)
        cout << vec->at(i) << "\n";
    delete vec;
    
    delete tree;
    return 0;
}

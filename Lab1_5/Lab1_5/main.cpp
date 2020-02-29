/*
 Удаление узла
 (двоичное дерево перестраивается в соответствии с требованием
 сохранения целостности и порядка;
 для дерева общего вида удаляется все поддерево,
 исходящее из удаляемого узла;
 должно быть предусмотрено корректное освобождение памяти).
 
 Определение числа вершин, степень которых совпадает со степенью дерева.
 */

#include <iostream>
#include "Tree.hpp"
#include "Node.hpp"
#include <vector>
using namespace std;


int main(int argc, const char * argv[]) {
    int min, max, depth;
    cout << "Введите минимальное, максимальное число и глубину дерева\n";
    cin >> min >> max >> depth;
    
    Tree* tree = new Tree(min, max, depth);
    cout << "Получившееся дерево:\n" + tree->ToString() + "\n";
    
    
    cout << "\nВведите номер узла для удаления\n";
    int num; cin >> num;
    if(tree->Delete(num))
        cout << "Получившееся дерево:\n" + tree->ToString() + "\n";
    else
        cout << "Такого узла не существует";
    
    vector<int> *vec = tree->CalculateDepths();
    cout << "Результат второй задачи: ";
    cout << vec->at(vec->size() - 1) << "\n";
    delete vec;
    
    delete tree;
    return 0;
}

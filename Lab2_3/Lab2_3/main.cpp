#include <iostream>
#include "graph.hpp"
#include "list"
using namespace std;

int main(int argc, const char * argv[]) {
    cout << "Введите количество узлов\n";
    int len;
    cin >> len;
    
    graph g(len);
    cout << "Введите веса:\n";
    cin >> g;
    
    cout << "\nПолучившийся граф:\n";
    cout << g;
    
    cout << "\nВведите А и Б\n";
    int a, b;
    cin >> a >> b;
    
    
    graph all_lenth;
    list<int> lis = g.get_path(a, b, all_lenth);
    
    cout << "\nРасстояния для всех вершин\n";
    cout << all_lenth;
    
    if(lis.size() <= 1){
        cout << "\nПути нет\n";
        return 0;
    }
    cout << "\nПуть:\n";
    for(int i: lis){
        cout << i;
        if(i != lis.back())
           cout << "->";
    }
    cout << "\n";
    
    return 0;
}//4 1 2 0 12 2 1 0 0 2 0 3 4 5 6 7 8 1 3
//4 0 1 0 5 0 0 1 0 0 0 0 1 0 0 0 0 0 3

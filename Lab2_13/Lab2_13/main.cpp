#include <iostream>
#include "graph.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    graph g(true);
    cout << "Введите количество узлов графа, а потом их веса:\n";
    cin >> g;
    
    cout << "\nПолучившыйся граф:\n";
    cout << g;
    
    cout << "\nЕго каркас";
    cout << g.get_frame();
    return 0;
}

#include <iostream>
#include "graph.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    cout << "Введите длину\n";
    int len;
    cin >> len;
    
    graph g(true, len);
    cout << "Введите количество узлов графа, а потом их веса:\n";
    cin >> g;
    
    cout << "\nПолучившийся граф:\n";
    cout << g;
    
    cout << "\nЕго каркас\n";
    cout << g.get_frame();
    return 0;
}

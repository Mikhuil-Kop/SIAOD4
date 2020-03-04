#include "graph.hpp"

graph::graph(int size){
    this->size = size;
    edges = new int*[size];
    for(int i = 0; i < size; i++)
        edges[i] = new int[size];
    
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
            edges[i][j] = 0;
}
graph::~graph(){
    for(int i = 0; i < size; i++)
        delete[] edges[i];
    delete[] edges;
}


int graph::get_size()
{
    return size;
}
int graph::get_edge(int x, int y)
{
    return edges[x][y];
}


ostream &operator<<(ostream &out, const graph &g){
    for(int i = 0; i < g.size; i++){
        for(int j = 0; j < g.size; j++)
            out << g.edges[i][j] << "\t";
        out << "\n";
    }
    
    return out;
}
istream &operator>>(istream &in, graph &g){
    for(int i = 0; i < g.size; i++){
        for(int j = 0; j < g.size; j++)
            in >> g.edges[i][j];
    }
    
    return in;
}

graph& graph::operator= (const graph &g){
    //от самокопирования
    if(this == &g)
        return *this;
    
    //стираем старое
    for(int i = 0; i < size; i++)
        delete[] edges[i];
    delete[] edges;
    
    //пересоздаем
    size = g.size;
    edges = new int*[size];
       for(int i = 0; i < size; i++)
           edges[i] = new int[size];
    
    //копируем
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
            edges[i][j] = g.edges[i][j];
    
    return *this;
}

list<int> graph::get_path(int a, int b, graph& g){//Не ебу как алгоритм работает. Графы использую в качестве двойного массива, так как лень делать обычный двойной массив. Объяснение алгоритма:
//https://www.cyberforum.ru/cpp-beginners/thread1102841.html
    list<int> path;
    //ленивый вариант динамического массива
    graph arr(size);
    graph path_graph(size);
    //копирование
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++){
            if(edges[i][j] == 0){
                arr.edges[i][j] = 1000000;
                path_graph.edges[i][j] = -1;
            }else{
                arr.edges[i][j] = edges[i][j];
                path_graph.edges[i][j] = j;
            }
        }
    
    //алгоритм Флойда из инета
    for(int k = 0; k < size; k++)
        for(int j = 0; j < size; j++)
            for(int i = 0; i < size; i++)
                if(arr.edges[i][j] > arr.edges[i][k] + arr.edges[k][j]){
                    arr.edges[i][j] = arr.edges[i][k] + arr.edges[k][j];
                    path_graph.edges[i][j] = path_graph.edges[i][k];
                }
    
    rec_path(a, b, path_graph.edges,path);
    g = arr;
    cout << endl << path_graph << endl;
    return path;
}

void graph::rec_path(int i, int j, int **arr, list<int> &lis){
    int k = arr[i][j];
    if(k == -1)
        return;
    
    lis.push_back(i);
    int x = i;
    while ( x != j ){
        x = arr[x][j];
        lis.push_back(x);
    }
    
}

#include "graph.hpp"

graph::graph(bool has_weight, int size){
    this->has_weight = has_weight;
    this->size = size;
    edges = new int*[size];
    for(int i = 0; i < size; i++)
        edges[i] = new int[size];
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
    in >> g.size;
    
    g.edges = new int*[g.size];
    for(int i = 0; i < g.size; i++)
        g.edges[i] = new int[g.size];
    
    for(int i = 0; i < g.size; i++){
        g.edges[i][i] = 0;
        for(int j = i + 1; j < g.size; j++){
            in >> g.edges[i][j];
            if(!g.has_weight && g.edges[i][j] != 0)//нормализация
                g.edges[i][j] = 1;
            g.edges[j][i] = g.edges[i][j];
        }
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
    has_weight = g.has_weight;
    edges = new int*[size];
       for(int i = 0; i < size; i++)
           edges[i] = new int[size];
    
    //копируем
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
            edges[i][j] = g.edges[i][j];
    
    return *this;
}


struct str{
public:
    str(int w, int x, int y):w(w), x(x), y(y){}
    int w, x, y;
};

graph graph::get_frame(){
    graph exit = graph(true, this->size);
    
    return exit;
}

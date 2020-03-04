#include "graph.hpp"
#include "list"

graph::graph(bool has_weight, int size){
    this->has_weight = has_weight;
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
    
    friend bool operator>(const str& s1, const str& s2){return s1.w > s2.w;}
    friend bool operator<(const str& s1, const str& s2){return s1.w < s2.w;}
    friend bool operator==(const str& s1, const str& s2){return s1.w == s2.w;}
};

graph graph::get_frame(){
    graph exit = graph(true, this->size);
    
    list<str> l;
    
    for(int i = 0; i < size; i++)
        for(int j = i + 1; j < size; j++)
            if(edges[i][j] != 0)
                l.push_back(str(edges[i][j],i,j));
    l.sort();
    
    //список отдельных каркасов
    list<list<int>> frames;
    for(int i = 0; i < size; i++)
        frames.push_back(list<int>{i});
                         
    //заполнение итогового каркаса и слияние списков
    while(!l.empty()){
        str now = l.front();
        l.pop_front();
        
        //поиск и слияние
        list<int> *f1 = nullptr, *f2 = nullptr;
        
        for(list<int>& f : frames){
            //нахождение узлов в списке
            for(int i: f){
                if(i == now.x) f1 = &f;
                if(i == now.y) f2 = &f;
            }
            
            //Оба узла найдены. Слияние
            if(f1 != nullptr && f2 != nullptr){
                if(f1 != f2){
                    for(int i: *f2)
                        f1->push_back(i);
                    frames.remove(*f2);
                    
                    exit.edges[now.x][now.y] = now.w;
                    exit.edges[now.y][now.x] = now.w;
                }
                break;
            }
        }
    }
    
    return exit;
}

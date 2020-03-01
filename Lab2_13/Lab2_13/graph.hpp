#ifndef graph_hpp
#define graph_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

class graph{
private:
    bool has_weight;
    int** edges = nullptr;
    int size;
public:
    graph(bool has_weight, int size = 0);
    ~graph();

    int get_size();
    int get_edge(int x, int y);
    
    friend ostream &operator<<(ostream &out, const graph &g);
    friend istream &operator>>(istream &in, graph &g);
    graph& operator= (const graph &str);

    graph get_frame();
};

ostream &operator<<(ostream &out, const graph &g);
istream &operator>>(istream &in,  graph &g);

#endif

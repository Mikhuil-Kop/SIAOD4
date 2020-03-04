#ifndef graph_hpp
#define graph_hpp

#include <stdio.h>
#include <iostream>
#include "list"
using namespace std;


class graph{
private:
    int** edges = nullptr;
    int size;
    
    void rec_path(int i, int j, int **arr, list<int> &lis);
public:
    graph(int size = 0);
    ~graph();

    int get_size();
    int get_edge(int x, int y);
    
    friend ostream &operator<<(ostream &out, const graph &g);
    friend istream &operator>>(istream &in, graph &g);
    graph &operator= (const graph &g);

    list<int> get_path(int a, int b, graph& g);
};

ostream &operator<<(ostream &out, const graph &g);
istream &operator>>(istream &in,  graph &g);

#endif

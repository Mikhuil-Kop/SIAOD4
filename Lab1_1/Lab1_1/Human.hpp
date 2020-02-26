#ifndef Human_hpp
#define Human_hpp

#include <stdio.h>
#include <string>
using namespace std;

class Human{
private:
    Human **childs;
    int count;
    string name;
    
public:
    Human(string name, Human** childs = nullptr, int count = 0);
    ~Human();
    string GetName();
    Human* GetChild(int i);
    int GetChildsCount();
};


#endif /* Human_hpp */

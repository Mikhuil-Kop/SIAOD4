#include "Human.hpp"

Human::Human(string name,Human**childs, int count){
    this->name = name;
    this->count = count;
    this->childs = new Human*[count];
    
    for(int i = 0; i < count; i++)
        this->childs[i] = childs[i];
}
Human::~Human(){
    for(int i = 0; i < count; i++)
        delete childs[i];
    delete[] childs;
}

string Human::GetName(){
    return name;
}

Human* Human::GetChild(int i){
    return childs[i];
}

int Human::GetChildsCount(){
    return count;
}

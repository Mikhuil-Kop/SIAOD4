/*
 Имеется дерево, корень которого соответствует основателю рода.
 Сыновья каждой вершины задают сыновей и дочерей соответствующего человека.
 Указываются имена двух человек (например, А и В).
 
 Сообщить, какая из следующих ситуаций имеет место:
    1) А предок В;
    2) В предок А;
    3) А и В имеют ближайшего общего предка С.
 */

#include <iostream>
#include "Human.hpp"
using namespace std;

//Функция
// '0' - не один из случаев. Нет наследников
// ('1'-'3') - один из случаев
// 'a' - имеет среди наследников только A
// 'b' - имеет среди наследников только B
char AnalizeChilds(Human* human, const string & a, const string & b, Human*& HumanC){
    //обработка наследников
    bool AInChilds = false, BInChilds = false;
    
    for(int i = 0; i < human->GetChildsCount(); i++)
    {
        char result = AnalizeChilds(human->GetChild(i), a, b, HumanC);
        
        //если задача решена для этого наследника - то завершить функцию
        if(result == '1' || result == '2' || result == '3')
            return result;
        
        //когда встречается один наследник
        if(result == 'a')
            AInChilds = true;
        else if(result == 'b')
            BInChilds = true;
    }
    
    //среди наследников найдены искомые
    if(AInChilds && !BInChilds){//среди наследников только А
        if(human->GetName() == b)
            return '2';
        return 'a';
    }else if(!AInChilds && BInChilds){//среди наследников только Б
        if(human->GetName() == a)
            return '1';
        return 'b';
    }else if(AInChilds && BInChilds){//среди наследников искомых Оба
        HumanC = human;
        return '3';
    }
    
    //human - искомый человек
    if(human->GetName() == a)
        return 'a';
    if(human->GetName() == b)
        return 'b';
    
    //Неподходящая нам ветвь
    return '0';

}


int main(int argc, const char * argv[]) {
    setlocale(LC_ALL, "rus");
    
    //Ввод данных
    Human* c;
    string a, b;
    cout << "Введите имя А и Б\n";
    cin >> a >> b;
    if(a == b){
        cout << "Введен один и тот же человек\n";
        return -1;
    }
    
    
    //создание дерева
    /*
     Батя
          |  Сын1
          |     | Сын2
          |     | Сын3
          |     |     |Сын4
          |     |     |Дочь1
          |     | Сын5
          |  Дочь2
          |     | Дочь3
          |     | Сын6
          |     |     |Сын7
          |     |     |Сын8
          |     |     |Сын9
          |     | Дочь4
          |  Сын10
          |     | Сын11
          |  Сын12
     */
    
    //третье поколение
    Human* Son3Childs[2];
    Son3Childs[0] = new Human("Сын4");
    Son3Childs[1] = new Human("Дочь1");
    
    Human* Son6Childs[3];
    Son6Childs[0] = new Human("Сын7");
    Son6Childs[1] = new Human("Сын8");
    Son6Childs[2] = new Human("Сын9");
    
    //второе поколение
    Human* Son1Childs[3];
    Son1Childs[0] = new Human("Сын2");
    Son1Childs[1] = new Human("Сын3", Son3Childs, 2);
    Son1Childs[2] = new Human("Сын5");
    
    Human* Daughter2Childs[3];
    Daughter2Childs[0] = new Human("Дочь3");
    Daughter2Childs[1] = new Human("Сын6", Son6Childs, 3);
    Daughter2Childs[2] = new Human("Дочь4");
    
    Human* Son10Childs[3];
    Son10Childs[0] = new Human("Сын11");
    
    //первое поколение
    Human* FatherChilds[4];
    FatherChilds[0] = new Human("Сын1", Son1Childs, 3);
    FatherChilds[1] = new Human("Дочь2", Daughter2Childs, 3);
    FatherChilds[2] = new Human("Сын10", Son10Childs, 1);
    FatherChilds[3] = new Human("Сын12");
    
    Human* father = new Human("Батя", FatherChilds, 4);
    
    //Алгоритм оброботки дерева
    
    char result = AnalizeChilds(father, a, b, c);
    
    switch (result) {
        case 'a':
            cout << "Среди наследников найден только " + a + "\n";
            break;
        case 'b':
            cout << "Среди наследников найден только " + b + "\n";
            break;
        case '0':
           cout << "Ни один из наследников не обнаружен\n";
            break;
        case '1':
            cout << a + " - предок " + b + "\n";
            break;
        case '2':
            cout << b + " - предок " + a + "\n";
            break;
        case '3':
            cout << "Третий случай. Ближайший предок: " + c->GetName() +"\n";
            break;
            
        default:
            cout << "Неизвестная ошибка\n";
            break;
    }
        
    delete father;
    return 0;
}

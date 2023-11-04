#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;



//Дружка 
Агрегацічя 2 обьекта связані между собой но при уначтожени главного обьекта агрегированній обьект продолжает существовать
Агрегація реальзуется через указатель на обьект 

class Cond
{
    string name;
public:
    Cond()
    {
        name = "Midea";
    }
    Cond(const char* N)
    {
        name = N;
    }
    Cond(Cond& obj)
    {
        name = obj.name;
    }
    void Show()
    {
        cout << name << endl;
    }
};
class Engine
{
    double w;
public:
    Engine()
    {
        w = 10000;
    }
    Engine(double d)
    {
        w = d;
    }
    void Show()
    {
        cout << "Engine w = " << w << endl;
    }
};

class CorobckaPeredach {
    int count;
public:
    CorobckaPeredach(int i) {
        count = i;
    }
    void Show()
    {
        cout << count << endl;
    }
};

class Magnitola {
    string firma;
public:
    Magnitola(const char* N)
    {
        firma = N;
    }
    void Show()
    {
        cout << firma << endl;
    }
};

class Car
{
    Cond* obj;   // не уничтожается при удалении объекта класса Car!!!  Агрегирование!
    int year;
    Engine a; // удаляется при уничтожении объекта класса Car!!! Композиция!

    Magnitola* b;
    CorobckaPeredach c;
public:
    Car(Cond* x, double d, int y,int count,Magnitola* u) : obj(x), a(d), c(count),b(u)
    {
        year = y;



    }
    void Show()
    {
        cout << year << endl;
        obj->Show();
        a.Show();
    }
    ~Car()
    {
        cout << "Destruct\n";
    }
};





int main()
{
    Cond obj{ "Samsung" };
    Magnitola mag2{ "hbh" };
    Car* ptr = new Car(&obj, 20000, 2018,4,&mag2);
    /*ptr->Show();
    delete ptr;
    cout << "\n---- obj2 -------------------\n";
    Car new_obj(&obj, 12000, 1999);
    new_obj.Show();*/
}
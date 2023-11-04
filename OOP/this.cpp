// ”казатель this это указатель на обьект дл€ которого вызываетс€ метод.Ёто константный указатель

#include<iostream>
using namespace std;



class Student
{
    char* lastname;
    char* name;
    int age;
public:
    Student() // construct by default
    {
        cout << "Constructor by default\n";
        name = nullptr;
        lastname = nullptr;
        age = 0;
    }
    Student(const char* Name, const char* LastName,int Age) // construct by 2 param
    {
        cout << "Constructor with parameters\n";
        name = new char[strlen(Name) + 1];
        lastname = new char[strlen(LastName) + 1];

        strcpy_s(name, strlen(Name) + 1, Name);
        strcpy_s(lastname, strlen(LastName) + 1, LastName);

        age = Age;
    }
    void Output()
    {
        if (name == nullptr)
        {
            cout << "Empty object!\n";
            return;
        }
        if (lastname == nullptr)
        {
            cout << "Empty object!\n";
            return;
        }
        cout << "Name: " << name << endl
             << "LastName: " << lastname << endl
            << "Age: " << age << endl << endl;
    }
    ~Student()
    {
        cout << "Destruct\n";
        delete[] name;
        delete[] lastname;

    }
};



int main()
{

    Student obj1("Oleg","", 21);
    obj1.Output();




    /*Student mas[2]{ {"Alena",20 }, {"Maksim", 22} };
    for (int i = 0; i < 2; i++)
    {
            mas[i].Output();
    }*/

}
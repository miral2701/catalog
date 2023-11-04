#include<iostream>

using namespace std;



class Student

{

    char* name;

    int age;

public:

    Student() // construct by default

    {

        cout << "Constructor by default\n";

        name = nullptr;

        age = 0;

    }

    Student(const char* Name, int Age) // construct by 2 param

    {

        cout << "Constructor with parameters\n";

        name = new char[strlen(Name) + 1];

        strcpy_s(name, strlen(Name) + 1, Name);

        age = Age;

    }
    void Set() {
        cin >> age;
        char name2[10];
        cin.ignore();
        cin.get(name2, 10);
        name = new char[strlen(name2) + 1];

        strcpy_s(name, strlen(name2) + 1, name2);

    }
    
    void Output()

    {

        if (name == nullptr)

        {

            cout << "Empty object!\n";

            return;

        }

        cout << "Name: " << name << endl

            << "Age: " << age << endl << endl;

    }

    ~Student()

    {

        cout << "Destruct\n";

        delete[] name;

    }

};

void show(Student* arr) {
    for (int i = 0; i < 5; i++) {
        arr[i].Output();
        cout<<endl;
    }
}

int main()

{

    Student obj1("Oleg", 21);

    obj1.Output();



    /*Student mas[2]{ {"Alena",20 }, {"Maksim", 22} };

    for (int i = 0; i < 2; i++)

    {

          mas[i].Output();

    }*/


   /* Создать динамический массив объектов типа Student.Заполнить поля всех элементов этого массива.
    Написать функцию для вывода на экран всех элементов этого массива.Вызвать эту функцию*/
    Student* arr = new Student[5];
    
  
    for (int i = 0; i < 3; i++) {
        
        arr[i].Set();
    }
    show(arr);
}
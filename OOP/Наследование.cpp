#include<iostream>
using namespace std;

class Person
{
protected:
	char* name;
	int age;
public:
	Person() = default;
	Person(const char* n, int a) :age(a)
	{
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
		//cout << "Person Constructor\n";
	}
	void Print()
	{
		cout << "Name: " << name << "\tAge: " << age << "\t";
	}
	void Input()
	{
		char buff[20];
		cout << "Enter Name: ";
		cin.getline(buff, 20);
		name = new char[strlen(buff) + 1];
		strcpy_s(name, strlen(buff) + 1, buff);
		cout << "Enter age: ";
		cin >> age;
	}
	~Person()
	{
		delete[]name;
		//cout << "Person Destructor\n";
	}
};


class Student : public Person
{
	char* University;
public:
	Student() = default;
	Student(const char* n, int a, const char* uni) :Person(n, a)
	{
		University = new char[strlen(uni) + 1];
		strcpy_s(University, strlen(uni) + 1, uni);
	}
	~Student() {
		delete[] University;
		cout << "Destructor";

	}

	void Print() // переопределение
	{
		Person::Print(); // вызов метода Print() родительского класса !!!!
		cout << "University: " << University << endl;
	}

	void Input(const char* uni)
	{
		delete[] University;
		University = new char[strlen(uni) + 1];
		strcpy_s(University, strlen(uni) + 1, uni);
		Person::Input();
	}
};


class Teacher :public Person
{
	char* University;
	int salary;
	string arr[];
public:
	Teacher() = default;
	Teacher(const char* n, int a, const char* uni,int s,string arr2[]) :Person(n, a)
	{
		University = new char[strlen(uni) + 1];
		strcpy_s(University, strlen(uni) + 1, uni);
		salary = s;
		for (int i = 0; i < 3; i++) {
			arr[i] = arr2[i];
		}

	}
	~Teacher() {
		delete[] University;
		cout << "Destructor";

	}
	void Print() // переопределение
	{
		Person::Print(); // вызов метода Print() родительского класса !!!!
		cout << "University: " << University << endl;
		cout << "Salary:"<< salary<<endl;
		cout << "Professions:"  << endl;
		for (int i = 0; i < 3;i++) {
			arr[i];
		}

	}

	void Input(const char* uni,int s)
	{
		delete[] University;
		University = new char[strlen(uni) + 1];
		strcpy_s(University, strlen(uni) + 1, uni);
		salary = s;
		Person::Input();
	}




};

class Driver :public Person
{
	char* car_name;
	long number;
public:

	Driver() = default;
	Driver(const char* n, int a, const char* uni, long s) :Person(n, a)
	{
		car_name = new char[strlen(uni) + 1];
		strcpy_s(car_name, strlen(uni) + 1, uni);
		number = s;
	}
	~Driver() {
		delete[] car_name;
		cout << "Destructor";

	}
	void Print() // переопределение
	{
		Person::Print(); // вызов метода Print() родительского класса !!!!
		cout << "Car name: " << car_name << endl;
	}

	void Input(const char* uni,long s)
	{
		delete[] car_name;
		car_name = new char[strlen(uni) + 1];
		strcpy_s(car_name, strlen(uni) + 1, uni);
		number = s;
		Person::Input();
	}

};

class Doctor :public Person
{
	char* nishe;
	char* hospital;
	short work_exp;
public:

	Doctor() = default;
	Doctor(const char* n, int a, const char* uni, short s,const char* hos) :Person(n, a)
	{
		nishe = new char[strlen(uni) + 1];
		strcpy_s(nishe, strlen(uni) + 1, uni);
		hospital= new char[strlen(hos) + 1];
		strcpy_s(hospital, strlen(hos) + 1, hos);
		work_exp = s;
	}
	~Doctor() {
		delete[] nishe;
		delete[] hospital;

		cout << "Destructor";

	}
	void Print() // переопределение
	{
		Person::Print(); // вызов метода Print() родительского класса !!!!
		cout << "nishe: " << nishe << endl;
		cout << "Hospital: " << hospital << endl;
		cout << "Work expirience: " << work_exp << endl;

	}

	void Input(const char* uni,const char* hos,short s)
	{
		delete[] hospital;
		hospital = new char[strlen(uni) + 1];
		strcpy_s(hospital, strlen(uni) + 1, uni);
		delete[] nishe;
		nishe = new char[strlen(hos) + 1];
		strcpy_s(nishe, strlen(hos) + 1, hos);
		work_exp = s;
		Person::Input();
	}

};
int main()
{
	Student obj("Nina", 19, "Politeh");
	obj.Input("grtg");
	string arr[3] = {"Math","Physic","IT"};
	Teacher Mira("dv",3,"k",3,arr);

}
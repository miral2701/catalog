#include<iostream>
using namespace std;


class Human {
protected:
	string name;
	int age;
public:
	Human(string a,int b) {
		name = a;
		age = b;
	}
	int getAge() {
		return age;
	}
	string getName() {
		return name;
	}

	void setAge(int a) {
		age=a;
	}
	void setName(string a) {
		name=a;
	}

};

class University {
protected:
	string name_univer;
	int year;
	string rector;
public:
	University(string a, int b,string c) {
		name_univer = a;
		year = b;
		rector = c;
	}
	int getYear() {
		return year;
	}
	string getName() {
		return name_univer;
	}
	string getRector() {
		return rector;
	}

	void setYear(int a) {
		year = a;
	}
	void setName(string a) {
		name_univer = a;
	}
	void setRector(string a) {
		rector = a;
	}
};

class Student:public University, public Human
{
	int arr[10];
	int year;
	string faculty;

public:
	Student(int* ar, int y, string faculty1, string a1, int b1, string c, string a, int b) :University(a1, b1, c), Human(a, b)
	{
		for (int i = 0; i < 10; i++) {
			arr[i] = ar[i];
		}
		year = y;
		faculty = faculty1;
	}
	int getAge() {
		return age;
	}
	string getName() {
		return name;
	}

	void setAge(int a) {
		age = a;
	}
	void setName(string a) {
		name = a;
	}

};



int main() {

}
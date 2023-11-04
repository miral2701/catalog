#include<iostream>
//#include <windows.h>
using namespace std;
#define PI 3.14

class Test {
	int a;

public:
	Test() {//конструктор
		a = 10;
	}
	void Set(int x) {
		a = x;
	}

};

class Rectangle {
	int a;
	int b;
public:
	Rectangle() {
		a = 10;
		b = 5;
	}
	void Set_a(int x) {
		a = x;
	}

	void Set_b(int x) {
		b = x;
	}

	void Area() {
		cout << a * b;
	}

	void Perimetr() {
		cout << 2 * a + 2 * b;
	}
};

class Circle {
	int r;

public:
	Circle() {
		r = 4;
	}
	void Set(int x) {
		r = x;
	}
	void Area() {
		cout << PI*r*r;
	}
	void Perimetr() {
		cout << 2 * PI * r;
	}
};

//class Counter {
//	int count;
//public:
//	void Set_count(int x) {
//		count = x;
//	}
//	int Get_count() {
//		return count;
//	}
//	void Run() {
//		for (int i = 0; i < 10; i++) {
//			count++;
//		}
//	}
//};

int main() {
	//1
	Rectangle obj1;
	
	obj1.Area();

	//2Написать класс Circle. В нём должны быть методы Area() и Perimetr() для расчета площади и периметра окружности.
	Circle b;
	b.Area();
	b.Perimetr();

	//3

	return(0);
}
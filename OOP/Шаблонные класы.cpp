#include <iostream>
using namespace std;


template<typename T>
class Type//универсальний клас
{
	T value;
public:
	Type(T value);
	
	T getType();
	
};

template<typename T>
 Type<T>::Type(T value) {
	 this->value = value;
}

template<typename T>
T Type<T>::getType() {
	cout << typeid(value).name();

}
int main() {
	Type<int> t1(100);
	Type<short> t1(100);

}
#include<iostream>
using namespace std;

class Foo {
    int number;
public:
    Foo(int a) {
        number = a;
    }
    int GetNumber() {
        return number;
    }
};


template<class T>
class MyShared
{
    T* ptr;
    static int count;
public:
    MyShared();

    MyShared(T* pt);

    MyShared(const MyShared& b)
    {
        ptr = b.ptr;
        count++;
    }
    ~MyShared();
    T* Get();
    static int GetCount()
    {
        return count;
    }
};
template<class T>
int MyShared<T>::count = 0;

template<class T>
MyShared<T>::MyShared()
{
    ptr = nullptr;
    count++;
}
template<class T>
MyShared<T>::MyShared(T* pt)
{
    ptr = pt;
    count++;
}
template<class T>
MyShared<T>::~MyShared()
{
    if (count == 1)
    {
        delete ptr;
    }
    else
    {
        count--;
    }
}
template<class T>
T* MyShared<T>::Get()
{
    return ptr;
}

void main()
{
    MyShared<Foo> pt1(new Foo(10));
    cout << pt1.Get()->GetNumber() << endl;

    MyShared<Foo> pt2 = pt1;
    cout << pt1.GetCount() << endl;
}


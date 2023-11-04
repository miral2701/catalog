//На основе кода с. 52 урока №2(высланного в Тимс) создать шаблонный класс динамического массива.
//Добавить в этот класс метод Sum() для расчета суммы элементов инкапсулированного массива.
//В main() создать объекты этого класса, инкапсулирующие массивы типа int, double, char
//и Point, и вызвать для этих объектов метод Sum().
//Point - это класс, содержащий 2 поля(координаты точки) : int x и int y


#include <iostream>
using namespace std;
/* Внимание!Программа завершается аварийно! Для этого
 примера это нормально.*/

class Point
{
	int x;
	int y;
public:
	Point() {
		x = 0;
		y = 0;
	}
	Point(int a,int b) {
		x = a;
		y = b;
	}
	

	Point operator+(const Point& N)
	{
		Point temp;
		temp.x = this->x + N.x;
		temp.y = this->y + N.y;

		return temp;
	}
};
template<typename T>

class DynArray
{
	T* arr;
	int size;
public:
	DynArray(int sizeP)
		: arr{ new T[sizeP] {} }, size{ sizeP }
	{
		std::cout << "DynArr constructed for " << size
			<< " elements, for " << this << '\n';
	}
	DynArray() : DynArray(5) {}
	DynArray(const DynArray& object)
		: arr{ object.arr }, size{ object.size }
	{
		std::cout << "DynArr copy constructed for "
			<< size << " elements, for " << this
			<< '\n';
	}
	int getElem(T idx) { return arr[idx]; }
	void setElem(T idx, int val) { arr[idx] = val; }
	void print();
	void randomize();
	void sum();
	DynArray(const initializer_list<T>& list):DynArray(list.size())
	{
		int i = 0;
		for (auto element : list) {
			arr[i] = element;
			i++;
		}
	}
	
	~DynArray()
	{
		delete[] arr; std::cout << "DynArr destructed for"
			<< size << " elements, for"
			<< this << '\n';
	}
};



template<typename T>
void DynArray<T>::print()
{
	for (int i{ 0 }; i < size; ++i)
	{
		std::cout << arr[i] << ' ';
	}
	std::cout << '\n';
}

template<typename T>

void DynArray<T>::randomize()
{
	for (int i{ 0 }; i < size; ++i)
	{
		arr[i] = rand() % 10;
	}
}



template<typename T>

void DynArray<T>::sum()
{
	T sum = 0;
	for (int i{ 0 }; i < size; ++i)
	{
		sum+=arr[i];
	}
	std::cout <<"Sum: " << sum<<endl;
}

int main()
{
	DynArray<Point> arr_int = {1,3,5,7,9,5};
	std::cout << "ar1 elements: ";
	arr_int.print();
	arr_int.sum();

	cout << endl;

	//DynArray<double> arr_double{ 10 };
	//arr_double.randomize();
	//std::cout << "ar2 elements: ";
	//arr_double.print();
	//arr_double.sum();
	//cout << endl;

	//DynArray<char> arr_char{ 10 };
	//arr_int.randomize();
	//std::cout << "ar3 elements: ";
	//arr_char.print();
	//arr_char.sum();
	//cout << endl;

	/*DynArray<Point> arr_point{ 10 };
	arr_point.randomize();
	std::cout << "ar4 elements: ";
	arr_point.print();
	arr_point.sum();*/


	return 0;
}
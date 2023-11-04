#include <iostream>
using namespace std;
class Stack
{
	//Нижняя и верхняя границы стека
	enum { EMPTY = -1, FULL = 20 };
	//Массив для хранения данных
	char st[FULL + 1];
	//Указатель на вершину стека
	int top;
public:
	//Конструктор
	Stack();
	//Добавление элемента
	void Push(char c);
	//Извлечение элемента
	char Pop();
	//Очистка стека
	void Clear();
	//Проверка существования элементов в стеке
	bool IsEmpty();
	//Проверка на переполнение стека
	bool IsFull();
	//Количество элементов в стеке
	int GetCount();
	void Show();
	char* GetArray();
};

Stack::Stack()
{
	//Изначально стек пуст
	top = EMPTY;
}
void Stack::Clear()
{
	//Эффективная "очистка" стека
	//(данные в массиве все еще существуют,
	//но функции класса, ориентированные
	//на работу с вершиной стека,
	//будут их игнорировать)
	top = EMPTY;
}
bool Stack::IsEmpty()
{
	//Пуст?
	return top == EMPTY;
}
bool Stack::IsFull()
{
	//Полон?
	return top == FULL;
}
int Stack::GetCount()
{
	//Количество присутствующих в стеке элементов
	return top + 1;
}
void Stack::Push(char c)
{
	//Если в стеке есть место, то увеличиваем указатель
	//на вершину стека и вставляем новый элемент 
	if (!IsFull())
		st[++top] = c;
}
char Stack::Pop()
{
	//Если в стеке есть элементы, то возвращаем
	//верхний и уменьшаем указатель на вершину стека 
	if (!IsEmpty())
		return st[top--];
	else //Если в стеке элементов нет 
		return 0;
}

void Stack::Show() {
	for (int i = 0; i < FULL; i++) {
		cout << st[i]<<" ";
	}
}
char* Stack::GetArray() {
	return st;
}


int main()
{
	srand(time(0));
	Stack ST;
	char c;
	//пока стек не заполнится
	while (!ST.IsFull()) {
		c = rand() % 4 + 70;
		ST.Push(c);
	}
	//пока стек не освободится
	ST.Show();
	Stack ST2;
	int i = 0;
	while (!ST2.IsFull()) {
		ST2.Push(ST.GetArray()[i]);
		i++;
	}
	cout << endl;
	ST2.Show();
	
}

// Принцип работы стека - последний зашел, первый вышел.
// Данная реализация класса Stack основана на статическом массиве. В классе закрыта возможность произвольного доступа
// к элементам массива. Интерфейс класса обеспечивает возможность доступа только к вершине стека.
// Вариант применения стека - анализ правильности синтаксических конструкций
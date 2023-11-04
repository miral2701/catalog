#include <iostream>
using namespace std;
class Stack
{
	//������ � ������� ������� �����
	enum { EMPTY = -1, FULL = 20 };
	//������ ��� �������� ������
	char st[FULL + 1];
	//��������� �� ������� �����
	int top;
public:
	//�����������
	Stack();
	//���������� ��������
	void Push(char c);
	//���������� ��������
	char Pop();
	//������� �����
	void Clear();
	//�������� ������������� ��������� � �����
	bool IsEmpty();
	//�������� �� ������������ �����
	bool IsFull();
	//���������� ��������� � �����
	int GetCount();
	void Show();
	char* GetArray();
};

Stack::Stack()
{
	//���������� ���� ����
	top = EMPTY;
}
void Stack::Clear()
{
	//����������� "�������" �����
	//(������ � ������� ��� ��� ����������,
	//�� ������� ������, ���������������
	//�� ������ � �������� �����,
	//����� �� ������������)
	top = EMPTY;
}
bool Stack::IsEmpty()
{
	//����?
	return top == EMPTY;
}
bool Stack::IsFull()
{
	//�����?
	return top == FULL;
}
int Stack::GetCount()
{
	//���������� �������������� � ����� ���������
	return top + 1;
}
void Stack::Push(char c)
{
	//���� � ����� ���� �����, �� ����������� ���������
	//�� ������� ����� � ��������� ����� ������� 
	if (!IsFull())
		st[++top] = c;
}
char Stack::Pop()
{
	//���� � ����� ���� ��������, �� ����������
	//������� � ��������� ��������� �� ������� ����� 
	if (!IsEmpty())
		return st[top--];
	else //���� � ����� ��������� ��� 
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
	//���� ���� �� ����������
	while (!ST.IsFull()) {
		c = rand() % 4 + 70;
		ST.Push(c);
	}
	//���� ���� �� �����������
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

// ������� ������ ����� - ��������� �����, ������ �����.
// ������ ���������� ������ Stack �������� �� ����������� �������. � ������ ������� ����������� ������������� �������
// � ��������� �������. ��������� ������ ������������ ����������� ������� ������ � ������� �����.
// ������� ���������� ����� - ������ ������������ �������������� �����������
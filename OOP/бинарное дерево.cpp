#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
using namespace std;
struct Elem
{
	char Name[20]; 
	char Surname[20]; 
	char Fathersname[20];
	float mid_grade;
	Elem* left, * right, * parent;
};

class Tree
{
	//������
	Elem* root;
public:
	Tree();
	~Tree();
	//������ �� ���������� ����
	void Print(Elem* Node);
	//����� �� ���������� ����
	Elem* Search(Elem* Node, char* key);
	//min �� ���������� ����
	Elem* Min(Elem* Node);
	//max �� ���������� ����
	Elem* Max(Elem* Node);
	//��������� ��� ���������� ����
	Elem* Next(Elem* Node);
	//���������� ��� ���������� ����
	Elem* Previous(Elem* Node);
	//������� ����
	void Insert(Elem* z);
	//�������� ����� ��� ���������� ����,
	//0 - �������� ����� ������
	void Del(Elem* z = 0);
	//�������� ������
	Elem* GetRoot();
};
Tree::Tree()
{
	root = NULL;
}
Tree::~Tree()
{
	Del();
}

//����������� ����� ������
void Tree::Print(Elem* Node)
{
	if (Node != 0)
	{
		Print(Node->left);
		cout << Node->Name
			<< Node->Surname
			<< Node->Fathersname
			<<Node->mid_grade
			<< endl;
		Print(Node->right);
	}
}
Elem* Tree::Search(Elem* Node, char* k)
{
	//���� ���� ���� � ����� �� ���������
	while (Node != 0 && strcmp(k, Node->Name) != 0)
	{
		if (strcmp(k, Node->Name) < 0)
			Node = Node->left;
		else
			Node = Node->right;
	}
	return Node;
}
Elem* Tree::Min(Elem* Node)
{
	//����� ������ "������" ����
	if (Node != 0)
		while (Node->left != 0)
			Node = Node->left;
	return Node;
}
Elem* Tree::Max(Elem* Node)
{
	//����� ������ "�������" ����
	if (Node != 0)
		while (Node->right != 0)
			Node = Node->right;
	return Node;
}
Elem* Tree::Next(Elem* Node)
{
	Elem* y = 0;
	if (Node != 0)
	{
		//���� ���� ������ �������
		if (Node->right != 0)
			return Min(Node->right);
		//�������� ����
		y = Node->parent;
		//���� Node �� ������ � Node ������
		while (y != 0 && Node == y->right)
		{
			//�������� �����
			Node = y;
			y = y->parent;
		}
	}
	return y;
}
Elem* Tree::Previous(Elem* Node)
{
	Elem* y = 0;
	if (Node != 0)
	{
		//���� ���� ����� �������
		if (Node->left != 0)
			return Max(Node->left);

		//�������� ����
		y = Node->parent;
		//���� Node �� ������ � Node �����
		while (y != 0 && Node == y->left)
		{
			//�������� �����
			Node = y;
			y = y->parent;
		}
	}
	return y;
}
Elem* Tree::GetRoot()
{
	return root;
}
void Tree::Insert(Elem* z)
{
	//�������� ���
	z->left = NULL;
	z->right = NULL;
	Elem* y = NULL;
	Elem* Node = root;
	//����� �����
	while (Node != 0)
	{
		//������� ��������
		y = Node;
		if (strcmp(z->Name, Node->Name) < 0)
			Node = Node->left;
		else
			Node = Node->right;
	}

	//��������� ��������
	z->parent = y;
	if (y == 0) //������� ������ (������������)
		root = z;
	//��� ���� ������?
	else if (strcmp(z->Name, y->Name) < 0)
		y->left = z;
	else
		y->right = z;
}
void Tree::Del(Elem* z)
{
	//�������� �����
	if (z != 0)
	{
		Elem* Node, * y;
		//�� 2 �������
		if (z->left == 0 || z->right == 0)
			y = z;
		else
			y = Next(z);
		if (y->left != 0)
			Node = y->left;
		else
			Node = y->right;
		if (Node != 0)
			Node->parent = y->parent;
		//��������� �������� ����?
		if (y->parent == 0)
			root = Node;
		else if (y == y->parent->left)
			//����� �� ��������?
			y->parent->left = Node;
		else
			//������ �� ��������?
			y->parent->right = Node;
		if (y != z)
		{
			//����������� ������ ����
			strcpy(z->Name, y->Name);
			strcpy(z->Surname, y->Surname);
			strcpy(z->Fathersname, y->Fathersname);
			z->mid_grade = y->mid_grade;
		}
		delete y;
	}
	else //�������� ����� ������
		while (root != 0)
			Del(root);
}

void main()
{
}

//�� ���� ���� ��������� ������(������� �� ����� �9 ��� ���������� � ����) 
//������� ���������, ������� ������ � �������� ������ ��� ��������� � �� ������� �����.
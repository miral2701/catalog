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
	//корень
	Elem* root;
public:
	Tree();
	~Tree();
	//печать от указанного узла
	void Print(Elem* Node);
	//поиск от указанного узла
	Elem* Search(Elem* Node, char* key);
	//min от указанного узла
	Elem* Min(Elem* Node);
	//max от указанного узла
	Elem* Max(Elem* Node);
	//следующий дл€ указанного узла
	Elem* Next(Elem* Node);
	//предыдущий дл€ указанного узла
	Elem* Previous(Elem* Node);
	//вставка узла
	void Insert(Elem* z);
	//удаление ветки дл€ указанного узла,
	//0 - удаление всего дерева
	void Del(Elem* z = 0);
	//получить корень
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

//–екурсивный обход дерева
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
	//ѕока есть узлы и ключи не совпадают
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
	//ѕоиск самого "левого" узла
	if (Node != 0)
		while (Node->left != 0)
			Node = Node->left;
	return Node;
}
Elem* Tree::Max(Elem* Node)
{
	//ѕоиск самого "правого" узла
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
		//если есть правый потомок
		if (Node->right != 0)
			return Min(Node->right);
		//родитель узла
		y = Node->parent;
		//если Node не корень и Node справа
		while (y != 0 && Node == y->right)
		{
			//ƒвижемс€ вверх
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
		//если есть левый потомок
		if (Node->left != 0)
			return Max(Node->left);

		//родитель узла
		y = Node->parent;
		//если Node не корень и Node слева
		while (y != 0 && Node == y->left)
		{
			//ƒвижемс€ вверх
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
	//потомков нет
	z->left = NULL;
	z->right = NULL;
	Elem* y = NULL;
	Elem* Node = root;
	//поиск места
	while (Node != 0)
	{
		//будущий родитель
		y = Node;
		if (strcmp(z->Name, Node->Name) < 0)
			Node = Node->left;
		else
			Node = Node->right;
	}

	//заполн€ем родител€
	z->parent = y;
	if (y == 0) //элемент первый (единственный)
		root = z;
	//чей ключ больше?
	else if (strcmp(z->Name, y->Name) < 0)
		y->left = z;
	else
		y->right = z;
}
void Tree::Del(Elem* z)
{
	//удаление куста
	if (z != 0)
	{
		Elem* Node, * y;
		//не 2 ребенка
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
		//”дал€етс€ корневой узел?
		if (y->parent == 0)
			root = Node;
		else if (y == y->parent->left)
			//слева от родител€?
			y->parent->left = Node;
		else
			//справа от родител€?
			y->parent->right = Node;
		if (y != z)
		{
			// опирование данных узла
			strcpy(z->Name, y->Name);
			strcpy(z->Surname, y->Surname);
			strcpy(z->Fathersname, y->Fathersname);
			z->mid_grade = y->mid_grade;
		}
		delete y;
	}
	else //удаление всего дерева
		while (root != 0)
			Del(root);
}

void main()
{
}

//Ќа базе кода бинарного дерева(вз€того из урока є9 или высланного в “имс) 
//создать программу, котора€ хранит в бинарном дереве ‘»ќ студентов и их средние баллы.
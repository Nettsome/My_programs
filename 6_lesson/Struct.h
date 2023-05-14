#pragma once
#include <string>

struct value
{
	int x;
	int count = 1;	// ������� ��� ���������� �������
};

struct node
{
	value v;
	int height = 1;
	node* left = nullptr;
	node* right = nullptr;
};


struct person
{
	char name[20];
	int score;
	int count = 1;
};

struct person_node
{
	person p;
	int height = 1;
	person_node* left = nullptr;
	person_node* right = nullptr;
};
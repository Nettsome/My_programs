#pragma once
#include <string>

struct value
{
	int x;
	int count = 1;	// сколько раз встретился элемент
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
	double score;
	int count = 1;
	person* another_pers = nullptr;		// Другой студент
};

struct person_node
{
	person p;
	int height = 1;
	person_node* left = nullptr;
	person_node* right = nullptr;
};
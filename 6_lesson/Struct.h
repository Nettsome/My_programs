#pragma once
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
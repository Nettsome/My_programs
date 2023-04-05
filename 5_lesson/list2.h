#pragma once



struct elem
{
	int x;

	elem* next = nullptr;

	elem* prev = nullptr;
};


struct list2
{
	elem* first = nullptr;
	elem* last = nullptr;
};


void		add(list2& list, int x);

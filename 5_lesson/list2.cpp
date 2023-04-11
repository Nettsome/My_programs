#include "list2.h"
#include <iostream>

using namespace std;

void print_list(list2& list) 
{
	elem* curr = list.first;

	while (curr)
	{
		cout << curr->x;
		if (curr == list.last)
			return;
		curr = curr->next;
	}
}

void		add(list2& list, int x)
{
	elem* newel = new elem;
	newel->x = x;
	
	if (!list.first)
	{
		list.first = newel;
		list.last = newel;
	}
	else
	{
		if (x < list.first->x)
		{
			newel->next = list.first;
			list.first->prev = newel;
			list.first = newel;
		}
		if (x > list.last->x)
		{
			list.last->next = newel;
			newel->prev = list.last;
			list.last = newel;
		}
		else
		{
			elem* curr = list.first;

			while (curr->next)
			{
				if (curr->x > x)
				{
					newel->next = curr; 
					newel->prev = curr->prev; 
					curr->prev->next = newel; 
					curr->prev = newel; 
					return;
				}
				curr = curr->next;
			}
			if (curr->x > x)
			{
				newel->next = curr;
				newel->prev = curr->prev;
				curr->prev->next = newel;
				curr->prev = newel;
				return;
			}
		}
		int i = 5 + 5;
	}
}



void add_unique(list2& list, int x)
{
	elem* newel = new elem;
	newel->x = x;

	if (!list.first)
	{
		list.first = newel;
		list.last = newel;

	}
	else
	{
		elem* curr = list.first;

		while (curr)
		{
			if (curr->x == x)
			{
				return;
			}
			//if (curr == list.last)
				//break;
			curr = curr->next;
		}
		newel->next = list.last->next;
		list.last->next = newel;
		newel->prev = list.last;
		list.last = newel;
	}
}





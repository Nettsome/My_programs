#include "list2.h"

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
#include "List.h"
#include <cstring>


void add(list_elem*& list, person student)
{
	list_elem* newel = new list_elem;
	newel->student = student;

	if (list)
	{
		list_elem* curr = list;

		while (curr->next)
		{
			curr = curr->next;
		}
		curr->next = newel;
	}
	else
	{
		list = newel;
	}
	list->size++;
}

bool pop(list_elem*& list, person& stud)
{
	if (!list) return false;


	auto* old = list;
	stud = list->student;
	list = list->next;
	delete old;
	return true;
}

void separation(list_elem*& list, list_elem*& group1, list_elem*& group2)
{
	person stud;
	while (pop(list, stud))
	{
		if (stud.group == 1)
		{
			if (!group1)								//	Если 1 группа пустая
			{
				list_elem* newel = new list_elem;
				newel->student = stud;
				group1 = newel;
			}
			else										// Если 1 группа не пустая, то сортируем вновь прибывших в список студентов
			{
				list_elem* curr = group1;
				while (strcmp(group1->student.name, curr->student.name) > 0 && curr->next)	// ???????????????
				{
					curr = curr->next;

				}
			}
		}
		else if (stud.group == 2)
		{

		}
	}
}

void swaptwo(list_elem*& list)
{
	
}
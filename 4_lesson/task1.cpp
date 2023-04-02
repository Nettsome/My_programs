#include "List.h"
#include <cstring>
//#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void separation(list_elem*& list, list_elem*& group1, list_elem*& group2)
{
	person stud;
	while (pop(list, stud))
	{
		if (stud.group == 1)
		{
			add_in_sort_list(group1, stud);
		}
		else if (stud.group == 2)
		{
			add_in_sort_list(group2, stud);
		}
	}
}


void add_in_sort_list(list_elem*& list, person stud)
{
	list_elem* newel = new list_elem;
	newel->student = stud;

	if (!list)											//	Если группа пустая
	{
		list = newel;
		return;
	}
	else													//	Если группа не пустая, то сортируем вновь прибывшего в список студента
	{
		list_elem* curr = list;


		if (strcmp(stud.name, curr->student.name) <= 0)					//	Проверка первого элемента
		{
			newel->next = curr;
			list = newel;
			return;
		}


		while (curr->next) 												//	Проверка остальных
		{
			if (strcmp(stud.name, curr->next->student.name) <= 0)
				break;
			curr = curr->next;
		}
		newel->next = curr->next;
		curr->next = newel;
	}
}
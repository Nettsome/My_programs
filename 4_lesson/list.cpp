#include "List.h"
#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void	add(list_elem*& list, person student)
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
	//list->size++;
}

void	add_unique(list_int_elem*& list, int x)
{
	list_int_elem* newel = new list_int_elem;
	newel->x = x;

	if (list)
	{
		list_int_elem* curr = list;

		while (curr->next)
		{
			if (curr->x == x)
				return;
			curr = curr->next;
		}
		if (curr->x != x)
			curr->next = newel;
	}
	else
	{
		list = newel;
	}
}

bool	pop(list_elem*& list, person& stud)
{
	if (!list) return false;

	auto* old = list;
	stud = list->student;
	list = list->next;
	delete old;
	return true;
}

bool	pop(list_int_elem*& list, int& x)
{
	if (!list) return false;

	auto* old = list;
	x = list->x;
	list = list->next;
	delete old;
	return true;
}

void	open_file(const char* filename, list_elem*& list)
{
	ifstream f(filename);


	person p;
	if (f.is_open())
	{
		const int linelen = 256;
		char* line = new char[linelen];
		while (!f.eof())
		{
			f.getline(line, linelen);
			p = creat_person(line);
			add(list, p);
		}
		delete[] line;
		f.close();
	}
}

person	creat_person(char* person_data)
{
	person p;

	char* name = new char[50];
	int group;
	sscanf_s(person_data, "%s %d", name, 50, &group);
	strcpy_s(p.name, name);
	p.group = group;
	delete[] name;
	return p;
}


void swaptwo(list_int_elem*& list, int pos1, int pos2)			// pos1 < pos2
{
	if (list && pos1 > 0)
	{
		list_int_elem* curr = list;
		list_int_elem* p1 = list;
		list_int_elem* p2 = list;

		int pos = 1;
		
		while (curr->next)
		{
			if (pos == pos1)
			{
				p1 = curr;
			}
			if (pos == pos2)
			{
				p2 = curr;
			}
			curr = curr->next;
			pos++;
		}



		list_int_elem* p = p1->next->next;
		list_int_elem* pp = p1->next;

		p1->next->next = p2->next->next;

		p2->next->next = p;

		p1->next = p2->next;

		p2->next = pp;
	}
	else
	{
		if (pos2 == 1)
		{
			list_int_elem* first_next = list->next;

			list->next = first_next->next;

			first_next->next = list;

			list = first_next;

			return;
		}
		list_int_elem* first = list;
		list_int_elem* curr = list;
		list_int_elem* p2 = list;
		int pos = 1;

		while (curr->next)
		{
			if (pos == pos2)
			{
				p2 = curr;
				break;
			}
			pos++;
			curr = curr->next;
		}

		curr = curr->next->next;		// указатель на следующий элемент после pos2

		list = p2->next;

		p2->next->next = first->next;

		first->next = curr;

		p2->next = first;
	}
}
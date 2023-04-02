#include "List.h"
#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

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

void open_file(const char* filename, list_elem*& list)
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

person creat_person(char* person_data)
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

void separation(list_elem*& list, list_elem*& group1, list_elem*& group2)
{
	person stud;
	while (pop(list, stud))
	{
		if (stud.group == 1)
		{
			if (!group1)											//	Если 1 группа пустая
			{
				list_elem* newel = new list_elem;
				newel->student = stud;
				group1 = newel;
			}
			else													// Если 1 группа не пустая, то сортируем вновь прибывших в список студентов
			{

				list_elem* curr = group1;

				list_elem* newel = new list_elem;
				newel->student = stud;

				
				if (strcmp(stud.name, curr->student.name) < 0)					//	Проверка первого элемента
				{
					newel->next = curr;
					group1 = newel;
					continue;							// return;
				}


				while (curr->next) 												//	Проверка остальных
				{
					if (strcmp(stud.name, curr->next->student.name) < 0)
						break;
					if (strcmp(stud.name, curr->student.name) == 0)
					{

					}
					curr = curr->next;
				}
				newel->next = curr->next;
				curr->next = newel;
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
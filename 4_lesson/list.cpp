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



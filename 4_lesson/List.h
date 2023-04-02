#pragma once


struct person
{
	char name[20];
	int group;
};

struct list_elem
{
	person student;

	list_elem* next = nullptr;
	size_t size = 0;
};


void		add(list_elem*& list, person student);

bool		pop(list_elem*& list, person& stud);


void		open_file(const char* filename, list_elem*& list);
person			creat_person(char* person_data);


void		separation(list_elem*& list, list_elem*& group1, list_elem*& group2);
void			add_in_sort_list(list_elem*& list, person stud);




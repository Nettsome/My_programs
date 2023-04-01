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


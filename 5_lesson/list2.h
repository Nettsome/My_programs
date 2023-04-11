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

// Service
//====================

void	file_open(const char* filename, list2& list);

void	print_list(list2& list);

//====================

// Task 1
void	add(list2& list, int x);

void	add_unique(list2& list, int x);

// Task 2

struct cyclic_list
{
	elem* head = nullptr;
};

void	add_uniq_in_cyclic(cyclic_list& list, int x);

void	file_open(const char* filename, cyclic_list& list);

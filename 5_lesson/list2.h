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


struct cyclic_list
{
	elem* head = nullptr;
};


// Service
//====================

void	file_open(const char* filename, cyclic_list& list);

void	print_list(list2& list);

//====================

// Task 1
void	add(list2& list, int x);

void	add_unique(list2& list, int x);

// Task 2



void	add_uniq_in_cyclic(cyclic_list& list, int x);

bool	pop_cyclic_list(cyclic_list& list, int& x);

void	union_of_lists(cyclic_list& list, cyclic_list& first, cyclic_list& second);
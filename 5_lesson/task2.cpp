#include <iostream>
#include <fstream>
#include "list2.h"


using namespace std;

void	add_uniq_in_cyclic(cyclic_list& list, int x)
{
	elem* newel = new elem;
	newel->x = x;

	if (!list.head)
	{
		list.head = newel;
		newel->next = newel;
		newel->prev = newel;
	}
	else
	{
		elem* curr = list.head;

		while (curr->next != list.head)
		{
			if (curr->x == x)
				return;
			curr = curr->next;
		}
		if (curr->x == x)
			return;
		//	curr = элементу до list.head

		curr->next = newel;
		newel->prev = curr;
		newel->next = list.head;
		list.head->prev = newel;
	}
}

bool pop_cyclic_list(cyclic_list& list, int& x)
{
	if (!list.head)
		return false;

	auto* old_elem = list.head->prev;
	x = list.head->prev->x;

	if (old_elem != list.head)
	{
		old_elem->prev->next = list.head;
		list.head->prev = old_elem->prev;
		delete old_elem;
	}
	else
	{
		delete old_elem;
		list.head = nullptr;
	}
	return true;
}

void	union_of_lists(cyclic_list& list, cyclic_list& first, cyclic_list& second)
{
	int x;
	while (pop_cyclic_list(first, x))
	{
		add_uniq_in_cyclic(list, x);
	}
	while (pop_cyclic_list(second, x))
	{
		add_uniq_in_cyclic(list, x);
	}
}

void file_open(const char* filename, cyclic_list& list)
{
	ifstream f(filename);

	if (f.is_open())
	{
		const int linelen = 256;
		char* line = new char[linelen];

		while (!f.eof())
		{
			f.getline(line, linelen);
			
			int x;
			sscanf_s(line, "%d", &x);
			cout << x << endl;

			add_uniq_in_cyclic(list, x);
		}
		
		delete[] line;
		f.close();
	}
}
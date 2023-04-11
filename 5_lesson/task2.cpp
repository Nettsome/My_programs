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
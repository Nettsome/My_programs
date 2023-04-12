#include <iostream>
#include "list2.h"
#include <math.h>


using namespace std;

void task1()
{
	list2 list;

	for (int i = 1; i < 10; i++)
	{
		cout << i << endl;
		add_unique(list, i);
	}

	int x = 9;

	add_unique(list, x);

	cout << "---------" << endl;

	print_list(list);
}

void task2()
{
	return;
}

int main()
{
	const char* filename1 = "first_list.txt";
	const char* filename2 = "second_list.txt";

	cyclic_list first;
	cyclic_list second;

	file_open(filename1, first);
	file_open(filename2, second);

	cyclic_list list;
	union_of_lists(list, first, second);

}
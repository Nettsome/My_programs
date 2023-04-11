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

int main()
{
	const char* filename = "first_list.txt";

	cyclic_list list;

	file_open(filename, list);

}
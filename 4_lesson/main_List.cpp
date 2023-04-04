#include <iostream>
#include <fstream>
#include <sstream>
#include "List.h"


using namespace std;

void task1()
{
	setlocale(LC_ALL, "Rus");

	const char* filename = "students.txt";

	list_elem* list = nullptr;
	open_file(filename, list);

	person stud;

	list_elem* group1 = nullptr;
	list_elem* group2 = nullptr;

	separation(list, group1, group2);
	cout << "Group 1:" << endl;
	while (pop(group1, stud))
	{
		cout << stud.name << " " << stud.group << endl;
	}


	cout << "\nGroup 2:" << endl;
	while (pop(group2, stud))
	{
		cout << stud.name << " " << stud.group << endl;
	}
}

void task2()
{
	srand(time(0));

	list_int_elem* list = nullptr;

	for (int i = 0; i < 10; i++)
	{
		add_unique(list, i);
	}


	swaptwo(list, 1, 9);

	int x;
	while (pop(list, x))
	{
		cout << x << endl;
	}
}

void	task3()
{
	srand(time(0));
	list_int_elem* list = nullptr;
	int n;
	for (int i = 0; i < 10; i++)
	{
		//n = rand() % 10;
		cin >> n;
		//cout << n << endl;
		add_unique(list, n);
	}

	cout << "\n------------------------------------" << endl;
	while (pop(list, n))
	{
		cout << n << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");

	//task1();

	//task2();

	//task3();




}
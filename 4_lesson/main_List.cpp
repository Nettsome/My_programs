#include <iostream>
#include <fstream>
#include <sstream>
#include "List.h"


using namespace std;



int main()
{
	setlocale(LC_ALL, "Rus");

	const char* filename = "students.txt";

	list_elem* list = nullptr;
	open_file(filename, list);

	person stud;

	list_elem* group1 = nullptr;
	list_elem* group2 = nullptr;

	separation(list, group1, group2);
	while (pop(group1, stud))
	{
		cout << stud.name << " " << stud.group << endl;
	}
}
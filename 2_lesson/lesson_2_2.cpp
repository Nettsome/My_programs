#include <iostream>
#include "stek.h"
#include "work_files.h"

using namespace std;

// task 1_2 ======================================================================

char flip(char skob)
{
	if (skob == ')')
		return 40;
	else
		return skob - 2;
}


void check(const char* str, m_elem* stack) 
{
	for (int i = 0; i < strlen(str); i++) 
	{
		if (str[i] == '(' || str[i] == '{' || str[i] == '[' || (str[i] == '<')) 
		{
			push(stack, str[i], i + 1);
		}
		if (str[i] == ')' || str[i] == '}' || str[i] == ']' || (str[i] == '>')) 
		{
			int tpos;
			char tskob;
			if (pop(stack, tskob, tpos)) 
			{
				if (tskob != flip(str[i])) cout << "—кобки на позици€х " << tpos << " и " << i + 1 << " не совпадают" << endl;
			}
			else 
			{
				cout << "—кобка на позиции " << i + 1 << " лишн€€" << endl;
			}
		}
	}
	int tpos;
	char tskob;
	while (pop(stack, tskob, tpos)) 
	{
		cout << "—кобка на " << tpos << " лишн€€" << endl;
	}

}

void task1_2()
{
	setlocale(LC_ALL, "Rus");
	m_elem* stack = nullptr; 

	char str[] = "()<([>{}<)";
	cout << str << endl;
	check(str, stack);
}

void task2_2()
{

}

void task3_2()
{

}


#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

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

//	Functions
// ===============
void	add_in_list(list2& list, elem* newel);

void	separation(char* line, list2& list);
// ==============



void	file_open(const char* filename, list2& list)
{
	ifstream f(filename);

	if (f.is_open())
	{
		const int linelen = 1000;
		char* line = new char[linelen];


		while (!f.eof())
		{
			f.getline(line, linelen);


		}

		delete[] line;
		f.close();
	}
}


void	separation(char* line, list2& list)
{
	// «десь должна быть:
	// проверка корректности введенных данных
	// проверка на то, что строка не пуста€


	int n = strlen(line);
	int dec;

	while (n >= 9)
	{
		elem* newel = new elem;
		newel->x = 0;

		dec = 1;
		for (int i = 1; i <= 9; ++i)
		{
			newel->x += (line[n - 1] - 48) * dec;
			dec *= 10;
			n--;
		}
		add_in_list(list, newel);
	}

	if (n > 0)
	{
		elem* newel = new elem;
		newel->x = 0;

		dec = 1;
		for (int i = n - 1; i >= 0; i--)
		{
			newel->x += (line[i] - 48) * dec;
			dec *= 10;
		}
		add_in_list(list, newel);
	}
}


void	add_in_list(list2& list, elem* newel)
{
	if (!list.first)
	{
		list.first = newel;
		list.last = newel;
	}
	else
	{
		newel->next = list.first;
		newel->prev = list.first->prev;
		list.first->prev = newel;
		list.first = newel;
	}
}

//================
// Addition

void	addition(list2& cyclic_list, list2& list1, list2& list2)
{
	// ”казатели на последнии элементы
	elem* curr1 = list1.last;
	elem* curr2 = list2.last;

	while (curr1)
}

void	test1()
{
	char line[] = "12345123456789";
	list2 list;

	separation(line, list);
}

int main()
{
	test1();

}
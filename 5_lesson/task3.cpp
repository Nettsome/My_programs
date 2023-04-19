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
void	file_open(const char* filename, list2& list);

void	separation(char* line, list2& list);

void	add_in_list(list2& list, elem* newel);

void	addition(list2& cyclic_list, list2& list1, list2& list2);

void	add_in_cyclic(list2& list, int x);
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
			separation(line, list);
		}

		delete[] line;
		f.close();
	}
}


void	separation(char* line, list2& list)		//	Разделение большого числа на несколько маленьких и занесение их в список			
{
	// Здесь должна быть:
	// проверка корректности введенных данных

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


void	add_in_list(list2& list, elem* newel)	//	Добавление в начало списка
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
	elem* curr1 = list1.last;
	elem* curr2 = list2.last;

	int sum;
	short int mem = 0;

	while (curr1 || curr2)
	{
		if (curr1 && curr2)
		{
			sum = curr1->x + curr2->x + mem;

			if (sum >= 1000000000)
			{
				mem = 1;
				sum -= 1000000000;
			}
			else
				mem = 0;

			add_in_cyclic(cyclic_list, sum);

			curr1 = curr1->prev;
			curr2 = curr2->prev;
		}

		else if (curr1 && !curr2)	//	curr2 = null
		{
			sum = curr1->x + mem;

			if (sum >= 1000000000)
			{
				mem = 1;
				sum -= 1000000000;
			}
			else
				mem = 0;

			add_in_cyclic(cyclic_list, sum);

			curr1 = curr1->prev;
		}

		else if (curr2 && !curr1)
		{
			sum = curr2->x + mem;

			if (sum >= 1000000000)
			{
				mem = 1;
				sum -= 1000000000;
			}
			else
				mem = 0;

			add_in_cyclic(cyclic_list, sum);

			curr2 = curr2->prev;
		}		
	}
	if (mem == 1)
	{
		add_in_cyclic(cyclic_list, 1);
	}
}

void	add_in_cyclic(list2& list, int x)
{
	elem* newel = new elem;
	newel->x = x;

	if (!list.first)
	{
		list.first = newel;
		list.last = newel;
		newel->next = newel;
		newel->prev = newel;
	}
	else
	{
		newel->next = list.first;
		newel->prev = list.last;

		list.first->prev = newel;
		list.last->next = newel;
		list.first = newel;
	}
}

void	test1()
{
	char line[] = "12345123456789";
	list2 list;

	separation(line, list);
}

void	test2()
{
	char line1[] = "999999999999999999999999999";

	char line2[] = "1";

	list2 list_1;
	list2 list_2;

	separation(line1, list_1);
	separation(line2, list_2);

	list2 cyclic_list;

	addition(cyclic_list, list_1, list_2);


	//delete[] line1;
	//delete[] line2;
}

void	test3()
{
	const char* filename1 = "first_number.txt";
	const char* filename2 = "second_number.txt";

	list2 list_1;
	list2 list_2;

	file_open(filename1, list_1);
	file_open(filename2, list_2);

	list2 cyclic;
	addition(cyclic, list_1, list_2);

	cout << "Hello" << endl;
}

int main()
{


	test3();

}
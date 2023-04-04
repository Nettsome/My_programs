#include <iostream>
#include <time.h>

using namespace std;

struct	list_int_elem
{
	int x;
	list_int_elem* next = nullptr;
};

void	add_unique(list_int_elem*& list, int x)
{
	list_int_elem* newel = new list_int_elem;
	newel->x = x;

	if (list)
	{
		list_int_elem* curr = list;

		while (curr->next)
		{
			if (curr->x == x)
				return;
			curr = curr->next;
		}
		if (curr->x != x)
			curr->next = newel;
	}
	else
	{
		list = newel;
	}
}

bool	pop(list_int_elem*& list, int& x)
{
	if (!list) return false;

	auto* old = list;
	x = list->x;
	list = list->next;
	delete old;
	return true;
}


//int main()
//{
//	setlocale(LC_ALL, "");
//	srand(time(0));
//
//	list_int_elem* list = nullptr;
//	int n;
//
//	for (int i = 0; i < 10; i++)								//	Вставка элементов
//	{
//		//n = rand() % 10;
//		cin >> n;
//		//cout << n << endl;
//		add_unique(list, n);
//	}
//
//	cout << "\n------------------------------------" << endl;
//	while (pop(list, n))										//	Вывод уникальных значений
//	{
//		cout << n << endl;
//	}
//}
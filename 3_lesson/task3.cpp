#include <iostream>
#include "queue.h"
#include <fstream>
#include <sstream>

using namespace std;

void m_enqueue(queue_P& q, elem elem_P);

void enqueue(queue_P& q, elem elem_P);

bool dequeue(queue_P& q, elem& elem_P);




void m_enqueue(queue_P& q, elem elem_P) // обычная вставка в очередь
{
	auto* new_elem = new queue_elem_P;
	new_elem->elem = elem_P;
	new_elem->prev = q.last;
	if (q.last) q.last->next = new_elem;
	q.last = new_elem;
	if (!q.first) q.first = new_elem;
	q.size++;
}

void enqueue(queue_P& q, elem elem_P)
{
	// если очередь пуста
	if (q.size == 0)
	{
		m_enqueue(q, elem_P);
		return;
	}

	elem tmp_elem;

	size_t size_q = q.size;
	int stop = 0;
	for (size_t i = 0; i < size_q; i++)
	{
		dequeue(q, tmp_elem);
		if (tmp_elem.P < elem_P.P && stop == 0)
		{
			m_enqueue(q, elem_P);
			stop++;
		}
		m_enqueue(q, tmp_elem);
	}
	if (stop == 0) // ?????????????????????
	{
		m_enqueue(q, elem_P);
	}
}

bool dequeue(queue_P& q, elem& elem_P)
{
	if (!q.first) return false;
	elem_P = q.first->elem;
	auto* old_elem = q.first;
	q.first = q.first->next;
	delete old_elem;
	if (q.first) q.first->prev = nullptr;
	else q.last = nullptr;
	q.size--;
	return true;
}

void task3()
{
	queue_P q;
	elem P;

	cout << "Создание очереди:" << endl;
	for (int i = 20; i > 0; i -= 2)
	{
		P.P = i;
		cout << P.P << "; ";
		m_enqueue(q, P);
	}
	cout << endl;

	//cout << q.size << endl;


	P.P = 9;  // элемент, который мы хотим добавить
	cout << "\nP = " << P.P << endl;

	enqueue(q, P);

	cout << "\nВывод конечной очереди: " << endl;
	while (dequeue(q, P))
	{
		cout << P.P << endl;
	}
}
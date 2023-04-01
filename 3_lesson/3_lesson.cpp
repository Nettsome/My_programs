#include <iostream>
#include "queue.h"
#include <time.h>
#include <fstream>
#include <sstream>


using namespace std;

man			create_person(char* man_data);

void		file_open(const char* filename, queue& credit, queue& vklad);

void		save(const char* filename, queue& q);


void task1()
{
	queue credit;
	queue vklad;
	const char* filename = "input.txt";

	file_open(filename, credit, vklad);

	save("credit.txt", credit);
	save("vklad.txt", vklad);
}

void task2()
{
	srand(time(NULL));
	int C;
	cout << "¬ведите число:\nC = ";
	cin >> C; cout << "\n";
	int n = 0;
	n_queue q;
	for (int i = 1; i < 20; i++)
	{
		n = rand() % 15 + 1;
		cout << n << endl;
		enqueue(q, n);
	}
	n_queue q_less;
	n_queue q_more;

	while (dequeue(q, n))
	{
		if (n < C)
		{
			//cout << n << endl;
			enqueue(q_less, n);
		}
		else
		{
			enqueue(q_more, n);
		}
	}
	clear(q);

	cout << "Numbers less than " << C << endl;
	while (dequeue(q_less, n))
	{
		cout << n << endl;
	}
	clear(q_less);
	cout << "\nNumbers more than " << C << endl;
	while (dequeue(q_more, n))
	{
		cout << n << endl;
	}
	clear(q_more);


}



//struct elem
//{
//	int P; // приоритет
//	int x;
//};
//
//struct queue_elem_P
//{
//	elem elem;
//	//int P;
//	queue_elem_P* next = nullptr;
//	queue_elem_P* prev = nullptr;
//};
//
//struct queue_P
//{
//	queue_elem_P* first = nullptr;
//	//queue_elem_P* curr = nullptr;
//	queue_elem_P* last = nullptr;
//	size_t size = 0;
//
//};
//
//void m_enqueue(queue_P& q, elem elem_P) // обычна€ вставка в очередь
//{
//	auto* new_elem = new queue_elem_P;
//	new_elem->elem = elem_P;
//	new_elem->prev = q.last;
//	if (q.last) q.last->next = new_elem;
//	q.last = new_elem;
//	if (!q.first) q.first = new_elem;
//	q.size++;
//}
//
//void enqueue(queue_P& q, elem elem_P)
//{
//	// если очередь пуста
//	if (q.size == 0)  
//	{
//		m_enqueue(q, elem_P);
//	}
//
//	
//
//	elem tmp_elem;
//
//	for (int i = 0; i < q.size; i++)
//	{
//		dequeue(q, tmp_elem);
//		cout << "tmp_elem.P = " << tmp_elem.P << endl;
//		if (tmp_elem.P <= elem_P.P)
//		{
//			m_enqueue(q, elem_P);
//		}
//		m_enqueue(q, tmp_elem);
//	}
//}
//
//bool dequeue(queue_P& q, elem& elem_P)
//{
//	if (!q.first) return false;
//	elem_P = q.first->elem;
//	auto* old_elem = q.first;
//	q.first = q.first->next;
//	delete old_elem;
//	if (q.first) q.first->prev = nullptr;
//	else q.last = nullptr;
//	return true;
//}
//
//void task3()
//{
//	queue_P q;
//	elem P;
//
//	cout << "—оздание очереди:" << endl;
//	for (int i = 1; i < 20; i += 2)
//	{
//		P.P = i;
//		cout << P.P << "; ";
//		m_enqueue(q, P);
//	}
//	cout << endl;
//
//	P.P = 8;
//
//	enqueue(q, P);
//}

int main()
{
	setlocale(LC_ALL, "Rus");

	//task1();

	//task2();

	task3();
}
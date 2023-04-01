#pragma once

struct man
{
	char Fio[50];
	char gender[10];
	int age;
	char work[50];
	long long int zarplata;
	char tsel[10];
};

struct queue_elem
{
	man client;
	queue_elem* next = nullptr;
	queue_elem* prev = nullptr;
};

struct queue
{
	queue_elem* first = nullptr;
	queue_elem* last = nullptr;
};

void		enqueue(queue& q, man employee); 
bool		dequeue(queue& q, man& employee);
void		clear(queue& q);

///////////////////////////////////////////////////////////
// TASK 2

struct n_queue_elem
{
	int x;
	n_queue_elem* next = nullptr;
	n_queue_elem* prev = nullptr;
};

struct n_queue
{
	n_queue_elem* first = nullptr;
	n_queue_elem* last = nullptr;
};

void		enqueue(n_queue& q, int n);

bool		dequeue(n_queue& q, int& n);

void		clear(n_queue& q);

/////////////////////////////////////////////////////////
// TASK 3

struct elem
{
	int P; // приоритет
	int x;
};

struct queue_elem_P
{
	elem elem;
	//int P;
	queue_elem_P* next = nullptr;
	queue_elem_P* prev = nullptr;
};

struct queue_P
{
	queue_elem_P* first = nullptr;
	//queue_elem_P* curr = nullptr;
	queue_elem_P* last = nullptr;
	size_t size = 0;

};

void task3();
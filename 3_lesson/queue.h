#pragma once

struct man
{
	char Fio[50];
	char gender[10];
	int age;
	char work[50];
	int zarplata;
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
	size_t size = 0;
};

void		enqueue(queue& q, man employee); 
bool		dequeue(queue& q, man& employee);
void		clear(queue& q);

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

#include "queue.h"

void enqueue(queue& q, man client)
{
	auto* new_elem = new queue_elem;
	new_elem->client = client;
	new_elem->prev = q.last;
	if (q.last) q.last->next = new_elem;
	q.last = new_elem;
	if (!q.first) q.first = new_elem;
	q.size++;
}

bool dequeue(queue& q, man& client)
{
	if (!q.first) return false;
	client = q.first->client;
	auto* old_elem = q.first;
	q.first = q.first->next;
	delete old_elem;
	if (q.first) q.first->prev = nullptr;
	else q.last = nullptr;
	q.size--;
	return true;
}

void clear(queue& q)
{
	auto* curr = q.first;
	while (curr)
	{
		auto* old_elem = curr;
		curr = curr->next;
		delete old_elem;
	}
	//q.size = 0;
}


void enqueue(n_queue& q, int n)
{
	auto* new_elem = new n_queue_elem;
	new_elem->x = n;

	if (q.last) q.last->next = new_elem;
	q.last = new_elem;
	if (!q.first) q.first = new_elem;
}

bool dequeue(n_queue& q, int& n)
{
	if (!q.first) return false;
	n = q.first->x;
	auto* old_elem = q.first;
	q.first = q.first->next;
	delete old_elem;
	if (q.first) q.first->prev = nullptr;
	else q.last = nullptr;
	return true;
}

void clear(n_queue& q)
{
	auto* curr = q.first;
	while (curr)
	{
		auto* old_elem = curr;
		curr = curr->next;
		delete old_elem;
	}
	//q.size = 0;
}
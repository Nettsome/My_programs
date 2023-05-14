#pragma once
#include "Struct.h"

struct queue_elem
{
	node* tree_node;
	queue_elem* next = nullptr;
	queue_elem* prev = nullptr;
};

struct queue1
{
	queue_elem* first = nullptr;
	queue_elem* last = nullptr;
};

void enqueue(queue1& q, node* employee);
bool dequeue(queue1& q, node*& employee);
void clear(queue1& q);
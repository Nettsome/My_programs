#pragma once
#include "Struct.h"

struct queue_elem
{
	node* tree_node;
	queue_elem* next = nullptr;
	queue_elem* prev = nullptr;
};

struct queue
{
	queue_elem* first = nullptr;
	queue_elem* last = nullptr;
};

void enqueue(queue& q, node* employee);
bool dequeue(queue& q, node*& employee);
void clear(queue& q);


struct queue_p_elem
{
	person_node* tree_node;
	queue_p_elem* next = nullptr;
	queue_p_elem* prev = nullptr;
};

struct queue_p
{
	queue_p_elem* first = nullptr;
	queue_p_elem* last = nullptr;
};

void enqueue(queue_p& q, person_node* employee);
bool dequeue(queue_p& q, person_node*& node);
void clear(queue_p& q);
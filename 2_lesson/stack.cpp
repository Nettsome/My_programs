#include "stek.h"
#include <iostream>

using namespace std;

void push(elem*& top, int value)
{
	elem* new_el = new elem;
	new_el->x = value;
	new_el->next = top;
	top = new_el;
}

bool pop(elem*& top, int& value)
{
	if (!top) return false;

	value = top->x;
	auto old_el = top;
	top = top->next;
	delete old_el;
	return true;
}

bool peek(elem* top, int& value)
{
	if (!top) return false;

	value = top->x;
	return true;
}



//=======================================================================================================
void push2(twoelem*& top, int x, int y)
{
	twoelem* newel = new twoelem;
	newel->x = x;
	newel->y = y;
	newel->next = top;
	top = newel;
}

bool peek2(twoelem* top, int& x, int& y)
{
	if (!top) return false;

	x = top->x;
	y = top->y;
	return true;
}


bool pop2(twoelem*& top, int& x, int& y)
{
	if (!top) return false;

	x = top->x;
	y = top->y;
	auto old_el = top;
	top = top->next;
	delete old_el;
	return true;
}
// ==============================================================================================



void push_S(S_path_node*& path_stack, int i_curr, int j_curr, int i_prev, int j_prev)
{
	S_path_node* newel = new S_path_node;

	newel->curr_cell.i = i_curr;
	newel->curr_cell.j = j_curr;
	newel->prev_cell.i = i_prev;
	newel->prev_cell.j = j_prev;

	newel->next = path_stack;
	path_stack = newel;
}


bool pop_S(S_path_node*& stack, S_cell& curr, S_cell& prev)
{
	if (!stack) return false;

	curr = stack->curr_cell;
	prev = stack->prev_cell;

	auto old_el = stack;
	stack = stack->next;
	delete old_el;
	return true;

}

// ===========================================================
//	lesson_2_2

void push(m_elem*& stack, char skob, int pos)
{
	m_elem* newel = new m_elem;

	newel->pos = pos;
	newel->skobka = skob;
	newel->next = stack;
	stack = newel;
}

bool pop(m_elem*& stack, char& skob, int& pos)
{
	if (!stack) return false;

	skob = stack->skobka;
	pos = stack->pos;
	auto old = stack;
	stack = stack->next;
	delete old;
	return true;
}



// ==========================================================

//void push(c_elem*& stack, char c)
//{
//	c_elem* newel = new c_elem;
//
//	newel->c = c;
//	newel->next = stack;
//	stack = newel;
//}
//
//void push(d_elem*& stack, double c)
//{
//	d_elem* newel = new d_elem;
//
//	newel->num = c;
//	newel->next = stack;
//	stack = newel;
//}
//
//void pop(c_elem*& stack)
//{
//	if (!stack) return;
//
//	auto old = stack;
//	stack = stack->next;
//	delete old;
//	return;
//}
//
//void pop(d_elem*& stack)
//{
//	if (!stack) return;
//
//	auto old = stack;
//	stack = stack->next;
//	delete old;
//	return;
//}
//
//char	top(c_elem* stack)
//{
//	return stack->c;
//}
//
//double  top(d_elem* stack)
//{
//	return stack->num;
//}
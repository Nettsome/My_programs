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


// =====================================================================================================
//
// void cell(S_cell*& cell, int i, int j)
// {
// 	cell->i = i;
// 	cell->j = j;
// }
//
// void path_node(S_path_node*& path_node, S_cell curr_cell, S_cell prev_cell)
// {
// 	path_node->curr_cell = curr_cell;
// 	path_node->prev_cell = prev_cell;
// }
//
// void push_path(S_path_stack*& path_stack, S_path_node node)
// {
// 	S_path_stack* newel = new S_path_stack;
// 	newel->node = node;
// 	newel->next = path_stack;
// 	path_stack = newel;
// }
//
// bool peek_path(S_path_node* path_stack, S_cell curr_cell, S_cell prev_cell)
// {
//
// }
//
//
// ===========================================================================================================


//void push_R(R_path_stack*& path_stack, int i_curr, int j_curr, int i_prev, int j_prev)
//{
//	R_path_stack* newel = new R_path_stack;
//
//	newel->i_curr = i_curr;
//	newel->j_curr = j_curr;
//	newel->i_prev = i_prev;
//	newel->j_prev = j_prev;
//
//	newel->next = path_stack;
//	path_stack = newel;
//}

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



//bool pop_R(R_path_stack*& stack, int& i_curr, int& j_curr, int& i_prev, int& j_prev)
//{
//	if (!stack) return false;
//
//	i_curr = stack->i_curr;
//	j_curr = stack->j_curr;
//	i_prev = stack->i_prev;
//	j_prev = stack->j_prev;
//
//	// cout << i_curr << "\t" << j_curr << endl;
//
//	auto old_el = stack;
//	stack = stack->next;
//	delete old_el;
//	return true;
//}


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
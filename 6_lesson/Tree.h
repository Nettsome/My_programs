#pragma once
#include "Struct.h"
#include "queue.h"
#include <string>

struct tree
{
	node* root = nullptr;
};

bool add(tree& t, int value);
int find(tree  t, int value);
bool remove(tree& t, int value);
void drop(tree& t);

// очереди для вывода на экран
queue prefix_traverse(tree& t);
queue infix_traverse(tree& t);
queue postfix_traverse(tree& t);
queue wide_traverse(tree& t);

void	balance(tree& t);


struct person_tree
{
	person_node* root = nullptr;
};

bool	add(person_tree*& tree, person pers);
int		find(person_tree tree, char c);
void	drop(person_node*& root);




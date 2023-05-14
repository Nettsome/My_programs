#pragma once
#include "Struct.h"
#include "queue.h"
#include <iostream>


struct tree
{
	node* root = nullptr;
};

bool add(tree& t, int value);
int find(tree  t, int value);
bool remove(tree& t, int value);
void drop(tree& t);

// ������� ��� ������ �� �����
queue prefix_traverse(tree& t);
queue infix_traverse(tree& t);
queue postfix_traverse(tree& t);
queue wide_traverse(tree& t);

void	balance(tree& t);


struct person_tree
{
	person_node* root = nullptr;
};

bool		add(person_tree& tree, person pers);
queue_p		find(person_tree tree, char c);
void		drop(person_node*& root);



void	printStudentsBySurname(person_node* root, char c);




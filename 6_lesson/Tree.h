#pragma once
#include "Struct.h"
#include "queue.h"
#include "WorkFiles.h"
#include <iostream>
#include <stdio.h>


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


// Task 2
struct person_tree
{
	person_node* root = nullptr;
};

bool		add(person_tree& tree, person pers);
queue_p		find(person_tree tree, char c);
void		drop(person_tree& root);



bool		printStudentsBySurname(person_tree t, char c);
void		balance_person_tree(person_tree& tree);

// очереди для вывода на экран
queue_p		postfix_traverse(person_tree& t);


#pragma once
#include <list>
#include <queue>
#include <string>

struct node
{
	std::string name = "";
	int level = -1;
	std::list<node*> list;
};

struct tree
{
	node* root = new node;
	tree()
	{
		root->name = "\\";
		root->level = 0;
	}
	~tree()
	{
		delete root;
		root = nullptr;
	}
};



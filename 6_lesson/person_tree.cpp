#include "Tree.h"
//#include <queue>

using namespace std;

bool	add(person_node*& root, person pers);
void	drop(person_node*& root);
int		get_height(const person_node* root);
void	find(person_node* root, char c, queue_p q);


bool	add(person_tree*& tree, person pers)
{
	return add(tree->root, pers);
}

queue_p		find(person_tree tree, char c)
{
	queue_p q;
	find(tree.root, c, q);
	return q;
}

void	drop(person_tree& tree)
{
	drop(tree.root);
}

// output


void	drop(person_node*& root)
{
	if (!root) return;
	if (root->left) drop(root->left);
	if (root->right) drop(root->right);
	delete root;
	root = nullptr;
}

bool	add(person_node*& root, person pers)
{
	if (!root)
	{
		auto* new_node = new person_node;
		strcpy_s(new_node->p.name, pers.name);
		new_node->p.score = pers.score;
		root = new_node;
		return true;
	}
	if (strcmp(root->p.name, pers.name) == 0)
	{
		root->p.count++;
		root->p.score = (double)(root->p.score + pers.score) / 2;
		return false;
	}
	const auto result = add(strcmp(pers.name, root->p.name) < 0 ? root->left : root->right, pers);
	if (result) root->height = get_height(root);
	return result;
}

int		get_height(const person_node* root)
{
	if (!root) return 0;
	const auto lh = (root->left) ? root->left->height : 0;
	const auto rh = (root->right) ? root->right->height : 0;
	return 1 + (lh < rh ? rh : lh);
}



void	find(person_node* root, char c, queue_p q)	// Not complete
{
	if (root)
	{
		if (c == root->p.name[0])
		{
			enqueue(q, root);
			find(c == root->right->p.name[0] ? root->right : nullptr, c, q);
			return;
		}
		find(c >= root->p.name[0] ? root->right : root->left, c, q);
	}
	else return;
}
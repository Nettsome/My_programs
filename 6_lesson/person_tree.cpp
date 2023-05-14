#include "Tree.h"
#include <queue>

using namespace std;

bool	add(person_node*& root, person pers);

bool	add(person_tree*& tree, person pers)
{
	return add(tree->root, pers);
}

int		find(person_tree tree, char c)
{
	return find(tree.root, c);
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

int		find(const person_node* root, char c)
{
	std::queue<person> q;
	if (root)
	{
		if (root->p.name[0] == c) q.push(root->p);
		return find(c >= root->p.name[0] ? root->right : root->left, c);
	}
}
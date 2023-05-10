#include "Tree.h"
#include <iostream>

using namespace std;

void	Creat_tree(tree& t, size_t count)
{
	for (size_t i = 0; i < count; ++i)
	{
		add(t, i);
	}
}

void	show_tree(tree t)
{
	queue q = wide_traverse(t);
	auto curr = q.first;
	int count = 0;
	int two = 1;
	while (curr)
	{
		const auto v = curr->tree_node;
		if (!v) cout << "[-]";
		else cout << (char)(v->v.x) << "(" << v->v.count << ")";
		cout << " ";
		curr = curr->next;
		if (!(count % two))
		{
			cout << endl;
			count = 0;
			two *= 2;
		}
		count++;
	}
	clear(q);
}

int	main()
{
	tree t;
	//Creat_tree(t, 7);
	int a[] = { 'B', 'A', 'E', 'F', 'C', 'D' };
	for (int i : a)
	{
		add(t, i);
	}
	show_tree(t);
	cout << "Balanced tree:" << endl;
	balance(t);
	show_tree(t);
	drop(t);

	//cout << 2 % 4;
}
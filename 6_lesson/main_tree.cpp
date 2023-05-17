#include "Tree.h"
//#include <iostream>
#include <chrono>

using namespace std;


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
		else cout << (int)(v->v.x) << "(" << v->height << ")";
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

void	show_person_tree(person_tree t)
{
	queue_p q = postfix_traverse(t);
	auto curr = q.first;
	while (curr)
	{
		const auto v = curr->tree_node;
		if (!v) cout << "[-]";
		else cout << (v->p.name) << " - " << v->p.score << endl;
		curr = curr->next;
	}
}

void	task1()
{
	tree t;
	tree t_b;
	//int a[] = { 'B', 'A', 'E', 'F', 'C', 'D' };
	//int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 ,12, 13, 14, 15 };
	//int a[] = { 4, 2, 6, 1, 3, 5, 7 };

	//for (int i : a)
	//{
	//	add(t, i);
	//	add(t_b, i);
	//}

	for (int i = 1; i < 16; i++)
	{
		add(t, i);
		add(t_b, i);
	}

	//show_tree(t);
	cout << "\nBalanced tree:" << endl;
	balance(t_b);
	show_tree(t_b);

	cout.precision(10);

	
	auto start_time = chrono::steady_clock::now();
	find(t, 5053);
	auto end_time = chrono::steady_clock::now();
	auto elapsed_ns = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time);
	cout << "\nNon balanced tree: " << elapsed_ns.count() << " ns" << endl;

	start_time = chrono::steady_clock::now();
	find(t_b, 5053);
	end_time = chrono::steady_clock::now();
	elapsed_ns = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time);
	cout << "\nBalanced tree: " << elapsed_ns.count() << " ns" << endl;	



	drop(t);
}


void	task2()
{
	setlocale(LC_ALL, "Rus");
	person_tree t;

	const char* filename = "students.txt";
	open_file(filename, t.root, by_name);

	show_person_tree(t);

	balance_person_tree(t);

	char c = 'П';
	cout << "\nВывод студентов на букву " << c << ":" << endl;
	if (!printStudentsBySurname(t, c))
		cout << "Таких студентов нет" << endl;
		

	drop(t);
}

void	task3()
{
	setlocale(LC_ALL, "Rus");
	person_tree t;

	const char* filename = "students.txt";
	open_file(filename, t.root, by_score);


	show_person_tree(t);
}

int	main()
{
	//task1();

	//task2();

	task3();
}
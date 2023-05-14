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

	for (int i = 1; i < 2048; i++)
	{
		add(t, i);
		add(t_b, i);
	}

	//show_tree(t);
	cout << "\nBalanced tree:" << endl;
	balance(t_b);
	//show_tree(t_b);

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

person	CreatPerson(char* pers_data)
{
	person p;

	char* name = new char[20];
	double score;

	sscanf_s(pers_data, "%s %lf", name, 20, &score);
	strcpy_s(p.name, name);
	p.score = score;
	delete[] name;

	return p;
}

void	task2()
{
	person_tree t;

	char name[20] = "Ivanov 4.5";
	person pers = CreatPerson(name);
	add(t, pers);

	strcpy_s(name, "Petrov 4.0");
	pers = CreatPerson(name);
	add(t, pers);

	strcpy_s(name, "Sergeev 4.2");
	pers = CreatPerson(name);
	add(t, pers);

	strcpy_s(name, "Petrov 2.0");
	pers = CreatPerson(name);
	add(t, pers);

	strcpy_s(name, "Sidorov 3.5");
	pers = CreatPerson(name);
	add(t, pers);

	printStudentsBySurname(t.root, 'S');
}

int	main()
{
	//task1();

	task2();


}
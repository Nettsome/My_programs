#include <iostream>
#include "queue.h"
#include <time.h>
#include <fstream>
#include <sstream>


using namespace std;

man			create_person(char* man_data);

void		file_open(const char* filename, queue& credit, queue& vklad);

void		save(const char* filename, queue& q);



void task1()
{
	queue credit;
	queue vklad;
	const char* filename = "input.txt";

	file_open(filename, credit, vklad);
}

void task2()
{
	srand(time(0));
	int C;
	cout << "¬ведите число:\nC = ";
	cin >> C; cout << "\n";
	int n = 0;
	n_queue q;
	for (int i = 1; i < 20; i++)
	{
		n = rand() % 15 + 1;
		cout << n << endl;
		enqueue(q, n);
	}
	n_queue q_less;
	n_queue q_more;

	while (dequeue(q, n))
	{
		if (n < C)
		{
			//cout << n << endl;
			enqueue(q_less, n);
		}
		else
		{
			enqueue(q_more, n);
		}
	}
	clear(q);

	cout << "Numbers less than " << C << endl;
	while (dequeue(q_less, n))
	{
		cout << n << endl;
	}
	clear(q_less);
	cout << "\nNumbers more than " << C << endl;
	while (dequeue(q_more, n))
	{
		cout << n << endl;
	}
	clear(q_more);


}















int main()
{
	setlocale(LC_ALL, "Rus");

	task1();

	//task2();
}
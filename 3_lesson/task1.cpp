#include <iostream>
#include "queue.h"
#include <fstream>
#include <sstream>

using namespace std;


man			create_person(char* man_data);

void		file_open(const char* filename, queue& credit, queue& vklad);

void		save(const char* filename, queue& q);

void print_man(man m)
{
	cout.setf(ios::left);
	cout.width(10);
	cout << m.Fio << "\t";
	cout << m.gender << "\t";
	cout << m.age << "\t";
	cout.width(10);
	cout << m.work << "\t";
	cout.width(10);
	cout << m.zarplata << "\t"
		<< m.tsel << "\t" << endl;
}

void file_open(const char* filename, queue& credit, queue& vklad)
{
	ifstream f(filename);

	man man;
	if (f.is_open())
	{
		const int linelen = 256;
		char* line = new char[linelen];
		while (!f.eof())
		{
			f.getline(line, linelen);
			//cout << line << endl;
			man = create_person(line);

			if (!strcmp(man.tsel, "credit") || !strcmp(man.tsel, "кредит"))
			{
				enqueue(credit, man);
			}
			else
			{
				enqueue(vklad, man);
			}
		}
		delete[] line;

		cout << "credit mans:" << endl;
		while (dequeue(credit, man))
		{
			print_man(man);

		}
		cout << "vklad mans:" << endl;
		while (dequeue(vklad, man))
		{
			print_man(man);
		}
		f.close();
	}
}

man create_person(char* man_data)
{
	man m;

	char* name = new char[50];
	char* gender = new char[50];
	int age;
	char* work = new char[50];
	int zarplata;
	char* tsel = new char[50];

	sscanf_s(man_data, "%s %s %d %s %d %s", name, 50, gender, 50, &age, work, 50, &zarplata, tsel, 50);
	strcpy_s(m.Fio, name);
	strcpy_s(m.gender, gender);
	m.age = age;
	strcpy_s(m.work, work);
	m.zarplata = zarplata;
	strcpy_s(m.tsel, tsel);
	delete[] name;
	delete[] gender;
	delete[] work;
	delete[] tsel;
	return m;
}

void save(const char* filename, queue& q)
{
	ofstream f(filename);
	if (f.is_open())
	{
		man m;
		while (dequeue(q, m))
		{
			print_man(m);
			f << m.Fio << " " << m.gender << m.age << m.work << m.zarplata << m.tsel << endl;
		}
		f.close();
	}
}
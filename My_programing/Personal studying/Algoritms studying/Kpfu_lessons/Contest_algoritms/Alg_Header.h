#pragma once

#include <iostream>
#include <cassert>
#include <list>
#include "Alg_Header.h"

double problem_6_solution(int** things, int n, int w);

class Problems
{
private:

	// fib mod m
	unsigned int problem_3_solution(unsigned long n, unsigned int m)
	{
		assert(n >= 1 & m >= 2);

		if (n <= 1)
			return n;

		unsigned int f0 = 0;
		unsigned int f1 = 1;
		unsigned int fn;
		unsigned int tmp = -1;

		std::cout << "0 1 ";
		for (unsigned long i = 1; i < n; ++i)
		{
			fn = (f1 + f0) % m;
			f0 = f1;
			f1 = fn;

			if (fn == 0)
			{
				if (f1 + f0 == 1)
				{
					tmp = i + 1;
					break;
				}
			}
			std::cout << fn << " ";
		}

		if (tmp == -1)
			return fn;
		tmp = n % tmp;
		std::cout << "\ntmp = " << tmp << std::endl;

		if (tmp <= 1)
			return tmp;

		f0 = 0;
		f1 = 1;
		for (unsigned int i = 1; i < tmp; ++i)
		{
			fn = (f1 + f0) % m;
			f0 = f1;
			f1 = fn;
		}

		//std::cout << "fn = " << fn << std::endl;

		return fn;
	}

	void problem_5_solution(long* a, int n)
	{
		int min_index = 0;

		long min;
		long max;


		min = a[min_index];
		for (int i = 0; i < 2 * n; i += 2)
		{
			if (a[i] < min)
			{
				min = a[i];
				min_index = i;
			}
		}
		// найти отрезок, значение конца < a[min_index + 1]
	}


	/// <summary>
	/// Решение находиться в зеленой тетради
	/// n < k(k + 1) / 2	==>		k = (-1 +- sqrt(1 + 8n)) / 2
	/// А потом я на листочке расписал первые 21 значений и заметил закономерность:
	/// 1 = 1
	/// 3 = 12
	/// 6 = 123
	/// 10 = 1234 и т.д.
	/// а числа между ними имеют такой же вид, но у них отсутсвует одна цифра (в коде я нахожу индекс этой цифры)
	/// </summary>
	/// <param name="n"></param>
	void problem_7_solution(unsigned long long n)
	{
		assert(n >= 1);

		/*
		unsigned int k = int((-1 + sqrt(1 + 8 * n)) / 2);



		int* a = new int[3] {0};
		//int a[3] = { 0 };
		a[k-1] = 2;
		unsigned int index = k-1; // индекс первого элемента

		for (int i = 2; i < n; ++i)
		{
			for (int j = index; j <= k-1; ++j)
			{
				if (a[index] > 1)
				{
					a[index - 1] = 1; index--; break;
				}
				else if (j == k-1)
				{
					a[j] += 1;
				}
				else if (a[j] + 1 < a[j + 1])
				{
					a[j] += 1; break;
				}
			}
		}

		//std::cout << *a << std::endl;

		delete[] a;
		*/

		if (n <= 2)
		{
			std::cout << 1 << "\n" << n; return;
		}


		unsigned long k = long((-1 + sqrt(1 + 8 * n)) / 2);

		std::cout << k << std::endl;

		unsigned long long index = ((k + 1) * (k + 2)) / 2 - n - 1;


		for (unsigned long i = 0; i < k+1; ++i)
		{
			if (i == index)
				continue;
			std::cout << i + 1 << " ";
		}
	}




public:
	void problem_3_main()
	{
		unsigned long n;
		unsigned int m;

		std::cin >> n >> m;

		std::cout << "\n" << problem_3_solution(n, m);

		//for (unsigned int i = 2; i < 100; ++i)
		//{
		//	std::cout << i << ":" << std::endl;
		//	problem_3_solution(n, i);
		//	std::cout << std::endl;
		//}
	}

	struct segment
	{
		long start;
		long end;
	};
	void problem_5_main()
	{
		int n;
		std::cin >> n;

		segment* a = new segment[n];

		long x, y;
		for (int i = 0; i < n; i++)
		{
			std::cin >> x >> y;
			a[i].start = x;
			a[i].end = y;
		}
		
		//Temp new_temp;
		//new_temp.problem_5_output(a, n);


		//long* a = new long[2 * n];
		//long x, y;
		//for (int i = 0; i < 2*n; i += 2)
		//{
		//	std::cin >> x >> y;
		//	a[i] = x;
		//	a[i + 1] = y;
		//}

		//for (int i = 0; i < 2 * n; i++)
		//{
		//	std::cout << a[i] << " ";
		//}

		//problem_5_solution(a, n);
	}


	void problem_7_main()
	{
		unsigned long long n = 7;
		problem_7_solution(n);
	}

	void problem_6_main()
	{
		int n, w;
		std::cin >> n >> w;

		int** things = new int* [n];
		for (int i = 0; i < n; ++i)
		{
			things[i] = new int[2];
		}

		//delete &n;

		for (int i = 0; i < n; ++i)
		{
			std::cin >> things[i][0] >> things[i][1];
			//std::cout << things[i][0] << " " << things[i][1] << std::endl;
		}

		std::cout << "\ncost = " << problem_6_solution(things, n, w) << std::endl;

		delete[] things;
	}

};

/// <summary>
/// Временные функции, структуры и классы
/// </summary>
class Temp
{
public:


	//void problem_5_output(segment* a, int n)
	//{
	//	//for (int i = 0; i < n; ++i)
	//	//{
	//	//	std::cout << &a[i].start << &a[i].end << std::endl;
	//	//}
	//}
};


 /// <summary>
 /// Отрезок
 /// </summary>
// struct segment : public Temp
//{
//	long start;
//	long end;
//};




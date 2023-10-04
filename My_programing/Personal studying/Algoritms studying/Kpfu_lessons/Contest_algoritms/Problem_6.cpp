#include "Alg_Header.h"
#include <algorithm>

bool compare(int* arr1, int* arr2)
{
	if (double(arr1[0] / arr1[1]) > double(arr2[0] / arr2[1]))
		return true;
	else
		return false;
}


double problem_6_solution(int** things, int n, int w)
{
	std::sort(things, things + n, compare);

	//std::cout << sizeof(things) / sizeof(*things[0]) << std::endl;
	//std::cout << *(&things + 1) - things << std::endl;


	//std::cout << std::endl;
	//for (int i = 0; i < n; ++i)
	//{
	//	std::cout << things[i][0] << " " << things[i][1] << std::endl;
	//}

	double cost = 0;
	for (int i = 0; i < n; ++i)
	{
		if (things[i][1] < w)
		{
			cost += things[i][0];
			w -= things[i][1];
		}
		else if (things[i][1] == w)
			return cost + things[i][0];
		else
		{
			std::cout << "i = " << i << " " << double(things[i][0] / things[i][1]) << std::endl;
			return cost + double((things[i][0] * w) / things[i][1]);
		}
	}

	return 0;
}
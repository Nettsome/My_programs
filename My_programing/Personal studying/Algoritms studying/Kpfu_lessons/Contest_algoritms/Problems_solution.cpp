#include <iostream>


class Problems
{
private :
	void problem_7_solution(unsigned int n)
	{
		unsigned int k = 1;

		while (n > k)
		{
			k++;
		}

		std::cout << k << std::endl;
	}


public:
	void problem_7_main()
	{
		unsigned int n = 6;
		problem_7_solution(n);
	}
};
/*
 * Author: Matt Schwager
 * schwag09@gmail.com
 * Project Euler problem 12
 * Finding divisor count of triangular numbers
 */

#include <iostream>

int main()
{
	int divisorCount;
	long long number = 3, incrementBy = 3;
	while(divisorCount < 500)
	{
		divisorCount = 0;
		for(int i = 1; i*i <= number; ++i)
		{
			if(!(number % i))
			{
				divisorCount += 2;
			}
		}
		number += incrementBy;
		incrementBy++;
	}

	incrementBy--;
	number -= incrementBy;
	std::cout << number << std::endl;

	return 0;
}

/*
 * Author: Matt Schwager
 * schwag09@gmail.com
 * Project Euler problem 69
 * Maximal Eulers totient value under 1,000,000
 */

#include <iostream>

double totient(int);

int main()
{
	int result;
	double currentVal = 0.0, testVal = 0.0;

	for(int i = 2; i <= 1000000; ++i)
	{
		currentVal = i / totient(i);
		if(currentVal > testVal)
		{
			testVal = currentVal;
			result = i;
		}
	}
	std::cout << result << std::endl;
	return 0;
}

double totient(int number)
{
	long result = 1, pow = 1;
	for(int i = 2; number != 1; ++i)
	{
		pow = 1;
		while(!(number % i))
		{
			number /= i;
			pow *= i;
		}
		result *= pow - (pow / i);
	}
	return result;
}

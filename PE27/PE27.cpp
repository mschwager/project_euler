/*
 * Author: Matt Schwager
 * schwag09@gmail.com
 * Project Euler problem 27
 * Consecutive primes for quadratic formulae
 */

#include <iostream>

inline bool isPrime(long);

int main()
{
	long primeCount = 0, result = 0, n = 0;
	for(int a = -999; a < 1000; ++a)
	{
		for(int b = -999; b < 1000; ++b)
		{
			while(isPrime(n*n + a*n + b))
			{
				primeCount++;
				n++;
			}
			if(primeCount > result)
			{
				result = primeCount;
				std::cout << a << " " << b << std::endl;
			}
			primeCount = n = 0;
		}
	}
	std::cout << result << std::endl;
	return 0;
}

inline bool isPrime(long num)
{
	//If number is even and not 2
	if(!(num & 0x1) && (num != 2))
	{
		return false;
	}
	else if(num < 0)
	{
		return false;
	}
	else
	{
		for(int i = 3; i*i <= num; i += 2)
		{
			if(!(num % i))
			{
				return false;
			}
		}
	}
	return true;
}

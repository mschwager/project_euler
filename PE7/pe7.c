#include <stdlib.h>
#include <stdio.h>

/*
 * Mathematics behind this problem:
 *
 * We are finding primes similar to PE3. In this problem, however,
 * we don't have an upper bound so we continue to loop until we find the
 * 10001 iteration of a prime number. There is a slight optimization to be
 * made by incrementing by 6 each time instead of 2. This is because all 
 * primes are of the form:
 *
 * 6k +/- 1
 * (except for 2 and 3 of course)
 * https://en.wikipedia.org/wiki/Primality_test#Naive_methods 
 *
 * The isPrime() function is the same as the one used in PE3 and includes the
 * following optimizations:
 *
 * 1. Initially check if the number is even so we can only check odd numbers in
 * the loop.
 * 2. Only check up to sqrt(n) because after that there can be no numbers that
 * evenly divide the number in question.
 */

#define MAX 10001

int isPrime(long);

int main(void)
{
	long k = 0;
	int prime_count = 2;
	while(prime_count != MAX)
	{
		k += 6;
		if(isPrime(k-1))
		{
			prime_count++;
		}
		if(isPrime(k+1))
		{
			prime_count++;
		}
	}
	/* Add one to account for the final prime being of the form 6k + 1 */
	printf("%ld\n", k+1);

	return EXIT_SUCCESS;
}

int isPrime(long input)
{
	if(input % 2 == 0)
	{
		return 0;
	}
	int i;
	for(i = 3; i*i <= input; i += 2)
	{
		if(input % i == 0)
		{
			return 0;
		}
	}
	return 1;
}

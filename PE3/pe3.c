#include <stdio.h>
#include <stdlib.h>

/*
 * Mathematics behind this problem:
 *
 * A prime number is a number that is divisible only by itself and 1, the first
 * few are 3, 5, 7, 11, 13, 17... 
 * 
 * A factor is something that evenly divides a number. This means we can again
 * use the modulus operator because if a number evenly divides another number
 * that means the second number mod the first will equal 0.
 *
 * We simply need to find the largest number under NUM that is both prime
 * and a factor of NUM.
 */

#define NUM 600851475143

int isPrime(long);

int main()
{
	long i, result;

	/* There are no even primes (Can start at 3 and increment by 2).
	** Also only need to check up to sqrt(NUM) because after that there can
	** be no evenly dividable numbers to NUM */
	for(i = 3; i*i < NUM; i += 2)
	{
		if(NUM % i == 0 && isPrime(i))
		{
			result = i;
		}
	}
	printf("%ld\n", result);
	return EXIT_SUCCESS;
}

int isPrime(long input)
{
	if(input % 2 == 0)
	{
		return 0;
	}
	long i;
	
	/* Only need to check up to sqrt(INPUT), after that there can
	** be no evenly dividable numbers to NUM */
	for(i = 3; i*i < input; i += 2)
	{
		if(input % i == 0)
		{
			return 0;
		}
	}
	return 1;
}

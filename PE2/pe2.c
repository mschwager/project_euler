#include <stdio.h>
#include <stdlib.h>

/*
 * Mathematics behind this problem:
 *
 * In this problem we again use the modulus operator to check if a number
 * is even (evenly divisible by 2). We are summing the Fibonacci sequence
 * (https://en.wikipedia.org/wiki/Fibonacci_sequence) under 4 million. The
 * Fibonacci sequence takes the form:
 *
 * F_0 = 0
 * F_1 = 1
 * F_n = F_n-1 + F_n-2
 *
 * This can be done simply by keeping the latest two Fibonacci terms and adding
 * them to the running total if they're even.
 */

#define MAX 4000000

int main()
{
	int first = 0, second = 1, result = 0, temp;
	while(second < MAX)
	{
		if(second % 2 == 0)
		{
			result += second;
		}
		temp = first;
		first = second;
		second = temp + first;
	}
	printf("%d\n", result);
	return EXIT_SUCCESS;
}


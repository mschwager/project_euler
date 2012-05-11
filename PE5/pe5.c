#include <stdio.h>
#include <stdlib.h>

/*
 * Mathematics behind this problem:
 *
 * This is another simple iteration. We continue to iterate until we find a
 * number that is divisible by all 1-20 (brute force solution).
 *
 * There are a number of optimizations possible:
 * 1. Unroll (or unwind) the loop (https://en.wikipedia.org/wiki/loop_unwinding)
 * 2. Only check 11-20 because all numbers 1-10 are evenly divisible if all
 * numbers 11-20 are. For example, if the number is divisible by 16 it is
 * also divisible by 2, 4, and 8. The same can be said for 9 and 18, ect...
 * 3. Start at 20 in the condition instead of 11. This assumes that larger
 * numbers have less of a chance of being evenly divisible. Under this
 * assumption if the number isn't divisible by 20 then the condition cannot
 * be true so it doesn't have to check the rest of the possible conditions.
 * We want the numbers with least likely even divisibility to be checked first
 * so we can return possible with as little checks as possible.
 *
 * There is also a solution that can be done by hand dealing with prime
 * factorizations.
 */

int divisible120(long);

int main()
{
	long i = 1;
	while(!divisible120(i++))
	{
	}
	printf("%ld\n", i);
	return EXIT_SUCCESS;
}

int divisible120(long input)
{
	// Loop unrolling
	if(input % 20 == 0 &&
	   input % 19 == 0 &&
	   input % 18 == 0 &&
	   input % 17 == 0 &&
	   input % 16 == 0 &&
	   input % 15 == 0 &&
	   input % 14 == 0 &&
	   input % 13 == 0 &&
	   input % 12 == 0 &&
	   input % 11 == 0)
	{
		return 1;
	}
	return 0;
}

#include <stdio.h>
#include <stdlib.h>

/*
 * Mathematics behind this problem:
 *
 * As stated by the problem a palindrome is a number that is lexographically
 * equivelent to its reverse. So, 8558 and 87678 are both palindromes. This
 * problem is fairly straight forward, the problem space is small enough that
 * we can simply iterate over the whole thing (the product of 2 3-digit 
 * numbers). Checking each number in the range (100, 1000] multiplied by every
 * other number in that range, checking the product for "palindromeness",
 * and finally checking if it's the largest we've seen so far is sufficient.
 *
 * Checking "palindromeness" is more easily thought of as a lexographical check
 * but here it is done using integers instead of strings (much faster than
 * converting). We are also able to implement a few optimizations.
 */

int isPalindrome(int);

int main()
{
	int i, j, result;
	for(i = 100; i < 1000; ++i)
	{
		// This loop can be initialized to the value of the outside loop
		// because we've already tested all numbers below the outside value
		for(j = i; j < 1000; ++j)
		{
			if(isPalindrome(i*j) && i*j > result)
			{
				result = i*j;
			}
		}
	}
	printf("%d\n", result);
	return EXIT_SUCCESS;
}

int isPalindrome(int input)
{
	// This builds the reverse of the input using modulus and integer division
	int digit, comparator = input, rev = 0;
	while(comparator)
	{
		digit = comparator % 10;
		rev = rev * 10 + digit;
		comparator /= 10;
	}
	return (input == rev ? 1 : 0);
}

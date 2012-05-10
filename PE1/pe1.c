#include <stdio.h>
#include <stdlib.h>

/*
 * Mathematics behind this problem:
 *
 * One of the easiest ways to find if a number x is divisible by another number
 * y is to use the modulus operator. x mod y will equal 0 if x is evenly
 * divisible by y, so we simple iterate over the selected range [0, 1000)
 * checking if our current number mod 3 or 5 equals zero and add this to the
 * running sum if it does.
 */

int main()
{
	int i, sum = 0;
	for(i = 0; i < 1000; ++i)
	{
		if(i % 3 == 0 || i % 5 == 0)
		{
			sum += i;
		}
	}
	printf("%d\n", sum);
	return EXIT_SUCCESS;
}

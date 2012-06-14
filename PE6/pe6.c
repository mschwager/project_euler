#include <stdio.h>
#include <stdlib.h>

#define MAX 100

/*
 * Mathematics behind this problem:
 * 
 * To find the difference of sums we simply have to iterate over the range
 * [1,100] keeping the two running sums as advised. After this we find the
 * difference and arrive at our answer.
 */

int main(void)
{
	long sum1 = 0;
	long sum2 = 0;

	int i;
	for(i = 1; i <= MAX; ++i)
	{
		sum1 += (i*i);
		sum2 += i;
	}
	sum2 *= sum2;
	printf("%ld\n", sum2-sum1);

	return EXIT_SUCCESS;
}

#include <stdio.h>
#include <stdlib.h>

/*
 * Mathematics behind this problem:
 *
 * First the number is copied into the source in string format. From here we
 * simply iterate through each index in the string checking if it multiplied
 * by the next four numbers is greater than the current best.
 *
 * There are a couple optimizations that are made:
 *
 * 1. Each indice is converted to it's ASCII form and then '0' (48) is
 * subtracted. This is much faster then using a C library function to convert
 * the char/string to an integer.
 * 2. The loop is unrolled to include all the multiplication necessary for the
 * current product, this is faster than only having one multiplication per
 * iteration of the loop.
 */

char NUM[] = "73167176531330624919225119674426574742355349194934"
			"96983520312774506326239578318016984801869478851843"
			"85861560789112949495459501737958331952853208805511"
			"12540698747158523863050715693290963295227443043557"
			"66896648950445244523161731856403098711121722383113"
			"62229893423380308135336276614282806444486645238749"
			"30358907296290491560440772390713810515859307960866"
			"70172427121883998797908792274921901699720888093776"
			"65727333001053367881220235421809751254540594752243"
			"52584907711670556013604839586446706324415722155397"
			"53697817977846174064955149290862569321978468622482"
			"83972241375657056057490261407972968652414535100474"
			"82166370484403199890008895243450658541227588666881"
			"16427171479924442928230863465674813919123162824586"
			"17866458359124566529476545682848912883142607690042"
			"24219022671055626321111109370544217506941658960408"
			"07198403850962455444362981230987879927244284909188"
			"84580156166097919133875499200524063689912560717606"
			"05886116467109405077541002256983155200055935729725"
			"71636269561882670428252483600823257530420752963450";

int NUM_SIZE = 50*20;

int main(void)
{
	int i, cur_sum = 1, result = 1;
	for(i = 0; i < NUM_SIZE - 4; ++i)
	{
		// Convert from ASCII, '0' = 48
		cur_sum *= ((int) NUM[i]) - 48;
		cur_sum *= ((int) NUM[i+1]) - 48;
		cur_sum *= ((int) NUM[i+2]) - 48;
		cur_sum *= ((int) NUM[i+3]) - 48;
		cur_sum *= ((int) NUM[i+4]) - 48;
		if(cur_sum > result)
		{
			result = cur_sum;
		}
		cur_sum = 1;
	}

	printf("%d\n", result);
	return EXIT_SUCCESS;
}

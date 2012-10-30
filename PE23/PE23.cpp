/*
 * Author: Matt Schwager
 * schwag09@gmail.com
 * Project Euler problem 23
 * Abundant numbers
 */

#include <vector>
#include <iostream>

const int MAX = 28124;

int main()
{
	long				divisorSum = 0, result = 0;
	std::vector<long>	abundantList;
	std::vector<bool>	abundantSumList(MAX, false);
	
	//Generate list of abundant numbers below MAX
	for(int i = 1; i < MAX; ++i, divisorSum = 1)
	{
		for(int j = 2; j * j <= i; ++j)
		{
			//If j is a proper divisor of i
			if(!(i % j))
			{
				//Accounts for the sqrt(i) being a proper divisor twice
				divisorSum += (j * j == i) ? j : (j + (i / j));
			}
			if(divisorSum > i)
			{
				abundantList.push_back(i);
				break;
			}
		}
	}

	//Generate list of numbers that are the sum of two abundant numbers
	int endLoop = abundantList.size();
	for(int i = 0; i < endLoop; ++i)
	{
		for(int j = 0; abundantList[i] + abundantList[j] < MAX; ++j)
		{
			abundantSumList[abundantList[i]+abundantList[j]] = true;
		}
	}

	//Sum list of numbers that aren't the sum of two abundant numbers
	for(int i = 0; i < MAX; ++i)
	{
		result += !abundantSumList[i] ? i : 0;
	}

	std::cout << result << std::endl;
	return 0;
}

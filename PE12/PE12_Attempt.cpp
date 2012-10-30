/*
 * Author: Matt Schwager
 * schwag09@gmail.com
 * Project Euler problem 12
 * Finding divisor count of triangular numbers
 */

#include <iostream>
#include <vector>

struct factorCount
{
	int factor;
	int count;
};

int main()
{
	factorCount temp;
	std::vector<int> primeList;
	std::vector<factorCount> factorList;
	std::vector<bool> numList;
	long index, divCount, step, MAX_NUM = 3, incrementBy = 3, tempMax;

	while(divCount < 300)
	{
		primeList.clear();
		factorList.clear();
		numList.clear();
		numList.resize(MAX_NUM + 1, true);
		divCount = 1;
		index = 1;
		step = 0;

		//Sieve
		while((index * index) <= MAX_NUM)
		{
			index++;
			if(!numList[index])
			{
				continue;
			}
			step = (index > 2) ? 2 * index : index;
			for(unsigned int i = index * index; i <= MAX_NUM; i += step)
			{
				numList[i] = false;
			}
		}

		//Check primes for divisibility
		tempMax = MAX_NUM;
		while(tempMax != 1)
		{
			for(unsigned int i = 2; i <= tempMax; ++i)
			{
				if(numList[i] && (tempMax % i == 0))
				{
					tempMax /= i;
					primeList.push_back(i);
					break;
				}
			}
		}

		//Determine count of each prime factor
		for(int i = 0, primeCount = 0; i < primeList.size(); i += primeCount, primeCount = 0)
		{
			for(int j = i; primeList[i] == primeList[j]; ++j)
			{
				primeCount++;	
			}
			temp.factor = primeList[i];
			temp.count = primeCount;
			factorList.push_back(temp);
		}

		//Find divisor count
		for(int i = 0; i < factorList.size(); ++i)
		{
			divCount *= (factorList[i].count + 1);
		}

		MAX_NUM += incrementBy;
		incrementBy++;
	}
	incrementBy--;
	MAX_NUM -= incrementBy;
	std::cout << MAX_NUM << std::endl;
	return 0;
}

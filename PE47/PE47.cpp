/*
 * Author: Matt Schwager
 * schwag09@gmail.com
 * Project Euler problem 47
 * First four consectutive numbers with distinct prime factorizations
 */

#include <iostream>
#include <boost/dynamic_bitset.hpp>
#include <vector>

int main()
{
	int MAX_NUM = 1000000, temp = 0;
	boost::dynamic_bitset<> numList(MAX_NUM + 1);
	std::vector<int> primeList;
	numList.flip();
	long index = 1, step = 0;

	//Sieve
	while((index * index) <= MAX_NUM)
	{
		index++;
		if(!numList[index])
		{
			continue;
		}
		step = (index > 2) ? 2 * index : index;
		for(unsigned long i = index * index; i <= MAX_NUM; i += step)
		{
			numList[i] = 0;
		}
	}

	for(int i = 0; ; i += 4)
	{
		temp = i;
		for(int j = 3; j != i; --j)
		{
			while(temp != 1)
			{
				for(int i = 2; i <= MAX_NUM; ++i)
				{
					if(numList[i] && (temp % i == 0))
					{
						temp /= i;
						primeList.push_back(i);
					}
				}
			}
		}
	}

	return 0;
}

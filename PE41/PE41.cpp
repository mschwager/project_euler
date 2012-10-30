/*
 * Author: Matt Schwager
 * schwag09@gmail.com
 * Project Euler problem 41
 * Computing n-digit pandigital primes
 */

#include <iostream>
#include <string>
#include <boost/lexical_cast.hpp>
#include <boost/dynamic_bitset.hpp>

bool isPandigital(long long);

int main(int argc, char **argv)
{
	const long MAX_NUM = boost::lexical_cast<long>(argv[1]);

	//Error checking
	if(argc > 2)
	{
		std::cerr << " >> ERROR: Too many arguments" << std::endl;
		return 1;
	}
	if(MAX_NUM < 0)
	{
		std::cerr << " >> ERROR: Argument must be positive or zero" << std::endl;
		return 1;
	}

	boost::dynamic_bitset<> numList(MAX_NUM + 1);
	numList.flip();
	long index = 1, step = 0;

	//Sieve
	while((index * index) <= MAX_NUM)
	{
		index++;
		if(numList[index] == 0)
		{
			continue;
		}
		step = (index > 2) ? 2 * index : index;
		for(long i = index * index; i <= MAX_NUM; i += step)
		{
			numList[i] = 0;
		}
	}

	//Output results
	for(long i = 2; i <= MAX_NUM; ++i)
	{
		if(numList[i] && isPandigital(i))
		{
			std::cout << i << '\n';
		}
	}
	return 0;
}

bool isPandigital(long long number)
{
	std::string num = boost::lexical_cast<std::string>(number);
	int MAX = num.size() - 1;
	bool *indices = new bool[MAX];
	for(int i = 0; i < MAX; ++i)
	{
		indices = false;
	}
	for(int i = 0; i < MAX; ++i)
	{
		indices[boost::lexical_cast<int>(num[i]) - 1] = true;
	}
	for(int i = 0; i < MAX; ++i)
	{
		if(!indices[i])
		{
			delete [] indices;
			return false;
		}
	}
	delete [] indices;
	return true;
}

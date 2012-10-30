/*
 * Author: Matt Schwager
 * Project Euler Problem 92
 * Number chains
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include <boost/lexical_cast.hpp>

const unsigned long MAX = 10000000;

bool isStarting(unsigned long);

int main()
{
	unsigned long result = 0;
	for(unsigned long i = 0; i < MAX; ++i)
	{
		if(isStarting(i))
		{
			result++;
		}
	}
	std::cout << result << std::endl;
	return EXIT_SUCCESS;
}

bool isStarting(unsigned long num)
{
	unsigned long sum = 0;
	unsigned long temp = 0;
	std::string number = boost::lexical_cast<std::string>(num);
	do
	{
		for(int i = 0; i < number.size(); ++i)
		{
			temp = (boost::lexical_cast<int>(number[i]) *
				    boost::lexical_cast<int>(number[i]));
			sum += temp;
		}
		if(sum == 89)
		{
			return true;
		}
		if(sum == 1)
		{
			return false;
		}
		number = boost::lexical_cast<std::string>(sum);
		sum = 0;
	} while(true);
}

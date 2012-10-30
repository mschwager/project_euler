/*
 * Author: Matt Schwager
 * schwag09@gmail.com
 * Project Euler problem 28
 * Spiral diagonal sum
 */

#include <cstdlib>
#include <iostream>
#include <boost/lexical_cast.hpp>

int main(int argc, char **argv)
{
	const long MAX = boost::lexical_cast<long>(argv[1]);
	long result = 1, i = 3, j = 1;
	while(i <= MAX)
	{
		result += 4*i*i - 12*j;
		//result += i*i;
		//result += (i*i - j*2);
		//result += (i*i - j*4);
		//result += (i*i - j*6);
		i += 2;
		j++;
	}

	std::cout << result << std::endl;
	
	return EXIT_SUCCESS;
}

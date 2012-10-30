#include <iostream>
#include <cmath>
#include <boost/lexical_cast.hpp>

int main(int argc, char **argv)
{
	int num = boost::lexical_cast<int>(argv[1]);	
	if(fmod((sqrt(24 * num + 1) + 1) / 6, 1.0) == 0)
	{
		std::cout << num << " is pentagonal\n";
	}
	else
	{
		std::cout << num << " isn't pentagonal\n";
	}
	return 0;
}

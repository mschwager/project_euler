#include <boost/lexical_cast.hpp>
#include <iostream>
#include <string>

inline bool isPandigital(long long int);

int main(int argc, char **argv)
{
	if(isPandigital(boost::lexical_cast<long long int>(argv[1])))
	{
		std::cout << "Is pandigital" << std::endl;
	}
	else
	{
		std::cout << "Isn't pandigital" << std::endl;
	}

	return 0;
}

inline bool isPandigital(long long int number)
{
	std::string num = boost::lexical_cast<std::string>(number);
	int MAX = num.size();
	bool *indices = new bool[MAX];
	for(int i = 0; i < MAX; ++i)
	{
		indices[i] = false;
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

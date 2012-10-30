/*
 * Author: Matt Schwager
 * schwag09@gmail.com
 */

#include <iostream>
#include <string>
#include <boost/lexical_cast.hpp>

bool sameDigits(std::string, std::string);

int main(int argc, char **argv)
{
	std::string string1 = argv[1];
	std::string string2 = argv[2];
	if(sameDigits(string1, string2))
	{
		std::cout << string1 << " and " << string2 << " are anagrams\n";
	}
	else
	{
		std::cout << string1 << " and " << string2 << " aren't anagrams\n";
	}

	return 0;
}

bool sameDigits(std::string string1, std::string string2)
{
	if(string1.size() != string2.size())
	{
		return false;
	}
	int digits[10];

	//Initialize digits
	for(int i = 0; i < 10; ++i)
	{
		digits[i] = 0;
	}

	int endLoop = string1.size();

	//Increase index value of each digit in string1
	for(int i = 0; i < endLoop; ++i)
	{
		digits[static_cast<int>(string1[i]) - 48]++;
	}

	//Decrease index value of each digit in string1
	for(int i = 0; i < endLoop; ++i)
	{
		digits[static_cast<int>(string2[i]) - 48]--;
	}

	//Each index value should be 0 if the strings are anagrams
	for(int i = 0; i < 10; ++i)
	{
		if(digits[i] != 0)
		{
			return false;
		}
	}
	return true;
}

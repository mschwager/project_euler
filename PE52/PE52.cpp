/*
 * Author: Matt Schwager
 * schwag09@gmail.com
 * Project Euler problem 52
 * Multiples with same digits (aka anagrams)
 */

#include <iostream>
#include <string>
#include <cstring>
#include <boost/lexical_cast.hpp>

const int DIGIT_COUNT = 10;

bool sameDigits(std::string, std::string);

int main()
{
	int curNumber = 1;
	std::string curString = boost::lexical_cast<std::string>(curNumber);

	while(!(sameDigits(curString, boost::lexical_cast<std::string>(curNumber * 6)) &&
		    sameDigits(curString, boost::lexical_cast<std::string>(curNumber * 5)) &&
		    sameDigits(curString, boost::lexical_cast<std::string>(curNumber * 4)) &&
		    sameDigits(curString, boost::lexical_cast<std::string>(curNumber * 3)) &&
		    sameDigits(curString, boost::lexical_cast<std::string>(curNumber * 2))))
	{
		curNumber++;
		curString = boost::lexical_cast<std::string>(curNumber);
	}

	std::cout << curNumber << std::endl;
	
	return 0;
}

bool sameDigits(std::string string1, std::string string2)
{
	if(string1.size() != string2.size())
	{
		return false;
	}
	int digits[DIGIT_COUNT];
	int endLoop = string1.size();

	//Initialize digits[]
	memset(digits, 0, sizeof(digits));

	//Increase index value of each digit in string1
	for(int i = 0; i < endLoop; ++i)
	{
		digits[static_cast<int>(string1[i]) - 48]++;
	}

	//Decrease index value of each digit in string2
	for(int i = 0; i < endLoop; ++i)
	{
		digits[static_cast<int>(string2[i]) - 48]--;
	}

	//Each index value should be 0 if the strings are anagrams
	for(int i = 0; i < DIGIT_COUNT; ++i)
	{
		if(digits[i] != 0)
		{
			return false;
		}
	}
	return true;
}

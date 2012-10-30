#include <iostream>
#include <cstdlib>

void appendInt(long &, long);
bool isPandigital9(long);

int main()
{
	long curValue = 0;
	long result = 0;
	for(int i = 1; i < 10000; ++i)
	{
		curValue = 0;
		for(int j = 1; j < 20; ++j)
		{
			appendInt(curValue, i*j);
			if(isPandigital9(curValue))
			{
				result = curValue;
			}
		}
	}
	std::cout << result << std::endl;

	return EXIT_SUCCESS;
}

bool isPandigital9(long input)
{
	if(input > 987654321 || input < 123456789)
	{
		return false;
	}

	int numList[9] = {};

	while(input)
	{
		numList[(input % 10) - 1]++;
		input /= 10;	
	}
	for(int i = 0; i < 9; ++i)
	{
		if(numList[i] != 1)
		{
			return false;
		}
	}
	return true;
}

void appendInt(long &input,long appendValue)
{
	int i;
	for(i = 10; appendValue / i != 0; i *= 10) {}
	input = (input * i) + appendValue;
}

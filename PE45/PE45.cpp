#include <iostream>
#include <cmath>

inline bool isTriangular(long);
inline bool isPentagonal(long);

int main()
{
	long n = 144, hexNum = 0;
	do 
	{
		hexNum = n * (2 * n - 1);
		if(isTriangular(hexNum) && isPentagonal(hexNum))
		{
			std::cout << hexNum << std::endl;
			break;
		}
		n++;
	} while(true);
	return 0;
}

//A number is triangular if:
//sqrt(8 * number + 1)
//is a natural number
inline bool isTriangular(long num)
{
	return fmod(sqrt(8.0 * num + 1.0), 1.0) == 0.0;
}

//A number is pentagonal if:
//(sqrt(24 * number + 1) + 1) / 6
//is a natural number
inline bool isPentagonal(long num)
{
	return fmod((sqrt(24.0 * num + 1.0) + 1.0) / 6.0, 1.0) == 0.0;
}

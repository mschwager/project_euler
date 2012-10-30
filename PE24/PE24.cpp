/*
 * Author: Matt Schwager
 * schwag09@gmail.com
 * Project Euler problem 24
 * Finding lexigraphical permutations
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include <boost/math/special_functions/factorials.hpp>

inline int largestKIndex(std::string);
inline int largestLIndex(std::string, int);
inline void swap(std::string &, int, int);
void reverse(std::string &, int, int);

int main(int argc, char **argv)
{
	std::string value = argv[1];
	long index = 0, k = 0, l = 0, n = value.size();

	//Creates a vector of size n! to accomodate all permutations of the input value
	long size = static_cast<int>(boost::math::factorial<double>(value.size()));
	std::string *permutationList = new std::string[size];

	//First value is assumed to be the first possible lexographical permutation
	permutationList[index] = value;
	index++;

	while(true)
	{
		k = largestKIndex(value);
		//largestKIndex() returns -1 when it's the last permutation
		if(k == -1)
		{
			break;
		}
		l = largestLIndex(value, k);
		swap(value, k, l);
		reverse(value, k + 1, n - 1);

		permutationList[index] = value;
		index++;	
	}

	//Output results
	for(int i = 0; i < size; ++i)
	{
		std::cout << permutationList[i] << std::endl;
	}

	delete [] permutationList;
	return EXIT_SUCCESS;
}

//Find the largest index k such that a[k] < a[k + 1].
//If no such index exists, the permutation is the last permutation.
//Return -1 if it's the last permutation.
inline int largestKIndex(std::string value)
{
	bool found = false;
	int result = 0, max = value.size(), index = 0;
	while(index < max - 1)
	{
		if(value[index] < value[index + 1])
		{
			found = true;
			result = index;
		}
		index++;
	}
	return (found == true ? result : -1);
}

//Find the largest index l such that a[k] < a[l].
//Since k + 1 is such an index, l is well defined and satisfies k < l.
inline int largestLIndex(std::string value, int k)
{
	int result = 0, max = value.size(), index = 0;
	while(index < max)
	{
		if(value[k] < value[index])
		{
			result = index;
		}
		index++;
	}
	return result;
}

//Swaps values at indices k and l
inline void swap(std::string &value, int k, int l)
{
	char temp = value[k];
	value[k] = value[l];
	value[l] = temp;
}

//Reverse the sequence from a[k + 1] up to and including the final element a[n].
void reverse(std::string &value, int k, int n)
{
	if(k >= n)
	{
		return;
	}
	swap(value, k, n);
	reverse(value, k + 1, n - 1);
}



#include <vector>
#include <iostream>

struct factorCount
{
	int factor;
	int count ;
};

int main()
{
	int divCount = 1;
	factorCount temp;
	std::vector<factorCount> factorList;
	std::vector<int> primeCount;
	primeCount.push_back(2);
	primeCount.push_back(2);
	primeCount.push_back(3);
	primeCount.push_back(5);

	//Find out how many times each prime factor is used
	for(int i = 0, numCount = 0; i < primeCount.size(); i += numCount, numCount = 0)
	{
		for(int j = i; primeCount[j] == primeCount[i]; ++j)
		{
			numCount++;
		}
		temp.factor = primeCount[i];
		temp.count = numCount;
		factorList.push_back(temp);
	}
	
	//Find divisor count
	for(int i = 0; i < factorList.size(); ++i)
	{
		divCount *= (factorList[i].count + 1);
	}

	//Output results
	/*
	for(int i = 0; i < factorList.size(); ++i)
	{
		std::cout << factorList[i].factor << "^" << factorList[i].count << std::endl;
	}
	*/

	std::cout << divCount << std::endl;

	return 0;
}

/*
 * Author: Matt Schwager
 * schwag09@gmail.com
 * Project Euler problem 44
 * Pentagonal sums and differences
 */

#include <vector>
#include <iostream>
#include <cmath>

const long MAX = 10000000;

int main ()
{
	long				curNum = 1;
	std::vector<long>	pentList;
	std::vector<bool>	isPent(MAX, false);

	for(int i = 1; curNum < MAX ; i += 3, curNum += i)
	{
		//Create list of pentagonal numbers
		pentList.push_back(curNum);

		//Create look up table of pentagonal numbers
		isPent[curNum] = true;
	}

	int endLoop = pentList.size();
	for(int i = 0; i < endLoop; ++i)
	{
		for(int j = i; j < endLoop; ++j)
		{
			//This condition prevents segfaulting even though it shouldn't be needed
			//Reason: Unknown
			if(pentList[i] + pentList[j] > MAX ||
			   pentList[j] - pentList[i] < 0)
			{
				break;
			}
			else if(isPent[pentList[i] + pentList[j]] &&
			   		isPent[pentList[j] - pentList[i]])
			{
				std::cout << pentList[i] << " " << pentList[j] << " " << pentList[j] - pentList[i] << std::endl;
			}
			else {}
		}
	}

	return 0;
}

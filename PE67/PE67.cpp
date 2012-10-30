/*
 * Author: Matt Schwager
 * schwag09@gmail.com
 * Project Euler problem 67
 * Maximal traveling triangular sum
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <boost/lexical_cast.hpp>
#include <boost/foreach.hpp>
#include <boost/tokenizer.hpp>

int main()
{
	int					row = 0;
	std::string			curNum;
	std::vector<int>	numList;

	//Initialize delimiter as a space
	boost::char_separator<char> del(" ");
	while(getline(std::cin, curNum))
	{
		row++;

		//Tokenize current line
		boost::tokenizer<boost::char_separator<char> > tokens(curNum, del);

		//Populate vector
		BOOST_FOREACH(std::string curToken, tokens)
		{
			numList.push_back(atoi(curToken.c_str()));
		}
	}
	
	//Work from bottom to top adding max(child1, child2) to parent nodes
	int curInt = numList.size() - 1;
	for(int i = numList.size() - 1; i >= 1; --i)
	{
		if(i == (curInt - row + 1))
		{
			curInt -= row;
			row--;
			continue;
		}
		numList[i - row] += std::max(numList[i], numList[i - 1]);
	}

	std::cout << numList[0] << std::endl;

	return 0;
}

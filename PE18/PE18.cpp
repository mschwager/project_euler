/*
 * Author: Matt Schwager
 * schwag09@gmail.com
 * Project Euler problem 18
 * Maximal sum of a triangle
 */

#include <vector>
#include <iostream>
#include <string>
#include <cstdlib>
#include <boost/lexical_cast.hpp>
#include <boost/tokenizer.hpp>
#include <boost/foreach.hpp>

//Globals
int ROW_COUNT = 1;
int CUR_BEST = 0;
std::vector<int> numList;

//Data Structures
struct node
{
	int value;
	node *left;
	node *right;
};

//Prototypes
void maximumRoute(node *, int, int);
node* populate(int, int);
void destroy(node *);

int main()
{
	std::string			curNum;

	//Initialize delimiter as a space
	boost::char_separator<char> del(" ");
	while(getline(std::cin, curNum))
	{
		ROW_COUNT++;

		//Tokenize current line
		boost::tokenizer<boost::char_separator<char> > tokens(curNum, del);

		//Populate vector
		BOOST_FOREACH(std::string curToken, tokens)
		{
			numList.push_back(boost:lexical_cast<int>(curToken));
		}
	}

	node *root = populate(1, 0);
	maximumRoute(root, 1, 0);
	std::cout << CUR_BEST << std::endl;

	destroy(root);
	root = NULL;
	return EXIT_SUCCESS;
}

node* populate(int row, int curPosition)
{
	if(row > ROW_COUNT)
	{
		return NULL;
	}
	node *root = new node;
	root->value = numList[curPosition];
	root->left = populate(row + 1, row + curPosition);
	root->right = populate(row + 1, row + curPosition + 1);
	return root;
}

void destroy(node *root)
{
	if(root != NULL)
	{
		destroy(root->left);
		destroy(root->right);
		delete root;
	}
}

void maximumRoute(node *root, int row, int curVal)
{
	if(root == NULL)
	{
		return;
	}
	maximumRoute(root->left, row + 1, curVal + root->value);
	maximumRoute(root->right, row + 1, curVal + root->value);
	if(curVal > CUR_BEST)
	{
		CUR_BEST = curVal;
	}
}

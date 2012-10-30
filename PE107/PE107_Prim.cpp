/* 
 * Author: Matt Schwager
 * schwag09@gmail.com
 * Project Euler problem 107
 * Optimising a network
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <boost/lexical_cast.hpp>
#include <boost/tokenizer.hpp>
#include <boost/foreach.hpp>


struct vertex
{
	int		x;
	int 	y;
	int 	weight;
	bool	beenPushed; 
};

struct min_queue
{
	bool operator ()(const vertex &l, const vertex &r)
	{
		return l.weight > r.weight;
	}
};

int main(int argc, char **argv)
{
	const int		NODE_COUNT = boost::lexical_cast<int>(argv[1]);
	long			totalWeight = 0;
	long			spanningWeight = 0;
	long			tempSwap;
	//edge # = node # - 1, -1 again for root node being
	//chosen before entering loop
	long			edgeCount = NODE_COUNT - 2;
	std::string		curNum;

	bool			beenTo[NODE_COUNT];
	for(int i = 0; i < NODE_COUNT; ++i)
	{
		beenTo[i] = false;
	}

	//Min-priority queue
	std::priority_queue<vertex, std::vector<vertex>, min_queue> queue;

	//Create vector grid
	std::vector<std::vector<vertex> > graph;
	graph.resize(NODE_COUNT);
	for(int i = 0; i < NODE_COUNT; ++i)
	{
		graph[i].resize(NODE_COUNT);
	}

	//Populate grid from std input
	for(int i = 0, j = 0; getline(std::cin, curNum, '\n'); ++i, j = 0)
	{
		//Set comma as token delimiter
		boost::char_separator<char> del(",");

		//Tokenize current line based on delimited
		boost::tokenizer<boost::char_separator<char> > tokens(curNum, del);

		//Populate grid with tokens
		//Treat "-" as not connected, therefore INT_MAX
		BOOST_FOREACH(std::string curToken, tokens)
		{
			//graph[i][j].weight = (curToken == "-") ? INT_MAX : boost::lexical_cast<int>(curToken);
			//totalWeight += (curToken == "-") ? 0 : boost::lexical_cast<int>(curToken);
			graph[i][j].weight = (curToken == "-") ? INT_MAX : atoi(curToken.c_str());
			totalWeight += (curToken == "-") ? 0 : atoi(curToken.c_str());
			graph[i][j].x = i;
			graph[i][j].y = j;
			graph[i][j].beenPushed = false;
			++j;
		}
	}

	//Minimal Spanning Tree (MST) algorithm
	vertex root;
	//Use arbitrary node as the first root node
	for(int i = 1; i < NODE_COUNT; ++i)
	{
		if(graph[i][0].weight != INT_MAX)
		{
			root = graph[i][0];
			break;
		}
	}
	graph[root.x][root.y].beenPushed = true;
	spanningWeight += graph[root.x][root.y].weight;
	beenTo[root.x] = true;
	//# of Edges in MST = # of Vertices - 1
	while(edgeCount > 0)
	{
		//Invert x and y values
		tempSwap = root.x;
		root.x = root.y;
		root.y = tempSwap;

		//Push vertices connected to current root
		for(int i = root.x + 1; i < NODE_COUNT; ++i)
		{
			if((graph[i][root.y].weight != INT_MAX) && 
			   (!graph[i][root.y].beenPushed) 		&&
			   (!graph[root.y][i].beenPushed))
			{
				//std::cout << "Pushing... " << graph[i][root.y].weight << '\n';
				graph[i][root.y].beenPushed = true;
				queue.push(graph[i][root.y]);
			}
		}
		root = queue.top();
		while(beenTo[root.x])
		{
			queue.pop();
			root = queue.top();
		}
		std::cout << "Popping... " << graph[root.x][root.y].weight << '\n';
		spanningWeight += graph[root.x][root.y].weight;

		beenTo[root.x] = true;
		queue.pop();
		edgeCount--;
	}
	std::cout << "Total weight: " << (totalWeight / 2) << std::endl;
	std::cout << "Spanning weight: " << spanningWeight << std::endl;
	std::cout << "Difference: " << (totalWeight / 2) - spanningWeight << std::endl;

	return EXIT_SUCCESS;
}

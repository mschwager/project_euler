/* 
 * Author: Matt Schwager
 * schwag09@gmail.com
 * Project Euler problem 107
 * Optimising a network using Minimal Spanning Trees (MST)
 */

#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <boost/lexical_cast.hpp>
#include <boost/tokenizer.hpp>
#include <boost/foreach.hpp>

struct edge
{
	int weight;
	int toVertex;
	int fromVertex;
};

struct vertex
{
	int name;
	std::vector<edge> connectedTo;
};

struct min_queue
{
	bool operator()(const edge &l, const edge &r)
	{
		return l.weight >= r.weight;
	}
};

int main(int argc, char **argv)
{
	const int		NODE_COUNT = boost::lexical_cast<int>(argv[1]);
	long			totalWeight = 0;
	long			spanningWeight = 0;
	long			tempWeight;
	std::string		curNum;
	edge 			tempEdge;
	bool			*prevBeen = new bool[NODE_COUNT];
	int				*prevDistance = new int[NODE_COUNT];
	vertex			*graph = new vertex[NODE_COUNT];

	//Initialized beenVisited list
	for(int i = 0; i < NODE_COUNT; ++i)
	{
		prevDistance[i] = INT_MAX;
		prevBeen[i] = false;
	}

	//Min-priority queue
	std::priority_queue<edge, std::vector<edge>, min_queue> queue;

	//Populate grid from std input
	for(int i = 0, j = 0; getline(std::cin, curNum); ++i, j = 0)
	{
		//Set comma as token delimiter
		boost::char_separator<char> del(",");

		//Tokenize current line based on delimited
		boost::tokenizer<boost::char_separator<char> > tokens(curNum, del);

		//Populate graph with vertices and where they're connected
		BOOST_FOREACH(std::string curToken, tokens)
		{
			if(curToken == "-")
			{
				++j;
				continue;
			}
			std::cout << curToken << " with size " << curToken.size() << std::endl;
			tempWeight = lexical_cast<int>(curToken);
			tempEdge.weight = tempWeight;
			tempEdge.toVertex = j;
			tempEdge.fromVertex = i;
			graph[i].connectedTo.push_back(tempEdge);
			totalWeight += tempWeight;
			++j;
		}
	}

	//Output nodes
	/*
	std::cout << '\n';
	for(int i = 0; i < NODE_COUNT; ++i)
	{
		std::cout << "Node " << graph[i].connectedTo.front().fromVertex << " is connected to: \n";
		for(unsigned int j = 0; j < graph[i].connectedTo.size(); ++j)
		{
			std::cout << "\tnode " << graph[i].connectedTo[j].toVertex;
			std::cout << " with distance " << graph[i].connectedTo[j].weight << '\n';
		}
	}
	*/

	//Using Prim's MST Algorithm
	//Choose an arbitrary vertex to start
	vertex *root = &graph[0];
	prevDistance[0] = 0;
	std::cout << "\nStarting at node: 0\n";
	do
	{	
		//Push all nodes connected to current root into min-priority queue
		for(unsigned int j = 0; j < root->connectedTo.size(); ++j)
		{
			//Check if weight for the given node is less than the best weight
			//already for that node and if it's already been visited
			if(root->connectedTo[j].weight < prevDistance[root->connectedTo[j].toVertex])
			{
				queue.push(root->connectedTo[j]);
				//std::cout << "Pushing node: " << root->connectedTo[j].toVertex << std::endl;
				prevDistance[root->connectedTo[j].toVertex] = root->connectedTo[j].weight;
			}
		}
		//Take smallest edge off the top of the minimal spanning tree
		root = &graph[queue.top().toVertex];
		//Check if the node has already been visited
		if(!prevBeen[queue.top().toVertex])
		{
			std::cout << "Moving to node: " << queue.top().toVertex << std::endl;
			spanningWeight += queue.top().weight;
		}
		prevBeen[queue.top().toVertex] = true;
		queue.pop();
	} while(!queue.empty());

	//Results
	totalWeight /= 2;
	std::cout << "\nTotal weight: " << totalWeight << '\n';
	std::cout << "Spanning weight: " << spanningWeight << '\n';
	std::cout << "Difference: " << totalWeight - spanningWeight << "\n\n";

	delete [] graph;
	delete [] prevBeen;
	delete [] prevDistance;
	return 0;
}

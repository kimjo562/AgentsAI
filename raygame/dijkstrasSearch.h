#include "Agent.h"
#pragma once

struct  Edge
{
	// Store Node's position
	Vector2 position;

	float gScore;
	Node* parent;

	std::vector<Edge> connections;
};

struct Node
{
	Node* target;
	float cost;
};

class dijkstrasSearch
{
public:
	dijkstrasSearch(dijkstrasSearch* startNode, dijkstrasSearch* endNode) {}
	~dijkstrasSearch() {}



private:
	dijkstrasSearch* startNode;
	dijkstrasSearch* endNode;
};


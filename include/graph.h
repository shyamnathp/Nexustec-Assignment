/*
This file defines the graph and node class.
*/
#pragma once

#include<map>

using namespace std;

/*Node of the Graph*/
class Node
{
private:
	map<int, int> nodeDistances;
public:
	Node() = default;
	Node(const map<int, int>& distances) : nodeDistances(distances)
	{
	}
	Node(map<int,int>&& distances) : nodeDistances(std::move(distances))
	{
	}

	//This function is used to remove the corresponding entry from nodeDistances when the node at 'position' is deleted
	void RemoveDistance(int node);

	void UpdateDistance(int nodeNumber, int distance);

	//Returns nodeDistances
	map<int, int> GetDistances() const;

	//Set nodeDistances explicitly
	void SetDistances(const map<int,int>& distances);
};

/*Graph*/
class Graph
{
private:
	map<int, Node> nodes;
	int numNodes = 0;
	void FindFastestRoute();
public:
	Graph();

	//Adds a node to the graph and recalculates the fastest route
	void AddNode(Node& node);

	//Deletes a node based on nodeNumber and recalculates the fastest route
	void DeleteNode(int nodeNumber);

	//Returns nodes
	map<int, Node> GetNodes() const;

	//Prints the graph using adjacency list representation.
	void PrintGraph() const;
};
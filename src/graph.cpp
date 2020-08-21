#include<vector>
#include<algorithm>
#include<iostream>
#include<map>
#include<graph.h>
#include<iterator>

using namespace std;

/*Node Implementation*/

map<int,int> Node::GetDistances() const
{
	return nodeDistances;
}

void Node::SetDistances(const map<int,int>& distances)
{
	nodeDistances = distances;
}

void Node::RemoveDistance(int node)
{
	nodeDistances.erase(node);
}

void Node::UpdateDistance(int nodeNumber, int distance)
{
	nodeDistances.emplace(make_pair(nodeNumber, distance));
}

/* Graph Implementation */

Graph::Graph()
{
	numNodes = 4;
	nodes.insert_or_assign(1, Node({ {2,10}, {3,15}, {4,20} }));
	nodes.insert_or_assign(2, Node({ {1,10}, {3,35}, {4,25} }));
	nodes.insert_or_assign(3, Node({ {1,15}, {2,35}, {4,30} }));
	nodes.insert_or_assign(4, Node({ {1,20}, {2,25}, {3,30} }));
	FindFastestRoute();
}

void Graph::AddNode(Node& node)
{
	++numNodes;
	for (auto& [number, nodeGraph] : nodes)
	{
		nodeGraph.UpdateDistance(numNodes, (node.GetDistances())[number]);
	}

	nodes.insert_or_assign(numNodes, node);

	cout << "Recalculating Fastest Path \n";
	FindFastestRoute();
}

void Graph::DeleteNode(int nodeNumber)
{
	nodes.erase(nodeNumber);
	for (auto& [number, node] : nodes)
	{
		node.RemoveDistance(nodeNumber);
	}

	cout << "Recalculating Fastest Path \n";
	FindFastestRoute();
}

map<int, Node>  Graph::GetNodes() const
{
	return nodes;
}

void Graph::FindFastestRoute()
{
	vector<int> vertices;
	vector<int> fastestPath;

	//taking the first node in map as starting point 
	fastestPath.emplace_back(nodes.begin()->first);
	vector<int> fastestPathWithoutFirst;

	//add remaining nodes to vertices
	for (auto it = std::next(nodes.begin()); it != nodes.end(); ++it)
	{
		const auto&[number, node] = *it;
		vertices.emplace_back(number);
	}

	int fastestPathWeight = INT_MAX;
	do
	{
		int currentPathWeight = 0;

		int prevVertex = (nodes.begin())->first;
		for (auto vertex : vertices)
		{
			auto vertexDistances = nodes[vertex].GetDistances();
			currentPathWeight += vertexDistances[prevVertex];
			prevVertex = vertex;
		}
		//adding the distances from last node back to the first node
		currentPathWeight += ((nodes.begin())->second.GetDistances())[prevVertex]; 

		if (currentPathWeight < fastestPathWeight)
		{
			fastestPathWeight = currentPathWeight;
			fastestPathWithoutFirst = vertices;
		}

	} while (next_permutation(vertices.begin(), vertices.end()));

	std::copy(fastestPathWithoutFirst.begin(), fastestPathWithoutFirst.end(), std::back_inserter(fastestPath));

	cout << "Fastest Path is: \n";
	for (const auto& vertex : fastestPath)
	{
		cout << vertex << "->";
	}
	cout << nodes.begin()->first <<"\n";

	cout << "Weight of fastest path: " << fastestPathWeight <<"\n";
}

void Graph::PrintGraph() const
{
	for (const auto&[number, node] : nodes)
	{
		cout << number << "->";

		for (const auto&[adjNode, weight] : node.GetDistances())
		{
			cout << adjNode << "(" << weight << ")->";
		}
		cout << "X\n";
	}
}
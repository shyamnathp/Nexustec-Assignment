/*
This is the main file which contains all the necessary actions to be performed.
*/
#include<vector>
#include<iostream>
#include<graph.h>
#include<string>
#include<sstream>
#include<iterator>

using namespace std;

void PrintExisitingNodes(const map<int, Node>& nodes)
{
	cout << "Existing Nodes:";
	for (const auto& [number, node] : nodes)
	{
		cout << number << " ";
	}
	cout << "\n";
}

void Help()
{
	cout << "------Help Console-----\n";
	cout << "------Add Command------\n";
	cout << "Syntax: add \n Enter distances to each of the exiting nodes(space separated) \n distances_to_existing_nodes_space_separated \n";
	cout << "\n";
	cout << "eg:\n add \n Enter distances to each of the exiting nodes(space separated) \n 10 15 20 30 \n \n The numbers depitcs the distances to each node starting from the node with the lowest value \n i.e. if 1 is the node with the lowest value, 10 is the distance from the new node to 1 \n";
	cout << "\n";
	cout << "------Delete Command------\n";
	cout << "Syntax: delete \n Enter node number to delete \n node_value \n";
	cout << "\n";
	cout << "eg: \n delete \n Enter node number to delete \n 2 \n \n This command deletes the node with the value 2 and recalculates the shortest path";
	cout << "\n";
}

int main()
{
	auto graph = make_unique<Graph>();
	string command;
	do
	{
		if (!command.empty())
		{

			/*switch statement cannot be done with strings. Instead of creating an enum, I thought 
			the if-else chain was a better choice here*/
			if (command == "help")
			{
				Help();
			}
			else if (command == "add")
			{
				bool mark = false;
				auto nodes = graph->GetNodes();
				PrintExisitingNodes(nodes);

				cout << "Enter distances to each of the exiting nodes(space separated)\n";
				string distances;
				getline(cin, distances);
				istringstream distStream(distances);
				vector<int> distVec(std::istream_iterator<int>{distStream},std::istream_iterator<int>());

				if (distVec.size() != nodes.size())
				{
					cout << "invalid distances - enter distance to all nodes in graph -enter command again \n";
					continue;
				}

				int distance;
				map<int, int> nodeDistances;
				int i = 0;
				for (const auto&[number, node] : nodes)
				{
					distance = distVec[i];

					if (distance == 0)
					{
						cout << "distance cannot be 0 - enter command again \n";
						mark = true;
						break;
					}

					nodeDistances[number] = distance;
					++i;
				}

				//when a distance value is 0
				if (mark)
					continue;

				//implicit initialization
				graph->AddNode(Node(nodeDistances)); 

			}
			else if (command == "delete")
			{
				auto nodes = graph->GetNodes();
				if (nodes.size() == 2)
				{
					cout << "Cannot delete anymore - only 2 remaining nodes \n";
				}

				PrintExisitingNodes(nodes);

				int number;
				cout << "Enter node number to delete\n";
				cin >> number;
				graph->DeleteNode(number);
			}
			else if (command == "exit")
			{
				exit(0);
			}
			else if (command == "print")
			{
				graph->PrintGraph();
			}
			else
			{
				cout << "invalid command - Find command syntax below \n \n";
				Help();
			}
		}
	} while (getline(cin, command));
}
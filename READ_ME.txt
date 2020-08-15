C++ Version : C++17
No external libraries were used.

Commands:
1. help
   Displays the syntax for add and delete command.
2. add 
Adds a node and recalculates the fastest route.
The nodes are added incrementally with the new node having the number one greater than the exisiting node with the biggest number.
eg: add
	Exisiting nodes: 1 2 3 4
	Enter distances to each of the exisiting node (space separated)
	2 5 10 16
	Fastest Path is:
	1->2->5->4->-3->1
	Weight of the fastest path: 60
3. delete
Deletes a node with the given number and recalculates the fastest route.
eg: delete
	Exisiting nodes: 1 2 3 4
    Enter the node number to be deleted
	4
	Recalculating Fastest Path:
	Fastest Path is:
	1->2->3->1
	Weight of fastest path: 60
4. print
   This command displays the graph using the adjacency list representation of graph.
5. exit
   Exits the program.

If none of the above, then its shows invalid command.

Design Choices:
1. Map was used as a suitable datastructure for both the graph as well as the node within the graph. This enables us to 
   keep track of the nodes, when a node is deleted. 
   
   With a vector, this task get more complex because we will have to work with iterators to track the exisiting neighbouring nodes. 
   This makes the code more complicated.
   
2. I generally create UML Diagrams, but in this case since there was only one extra class, there was no need of one.

3. For the bonus questions, I am displaying the graph using its adjacency list representation rather than the adjacency matrix representation.
   This was easier, considering that I used 'map' as the datastructure.
   
4. I could have used PIMPL idiom inorder the avoid map.h in the header graph.h. But this may make the code a little less readable. It is
   generally advised to use PIMPL idiom in the case when there are more complex scenarios that impair the compilation speed.
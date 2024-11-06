Gheorghe Marius Razvan 324CA

Project 2 - Algorithm Design

Problem 1 ----Counting Paths----
I read the input data, which consists of two graphs. I apply a topological sorting algorithm to the first graph to ensure that when accessing a node u, I have already calculated all paths leading to u from its predecessors. This is achieved through topological sorting. I use Kahn's algorithm for topological sorting, where the in-degree of nodes is checked, and nodes with an in-degree of 0 (which are not preceded by any other nodes) are added to the queue first.

In the compute_paths() function, the vector dp[i] represents the paths from the source to node i. For each node in topological order, I iterate through its neighbors in the first graph and check if the same edges exist in the second graph. If they do, I add the number of paths reaching node to neighbor, as these paths will also reach neighbor. In the end, dp[n] contains the total number of paths from the source to the destination.

The complexity of Kahn's algorithm is O(n+m), and for compute_paths, the complexity is also O(n+m) as we update each node's neighbors in topological order.

Problem 2 ----Trains----
For Problem 2, I store nodes as strings in the order they are read. Similar to Problem 1, I sort the graph topologically. In the get_result function, the dist vector represents the maximum distance from the start node to any other node. I iterate through each node in topological order, then iterate through each node's neighbors to update the maximum distance for each neighbor if the previous distance was smaller. This ultimately provides the maximum distance from start to end.

The program's complexity is O(n+m) for both topological sorting and for calculating the maximum distances to cities.

Problem 3 ----Paths----
I apply Dijkstra's algorithm to find the minimum distances. I calculate the minimum distances from x to all nodes, from y to all nodes using Dijkstra again, and from z to all nodes in the reversed (transposed) graph.

I check each node to verify if it is part of the shortest paths from x to z and from y to z. For each node i, if there exists a path from x to z passing through i and from y to z passing through i, the cost is dist_x[i] + dist_y[i] + dist_z[i]. By starting from z towards x and y, the paths will intersect at a common point, i, which serves as the intermediary. Thus, the total cost becomes dist_x[i] + dist_y[i] + dist_z[i].

The complexity is O((n+m)⋅logn) due to the log n factor from using a priority queue for insertion operations, and n+m because we traverse all nodes and edges.

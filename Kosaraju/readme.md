# Kosaraju Algorithm For Strongly Connected Components

### Problem
To find the number of strongly connected components in a directed graph.

#### What is a strongly connected component?
A strongly connected component is a component of graph in which all nodes can reach to all other nodes in that component.

### Algorithm
1. Call a Depth First Traversal of Graph and after calling DFS for the adjacent vertices of a vertex push that vertex into a stack.
2. Obtain the transpose of given graph by reversing the directions of all edges in graph. All start nodes become end nodes and all end nodes become start nodes.
3. While the stack is not empty pop an element from stack, do dfs traversal on the transpose graph, all the vertices that are reachable by that vertex are members of its strongly connected component. Do this till stack is not empty or all vertices are not visited.

#### Time Complexity: O(V + E)  

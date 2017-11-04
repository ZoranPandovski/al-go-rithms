# Connected components

In an undirected graph, two vertices A and B are said to be connected if and only if there exists a path of edges that join A to B. 
The connected components in a graph is a partition of a graph such that every two nodes (vertices) in the graph is connected if and only if they belong to the same component. 
For example, if graph contains edges (2, 3), (9, 1), then (2, 3) and (9, 1) are the two components but if we add an edge (3, 9), then (1, 2, 3, 9) are in the same component. 
For the purpose of this algorithm we name the ID of the component the minimum ID of the vertex belong to the component. 
For example, in the first example (2, 3) and (9, 1), 2 is the ID of the first component and 1 is the ID of the second component, denoted as CCID below. 

Below are the algorithms for the connected components: 
## Quick-find
Initially, each vertex is treated as a single component. 
Then, for each edge (a, b), if the component id of a != component id of b, we let m and M to be the minimum of the two IDs, respectively. 
Then, we search through all the nodes in the graph and find all vertices with connected component ID as M, and change them to m. 

For example, if (1,2,4,9) and (5,7,10) are different components and a new edge (4,7) is recorded. Knowing that the CCID of 4 is 1 and CCID of 7 is 5, 
and 1<5, we chane the ccid of all 5, 7, 10 to 1. 

The time complexity is O(min(N^2, MN)) where M is the number of edges and N is the number of vertices. 
The cap MN is clear; the cap N^2 simply follows from the fact that iterations are only needed if the ccid of the two vertices joined by the new edge is different. 
This is inefficient. 

## Quick-union
Now the components are treated as trees, with another map called "parent" to store the parent of each node (exception: when the node is itself a root of the tree, in which case we name parent as itself).
Again, each node is treated as single compoent in the beginning. 
For each edge being recorded, the roots of the two vertices are first identified by iteratively finding their parents. 
Do nothing if they are equal. 
If they are not equal, simply one of the trees under another (by naming the parent of root_1 as root_0, for example). 
Time complexity: O(M*h), where M is the number of edges and h the height of tree. 
Worst case of h is O(N) when the tree is linear: we cannot escape from O(M*N).

## Weighted quick-union
Same as quick-union, except that the size of the trees are recorded, and the smaller tree is attached under the bigger tree when merging. 
This caps the height at O(log N) so the complexity is O(M log N), which is better. 



# Breadth First Search algorithms

Breadth First Search (BFS) is a traversing algorithm where you should start traversing from a selected node (source or starting node) and traverse the graph layerwise thus exploring the neighbour nodes (nodes which are directly connected to source node). You must then move towards the next-level neighbour nodes.
As the name BFS suggests, you are required to traverse the graph breadthwise as follows:

1. First move horizontally and visit all the nodes of the current layer
2. Move to the next layer

## Consider the following diagram

![ BFS Animation ](https://upload.wikimedia.org/wikipedia/commons/4/46/Animated_BFS.gif)

The distance between the nodes in layer 1 and the starting node is comparitively lesser than the distance between the nodes in layer 2. Therefore, in BFS, you must traverse all the nodes in layer 1 before you move to the nodes in layer 2.

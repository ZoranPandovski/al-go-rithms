#### Single Source Shortest Path Algorithm (Bellman–Ford Algorithm)

Given a graph and a source vertex src in graph, find shortest paths from src to all vertices in the given graph.
The graph may contain negative weight edges.

#### The algorithm

The algorithm calculates shortest paths in a bottom-up manner. It first calculates the shortest distances which have at-most one edge in the path. Then, it calculates the shortest paths with at-most 2 edges, and so on. After the i-th iteration of the outer loop, the shortest paths with at most i edges are calculated. There can be maximum |V| – 1 edges in any simple path, that is why the outer loop runs |v| – 1 times. The idea is, assuming that there is no negative weight cycle, if we have calculated shortest paths with at most i edges, then an iteration over all edges guarantees to give shortest path with at-most (i+1) edges.


edge 0-1 (or A-B in above figure)
src = 0;
dest = 1;
weight = -1;

edge 0-2 (or A-C in above figure)
src = 0;
dest = 2;
weight = 4;

edge 1-2 (or B-C in above figure)
src = 1;
dest = 2;
weight = 3;

edge 1-3 (or B-D in above figure)
src = 1;
dest = 3;
weight = 2;

edge 1-4 (or A-E in above figure)
src = 1;
dest = 4;
weight = 2;

edge 3-2 (or D-C in above figure)
src = 3;
dest = 2;
weight = 5;

edge 3-1 (or D-B in above figure)
src = 3;
dest = 1;
weight = 1;

edge 4-3 (or E-D in above figure)
src = 4;
dest = 3;
weight = -3;

Output will be (distance of each node from source vertex)

Vertex   Distance from Source
0                0
1                -1
2                2
3                -2
4                1
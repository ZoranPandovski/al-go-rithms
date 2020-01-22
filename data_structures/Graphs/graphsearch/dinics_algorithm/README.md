# Dinic's Algorithm

Dinic's algorithm is a strongly polynomial algorithm for computing the maximum flow in a flow network.

The algorithm runs in O(V * V * E) time and is similar to the Edmonds–Karp algorithm, which runs in O(V * E * E) time, in that it uses shortest augmenting paths. The introduction of the concepts of the level graph and blocking flow enable Dinic's algorithm to achieve its performance.

## Algorithm

*Input*: A network (graph) G = (V,E,c,s,t)
- V : Vertices
- E : Edges
- c : Capacity of edges (u,v)
- s : Starting vertice
- t : Terminal vertice

*Output*: An flow of maximum value.

1. Set for each edge in Edges list, f(u,v) = 0 if c(u,v) > 0.
2. Construct level graph from residual graph. If distance(t) = infinite, stop and output flow value.
3. Find a blocking flow in level graph.
4. Augment flow by blocking flow found in step 3 and go back to step 2.

[Wikipedia](https://en.wikipedia.org/wiki/Dinic%27s_algorithm)  
[Visualization](https://visualgo.net/en/maxflow)

# Kruskal's Algorithm
This is a greedy algorithm that finds a minimum spanning tree for a weighted
graph, which means it finds the smallest weighted subset of all the edges in
the graph such that each vertex in the graph is connected to at least one of
the edges in the subset. If the original graph had more than one connected
component, then Kruskal's algorithm returns a "minimum spanning forest," which
means each connected component it returns is a minimum spanning tree.

### Pseudocode
If implemented with a disjoint-set data structure, the algorithm could resemble
the following, where `A` represents a forest, `MAKE-SET(v)` creates a set
containing the vertex `v`, `FIND-SET(u)` returns vertex `u`, and `FIND-SET(v)`
returns vertex `v`.
```
KRUSKAL(G):
  A = ∅
  foreach v ∈ G.V:
     MAKE-SET(v)
  foreach (u, v) in G.E ordered by weight(u, v), increasing:
     if FIND-SET(u) ≠ FIND-SET(v):
        A = A ∪ {(u, v)}
        UNION(u, v)
  return A
```

### Runtime
Kruskal's algorithm runs in O(E log(E)) = O(E log(V)) time, where E = number of
edges in the graph and V = number of vertices in the graph. V is equal to E
because E is at most V^2, and log(V^2) = 2log(V) => log(V).

### Demo
![](https://upload.wikimedia.org/wikipedia/commons/5/5c/MST_kruskal_en.gif)

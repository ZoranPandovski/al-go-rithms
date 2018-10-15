###Hamiltonian cycle

A Hamiltonian cycle (or Hamiltonian circuit) is a Hamiltonian path that is a cycle. Determining whether such paths and cycles exist in graphs is the Hamiltonian path problem, which is NP-complete.

Hamiltonian paths and cycles are named after William Rowan Hamilton who invented the icosian game, now also known as Hamilton's puzzle, which involves finding a Hamiltonian cycle in the edge graph of the dodecahedron. Hamilton solved this problem using the icosian calculus, an algebraic structure based on roots of unity with many similarities to the quaternions (also invented by Hamilton). This solution does not generalize to arbitrary graphs.

Any Hamiltonian cycle can be converted to a Hamiltonian path by removing one of its edges, but a Hamiltonian path can be extended to Hamiltonian cycle only if its endpoints are adjacent.

All Hamiltonian graphs are biconnected, but a biconnected graph need not be Hamiltonian

#####Bondy–Chvátal theorem

The best vertex degree characterization of Hamiltonian graphs was provided in 1972 by the Bondy–Chvátal theorem, which generalizes earlier results by G. A. Dirac (1952) and Øystein Ore. Both Dirac's and Ore's theorems can also be derived from Pósa's theorem (1962). Hamiltonicity has been widely studied with relation to various parameters such as graph density, toughness, forbidden subgraphs and distance among other parameters.Dirac and Ore's theorems basically state that a graph is Hamiltonian if it has enough edges.

Bondy–Chvátal theorem operates on the closure cl(G) of a graph G with n vertices, obtained by repeatedly adding a new edge uv connecting a nonadjacent pair of vertices u and v with degree(v) + degree(u) = n until no more pairs with this property can be found.

Bondy–Chvátal theorem

A graph is Hamiltonian if and only if its closure is Hamiltonian.
As complete graphs are Hamiltonian, all graphs whose closure is complete are Hamiltonian, which is the content of the following earlier theorems by Dirac and Ore.

Dirac (1952)

A simple graph with n vertices (n = 3) is Hamiltonian if every vertex has degree n / 2 or greater.
Ore (1960)

A graph with n vertices (n = 3) is Hamiltonian if, for every pair of non-adjacent vertices, the sum of their degrees is n or greater (see Ore's theorem).
The following theorems can be regarded as directed versions:

Ghouila-Houiri (1960)

A strongly connected simple directed graph with n vertices is Hamiltonian if every vertex has a full degree greater than or equal to n.
Meyniel (1973)

A strongly connected simple directed graph with n vertices is Hamiltonian if the sum of full degrees of every pair of distinct non-adjacent vertices is greater than or equal to 2n - 1.
The number of vertices must be doubled because each undirected edge corresponds to two directed arcs and thus the degree of a vertex in the directed graph is twice the degree in the undirected graph.

Rahman-Kaykobad (2005)

A simple graph with n vertices has a Hamiltonian path if, for every non-adjacent vertex pairs the sum of their degrees and their shortest path length is greater than n.[9]
The above theorem can only recognize the existence of a Hamiltonian path in a graph and not a Hamiltonian Cycle.

Many of these results have analogues for balanced bipartite graphs, in which the vertex degrees are compared to the number of vertices on a single side of the bipartition rather than the number of vertices in the whole graph.[10]
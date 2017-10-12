### Dijkstra’s algorithm
Dijkstra's algorithm is an algorithm for finding the shortest paths between nodes in a graph, which may represent, for example, road networks. We generate a shortest path tree with given source as root. We maintain two sets, one set contains vertices included in shortest path tree, other set includes vertices not yet included in shortest path tree. At every step of the algorithm, we find a vertex which is in the set of not yet included and has minimum distance from source.

#### A graphical example of Dijkstra’s algorithm
![](https://upload.wikimedia.org/wikipedia/commons/5/57/Dijkstra_Animation.gif)

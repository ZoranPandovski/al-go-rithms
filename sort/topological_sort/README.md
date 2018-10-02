### Topological Sort

A _topological sort_ (or topological ordering) of a [directed graph](https://en.wikipedia.org/wiki/Directed_graph) is a **linear** ordering of its vertices such that for directed edge *uv* from vertex *v*, *u* comes before *v* in the ordering.

For instance, the vertices of the graph may represent **tasks** to be performed, and the edges may represent _constraints_ that one task must be performed before another; in this application, a topological ordering is just a valid sequence for the tasks. A topological ordering is possible **if and only if** the graph has no directed cycles, that is, if it is a directed acyclic graph ([**DAG**](https://en.wikipedia.org/wiki/Directed_acyclic_graph)). Any DAG has at least one topological ordering, and algorithms are known for constructing a topological ordering of any DAG in linear time.

#### Aplications

* Scheduling a sequence of jobs
* Deciding the order of compilation tasks to perform in makefiles
* Data serialization
* Resolving symbol dependencies in linkers.
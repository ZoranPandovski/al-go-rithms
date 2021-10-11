### A* Algorithm 

A* (A-star) algorithm is one of Graph Traversal algorithm which identifies the shortest path.

It is similar with Dijkstra’s algorithm, but A* achieves better performance by using heuristics to guide its search. 

Heuristic estimates the best path through each vertex. 

At each iteration of its loop, A* determine which of its paths to extend. 
A* selects the path that minimizes f(n) = g(n)+h(n). g(n) is cost of the path from the start node to nth node, and h(n) is cost of the path from nth node to the last node.

--------
#### An example of A* algorithm
![image](https://user-images.githubusercontent.com/71889628/99620484-f3316c80-2a68-11eb-826b-1e15da4987ff.png)

Nodes are cities, which are connected with roads(edges) and h(n) is the straight-line distance to target point in this example. Orange node between A and D is start, and blue node between C, E is the goal. 

Following is the problem-solving process.

![image](https://user-images.githubusercontent.com/71889628/99621843-35a87880-2a6c-11eb-9231-f225413a4ea5.png)

![image](https://user-images.githubusercontent.com/71889628/99621848-380ad280-2a6c-11eb-84d6-66a48e776c77.png)

![image](https://user-images.githubusercontent.com/71889628/99621855-3a6d2c80-2a6c-11eb-8895-6a09fc47b499.png)

![image](https://user-images.githubusercontent.com/71889628/99621857-3ccf8680-2a6c-11eb-9d04-7bb5fad83b06.png)


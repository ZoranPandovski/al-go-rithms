# Given a graph and a source vertex in graph, find shortest paths from source to all vertices in the given graph
from collections import defaultdict


class Graph:
    def __init__(self, directed=False):
        self.graph = defaultdict(list)
        self.directed = directed

    def addEdge(self, frm, to, weight):
        self.graph[frm].append([to, weight])

        if self.directed is False:
            self.graph[to].append([frm, weight])
        else:
            self.graph[to] = self.graph[to]

    def find_min(self, dist, visited):
        minimum = float('inf')
        index = -1
        for v in self.graph.keys():
            if visited[v] is False and dist[v] < minimum:
                minimum = dist[v]
                index = v

        return index

    def dijkstra(self, src):
        visited = {i: False for i in self.graph}
        dist = {i: float('inf') for i in self.graph}
        parent = {i: None for i in self.graph}

        # set distance of src vertex from itself 0
        dist[src] = 0

        # find shortest path for all vertices
        for i in range(len(self.graph)-1):
            # find minimum distance vertex from source
            # initially src itself as dist[src] = 0
            u = self.find_min(dist, visited)

            # mark the node as visited
            visited[u] = True
            # check if the distance through current edge is less than previously known distance to v
            for v, w in self.graph[u]:

                if visited[v] is False and dist[u] + w < dist[v]:
                    dist[v] = dist[u] + w
                    parent[v] = u
        # return parent list and distance to each node from source
        return parent, dist

    def printPath(self, parent, v):
        if parent[v] is None:
            return
        self.printPath(parent, parent[v])
        print(v, end=' ')

    def printSolution(self, dist, parent, src):
        print('{}\t{}\t{}'.format('Vertex', 'Distance', 'Path'))

        for i in self.graph.keys():
            if i == src:
                continue
            print('{} -> {}\t\t{}\t\t{}'.format(src, i, dist[i], src), end=' ')
            self.printPath(parent, i)
            print()

if __name__ == '__main__':
    # make an undirected graph
    graph = Graph()

    graph.addEdge(0, 1, 4)
    graph.addEdge(0, 7, 8)
    graph.addEdge(1, 2, 8)
    graph.addEdge(1, 7, 11)
    graph.addEdge(7, 6, 1)
    graph.addEdge(7, 8, 7)
    graph.addEdge(6, 8, 6)
    graph.addEdge(6, 5, 2)
    graph.addEdge(8, 2, 2)
    graph.addEdge(2, 3, 7)
    graph.addEdge(2, 5, 4)
    graph.addEdge(3, 4, 9)
    graph.addEdge(3, 5, 14)
    graph.addEdge(5, 4, 10)

    parent, dist = graph.dijkstra(0)

    graph.printSolution(dist, parent, 0)



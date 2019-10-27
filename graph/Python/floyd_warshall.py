# Given a graph (adjacency matrix) calculates the minimum distance between each vertex pair
from collections import defaultdict

INF = 999999999


class Graph:

    # Constructor
    def __init__(self, vertices, directed=True):
        # default dictionary to store graph
        self.graph = defaultdict(list)

        # Number of vertices
        self.V = vertices

        # Is a directed graph?
        self.directed = directed

        # Initialize adjacency matrix
        for i in range(self.V):
            self.graph[i] = [INF] * self.V
            self.add_edge(i, i, 0)

    # Add an edge from vertex u to vertex v with weight w 
    # if it's a undirected graphs, add an edge from v to u too
    def add_edge(self, u, v, w):
        self.graph[u][v] = w
        if not self.directed:
            self.graph[v][u] = w

    # Solves the lowest distance between each vertex pair
    def solve(self):
        for k in range(self.V):
            for i in range(self.V):
                for j in range(self.V):
                    if self.graph[i][k] + self.graph[k][j] < self.graph[i][j]:
                        self.graph[i][j] = self.graph[i][k] + self.graph[k][j]

    def print_matrix(self):
        for i in range(self.V):
            print(self.graph[i])

def main():
    g = Graph(4)
    g.add_edge(0, 3, 10)
    g.add_edge(2, 3, 1)
    g.add_edge(0, 1, 5)
    g.add_edge(1, 2, 3)
    g.add_edge(3, 1, 7)
    g.add_edge(2, 0, 9)

    g.solve()

    g.print_matrix()

if __name__ == '__main__':
    main()

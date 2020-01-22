from collections import deque
import numpy as np
from copy import deepcopy
import math
class Graph:
    """
    Implementation of a graph with Adjacency Matrix
    """
    def __init__(self,size,directed = False):
        self.size = size
        self.matrix = [[0 for i in range(self.size)] for j in range(self.size)]
        self.directed = directed
        self.Time = 0
        self.color = {i:"white" for i in range(self.size)}
        self.parent = [-1 for i in range(self.size)]
        self.time = [[0,0] for i in range(self.size)]

    def has_vertex(self,i):
        return i>=0 and i<self.size

    def addEdge(self,i,j,weight=1):
        if self.has_vertex(i) and self.has_vertex(j):
            if self.directed:
                self.matrix[i][j] = weight
            else:
                self.matrix[i][j] = weight
                self.matrix[j][i] = weight

    def delEdge(self,i,j):
        if self.directed:
            self.matrix[i][j] = 0
        else:
            self.matrix[i][j] = 0
            self.matrix[j][i] = 0

    def adjacent_vertices(self,i):
        if self.has_vertex(i):
            w = []
            for j in range(self.size):
                if self.matrix[i][j] != 0:
                    w.append(j)
            return w

    def indeg(self):
        indegree = [0 for i in range(self.size)]
        for i in range(self.size):
            l = self.adjacent_vertices(i)
            for j in l:
                indegree[j] =  indegree[j] + 1
        return indegree
## Graph Coloring Using Greedy Algorithm
##1. Color first vertex with first color.
##2. Do following for remaining V-1 vertices.
##….. a) Consider the currently picked vertex and color it with the
##lowest numbered color that has not been used on any previously
##colored vertices adjacent to it. If all previously used colors
##appear on vertices adjacent to v, assign a new color to it.
    
    def chromatic_number(self):
        # Initially all vertices are uncolored
        color = [-1 for i in range(self.size)]
        # Initially all colors are available
        available_color = [True for i in range(self.size)]
        # Color the 0th vertex 
        color[0] = 0
        # Iterate for all other vertices
        for u in range(1,self.size):
            for v in self.adjacent_vertices(u):
                # If the neighbor is colored then make its
                # color unavailable
                if color[v] != -1:
                    available_color[color[v]] = False
            # Find the first available color for vertices u
            c = 0
            for i in range(self.size):
                if available_color[i]:
                    c = i
                    break
            # Color the vertex with that color
            color[u] = c
            # Make all the colors available
            available_color = [True for i in range(self.size)]
        for i in range(self.size):
            print("Color of vertex",i,"is",color[i])
    
def main():
    g = Graph(6)
    g.directed = True
    g.addEdge(5, 2); 
    g.addEdge(5, 0); 
    g.addEdge(4, 0); 
    g.addEdge(4, 1); 
    g.addEdge(2, 3); 
    g.addEdge(3, 1); 
    g.chromatic_number()
    
if __name__ == '__main__':
    main()

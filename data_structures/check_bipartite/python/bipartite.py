from __future__ import print_function
# Python program to find out whether a  
# given graph is Bipartite or not 
  
class Graph(): 
  
    def __init__(self, V): 
        self.V = V 
        self.graph = [[0 for column in range(V)]
                                for row in range(V)] 
  
    # This function returns true if graph G[V][V]  
    # is Bipartite, else false
    def isBipartite(self, src): 
  
        # Create a color array to store colors  
        # assigned to all veritces. Vertex 
        # number is used as index in this array.  
        # The value '-1' of  colorArr[i] is used to  
        # indicate that no color is assigned to  
        # vertex 'i'. The value 1 is used to indicate  
        # first color is assigned and value 0 
        # indicates second color is assigned. 
        colorArr = [-1] * self.V 
  
        # Assign first color to source 
        colorArr[src] = 1
  
        # Create a queue (FIFO) of vertex numbers and  
        # enqueue source vertex for BFS traversal 
        queue = [] 
        queue.append(src) 
  
        # Run while there are vertices in queue  
        # (Similar to BFS) 
        while queue: 
  
            u = queue.pop() 
  
            # Return false if there is a self-loop 
            if self.graph[u][u] == 1: 
                return False; 
  
            for v in range(self.V): 
  
                # An edge from u to v exists and destination  
                # v is not colored 
                if self.graph[u][v] == 1 and colorArr[v] == -1: 
  
                    # Assign alternate color to this  
                    # adjacent v of u 
                    colorArr[v] = 1 - colorArr[u] 
                    queue.append(v) 
  
                # An edge from u to v exists and destination  
                # v is colored with same color as u 
                elif self.graph[u][v] == 1 and colorArr[v] == colorArr[u]: 
                    return False
  
        # If we reach here, then all adjacent  
        # vertices can be colored with alternate  
        # color 
        return True
  
# Driver program to test above function 
g = Graph(4) 
g.graph = [[0, 1, 0, 1], 
            [1, 0, 1, 0], 
            [0, 1, 0, 1], 
            [1, 0, 1, 0] 
            ] 
              
print("Yes" if g.isBipartite(0) else "No")

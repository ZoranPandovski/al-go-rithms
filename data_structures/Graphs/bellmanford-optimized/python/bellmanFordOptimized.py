import math

class Node: #Custom class to keep together information stored on edges (the neighbour and the cost to get there)
    def __init__(self, neighbour = None, cost = None):
        self.neighbour = neighbour
        self.cost = cost

class BellmanFordOptimized:
    
    def __init__(self, startPosition = 1, n = 0):
        self.adjacencyList = {}
        self.startPosition = startPosition
        self.solution = {}
        self.n = 0

    def addToAdjacencyList(self, firstNode, secondNode, weight):
        if firstNode not in self.adjacencyList:
            self.adjacencyList[firstNode] = []
            
        self.adjacencyList[firstNode].append(Node(secondNode, weight))
        
        if secondNode not in self.adjacencyList: #it is an undirected graph, so we have to add it both ways
            self.adjacencyList[secondNode] = []
        
        self.adjacencyList[secondNode].append(Node(firstNode, weight))
        
    def createExampleInput(self):
        #This will create an example of input
        #The adjacency list will be the following: startingNode --> (neigh, cost) --> ...
        # 1 --> (2, 2) --> (4, 3)
        # 2 --> (1, 2) --> (3, 4) --> (5, 8)
        # 3 --> (2, 4) --> (5, 10) --> (7, 7)
        # 4 --> (1, 3) --> (6, 2) --> (5, 5)
        # 5 --> (4, 5) --> (2, 8) --> (3, 10)
        # 6 --> (4, 2)
        # 7 --> (3, 7)
        
        self.addToAdjacencyList(1, 2, 2)
        self.addToAdjacencyList(1, 4, 3)
        
        self.addToAdjacencyList(2, 3, 4)
        self.addToAdjacencyList(2, 5, 8)
        
        self.addToAdjacencyList(3, 5, 10)
        self.addToAdjacencyList(3, 7, 7)
        
        self.addToAdjacencyList(4, 6, 2)
        self.addToAdjacencyList(4, 5, 5)
        self.n = 7
        
    def findSolution(self): #we will expand all the neighbours at maximum N times and try to relax the edges
        queue = [self.startPosition]
        start = finish = 0
        inQueue = {}
        visited = {} #instead of keeping just true or false, we will store how many times we visited each node

        self.solution[self.startPosition] = 0

        while start <= finish:
            currentNode = queue[start]
            inQueue[currentNode] = False    
            
            if currentNode not in visited:
                visited[currentNode] = 1
            else:
                visited[currentNode] += 1

            if visited[currentNode] > self.n:
                self.solution = "Graph has a negative cycle!"
                return

            start += 1
            
            for neigh in self.adjacencyList[currentNode]: #we are trying to use this node to relax the path from the previous one to the next one
                
                if neigh.neighbour not in self.solution:
                    self.solution[neigh.neighbour] = math.inf
                    
                if currentNode not in self.solution:
                    self.solution[currentNode] = math.inf
                
                if neigh.cost + self.solution[currentNode] < self.solution[neigh.neighbour]:
                    self.solution[neigh.neighbour] = neigh.cost + self.solution[currentNode] 
                    
                    if neigh.neighbour not in inQueue or inQueue[neigh.neighbour] == False:
                        queue.append(neigh.neighbour)
                        finish += 1
                        inQueue[neigh.neighbour] = True
                    else:
                        if neigh.neighbour not in visited:
                            visited[neigh.neighbour] = 1
                        else:
                            visited[neigh.neighbour] += 1

    def reset(self):
        self.adjacencyList = {}
        self.solution = {}
        self.n = 0

if __name__  == "__main__":
    
    algo = BellmanFordOptimized()

    algo.addToAdjacencyList(1, 2, 3)
    algo.addToAdjacencyList(1, 3, 12)
    algo.addToAdjacencyList(1, 5, 4)
    algo.addToAdjacencyList(1, 6, 5)
    algo.addToAdjacencyList(2, 3, 4)
    algo.addToAdjacencyList(2, 4, 7)
    algo.addToAdjacencyList(3, 5, 4)
    algo.addToAdjacencyList(3, 6, 2)
    algo.addToAdjacencyList(4, 5, 4)

    algo.n = 6

    algo.findSolution()
    
    print(algo.solution)
class Graph:
    def __init__(self, nnodes, nedges):
        self.nnodes = nnodes
        self.nedges = nedges
        self.adj = []
        for i in  range(nnodes+1):
            temp = []
            for j in range(nnodes+1):
                temp.append(0)
            self.adj.append(temp)
        self.cyclens = []

    def addEdge(self, a, b):
        self.adj[a][b] = 1
        self.adj[b][a] = 1


    def dfsHelper(self, v, visited, myval, parent, parents):


        parents[v] = parent


        visited[v] = True

        for i in range(1, len(self.adj[0])):

            if(self.adj[v][i] == 1):
                if(visited[i] == False):
                    self.dfsHelper(i, visited, myval+1, v, parents)

                else:               

                    if(i!=parent):
                        #cycle detected                     

                        cur = parent
                        count =1
                        #start traversing the parents from here till we reach the current node again
                        while(cur!=i):                          
                            cur = parents[cur]

                            count+=1
                            if(count>self.nedges):
                                break

                        #save count which is the length of the cycle.
                        if(count <self.nedges):
                            self.cyclens.append(count+1)

                visited[i] = True



    def dfs(self, v):
        visited = [0 for i in range(self.nnodes+1)]
        self.cyclens = []
        parents = [0]*(self.nnodes+1)
        self.dfsHelper(v, visited, 1, 0, parents)
        print("The cycles in the graph are of the following lengths")
        print((self.cyclens))


#input the no of nodes and edges
n, m = map(int, input().split())


g = Graph(n, m)
for i in range(m):
    #input the edges as space separated integers.
    a, b = map(int, input().split())
    g.addEdge(a, b)

#prints an array consisiting the lengths of cycles in the graph
g.dfs(1)

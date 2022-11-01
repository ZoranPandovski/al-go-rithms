def isBipartite(self, graph: List[List[int]]) -> bool:
    dic = defaultdict(str)
    
    def adjReqColor(col):
        if col == 'R':
            return 'B'
        return 'R'
        
    def dfs(v, color):

        dic[v] = color
        visited[v] = True

        for adj in graph[v]:
            if dic[adj] and dic[adj] != adjReqColor(color):
                return False    
            elif visited[adj] ==False and (not dfs(adj, adjReqColor(color))):
                return False  
        return True
            

    visited = [False]* len(graph)
    for i in range(len(graph)):
        if visited[i] == False and not dfs(i, 'B'):
            return False
        
    return True
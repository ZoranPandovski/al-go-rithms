import queue

# Standard Breadth First Search
def BFS(graph, source, sink, parent):
    node_count = len(graph)
    visited = [False] * node_count

    q = queue.Queue()
    q.put(source)
    visited[source] = True

    while not q.empty():
        u = q.get()

        for ind, val in enumerate(graph[u]):
            if visited[ind] is False and val > 0:
                q.put(ind)
                visited[ind] = True
                parent[ind] = u
    return True if visited[sink] else False

def EK(graph, source, sink):
    node_count = len(graph)

    parent = [-1] * node_count
    max_flow = 0
    
    # While there exists a path with residual capacity
    while BFS(graph, source, sink, parent):
        path_flow = float('Inf')
        s = sink
        while(s is not source):
            path_flow = min(path_flow, graph[parent[s]][s])
            s = parent[s]
        
        max_flow += path_flow

        # Update the residual capacities of the edges and reverse edges along the path
        v = sink
        while (v is not source):
            u = parent[v]
            graph[u][v] -= path_flow
            graph[v][u] += path_flow
            v = parent[v]
    return max_flow

def main():
    graph = {}
    graph[0] = [0, 1, 0, 0]
    graph[1] = [0, 0, 1, 0]
    graph[2] = [0, 0, 0, 1]
    graph[3] = [0, 0, 0, 0]
    max_flow = EK(graph, 0, 3)
    assert(max_flow == 1)

if __name__ == '__main__':
    main()
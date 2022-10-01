# Breadth-first search(BFS) is an algorithm used for tree traversal on graphs or tree data structures.
# BFS can be easily implemented using recursion and data structures like dictionaries and lists.

# That's how bfs algorithms works:

# 1- Pick any node, display it, visit the adjacent unvisited vertex, mark it as visited and insert it in a queue.
# 2- If there are no remaining adjacent vertices left, remove the first vertex from the queue.
# Repeat step 1 and step 2 until the queue is empty or the desired node is found

graph = {
    'A': ['B', 'C'],
    'B': ['D', 'E'],
    'C': ['F'],
    'D': [],
    'E': ['F'],
    'F': []
}

visited = []  # List to keep track of visited nodes.
queue = []  # Initialize a queue


def bfs(visited, graph, node):
    visited.append(node)
    queue.append(node)

    while queue:
        s = queue.pop(0)
        print(s, end=" ")

        for neighbour in graph[s]:
            if neighbour not in visited:
                visited.append(neighbour)
                queue.append(neighbour)


# Driver Code
bfs(visited, graph, 'A')

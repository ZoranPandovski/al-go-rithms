#In computer science, A* (pronounced as "A star") is a computer algorithm that is widely used in pathfinding and graph
# traversal, which is the process of finding a path between multiple points, called "nodes". It enjoys widespread use due
#to its performance and accuracy. However, in practical travel-routing systems, it is generally outperformed by algorithms
# which can pre-process the graph to attain better performance,  although other work has found A* to be superior to other
#approaches.

#This algorithm is widely used in the field game development to approximate the shortest path on a map
#It is similar to Dijkstra’s Algorithm in the sense that the main objective of both algorithms is to find the shortest path
#       but it runs much quicker than Dijkstra’s Algorithm


class Node():
    """A node class for A* Pathfinding"""
    def __init__(self, parent=None, position=None):
        self.parent = parent
        self.position = position

        self.g = 0
        self.h = 0
        self.f = 0

    def __eq__(self, other):
        return self.position == other.position


def astar(maze, start, end):
    """Returns a list of tuples as a path from the given start to the given end in the given maze"""

    # Create start and end node
    start_node = Node(None, start)
    start_node.g = start_node.h = start_node.f = 0
    end_node = Node(None, end)
    end_node.g = end_node.h = end_node.f = 0

    # Initialize both open and closed list
    open_list = {}
    closed_list = set()

    # Add the start node
    open_list[start_node.position] = start_node

    # Loop until you find the end
    while len(open_list):
        # Get the current node
        current_index = min(open_list, key=lambda x: open_list[x].f)
        current_node = open_list[current_index]

        # Pop current off open list, add to closed list
        open_list.pop(current_index)
        closed_list.add(current_index)

        # Found the goal
        if current_node == end_node:
            path = []
            current = current_node
            while current is not None:
                path.append(current.position)
                current = current.parent
            return path[::-1] # Return reversed path

        # Generate children
        children = []
        adj = [(0, -1), (0, 1), (-1, 0), (1, 0), (-1, -1), (-1, 1), (1, -1), (1, 1)]
        for new_position in adj:  # Adjacent squares
            # Get node position
            node_position = (current_node.position[0] + new_position[0],
                             current_node.position[1] + new_position[1])

            # Make sure within range
            if (node_position[0] > (len(maze) - 1) or node_position[0] < 0
                    or node_position[1] > (len(maze[len(maze) - 1]) - 1)
                    or node_position[1] < 0):
                continue

            # Make sure walkable terrain
            if maze[node_position[0]][node_position[1]] != 0:
                continue

            # Create new node
            new_node = Node(current_node, node_position)

            # Append
            children.append(new_node)

        # Loop through children
        for child in children:
            # Child is on the closed list
            if child.position in closed_list:
                continue

            # Create the f, g, and h values
            child.g = current_node.g + 1
            child.h = ((child.position[0] - end_node.position[0])**2) + (
                (child.position[1] - end_node.position[1])**2)
            child.f = child.g + child.h

            # Child is already in the open list
            if child.position in open_list and child.g > open_list[child.position].g:
                continue

            # Add the child to the open list
            open_list[child.position] = child


def main():

    maze = [[0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]]

    start = (0, 0)
    end = (7, 6)

    path = astar(maze, start, end)
    print(path)


if __name__ == '__main__':
    main()

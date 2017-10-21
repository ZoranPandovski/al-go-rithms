from sortedcontainers import SortedList
import ast
from a_star.util.node import node
from a_star.util.path import path


def read_input(filename):
    """
    read the input files:
    - first line reads n(#of nodes) and e(# of edges)
    - lines 2 to n+1 contain the heuristic values of the nodes
    - lines n+2 to the end represent edges in this way: from to value e.g. from 0 to 1 with cost 3 (in01.in)
    :param filename: name of the input file. e.g. 01.in
    :return: dimensions, nodes and paths
    """
    with open(filename) as f:
        content = f.read().splitlines()
    # variables for our representation
    dimensions = list()  # nodes,edges
    heuristics = list()  # for node 0-n
    edges = {}  # for node 0-n: node:[from,to,cost]
    nodes = list()
    paths = list()
    # splitting
    for i in range(0, len(content)):
        if 0 == i:
            dimensions = content[i].split(" ")
        else:
            if i > 0 and i < 1 + int(dimensions[0]):
                number = int(content[i])
                heuristics.append(number)
                nodes.append(node(i - 1, number, -1))
            else:
                split = content[i].split(" ")
                source_index = int(split[0])
                destination_index = int(split[1])
                cost = int(split[2])

                paths.append(path(nodes[source_index], nodes[destination_index], cost))
    return dimensions, nodes, paths


def compare_solutions(solution, filename):
    """
    compare the solution to the solution in *.ans
    :param solution: solution from A*
    :param filename: input file name
    :return: True if it matches
    """
    with open(filename) as f:
        content = ast.literal_eval(f.read())  # parse string repr of the output to a list
        return solution == content


def goal_check(current_node, target_node):
    """
    Check if the current node id is equal to target node it
    :param current_node: currently checked node
    :param target_node: node we want to reach
    :return:
    """
    if current_node.id == target_node.id:
        return True
    else:
        return False


def get_connected_nodes(current_node, paths):
    """
    Get all nodes that are connected to current_node
    :param current_node: current node
    :param paths: paths of this node
    :return:  all connected nodes in a list
    """
    connectedNodes = list()
    for path in paths:
        if (current_node.id == path.source.id):
            node = path.destination.copy()
            node.setParent(current_node)
            node.f = path.cost + node.heuristic
            connectedNodes.append(node)
    return connectedNodes


def find_solution(last_node):
    """
    Goes through all visited nodes via their parents, returns a list of the correct order in which we traversed the graph
    :param last_node: last node we checked
    :return: ordered list from first to last node.
    """
    solution = list()
    node = last_node
    while True:
        solution.append(node.id)
        if (node.parent == None):  # found the first node
            solution.reverse()
            return solution
        node = node.parent


def a_star(starting_node, target_node, paths):
    """
    A Star generic implementation (see https://en.wikipedia.org/wiki/A*_search_algorithm for more information)
    Finds a way from start to target by using the real cost of travelling and the heuristic values to determine a short path.
    :param starting_node: starting node
    :param target_node: target node
    :param paths: paths
    :return: ordered list of nodes leading to our goal.
    """
    closed = list()  # list that contains all visited nodes
    fringe = SortedList()  # contains all found nodes
    fringe.append(starting_node)  # append the starting node

    while True:
        if (len(fringe) == 0):  # if the fringe is empty
            return None
        node = fringe.pop(0)
        if not any(node.id == it.id for it in closed):  # if the current node is not in our closed list do:
            # print("Current Node= {}, Fringe={}".format(node,fringe)) - uncomment to see how it works!
            if (goal_check(node, target_node)):  # if the current node is our target find the path
                return find_solution(node)
            else:  # else find all neighboring nodes of the current node and add them to the fringe, finally add the curr node to closed.
                connected_nodes = get_connected_nodes(node, paths)
                for connected_node in connected_nodes:
                    fringe.add(connected_node)
                closed.append(node)
        else:
            print("skipped node={}".format(node))


def test():
    #1
    (dimensions, nodes, paths) = read_input("in/01.in")
    print("Got dimensions (nodes,edges) : {}".format(dimensions))
    print("Got nodes: {}".format(nodes))
    print("Got paths: {}".format(paths))
    solution = a_star(nodes[0], nodes[-1], paths)
    print("Got A* Path: {}".format(solution))
    print("Solution matches provided answer? {}".format(compare_solutions(solution, "in/01.ans")))
    #2
    (dimensions, nodes, paths) = read_input("in/02.in")
    print("Got dimensions (nodes,edges) : {}".format(dimensions))
    print("Got nodes: {}".format(nodes))
    print("Got paths: {}".format(paths))
    solution = a_star(nodes[0], nodes[-1], paths)
    print("Got A* Path: {}".format(solution))
    print("Solution matches provided answer? {}".format(compare_solutions(solution, "in/02.ans")))


test()

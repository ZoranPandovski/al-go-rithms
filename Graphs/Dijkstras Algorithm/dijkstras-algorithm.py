def buildGraph():
    graph = {}
    graph['start'] = {}
    graph['start']['a'] = 6
    graph['start']['b'] = 2
    graph['a'] = {}
    graph['a']['fin'] = 1
    graph['b'] = {}
    graph['b']['a'] = 3
    graph['b']['fin'] = 5
    graph['fin'] = {}
    
    return graph

def buildCost():
    cost = {}
    cost['a'] = 6
    cost['b'] = 2
    cost['fin'] = float('inf')
    return cost
    
def buildParent():
    parent = {}
    parent['a'] = 'start'
    parent['b'] = 'start'
    parent['fin'] = None
    return parent
    
def findLowestCostNode(cost, processedNodes):
    lowestCost = float('inf')
    lowestCostNode = None
    for node in cost:
        nodeCost = cost[node]
        if nodeCost < lowestCost and node not in processedNodes:
            lowestCost = nodeCost
            lowestCostNode = node
    return lowestCostNode
    
def dijkstraAlgo():
    graph = buildGraph()
    cost = buildCost()
    parent = buildParent()
    processedNodes = []
    node = findLowestCostNode(cost, processedNodes)
    while node is not None:
        nodeCost = cost[node]
        members = graph[node]
        for member in members:
            newCost = nodeCost + members[member]
            if newCost < cost[member]:
                cost[member] = newCost
                parent[member] = node
        processedNodes.append(node)
        node = findLowestCostNode(cost, processedNodes)
    return cost, parent

cost, parent = dijkstraAlgo()
print('Shortest cost is', cost['fin'])
finParent = parent['fin']
tree = ['fin', finParent]
while parent.get(finParent):
    finParent = parent[finParent]
    tree.append(finParent)
print('Shortest path is', tree[::-1])
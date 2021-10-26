INF = 99999
def printSolution(dist):
	V = len(dist)
	for i in range(V):
		for j in range(V):
			if (dist[i][j] == INF):
				print ("INF")
			else:
				print (dist[i][j])

def floydWarshall (graph):
	V = len(graph)
	dist = list.copy(graph)
	for i in range(V):
		for j in range(V):
			for k in range(V):
				dist[i][j] = min(graph[i][j], graph[i][k] + graph[k][j])

	printSolution(dist)

	
graph = [ [0,   5,  INF, 10],
	[INF, 0,   3, INF],
	[INF, INF, 0,   1],
	[INF, INF, INF, 0]
];

floydWarshall(graph);

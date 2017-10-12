INF = 99999
V = 4
def printSolution(dist):
	print ("Following matrix shows the shortest distances"
			" between every pair of vertices ");
	for i in range(V):
		for j in range(V):
			if (dist[i][j] == INF):
				print ("INF")
			else:
				print (dist[i][j])

def floydWarshall (graph):
	dist = [[0 for i in range(V)] for j in range(V)]

	for i in range(V):
		for j in range(V):
			dist[i][j] = graph[i][j]

	for k in range(V):
		for i in range(V):
			for j in range(V):
				if (dist[i][k] + dist[k][j] < dist[i][j]):
					dist[i][j] = dist[i][k] + dist[k][j]

	printSolution(dist)



def main():
	graph = [ [0,   5,  INF, 10],
		[INF, 0,   3, INF],
		[INF, INF, 0,   1],
		[INF, INF, INF, 0]
	];

	floydWarshall(graph);

main()

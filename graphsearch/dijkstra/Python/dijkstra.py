from sys import argv
from queue import Queue
from math import inf

#Graph class
class Graph:
	def __init__(self,is_directed=False):
		self.vertex = set()
		self.edges = list()
		self.distances = {}
		self.is_directed = is_directed

	#Create a new vertex in the graph
	def add_vertex(self,value):
		self.vertex.add(value)
		self.edges.append([])


	#Create new edges in the graph
	def add_edge(self, from_vertex, to_vertex, distance=1):
		self.edges[from_vertex].append(to_vertex)
		self.distances[(from_vertex, to_vertex)] = distance

		if(self.is_directed):
			self.edges[to_vertex].append(from_vertex)
			self.distances[(to_vertex,from_vertex)] = distance

def dijsktra(graph, src,dst):
	current = src
	distances = []
	distance = 0
	visited = set()

	#Create a list of distances with infinite weight
	for i in graph.vertex:
		distances.append((i,inf))
	distances[current] = (current,0)
	
	#Create an empty list of edge, this list will save the path
	edges = []

	#Crawl the graph while the current vextex is not the destination
	while(current != dst):


		for i in (graph.edges[current]):
		
			#Check if the current edge is not visited, and add it to te visited list
			if(((current,i),graph.distances[current,i]) not in visited):
				visited.add(((current,i),graph.distances[current,i]))
				edges.append(((current,i),graph.distances[current,i]))
		
		#Sort the edges
		edges.sort(key=lambda tup: tup[1],reverse=True)
		
		#Get the smallest edge
		edge = edges.pop()
		
		distance = distances[current][1]+edge[1]
		prev = current
		current = edge[0][1]
		
		#Update the distances list with the current weight to get to this node from the starting node
		if(distance < distances[current][1]):
			distances[current] = (distances[current][0],distance)
		else:
			current = prev
		

	return(distances[dst][1])

def main():
	
	#number of vertex in the graph
	vertex = 4

	#The first number is the the starting vertex index, the second number is the ending vertex index and the third number is the weight of the edge
	edge = [['0', '1', '2'], ['1', '2', '4'], ['2', '0', '5'], ['2', '3', '7']]

	#Initialize the graph
	g=Graph()

	#Initialize vertex in the graph
	for i in range(vertex):
		g.add_vertex(i)

	#Inititialize the edges in the graph
	for i in edge:
		if(len(i) == 2):
			g.add_edge(int(i[0]),int(i[1]))
		else:
			g.add_edge(int(i[0]),int(i[1]),float(i[2]))
	

	print("Distance:(%d,%d): %.2f" % (0,3,dijsktra(g,0,3)))

	
	
main()

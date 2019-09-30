def build_graph(filename):
	graph = dict()
	with open(filename, 'r') as f:
		for line in f:
			s,t = line.split()
			s,t = int(s), int(t)
			dest_nodes = graph.get(s, set())
			dest_nodes.add(t)
			graph[s] = dest_nodes
	return graph

def kosaraju_strongly_connected_components(graph):

	t = 0
	s = 0
	explored_nodes = None
	finishing_times = None
	leaders = None

	def dfs(graph, node):
		nonlocal t,s,finishing_times,leaders
		explored_nodes.add(node)
		leaders[node] = s
		if node in graph:
			for dest_node in graph[node]:
				if dest_node not in explored_nodes:
					dfs(graph, dest_node)
		t += 1
		finishing_times[node] = t

	def dfs_loop(graph):
		nonlocal t,s,finishing_times,leaders, explored_nodes
		finishing_times, leaders, explored_nodes = dict(), dict(), set()
		nb_nodes = len(graph.keys())
		for i in reversed(range(1,nb_nodes+1)):
			if i not in explored_nodes:
				s = i
				dfs(graph, i)

	def reverse_graph(graph):
		edges = set()
		new_graph = dict()
		for node,dest_nodes in graph.items():
			for dest_node in dest_nodes:
				edges.add((node, dest_node))
		for edge in edges:
			dest_nodes = new_graph.get(edge[1],set())
			dest_nodes.add(edge[0])
			new_graph[edge[1]] = dest_nodes
		return new_graph

	rev_graph = reverse_graph(graph)
	#1st dsf_loop pass: we are interested in the finishing_times to create the times_graph
	dfs_loop(graph)
	rev_times_graph = dict()
	for node,dest_nodes in graph.items():
		time_dest_nodes = set()
		for dest_node in dest_nodes:
			time_dest_nodes.add(finishing_times[dest_node])
		rev_times_graph[finishing_times[node]] = time_dest_nodes
	times_graph = reverse_graph(rev_times_graph)
	#2nd dsf_loop pass: we are interested in getting the leader for every node to form the sccs
	dfs_loop(times_graph)
	rev_leaders = dict()
	for node,leader in leaders.items():
		rev_leaders[leader] = rev_leaders.get(leader,[])
		rev_leaders[leader].append(node)
	return list(rev_leaders.values())

def main():
	print('Building graph from file...')
	graph = build_graph('test.txt')
	print('Computing strongly connected components...')
	print(kosaraju_strongly_connected_components(graph))
	

if (__name__ == '__main__'):
	main()

<script>

// Javascript program to print DFS
// traversal from a given given
// graph

// This class represents a
// directed graph using adjacency
// list representation
class Graph
{
	
	// Constructor
	constructor(v)
	{
		this.V = v;
		this.adj = new Array(v);
		for(let i = 0; i < v; i++)
			this.adj[i] = [];
	}
	
	// Function to add an edge into the graph
	addEdge(v, w)
	{
		
		// Add w to v's list.
		this.adj[v].push(w);
	}
	
	// A function used by DFS
	DFSUtil(v, visited)
	{
		
		// Mark the current node as visited and print it
		visited[v] = true;
		document.write(v + " ");

		// Recur for all the vertices adjacent to this
		// vertex
		for(let i of this.adj[v].values())
		{
			let n = i
			if (!visited[n])
				this.DFSUtil(n, visited);
		}
	}
	
	// The function to do DFS traversal.
	// It uses recursive
	// DFSUtil()
	DFS(v)
	{
		
		// Mark all the vertices as
		// not visited(set as
		// false by default in java)
		let visited = new Array(this.V);
		for(let i = 0; i < this.V; i++)
			visited[i] = false;

		// Call the recursive helper
		// function to print DFS
		// traversal
		this.DFSUtil(v, visited);
	}
}

// Driver Code
g = new Graph(4);

g.addEdge(0, 1);
g.addEdge(0, 2);
g.addEdge(1, 2);
g.addEdge(2, 0);
g.addEdge(2, 3);
g.addEdge(3, 3);

document.write("Following is Depth First Traversal " +
			"(starting from vertex 2)<br>");

g.DFS(2);

// This code is contributed by avanitrachhadiya2155

</script>


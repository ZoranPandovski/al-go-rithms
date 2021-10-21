/**            Author: Ajaysinh Rajput                 **/

//      Kahn's Algorithm for Topological Sorting        // 

/*  

Problem: Given Directed Acyclic Graph(DAG), find topological sorting of the graph.
         
Note: Topological sorting for Directed Acyclic Graph (DAG) is a linear 
	  ordering of vertices such that for every directed edge uv, 
	  vertex u comes before v in the ordering. Topological Sorting for
	  a graph is not possible if the graph is not a DAG.

Complexity Analysis:  Time Complexity: O(V+E)  , Space Complexity: O(V)

*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;


vector<int> TopologicalSort(int V, vector<int> adj[])
{
	
	vector<int> indegree(V,0); // store in-degree of vertices
	vector<int> TopSort;

	// calculate in-degrees of vertices
	for(int i=0;i<V;i++) 
		for(auto x:adj[i])
			indegree[x]++;

	// create queue and enqueue all vertices with indegree zero.	
	queue<int> q;
	for(int i=0;i<V;i++)
		if(indegree[i]==0)
			q.push(i);

	// count of visited vertices
	int vis = 0;

	// 
	while(!q.empty())
	{
		// extract queue front and add it to topological sort
		int curr=q.front();
		q.pop();
		TopSort.push_back(curr);

		// reduce indegree of neighbor vertices and add zero indegree neighbour vertices into queue 
		for(auto next:adj[curr])
		{
			indegree[next]--; 
			if(indegree[next]==0) 
				q.push(next);
		}

		vis++; // increase visited vertices count
	}

	// Check for cycle
	if(vis!=V)
	{
		cout<<"There exists a cycle in graph.\n";
		return {};
	}

	return TopSort;
}


// To print Topological Sort
void print(vector<int> v)
{
	cout<<"\nTopological Sort: ";
	for(auto x:v)
		cout<<x<<" ";
}



int main()
{

    int V,E; // V=number of vertices , E=number of edges
	cout<<"\nEnter |V| and |E|: ";
	cin>>V>>E;

	vector<int> adj[V]; // adjacency list
	int u,v;
	cout<<"\nEnter edges: \n";
	// make adjacency list
	for(int i=0;i<E;i++)
	{
		cin>>u>>v;
		adj[u].push_back(v);
	}

	vector<int> TopSort = TopologicalSort(V,adj);
	// print Topological Sort of given graph
	print(TopSort);

	return 0;

}
#include <bits/stdc++.h>
using namespace std;

// Declaring the in_time and out_time arrays of the nodes 
int int_time[100], out_time[100];

// Declaring the tour array which will have the position of the node in the flattend tree 
int timer, tour[100];

// Tree will be stored using adjecency list
vector<int> adj[100];

// A simple DFS method used for euler tour of a tree
void euler_tour(int node, int parent)
{
	timer++;
	
	//We store the time when we enter the subtree of a particular node
	int_time[node]=timer;
	
	// A node is stored according in the tour array according to the position in the tree
	tour[timer]=node;
	
	for(int it: adj[node])
	{
		if(it == parent)	continue;	// If parent occurs in the list then we dont call the DFS function
		euler_tour(it,node);
	}
	
	// Storing the time when the subtree of the 'node' is fully visited	
	out_time[node]=timer;	
}

int main()
{
	int n,u,v;
	
	// Taking input of the node in the standard way
	cin>>n;
	
	// Taking n-1 lines of input of 2 integers which denotes there is an edge between node u and node v
	for(int i=1;i<=n-1;i++)
	{
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	// Calling the DFS function to make a euler tour of the tree
	euler_tour(1,0);
	
	cout<<"The Euler Tour of the tree : ";
	// Printing the euler tour
	for(int i=1;i<=n;i++)
	{
		cout<<tour[i]<<" ";
	}
	
	return 0;
}

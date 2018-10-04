#include<bits/stdc++.h>

using namespace std;

int vertices;
vector <int> graph[100];
int visited[100];

void initialize()
{
	for(int i = 0; i < vertices; i++)
		visited[i] = 0;  // all vertices unvisited initially
}

void dfs(int vertex)
{
	printf("%d\n", vertex);
	visited[vertex] = 1;
	for(int i = 0; i < graph[vertex].size(); i++)
		if(visited[ graph[vertex][i] ] == 0)
			dfs(graph[vertex][i]);
}

int main()
{
	scanf("%d", &vertices);  // user input for number of vertices in the undirected graph
	initialize();
	int edges;
	scanf("%d", &edges);  // user input for number of edges
	for(int i = 0; i < edges; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v); // user input for end point of edges
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	dfs(0); // start dfs with vertex 0
}

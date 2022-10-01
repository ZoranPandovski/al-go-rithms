#include<bits/stdc++.h>

using namespace std;

int vertices;
vector <int> graph[100];
int visited[100];
queue <int> q;

void initialize()
{
	for(int i = 0; i < vertices; i++)
		visited[i] = 0;  // all vertices unvisited initially
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
	int start;
	scanf("%d", &start);   // user input for start vertex
	q.push(start);
	visited[start] = 1;
	while(!q.empty())
	{
		int current = q.front();
		q.pop();
		printf("%d\n", current);
		for(int i = 0; i < graph[current].size(); i++)
		{
			if(visited[ graph[current][i] ] == 0)
			{
				q.push(graph[current][i]);
				visited[ graph[current][i] ] = 1;
			}
		}
	}
}

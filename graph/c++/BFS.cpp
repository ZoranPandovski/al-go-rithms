#include<bits/stdc++.h>
using namespace std;
class graph
{
int V; 
list<int> *adj; 
public:
	graph (int v);
	void addedge(int v,int m);
	void bfs(int s);
};
graph ::graph(int v)
{
	V=v;
	adj=new list<int>[V];
}
void graph:: addedge(int v,int m)
{
	adj[v].push_back(m);
}
void graph::bfs(int s)
{
	bool *visited= new bool[V];
	for(int i=0;i<V;i++)
	visited[i]=false;
	list<int> queue;
	visited[s]=true;
	queue.push_back(s);
	list<int> ::iterator i;
	while(!queue.empty())
	{
		s=queue.front();
		cout<<s<<"->";
		queue.pop_front();
		for(i=adj[s].begin();i!=adj[s].end();++i)
		{	
			if(!visited[*i])
			{
				visited[*i]=true;
				queue.push_back(*i);
				
			}
		}	
	}
}
int main()
{
	graph g(4);
	g.addedge(0, 1);
g.addedge(0, 2);
g.addedge(1, 2);
g.addedge(2, 0);
g.addedge(2, 3);
g.addedge(3, 3);
	g.bfs(0);
	return 0;
}
	
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

#include <bits/stdc++.h>
using namespace std;

void BellmanFord(int graph[][3], int V, int E,int src)
{
	int dis[V];
	
	for (int i = 0; i < V; i++)
		dis[i] = INT_MAX;

	dis[src] = 0;

	for (int i = 0; i < V - 1; i++) {

		for (int j = 0; j < E; j++) {
			if (dis[graph[j][0]] != INT_MAX && dis[graph[j][0]] + graph[j][2] <	dis[graph[j][1]])
				dis[graph[j][1]] =	dis[graph[j][0]] + graph[j][2];
		}
	}

	for (int i = 0; i < E; i++) {
		int x = graph[i][0];
		int y = graph[i][1];
		int weight = graph[i][2];
		if (dis[x] != INT_MAX &&
				dis[x] + weight < dis[y])
			cout << "Graph contains negative weight cycle"<< endl;
	}

	for (int i = 0; i < V; i++)
		cout << i << "\t" << dis[i] << endl;
}

int main()
{
    int V;
	int E;
	cout<<"enter number of vertices and edges: ";
	cin >> V >> E;
	int** graphs = new int*[V];
	for (int i = 0; i < V; i++) {
		graphs[i] = new int[V];
		for (int j = 0; j < V; j++) {
			graphs[i][j] = 0;
		}
	}
	
	cout<<"enter vertices and weight of edge between them: "<<endl;
	for (int i = 0; i < E; i++) {
		int f, s, weight;
		cin >> f >> s >> weight;
		graphs[f][s] = weight;
		graphs[s][f] = weight;
	}
	cout << endl;
	cout<<"output: "<<endl;

	int graph[][3] = { { 0, 1, 3 }, { 1, 2, 1 }, { 2, 3, 8 },
					{ 0, 3, 5 },};

	BellmanFord(graph, V, E, 0);
	return 0;
}

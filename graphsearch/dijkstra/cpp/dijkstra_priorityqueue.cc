#include <iostream>
#include <utility>
#include <list>
#include <vector>
#include <queue>

using namespace std;
#define INF 999999

typedef pair<int, int> pii;

list<pii> adj[INF];
int V;

void dijkstra(int src) {
	priority_queue<pii, vector<pii>, greater<pii> > pq;
	vector<int> dist(V, INF);
	
	pq.push(make_pair(0, src));
	dist[src] = 0;

	while(!pq.empty()) {
		int u = pq.top().second;
		pq.pop();

		for(auto const& i : adj[u]) {
			int v = i.first;
			int w = i.second;

			if(dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				pq.push(make_pair(dist[v], v));
			}
		}
	}
  	//prints all distances from 0 to all nodes
	for(auto i : dist)
		cout << i << ' ';
}

int main() {
	cin >> V; //vertices
	int u, v, w, e;
	cin >> e; //edges
	for(int i = 0; i < e; i++) {
		cin >> u >> v >> w; //source, dest, weight
		adj[u].push_back(make_pair(v, w));
		adj[v].push_back(make_pair(u, w));
	}
	dijkstra(0); //source
}

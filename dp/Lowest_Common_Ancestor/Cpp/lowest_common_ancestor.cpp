#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+5; //maximum number of nodes in tree
const int maxlog = 17; 

int p[maxn][maxlog+1], level[maxn];
vector<int> adj[maxn];

void dfs(int i, int par=0, int d = 1){
	
	p[i][0] = par;
	level[i] = d;
	
	for(auto next : adj[i]){
		if(next == par)
			continue;
		dfs(next, i, d+1);
	}
}

void process(int n){
	memset(p, -1, sizeof(p));
		
	dfs(1);
	
	for(int j = 1; (1<<j)<n; j++){
		for(int i = 1; i<=n; i++){
			if(p[i][j-1] != -1)
				p[i][j] = p[p[i][j-1]][j-1];
		}
	}
}

int lca(int u, int v){
	if(level[u] < level[v]){
		swap(u, v);
	}
	
	int dist = level[u] - level[v];
	
	while(dist > 0){
		int raise = log2(dist);
		
		u = p[u][raise];
		
		dist -= (1LL<<raise);
	}
	
	if(u == v)
		return u;
	
	for(int j = maxlog; j>=0; j--){
		if(p[u][j] != -1 && p[u][j] != p[v][j]){
			u = p[u][j];
			v = p[v][j];
		}
	}
	return p[u][0];
}

int dist(int u, int v){
	return level[u] + level[v] - 2*level[lca(u, v)] + 1;
}

int main(){
	int n = 6;
	
	//Taking input
	adj[1].push_back(2);
	adj[1].push_back(3);
	adj[3].push_back(4);
	adj[3].push_back(5);
	adj[4].push_back(6);
	
	process(n);

	cout << "LCA of 5 and 6 = " << lca(5, 6) << endl;

	return 0;
}
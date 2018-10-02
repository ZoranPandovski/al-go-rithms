// Code for depth first search in c++
#include<bits/stdc++.h>

using namespace std;

const int N = int(1e5)+10;
const int INF = int(1e9)+10;
vector<int> G[N],W[N];
int vis[N];
void dfs(int u, int w)
{
	if(vis[u]) return;
	vis[u] = 1;
	for(int i=0; i<G[u].size(); i++)
		if(W[u][i] <= w && vis[G[u][i]] == 0)
			dfs(G[u][i],w);
}

int main()
{
	int n,m; cin>>n>>m;
	vector<int> E;
	for(int i=0; i<m; i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		G[u].push_back(v);
		W[u].push_back(w);
		E.push_back(w);
	}
	int src,dest; cin>>src>>dest;
	sort(E.begin(),E.end());
	int l=0,r=E.size()-1;
	int ans=INF;
	while(l<=r)
	{
		for(int i=1; i<=n; i++) vis[i] = 0;
		int m = (l+r)/2;
		dfs(src,E[m]);
		if(vis[dest])
		{
			ans = E[m];
			r = m-1;
		}
		else l = m+1;
	}
	cout<<ans<<endl;
	return 0;
}

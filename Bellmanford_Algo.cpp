#include<bits/stdc++.h>

using namespace std;

const int N = int(1e5)+10;
const int INF = int(1e9)+10;
vector<int> G[N],W[N];
int D[N];

int main()
{
	int n,m; cin>>n>>m;
	for(int i=0; i<m; i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		G[u].push_back(v);
		G[v].push_back(u);
		W[u].push_back(w);
		W[v].push_back(w);
	}
	int src; cin>>src;
	for(int i=1; i<=n; i++) D[i] = INF;
	D[src] = 0;
	bool flag=0;
	for(int i=0; i<n; i++)
	{
		for(int u=1; u<=n; u++)
			for(int j=0; j<G[u].size(); j++)
				if(D[u] + W[u][j] < D[G[u][j]])
				{
					if(i==n-1) flag=1;
					D[G[u][j]] = D[u] + W[u][j];
				}
	}
	if(flag) cout<<"Negative Cycle\n";
	else
	{
		for(int i=1; i<=n; i++)
			cout<<i<<" "<<D[i]<<endl;
	}
	return 0;
}

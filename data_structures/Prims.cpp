#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
vector< pair<int,int> > adj[100001];
priority_queue< pair<int,pair<int,int> >, vector<pair<int,pair<int,int> > >, greater<pair<int,pair<int,int> > > > pq;
int done[100001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int i,n,m;
	
	cin>>n>>m;
	for(i=0;i<m;i++)
	{
		int u, v, w;
		cin>>u>>v>>w;
		adj[u].pb(mp(v,w));
		adj[v].pb(mp(u,w));		
	}
	for(i=0;i<adj[1].size();i++)
		pq.push(mp(adj[1][i].second,mp(1,adj[1][i].first)));
	done[1]=1;
	long long sum=0;
	int count=1;
	while(!pq.empty())
	{
		pair<int,pair<int,int> > x = pq.top();
		pq.pop();
		int u = x.second.first;
		int v = x.second.second;
		int w = x.first;
		if(done[u]==1 && done[v]==1)
			continue;
		for(i=0;i<adj[v].size();i++)
			pq.push(mp(adj[v][i].second,mp(v,adj[v][i].first)));
		sum+=w;
		count++;
		done[v]=1;
		if(count==n)
			break;
	}
	cout<<sum;
	cout<<"\n";
	return 0;
}
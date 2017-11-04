
#include<bits/stdc++.h>
using namespace std;
#define lli long long int 
#define fr(a,b,c) for(a=b;a<c;a++)	
#define vi vector<int> 
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
vi adj[100001];
vi vert(100001);
vi sum(100001);
vi dist1(100001);
vi dist2(100001);
vector<bool>visited(100001,false);

int dfs(int v)
{
	int i;
	int ans=v;
	int maxi=0;
	visited[v]=true;	
	for(i=0;i<adj[v].size();i++)
	{
		if(visited[adj[v][i]]==false)
		{
			int a=dfs(adj[v][i]);
			maxi=max(a,maxi);
			if(a==maxi)
			{
				ans=vert[adj[v][i]];
			}
		}
	}
	vert[v]=ans;
	sum[v]=maxi;
	return maxi+1	;


}
void  dfs1(int v,int j)
{
	int i;
	
	visited[v]=true;	
	dist1[v]=j;

	for(i=0;i<adj[v].size();i++)
	{
		if(visited[adj[v][i]]==false)
		{
			dfs1(adj[v][i],j+1);
		}
	}
}
void  dfs2(int v,int j)
{
	int i;
	
	visited[v]=true;	
	dist2[v]=j;

	for(i=0;i<adj[v].size();i++)
	{
		if(visited[adj[v][i]]==false)
		{
			dfs2(adj[v][i],j+1);
		}
	}
}
int main()
{
	int n;
	cin>>n;
	int i,u,v;
	for(i=0;i<n-1;i++)
	{
		scanf("%d%d",&u,&v);
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(1);
	for(i=1;i<=n;i++)
	{
		cout<<"max height is"<<sum[i]<<endl;
	}
	cout<<vert[1]<<endl;

	int diam1=vert[1];
	fill(visited.begin(),visited.end(),false);
	dfs(diam1);
	for(i=1;i<=n;i++)
	{
		cout<<"max height is"<<sum[i]<<endl;
	}
	cout<<vert[diam1]<<endl;
	int diam2=vert[diam1];
	fill(visited.begin(),visited.end(),false);

	dfs1(diam1,0);
	fill(visited.begin(),visited.end(),false);
	dfs2(diam2,0);
	for(i=1;i<=n;i++)
	{
		cout<<"dist from "<<diam1<<" is "<<dist1[i]<<"and "<<diam2<<" is "<<dist2[i]<<endl;
	}
	for(i=1;i<=n;i++)
	{
		cout<<"Height of tree with "<<i<<" as node is "<<max(dist1[i],dist2[i])<<endl		;
	}

	
} 

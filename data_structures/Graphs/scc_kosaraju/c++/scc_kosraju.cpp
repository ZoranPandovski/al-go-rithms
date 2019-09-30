
#include<bits/stdc++.h>
using namespace std;
#define lli long long int 
#define fr(a,b,c) for(a=b;a<c;a++)	
#define vi vector<int> 
#define vlli vector<long long int >
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define f first
#define s second
vi adj[100001];
vi rev[100001];
vi (100001);
bool visited[100001]={false};
vlli ans(100001);

void dfs(int v)
{
	visited[v]=true;
	int i;
	int n=adj[v].size();

	fr(i,0,n)
	{
		if(visited[adj[v][i]]==false)dfs(adj[v][i]);
	}
	q[size++]=v;
}
void dfs2(int v)
{
	visited[v]=true;
	int i;
	//cout<<v<<endl;
	ans[size++]=(lli)v;
	int n=rev[v].size();

	fr(i,0,n)
	{
		if(visited[rev[v][i]]==false)dfs2(rev[v][i]);
	}
			
}

int main()
{
		int t;
		cin>>t;
		
		while(t--)
		{
			lli prod=1;
			lli mod;
			int n,m;
			cin>>n>>m>>mod;
			int i;
			int u,v;

			memset(visited,false,sizeof(visited));
		
		

			fr(i,0,m)
			{
				cin>>u>>v;
				adj[u].pb(v);
				rev[v].pb(u);
			}
			size=0;

			fr(i,1,n+1)
			{
				if(visited[i]==false)
				{
					dfs(i);
				}
			}
			memset(visited,false,sizeof(visited));

			for(i=n-1;i>=0;i--)
			{

				size=0;
				if(visited[q[i]]==false)
				{
					//printf("Start component\n");
					dfs2(q[i]);
				}

				if(size>1)
				{
					int j;
					
					fr(j,0,size)
					{
						prod=((prod%mod)*(ans[j]%mod))%mod;
					}
				}
				size=0;
				//adj[q[i]].resize(0);
				//rev[q[i]].resize(0);
				//visited[q[i]]=false;

			}
			cout<<prod<<endl;
			fr(i,1,n+1)
			{
				adj[i].resize(0);
				rev[i].resize(0);

			}
		}
		return 0;
		
}



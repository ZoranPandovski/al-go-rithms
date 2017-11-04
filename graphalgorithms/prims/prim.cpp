#include<bits/stdc++.h>
using namespace std;
vector< pair<int,int> >adj[100001];
bool visited[100001]={false};
int cost=0;
void prim(int v)
{
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
	q.push(make_pair(0,v));
	int i;
	while(!q.empty())
	{
		pair<int,int> curr=q.top();
		q.pop();
		int x=curr.second;

		if(visited[x]==true )
			continue;

		visited[x]=true;
		cost+=curr.first;

		for(i=0;i<adj[x].size();i++)
			{
				if(visited[adj[x][i].second]==false)
					{
						q.push(adj[x][i]);
					}

			}
	}

}
int main()
{
	int n,m,i,a,b,c;
	cin>>n>>m;
	for(i=0;i<m;i++)
	{
		cin>>a>>b>>c;
		adj[a].push_back(make_pair(c,b));
		adj[b].push_back(make_pair(c,a));

	}

	prim(1);
	cout<<cost<<endl;

}

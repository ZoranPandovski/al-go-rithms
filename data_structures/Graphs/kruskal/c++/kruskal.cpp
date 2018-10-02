#include<bits/stdc++.h>
using namespace std;
vector< pair < int, pair<int,int> > > edge;
vector<int>parent(100001,-1);

int find(int v)
{
	while(parent[v]!=-1)
	{
		v=parent[v];
	}
	return v;

}
void union1(int x,int y)
{
	int v=find(y);
	int w=find(x);
	parent[v]=w;

}
int main()

{
	int n,m,i,a,b,c;
	cin>>n>>m;
	
	int ans=0;

	for(i=0;i<m;i++)
	{
		cin>>a>>b>>c;
		edge.push_back(make_pair(c,make_pair(a,b)));
	}

	sort(edge.begin(),edge.end());

	for(i=0;i<m;i++)
	{

		int x=edge[i].second.first;
		int y=edge[i].second.second;

		if(find(x)!=find(y))
		{
			ans+=edge[i].first;
			union1(x,y);
		}

	}
	cout<<ans;
}


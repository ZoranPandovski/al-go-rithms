#include<bits/stdc++.h>
using namespace std;
#define fr(a,b) for(i=a;i<b;i++)
#define pb push_back
int main()
{
	int n,m,a,b,c;
	cin>>n>>m;
	int i,j;
	vector<int>v[100001];
	vector<int>dist(100001,2e9);
	fr(0,m)
	{
		cin>>a>>b>>c;
		v[i].pb(a);
		v[i].pb(b);
		v[i].pb(c);
	}
	//source is assumed to be 0
	dist[0]=0;

	fr(0,n-1)
	{
		j=0;

		while(v[j].size()!=0)
		{
			if(dist[v[j][0]]+v[j][2]<dist[v[j][1]])
			{
				dist[v[j][1]]=dist[v[j][0]]+v[j][2];
			}

		j++;
		}
		
	}

	for(i=1;i<=n;i++)
	{
		cout<<dist[i]<<endl;
	}
}
	
	
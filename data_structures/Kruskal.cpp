#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
priority_queue<pair<int,pair<int,int> >, vector<pair<int,pair<int,int> > >,
	greater<pair<int,pair<int,int> > > > pq;
vector<int> arr(100001,-1);
int findRoot(int i)
{
	if(arr[i]<0)
		return i;
	return findRoot(arr[i]);
}
void merge(int i,int j)
{
	if(arr[i]>arr[j])
		arr[i]=j;
	if(arr[i]<arr[j])
		arr[j]=i;
	else
		arr[j]=i--;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int i,n,m;
	int u,v,w;
	cin>>n>>m;
	for(i=0;i<m;i++)
	{
		cin>>u>>v>>w;
		pq.push(mp(w,mp(u,v)));
	}
	int ct=0;
	ll wt=0;
	while(ct!=n-1)
	{
		pair<int,pair<int,int> > x= pq.top();
		pq.pop();
		u = x.second.first; v = x.second.second;
		w = x.first;
		int i=findRoot(u);
		int j=findRoot(v);
		if (i!=j)
		{
			merge(i,j);
			ct++;
			wt+=w;
		}
	}
	cout<<wt<<endl;
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

struct node
{
	long long int weight;
	long long int u,v;
	node()
	{
		weight=0;
		u=-1;
		v=-1;
	}
};

node arr_of_edges[5000009];
long long int val[1000009];
long long int DSU[1000009];
long long int n,m;
long long int counta=0;
long long int tot_weigh=0;

long long int find_par(long long int a)
{
	if(DSU[a]!=a)
	{
		long long int temp=find_par(DSU[a]);
		DSU[a]=temp;
		return DSU[a];
	}
	else
		return a;
}
bool compareTwoNodes(node a, node b)
{
    if (a.weight != b.weight )
        return a.weight < b.weight;
}
void Krooskal()
{
	long long int i=0;
	while(counta!=n-1)
	{
		if(find_par(arr_of_edges[i].u)!=find_par(arr_of_edges[i].v))
		{
			tot_weigh+=arr_of_edges[i].weight;
			DSU[arr_of_edges[i].v]=arr_of_edges[i].u;
			counta++;
		}
		i++;
	}
}

int main()
{
	cin >> n >> m ;
	for(long long int i=1;i<=n;i++)
	{
		cin >> val[i];
		DSU[i]=i;
	}
	for(long long int i=0;i<m;i++)
	{
		long long int a,b;
		cin >> a >> b ;
		arr_of_edges[i].u=a;
		arr_of_edges[i].v=b;
		arr_of_edges[i].weight=min(val[a],val[b]);
	}
	sort(arr_of_edges, arr_of_edges+m, compareTwoNodes);
	Krooskal();
	cout << tot_weigh << endl ;
	return 0;
}
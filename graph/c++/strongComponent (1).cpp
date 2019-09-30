#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

ll k=1;
ll visited[100000]={0};
ll visited_rev[100000]={0};
vector<ll> adjList[1003];
vector<ll> adjList_rev[1003];
vector<ll> SCC[1003];
stack <int> S;

void utility(ll list){
	visited[list]=1;

	ll i;
	for(i=0;i<adjList[list].size();i++){
		if(visited[adjList[list][i]]==0){
			utility(adjList[list][i]);
		}
	}
	S.push(list);
}

void DFS(ll num){
	ll list;
	for (list=1; list<=num; list++){
		if(visited[list]==0)
			utility(list);
	}
}

void utility_rev(ll list){
	visited_rev[list]=1;

	ll i;
	//cout << list << " ";
	SCC[k].push_back(list);
	for(i=0;i<adjList_rev[list].size();i++){
		if(visited_rev[adjList_rev[list][i]]==0){
			utility_rev(adjList_rev[list][i]);
		}
	}
}

/*void DFS_rev(ll num){
	ll list;
	for (list=1; list<=num; list++){
		if(visited_rev[list]==0)
			utility_rev(list);
	}
}*/

int main()
{
	ll edges,vertices,i,j,v1,v2;
	cin >> edges >> vertices;
	for(i=1;i<=edges;i++)
	{
		cin >> v1 >> v2;
		adjList[v1].push_back(v2);
		adjList_rev[v2].push_back(v1);
	}
	DFS(vertices);
	while(!S.empty())
	{
		ll v = S.top();
		S.pop();
		if(visited_rev[v]!=1)
		{
			utility_rev(v);
			k++;
		}
	}

	cout << "\n";
	for(i=1;i<=k;i++)
	{
		for(j=0;j<SCC[i].size();j++)
			cout << SCC[i][j] << " ";
		cout << "\n";
	}
}
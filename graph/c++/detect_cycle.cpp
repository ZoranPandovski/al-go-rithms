#include<iostream>
#include<vector>
using namespace std;

void addedge(vector<int> adj[], int u, int v)
{
	adj[u-1].push_back(v-1);
	adj[v-1].push_back(u-1);
}

int main()
{
	int n; cin>>n; // take input of number of nodes
	vector<int> adj[n];
	
	int edges; cin>>edges; // take input of number of edges
	while (edges--)
	{
		int u,v; cin>>u>>v;
		addedge(adj,u,v);
	}

	vector<int> S = {1};
	int discovered[n];
	
	for (int i = 0; i<n; i++)
		discovered[i] = 0;
	discovered[0] = 1;

	string ans = "no";
	while (S.size() > 0)
	{
		vector<int> temp;
		for (int i = 0; i<S.size(); i++)
		{
			int discoveredCount=0;
			int u = S[i];

			// iterate over every neighbour of node u
			for (int j =0; j<adj[S[i]-1].size(); j++)
			{
				int v = adj[u][j];
				if (discovered[v] == 0)
				{
					temp.push_back(v);
					discovered[v] = 1;
				}
				else
				{
					discoveredCount++;

					// break if there is a visited neighbour (excluding the parent)
					if (discoveredCount > 1)
					{
						ans = "yes";
						break;
					}
				}

			}
			S = temp;
		}
	}
	cout<<ans<<endl;
}

							


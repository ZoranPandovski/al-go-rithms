// This code demonstrates use of Dijkstra algorithm
// This algo is used to find single source shortest path for any given source for a graph
// that means for each node we find the shortest path from source to reach there
// shortest path means a path with least sum of weights

// Time Complexity: O(ElogV)

#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int src, vector<vector<pair<int, int>>> adj, int n)
{
    //max-heap with negative values
    priority_queue<pair<int,int>> pq;

    //dist, node ID
    pq.push({0,src});

    vector<int> d(n+1, INT_MAX);
    d[src]=0;

    //while there are red nodes
    while(!pq.empty())
    {
        pair<int,int> p = pq.top();
        pq.pop();
        int v = p.second;
        int cur_dist = -p.first;

        //because of multiple entries in pq
        if(cur_dist>d[v])
        {
            continue;
        }

        for(pair<int,int> e: adj[v])
        {
            int u = e.first;
            int w = e.second;

            //got better distance, then update
            if(d[v] + w < d[u]){
                d[u] = d[v] + w;
                pq.push({-d[u], u});
            }
        }
    }
    return d;
}

int main()
{
    // input the number of nodes
    int n;
    cin>>n;

    int e;
    cin>>e;

    // adjacency list
    vector<vector<pair<int, int>>> adj(n+1);

    // input the edges with source, destination, weight
    for(int i=0;i<e;i++)
    {
        int s, d, w;
        cin>>s>>d>>w;

        adj[s].push_back({d, w});
    }

    // find shortest distance of all nodes from node 1
    vector<int> dist = dijkstra(1, adj, n);

    for(int i=1;i<=n;i++)
    {
        cout<<dist[i]<<" ";
    }
    cout<<endl;
}

/*
    Test cases:
    n = 5
    e = 4

    1 2 3
    2 3 4
    1 3 2
    2 4 6

    Output :
    0 3 2 9 INT_MAX
*/

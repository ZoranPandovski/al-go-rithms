#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

stack<int> s, component;

// This function arranges all the nodes in the order of increasing finishing time.
void firstDFS(int node, vector<int> adj[], vector<bool> &vis)
{
    vis[node] = true;
    for(int i=0;i<adj[node].size();i++)
    {
        if(!vis[adj[node][i]])
        {
            firstDFS(adj[node][i], adj, vis);
        }
    }
    s.push(node);
}

// This function "collects" all the nodes present in a paticular SCC and pushes them into the component stack.
// Later, this component stck is printed and emptied.
void secondDFS(int node, vector<int> adj[], vector<bool> &vis)
{
    vis[node] = true;
    component.push(node);
    for(int i=0;i<adj[node].size();i++)
    {
        if(!vis[adj[node][i]])
        {
            secondDFS(adj[node][i], adj, vis);
        }
    }
}

int main()
{
    // n-> vertices, m->edges
    int n, m;
    cin>>n>>m;

    vector<int> adj[n], adjReverse[n];
    vector<bool> vis(n, false);

    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adjReverse[v].push_back(u);
    }

    for(int i=0;i<n;i++)
    {
        if(!vis[i])
            firstDFS(i, adj, vis);
    }

    vis.assign(n, false);

    cout<<"The connected components are: "<<endl;
    while(!s.empty())
    {
        int top = s.top();
        s.pop();
        if(!vis[top])
        {
            secondDFS(top, adjReverse, vis);
            while(!component.empty())
            {
                cout<<component.top()<<" ";
                component.pop();
            }
            cout<<endl;
        }
    }
}
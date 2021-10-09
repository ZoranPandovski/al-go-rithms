#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;
void topological_order(int v,vector<vector<int>> &adj,vector<bool>&used,stack<int>&order);
void dfs(int v,vector<vector<int>> &adj_rev,vector<bool>&used,queue<int>&component);
int main() {
    // Enter Number of vertices in Graph
    int n; cin>>n;
    // Enter Edge count
    int m;
    cin>>m;
    vector<vector<int>> adj, adj_reverse;
    vector<bool> used;
    stack<int>order;

    adj.resize(n+1);
    adj_reverse.resize(n+1);

    while(m--){
        // Enter connection u->v
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj_reverse[v].push_back(u);
    }
    used.assign(n+1, false);

    for (int i = 1;i<= n;i++)
        if (!used[i])topological_order(i,adj,used,order);

    used.assign(n+1, false);
    int cnt=1;

    while(!order.empty()){
        int v=order.top();
        order.pop();

        if (!used[v]) {
        queue<int>component;
        dfs (v,adj_reverse,used,component);
        //Print Component
        cout<<"Component "<<cnt<<" :"<<endl;
        while(!component.empty()){
            int u=component.front();
            component.pop();
            cout<<u<<" ";
        }
        cout<<endl;
        cnt++;    
        }

    }

}


void topological_order(int v,vector<vector<int>> &adj,vector<bool>&used,stack<int>&order) {
    used[v] = true;

    for (int u : adj[v])
        if (!used[u])
            topological_order(u,adj,used,order);

    order.push(v);
}

void dfs(int v,vector<vector<int>> &adj_reverse,vector<bool>&used,queue<int>&component) {
    used[v] = true;
    component.push(v);

    for (int u : adj_reverse[v])
        if (!used[u])
            dfs(u,adj_reverse,used,component);
} 

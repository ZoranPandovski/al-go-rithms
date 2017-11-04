// LCA binary lifting method
#include<bits/stdc++.h>
using namespace std;

#define maxn 300111
#define logN 20

vector<int> adj[maxn];
int par[maxn][logN], depth[maxn];

void dfs2(int u, int p){
    depth[u] = depth[p] + 1;
    par[u][0] = p;
    for(auto i : adj[u]){
        if(i!=p)
            dfs2(i,u);
    }
}

int helper(int n){
    for(int i = 1;i < logN; i++){
        for(int j = 1;j <= n; j++){
            par[j][i] = par[par[j][i-1]][i-1];
        }
    }
}

int lca(int u, int v){
    if(depth[u] < depth[v])
        swap(u, v);
    for(int i = logN - 1;i >= 0; i--){
        if(depth[par[u][i]] >= depth[v])
            u = par[u][i];
    }
    if(u == v)
        return u;
    for(int i = logN - 1;i >= 0; i--)
        if(par[u][i] != par[v][i]){
            u = par[u][i];
            v = par[v][i];
        }
    return par[u][0];     // means parent of u        2^0 'th ancestor of u
}

int main(){
    int i, j, n, k;
    cin >> n;
    for(i = 1;i < n; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs2(2, 0);
    helper(n);
    cin >> k;
    while(k--){
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << endl;
    }
}

#include <bits/stdc++.h>
using namespace std;

/*
    Edmonds karp algorithm computes maximal flow in graph from edge 0 to n-1 in O(|E|x|V|^2)
    Sample input:
        3 3
        0 1 3
        0 2 5
        2 1 7
*/

const int inf = INT_MAX/2;
int n, m;
vector<vector<int>> c, tc;
vector<set<int>> adj;
vector<pair<int,int>> pipes;
vector<int> cut;
vector<bool> visited;
vector<vector<int>> edge_id;

int bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int,int>> q;
    q.push({s, inf});
    while (!q.empty()) {
        int v = q.front().first;
        int f = q.front().second;
        q.pop();
        for (int u : adj[v]) {
            if (parent[u] == -1 and c[v][u] != 0) {
                parent[u] = v;
                int nf = min(f, c[v][u]);
                if (u == t) return nf;
                q.push({u, nf});
            }
        }
    }

    return 0;
}

int maxflow(int s, int t) {
    int f = 0;
    vector<int> parent(n);
    int nf;
    while (nf = bfs(s, t, parent)) {
        f += nf;
        int v = t;
        while (v != s) {
            int prev = parent[v];
            c[prev][v] -= nf;
            c[v][prev] += nf;
            v = prev;
        }
    }
    return f;
}

void dfs_cut(int v)
{
    visited[v] = true;
    for (int u : adj[v]) {
        if (not visited[u] and c[v][u] > 0) dfs_cut(u);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> m; // read number of vertices, number of edges
    c.assign(n, vector<int>(n, 0));
    adj.assign(n, set<int>());
    edge_id.assign(n, vector<int>(n, -1));
    for (int i = 0; i < m; ++i) {
        int ai, bi, ci;
        cin >> ai >> bi >> ci; // read edge {vertex a, vertex b, capacity}
        pipes.push_back(make_pair(ai, bi));
        c[ai][bi] += ci;
        c[bi][ai] += ci;
        adj[ai].insert(bi);
        adj[bi].insert(ai);
        edge_id[ai][bi] = edge_id[bi][ai] = i;
    }
    tc = c;
    int Mf = maxflow(0, n-1);
    visited.assign(n, false);
    dfs_cut(0);
    int mc = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (visited[i] and not visited[j] and tc[i][j] > 0) {
                ++mc;
                cut.push_back(edge_id[i][j]);
            } 
        }
    }
    sort(cut.begin(), cut.end());
    cout << "max flow: " << Mf << ", min cut: " << mc << ", min cut edges: " << endl;
    bool first = true;
    for (int e : cut) {
        cout << pipes[e].first << ' ' << pipes[e].second << endl;
    }
}
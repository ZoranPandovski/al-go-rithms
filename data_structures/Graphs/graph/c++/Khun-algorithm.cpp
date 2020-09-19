#include <bits/stdc++.h>
using namespace std;

/*
    Khun algorithm computes maximum bipartite matching in O(|V|^3)
    Sample input:
        5 5
        0 3
        1 3
        1 4
        2 3
        2 4
*/

bool tryKhun(int n, const vector<vector<int>>& adj, vector<bool>& used, vector<int>& M, int v)
{
    if (used[v]) return false;
    used[v] = true;
    for (int u : adj[v]) {
        if (M[u] == -1) {
            M[u] = v;
            return true;
        }
    }
    for (int u : adj[v]) {
        if (tryKhun(n, adj, used, M, M[u])) {
            M[u] = v;
            return true;
        }
    }
    return false;
}

vector<pair<int,int>> maximumBipartiteMatching(vector<vector<int>>& adj)
{   // Return: Vector of edges in maximum matching
    int n = adj.size();
    vector<bool> used(n, false);
    vector<int> M(n, -1); // -1 if not in maximum matching, else value is the other vertex of the edge
    M.assign(n, -1);
    for (int v = 0; v < n; ++v) {
        used.assign(n, false);
        tryKhun(n, adj, used, M, v);
    }
    vector<pair<int,int>> MM;
    for (int v = 0; v < n; ++v) {
        if (M[v] != -1) {
            pair<int,int> edge = make_pair(min(v, M[v]), max(v, M[v]));
            if (not binary_search(MM.begin(), MM.end(), edge)) { // Avoid repeating same edges
                MM.push_back(edge);
            }
        }
    }
    return MM;
}

int main()
{
    ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m; // read number of vertices, number of edges
    vector<vector<int>> adj(n); // undirected graph adjacency list
    for (int i = 0; i < n; ++i) {
        int v, u;
        cin >> v >> u; // read edge
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    vector<pair<int,int>> MM = maximumBipartiteMatching(adj);
    cout << "maximum bipartite matching size = " << MM.size() << ", edges:" << endl;
    for (auto edge : MM) {
        cout << edge.first << ' ' << edge.second << endl;
    }
}
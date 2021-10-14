#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to detect cycle in an undirected graph.
    bool vis[(int)1e5 + 1];
    
    bool dfs(int e, int p, vector<int> adj[]){
        vis[e] = false;
        for (int x : adj[e]){
            if (x != p){
                if (vis[x]){
                    if (dfs(x, e, adj) == false)
                        return false;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
    
	bool isCycle(int V, vector<int>adj[])
	{
	    // Code here
	    memset(vis, true, sizeof(vis));
	    for (int i = 0; i<V; i++){
	        if (vis[i]){
	            if (dfs(i,-1, adj) == false) return true;
	        }
	    }
	    
	    return false;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isCycle(V, adj);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends
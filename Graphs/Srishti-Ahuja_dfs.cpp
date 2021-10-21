#include<bits/stdc++.h>
using namespace std;

/* DESCRIPTION: Depth First Search or the DFS algorithm starts with the initial node of a given graph, and then goes to deeper and deeper until
we find the final node or a node which has no children. It then backtracks from this final node towards the most recent node that is yet to be
completely unexplored using a stack. */

void recurser(int e, vector<bool> &visited, vector<int> &result, vector<int> adj[]){
    for( auto  i: adj[e]){
        if(!visited[i]){
            visited[i]=true;
            result.push_back(i);
            recurser(i, visited, result, adj);
        }
    }
}

vector<int>dfsOfGraph(int V, vector<int> adj[]){
    //Function to return a list containing the DFS traversal of the graph.
    vector<bool> visited(V,0);
    vector<int> result;
    visited[0]=true;
    result.push_back(0);
    recurser(0, visited, result, adj);

    return result;
}

int main(){
    int V, E;
    cin >> V >> E;
    vector<int> adj[V];

    for(int i = 0; i < E; i++){
        int u, v;
    	cin >> u >> v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }

    vector<int>ans=dfsOfGraph(V, adj);
    for(int i=0;i<ans.size();i++){
      	cout<<ans[i]<<" ";
    }
    cout<<endl;

	return 0;
}

/* Test Case 1:
Input-
5 4
0 1
0 2
0 3
2 4
Output-
0 1 2 4 3*/

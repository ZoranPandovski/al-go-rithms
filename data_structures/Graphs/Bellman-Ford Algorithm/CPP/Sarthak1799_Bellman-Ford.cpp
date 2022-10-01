#include<bits/stdc++.h>
using namespace std;

/* 
The Bellman–Ford algorithm finds shortest paths from a starting node to all
nodes of the graph. The algorithm can process all kinds of graphs, provided that
the graph does not contain a cycle with negative length. If the graph contains a
negative cycle, the algorithm can detect this.

The algorithm keeps track of distances from the starting node to all nodes
of the graph. Initially, the distance to the starting node is 0 and the distance to
all other nodes in infinite. The algorithm reduces the distances by finding edges
that shorten the paths until it is not possible to reduce any distance.

The minimum distance for all nodes can be found in n-1 iterations.

Negative weight detection -> if after n-1 iterations, if the distances to nodes
can again be changed on a further iteration, this indicates a negative weight edge
in graph as when all weights are positive, the minimum distances can be found in 
a maximum of n-1 iterations.

Time Complexity -> O(n*m) , where n are number of nodes and m are number of edges
*/

void Bellman_Ford(vector<tuple<int,int,int>> &edge_list,vector<int> &distance,int x,int n){
    distance[x] = 0;
    for(int i=1;i<=n-1;i++){      // loop for a total of n-1 times (n is the number of nodes)
       for(auto e : edge_list){   // loop for all edges in the graph
           int a,b,w;
           tie(a,b,w) = e;
           distance[b] = min(distance[b],distance[a] + w);
       }
    }
}

int main(){
    vector<tuple<int,int,int>> edge_list;
    edge_list.push_back({1,2,5});           // {a,b,w} -> edge from node a to node b with weight w
    edge_list.push_back({1,3,3});
    edge_list.push_back({1,4,7});
    edge_list.push_back({2,1,5});
    edge_list.push_back({2,4,3});
    edge_list.push_back({2,5,2});
    edge_list.push_back({3,1,3});
    edge_list.push_back({3,4,1});
    edge_list.push_back({4,1,7});
    edge_list.push_back({4,3,1});
    edge_list.push_back({4,2,3});
    edge_list.push_back({4,5,2});
    edge_list.push_back({5,2,2});
    edge_list.push_back({5,4,2});

    vector<int> distance(6,INT32_MAX);    // Initialising distance array with infinty distance for all nodes initially
    Bellman_Ford(edge_list,distance,1,6);

    for(int i=1;i<6;i++){
        cout<<distance[i]<<"\t";
    }
    return 0;
}
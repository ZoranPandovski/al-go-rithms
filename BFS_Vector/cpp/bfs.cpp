#include <bits/stdc++.h> 
using namespace std; 
  
// Declaring the vectors to store color, distance 
// and parent 
vector<string> colour; 
vector<int> d; 
vector<int> p; 
  
/* This function adds an edge to the graph. 
It is an undirected graph. So edges are  
added for both the nodes. */
void addEdge(vector <int> g[], int u, int v) 
{ 
    g[u].push_back(v); 
    g[v].push_back(u); 
} 
  
/* This function does the Breadth First Search*/
void BFSSingleSource(vector <int> g[], int s) 
{ 
    // The Queue used for the BFS operation 
    queue<int> q; 
  
    // Pushing the root node inside the queue 
    q.push(s);  
  
    /* Distance of root node is 0 & colour 
    is gray as it is visited partially now */
    d[s] = 0; 
    colour[s] = "green"; 
          
    /* Loop to traverse the graph. Traversal 
    will happen traverse until the queue is  
    not empty.*/
    while (!q.empty()) 
    { 
        /* Extracting the front element(node)  
        and poping it out of queue. */
        int u = q.front(); 
        q.pop(); 
  
        cout << u << " "; 
  
        /* This loop traverses all the child nodes of u */
        for (auto i = g[u].begin(); i != g[u].end(); i++) 
        { 
            /* If the colour is white then the said node 
            is not traversed. */
            if (colour[*i] == "white") 
            { 
                colour[*i] = "green"; 
                d[*i] = d[u] + 1; 
                p[*i] = u; 
  
                /* Pushing the node inside queue 
                to traverse its children. */
                q.push(*i);  
            } 
        } 
  
        /* Now the node u is completely traversed 
        and colour is changed to black. */
        colour[u] = "dark_green"; 
    } 
} 
  
void BFSFull(vector <int> g[], int n) 
{ 
    /* Initially all nodes are not traversed. 
    Therefore, the colour is white. */
    colour.assign(n, "white"); 
    d.assign(n, 0); 
    p.assign(n, -1); 
  
    // Calling BFSSingleSource() for all white 
    // vertices. 
    for (int i = 0; i < n; i++)      
        if (colour[i] == "white") 
            BFSSingleSource(g, i);  
} 
  
// Driver Function 
int main() 
{ 
    // Graph with 7 nodes and 6 edges. 
    int n = 7; 
          
    // The Graph vector 
    vector <int> g[n]; 
      
    addEdge(g, 0, 1); 
    addEdge(g, 0, 2); 
    addEdge(g, 1, 3); 
    addEdge(g, 1, 4); 
    addEdge(g, 2, 5); 
    addEdge(g, 2, 6); 
  
    BFSFull(g, n); 
  
    return 0; 
} 

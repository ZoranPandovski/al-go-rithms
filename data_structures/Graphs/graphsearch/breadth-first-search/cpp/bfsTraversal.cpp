#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<bool> v;
vector<vector<int>> g;

void bfsTraversal(int b)
{
    //Declare a queue to store all the nodes connected to b
    queue<int> q;

    //Insert b to queue
    q.push(b);

    //mark b as visited
    v[b] = true;

    cout << "\n\nThe BFS Traversal is:  ";

    while (!q.empty())
    {
        int a = q.front();

        //delete the first element form queue
        q.pop(); 

        for (auto j = g[a].begin(); j != g[a].end(); j++)
        {
            if (!v[*j])
            {
                v[*j] = true;
                q.push(*j);
            }
        }
        cout << a << "  ";
    }
}

void makeEdge(int a, int b)
{
    //an edge from a to b (directed graph)
    g[a].push_back(b); 
}

int main()
{

    int vertices, edges;

    cout << "Enter the number of vertices: ";

    cin >> vertices;

    cout << "\n\nEnter the number of edges: ";

    cin >> edges;

    v.assign(vertices, false);
    g.assign(vertices, vector<int>());

    int a, b, i;

    cout << "Enter the edges with source and target vetex: \n ";

    for (i = 0; i < edges; i++)
    {
        cin >> a >> b;
        makeEdge(a, b);
    }

    for (i = 0; i < vertices; i++)
    {
        //if the node i is unvisited
        if (!v[i])
        {
            bfsTraversal(i);
        }
    }

    cout << "\n\n\n";

    return 0;
}

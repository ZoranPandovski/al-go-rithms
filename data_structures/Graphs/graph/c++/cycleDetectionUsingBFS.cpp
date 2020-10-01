#include<bits/stdc++.h>
using namespace std;

//generic graph using templates
template<typename T>
class graph{
    int V;
    map<T,list<T>> h;

public:
    //adding edge between two vetices
    void addEdge(T u,T v,bool biDir=true)
    {
        h[u].push_back(v);
        if(biDir)
        {
            h[v].push_back(u);
        }
        return;
    }
    //printing the graph
    void print()
    {
        for(auto i:h)
        {
            cout<<i.first<<" -> ";
            for(auto j:i.second)
            {
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }
    //function to check that cycle exists or not?
    bool iscyclic(T src)
    {
        map<T,bool> visited;
        map<T,int> parent;
        queue<T> q;
        q.push(src);
        visited[src]=true;
        parent[src]=src;
        while(!q.empty())
        {
            T node=q.front();
            q.pop();
            for(auto neighbour: h[node])
            {
                if(visited[neighbour]==true && parent[node]!=neighbour)
                {
                    return true;
                }
                else if(!visited[neighbour])
                {
                    visited[neighbour]=true;
                    parent[neighbour]=node;
                    q.push(neighbour);
                }
            }
        }
        return false;
    } 
    
    
};
int main()
{
    graph<int> g;
    // test case 1: cycle present
    g.addEdge(0,1); 
    g.addEdge(1,2); 
    g.addEdge(0,4); 
    g.addEdge(2,4); 
    g.addEdge(2,3); 
    g.addEdge(3,4);
    g.addEdge(3,5);
    //test case 2: no cycle
    // g.addEdge(1,2);
    // g.addEdge(1,3);

    //g.print();

    bool ans=g.iscyclic(1);
    if(ans)
    {
        cout<<"cycle detected"<<endl;
    }
    else
    {
        cout<<"No cycle present"<<endl;
    }
    return 0;
}

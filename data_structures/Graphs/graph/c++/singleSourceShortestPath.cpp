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
    //finding the shortest distance of all nodes from the source node
    void sssp(T src)
    {
        queue <T>q;
        q.push(src);
        map<T,int> dist;
        map<T,T> parent;
        for(auto i:h)
        {
            dist[i.first]=INT_MAX;
        }
        dist[src]=0;
        parent[src]=src;
        while(!q.empty())
        {
            T temp=q.front();
            q.pop();
            for(auto i:h[temp])
            {
                if(dist[i]==INT_MAX)
                {
                    q.push(i);
                    dist[i]=1+dist[temp];
                    parent[i]=temp;
                }
            }
        }
        for(auto i:h)
        {
            T temp=i.first;
            cout<<"Distance of "<<temp<<" from "<<src<<" is " <<dist[temp]<<endl;
        }

    }
    
};
int main()
{
    graph<int> g;
    g.addEdge(0,1); 
    g.addEdge(1,2); 
    g.addEdge(0,4); 
    g.addEdge(2,4); 
    g.addEdge(2,3); 
    g.addEdge(3,4);
    g.addEdge(3,5);
    //g.print();
    g.sssp(0);
    return 0;
}

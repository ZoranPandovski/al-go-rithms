#include<bits/stdc++.h>
using namespace std;

template<typename T>
class graph{
   
   public:
   int v;
   map<T,vector<T>> m;

   graph(int V)
   {
      v=V;
   }

   void addEdge(T x,T y,bool bidir=false)
   {
       m[x].push_back(y);
       if(bidir)
       {
           m[y].push_back(x);
       }
   }

   
   void toplogicalSortPrintbyDFS(map<T,bool> &visited,stack<T> &s,T src)
   {
       visited[src]=true;

       for(auto i:m[src])
       {
           if(!visited[i])
           toplogicalSortPrintbyDFS(visited,s,i);
       }
       s.push(src);
   }
   void topologicalSortbyDFS()
   {
       stack<T> s;
       map<T,bool> visited;
       for(auto node:m)
       {
           if(!visited[node.first])
           {
               toplogicalSortPrintbyDFS(visited,s,node.first);
           }
       }

       while(!s.empty())
       {
           cout<<s.top()<<" ";
           s.pop();
       }
   }
};

int main()
{
    graph<int>  g(6);
    g.addEdge(5, 5); 
    g.addEdge(1, 3); 
    g.addEdge(1, 4);  
    g.addEdge(2, 3); 
    g.addEdge(2, 4); 
    g.topologicalSortbyDFS();
    
}
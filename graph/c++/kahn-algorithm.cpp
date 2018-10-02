#include<bits/stdc++.h>
using namespace std;

class Graph { 
    int V;
    list<int> *l;
    map<int, int> inDegree;

    void getInDegree(){
        for(auto u = 0; u < V; u++){
            for(auto child: l[u]){
                inDegree[child]++;
            }
        }
    }

    public:
        Graph(int V){
            this->V = V;
            l = new list<int>[V];
            inDegree.clear();
        }

        void addEdge(int u, int v, bool bidir=true){
            l[u].push_back(v);
            if(bidir) {
                l[v].push_back(u);
            }
        }

        void topologicalSort(){ 
            vector<int> in_degree(V, 0); 
        
            for (int u=0; u<V; u++){ 
                list<int>::iterator itr; 
                for (itr = l[u].begin(); itr != l[u].end(); itr++) 
                    in_degree[*itr]++; 
            } 
        
            queue<int> q; 
            for (int i = 0; i < V; i++) 
                if (in_degree[i] == 0) 
                    q.push(i); 
 
            int cnt = 0; 
         
            vector <int> top_order; 
        
            while (!q.empty()) 
            { 
                int u = q.front(); 
                q.pop(); 
                top_order.push_back(u); 
         
                list<int>::iterator itr; 
                for (itr = l[u].begin(); itr != l[u].end(); itr++) 
        
                    if (--in_degree[*itr] == 0) 
                        q.push(*itr); 
        
                cnt++; 
            } 
         
            if (cnt != V) 
            { 
                cout << "There exists a cycle in the graph\n"; 
                return; 
            } 
        
            for (int i=0; i<top_order.size(); i++) 
                cout << top_order[i] << " "; 
            cout << endl; 
        }
};

int main(){
    Graph g(6);
    g.addEdge(0, 1, false);
    g.addEdge(0, 3, false);
    g.addEdge(1, 2, false);
    g.addEdge(2, 4, false);
    g.addEdge(3, 4, false);
    g.addEdge(2, 3, false);

    g.topologicalSort();
    return 0;
}
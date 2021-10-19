#include<bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.
/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
bool check(int V, int* res, vector<int> adj[]){
    bool flag =true;
    for(int i=0;i<V && flag;i++)
    {
        int n=adj[res[i]].size();
        for(auto j : adj[res[i]])
        {
            for(int k=i+1;k<V;k++)
            {
                if(res[k]==j )
                    n--;
            }
        }
        if(n!=0)
            flag =false;
    }
    if(flag==false)
        return 0;
    return 1;
}
/*This is a function problem.You only need to complete the function given below*/
// The Graph structure is as folows
/*  Function which sorts the graph vertices in topological form
*   N: number of vertices
*   adj[]: input graph
*   NOTE: You must return dynamically allocated array
*/

int topSortUtil(int v,vector<int> adj[],int* vis,stack<int>& st)
{
    //cout<<"V "<<v<<endl;
    vis[v]=1;
    for(int i=0;i<adj[v].size();++i)
    {
        if(vis[adj[v][i]]==0)
        {
            topSortUtil(adj[v][i],adj,vis,st);
        }
    }
    st.push(v);
}

int* topoSort(int V, vector<int> adj[])
{
    // Your code here
    int vis[V]{};
    stack<int> st;

    for(int i=0;i<V;++i)
    {
        if(vis[i]==0)
        {
            //cout<<"U "<<i<<endl;
            topSortUtil(i,adj,vis,st);
        }
    }
    //cout<<"K "<<st.size()<<endl;
    int* v=new int[V];
    for(int i=0;i<V;++i)
    {
        v[i]=st.top();
        st.pop();
    }
    return v;
}

// Driver Code
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N,E;
        cin>>E>>N;
        int u,v;

        vector<int> adj[N];

        for(int i=0;i<E;i++)
        {
            cin>>u>>v;
            adj[u].push_back(v);
        }

        int *res = topoSort(N, adj);

        cout<<check(N, res, adj)<<endl;

    }
}



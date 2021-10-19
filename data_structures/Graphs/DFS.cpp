void dfs(int s, vector<int> g[], bool vis[])
{
    
    // Your code here
    cout<<s<<" ";
    vis[s]=1;
    
    for(int i=0;i<g[s].size();++i)
    {
        if(vis[g[s][i]]==0)
        {
            dfs(g[s][i],g,vis);
        }
    }
    
}
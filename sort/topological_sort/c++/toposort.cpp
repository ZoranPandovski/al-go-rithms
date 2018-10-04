#include<bits/stdc++.h>
using namespace std;
vector<int> adj[100000];
stack<int> st;
bool vis[1000000];
void dfs(int a)
{
  vis[a]=1;
  for (int i = 0; i < adj[a].size(); i++) {
    int v=adj[a][i];
    if(vis[v]) continue;
    vis[v]=1;
    dfs(v);
  }
  st.push(a);
}
int main()
{
  int n;
  cin>>n;
  for(int i=0;i<n-1;i++)
  {
    int a,b;cin>>a>>b;
    adj[a].push_back(b);
  }
  // cout<<"sdfdf";
  dfs(1);
  int len=st.size();
  // cout<<len<<endl;
  for(int i=0;i<len;i++)
  {
    cout<<st.top()<<"-->";
    st.pop();
  }
  return 0;
}

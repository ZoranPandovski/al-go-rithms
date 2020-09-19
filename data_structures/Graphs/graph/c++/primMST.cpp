#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e4 + 5;
int spanningTree(vector <pair<int,int> > g[], int n);
int main()
{
	int t ;
	cin>>t;
	while(t--)
	{
	vector <pair<int,int> > adj[MAX];
    int n,e;
    int w, mC;
    cin >> n>> e;
    for(int i = 0;i < e;++i)
    {
    	int x,y;
        cin >> x >> y >> w;
        adj[x].push_back({w, y});
        adj[y].push_back({w, x});
    }
  
    mC= spanningTree(adj, MAX);
    cout << mC << endl;
	}
    return 0;
}

typedef pair<int,int> p;  
  
int spanningTree(vector <pair<int,int> > g[], int MAX)
{
	//Your code here
	vector<int> key(MAX+1,INT_MAX);
	vector<bool> mset(MAX+1,false);
	priority_queue<p,vector<p>,greater<p>> minh;
	
	mset[1]=true;
	key[1]=0;
	minh.push(make_pair(0,1));
	int sum=0;
	while(!minh.empty()){
	    int u=minh.top().second;
	    minh.pop();
	    mset[u]=true;
	    for(auto it=g[u].begin();it!=g[u].end();it++){
	        int v=(*it).second;
	        int w=(*it).first;
	        if(!mset[v] && key[v]>w){
	            key[v]=w;
	            minh.push(make_pair(w,v));
	        }
	    }
	}
	for(int i=1;i<=MAX;i++){
	    if(key[i]!=INT_MAX)
	        sum+=key[i];
	}
	return sum;
}
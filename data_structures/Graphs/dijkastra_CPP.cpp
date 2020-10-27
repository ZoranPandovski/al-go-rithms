#include<bits/stdc++.h>
using namespace std;
	#define author          "Sihare0riginals"
	#define ss       		string 
	#define lli      		long long int
	#define ld       		long double
	#define f        		first
	#define s        		second
	#define all(v)   		v.begin(),v.end()
	#define I(a,i)			memset(a,i,sizeof(a));
	#define pb       		push_back
	#define mp       		make_pair
	#define L(i,start,end)  for(lli i=start;i<=end;i++)
	#define R(i,start,end)  for(lli i=start;i>=end;i--)
	#define ip(n) 			cin>>n;lli ip[n+1];L(i,1,n)cin>>ip[i];
const lli INF = 1e8,mod=1e9+7;
void Bl0ck_M0mb0();

lli n,m;
vector<vector<pair<lli, lli>>> g;
void dijkstra(lli s, vector<lli> &d) {
	d = vector<lli>(n+1, INF);
	d[s] = 0;
	set<pair<int, int>> st;
	st.insert({d[s], s});
	while (!st.empty()) {
		int v = st.begin()->second;
		st.erase(st.begin());
		for (auto it : g[v]) {
			lli to,w;
			to=it.f;
			w=it.s;
			if (d[to] > d[v] + w) {
				auto it = st.find({d[to], to});
				if (it != st.end()) st.erase(it);
				d[to] = d[v] + w;
				st.insert({d[to], to});
			}
		}
	}
}
signed main()
{
	Bl0ck_M0mb0();
	lli t=1;
	//cin>>t;
	while(t--){
		cin>>n>>m;
		vector<pair<lli,lli> > d1;
		L(i,1,n+1)
		g.pb(d1);
		L(i,1,m)
		{
			lli u,v,w;
			cin>>u>>v>>w;
			g[u].pb(mp(v,w));
			g[v].pb(mp(u,w));
		}  
		vector<vector<lli> > d(n+1);
		L(i,1,1)
			dijkstra(i,d[i]);
		L(i,1,9)
			cout<<d[1][i]<<endl;
	}
	return 0;
}

Test Case
/*
IP
Nodes->9 Edges->14 
1 2 4
1 8 8 
2 8 11
2 3 8
8 7 1
8 9 7
3 9 2
7 9 6
3 4 7
6 7 2
3 6 4
4 6 14
4 5 9
5 6 10

OP distance of all nodes from 1
0
4
12
19
21
11
9
8
14
*/

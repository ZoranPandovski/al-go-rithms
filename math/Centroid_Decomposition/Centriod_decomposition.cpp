#include <bits/stdc++.h>
using namespace std;
 
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define si(x) scanf("%d",&x)
#define sii(x,y) scanf("%d%d",&x,&y)
#define siii(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define sl(x) scanf("%lld",&x)
#define sll(x,y) scanf("%lld%lld",&x,&y)
#define slll(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)
 
#define ll long long
#define mp make_pair
#define pb push_back
#define nl printf("\n");
#define pf printf
#define rep(i,n) for(ll i=0;i<n;i++)
#define repi(i,a,b) for(ll i=a;i<b;i++)
#define vint vector<int>
#define tci int t;scanf("%d",&t);while(t--)
const int maxn=10e6+4;

#define MAXN 1025
 
vector<int> tree[MAXN];
vector<int> centroidTree[MAXN];
bool centroidMarked[MAXN];
 
void DFS(int src, bool visited[], int subtree_size[], int* n)
{
    visited[src] = true;
 
    *n += 1;
    subtree_size[src] = 1; 
    vector<int>::iterator it;
    for (it = tree[src].begin(); it!=tree[src].end(); it++)
        if (!visited[*it] && !centroidMarked[*it])
        {
            DFS(*it, visited, subtree_size, n);
            subtree_size[src]+=subtree_size[*it];
        }
}
 
int getCentroid(int src, bool visited[], int subtree_size[], int n)
{
    bool is_centroid = true;
 
    visited[src] = true;
 
    int heaviest_child = 0;
 
    vector<int>::iterator it;
 	for (it = tree[src].begin(); it!=tree[src].end(); it++)
        if (!visited[*it] && !centroidMarked[*it])
        {
            if (subtree_size[*it]>n/2)
                is_centroid=false;
 
            if (heaviest_child==0 ||
                subtree_size[*it]>subtree_size[heaviest_child])
                heaviest_child = *it;
        }
    if (is_centroid && n-subtree_size[src]<=n/2)
        return src;
 
    return getCentroid(heaviest_child, visited, subtree_size, n);
}
 
int getCentroid(int src)
{
    bool visited[MAXN];
 
    int subtree_size[MAXN];
 
    memset(visited, false, sizeof visited);
    memset(subtree_size, 0, sizeof subtree_size);
 
    int n = 0;
    DFS(src, visited, subtree_size, &n); 
    for (int i=1; i<MAXN; i++)
        visited[i] = false;
 
    int centroid = getCentroid(src, visited, subtree_size, n);
 
    centroidMarked[centroid]=true;
 
    return centroid;
}
 
int decomposeTree(int root)
{
    int cend_tree = getCentroid(root);
    printf("%d ", cend_tree); 
    vector<int>::iterator it;
 
    for (it=tree[cend_tree].begin(); it!=tree[cend_tree].end(); it++)
    {
        if (!centroidMarked[*it])
        {
            int cend_subtree = decomposeTree(*it);
 
            centroidTree[cend_tree].push_back(cend_subtree);
            centroidTree[cend_subtree].push_back(cend_tree);
        }
    }
 
    return cend_tree;
}
 
int main()
{
	ifstream myFile("task.in");
    if(!myFile.fail())
    {
        assert(freopen("task.in", "r", stdin));
    }
    int n,m;
 	sii(n,m);
 	rep(i,m)
 	{
 		int x,y;
 		sii(x,y);
	    tree[x].push_back(y);
	    tree[y].push_back(x); 	
	}
    decomposeTree(1);
 	nl
 	for(int i=0;i<=16;i++)
 	{
 		rep(j,centroidTree[i].size())
 			cout<<centroidTree[i][j]<<" ";
 		nl
 	}
    return 0;
}

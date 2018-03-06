#include<bits/stdc++.h>

using namespace std;

class Node
{
    public:
        int rank;
        int index;
        int parent;
        void makeset(int n);
        int findset(int n);
        void union_sets(int a, int b, int u, int v);
};

//Node parent;
Node nodes[100];

void Node :: makeset(int n)
{
//	cout << "h";
    for(int i = 0; i < n; i++)
    {
        nodes[i].rank = 0;
//        cout << "H";
		nodes[i].parent = i;
        nodes[i].index = i;
    }
}

int Node :: findset(int n)
{
	while(nodes[n].parent != nodes[n].index)
    {
        int valParent = nodes[n].parent;
        n = valParent;
    }
    return n;
}

void Node :: union_sets(int a, int b, int u, int v)
{
	int rank1 = nodes[a].rank;
	int rank2 = nodes[b].rank;
	if(rank1 > rank2)
	{
		nodes[b].parent = nodes[a].index;
		nodes[v].parent = nodes[a].index;
	}
	else if(rank2 > rank1)
	{
		nodes[a].parent = nodes[b].index;
		nodes[u].parent = nodes[b].index;
	}
	else
	{
		nodes[b].parent = nodes[a].index;
		nodes[v].parent = nodes[a].index;
		nodes[a].rank += 1;
	}
}

int main()
{
    int n, edges;
    printf("Enter number of vertices:");
    scanf("%d", &n);
    Node node;
    node.makeset(n);
    printf("Enter number of edges:");
    scanf("%d", &edges);
    printf("Enter end points of edges and weights respectively:\n");
    map <int, pair<int, int> > mp;
    multimap <int, int> mst;
    for(int i = 0; i < edges; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        mp.insert(make_pair(w, make_pair(u, v)));
    }
    map <int, pair<int, int> > :: iterator it;
    multimap <int, int> :: iterator it1;
    for(it = mp.begin(); it != mp.end(); it++)
    {
        int u = it -> second.first;
        int v = it -> second.second;
        int a = node.findset(u);
        int b = node.findset(v);
//        Printing Initial Parents
//        printf("Parent of %d is %d\n", u, nodes[u].parent);
//        printf("Parent of %d is %d\n", v, nodes[v].parent);
		if(a != b)
		{
			node.union_sets(a, b, u, v);
			mst.insert(make_pair(u, v));
		}
//		Printing Final Parents
//		printf("Parent of %d is %d\n", u, nodes[u].parent);
//      printf("Parent of %d is %d\n", v, nodes[v].parent);
//      printf("\n****\n");
	}
	printf("MST:\n");
	for(it1 = mst.begin(); it1 != mst.end(); it1++)
		printf("%d --- %d\n", it1 -> first, it1 -> second);
}

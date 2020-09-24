#include<stdio.h>
#include<stdlib.h>

#define N (int)1e5
#define M (int)1e6
const int INF = (int)1e9;

int max(int a, int b)
{
	if(a<b) return b;
	return a;
}

int* G[N];
int* W[N];
int deg[N],U[M],V[M],weight[M],cnt[N];
int Q[N],dis[N];

// Heap functions
struct node
{
	int v,d;
}node;
int empty();
node top();
void pop();
void insert(int v, int d);

void bfs(int src)
{
	int i;
	for(i=1; i<=n; i++) dis[i] = INF;
	dis[src] = 0;
	insert(src,0);
	while(!empty())
	{
		node x = top(); pop();
		int u = x.v; int d = x.d;
		if(d > dis[u]) continue;
		for(i=0; i<cnt[u]; i++)
		{
			int v = G[u][i];
			if(dis[u] + W[u][i] < dis[v])
			{
				dis[v] = dis[u] + W[u][i];
				insert(v,dis[v]);
			}
		}
	}
}

int main()
{
	int n,m,i;
	scanf("%d %d",&n,&m);
	for(i=0; i<m; i++)
	{
		scanf("%d %d %d",&U[i],&V[i],&weight[i]);
		deg[U[i]]++;
		deg[V[i]]++;
	}
	for(i=1; i<=n; i++)
	{
		dis[i] = INF;
		G[i] = (int*)malloc(deg[i]*sizeof(int));
	}
	for(i=0; i<m; i++)
	{
		int u = U[i], v = V[i];
		G[u][cnt[u]] = v;
		G[v][cnt[v]] = u;
		W[u][cnt[u]++] = weight[i];
		W[v][cnt[v]++] = weight[i];
	}
	bfs(1);
	for(i=1; i<=n; i++)
		printf("%d %d\n",i,dis[i]);
}

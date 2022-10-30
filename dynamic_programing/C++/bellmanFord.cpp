#include <iostream>
using namespace std;

struct edge
{
    int u, v, w;
};

struct Graph
{
    int V, E;
    struct edge *e;
};

struct Graph *create(int V, int E)
{
    struct Graph *g = new Graph;
    g->V = V;
    g->E = E;

    g->e = new edge[E];
    return g;
};

void ford(struct Graph *g, int S)
{
    int V = g->V;
    int E = g->E;
    int D[V];

    for (int i = 0; i < V; i++)
    {
        D[i] = INT_MAX;
    }

    D[S] = 0;
    for (int i = 1; i <= V - 1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            int u = g->e[j].u;
            int v = g->e[j].v;
            int w = g->e[j].w;

            if (D[u] != INT_MAX && D[u] + w < D[v])
            {
                D[v] = D[u] + w;
            }
        }
    }

    for (int j = 0; j < E; j++)
    {
        int u = g->e[j].u;
        int v = g->e[j].v;
        int w = g->e[j].w;

        if (D[u] != INT_MAX && D[u] + w < D[v])
        {
            cout << "Err.. Negative Cycle";
            return;
        }
    }

    cout << "Source   Destination Distance From Source\n";
    for (int i = 0; i < V; i++)
        printf("%d\t\t%d\n", i, D[i]);

    return;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("inp1.txt","r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int V = 5;
    int E = 8;
    int a, b, c, d;

    struct Graph *gph = create(V, E);

    /* for(int i=0;i<E;i++)
    {
        cin>>a>>b>>c;
         
         g->e[i].u = a;
         g->e[i].v = b;
         g->e[i].w = c;
    }*/

    gph->e[0].u = 0;
    gph->e[0].v = 1;
    gph->e[0].w = -1;

    gph->e[1].u = 0;
    gph->e[1].v = 2;
    gph->e[1].w = 4;

    gph->e[2].u = 1;
    gph->e[2].v = 2;
    gph->e[2].w = 3;

    gph->e[3].u = 1;
    gph->e[3].v = 3;
    gph->e[3].w = 2;

    gph->e[4].u = 1;
    gph->e[4].v = 4;
    gph->e[4].w = 2;

    gph->e[5].u = 3;
    gph->e[5].v = 2;
    gph->e[5].w = 5;

    gph->e[6].u = 3;
    gph->e[6].v = 1;
    gph->e[6].w = 1;

    gph->e[7].u = 4;
    gph->e[7].v = 3;
    gph->e[7].w = -3;

    ford(gph, 0);
}
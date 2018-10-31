#include <stdio.h>
#include <limits.h>

int print_prim_mst(int parent[], int n, int graph[n][n])
{
  int sum = 0;
  for (int i = 1; i < n; i++)
    {
      printf("%d %d %d\n", parent[i], i, graph[i][parent[i]]);
      sum = sum + graph[i][parent[i]];
    }
  printf("%d\n", sum);
}

int find_min_key(int key[], int mstSet[], int n)
{
  int min = INT_MAX, min_index;
  for (int v = 0; v < n; v++)
    if (mstSet[v] == 0 && key[v] < min)
        min = key[v], min_index = v;
  return min_index;
}

void min_spanning_tree_prim(int n, int graph[n][n])
{
  int parent[n];
  int key[n];
  int mstSet[n];
  for (int i = 0; i < n; i++)
     key[i] = INT_MAX, mstSet[i] = 0;
  key[0] = 0;
  parent[0] = -1;
  for (int count = 0; count < n-1; count++)
  {
     int u = find_min_key(key, mstSet, n);
     mstSet[u] = 1;
     for (int v = 0; v < n; v++)
       if (graph[u][v] && mstSet[v] == 0 && graph[u][v] <  key[v])
          parent[v]  = u, key[v] = graph[u][v];
  }
  print_prim_mst(parent, n, graph);
}

int main(int argc,char *argv[])
{
  int n, m;
  //scanf("%d %d", &n, &m);
  FILE *fp;
  fp=fopen("input.txt","r");
  fscanf(fp,"%d%d",&n,&m);
  int i, j;
  int mat0[n][n];
  int mat1[n][n];
  for (i=0; i<n; i++)
  {
    for (j=0; j<n; j++)
    {
      mat0[i][j] = 0;
      mat1[i][j] = 0;
    }
  }
  int u,v,w;
  for (i=0; i<m; i++)
  {
    //scanf("%d %d %d", &u, &v, &w);
    fscanf(fp,"%d%d%d",&u, &v, &w);
    mat0[u][v] = w;
    mat0[v][u] = w;
  }
  fclose(fp);
  min_spanning_tree_prim(n, mat0);
  return 0;
}

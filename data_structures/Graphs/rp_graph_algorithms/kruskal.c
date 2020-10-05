#define MAX 100
#include<stdio.h>
struct graph
{
	int u;
	int v;
	int w;
	int p;
	int rank;
}G[MAX],T[MAX];
void make(int x)
{
    G[x].p=x;
    G[x].rank=0;
}
int find(int x)
{
    if(x!=G[x].p)
        G[x].p=find(G[x].p);
    return(G[x].p);
}
void link(int x,int y)
{
    if(G[x].rank>G[y].rank)
        G[y].p=x;
    else
        G[x].p=y;
    if(G[x].rank==G[y].rank)
        G[y].rank=G[y].rank+1;
}
void Union(int x,int y)
{
    link(find(x),find(y));
}

void write_in_file(int ver)
{
	int sum=0,i;
	FILE *fp=fopen("output.txt","a");
	for(i=0;i<ver;i++)
        sum+=T[i].w;
   	 for(i=0;i<ver;i++)
    	{
        	fprintf(fp, "%d %d %d\n",T[i].u,T[i].v,T[i].w);
    	}
    	fprintf(fp,"%d\n",sum);
	fclose(fp);
}

void main()
{
	int n,m,i,j,temp,c=0,k,ver=0;
	FILE *fp;
	fp=fopen("input.txt","r");
	fscanf(fp,"%d%d",&n,&m);
	for(i=0;i<m;i++)
		fscanf(fp,"%d%d%d",&G[i].u,&G[i].v,&G[i].w);
	fclose(fp);
	for(i=0;i<n;i++)
	{
		make(i);
	}
	for(i=0;i<m;i++)
	{
		for(j=i+1;j<m;j++)
		{
		if(G[i].w>G[j].w){
			temp=G[i].w;
			G[i].w=G[j].w;
			G[j].w=temp;

			temp=G[i].u;
			G[i].u=G[j].u;
			G[j].u=temp;

			temp=G[i].v;
			G[i].v=G[j].v;
			G[j].v=temp;
		}
		}
	}
	for(i=0;i<m;i++)
    {
        if(find(G[i].u)!=find(G[i].v))
        {
            T[ver].u=G[i].u;
            T[ver].v=G[i].v;
            T[ver].w=G[i].w;
            ver++;
            Union(G[i].u,G[i].v);
        }
    }
    	write_in_file(ver);
}

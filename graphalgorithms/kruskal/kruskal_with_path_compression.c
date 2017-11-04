#include<stdio.h>
#include<stdlib.h>
#define lli long long int 
#define si(a) scanf("%d",&a)
typedef struct Node
{
	int x;
	int y;
}node;
typedef struct Edge
{
	int st;
	int en;
	int w;
}ed;
int cmp(const void* a,const void*b)
{
	return ((ed*)a)->w-((ed*)b)->w;
}
node vert[500000];
ed edge[9000000];
int parent[200001];
int count=0;

int find(int v)
{
        if(parent[v]==-1)
        {
                return v;
        }
        else
        {
        		count++;
                return parent[v]=find(parent[v]);
        }
}
void union2(int x,int y)
{
        count=0;
        int p1=find(x);
        //parent[x]=p1;
        int n1=count;
        count=0;
        int p2=find(y);
        //parent[y]=p2;	
        int n2=count;
        if(n1>n2)parent[p1]=p2;
        else parent[p2]=p1;
}
lli ans=0;
void kruskal(int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		int  a=edge[i].st;
		int  b=edge[i].en;
		int we=edge[i].w;

		if(find(a)!=find(b))
		{
			//printf("start is%d %d\n",vert[a].x,vert[a].y);
			//printf("end is%d %d\n",vert[b].x,vert[b].y);
			//printf("Wigth is %d\n",we);
			ans+=(lli)we;
			union2(a,b);
		}
	}
}

int main()
{
	int t;
	si(t);
	int i,j;
	while(t--)
	{
		ans=0;
		int size=0;
		int n;
		si(n);
		vert[0].x=0;
		vert[0].y=0;
		parent[0]=-1;
		for(i=1;i<=n;i++)
		{
			int a,b;
			si(a);
			si(b);
			vert[i].x=a;
			vert[i].y=b;
			parent[i]=-1;
		}
		size=0;
		for(i=0;i<=n;i++)
		{
			for(j=i;j<=n;j++)
			{
				if(j!=i)
				{
				edge[size].st=i;
				edge[size].en=j;
				edge[size].w=abs(vert[i].x-vert[j].x)+abs(vert[i].y-vert[j].y);
				size++;
				}
			}
		}
		qsort(edge,size,sizeof(ed),cmp);
		/*for(i=0;i<size;i++)
		{
			printf("%d%d%d\n",vert[edge[i].st].x,vert[edge[i].en].x,edge[i].w);
		}*/
		kruskal(size);
		printf("%lld\n",ans);

	}
	return 0;

}
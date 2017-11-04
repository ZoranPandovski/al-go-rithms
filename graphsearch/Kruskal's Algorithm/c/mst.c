#include <stdio.h>
#include <stdlib.h>

int edgeCount=0;
int parent[500000];
int rank[500000];

struct linkedlist
{
	int data;
	struct linkedlist* next;
};
struct linkedlist* start=NULL;

struct edge
{
	int s;
	int d;
	int weight;
	int parent;
};

struct adjlistnode
{
	int value;
	struct adjlistnode* next;
	struct adjlistnode* pre;
	
};

struct adjlist
{
	struct adjlistnode* head;
};

struct graph
{	
	//size is equivalent to V where V is the number of vertices in the graph.
	int size,e;
	struct adjlist* array;
	struct edge* edgeArray;

};

struct adjlistnode* newnode(int x)
{
	struct adjlistnode* node=(struct adjlistnode*)malloc(sizeof(struct adjlistnode));
	node->value=x;
	node->next=NULL;
	return node; 
};

struct graph* newgraph(int v, int e)
{
	struct graph* graph1=(struct graph*)malloc(sizeof(struct graph));
	graph1->size=v;
	graph1->e=e;
	graph1->array=(struct adjlist*)malloc((v+1)*sizeof(struct adjlist));
	graph1->edgeArray=(struct edge*)malloc(e*sizeof(struct edge));
	int i;
	for(i=1;i<v+1;i++)
		graph1->array[i].head=NULL;
	return graph1;
}

void addedge1(struct graph* graph1, int source, int destination, int w)
{	
	// making link betweeen source and desination.

	struct adjlistnode* node1=newnode(destination);
	node1->next=graph1->array[source].head;
	graph1->array[source].head=node1;
	edgeCount++;
	graph1->edgeArray[edgeCount].s=source;
	graph1->edgeArray[edgeCount].d=destination;
	graph1->edgeArray[edgeCount].weight=w;

	//graph1->edgeArray[edgeCount].parent=source;

	// making link from destination to source for an undirected graph.
	
	struct adjlistnode* node2=newnode(source);
	node2=newnode(source);
	node2->next=graph1->array[destination].head;
	graph1->array[destination].head=node2;
	
	
	
}


void printlist(struct graph* graph1)
{
	int j;
	for(j=1;j<(graph1->size)+1;j++)
	{	
		struct adjlistnode* travel=graph1->array[j].head;
		printf("Adjacency list of vertex %d is: ",j);
		while(travel!=NULL)
		{	
			printf("%d ",travel->value);
			travel=travel->next;

		}
		printf("\n");

	}
	
}

void merge(struct edge* edgeArray, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    struct edge L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = edgeArray[l + i];
    for (j = 0; j < n2; j++)
        R[j] = edgeArray[m + 1+ j];
 
    i = 0;
    j = 0; 
    k = l; 
    while (i < n1 && j < n2)
    {
        if (L[i].weight <= R[j].weight)
        {
            edgeArray[k] = L[i];
            i++;
        }
        else
        {
            edgeArray[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1)
    {
        edgeArray[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        edgeArray[k] = R[j];
        j++;
        k++;
    }
}
 
void mergeSort(struct edge* edgeArray, int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;
        mergeSort(edgeArray, l, m);
        mergeSort(edgeArray, m+1, r);
        merge(edgeArray, l, m, r);
    }
}

void makeset(struct graph* graph1, int parent[])
{
	int i;
	for(i=1;i<=graph1->e;i++)
		{
			parent[i]=i;
			rank[i]=0;
		}
}

int findset(int i)
{
	if(parent[i]==i)
		return i;
	else
		return (findset(parent[i]));
}

void Union(int i, int j)
{
	int x=findset(i);
	int y=findset(j);
	if(x==y)
		return ;

	if(rank[x]<rank[y])
		parent[x]=y;
	else if (rank[x]>rank[y])
		parent[x]=y;
	else
	{
		parent[y]=x;
		rank[x]++;
	}

}



void Kruskal(struct graph* graph1,int L)
{	

	int i,c1=1;
	struct edge A1[graph1->size];
	for(i=1;i<(graph1->size);i++)
	{
		A1[i].weight=0;
	}

	for(i=1;i<=graph1->e;i++)
	{
		makeset(graph1, parent);
	}

	mergeSort(graph1->edgeArray,1,L);
	
	for(i=1;i<=graph1->e;i++)
	{
		if(findset(graph1->edgeArray[i].s)!=findset(graph1->edgeArray[i].d))
		{
			A1[c1]=graph1->edgeArray[i];
			c1++;
			Union(graph1->edgeArray[i].s, graph1->edgeArray[i].d);
		}
	}
	
	for(i=1;i<=(graph1->size)-1;i++)
	{	
		printf(" %d %d %d\n",A1[i].s, A1[i].d, A1[i].weight);
	}	
	
}

int main()
{
	int T,N,L,R1,R2,size,i,e,j,p,q,r,w,t1,t2;
	scanf("%d",&T);
	for(i=0;i<T;i++)
	{	
		edgeCount=0;
		scanf("%d %d", &N, &L);
		struct graph* graph1=newgraph(N,L);

		for(j=0;j<L;j++)
		{
			scanf("%d %d %d",&p,&q,&r);
			addedge1(graph1,p,q,r);
		}
		if(L==1)
		{
			printf("%d\n",r);
		}

		else
		{
			Kruskal(graph1,L);
			edgeCount=0;
		}
	}


return 0;
}

/* Sample case
6 6 5
5 1 2
1 4 9
1 2 3
6 3 4
6 4 5
4 3 6
5 4 3
1 3 1
1 6 4
6 2 5
2 3 6
*/

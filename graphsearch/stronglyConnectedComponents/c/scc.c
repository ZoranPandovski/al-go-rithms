#include <stdio.h>
#include <stdlib.h>


int t=0;

struct linkedlist
{
	int data;
	struct linkedlist* next;
};
struct linkedlist* start=NULL;


char arrayc[10001]={'w'};
int arrayd[10001]={0};
int arrayf[10001]={0};
int arrayv[10001]={0};

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
	int size;
	struct adjlist* array;
};

// x is the value of the new node being entered.
struct adjlistnode* newnode(int x)
{
	struct adjlistnode* node=(struct adjlistnode*)malloc(sizeof(struct adjlistnode));
	node->value=x;
	node->next=NULL;
	return node; 
};

// v is the size of the graph
struct graph* newgraph(int v)
{	
	
	struct graph* graph1=(struct graph*)malloc(sizeof(struct graph));
	graph1->size=v;
	graph1->array=(struct adjlist*)malloc((v+1)*(sizeof(struct adjlist)));
	int i;
	for(i=1;i<v+1;i++)
		graph1->array[i].head=NULL;
	
	return graph1;
}


void addedge(struct graph* graph1, int source, int dest )
{	
	// making link betweeen source and desination.

	struct adjlistnode* node1=newnode(dest);
	
	node1->next=graph1->array[source].head;
	graph1->array[source].head=node1;

	// making link from destination to source for an undirected graph.
	/*
	struct adjlistnode* node2=newnode(source);
	node2=newnode(source);
	node2->next=graph1->array[dest].head;
	graph1->array[dest].head=node2;
	*/
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



void dfsvisit(struct graph* graph1, int x)
{	
	t++;
	arrayd[x]=t;
	arrayc[x]='g';
	struct adjlistnode* travel1=graph1->array[x].head;
	while(travel1!=NULL)
	{

		if(arrayc[travel1->value]=='w')
		{
			dfsvisit(graph1, travel1->value);
		}
		travel1=travel1->next;
	}

	arrayc[x]='b';
	t++;
	arrayf[x]=t;
	struct linkedlist* l2=(struct linkedlist*)malloc(sizeof(struct linkedlist));
	l2->data=x;
	l2->next=NULL;
	if(start==NULL)
	{	
		start=l2;
	}
	else
	{
		
		l2->next=start;
		start=l2;
	}

}	

void dfs(struct graph* graph1)
{
	int i;
	for(i=1;i<(graph1->size)+1;i++)
	{
		arrayc[i]='w';
		arrayd[i]=0;
		arrayv[i]=0;
		arrayf[i]=0;
	}

	for(i=1;i<(graph1->size)+1;i++)
	{
		if(arrayc[i]=='w')
		{	
			dfsvisit(graph1,i);
		}
	}	
}

void dfsvisit1(struct graph* graph1, int x)
{	
	t++;
	arrayd[x]=t;
	arrayc[x]='g';
	struct adjlistnode* travel1=graph1->array[x].head;
	while(travel1!=NULL)
	{

		if(arrayc[travel1->value]=='w')
		{
			dfsvisit1(graph1, travel1->value);
		}
		travel1=travel1->next;
	}

	arrayc[x]='b';
	t++;
	arrayf[x]=t;
	printf("%d ",x);
}

void dfs1(struct graph* graph1)
{	

	struct linkedlist* l3=start;
	int n;
	for(n=1;n<(graph1->size)+1;n++)
	{
		arrayc[n]='w';
		arrayf[n]=0;
		arrayd[n]=0;
		arrayv[n]=0;
	}

	while(l3!=NULL)
	{
		if(arrayc[l3->data]=='w')
		{	
			dfsvisit1(graph1,l3->data);
			printf("\n");
		}
		l3=l3->next;

	}
	
}

void scc(struct graph* graph1,struct graph* graph2)
{	
	dfs(graph1);
	struct linkedlist* l3=start;
	dfs1(graph2);
	
}




int main()
{	
	start=NULL;
	int size,c,i,vertex1,vertex2;
	scanf("%d",&size);
	struct graph* graph1=newgraph(size);
	struct graph* graph2=newgraph(size);
	scanf("%d",&c);
	for(i=0;i<c;i++)
	{
		scanf("%d %d",&vertex1,&vertex2);
		addedge(graph1,vertex1,vertex2);
		addedge(graph2,vertex2,vertex1);
	}
	scc(graph1,graph2);

	return 0;

}

#include <stdio.h>
#include <stdlib.h>


char arrayc[100000]={'w'};
int arrayd[100000]={0};


struct Queue
{
	int head1, tail,size1;
	int *array1;
	int capacity;
};

struct Queue* create(int capacity)
{
	struct Queue* queue=(struct Queue *)malloc(sizeof(struct Queue));
	queue->capacity=capacity;
	queue->array1=(int *)malloc(queue->capacity*sizeof(int));
	queue->head1=queue->size1=0;
	queue->tail=capacity-1;
	return queue;
}

int isFull(struct Queue* queue)
{
	return(queue->size1==queue->capacity);
}

int isEmpty(struct Queue* queue)
{
		return (queue->size1==0);
}

void enqueue(struct Queue* queue, int x)
{
	if(isFull(queue))
		return;
	
	queue->tail=(queue->tail+1)%queue->capacity;
	queue->array1[queue->tail]=x;
	queue->size1=queue->size1 +1;


	
}

int dequeue(struct Queue* queue)
{
	
	
		int item=queue->array1[queue->head1];
		queue->head1=(queue->head1 +1)%queue->capacity;
		queue->size1=(queue->size1)-1;
		return (item);
		

	

}

struct adjlistnode
{
	int value;
	struct adjlistnode* next;
	char color;
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
	graph1->array=(struct adjlist*)malloc(v*sizeof(struct adjlist));
	int i;
	for(i=0;i<v;i++)
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
	
	struct adjlistnode* node2=newnode(source);
	node2=newnode(source);
	node2->next=graph1->array[dest].head;
	graph1->array[dest].head=node2;
	
}

void printlist(struct graph* graph1)
{
	int j;
	for(j=0;j<(graph1->size);j++)
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

void bfs(struct graph* graph1, int s)
{
	int i;
	for(i=0;i<graph1->size;i++)
	{
		if(i!=s)
		{
			arrayc[i]='w';
			arrayd[i]=0;	
		}
		else
		{
			arrayc[i]='g';
			arrayd[i]=0;
		}
		
	}
	struct Queue* queue = create(50000);
	enqueue(queue,s);
	
	while(queue->size1!=0)
	{	
		int u;
		u=dequeue(queue);
		struct adjlistnode* travel=graph1->array[u].head;
		while(travel!=NULL)
		{	
			
			if(arrayc[travel->value]=='w')
			{	
				arrayc[travel->value]='g';
				arrayd[travel->value]=arrayd[u]+1;
				enqueue(queue,travel->value);
			}
			travel=travel->next;
			
		}
		arrayc[u]='b';
	}


}

int main()
{
    int N,M,p,q,r,s;
    scanf("%d %d",&N,&M);
    struct graph* graph1=newgraph(N);
    for(p=0;p<M;p++)
    {
    	scanf("%d %d",&q,&r);
    	addedge(graph1,q,r);
    }
    
    bfs(graph1,0);
    return 0;
}

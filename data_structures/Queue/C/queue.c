#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXQUEUE 1000

struct queue
{
	int items[MAXQUEUE];
	int front;
	int rear;
};

void choices()
{
	printf("\nAvailable choices are\n\n");
	printf("1: \tTo insert/push into the queue.\n");
	printf("2: \tTo return the first inserted/pushed element from the queue and delete it.\n");
	printf("3: \tTo return the first inserted/pushed element into the queue without deleting it.\n");
	printf("4: \tTo find whether queue is empty or not.\n");
	printf("-1: \tTo exit.\n\n");
}

void push(struct queue *q,int val)
{
	if((*q).rear==MAXQUEUE-1)
	{
		printf("Queue is full.\n");
	}
	else
	{
		(*q).rear++;
		(*q).items[(*q).rear]=val;
	}
	
}

int pop(struct queue *q)
{
	if((*q).front>(*q).rear)
	{
		printf("Queue is empty.\n");
		return -1;
	}

	return (*q).items[(*q).front++];
}

int firstel(struct queue q)
{
	int v = q.items[q.front];
	return v;
}


int main()
{
	struct queue q;
	q.front=0;
	q.rear=-1;
	choices();
	int ch;
	scanf("%d",&ch);
	while(ch!=-1)
	{
		if(ch==1)
		{
			printf("Enter the element to be inserted/pushed into the queue. \t");
			int val;
			scanf("%d",&val);
			push(&q,val);
			printf("pushed %d into the queue.\n",val);
		}

		else if(ch==2)
		{
			if(q.front>q.rear)
			{
				printf("Empty queue.\n");
			}	
			else
			{
				printf("first inserted/pushed element into the queue is: \t");	
				printf("%d\n",pop(&q));
				
			}
		}

		else if(ch==3)
		{
			if(q.front>q.rear)
			{
				printf("Empty queue\n");
			}
			else
			{
				printf("first inserted/pushed element into the queue is: \t");
				printf("%d\n",q.items[q.front]);
			}
		}

		else if(ch==4)
		{
			if(q.front>q.rear)
			{
				printf("The queue is empty.\n");
			}
			else
			{
				printf("Queue is not empty.\n");
			}
		}

		else
		{
			printf("None of the mentioned choices matches the input.\n");
			choices();
		}
		printf("\n\nEnter your choice: \t");
		scanf("%d",&ch);

	}

	return 0;
}

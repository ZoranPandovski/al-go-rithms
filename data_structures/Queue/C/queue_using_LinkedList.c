#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
	int data;
	struct node *next;
};

void choices()
{
	printf("You have the following choices.\n");
	printf("1: \tTo insert/push into the queue.\n");
	printf("2: \tTo pop/extract from the queue and delete it.\n");
	printf("3: \tTo return the first element without deleting it.\n");
	printf("4: \tTo print the queue.\n");
	printf("5: \tTo check whether the queue is empty.\n");
	printf("-1: \tTo quit.\n\n");
}

struct node *make(int x)
{
	struct node *p = (struct node *)malloc(sizeof(struct node));
	p->data=x;
	p->next=NULL;
	return p;
}

struct node *push(struct node *head,int x)
{
	struct node *temp=head;
	struct node *newnode = make(x);

	if(head==NULL)
	{
		head=newnode;
	}

	else
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newnode;
	}
	return head;
}

struct node *pop(struct node *head)
{
	if(head==NULL)
	{
		printf("\nThis operation requires a non-empty queue.\n");
		printf("Can't pop from an empty queue.\n");
		printf("Choose a valid operation from above mentioned ones..\n\n");
	}

	else
	{
		struct node *temp=head;
		head=head->next;
		printf("\nDeleted the first element. Its value was: \t");
		printf("%d\n\n",temp->data);
		return head;
	}
}

struct node *firstel(struct node *head)
{
	return head;
}

void printfun(struct node *head)
{
	if(head==NULL)
	{
		printf("\nEmpty queue. No element to be printed.\n\n");
		printf("Choose a valid choice from the above mentioned ones.\n");
	}
	else
	{
		printf("\nQueue is.\n\n");
		while(head!=NULL)
		{
			printf("%d ",head->data);
			head=head->next;
		}
		printf("\n\n");
	}
}

bool isempty(struct node *head)
{
	if(head==NULL) return true;
	else return false;
}


int main()
{
	printf("\n\nProgram to implement queue with the use of linked list.\n\n\n\n");
	struct node *head;
	head=NULL;
	int d;
	int ch;
	choices();
	scanf("%d",&ch);
	while(ch!=-1)
	{
		if(ch==1)
		{
			printf("\nEnter the element to insert/push into the queue: \t");
			int val;
			scanf("%d",&val);
			head=push(head,val);
			printf("\ninserted/pushed %d into the queue: \n\n",val);
		}

		else if(ch==2)
		{
			if(head==NULL)
			{
				printf("\nThis operation requires a non-empty queue.\n");
				printf("Can't pop from an empty queue.\n");
				printf("Choose a valid operation from above mentioned ones..\n\n");
			}
			else
			{
				head=pop(head);
			}
		}

		else if(ch==3)
		{
			struct node *p=firstel(head);
			if(p==NULL)
			{
				printf("\nEmpty queue.\n");
				printf("Choose a valid operation.\n\n");
			}
			else
			{
				printf("\nFirst element in the queue is: \t");
				printf("%d\n\n",p->data);
			}
		}

		else if(ch==4)
		{
			printfun(head);
		}

		else if(ch==5)
		{
			if(head==NULL) printf("\nThe queue is empty.\n\n");
			else printf("\nThe queue is not empty.\n\n");
		}

		else
		{
			printf("\nNone of the choices matches with your entered value.\n");
			printf("Please choose a valid choice from these.\n\n");
			choices();
		}
		printf("Enter your choice. \t");
		scanf("%d",&ch);
	}
	return 0;
}

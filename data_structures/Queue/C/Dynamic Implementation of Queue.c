/**********************************************************************************************************
TITLE: Dynamic Implementation of Queue.
**********************************************************************************************************/

#include<stdio.h>
#include<stdlib.h>
//#define NULL
typedef struct node
{

    int data;
    struct node *next;

}Node;

typedef struct
{

    Node *front,*rear;

}QueueLL;

void enqueue(QueueLL *ptr,int x)
{

    Node *p;
    p=(Node*)malloc(sizeof(Node));
    p->data=x;
    p->next=NULL;
    if(ptr->rear==NULL)
    {

        ptr->rear=ptr->front=p; //if this is a first node

    }
    else
    {

        ptr->rear->next=p;
        ptr->rear=p;

    }

}

int dequeue(QueueLL *ptr)
{

    Node *q;
    //if(ptr->front==NULL)
    if(isEmpty(ptr))
    {

        printf("Queue is empty.\n");
        return -1;

    }
    else

    {
        int x;
        q = ptr->front;
        x = q->data;
        ptr ->front = ptr->front->next;
        if(ptr->front == NULL)
        {
            ptr->rear = NULL; //to avoid dangling pointer
        }
        free(q);
        return x;

    }

}

void display(QueueLL temp)
{

    Node *q;
    for(q = temp.front; q != NULL; q= q->next)
    {
        printf("%d\n",q->data);
    }

}

int peek(QueueLL *ptr)
{
    if (ptr->front==NULL)
        printf("Queue is empty.\n");
    else
        return ptr->front->data;
}

int size(QueueLL *ptr)
{
    Node *p=ptr->front;
    int i=0;
    if(p == NULL)
    {
        return i;
    }
    else
    {
        while(p!=NULL)
        {
            i++;
            p=p->next;

        }
      return i;

    }
}
int isEmpty(QueueLL *ptr)
{

if(ptr->front==NULL)
    return 1;
else
    return 0;
}

int main()
{

    QueueLL q;
    int ch,num;
    q.front=NULL;
    q.rear=NULL;
    while(1)
    {
        printf("Enter your choice:");
        printf("\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n5.Exit\n\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter the element to insert in the queue:\n");
                scanf("%d",&num);
                enqueue(&q,num);
                break;

            case 2:
                printf("The deleted element is %d.\n",dequeue(&q));
                break;

            case 3:
                printf("The element at the front of the queue is %d.\n",peek(&q));
                break;

            case 4:
                printf("The queue elements are:\n");
                display(q);
                printf("Size of the queue is : %d \n\n",size(&q));
                break;

            default:
                printf("Invalid choice.\n");
                exit(0);

        }

    }
    return 0;

}
/**********************************************************************************************************
OUTPUT:
Enter your choice:
1.Enqueue
2.Dequeue
3.Peek
4.Display
5.Exit
2
Queue is empty.
The deleted element is -1.
Enter your choice:
1.Enqueue
2.Dequeue
3.Peek
4.Display
5.Exit
1
Enter the element to insert in the queue:
38
Enter your choice:
1.Enqueue
2.Dequeue
3.Peek
4.Display
5.Exit
1
Enter the element to insert in the queue:
44
Enter your choice:
1.Enqueue
2.Dequeue
3.Peek
4.Display
5.Exit
1
Enter the element to insert in the queue:
54
Enter your choice:
1.Enqueue
2.Dequeue
3.Peek
4.Display
5.Exit
1
Enter the element to insert in the queue:
60
Enter your choice:
1.Enqueue
2.Dequeue
3.Peek
4.Display
5.Exit
2
The deleted element is 38.
Enter your choice:
1.Enqueue
2.Dequeue
3.Peek
4.Display
5.Exit
3
The element at the front of the queue is 44.
Enter your choice:
1.Enqueue
2.Dequeue
3.Peek
4.Display
5.Exit
4
The queue elements are:
44
54
60
Enter your choice:
1.Enqueue
2.Dequeue
3.Peek
4.Display
5.Exit
5
Invalid choice.
Process returned 0
**********************************************************************************************************/

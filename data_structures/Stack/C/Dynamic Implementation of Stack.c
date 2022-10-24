/**********************************************************************************************************
TITLE:  Dynamic Implementation of Stack.
**********************************************************************************************************/
#include<stdio.h>
#include<stdlib.h>
//#define NULL
typedef struct node
{

    int info;
    struct node *next;

}Node;

typedef struct
{

    Node *tos;

}StackLL;

void push(StackLL *ptr, int x)
{

    Node *p;
    p=(Node *)malloc(sizeof(Node));
    p->info=x;
    if(ptr->tos == NULL )
    {

        ptr->tos=p; //tos = p
        p->next = NULL;

    }
    else
    {

        p->next=ptr->tos; //p->next = tos
        ptr->tos=p; //tos = p, newly created node becomes top of the stack
    }
}

int pop(StackLL *ptr)
{

    Node *p;
    int x;

    if(ptr->tos== NULL )
    {

        printf("Stack underflow\n");
        return;

    }
    else
    {

        p=ptr->tos; //p is pointer pointing to top of the stack
        x=p->info; //store its data to
        ptr->tos=p->next; //tos = tos->next
        free(p); //release the memory pointed by p
        return x;

    }

}

int peek(StackLL *ptr)
{

    if( ptr->tos== NULL)
    {
        printf("Stack underflow\n");
        exit(-1);
    }
    else
        return ptr->tos->info;
}

int size(StackLL *ptr)
{
    Node *p=ptr->tos;
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
void display(StackLL s)
{

    Node *p;
    p=s.tos;
    printf("The Stack is :\n");
    while(p!=NULL)
    {

        printf("%d\n",p->info);
        p=p->next;

    }

}

int main()
{

    int choice,ele;
    StackLL s1; //stack s1 created using LL
    s1.tos= NULL ; //Initially no node
    do
    {

        printf("\nEnter your choice : 1.Insert Data 2.Delete Data 3.Data at the top of the stack 4.Display 5.Exit\n");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1 :
            printf("Enter the element to be added to the stack using Linked List :\n");
            scanf("%d",&ele);
            push(&s1,ele);
            break;

        case 2 :
            printf("The Popped element is :\n%d",pop(&s1));
            break;

        case 3:
            printf("The element at the top of the stack is :\n%d",peek(&s1));
            break;

        case 4 :
            display(s1);
            printf("\nSize of the stack is : %d",size(&s1));
            break;

        }

    }while (choice!=5);

    return 0;

}

/**********************************************************************************************************
OUTPUT:
Enter your choice : 1.Insert Data 2.Delete Data 3.Data at the top of the stack 4.Display 5.Exit
1
Enter the element to be added to the stack using Linked List :
38
Enter your choice : 1.Insert Data 2.Delete Data 3.Data at the top of the stack 4.Display 5.Exit
1
Enter the element to be added to the stack using Linked List :
44
Enter your choice : 1.Insert Data 2.Delete Data 3.Data at the top of the stack 4.Display 5.Exit
1
Enter the element to be added to the stack using Linked List :
54
Enter your choice : 1.Insert Data 2.Delete Data 3.Data at the top of the stack 4.Display 5.Exit
1
Enter the element to be added to the stack using Linked List :
60
Enter your choice : 1.Insert Data 2.Delete Data 3.Data at the top of the stack 4.Display 5.Exit
2
The Popped element is :
60
Enter your choice : 1.Insert Data 2.Delete Data 3.Data at the top of the stack 4.Display 5.Exit
3
The element at the top of the stack is :
54
Enter your choice : 1.Insert Data 2.Delete Data 3.Data at the top of the stack 4.Display 5.Exit
4
The Stack is :
54
44
38
Enter your choice : 1.Insert Data 2.Delete Data 3.Data at the top of the stack 4.Display 5.Exit
5
Process returned 0
**********************************************************************************************************/


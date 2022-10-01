///Added by - Shakti Prasad Nanda , username - https://github.com/shakti-01
/* This algorithm uses the 2 stacks to create a queue with the functionality of a queue as well.
The only difference is that it uses 2 stacks to achieve this*/
#include<stdio.h>
#include<stdlib.h>
void insert(int);
void del();
void display();
void push1(int);
void push2(int);
int pop1();
int pop2();
int stack1[20],top1=-1,stack2[20],top2=-1,size;
main()
{
    int item,choice;
    printf("Enter the size of the queue: ");
    scanf("%d",&size);
    while(1)
    {
         printf("\nEnter the task you want to perform:\n1.Insert\n2.Delete\n3.Display\n4.EXIT\n");
         scanf("%d",&choice);
         switch(choice)
         {
             case 1: insert(item);
                     break;
             case 2: del();
                     break;
             case 3: display();
                     break;
             case 4: exit(0);
             default: printf("WRONG CHOICE !!");
         }
    }
}
void insert(int item)
{
    if(top1==size-1)
    {
        printf("Queue overflow");
    }
    else
    {
        printf("Enter the item you want to insert: ");
        scanf("%d",&item);
        push1(item);
    }
}
void del()
{
    int item;
    if(top1==-1)
    {
        printf("Queue underflow");
    }
    else
    {
        while(top1!=-1)
        {
            push2(pop1());
            top1--;
        }

        item=stack2[top2];
        top2--;
        printf("Deleted item: %d",item);
        while(top2!=-1)
        {
            push1(pop2());
            top2--;
        }
    }
}
void display()
{
    int i,item,n;
    if(top1==-1)
    {
        printf("Queue underflow");
    }
    else
    {
        printf("\nThe queue is\n");
        for(i=0;i<=top1;i++)
        {
            printf("%d  ",stack1[i]);
        }
    }
}
void push1(int item)
{
    if(top1==size-1)
    {
        printf("queue overflow");
    }
    else
    {
        top1++;
        stack1[top1]=item;
    }
}
void push2(int item)
{
     if(top2==size-1)
    {
        printf("queue overflow");
    }
    else
    {
        top2++;
        stack2[top2]=item;
    }
}
int pop1()
{
    if(top1==-1)
    {
        printf("queue underflow");
    }
    else
    {
        return stack1[top1];
    }
}
int pop2()
{
    if(top2==-1)
    {
        printf("queue underflow");
    }
    else
    {
        return stack2[top2];
    }
}




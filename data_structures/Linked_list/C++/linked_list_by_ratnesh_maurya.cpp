/*
Author: Ratnesh Maurya
Concept: Linked list implementation
All rights reserved
Github: https://github.com/ratnesh-maurya
*/





#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
    int data;
    struct node *next;
};
struct node *start=NULL;
struct node *create_ll(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *insert_before(struct node *);
struct node *insert_after(struct node*);
struct node *delete_beg(struct node*);
struct node *delete_end(struct node*);
struct node *delete_before(struct node*);
struct node *delete_after(struct node*);
int main()
{
int option;
 do
   { 
printf("\n\n *****MAIN MENU *****");
printf("\n 1: Create a list");
printf("\n 2: Display the list");
printf("\n 3: Add a node at the beginning");
printf("\n 4: Add a node at the end");
printf("\n 5: Add a node before a given node");
printf("\n 6: Add a node after a given node");
printf("\n 7: Delete a node from the beginning");
printf("\n 8:delete a node from beginning ");
printf("\n 9:delete a node from end ");
printf("\n 10:delete a node before a given node");
printf("\n 11:delete a node after a given node");
printf("\n\n Enter your option : ");
scanf("%d", &option); 
     switch(option)
        {
                case 1: start = create_ll(start);
                break;
                case 2: start = display(start);
                break;
                case 3: start = insert_beg(start);
                break;
                case 4: start = insert_end(start);
                break;
                case 5: start = insert_before(start);
                break;
                case 6: start = insert_after(start);
                break;
                case 8: start =delete_beg(start);
                break;
                case 9: start =delete_end(start);
                break;
                case 10: start =delete_before(start);
                break;
                case 11: start =delete_after(start);
                break;


        }
   }
    while(option !=12);
    return 0;
}

struct node *create_ll(struct node *start)
{
    struct node *new_node,*ptr;
    int num;
    printf("enter -1 to end\n");
    printf(" enter the value of data:");
    scanf("%d", &num);
    while(num!=-1 )
    { 
         new_node = (struct node*)malloc(sizeof (struct node));
         new_node -> data=num;
         if(start==NULL)
         {
             new_node -> next = NULL;
             start = new_node;
         }
         else
         {
             ptr = start;
             while (ptr->next!=NULL)
             ptr = ptr->next;
             ptr->next = new_node;
             new_node->next = NULL;
         }
         printf("\nenter the value of data : ");
         scanf("%d",&num);
             
         }
            return start;
}
struct node *display(struct node *start)
{
    struct node *ptr;
    ptr=start;
    while(ptr!= NULL)
    {
    printf("\t%d",ptr->data);

        ptr = ptr->next;
    }

    return start;
}
struct node *insert_beg(struct node *start)
{
     struct node *new_node;
     int num;
     new_node=(struct node *)malloc(sizeof(struct node));
     printf("\n enter the data inserted at beg:");
     scanf("%d", &num );
     new_node->data=num;
     new_node->next=start;
     start=new_node;
      display(start);
     return start;
     
}
struct node *insert_end(struct node *start)
{
    struct node *new_node,*ptr;
    int num;
    new_node=(struct node*)malloc(sizeof(struct node));
     printf("\n enter the data inserted at end :");
     scanf("%d", &num );
     new_node->data=num;
     new_node->next=NULL;
     ptr=start;
     while(ptr->next!=NULL)
     ptr=ptr->next;
     ptr->next=new_node;
     display(start);
     return start;
}
struct node *insert_before(struct node *start)
{ 
        struct node *new_node,*ptr,*preptr;
        int num, val;
        new_node=(struct node*)malloc(sizeof(struct node));
        printf("\nenter the data before which the newnode is to be inserted:");
        scanf("%d",&val);
        printf("\nenter the data;");
        scanf("%d", &num);
        new_node->data=num;
        ptr=start;
        while(ptr->data!=val)
        { 
        preptr=ptr;
        ptr=ptr->next;
        }
        preptr->next=new_node;
        new_node->next=ptr;
        display(start);
        return start;
}
struct node*insert_after(struct node *start)
{
    struct node *new_node,*ptr;
    int num,val;
    new_node=(struct node*)malloc(sizeof(struct node));
    printf("\nenter the value after which data is inserted:");
    scanf("%d", &val);
    printf("\n enter the value of data which is to be inseted");
    scanf("%d",&num);
    new_node->data=num;
    ptr=start;
    while (ptr->data!=val)
    { ptr=ptr->next;
    }
      new_node->next=ptr->next;
      ptr->next=new_node;
      display(start);
      return start;
}
struct node*delete_beg(struct node *start)
   {
    struct node *ptr;
    ptr=start;
    start=start->next;
    free(ptr);
    display(start);
    return start;
   }   
struct node*delete_end(struct node *start)     
{
    struct node *ptr,*preptr;
    ptr=start;
    while(ptr->next!=NULL)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=NULL;
    free(ptr);
    return start;
}
struct node*delete_before(struct node *start)
{
    struct node *ptr,*preptr;
    int val;
    printf("\n enter the value of node before node to be deleted:");
    scanf("%d",&val);
    ptr=start;
      while (ptr->next->data!=val)
     {
        preptr=ptr;
        ptr=ptr->next;
     }
     preptr->next=ptr->next;
     free(ptr);
     display(start);
}
struct node*delete_after(struct node *start)
{
    struct node *ptr,*preptr;
    int val;
    printf("\n enter the value of node after node to be deleted:");
    scanf("%d",&val);
    ptr=start;
    preptr=ptr;
    while (preptr->data!=val)
    {
        preptr=ptr;
       ptr=ptr->next;
    }
    preptr->next=ptr->next;
    free(ptr);
    display(start);
    return(start);
}
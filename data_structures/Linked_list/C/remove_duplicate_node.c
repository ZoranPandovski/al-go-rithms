#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node
{
    int data ;
    struct node *next;
};

struct node *create_ll(struct node *start)
{
    struct node *new_node,*ptr;
    int num;
    
    printf("\n Enter -1 to stop creating");
    printf("\n ENTER the Data : ");
    scanf("%d",&num);
    while (num!=-1)
    {
        new_node= (struct node*)malloc(sizeof(struct node));
        new_node->data=num;
        if (start==NULL)
        {
            new_node->next=NULL;
            start=new_node;
        }
        else
        {
            ptr = start;
            while (ptr->next!=NULL)
            ptr=ptr->next;
            ptr->next=new_node;
            new_node->next=NULL;    
        }
        printf(" Enter the Data : ");
        scanf("%d",&num);
    }
    return start;
}

struct node *display(struct node *start)
{
    struct node *ptr;
    ptr = start;
    int count =0;
    while(ptr != NULL)
    {
        count = count +1;
        printf("\t%d", ptr -> data);
        ptr=ptr->next;
    }
    printf("\n NUMBER OF NODES==  %d",count);
    return start;
} 
void removeDuplicates(struct node* start)
{
    struct node *ptr1, *ptr2, *dup;
    ptr1 = start;
 
    
    while (ptr1 != NULL && ptr1->next != NULL) {
        ptr2 = ptr1;
 
        
        while (ptr2->next != NULL) {
        
            if (ptr1->data == ptr2->next->data) {
        
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                free(dup);
            }
            else
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}  

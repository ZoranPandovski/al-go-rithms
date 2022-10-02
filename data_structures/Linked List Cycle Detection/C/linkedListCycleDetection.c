#include <stdio.h>
#include <stdlib.h> /* is included because malloc is a library function and will show warning if this is not included */
struct node
{
    int data;
    struct node* next;
};

//the function that will detect loop in the linked list
void detectLoop(struct node* head){
    
    struct node* fast;
    struct node* slow;
    
    
    fast = head;
    slow = head;
    
    while (fast != NULL || slow != NULL)
{
    fast = fast -> next -> next; //runs two units
    slow = slow -> next; //runs one units
    
    if (fast == slow)
    {
        printf ("There is a loop in the linked list\n");
        break;
    }
    
    
}
}

void main ()
{
    struct node* head = NULL;
    struct node* temp = NULL;
    struct node* temp1 = NULL;
    struct node* temp2 = NULL;
    struct node* temp3 = NULL;
    struct node* temp4 = NULL;
    struct node* temp5 = NULL;
    
    
    
    
    
    temp = (struct node*)malloc(sizeof(struct node));
    temp1 = (struct node* )malloc(sizeof(struct node));
    temp2 = (struct node* )malloc(sizeof(struct node));
    
    temp3 = (struct node* )malloc(sizeof(struct node));
    
    temp4 = (struct node* )malloc(sizeof(struct node));
    
    temp5 = (struct node* )malloc(sizeof(struct node));
    
    temp -> data = 10;
    temp -> next = temp1;
    
    head = temp;
    
    temp1 -> data = 14;
    temp1 -> next = temp2;
    
    temp2 -> data = 22;
    temp2 -> next = temp3;
    
    
    temp3 -> data = 42;
    temp3 -> next = temp4;
    
    temp4 -> data = 4;
    temp4 -> next = temp5;
    
    temp5 -> data = 54;
    head -> next -> next -> next -> next = head -> next; //This is the point where we created a loop in the Linked List
 

detectLoop(head);
  
}

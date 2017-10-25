#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

void printList(node *n)
{
    while(n!=NULL)
    {
        printf("%d ", n->data);
        n = n->next;
    }
}

node* newNode()
{
    node* new_node = (node*)malloc(sizeof(node));

    return new_node;
}
//To add new node at starting of the list
void push(node** head, int new_data)
{

    node* new_node = newNode();

    new_node->data = new_data;

    new_node->next = *head ;

    *head = new_node;

    return;
}

//insert after a particular position
void insertAfter (node* previous, int new_data)
{
    if(previous==NULL)
        return;

    node* new_node = newNode();

    new_node->data=new_data;

    new_node->next = previous->next;

    previous->next = new_node;

    return ;
}

//add a new node at the end of the list
void append(node** head, int data)
{
    node* new_node= newNode();

    new_node->data = data;

    new_node->next = NULL;

    //if the list is empty
    if(*head==NULL)
    {
        *head = new_node;
        return;
    }

    node* current = *head;

    while(current->next != NULL)
    {
        current = current->next;
    }

    current->next = new_node;

    return ;
}

//given a key delete a node
void deleteNode (node** head, int key)
{
    node* current=*head, *previous;

    //if the key is in head
    if(current!=NULL && current->data==key)
    {
        *head = current->next;
        free(current);
    }

    while(current != NULL && current->data != key)
    {
        previous = current;
        current = current->next;
    }

    if(current != NULL && current->data==key)
    {
        previous->next = current->next;
        free(current);
    }


    return;
}

//delete a node at a given position
void deleteNodePosition(node** head, int position)
{
    node* current=*head;

    //if head is to be removed
    if(position==0)
    {
        *head= (*head)->next; // *head=current->next;
        free(current);
        return;
    }

    int i;

    //till the previous node of the node to be deleted
    for(i=0; i<position-1 && current!=NULL ; i++ )
        current = current->next;

    if(current==NULL || current->next==NULL)
        return;

    node* next=current->next;

    current->next = current->next->next;

    free(next);

    return;
}

//finding length of linked list
int getCount(node* head)
{
    node *current=head;

    int count=0;

    while(current!=NULL)
    {
        current=current->next;
        count++;
    }

    return count;

 /*recursive function will be like

 if(current==NULL)
    return 0;

 return 1+getCount(current->next);

 */

}

void deleteFirst(node** head)
{
    /*
    1. Never make head a global pointer it has many disadvantages.
        Its value can be changed at any position in the project.
    2.Change the head pointer and then return it.
        Its better but it has certain problem if we forget to assign the value to head again.
        #head = deleteFirst(node* head) //correct way
        #deleteFirst(node* head) //compiler allows it but it is wrong
    3.Send address of the head pointer as an argument
        Its considered the best option.
    */

    node* temp=*head;

    *head=(*head)->next;

    free(temp);

    return;

}

//swapping two nodes without changing the data field and only changing links
void swapNodes(node** head, int x, int y)
{

    if(x==y)
        return;

    node *prevX=NULL, *currX=*head, *prevY=NULL, *currY=*head;

    while( (currY != NULL && currY->data!=y) || (currX != NULL && currX->data !=x) )
    {
        if(currY->data!=y && currY != NULL)
        {
            prevY=currY;
            currY=currY->next;
        }

        if(currX->data!=x && currX != NULL)
        {
            prevX=currX;
            currX=currX->next;
        }

    }

    if(currX==NULL || currY==NULL)
        return;

    if(prevX!=NULL)
        prevX->next=currY;

    else
        *head=currY;

    if(prevY!=NULL)
        prevY->next=currX;

    else
        *head=currX;

    node* temp= currY->next;
    currY->next=currX->next;
    currX->next=temp;

    return;

}

//reverse the linked list
void reverse(node** head)
{
	node *previous=NULL, *current=*head, *ahead;

	while(current != NULL)
	{
		ahead=current->next;
		current->next=previous;
		previous=current;
		current=ahead;
	}

	*head=previous;

	return;
}

//merge two sorted linked list
node* sortedMerge(node* a, node* b)
{
	node* curr1=a, *curr2=b, *head, *result;

	if(a==NULL)
		return b;

	else if(b==NULL)
		return a;

	if( (a->data) > (b->data) )
	{
		head=b;
		curr2=curr2->next;
	}
	else
	{
		head=a;
		curr1=curr1->next;
	}

	result=head;
	//printf("result=%d", result->data);


	while(curr1 != NULL && curr2 !=NULL)
	{
		if( (curr1->data) > (curr2->data) )
		{
			result->next = curr2;
			curr2=curr2->next;
		}
		else
		{
			result->next = curr1;
			curr1=curr1->next;
		}
		result=result->next;
		//printf("result=%d", result->data);
	}

	if(curr1 == NULL)
		result->next=curr2;
	else
		result->next=curr1;

	return head;

}

node* getMiddle(node* head)
{
    node* fast=head, *slow=head;

    if(head != NULL)
    {
        while(fast!=NULL && fast->next != NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
    }


    return slow;
}


// Floyd's Cycle finding algorithm
// also known as tortoise and hare algo
int detectLoop(node* head)
{
    node* slow=head, *fast=head;

    while(fast!=NULL && fast->next != NULL)
    {

        fast=fast->next->next;
        slow=slow->next;

        if(fast==slow)
            return 1;
    }

    return 0;
}

// the list is already sorted and inserting a value in it in sorted way
void sortedInsert(node** head, int value)
{

    node* temp = newNode();

    temp->data=value;


    if(*head==NULL || (*head)->data>value )
    {
        temp->next=*head;
        *head=temp;
        return ;
    }

    node* current=*head, *previous=*head;


    while(current!=NULL && value>current->data )
    {
        previous=current;
        current=current->next;
    }

    previous->next=temp;
    temp->next=current;

    return ;

}

void pairWiseSwap(node* head)
{

    node* previous=head, *current=head->next;
    int temp;

    while(previous!=NULL && current!=NULL)
    {
        temp=previous->data;
        previous->data=current->data;
        current->data=temp;

        previous=current->next;
        current=previous->next;
    }

    return;



}


node* sortedIntersect(node* head1, node* head2)
{

    node* curr1=head1, *curr2=head2;
    node* head=NULL;
    while(curr1 != NULL && curr2 != NULL)
    {


        if(curr1->data==curr2->data)
        {
            append(&head, curr1->data);
            curr1=curr1->next;
            curr2=curr2->next;
        }

        else if(curr1->data > curr2->data)
        {
            curr2=curr2->next;
        }
        else
        {
            curr1=curr1->next;
        }
    }
    return head;

}
struct node *reverseparticular (struct node *head, int k)

{ 
  struct node* current=head;
 
   struct node* prev=NULL;
  struct node* after=NULL;
  //it will reverse the linked list to every key nodes entered by the user
  int x=1;
 
 while(current!=NULL&&x<=k)
 
 {
     after=current->next;
 
       current->next=prev;
  
       prev=current;
    
       current=after;
    
       x++;

   }
  
if(after!=NULL)
 
   head->next=reverse(after,k);
 
 
  return prev;
 


}
int main()
{
     struct node* a = NULL;
  struct node* b = NULL;
  struct node *intersect = NULL;

  /* Let us create the first sorted linked list to test the functions
   Created linked list will be 1->2->3->4->5->6 */
  push(&a, 6);
  push(&a, 5);
  push(&a, 4);
  push(&a, 3);
  push(&a, 2);
  push(&a, 1);

  /* Let us create the second sorted linked list
   Created linked list will be 2->4->6->8 */
  push(&b, 8);
  push(&b, 6);
  push(&b, 4);
  push(&b, 2);

  /* Find the intersection two linked lists */
  intersect = sortedIntersect(a, b);

  printf("\n Linked list containing common items of a & b \n ");
  printList(intersect);

    return 0;
}

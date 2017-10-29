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
  //it will reverse the linked list to every key nodes entered by the users
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
//add two list//
struct Node* addTwoLists (struct Node* first, struct Node* second)
{
    struct Node* res = NULL; // res is head node of the resultant list
    struct Node *temp, *prev = NULL;
    int carry = 0, sum;
 
    while (first != NULL || second != NULL) //while both lists exist
    {
        // Calculate value of next digit in resultant list.
        // The next digit is sum of following things
        // (i)  Carry
        // (ii) Next digit of first list (if there is a next digit)
        // (ii) Next digit of second list (if there is a next digit)
        sum = carry + (first? first->data: 0) + (second? second->data: 0);
 
        // update carry for next calulation
        carry = (sum >= 10)? 1 : 0;
 
        // update sum if it is greater than 10
        sum = sum % 10;
 
        // Create a new node with sum as data
        temp = newNode(sum);
 
        // if this is the first node then set it as head of the resultant list
        if(res == NULL)
            res = temp;
        else // If this is not the first node then connect it to the rest.
            prev->next = temp;
 
        // Set prev for next insertion
        prev  = temp;
 
        // Move first and second pointers to next nodes
        if (first) first = first->next;
        if (second) second = second->next;
    }
 
    if (carry > 0)
      temp->next = newNode(carry);
 
    // return head of the resultant list
    return res;
}
int detectAndRemoveLoop(struct Node *list)
{
    struct Node  *slow_p = list, *fast_p = list;
 
    while (slow_p && fast_p && fast_p->next)
    {
        slow_p = slow_p->next;
        fast_p  = fast_p->next->next;
 
        /* If slow_p and fast_p meet at some point then there
           is a loop */
        if (slow_p == fast_p)
        {
            removeLoop(slow_p, list);
 
            /* Return 1 to indicate that loop is found */
            return 1;
        }
    }
 
    /* Return 0 to indeciate that ther is no loop*/
    return 0;
}
 
/* Function to remove loop.
 loop_node --> Pointer to one of the loop nodes
 head -->  Pointer to the start node of the linked list */
void removeLoop(struct Node *loop_node, struct Node *head)
{
   struct Node *ptr1;
   struct Node *ptr2;
 
   /* Set a pointer to the beging of the Linked List and
      move it one by one to find the first node which is
      part of the Linked List */
   ptr1 = head;
   while (1)
   {
     /* Now start a pointer from loop_node and check if it ever
       reaches ptr2 */
     ptr2 = loop_node;
     while (ptr2->next != loop_node && ptr2->next != ptr1)
         ptr2 = ptr2->next;
 
     /* If ptr2 reahced ptr1 then there is a loop. So break the
        loop */
     if (ptr2->next == ptr1)
        break;
 
     /* If ptr2 did't reach ptr1 then try the next node after ptr1 */
     ptr1 = ptr1->next;
   }
 
   /* After the end of loop ptr2 is the last node of the loop. So
     make next of ptr2 as NULL */
   ptr2->next = NULL;
}
//to rotate a linked list after the given integral position
void rotate(struct node* head_ref,int k)
{
struct node* temp=*head_ref;
if(k==0)
return;
int count=1;
while(count<k&&temp->next!=NULL)
{
temp=temp->next;
count++;
}
if(temp=NULL)
return;
struct node* temp2=temp;
while(temp!=NULL)
{
temp=temp->next;
}
temp->next=(*head_ref);
(*head_ref)=temp2->next;
temp2->next=NULL;

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

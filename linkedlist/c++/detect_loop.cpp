// to check whether there is a loop in a linked list or not.
//using Floyd’s Cycle-Finding Algorithm
#include<iostream> 
using namespace std; 
  
/* Link list node */
struct Node 
{ 
    int data; 
    struct Node* next; 
}; 
  
void push(struct Node** head_ref, int new_data) 
{ 
    /* allocate node */
    struct Node* new_node = new Node; 
  
    /* put in the data  */
    new_node->data  = new_data; 
  
    /* link the old list off the new node */
    new_node->next = (*head_ref); 
  
    /* move the head to point to the new node */
    (*head_ref)    = new_node; 
} 
  
// Returns true if there is a loop in linked list 
// else returns false. 
bool detectLoop(struct Node *h) 
{ 
    if(h==NULL || h->next==NULL)
        return false;
    Node *slow, *fast;
    slow=h;
    fast=h->next;
    while(fast && fast->next && slow)
    {
    	fast=fast->next->next;
    	slow=slow->next;
    if(slow==fast)
    	return true;
    return false;
    }
} 
  

int main() 
{ 
    /* Start with the empty list */
    struct Node* head = NULL; 
  
    push(&head, 1); 
    push(&head, 2); 
    push(&head, 3); 
    push(&head, 4); 
  
    /* Create a loop for testing */
    head->next->next->next->next = head; 
  
    if (detectLoop(head)) 
        cout << "Loop found\n"; 
    else
        cout << "No Loop\n"; 
  
    return 0; 
} 

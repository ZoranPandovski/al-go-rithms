// to remove a loop if there is a loop in the linked list.
//using Floyd’s Cycle-Finding Algorithm
#include<iostream> 
using namespace std; 
  
struct Node 
{ 
    int key; 
    struct Node *next; 
}; 
  
void push(struct Node** head_ref, int new_data) 
{ 
    /* allocate node */
    struct Node* new_node = new Node; 
  
    /* put in the data  */
    new_node->key  = new_data; 
  
    /* link the old list off the new node */
    new_node->next = (*head_ref); 
  
    /* move the head to point to the new node */
    (*head_ref)    = new_node; 
} 
  
// A utility function to print a linked list 
void printList(Node *head) 
{ 
    while (head != NULL) 
    { 
        cout << head->key << " "; 
        head = head->next; 
    } 
    cout << endl; 
} 
  
// Function to detect and remove loop in a linked list that may contain loop 
void RemoveLoop(struct Node *head) 
{ 
    // If list is empty or has only one node 
    // without loop 
    if (head == NULL || head->next == NULL) 
        return; 
  
    Node *slow ,*fast; 
  
    // Move slow and fast 1 and 2 steps 
    // ahead respectively. 
    slow = head; 
    fast = head->next; 
  
    // Search for loop using slow and 
    // fast pointers 
    while (fast && fast->next && slow!=fast) 
    { 
        fast = fast->next->next; 
        slow = slow->next;
    } 
  
    /* If loop exists */
    if (slow == fast) 
    { 
        slow=head;
        if(fast->next==slow) //this handles if there is complete loop.
        {
            fast->next = NULL;
            return;
        }
        while (slow->next != fast->next) 
        { 
            slow = slow->next; 
            fast = fast->next; 
        } 
  
        /* since fast->next is the looping point */
        fast->next = NULL; /* remove loop */
    } 
} 
  
/* Driver program to test above function*/
int main() 
{ 
    /* Start with the empty list */
    struct Node* head = NULL; 
  
    push(&head, 1); 
    push(&head, 2); 
    push(&head, 3); 
    push(&head, 4); 
  
  
    /* A loop for testing */
    head->next->next->next->next = head; 
  
    RemoveLoop(head); 
  
    printf("Linked List after removing loop \n"); 
    printList(head); 
  
    return 0; 
} 
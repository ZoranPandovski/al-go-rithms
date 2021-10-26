// C++ implementation of rotating a linked list clockwise by k units.
#include <bits/stdc++.h> 
using namespace std; 

/* Link list node */
class Node { 
public: 
	int data; 
	Node* next; 
}; 

/* A utility function to push a node */
void push(Node** head_ref, int new_data) 
{ 
	/* allocate node */
	Node* new_node = new Node(); 

	/* put in the data */
	new_node->data = new_data; 

	/* link the old list off the new node */
	new_node->next = (*head_ref); 

	/* move the head to point to the new node */
	(*head_ref) = new_node; 
} 

/* A utility function to print linked list */
void printList(Node* node) 
{ 
	while (node != NULL) { 
		cout << node->data << " -> "; 
		node = node->next; 
	} 
	cout << "NULL"; 
} 

// Function that rotates the given linked list 
// clockwise by k and returns the updated 
// head pointer 
Node* rightRotate(Node* head, int k) 
{ 

	// If the linked list is empty 
	if (!head) 
		return head; 

	// len is used to store length of the linked list 
	// tmp will point to the last node after this loop 
	Node* tmp = head; 
	int len = 1; 
	while (tmp->next != NULL) { 
		tmp = tmp->next; 
		len++; 
	} 

	// If k is greater than the size 
	// of the linked list 
	if (k > len) 
		k = k % len; 

	// Subtract from length to convert 
	// it into left rotation 
	k = len - k; 

	// If no rotation needed then 
	// return the head node 
	if (k == 0 || k == len) 
		return head; 

	// current will either point to 
	// kth or NULL after this loop 
	Node* current = head; 
	int cnt = 1; 
	while (cnt < k && current != NULL) { 
		current = current->next; 
		cnt++; 
	} 

	// If current is NULL then k is equal to the 
	// count of nodes in the list 
	// Don't change the list in this case 
	if (current == NULL) 
		return head; 

	// current points to the kth node 
	Node* kthnode = current; 

	// Change next of last node to previous head 
	tmp->next = head; 

	// Change head to (k+1)th node 
	head = kthnode->next; 

	// Change next of kth node to NULL 
	kthnode->next = NULL; 

	// Return the updated head pointer 
	return head; 
} 

// Driver code 
int main() 
{ 

	/* The constructed linked list is: 
  1->2->3->4->5 */
	Node* head = NULL; 
	push(&head, 5); 
	push(&head, 4); 
	push(&head, 3); 
	push(&head, 2); 
	push(&head, 1); 

	int k = 2; 

	// Rotate the linked list 
	Node* updated_head = rightRotate(head, k); 

	// Print the rotated linked list 
	printList(updated_head); 

	return 0; 
} 

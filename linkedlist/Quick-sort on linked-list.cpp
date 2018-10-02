#include <iostream> 
#include <cstdio> 
using namespace std; 

struct Node 
{ 
	int data; 
	struct Node *next; 
}; 

void push(struct Node** head_ref, int new_data) 
{ 
	struct Node* new_node = new Node; 

	new_node->data = new_data; 

	new_node->next = (*head_ref); 

	(*head_ref) = new_node; 
} 

void printList(struct Node *node) 
{ 
	while (node != NULL) 
	{ 
		printf("%d ", node->data); 
		node = node->next; 
	} 
	printf("\n"); 
} 

struct Node *getTail(struct Node *cur) 
{ 
	while (cur != NULL && cur->next != NULL) 
		cur = cur->next; 
	return cur; 
} 

struct Node *partition(struct Node *head, struct Node *end, 
					struct Node **newHead, struct Node **newEnd) 
{ 
	struct Node *pivot = end; 
	struct Node *prev = NULL, *cur = head, *tail = pivot; 

	while (cur != pivot) 
	{ 
		if (cur->data < pivot->data) 
		{ 

			if ((*newHead) == NULL) 
				(*newHead) = cur; 

			prev = cur; 
			cur = cur->next; 
		} 
		else 
		{ 
			if (prev) 
				prev->next = cur->next; 
			struct Node *tmp = cur->next; 
			cur->next = NULL; 
			tail->next = cur; 
			tail = cur; 
			cur = tmp; 
		} 
	} 

	
	if ((*newHead) == NULL) 
		(*newHead) = pivot; 


	(*newEnd) = tail; 


	return pivot; 
} 



struct Node *quickSortRecur(struct Node *head, struct Node *end) 
{ 

	if (!head || head == end) 
		return head; 

	Node *newHead = NULL, *newEnd = NULL; 

	struct Node *pivot = partition(head, end, &newHead, &newEnd); 


	if (newHead != pivot) 
	{ 

		struct Node *tmp = newHead; 
		while (tmp->next != pivot) 
			tmp = tmp->next; 
		tmp->next = NULL; 


		newHead = quickSortRecur(newHead, tmp); 


		tmp = getTail(newHead); 
		tmp->next = pivot; 
	} 

	pivot->next = quickSortRecur(pivot->next, newEnd); 

	return newHead; 
} 


void quickSort(struct Node **headRef) 
{ 
	(*headRef) = quickSortRecur(*headRef, getTail(*headRef)); 
	return; 
} 


int main() 
{ 
	struct Node *a = NULL; 
	push(&a, 5); 
	push(&a, 20); 
	push(&a, 4); 
	push(&a, 3); 
	push(&a, 30); 

	cout << "Linked List before sorting \n"; 
	printList(a); 

	quickSort(&a); 

	cout << "Linked List after sorting \n"; 
	printList(a); 

	return 0; 
}


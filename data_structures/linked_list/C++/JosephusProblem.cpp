// CPP solution for Josephus Problem using circular linked list

#include<bits/stdc++.h> 
using namespace std; 

struct Node 
{ 
	int data; 
	struct Node *next; 
}; 

Node *newNode(int data) 
{ 
Node *temp = new Node; 
temp->next = temp; 
temp->data = data; 
} 

void getJosephusPosition(int m, int n) 
{ 
	Node *head = newNode(1); 
	Node *prev = head; 
	for (int i = 2; i <= n; i++) 
	{ 
		prev->next = newNode(i); 
		prev = prev->next; 
	} 
	prev->next = head;
	Node *ptr1 = head, *ptr2 = head; 
	while (ptr1->next != ptr1) 
	{ 
		int count = 1; 
		while (count != m) 
		{ 
			ptr2 = ptr1; 
			ptr1 = ptr1->next; 
			count++; 
		} 

		ptr2->next = ptr1->next; 
		ptr1 = ptr2->next; 
	} 

	printf ("Last person left standing "
			"(Josephus Position) is %d\n ", 
			ptr1->data); 
} 

int main() 
{ 
	int n;
	cout<<"Enter no. of men in the circle - ";
	cin>>n;
	int m = 2;
	cout<<"\n\n";
	getJosephusPosition(m, n); 
	return 0; 
} 


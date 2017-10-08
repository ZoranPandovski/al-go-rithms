#include <iostream>
using namespace std;
// defined class stack for linked list
class Stack {
public:
	int data;
	Stack *next;
	Stack(int n) {
		data = n;
		next = NULL;
	}
};
// Add node to the end of the linked list
void AddNode(Stack* &head, Stack *newNode) {
	if (head == NULL) {
		head = newNode;
		return;
	}
	Stack *ptr = head;
	while (ptr->next != NULL) {
		ptr = ptr->next;
	}
	ptr->next = newNode;
}
// function to push element in the stack
void push(Stack* &head, int data) {
	Stack *newNode = new Stack(data);
	AddNode(head, newNode);
	cout << data << " is pushed into the Stack" << endl;
}
//function to pop element from the stack
void pop(Stack* &head) {
	if (head == NULL) {
		cout << "Stack UnderFlow" << endl;
		return;
	}
	Stack *ptr = head;
	Stack *pre = head;
	while (ptr->next != NULL) {
		pre = ptr;
		ptr = ptr->next;
	}
	if (pre->next == NULL) head = NULL;
	else pre->next = NULL;
	cout << ptr->data << " is popped out of the Stack" << endl;
}
// function to check if the stack is empty or not
bool isEmpty(Stack *head) {
	if (head == NULL) return true;
	else false;
}
int main() {
	Stack *head = NULL;
	if (isEmpty(head)) cout << "The stack is empty" << endl;
	push(head, 10);
	push(head, 20);
	if (!isEmpty(head)) cout << "The Stack is not empty" << endl;
	pop(head);
	pop(head);
	pop(head);
	return 0;
}
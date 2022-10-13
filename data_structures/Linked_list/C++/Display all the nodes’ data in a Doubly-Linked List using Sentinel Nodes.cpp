
#include <bits/stdc++.h>
using namespace std;

int size = 0;

struct node {
	int data;
	struct node* next;
	struct node* pre;
};

struct node* createnode()
{
	struct node* t;
	t = (struct node*)malloc(sizeof(struct node));
	return (t);
}

void display(struct node* head,
			struct node* tail)
{
	head = head->next;
	cout << "\nThe linked list is :- ";
	while (head != tail) {
		cout << head->data << " ";
		head = head->next;
	}
}

void insertion(struct node* head,
			struct node* tail,
			int n, int value)
{
	n--;
	struct node *temp, *ptr;
	ptr = head;
	temp = createnode();
	temp->data = value;

	int i = 0;

	while (i < n) {
		ptr = ptr->next;
		i++;
	}
	temp->next = ptr->next;
	temp->pre = ptr;
	ptr->next = temp;
	(temp->next)->pre = temp;

	size++;
}

void deletion(struct node* head,
			struct node* tail, int n)
{
	n--;

	if (head->next == tail) {
		cout << "\nerror : linked list is empty";
		return;
	}

	if (n >= size) {
		cout << "\nerror : position is larger"
				" than size of linked list";
		return;
	}
	struct node* ptr = head;
	struct node* temp;
	int i = 0;

	while (i < n) {
		ptr = ptr->next;
		i++;
	}

	cout << "\nDeleting node at position "
		<< n + 1 << " contains valude "
		<< (ptr->next)->data;
	temp = (ptr->next)->next;
	ptr->next = temp;
	temp->pre = ptr;

	size--;
}

int main()
{

	struct node* head = createnode();
	head->pre = NULL;

	struct node* tail = createnode();
	tail->pre = head;
	tail->next = NULL;

	head->next = tail;

	int n;

start:
	cout << "\n1. Insertion\n2. Deletion\n"
			"3. Display\n0. Exit\n";
	cin >> n;
	switch (n) {
	case 1:

		insertion(head, tail, 1, 10);
		display(head, tail);

		insertion(head, tail, size + 1, 14);
		display(head, tail);

		insertion(head, tail, 2, 8);
		display(head, tail);
		cout << endl;
		goto start;
		break;

	case 2:

		deletion(head, tail,
				2);
		display(head, tail);
		cout << endl;

		deletion(head, tail, 1);
		display(head, tail);
		cout << endl;

		deletion(head, tail, size);
		display(head, tail);
		cout << endl;
		goto start;

	case 3:
		display(head, tail);
		cout << endl;
		goto start;

	default:
		break;
	}

	return 0;
}

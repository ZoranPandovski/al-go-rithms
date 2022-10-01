/* This program swaps the nodes of linked list rather
than swapping the field from the nodes.*/
#include <bits/stdc++.h>
using namespace std;

/* A linked list node */
class Node {
public:
    int data;
    Node* next;
};

/* Function to swap nodes x and y in linked list by
changing links */
void swapNodes(Node** head_ref, int x, int y)
{
    // Nothing to do if x and y are same
    if (x == y)
        return;

    // Search for x (keep track of prevX and CurrX
    Node *prevX = NULL, *currX = *head_ref;
    while (currX && currX->data != x) {
        prevX = currX;
        currX = currX->next;
    }

    // Search for y (keep track of prevY and CurrY
    Node *prevY = NULL, *currY = *head_ref;
    while (currY && currY->data != y) {
        prevY = currY;
        currY = currY->next;
    }

    // If either x or y is not present, nothing to do
    if (currX == NULL || currY == NULL)
        return;

    // If x is not head of linked list
    if (prevX != NULL)
        prevX->next = currY;
    else // Else make y as new head
        *head_ref = currY;

    // If y is not head of linked list
    if (prevY != NULL)
        prevY->next = currX;
    else // Else make x as new head
        *head_ref = currX;

    // Swap next pointers
    Node* temp = currY->next;
    currY->next = currX->next;
    currX->next = temp;
}

/* Function to add a node at the beginning of List */
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

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
}

/* Driver program to test above function */
int main()
{
    Node* start = NULL;

    int cnt;
    cout << "Enter number of nodes: ";
    cin >> cnt;
    cout << endl;

    for(int i=0;i<cnt;i++)
    {
        cout << "Enter node" << (i+1) << ": ";
        int data;
        cin >> data;
        push(&start, data);
    }

    cout << endl;
    cout << "Linked list before calling swapNodes() ";
    printList(start);
    cout << endl;

    cout << "Enter data to swap: ";
    int first,second;
    cin >> first;
    cout << endl;
    cout << "Enter data to swap with: ";
    cin >> second;
    cout << endl;
    swapNodes(&start, first, second);

    cout << "\nLinked list after calling swapNodes() ";
    printList(start);
    cout << endl;

    return 0;
}

// This is code is contributed by bhanupsingh10

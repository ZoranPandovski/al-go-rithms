// Problem Statement: Given a Linked List of integers, write a
// function to modify the linked list such that all odd numbers
// appear before all the even numbers in the modified linked list.
//  Also, keep the order of even and odd numbers the same.

// Example:

// Input: 1-->2-->3-->4-->5-->6-->NULL
// Output: 1-->3-->5-->2-->4-->6-->NULL

// Solution:

#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

node *evenAfterOdd(node *&head)
{
    node *temp = head;

    node *dummy1 = new node(-1);
    node *ptr1 = dummy1;

    node *dummy2 = new node(-1);
    node *ptr2 = dummy2;

    int count = 1;
    while (temp != NULL)
    {
        // odd in dummy1:
        if (count % 2 == 1)
        {
            ptr1->next = temp;
            ptr1 = ptr1->next;
        }

        // even in dummy2:
        else
        {
            ptr2->next = temp;
            ptr2 = ptr2->next;
        }

        count++;
        temp = temp->next;
    }

    // combining dummy 1 and 2:
    ptr1->next = dummy2->next;

    return dummy1->next;
}

void printLL(node *head)
{
    while (head != NULL)
    {
        cout << head->data << "-->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    node a(1);

    node *head = &a;
    node *temp = head;

    for (int i = 1; i < 6; i++)
    {
        temp->next = new node(i + 1);
        temp = temp->next;
    }

    printLL(head);

    node *newHead = evenAfterOdd(head);

    printLL(newHead);

    return 0;
}
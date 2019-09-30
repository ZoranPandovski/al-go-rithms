/**
 * Merge sort algorithm. One of the efficient sorting algorithm. Works
 * on the principle of divide and conquer strategy.
 *
 * Very well suited especially for linked lists. Unlike array, in linked
 * lists, we can insert items in the middle in O(1) space and O(1) time.
 * So, merge operation can be implemented without extra space.
 */

/**
 * Merge sort algorithm on Singly linked list.
 */
#include <bits/stdc++.h>
using namespace std;

// Singly Linked list node structure
struct node {
    int data;
    struct node* next;
};

struct node* merge(struct node* a, struct node* b) {
  struct node* result = NULL;
 
  if (a == NULL) return(b);
  else if (b == NULL) return(a);
 
  
  if (a->data <= b->data) {
     result = a;
     result->next = merge(a->next, b);
  } else {
     result = b;
     result->next = merge(a, b->next);
  }
  return(result);
}

void split(struct node* source, struct node** frontRef,
           struct node** backRef)
{
  struct node* fast;
  struct node* slow;
  
  if (source==NULL || source->next==NULL) {
    *frontRef = source;
    *backRef = NULL;
  } else {
    slow = source;
    fast = source->next;

    while (fast != NULL)
    {
      fast = fast->next;
      if (fast != NULL)
      {
        slow = slow->next;
        fast = fast->next;
      }
    }
 
    // 'slow' pointer is before the midpoint in the list
    // so splitting in two at that point.
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
  }
}

void mergeSort(struct node** headRef) {
  struct node* a;
  struct node* b;
 
  if (*headRef == NULL || (*headRef)->next == NULL) return;
 
  // Split the list into two sublists.
  split(*headRef, &a, &b);
 
  // Recursively sort the sublists.
  mergeSort(&a);
  mergeSort(&b);

  *headRef = merge(a, b);
}

void push(node** head, int val) {
  node* newNode = new node;
  newNode->data = val;
  newNode->next = *head;
  *head = newNode;
}

int main() {
    int n;
    cin >> n;

    struct node *l = NULL;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        push(&l, val);
    }

    mergeSort(&l);

    // Print the sorted list
    while(l != NULL) {
        cout << l->data << ' ';
        l = l->next;
    }
    cout << endl;

    return 0;
}
// Time Complexity is O(nlogn).
// Space Complexity is constant.

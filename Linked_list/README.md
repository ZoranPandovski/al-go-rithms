# Linked list

A linked list is a collection of nodes which are connected to each other by pointers. A singly linked list has a pointer to the first node, and each node has a pointer to the next node. A double linked list has a pointer to the first and last node, and each node has a pointer to the next and previous node. Each node also contains data.

Linked lists have a runtime of O(1) when inserting or reading data from the front of the list (and back for doubly linked lists), but have a runtime of O(n) when accessing a specific element in the list or searching the list.

Images from Wikipedia under public domain.

# Singly Linked List Diagram:

Singly linked lists contain nodes which have a data field as well as 'next' field, which points to the next node in line of nodes. Operations that can be performed on singly linked lists include insertion, deletion and traversal.

![](https://upload.wikimedia.org/wikipedia/commons/6/6d/Singly-linked-list.svg)

# Doubly Linked List Diagram:

In a 'doubly linked list', each node contains, besides the next-node link, a second link field pointing to the 'previous' node in the sequence. The two links may be called 'forward('s') and 'backwards', or 'next' and 'prev'('previous').

![](https://upload.wikimedia.org/wikipedia/commons/5/5e/Doubly-linked-list.svg)

# Circular Linked List:

In the last node of a list, the link field often contains a null reference, a special value is used to indicate the lack of further nodes. A less common convention is to make it point to the first node of the list; in that case, the list is said to be 'circular' or 'circularly linked'; otherwise, it is said to be 'open' or 'linear'. It is a list where the last pointer points to the first node.

![](https://upload.wikimedia.org/wikipedia/commons/d/df/Circularly-linked-list.svg)

## Source: Wikipedia
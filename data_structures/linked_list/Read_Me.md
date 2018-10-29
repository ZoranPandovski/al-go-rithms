Definition:

Singly linked list can be defined as the collection of ordered set of elements. The number of elements may vary according to need of the program. A node in the singly linked list consist of two parts: data part and link part. Data part of the node stores actual information that is to be represented by the node while the link part of the node stores the address of its immediate successor.

One way chain or singly linked list can be traversed only in one direction. In other words, we can say that each node contains only next pointer, therefore we can not traverse the list in the reverse direction.

Advantages over arrays:

Dynamic size
Ease of insertion/deletion
Drawbacks:

Random access is not allowed. We have to access elements sequentially starting from the first node. So we cannot do binary search with linked lists efficiently with its default implementation. Read about it here.
Extra memory space for a pointer is required with each element of the list.
Not cache friendly. Since array elements are contiguous locations, there is locality of reference which is not there in case of linked lists.
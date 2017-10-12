# Binary Search Tree
A tree is simply a graph with root, that is a starting point, but containing no cycles. Binary tree means that every node might have 2 children at most. Node that have no child is called Leaf. If we add search term in the middle, we define that every node's left child (or left subtree rooted at it's left child) contains smaller value than node's value and right child (or right subtree rooted at it's right child) contains larger value than the node's value. We can illustrate this with an example:

  Figure 1 - Optimal Case:
  
![alt text](https://en.0wikipedia.org/index.php?q=aHR0cDovL3VwbG9hZC53aWtpbWVkaWEub3JnL3dpa2lwZWRpYS9jb21tb25zL3RodW1iL2QvZGEvQmluYXJ5X3NlYXJjaF90cmVlLnN2Zy8yMDBweC1CaW5hcnlfc2VhcmNoX3RyZWUuc3ZnLnBuZw)

When we anlyze the image above, which is taken from wiki, we see that node that has value of 8 is the root. Nodes to the left child of root have values that are less than root and nodes to the right child of root are greater than root.

## Properties of Binary Search Tree

| Algorithm | Avarage | Worst |
| ----------| ------- | ----- |
| Space | O(n) | O(n) |
| Search | O(log(n)) | O(n) |
| Insert | O(log(n)) | O(n) |
| Delete | O(log(n)) | O(n) |

### Space
It is the space that every node defined in tree occupies in the memory. Whether it is the best case or worst case, space that is occupied by n nodes does not change.
### Search
Search is a recursive algorithm that looks for given value in the tree. We start with root checking whether it's comperable value is equal to searched value, if it is we hit the desired node and we return it. However, when it is not a hit, we compare the value that is being searched and the value that is in the node. If searched value is greater than current value, we call our search algorithm by giving current node's right child as argument. If searched value is less than current value, we give node's left child as argument to search algorithm. If we could not manage to find the searched value, we simply return NULL or False which is a designer's choice.
### Insert
Insert is also a recursive algorithm that searches for a place to add new node. When the tree is empty, we create new node with value that is being inserted and return it. However, tree is not empty, we look for proper place to insert our value by using same logic described in Search algorithm. It is easy to show it on example. Let's consider the example given in Figure 1 and suppose that we want to insert 5 into the tree. Here is the step by step description of how algorithm works:

1- call insert(root,5)

2- 8 is larger than 5, check if left child is NULL, it isn't so call insert(root->left_child, 5)

3- 3 is less than 5, check if right child is NULL, it isn't so call insert(current_node->right_child, 5)

4- 4 is less than 5, check if right child is NULL, it is NULL so create new node and make it current node's right child.

5- return.

That was the optimal case where algorithm runs in O(log(n)) complexity. 

  Figure 2- Worst Case:

![alt text](http://gateoverflow.in/?qa=blob&qa_blobid=11541371034779034273)

In the tree like Figure 2, when we want to insert 15 into tree, we would have to traverse all the nodes so that the time complexity would be O(n). Worst case might also be reversed case like larger to smaller.

### Delete
Deletion of minimum: We traverse through left most child since it has the minimum value. When we reach it, we check whether it has any right child or not. If it has one, we connect it's right child to parent node's left child then we delete the node with minimum value.

Deletion of maximum: It is the sameway around as minimum.

Delete: It is easy when the node has only one child, left or right. We would simply replace the link between it's parent and it's only child. However, things get complicated when the node has two children. In this case:

1- We search for a successor x which is the smallest value in the right sub tree of the node. 

2- We replace the node's value and x's value. 

3- If x has a right child, we perform same logic on x's right sub tree to find a successor to x called y.

4- We perform step 2-3 until we hit to the point where successor x has no child. 

5- We perform our final swap operation and delete the node.

### Traversals
#### Depth first Traversals
##### In-Order Traversal
In this algorithm left child has first priority to be printed out then parent and finally the right child.
##### Pre-Order Traversal
In this algorithm parent has first priority then left child and finally the right child.
##### Post-Order Traversal
In this algorithm left child has first priorty then right child and finally the parent.
#### Level Order or Breadth First Traversal
In this algorithm we print level by level by the help of the queue. Step by step description:

1- create an empty queue and insert root

2- while queue is not empty:

  3- get the top of queue as current_node, pop it
  
  4- insert current_node's left child then right child to queue
  
  5- print the value of current_node
  
  6- go to step 2
  
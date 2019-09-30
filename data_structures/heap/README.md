# Heap
One implementation of the Priority Queue ADT. A heap data structure looks similar to a binary tree (but an implementation doesn't have to be binary), and additionally satisfies one of the following rules:
1. any given node is greater than or equal to its parent node
2. any given node is less than or equal to its parent node

Heaps are created as either a MaxHeap or MinHead, which determines which of the preceeding rules it implements. A MinHeap will satisfy the first rule, making the root node the smallest in the tree and the MaxHeap will satisfy the second rule, making the root the largest in the tree. Because the rules only care about parent/child relationships, nothing can be said when comparing nodes at the same level of a heap.
The main functions expected from a Heap implementation are deleteMax (or deleteMin, depending on the type), insert, and peek. DeleteMax returns and removes the value at the top of the heap, insert adds a value to the heap, and peek return the value at the top without removing it.
When using a heap, the logic of maintaining the order is hidden from the user, so its important to understand the concept of heapify.
# Heapfiy - Max Heap
Every time a value is inserted or deleted, the heap needs to rearrange itself to maintain its rule. Lets start with insertion:
1. Put the new value at the first available position (the bottom of the heap).
2. If this new value is smaller than its parent, swap positions with it.
3. Repeat until the new value is smaller than its parent node (or we reach the top of the heap).

Deletion:
1. Remove the item from the top of the heap
2. Put the last item in the heap (farthest down the heap) at the top
3. While this node is greater than either of its children, swap its position with the largest of its children

Both of these will result in maintaining a heap structure and complete in a reasonable O(log(n)) time when using a binary tree.
Also interesting to note is that by magic of math http://www.geeksforgeeks.org/time-complexity-of-building-a-heap/ , building a heap is accomplished in O(n) time.

Similar to other binary trees, a heap can be represented using an array. See the avl tree README for reference.
Further reading: https://en.wikipedia.org/wiki/Heap_(data_structure)

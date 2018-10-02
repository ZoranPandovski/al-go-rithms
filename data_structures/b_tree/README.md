
## B-Tree
B-Tree is a self-balancing search tree. In most of the other self-balancing search trees (like AVL and Red-Black Trees), it is assumed that everything is in main memory. To understand the use of B-Trees, we must think of the huge amount of data that cannot fit in main memory. When the number of keys is high, the data is read from disk in the form of blocks. Disk access time is very high compared to main memory access time. The main idea of using B-Trees is to reduce the number of disk accesses. Most of the tree operations (search, insert, delete, max, min, ..etc ) require O(h) disk accesses where h is the height of the tree. B-tree is a fat tree. The height of B-Trees is kept low by putting maximum possible keys in a B-Tree node. Generally, a B-Tree node size is kept equal to the disk block size. Since h is low for B-Tree, total disk accesses for most of the operations are reduced significantly compared to balanced Binary Search Trees like AVL Tree, Red-Black Tree, ..etc.

# Properties of B-Tree
1) All leaves are at same level.
2) A B-Tree is defined by the term minimum degree ‘t’. The value of t depends upon disk block size.
3) Every node except root must contain at least t-1 keys. Root may contain minimum 1 key.
4) All nodes (including root) may contain at most 2t – 1 keys.
5) Number of children of a node is equal to the number of keys in it plus 1.
6) All keys of a node are sorted in increasing order. The child between two keys k1 and k2 contains all keys in the range from k1 and k2.
7) B-Tree grows and shrinks from the root which is unlike Binary Search Tree. Binary Search Trees grow downward and also shrink from downward.
8) Like other balanced Binary Search Trees, time complexity to search, insert and delete is O(Logn).


# Search
Search is similar to the search in Binary Search Tree. Let the key to be searched be k. We start from the root and recursively traverse down. For every visited non-leaf node, if the node has the key, we simply return the node. Otherwise, we recur down to the appropriate child (The child which is just before the first greater key) of the node. If we reach a leaf node and don’t find k in the leaf node, we return NULL.

# Traverse
Traversal is also similar to Inorder traversal of Binary Tree. We start from the leftmost child, recursively print the leftmost child, then repeat the same process for remaining children and keys. In the end, recursively print the rightmost child. 

## Variants
In the B+ tree, copies of the keys are stored in the internal nodes; the keys
and records are stored in leaves; in addition, a leaf node may include a
pointer to the next leaf node to speed sequential access (Comer 1979, p. 129).

The B* tree balances more neighboring internal nodes to keep the internal nodes
more densely packed (Comer 1979, p. 129). This variant requires non-root nodes
to be at least 2/3 full instead of 1/2 (Knuth 1998, p. 488). To maintain this,
instead of immediately splitting up a node when it gets full, its keys are
shared with a node next to it. When both nodes are full, then the two nodes are
split into three. Deleting nodes is somewhat more complex than inserting
however.

B-trees can be turned into order statistic trees to allow rapid searches for
the Nth record in key order, or counting the number of records between any two
records, and various other related operations.

![](https://upload.wikimedia.org/wikipedia/commons/6/65/B-tree.svg)

[Source](https://en.wikipedia.org/wiki/B-tree)

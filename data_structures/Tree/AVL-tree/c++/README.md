# AVL Tree
When we find a data we want in a skewed binary search tree, we have to search from root node to leaf node in a worst case. To improve this problem, we can use AVL tree. AVL tree is a height-balanced binary tree. In other words, all the height difference between left subtrees and right subtrees are less than 1.

![그림2](https://user-images.githubusercontent.com/63658525/99893569-7c90ab00-2cc4-11eb-9278-81f562a8690c.png)


These are the examples of AVL trees. The numbers written in the trees are balance factor. Balance factor is defined as hL-hR (hL is the height of left subtree, and hR is the height of right subtree). We can figure out if this is AVL tree, by balance factor. If balance factor is -1 or 0 or 1, it’s AVL tree.

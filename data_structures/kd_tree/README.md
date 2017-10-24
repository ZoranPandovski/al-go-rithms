
## KD-Tree
In computer science, a k-d tree (short for k-dimensional tree) is a
space-partitioning data structure for organizing points in a k-dimensional
space. k-d trees are a useful data structure for several applications, such as
searches involving a multidimensional search key (e.g. range searches and
nearest neighbor searches). k-d trees are a special case of binary space
partitioning trees.

The k-d tree is a binary tree in which every node is a k-dimensional point.
Every non-leaf node can be thought of as implicitly generating a splitting
hyperplane that divides the space into two parts, known as half-spaces. Points
to the left of this hyperplane are represented by the left subtree of that node
and points right of the hyperplane are represented by the right subtree. The
hyperplane direction is chosen in the following way: every node in the tree is
associated with one of the k-dimensions, with the hyperplane perpendicular to
that dimension's axis. So, for example, if for a particular split the "x" axis
is chosen, all points in the subtree with a smaller "x" value than the node
will appear in the left subtree and all points with larger "x" value will be in
the right subtree. In such a case, the hyperplane would be set by the x-value
of the point, and its normal would be the unit x-axis.

## Complexity
Building a static k-d tree from n points has the following worst-case
complexity:

- O(n log2 n) if an O(n log n) sort such as Heapsort or Mergesort is used to
  find the median at each level of the nascent tree.
- O(n log n) if an O(n) median of medians algorithm is used to select the
  median at each level of the nascent tree.
- O(kn log n) if n points are presorted in each of k dimensions using an O(n
  log n) sort such as Heapsort or Mergesort prior to building the k-d tree.

Inserting a new point into a balanced k-d tree takes O(log n) time.

Removing a point from a balanced k-d tree takes O(log n) time.

Querying an axis-parallel range in a balanced k-d tree takes O(n1−1/k +m) time,
where m is the number of the reported points, and k the dimension of the k-d
tree.

Finding 1 nearest neighbour in a balanced k-d tree with randomly distributed
points takes O(log n) time on average.

![](https://upload.wikimedia.org/wikipedia/commons/b/b6/3dtree.png)

[Source](https://en.wikipedia.org/wiki/K-d_tree)

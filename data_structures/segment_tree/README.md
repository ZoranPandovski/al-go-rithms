# Segment Tree

Segment Tree is a binary tree structure that is constructed by using an array. ST has 2*n-1 nodes for an array of size n. Since there are n leaves and there will be n-1 internal nodes.
Each node has information of index that points to minimum element in that subtree. Root has the index that points to smallest value in the array. 
Generally ST is a structure that should not be rebuilt once it is computed unless there is a change in the original array. 

The whole array Array[0:n-1] is represented by the root of the segment tree. Then we will break the interval or segment into half (since it is a binary tree) and the left child of the root will represent Array[0:(n-1)/2] and the right child of the root will represent Array[(n-1)/2 + 1: n]. So the height of the segment will be log(n).
We use an array representation for segment trees. In this resresentation, if the node index is i then it's left child will be indexed at 2*i+1, right child will be indexed at 2*i+2 and the parent of the node is indexed at (i-1)//2.
Size of the memory allocated for this representation will be: ![equation](http://www.geeksforgeeks.org/wp-content/uploads/segmenttree.png)

Figure-1: Example of a Segment Tree:

![alt text](http://www.geeksforgeeks.org/wp-content/uploads/RangeMinimumQuery.png)

## How to construct a Segment Tree
We start with segment array[0:n-1] and we divide the current segment into two halves on each iteration until we get the segment with length 1.
Then we apply same procedure on both halves and for each segment, we store the index of the minimum value in it.
Except the last level, all levels of segment tree will be completely filled. 
Once the tree is constructed, we can make a query to get index of minimum value.Here is the step by step description:

1- call query(l_index, r_index) which will call queryUtil(start = 0, end = size(array)-1, l_index, r_index, tree_index=0)

2- check if start and end is between left and right, if it is return the segmentTree[tree_index]

3- call queryUtil recursively for left and right side of array : min(queryUtil(start,mid,l_index,r_index,2\*t_index+1),queryUtil(mid+1,end,l_index, r_index, 2\*t_index+2))

This data structure is suitable for Range Minimum Query algorithm questions.
Disjoint Set Union :

This data structure provides the following capabilities. We are given several elements, each of which is a separate set. A DSU will have an operation to combine any two sets, and it will be able to tell in which set a specific element is. The classical version also introduces a third operation, it can create a set from a new element.

Thus the basic interface of this data structure consists of only three operations:

	* initialize(v) : 
		creates `v` sets where ith set contains element i

	* join(a, b) : 
		merges the two specified sets (the set in which the element a is located, and the set in which the element b is located)

	* find(v) :
		returns the representative (also called leader) of the set that contains the element v. This representative is an element of its corresponding set. It is selected in each set by the data     structure itself (and can change over time, namely after union_sets calls). This representative can be used to check if two elements are part of the same set of not. a and b are exactly in the same set, if find_set(a) == find_set(b). Otherwise they are in different sets.

		Path Compression Optimization ::

		The implemented version of the find(v) function includes the path compression optimization.

		Here each time we find the parent of some node:

		Then if the node is parent of itself then the value is returned 
		else the parent of the given node is set to the parent of the above node by recusively calling the find function.

		Hence after the recursive calls are completed the parent of all the nodes is set to the root of the set.

		For better understanding refer to the image given below:

		[DSU_Path_Optimization][img1]






[img1] : https://raw.githubusercontent.com/e-maxx-eng/e-maxx-eng/master/img/DSU_path_compression.png
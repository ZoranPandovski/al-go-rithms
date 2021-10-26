using System;

// A BTree
class Btree
{
public BTreeNode root; // Pointer to root node
public int t; // Minimum degree

// Constructor (Initializes tree as empty)
Btree(int t)
{
	this.root = null;
	this.t = t;
}

// function to traverse the tree
public void traverse()
{
	if (this.root != null)
	this.root.traverse();
	Console.WriteLine();
}

// function to search a key in this tree
public BTreeNode search(int k)
{
	if (this.root == null)
	return null;
	else
	return this.root.search(k);
}
}

// A BTree node
class BTreeNode
{
int[] keys; // An array of keys
int t; // Minimum degree (defines the range for number of keys)
BTreeNode[] C; // An array of child pointers
int n; // Current number of keys
bool leaf; // Is true when node is leaf. Otherwise false

// Constructor
BTreeNode(int t, bool leaf) {
	this.t = t;
	this.leaf = leaf;
	this.keys = new int[2 * t - 1];
	this.C = new BTreeNode[2 * t];
	this.n = 0;
}

// A function to traverse all nodes in a subtree rooted with this node
public void traverse() {

	// There are n keys and n+1 children, traverse through n keys
	// and first n children
	int i = 0;
	for (i = 0; i < this.n; i++) {

	// If this is not leaf, then before printing key[i],
	// traverse the subtree rooted with child C[i].
	if (this.leaf == false) {
		C[i].traverse();
	}
	Console.Write(keys[i] + " ");
	}

	// Print the subtree rooted with last child
	if (leaf == false)
	C[i].traverse();
}

// A function to search a key in the subtree rooted with this node.
public BTreeNode search(int k) { // returns NULL if k is not present.

	// Find the first key greater than or equal to k
	int i = 0;
	while (i < n && k > keys[i])
	i++;

	// If the found key is equal to k, return this node
	if (keys[i] == k)
	return this;

	// If the key is not found here and this is a leaf node
	if (leaf == true)
	return null;

	// Go to the appropriate child
	return C[i].search(k);

}
}

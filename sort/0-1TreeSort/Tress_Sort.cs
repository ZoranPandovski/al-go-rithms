// C# program to
// implement Tree Sort
using System;
public class GFG
{

// Class containing left and
// right child of current
// node and key value
public class Node
{
	public int key;
	public Node left, right;

	public Node(int item)
	{
	key = item;
	left = right = null;
	}
}

// Root of BST
Node root;

// Constructor
GFG()
{
	root = null;
}

// This method mainly
// calls insertRec()
void insert(int key)
{
	root = insertRec(root, key);
}

/* A recursive function to
	insert a new key in BST */
Node insertRec(Node root, int key)
{

	/* If the tree is empty,
		return a new node */
	if (root == null)
	{
	root = new Node(key);
	return root;
	}

	/* Otherwise, recur
		down the tree */
	if (key < root.key)
	root.left = insertRec(root.left, key);
	else if (key > root.key)
	root.right = insertRec(root.right, key);

	/* return the root */
	return root;
}

// A function to do
// inorder traversal of BST
void inorderRec(Node root)
{
	if (root != null)
	{
	inorderRec(root.left);
	Console.Write(root.key + " ");
	inorderRec(root.right);
	}
}
void treeins(int []arr)
{
	for(int i = 0; i < arr.Length; i++)
	{
	insert(arr[i]);
	}

}

// Driver Code
public static void Main(String[] args)
{
	GFG tree = new GFG();
	int []arr = {5, 4, 7, 2, 11};
	tree.treeins(arr);
	tree.inorderRec(tree.root);
}
}

// This code is contributed by Rajput-Ji

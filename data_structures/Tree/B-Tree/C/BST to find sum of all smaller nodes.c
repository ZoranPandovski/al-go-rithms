/* Program to change a BST to Binary Tree such that key of a Node becomes original key plus sum of all smaller keys in BST */
#include <stdio.h> 
#include <stdlib.h> 

/* A BST Node has key, left child and 
right child */
struct Node { 
	int key; 
	struct Node* left; 
	struct Node* right; 
}; 

/* Helper function that allocates a new 
node with the given key and NULL left 
and right pointers.*/
struct Node* newNode(int key) 
{ 
	struct Node* node = new Node; 
	node->key = key; 
	node->left = NULL; 
	node->right = NULL; 
	return (node); 
} 

/* A recursive function that traverses the given BST in inorder and for every key, adds all smaller keys to it */
void addSmallerUtil(struct Node* root, int* sum) 
{ 
	// Base Case 
	if (root == NULL) 
		return; 

	// Recur for left subtree first so that 
	// sum of all smaller Nodes is stored 
	addSmallerUtil(root->left, sum); 

	// Update the value at sum 
	*sum = *sum + root->key; 

	// Update key of this Node 
	root->key = *sum; 

	// Recur for right subtree so that 
	// the updated sum is added 
	// to greater Nodes 
	addSmallerUtil(root->right, sum); 
} 

// A wrapper over addSmallerUtil(). It 
// initializes sum and calls addSmallerUtil() 
// to recursively update and use value of 
void addSmaller(struct Node* root) 
{ 
	int sum = 0; 
	addSmallerUtil(root, &sum); 
} 

// A utility function to print inorder 
// traversal of Binary Tree 
void printInorder(struct Node* node) 
{ 
	if (node == NULL) 
		return; 
	printInorder(node->left); 
	printf("%d ", node->key); 
	printInorder(node->right); 
} 

// Driver program to test above function 
int main() 
{ 
	/* Create following BST 
			 9 
		 /   \ 
		6  	 15 */
	Node* root = newNode(9); 
	root->left = newNode(6); 
	root->right = newNode(15); 

	printf(" Original BST\n"); 
	printInorder(root); 

	addSmaller(root); 

	printf("\n BST To Binary Tree\n"); 
	printInorder(root); 

	return 0; 
} 

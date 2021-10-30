// C++ implementation of a O(n) time method for spiral order traversal
#include <iostream>
#include <stack>
using namespace std;

// Binary Tree node
struct node {
	int data;
	struct node *left, *right;
};

void printSpiral(struct node* root)
{
	if (root == NULL)
		return; // NULL check

	// Create two stacks to store alternate levels
	stack<struct node*> s1; // For levels to be printed from right to left
	stack<struct node*> s2; // For levels to be printed from left to right

	// Push first level to first stack 's1'
	s1.push(root);

	// Keep printing while any of the stacks has some nodes
	while (!s1.empty() || !s2.empty()) {
		// Print nodes of current level from s1 and push nodes of
		// next level to s2
		while (!s1.empty()) {
			struct node* temp = s1.top();
			s1.pop();
			cout << temp->data << " ";

			// Note that is right is pushed before left
			if (temp->right)
				s2.push(temp->right);
			if (temp->left)
				s2.push(temp->left);
		}

		// Print nodes of current level from s2 and push nodes of
		// next level to s1
		while (!s2.empty()) {
			struct node* temp = s2.top();
			s2.pop();
			cout << temp->data << " ";

			// Note that is left is pushed before right
			if (temp->left)
				s1.push(temp->left);
			if (temp->right)
				s1.push(temp->right);
		}
	}
}

// A utility function to create a new node
struct node* newNode(int data)
{
	struct node* node = new struct node;
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

int main()
{
	struct node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(7);
	root->left->right = newNode(6);
	root->right->left = newNode(5);
	root->right->right = newNode(4);
	cout << "Spiral Order traversal of binary tree is \n";
	printSpiral(root);

	return 0;
}

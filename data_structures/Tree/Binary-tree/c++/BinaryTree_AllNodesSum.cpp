#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct Node {
	int key;
	struct Node *left, *right;
};

// Utility function to create a new node
Node* newNode(int key)
{
	Node* temp = new Node;
	temp->key = key;
	temp->left = temp->right = NULL;
	return (temp);
}

/*Function to find sum of all elements*/
int sumBT(Node* root)
{
	//sum variable to track the sum of
	//all variables.
	int sum = 0;

	queue<Node*> q;

	//Pushing the first level.
	q.push(root);

	//Pushing elements at each level from
	//the tree.
	while (!q.empty()) {
		Node* temp = q.front();
		q.pop();

		//After popping each element from queue
		//add its data to the sum variable.
		sum += temp->key;

		if (temp->left) {
			q.push(temp->left);
		}
		if (temp->right) {
			q.push(temp->right);
		}
	}
	return sum;
}

// Driver program
int main()
{
	// Let us create Binary Tree
	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	root->right->left->right = newNode(8);

	cout << "Sum of all elements in the binary tree is: "
		<< sumBT(root);
}

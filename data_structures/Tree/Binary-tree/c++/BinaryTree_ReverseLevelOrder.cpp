#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left and right children */
struct node
{
	int data;
	struct node* left;
	struct node* right;
};

/* Given a binary tree, print its nodes in reverse level order */
void reverseLevelOrder(node* root)
{
	stack <node *> S;
	queue <node *> Q;
	Q.push(root);

	// Do something like normal level order traversal order. Following are the
	// differences with normal level order traversal
	// 1) Instead of printing a node, we push the node to stack
	// 2) Right subtree is visited before left subtree
	while (Q.empty() == false)
	{
		/* Dequeue node and make it root */
		root = Q.front();
		Q.pop();
		S.push(root);

		/* Enqueue right child */
		if (root->right)
			Q.push(root->right); // NOTE: RIGHT CHILD IS ENQUEUED BEFORE LEFT

		/* Enqueue left child */
		if (root->left)
			Q.push(root->left);
	}

	// Now pop all items from stack one by one and print them
	while (S.empty() == false)
	{
		root = S.top();
		cout << root->data << " ";
		S.pop();
	}
}

/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
node* newNode(int data)
{
	node* temp = new node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;

	return (temp);
}

/* Driver program to test above functions*/
int main()
{
	struct node *root = newNode(1);
	root->left	 = newNode(2);
	root->right	 = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);

	cout << "Level Order traversal of binary tree is \n";
	reverseLevelOrder(root);

	return 0;
}

/// C++ program of space optimized solution
/// to find vertical sum of binary tree.
#include <bits/stdc++.h>

using namespace std;

/// Tree node structure
struct TNode{
	int key;
	struct TNode *left, *right;
};

/// Function to create new tree node
TNode* newTNode(int key)
{
	TNode* temp = new TNode;
	temp->key = key;
	temp->left = temp->right = NULL;
	return temp;
}

/// Doubly linked list structure
struct LLNode{
	int key;
	struct LLNode *prev, *next;
};

/// Function to create new Linked List Node
LLNode* newLLNode(int key)
{
	LLNode* temp = new LLNode;
	temp->key = key;
	temp->prev = temp->next = NULL;
	return temp;
}

/// Function that creates Linked list and store
/// vertical sum in it.
void verticalSumDLLUtil(TNode *root, LLNode *sumNode)
{
	/// Update sum of current line by adding value
	/// of current tree node.
	sumNode->key = sumNode->key + root->key;

	/// Recursive call to left subtree.
	if(root->left)
	{
		if(sumNode->prev == NULL)
		{
			sumNode->prev = newLLNode(0);
			sumNode->prev->next = sumNode;
		}
		verticalSumDLLUtil(root->left, sumNode->prev);
	}

	/// Recursive call to right subtree.
	if(root->right)
	{
		if(sumNode->next == NULL)
		{
			sumNode->next = newLLNode(0);
			sumNode->next->prev = sumNode;
		}
		verticalSumDLLUtil(root->right, sumNode->next);
	}
}

/// Function to print vertical sum of Tree.
/// It uses verticalSumDLLUtil() to calculate sum.
void verticalSumDLL(TNode* root)
{
	/// Create Linked list node for
	/// line passing through root.
	LLNode* sumNode = newLLNode(0);

	/// Compute vertical sum of different lines.
	verticalSumDLLUtil(root, sumNode);

	/// Make doubly linked list pointer point
	/// to first node in list.
	while(sumNode->prev != NULL){
		sumNode = sumNode->prev;
	}

	/// Print vertical sum of different lines
	/// of binary tree.
	while(sumNode != NULL){
		cout << sumNode->key <<" ";
		sumNode = sumNode->next;
	}
}

int main()
{
	/* binary Tree:
			 1
			/ \
		   /   \
		  2	    3
		 / \   / \
		/   \ /   \
	   4    5 6    7
	*/
	TNode *root = newTNode(1);
	root->left = newTNode(2);
	root->right = newTNode(3);
	root->left->left = newTNode(4);
	root->left->right = newTNode(5);
	root->right->left = newTNode(6);
	root->right->right = newTNode(7);

	cout << "Vertical Sums are\n";
	verticalSumDLL(root);
	return 0;
}

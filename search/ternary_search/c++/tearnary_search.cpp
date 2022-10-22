// C++ program to demonstrate Ternary Search Tree 

#include <bits/stdc++.h>
using namespace std;
#define MAX 50


struct Node {
	char data;

	unsigned isEndOfString = 1;
	Node *left, *eq, *right;
};


Node* newNode(char data)
{
	Node* temp = new Node();
	temp->data = data;
	temp->isEndOfString = 0;
	temp->left = temp->eq = temp->right = NULL;
	return temp;
}


void insert(Node** root, char* word)
{

	if (!(*root))
		*root = newNode(*word);


	if ((*word) < (*root)->data)
		insert(&((*root)->left), word);


	else if ((*word) > (*root)->data)
		insert(&((*root)->right), word);

	else {
		if (*(word + 1))
			insert(&((*root)->eq), word + 1);

		// the last character of the word
		else
			(*root)->isEndOfString = 1;
	}
}


void traverseTSTUtil(Node* root, char* buffer, int depth)
{
	if (root) {
	
		traverseTSTUtil(root->left, buffer, depth);

		// Store the character of this node
		buffer[depth] = root->data;
		if (root->isEndOfString) {
			buffer[depth + 1] = '\0';
			cout << buffer << endl;
		}


		traverseTSTUtil(root->eq, buffer, depth + 1);

		// Finally Traverse the right subtree
		traverseTSTUtil(root->right, buffer, depth);
	}
}


void traverseTST(struct Node* root)
{
	char buffer[MAX];
	traverseTSTUtil(root, buffer, 0);
}

// Function to search a given word in TST
int searchTST(Node* root, char* word)
{
	if (!root)
		return 0;

	if (*word < (root)->data)
		return searchTST(root->left, word);

	else if (*word > (root)->data)
		return searchTST(root->right, word);

	else {
		if (*(word + 1) == '\0')
			return root->isEndOfString;

		return searchTST(root->eq, word + 1);
	}
}


int main()
{
	Node* root = NULL;
	char cat[] = "cat";
	char cats[] = "cats";
	char up[] = "up";
	char bug[] = "bug";
	char bu[] = "bu";
	insert(&root, cat);
	insert(&root, cats);
	insert(&root, up);
	insert(&root, bug);

	cout << "Following is traversal of ternary search "
			"tree\n";
	traverseTST(root);

	cout << "\nFollowing are search results for cats, bu "
			"and cat respectively\n";
	searchTST(root, cats) ? cout << "Found\n"
						: cout << "Not Found\n";
	searchTST(root, bu) ? cout << "Found\n"
						: cout << "Not Found\n";
	searchTST(root, cat) ? cout << "Found\n"
						: cout << "Not Found\n";

	return 0;
}



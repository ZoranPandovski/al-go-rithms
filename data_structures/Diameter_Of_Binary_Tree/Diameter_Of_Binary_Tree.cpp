#include <bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	struct node *left, *right;
};
struct node *newNode(int data);

int ans=0;
int find(struct node* root)
{  
    if(!root) return 0;

     int l = find(root->left);
     int r = find(root->right);

     ans=max(ans,l+r+1);

     return max(l,r)+1;
}
int diameter(struct node *tree)
{       
	ans=0;
	if(!root) 
          return 0;
        find(root);
          return ans;
}
struct node *newNode(int data)
{
	struct node *node = (struct node *)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

int main()
{

	/* Constructed binary tree is
			 1
			/ \
		   2   3
		  /     \
		 4	     5
	*/
	struct node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	cout << "Diameter of the given binary tree is " << diameter(root);

	return 0;
}

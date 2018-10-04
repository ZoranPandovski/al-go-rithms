#include<iostream>
using namespace std;
struct node {
	int data;
	struct node *left,*right;
};
struct node* BST(struct node *root,int d) {
	if(root==NULL) {
		struct node *nn = new node();
		nn->data = d;
		nn->left=nn->right=NULL;
	}
	else {
		if(d>root->data)
			root->right = BST(root->right,d);
		else if(d<root->data)
			root->left = BST(root->left,d);
	}
}
void display(struct node *root) {
	if(root!=NULL) {
		display(root->left);
		cout<<root->data<<" ";
		display(root->right);
	}
}
int main() {
	struct node *root = NULL;
	int n,num;
	cout<<"Enter n:";
	cin>>n;
	 /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
	for(int i=0;i<n;i++) {
		cin>>num;
		root = BST(root,num);
	}
	display(root); // it will print in ascending order.
}

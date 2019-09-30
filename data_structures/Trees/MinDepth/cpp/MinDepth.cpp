#include<bits/stdc++.h>
#define ll long long
using namespace std;

typedef struct tree node;

struct tree
{
	ll data;
	node * right;
	node * left;
};

node * insert(ll a)
{
	tree * temp = new tree;
	temp->data=a;
	temp->left=temp->right=NULL;
	return temp;
}

//Height including the root
ll height(node * root)
{
	ll h=0;
	if(root==NULL)
	{
		return 0;
	}
	else return 1 + min(height(root->left),height(root->right));
}

int main()
{
	//The tree;
	node * root=insert(1);
	//cout<<height(root);
	root->right=insert(2);
	root->left=insert(3);
	root->left->left=insert(4);
	
	/*tree * root=new tree;
	root=NULL;
	*/
	cout<<height(root);	
        return 0;
}


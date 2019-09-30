#include<bits/stdc++.h>
using namespace std;
typedef struct tree{
  int data;
  int height;
  struct tree* left;
  struct tree* right;
  struct tree* parent;
} tree;
tree *root=NULL;
tree* create(int n)
{
	tree* temp=(tree*)malloc(sizeof(tree));
	temp->data=n;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
void printin(tree* temp)
{
	if(temp!=NULL)
	{
		printin(temp->left);
		printf("%d ",temp->data);
		printin(temp->right);
	}

}

tree* insert(int n)
{
	tree* temp=root;
	if(root==NULL)
	{
		root=create(n);
		root->parent=NULL;
    root->height=1;
	}
	else
	{
		while(temp!=NULL)
		{
			if((temp->data)<=n)
			{
				if(temp->right!=NULL)
        {
        // temp2->height=temp2->height+1;
        temp->height++;
				temp=temp->right;

      }
      else
        {
					tree* temp2=temp;
					 temp->right=create(n);
					 temp->right->parent=temp2;
           temp->right->height=0;
					 // break;
				 }
			}
			else
			{
				if(temp->left!=NULL)
        {
        temp->height++;
				temp=temp->left;
        }
        else
				{
					tree* temp2=temp;
					temp->left=create(n);
					temp->left->parent=temp2;
          temp->left->height=0;
          // break;
				}
			}
	   }

     
	 }

	return root;
}
void leftrotate(tree* node)
{
  tree* temp= node->parent;

    temp->left=node->left;
    tree* temp2=node->left->right;
    temp->left->right=node;
    node->left=temp2;
}
void rightrotate(tree* node)
{
  tree* temp=node->parent;
  temp->right=node->right;
  tree* temp2=node->right->left;
  temp->right->left=node;
  node->right=temp2;

}
int main()
{
  int n,i;
	cin>>n;
	for(i=0;i<n;i++)
	{
		int k;
		cin>>k;
		insert(k);
	}

  return 0;
}

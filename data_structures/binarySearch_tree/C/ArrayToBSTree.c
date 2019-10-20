#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define size 10
typedef struct node{
	int data;
	node* left;
	node* right;
};
node* newnode(int );
node* a2T(int arr[],int,int);
void printPreOrder(node*);
void main()
{
	int a[size];
	clrscr();
	for(int i=0;i<size;i++)
	{
		scanf("%d",&a[i]);
	}
       node* root=a2T(a,0,size-1);
       printf("Preorder Traversal for tree: ");
       printPreOrder(root);

}
node* newnode(int data)
{
	node* Node=(node*)malloc(sizeof(node));
	Node->data=data;
	Node->left=Node->right=NULL;
	return Node;
}
node* a2T(int arr[],int start,int end)
{
	if(start>end)
		return NULL;
	int r=(start+end)/2;
	node* root=newnode(arr[r]);
	root->left=a2T(arr,start,r-1);
	root->right=a2T(arr,r+1,end);
	return root;
}
void printPreOrder(node* Print_Node)
{
	if(Print_Node==NULL)
		return ;
	printf("%d",Print_Node->data);
	printPreOrder(Print_Node->left);
	printPreOrder(Print_Node->right);
}

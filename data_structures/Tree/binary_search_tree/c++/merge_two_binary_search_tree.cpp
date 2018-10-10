#include <iostream>
using namespace std;


/*
This represents the structure of the node of the Binary Search Tree.
*/


struct node
{
    node * left;
    node * right;
    int data;
};


/*
This function adds new data into binary search tree (BST). 
It takes root of the tree as parameter along with the new data to be inserted.
*/


node * add(node * root,int val)
{
    if(root == NULL)
    {
        node * newNode = new node;
        newNode->data = val;
        newNode->left=NULL;
        newNode->right=NULL;
        return newNode;
    }
    if(val > root->data)
        root->right=add(root->right,val);
    else
        root->left=add(root->left,val);
    return root;
}


/*
This function traverses the second tree and adds its nodes to tree 1.
It takes roots of tree 1 and tree 2 as parameters.
*/


node * merge(node * root1,node * root2)
{
    if(root2==NULL)
        return root1;
    merge(root1,root2->left);
    add(root1,root2->data);
    merge(root1,root2->right);
}


/*
This function prints the inorder traversal of the BST thus printing
a list of entered values in ascending order.It takes the root node as a parameter.
*/


void print_inorder(node *root)
{
    if(root==NULL)
    return;
    print_inorder(root->left);
    cout<<root->data<<" ";
    print_inorder(root->right);
    
}

int main()
{
    node * root1 =NULL;
    node * root2 =NULL;
    
    //  Insertion into tree1
    root1=add(root1,12);
    root1=add(root1,30);
    root1=add(root1,2);
    root1=add(root1,15);
    root1=add(root1,6);
    root1=add(root1,54);
    root1=add(root1,27);
    
    //Printing result
    print_inorder(root1);
    cout<<"\n";


    //  Insertion into tree2
    root2=add(root2,30);
    root2=add(root2,23);
    root2=add(root2,12);
    root2=add(root2,43);
    root2=add(root2,33);
    root2=add(root2,62);
    root2=add(root2,31);
    
    //Printing result
    print_inorder(root2);
    cout<<"\n";


    //  Merging the two trees

    merge(root1,root2);


    //  Printing merged tree

    print_inorder(root1);

    return 0;
}
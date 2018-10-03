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



/*
This function searches for the first occurance of data in the tree.
It takes the root node alongwith the value to search as parameters.
*/


node * search_node(node *root,int val)
{
    if(root==NULL)
        return NULL;
    if(val == root->data)
        return root;
    if (val < root->data)
        return search_node(root->left,val);
    return search_node(root->right,val);    
}



int main()
{
    node * root =NULL;
    
    //  Inserting values
    root=add(root,12);
    root=add(root,30);
    root=add(root,2);
    root=add(root,15);
    root=add(root,6);
    root=add(root,54);
    root=add(root,27);
    
    //Printing result
    node * searched_node = search_node(root,30);
    if(searched_node == NULL)
        cout<<"Node not found\n";
    else
        cout<<"Node with data "<<searched_node->data<<" found.\n";

    
    //Printing result
    searched_node = search_node(root,3);
    if(searched_node == NULL)
        cout<<"Node not found\n";
    else
        cout<<"Node with data "<<searched_node->data<<" found.\n";

    return 0;
}
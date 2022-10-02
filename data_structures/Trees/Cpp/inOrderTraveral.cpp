#include <iostream>
using namespace std;

/*
*   Create structure of a node
*/
struct node 
{ 
    int data; 
    struct node *left, *right; 
}; 
   
/*
*   A utility function to create a new node
*/
struct node *newNode(int item) 
{ 
    struct node *temp = new node; 
    temp->data = item; 
    temp->left = temp->right = NULL; 
    return temp; 
};

/*
*   Add a new node in the tree
*/
struct node * insert(struct node *root, int element)
{
    if(root == NULL)
        return newNode(element);
    if(root->data > element)
        root->left = insert(root->left, element);
    else if (root->data < element)
        root->right = insert(root->right, element); 
    return root;
}

/*
*   Make inorder traverse of the tree
*/
void inorder(struct node *root)
{
    if(root == NULL)
        return; 
    inorder(root->left);
    cout <<root->data << " ";
    inorder(root->right);
}


/*
*   Entry point of the application
*/
int main()
{
    struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 40);
    insert(root, 26);
    insert(root, 35);
    insert(root, 67);
    insert(root, 89);
    insert(root, 1);

   
    inorder(root);
    return 0;
}

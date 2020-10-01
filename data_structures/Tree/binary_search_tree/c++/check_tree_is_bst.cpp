#include <bits/stdc++.h> 
using namespace std; 
  
/* A binary tree node has data, pointer to 
left child and a pointer to right child */
struct Node 
{ 
    int data; 
    struct Node* left, *right; 
}; 
  
  
bool isBSTUtil(struct Node* root, Node *&prev) 
{ 
    // traverse the tree in inorder fashion and  
    // keep track of prev node 
    if (root) 
    { 
        if (!isBSTUtil(root->left, prev)) 
          return false; 
   
        // Allows only distinct valued nodes  
        if (prev != NULL && root->data <= prev->data) 
          return false; 
   
        prev = root; 
   
        return isBSTUtil(root->right, prev); 
    } 
   
    return true; 
} 
  
bool isBST(Node *root) 
{ 
   Node *prev = NULL; 
   return isBSTUtil(root, prev); 
} 

int main() 
{ 
    /* Let us create following BST 
              3 
           /     \ 
          2       5 
         /  \       
        1    4      */
    struct Node *root = new Node(3); 
    root->left     = new Node(2); 
    root->right     = new Node(5); 
    root->left->left = new Node(1); 
    root->left->right = new Node(4); 
    if (isBST(root)) 
        cout << "Is BST"; 
    else
        cout << "Not a BST"; 
    return 0; 
} 

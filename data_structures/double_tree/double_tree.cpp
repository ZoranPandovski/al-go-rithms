#include <stdio.h> 
#include <stdlib.h> 
   
/* A binary tree node has data, pointer to left child 
   and a pointer to right child */
struct node 
{ 
    int data; 
    struct node* left; 
    struct node* right; 
}; 
   
/* function to create a new node of tree and returns pointer */
struct node* newNode(int data); 
   
/* Function to convert a tree to double tree */ 
void doubleTree(struct node* node)  
{ 
  struct node* oldLeft; 
  
  if (node==NULL) return; 
  
  /* do the subtrees */
  doubleTree(node->left); 
  doubleTree(node->right); 
  
  /* duplicate this node to its left */
  oldLeft = node->left; 
  node->left = newNode(node->data); 
  node->left->left = oldLeft; 
} 
    
  
   
/* UTILITY FUNCTIONS TO TEST doubleTree() FUNCTION */
 /* Helper function that allocates a new node with the 
   given data and NULL left and right pointers. */
struct node* newNode(int data) 
{ 
  struct node* node = (struct node*) 
                       malloc(sizeof(struct node)); 
  node->data = data; 
  node->left = NULL; 
  node->right = NULL; 
   
  return(node); 
} 
  
/* Given a binary tree, print its nodes in inorder*/
void printInorder(struct node* node) 
{ 
  if (node == NULL) 
    return; 
  printInorder(node->left);  
  printf("%d ", node->data); 
  printInorder(node->right); 
} 
   
   
/* Driver program to test above functions*/
int main() 
{ 
   
  /* Constructed binary tree is 
            1 
          /   \ 
        2      3 
      /  \ 
    4     5 
  */
  struct node *root = newNode(1); 
  root->left        = newNode(2); 
  root->right       = newNode(3); 
  root->left->left  = newNode(4); 
  root->left->right = newNode(5); 
   
  printf("Inorder traversal of the original tree is \n"); 
  printInorder(root); 
  
  doubleTree(root); 
    
  printf("\n Inorder traversal of the double tree is \n");   
  printInorder(root); 
     
  getchar(); 
  return 0; 
} 

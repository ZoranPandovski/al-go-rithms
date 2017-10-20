# include <stdio.h>
# include <stdlib.h>

#include "bst.h"

#define SIZE 9

typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
} node;

/*
    create a new node
*/
node* create_node(int data)
{
    node *new_node = (node*)malloc(sizeof(node));
    if(new_node == NULL)
    {
        exit(1);
    }
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

/*
    insert a new node into the BST
*/
node* insert_node(node *root, comparer compare, int data)
{
    if(root == NULL)
    {
        root = create_node(data);
    }
    else
    {
        int is_left  = 0;
        int r        = 0;
        node* cursor = root;
        node* prev   = NULL;
 
        while(cursor != NULL)
        {
            r = compare(data,cursor->data);
            prev = cursor;
            if(r < 0)
            {
                is_left = 1;
                cursor = cursor->left;
            }
            else if(r > 0)
            {
                is_left = 0;
                cursor = cursor->right;
            }
        }
        if(is_left)
            prev->left = create_node(data);
        else
            prev->right = create_node(data);
    }
    return root;
}

/*
    delete a node in the binary search tree
*/
node* delete_node(node* root, int data,comparer compare)
{
    if(root == NULL)
        return NULL;
 
    node *cursor;
    int r = compare(data,root->data);
    if( r < 0)
        root->left = delete_node( root->left, data,compare);
    else if( r > 0 )
        root->right = delete_node(root->right,data,compare);
    else
    {
        if (root->left == NULL)
        {
            cursor = root->right;
            free(root);
            root = cursor;
        }
        else if (root->right == NULL)
        {
            cursor = root->left;
            free(root);
            root = cursor;
        }
        else    //2 children
        {
            cursor = root->right;
            node *parent = NULL;
 
            while(cursor->left != NULL)
            {
                parent = cursor;
                cursor = cursor->left;
            }
            root->data = cursor->data;
            if (parent != NULL)
                parent->left = delete_node(parent->left, parent->left->data,compare);
            else
                root->right = delete_node(root->right, root->right->data,compare);
        }
    }
    return root;
}

/*
    search for a specific key
*/
node* search(node *root,const int data,comparer compare)
{
    if(root == NULL)
        return NULL;
 
    int r;
    node* cursor = root;
    while(cursor != NULL)
    {
        r = compare(data,cursor->data);
        if(r < 0)
            cursor = cursor->left;
        else if(r > 0)
            cursor = cursor->right;
        else
            return cursor;
    }
    return cursor;
}

/*
    in order traversal the binary search tree
*/
void traverse(node *root,callback cb)
{
    node *cursor, *pre;
 
    if(root == NULL)
        return;
 
    cursor = root;
 
    while(cursor != NULL)
    {
        if(cursor->left != NULL)
        {
            cb(cursor);
            cursor = cursor->right;
        }
        else
        {
            pre = cursor->left;
 
            while(pre->right != NULL && pre->right != cursor)
                pre = pre->right;
 
            if (pre->right != NULL)
            {
                pre->right = cursor;
                cursor = cursor->left;
            }
            else
            {
                pre->right = NULL;
                cb(cursor);
                cursor = cursor->right;
            }
        }
    }
}

/*
    recursively remove all nodes of the tree
*/
void dispose(node* root)
{
    if(root != NULL)
    {
        dispose(root->left);
        dispose(root->right);
        free(root);
    }
}

/*
    compare two integers
*/
int compare(int left,int right)
{
    if(left > right)
        return 1;
    if(left < right)
        return -1;
    return 0;
}

/*
    display a node's key
*/
void display(node* nd)
{
    if(nd != NULL)
        printf("%d ",nd->data);
}

/*
    Recursively display tree or subtree
*/
void display_tree(node* nd)
{
    if (nd == NULL)
        return;
    /* display node data */
    printf("%d",nd->data);
    if(nd->left != NULL)
        printf("(L:%d)",nd->left->data);
    if(nd->right != NULL)
        printf("(R:%d)",nd->right->data);
    printf("\n");
 
    display_tree(nd->left);
    display_tree(nd->right);
}

int main() {
  node* root = NULL;
  comparer int_comp = compare;
  callback f = display;

  /* insert data into the tree */
  int a[SIZE] = {8,3,10,1,6,14,4,7,13};
  int i;
  printf("--- C Binary Search Tree ---- \n\n");
  printf("Insert: ");
  for(i = 0; i < SIZE; i++)
  {
      printf("%d ",a[i]);
      root = insert_node(root,int_comp,a[i]);
  }
  printf(" into the tree.\n\n");

  /* display the tree */
  display_tree(root);

  /* remove element */
  int r;
  do
  {
      printf("Enter data to remove, (-1 to exit):");
      scanf("%d",&r);
      if(r == -1)
          break;
      root = delete_node(root,r,int_comp);
      /* display the tree */
      if(root != NULL)
          display_tree(root);
      else
          break;
  }
  while(root != NULL);

  /* search for a node */
  int key = 0;
  node *s;
  while(key != -1)
  {
      printf("Enter data to search (-1 to exit):");
      scanf("%d",&key);

      s = search(root,key,int_comp);
      if(s != NULL)
      {
          printf("Found it %d",s->data);
          if(s->left != NULL)
              printf("(L: %d)",s->left->data);
          if(s->right != NULL)
              printf("(R: %d)",s->right->data);
          printf("\n");
      }
      else
      {
          printf("node %d not found\n",key);
      }
  }

  /* remove the whole tree */
  dispose(root);
  return 0;
}
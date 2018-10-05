// Author : Satyajit Das, NIT Durgapur, India

#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *right;
    struct Node *left;

}node;

void initroot(node **root)
{
    (*root)=NULL;
    printf("TREE INITIALIZED");
}

void addroot(node **root, int value)
{
    if(*root == NULL)
    {
        node *temp = (node *)malloc(sizeof(node));
        temp->data=value;
        temp->left=NULL;
        temp->right=NULL;
        *root = temp;
    }
}

void addLChild(node *parent, int value)
{
    if(parent !=NULL && parent->left == NULL)
    {
        node *temp = (node *)malloc(sizeof(node));
        temp->data=value;
        temp->right=NULL;
        temp->left=NULL;
        parent->left=temp;
    }
}

void addRChild(node *parent, int value)
{
    if(parent !=NULL && parent->right == NULL)
    {
        node *temp = (node *)malloc(sizeof(node));
        temp->data=value;
        temp->right=NULL;
        temp->left=NULL;
        parent->right=temp;
    }
}

void findmaxmin(node *root, int *max, int *min, int start)
{
    if(root == NULL)
        return;
    if(start < *min)
        *min=start;
    else if(start > *max)
        *max=start;
    findmaxmin(root->left, max, min, start-1);
    findmaxmin(root->right, max, min, start+1);
}

void printverticalorder(node *root, int line, int start)
{
    if(root == NULL)
        return;
    if(line == start)
    {
        printf("%d ", root->data);
        //return;       // if this statement is executed, then we get top view of the tree.
    }

    printverticalorder(root->left, line, start-1);
    printverticalorder(root->right, line, start+1);
}

void verticalorder(node *root)
{
    int max=0, min=0, line;
    node *temp=root;
    findmaxmin(temp, &max, &min, 0);

    node *temp1 = root;
    for(line = min; line <= max; line++)
    {
        printverticalorder(temp1, line, 0);
        printf("\n");
    }
}

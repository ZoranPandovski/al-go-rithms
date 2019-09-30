#include<bits/stdc++.h>
using namespace std;
#define key data

struct node{
    int data;
    struct node * left, *right;
};

int height(struct node* root){
    if(root==NULL)return 0;
        return max(height(root->left),height(root->right))+1;
}

int getBalance(struct node * root){
    return height(root->left)-height(root->right);
}

struct node * rightRotate(struct node * root){
        struct node * temp2=root->left;
        struct node * temp1=temp2->right;

        root->left=temp1;
        temp2->right=root;
        return temp2;
}

struct node * leftRotate(struct node * root){
        struct node * temp2=root->right;
        struct node * temp1=temp2->left;

        root->right=temp1;
        temp2->left=root;
        return temp2;
}




struct node* insert(struct node * root,int data){
    if(root==NULL){
        root=(struct node *)malloc(sizeof(struct node));
        root->data=data;
        root->left=NULL;
        root->right=NULL;
        return root;
    }
    else if (data<root->data)
        root->left=insert(root->left,data);
    else if(data>root->data)
        root->right=insert(root->right,data);

    int balance = getBalance(root);

    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && key < root->left->key)
        return rightRotate(root);

    // Right Right Case
    if (balance < -1 && key > root->right->key)
        return leftRotate(root);

    // Left Right Case
    if (balance > 1 && key > root->left->key)
    {
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left Case
    if (balance < -1 && key < root->right->key)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }



    return root;
}
struct node* minValueNode(struct node* node)
{
    struct node* current = node;

    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;

    return current;
}


struct node* deleteValue(struct node * root,int data){
    if(root==NULL){
        return root;
    }
    else if (data<root->data)
        root->left=deleteValue(root->left,data);
    else if(data>root->data)
        root->right=deleteValue(root->right,data);
    else{
            if(root->left==NULL && root->right==NULL){

                free(root);
                return NULL;
            }

        else if(root->left==NULL || root->right==NULL){
            if(root->left==NULL){
                struct node * temp=(root->right);
                free(root);
                return temp;
            }
            else{
                struct node * temp=(root->left);
                free(root);
                return temp;

            }
            }
            else{
                root->data=(minValueNode(root->right))->data;
                root->right=deleteValue(root->right,root->data);



            }
        }


    int balance = getBalance(root);

    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && key < root->left->key)
        return rightRotate(root);

    // Right Right Case
    if (balance < -1 && key > root->right->key)
        return leftRotate(root);

    // Left Right Case
    if (balance > 1 && key > root->left->key)
    {
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left Case
    if (balance < -1 && key < root->right->key)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }



    return root;
}



int main(){
  struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 60);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 30);
    insert(root, 80);


}



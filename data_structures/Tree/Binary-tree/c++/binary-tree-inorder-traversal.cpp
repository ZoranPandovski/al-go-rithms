#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* mnew(int key)
{
    struct node* nde = new node;
    nde->data = key;
    nde->left = NULL;
    nde->right = NULL;
};

void make_tree(struct node* root,int key)
{
    queue<node* > my;
        my.push(root);
        while(!my.empty())
        {
        struct node* cur = my.front();
        my.pop();
        if(cur->left!=NULL)
            my.push(cur->left);
        if(cur->right!=NULL)
            my.push(cur->right);
        if(cur->left==NULL)
        {cur->left =  mnew(key);break;}
        if(cur->right==NULL)
           {cur->right = mnew(key);break;}
        }
}

void inorder(struct node* root)
{
    if(root==NULL)
        return;
    else{
        inorder(root->left);       // Go to the left node
        cout<<root->data<<" ";      // Visit The root node
        inorder(root->right);      // Go to the right node
    }
}



int main()
{
    int a,b,c,d,e,f,g,h;
    cout<<"Enter no of nodes\n";
    cin>>a;
    struct node* root = NULL;
    for(b=0;b<a;b++)
    {
        cin>>c;
        if(root==NULL)
        {
       root = mnew(c);
        }
        else
        make_tree(root,c);
    }
    cout<<"tree in inorder traversal\n";
    inorder(root);

}



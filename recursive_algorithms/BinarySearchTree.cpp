#include <iostream>
using namespace std;
struct node{
    int data;
    node *left,*right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
node* insertBST(node *root,int val){
    if(root==NULL){
        return new node(val);
    }
    if(val<root->data){
        root->left=insertBST(root->left,val);
    }
    else{
        root->right=insertBST(root->right,val);
    }
    return root;
}
node*SearchInBST(node* root,int key){
    if(root==NULL){
        return NULL;
    }
    if (root->data==key){
        return root;
    }
    if(key<root->data){
        return SearchInBST(root->left,key);
    }
    if(key>root->data){
        return SearchInBST(root->right,key);
    }
}
preorder(node* root){
if(root==NULL){
return NULL;
}
cout<<root->data;
preorder(root->left);
preorder(root->right);
}
inorder(node* root){
if(root==NULL){
return NULL;
}
inorder(root->left);
cout<<root->data;
inorder(root->right);
}
postorder(node* root){
if(root==NULL){
return NULL;
}
postorder(root->left);
postorder(root->right);
cout<<root->data;
}
node* deleteInBST(node* root,int key){
if(key<root->data){
	root->left=deleteInBST(root->left,key);
}
else if(key>root->data){
   root->right=delteInBST(root->right,key);
}
else{
	if(root->left==NULL){
		node* temp=root->right;
		delte root;
		return temp;
	}
else if(root->right==NULL){
   node* temp=root->left;
   delete root;
   return temp;
}
node* temp=inorderSucc(root->right);
swap(root->data,temp->data);
root->right=deleteInBST(root->right,temp->data);
}
return root;
}
}

int main()
{
    node *root=NULL;
    root=insertBST(root,4);
    insertBST(root,2);
    insertBST(root,1);
    insertBST(root,3);
    insertBST(root,8);
    insertBST(root,7);
    insertBST(root,10);
    insertBST(root,5);
    insertBST(root,6);
    node*ele=SearchInBST(root,4);
    cout<<ele->data<<endl;
    cout<<"data found"<<endl;
    cout<<"preorder  : ";
    preorder(root);
    cout<<endl;
    cout<<"inorder : ";
    //print inorder
    inorder(root);
    cout<<endl;
    cout<<"postorder :";
    postorder(root);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

struct node{
    int data;
    struct node *left, *right;
};

struct node* newNode(int data){
    struct node* Node = (struct node*)malloc(sizeof(struct node));
    Node->left = Node->right = NULL;
    Node->data = data;
    return Node;
};
void preOrderIterative(struct node *root){

    stack <node*> s;
    while(1){
        while(root){
            cout<<root->data;
            s.push(root);
            root = root->left;
        }
        if(s.empty()) break;
        root = s.top();
        s.pop();
        root = root->right;
    }
}

void inOrderIterative(struct node *root){
    stack <node*> s;
    while(1){
        while(root){
            s.push(root);
            root = root->left;
        }
        if(s.empty()) return ;
        root = s.top();
        s.pop();
        cout<<root->data;
        root = root->right;
    }
}

void postOrderIterative(struct node* root){
    stack <node*> s;
    node *previous = NULL;
    do{
        while(root){
            s.push(root);
            root = root->left;
        }
        while(root== NULL && !s.empty()){
            root = s.top();
            if(root->right == NULL || root->right == previous){
                cout<<root->data;
                s.pop();
                previous= root;
                root = NULL;
            }
            else root = root->right;
        }
    }while(!s.empty());
    return;
}

void levelOrder(struct node* root){
    queue <node *> q;
    if(!root) return ;
    q.push(root);
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        cout<<temp->data;
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
}


int findmax(struct node* root){
    int root_val, left, right, mx= INT_MIN;
    if(root!=NULL){
        root_val = root->data;
        left = findmax(root->left);
        right = findmax(root->right);
        mx = max( root_val,max(left, right));
    }
    return mx;
}
int main(){
    struct node *root = NULL;
    root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    preOrderIterative(root) ; cout<<endl;
    postOrderIterative(root); cout<<endl;
    inOrderIterative(root)  ; cout<<endl;
    levelOrder(root)        ; cout<<endl;
    cout<<findmax(root)<<endl;
    return 0;
}

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

struct Stack{
    int size;
    int top;
    struct node* *array;
};

struct Stack *createstack(int size){
    struct Stack *s= (struct Stack*)malloc(sizeof(struct Stack));
    s->top =-1;
    s->size = size;
    s->array = (struct node**)malloc(sizeof(struct node*));
    return s;
};

int isFull(struct Stack *s){
    return s->top-1 == s->size;
}

int isEmpty(struct Stack *s){
    return s->top==-1;
}

void push(struct Stack *s, struct node* Node){
    if(isFull(s)) return;
    s->array[++s->top] = Node;
}

struct node *pop(struct Stack *s){
    if(isEmpty(s)) return NULL;
    return s->array[s->top--];
};

struct node *peek(struct Stack *s){
    if(isEmpty(s)) return NULL;
    return s->array[s->top];
};


int findmax(struct node* root){
    int root_val, left, right, mx= INT_MIN;
    if(root!=NULL){
        root_val = root->data;
        left = findmax(root->left);
        right = findmax(root->right);
    //
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
    cout<<findmax(root);
    return 0;
}

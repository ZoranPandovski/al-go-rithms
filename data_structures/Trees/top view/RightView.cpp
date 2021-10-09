
// C++ program to print right view of binary tree 
#include<bits/stdc++.h> 
using namespace std;

// Structure of binary tree and function to create a new node 
struct node
{
    int data;
    struct node *left;
    struct node *right;
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// function should print the topView of the binary tree 
void rightView(node* root){
    if(root==NULL){
        return ;
    }
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        int n= q.size();
        for(int i=0; i<n; i++){
            node* curr= q.front();
            q.pop();
            if(i==n-1){
                cout<<curr->data<<" ";
            }
            if(curr->left!=NULL){
                q.push(curr->left);
            }
             if(curr->right!=NULL){
                q.push(curr->right);
            }
        }
    }
}
int main()
{
    struct node *p = new node(4);
    p->left = new node(1);
    p->right = new node(6);
    p->left->left = new node(5);
    p->left->right = new node(2);
    p->right->left=new node(9);
    p->left->right->left = new node(3);
    p->left->right->right = new node(7);
    // p->right->right=p6;

    /*     4
         /   \
        1     6
      /   \  /  \
      5   2  9  NULL
         / \
         3  7
    Right View for this Binary Tree is: 4 6 9 7
*/
    cout << "Right View Nodes of Tree: ";
    rightView(p);

    return 0;
}


/* Test Cases: 
    Input:
       1
    /    \
   3      2
    Output: 1 2

    Input:
     10
    /   \
  20     30
 /   \
40  60 
    Output: 10 30 60

    Time Complexity: O(N).
    Auxiliary Space: O(Height of the Tree).
*/
#include<iostream>

using namespace std;

class Node {
public:
    int val;
    Node* left = NULL;
    Node* right = NULL;

    Node(int val) {
        this->val = val;
    }
};

void preOrderTraversal(Node* root) {
    if (root == NULL) return;

    cout << root->val << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

int main(){
    Node* root = new Node(2);
    Node* left = new Node(1);
    Node* right = new Node(4);
    root->left = left;
    root->right = right;

    left->left = new Node(3);
    right->right = new Node(9);
    
    /* Given Tree is like this :
            2
        1       4
    3               9
    */

   preOrderTraversal(root);
    return 0;
}
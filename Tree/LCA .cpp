struct node* LCA(node* root,int a, int b){
    node *left, *right;
    if(!root) return root;
    if(root->data == a || root->data == b) return root;

    left = LCA(root->left, a, b);
    right = LCA(root->right, a, b);

    if(left && right) return root;
    else return (left?left:right);
}

node* lca(node* root, int a, int b){
    if(root== NULL) return NULL;
    if ((root->data) >a && (root->data) > b )  return lca(root->left, a , b);
    if ((root->data) <a && (root->data) < b )  return lca(root->right,a , b);
    return root;
}
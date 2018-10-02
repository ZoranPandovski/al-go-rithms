int checkmirror(node* root, node* root1){
    if(root== NULL && root1==NULL) return 1;
    else if(root==NULL || root1 == NULL) return 0;
    else if(root->data != root1->data) return 0;
    else return checkmirror(root->left , root1->right) && checkmirror(root->right, root1->left);
}
int checkstructure(node* root,node* root1){
    if(root == NULL && root1==NULL) return 1;
    else if(root==NULL || root1 == NULL) return 0;
    return ((root->data== root1->data) && checkstructure(root->left,root1->left) && checkstructure(root->right, root1->right));
}
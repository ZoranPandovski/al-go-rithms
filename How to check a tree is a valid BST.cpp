int checkbst(node* root){
    if(root==NULL) return 1;
    else if(root->left!=NULL && mx(root->left)->data>root->data) return 0;
    else if(root->right!=NULL && mn(root->right)->data <root->data) return 0;
    else if(!checkbst(root->left) || !checkbst(root->right)) return 0;
    return 1;
}
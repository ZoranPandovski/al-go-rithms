int printAncestors(node* root, int value){
    if(root== NULL) return 0;
    if(root->data == value) return 1;
    if( printAncestors(root->left,value) || printAncestors(root->right,value)){
        cout<<root->data<<" ";
        return 1;
    }
    return 0;
}
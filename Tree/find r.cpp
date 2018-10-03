int findR(struct node* root, int value){
    int temp;
    if(root == NULL) return 0;
    else{
        if(value == root->data) return 1;
        else{
            temp = findR(root->left, value);
            if(temp) return temp;
            temp = findR(root->right, value);
        }
    }
    return 0;
}

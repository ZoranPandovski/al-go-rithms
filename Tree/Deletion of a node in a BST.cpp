node* del(node* root, int data){
    if(root == NULL) return NULL;
    if(data > root->data) root->right = del(root->right, data);
    else if(data<root->data) root->left = del(root->left,data);
    else{
        if (root->left == NULL){
            node* temp =root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            node* temp = root->left;
            free(root);
            return temp;
        }
        node* temp = find_max(root->left);
        root->data = temp->data;
        root->left = del(root->left, root->data);
    }
    return root;
}


node* find_max(struct node* root){
    while(root->right!=NULL) root = root->right;
    return root;
}
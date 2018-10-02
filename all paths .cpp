void print(int a[], int len){
    for(int i=0;i<len;i++) cout<<a[i]<<" - ";
    cout<<endl;
}

void allPaths(node* root, int a[], int len){
    if(!root) return ;
    a[len] = root->data;
    len++;
    if(root->left == NULL && root->right == NULL) print(a,len);

    if(root->left)  allPaths(root->left , a, len);
    if(root->right) allPaths(root->right, a, len);
}

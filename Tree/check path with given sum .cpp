
bool SumPath(node* root, int sum){
    if(!root) return sum == 0;

    bool ans=0;
    int sub = sum - root->data;
    if(sub==0 && root->left== NULL && root->right ==NULL) return 1;
    if(root->left) ans = ans || SumPath(root->left, sub);
    if(root->right) ans = ans || SumPath(root->right, sub);
    return ans;
}
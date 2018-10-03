//iterative
int findsizeI(node* root){
    queue <node* > q;
    int cnt = 0;
    if(!root) return 0;
    q.push(root);
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        cnt++;
        if(temp->left)  q.push(temp->left) ;
        if(temp->right) q.push(temp->right);
    }
    return cnt;
}
// recursive
int findsizeR(node* root){
    if(!root) return 0;
    return findsizeR(root->left) + 1 +findsizeR(root->right);
}
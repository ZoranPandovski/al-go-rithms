int findmaxI(struct node* root){
    queue <node* > q;
    int mx = INT_MIN;
    if(!root) return -1;
    q.push(root);
    while(!q.empty()){
        node * temp = q.front();
        q.pop();
        mx = max(mx, temp->data);
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
    return mx;
}
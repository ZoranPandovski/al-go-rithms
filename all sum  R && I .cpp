int allsum(node* root){
    if(!root) return 0;
    queue <node* > q;
    q.push(root);
    int sum=0;

    while(!q.empty()){
        node* temp = q.front();
        sum+= temp->data;
        q.pop();
        if(temp->left)  q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
    return sum;
}

//
int allsum(node* root){
    if(!root) return 0;
    return (root->data + allsum(root->left) + allsum(root->right));
}


//
int allsum(node* root){
    if(!root) return 0;
    queue <node* > q;
    q.push(root);
    int sum=0;
    while(1){
        int cnt = q.size();
        if(cnt==0) return sum;
        while(cnt){
            node* temp = q.front();
            sum+= temp->data;
            q.pop();
         if(temp->left)  q.push(temp->left);
        if(temp->right) q.push(temp->right);
            cnt--;
        }
    }
}
void reverseLevelOrder(node* root){
    stack< int > s;
    queue<node*> q;
    if(!root) return ;
    q.push(root);
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        if(temp ->right) q.push(temp->right);
        if(temp ->left) q.push(temp->left);
        s.push(temp->data);
    }
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}
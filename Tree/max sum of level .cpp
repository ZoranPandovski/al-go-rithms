int maxsumoflevel(node* root){
    if(!root) return NULL;

    queue < node*> q;
    q.push(root);
    int sum=0;

    while(1){
        int cnt = q.size();
        int var =0;
        if(cnt==0) break;

        while(cnt){
            node* temp = q.front();
            q.pop();
            var+= temp->data;
            if(temp->left ) q.push(temp->left );
            if(temp->right) q.push(temp->right);
            cnt--;
        }
        sum = max(sum,var);
    }
    return sum;
}
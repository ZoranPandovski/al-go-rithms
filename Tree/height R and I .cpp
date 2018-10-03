int heightR(node* root){
    int l,r;
    if(!root) return 0;
    while(root){
        l = heightR(root->left);
        r = heightR(root->right);
        return max(l,r)+1;
    }
}

int heightI(node* root){
    if(!root) return 0;

    queue <node* > q;
    q.push(root);
    int hgt = 0;
    
    while(1){
        int cnt = q.size();
        if(cnt==0) return hgt;
        hgt++;

        while(cnt>0){
            node* rt = q.front();
            q.pop();
            if(rt->left) q.push(rt->left);
            if(rt->right) q.push(rt->right);
            cnt--;
        }
    }
}
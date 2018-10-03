int srch(int arr[], int strt, int last, int value){
    for(int i = strt; i <= last; i++){
        if(arr[i] == value) return i;
        }
        }

node* buildTree(int in[], int pre[], int start, int last){
    static int preindex = 0;
    if(start >last) return NULL;
    node* root1=newNode(pre[preindex++]);
    if(start==last) return root1;
    int idx = srch( in ,start, last, root1->data);
    root1->left = buildTree(in, pre, start, idx-1);
    root1->right = buildTree(in,pre, idx+1, last);
    return root1;
}
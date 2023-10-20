#include<bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node *left=NULL,*right=NULL,*par=NULL;
    bool red;
    node(int x=0,bool c=true):val(x),red(c){}
};

class RB_tree{
    private:
        node* r=NULL;

    private:
        node* bst_insert(node* root,int key){
            if(root==NULL) return new node(key);
            if(key<root->val) root->left=bst_insert(root->left,key);
            else root->right=bst_insert(root->right,key);
            return root;
        }

        void left_rotate(node* root){
            node* y=root->right;
            root->right=y->left;
            if(y->left!=NULL) y->left->par=root;
            y->par=root->par;
            if(root->par==NULL) r=y;
            else if(root==root->par->left) root->par->left=y;
            else root->par->right=y;
            y->left=root;
            root->par=y;
        }

        void right_rotate(node* root){
            node* y=root->left;
            root->left=y->right;
            if(y->right!=NULL) y->right->par=root;
            y->par=root->par;
            if(root->par==NULL) r=y;
            else if(root==root->par->left) root->par->left=y;
            else root->par->right=y;
            y->right=root;
            root->par=y;
        }

        bool find(node* root,int key){
            if(root==NULL) return false;
            if(root->val==key) return true;
            if(key>root->val) return find(root->right,key);
            return find(root->left,key);
        }

        node* bst_del(node* root,int key){
            if(root==NULL) return root;
            if(key==root->val){
                node* curr=root;
                if(root->left==NULL) curr=root->right;
                else if(root->right==NULL) curr=root->left;
                else{
                    node* succ=root->right;
                    while(succ->left!=NULL){
                        curr=succ;
                        succ=succ->left;
                    }
                    if(curr!=root) curr->left=succ->right;
                    else root->right=succ->right;
                    root->val=succ->val;
                    curr=succ;
                }
                delete curr;
                return root;

            }
            else if(key<root->val) root->left=bst_del(root->left,key);
            else root->right=bst_del(root->right,key);
            return root;
        }

        void inorder(node* root){
            if(root==NULL) return;
            inorder(root->left);
            cout<<root->val<<' ';
            inorder(root->right);
        }

    public:
        void rb_insert(int key){
            r=bst_insert(r,key);
            node* z=r;
            while(z->par!=NULL&&z->par->par!=NULL&&z->par->red){
                if(z->par==z->par->par->left){
                    node* y=z->par->par->right;
                    if(y!=NULL&&y->red){
                        z->par->red=false;
                        y->red=false;
                        z->par->par->red=true;
                        z=z->par->par;
                    }
                    else{
                        if(z==z->par->right){
                            z=z->par;
                            left_rotate(z);
                        }
                        z->par->red=false;
                        z->par->par->red=true;
                        right_rotate(z->par->par);
                    }
                }
                else{
                    node* y=z->par->par->left;
                    if(y!=NULL&&y->red){
                        z->par->red=false;
                        y->red=false;
                        z->par->par->red=true;
                        z=z->par->par;
                    }
                    else{
                        if(z==z->par->left){
                            z=z->par;
                            right_rotate(z);
                        }
                        z->par->red=false;
                        z->par->par->red=true;
                        left_rotate(z->par->par);
                    }
                }
            }
            r->red=false;
        }

        void rb_del(int key){ 
            r=bst_del(r,key);
            node* x=r;
            while(x!=NULL&&x->par!=NULL&&!x->red){
                if(x==x->par->left){
                    node* w=x->par->right;
                    if(w->red){
                        w->red=false;
                        x->par->red=true;
                        left_rotate(x->par);
                        w=x->par->right;
                    }
                    if((w->left==NULL||!w->left->red)&&(w->right==NULL||!w->right->red)){
                        w->red=true;
                        x=x->par;
                    }
                    else{
                        if(w->right==NULL||!w->right->red){
                            w->left->red=false;
                            w->red=true;
                            right_rotate(w);
                            w=x->par->right;
                        }
                        w->red=x->par->red;
                        x->par->red=false;
                        w->right->red=false;
                        left_rotate(x->par);
                        x=r;
                    }
                }
                else{
                    node* w=x->par->left;
                    if(w->red){
                        w->red=false;
                        x->par->red=true;
                        right_rotate(x->par);
                        w=x->par->left;
                    }
                    if((w->left==NULL||!w->left->red)&&(w->right==NULL||!w->right->red)){
                        w->red=true;
                        x=x->par;
                    }
                    else{
                        if(w->left==NULL||!w->left->red){
                            w->right->red=false;
                            w->red=true;
                            left_rotate(w);
                            w=x->par->left;
                        }
                        w->red=x->par->red;
                        x->par->red=false;
                        w->left->red=false;
                        right_rotate(x->par);
                        x=r;
                    }
                }
            }
            if(x!=NULL) x->red=false;
        }

        bool find(int key){
            return find(r,key);
        }

        void print(){
            inorder(r);
            cout<<'\n';
        }
};

int main() {
    
    return 0;
}

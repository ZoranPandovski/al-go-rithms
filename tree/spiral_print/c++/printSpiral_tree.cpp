// print a tree in spriral order


#include <bits/stdc++.h>
using namespace std;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};
/* Returns true if the given tree is a binary search tree
 (efficient version). */

/* Driver program to test size function*/


void inorder(Node *root)
{
    if (root == NULL)
       return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}


void printSpiral(Node*);

int main()
{
  int t;
  struct Node *child;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
      //  cout << n1 << " " << n2 << " " << (char)lr << endl;
        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     printSpiral(root);
  }
  return 0;

} //end of main

// solution starts from here

int getHeight(Node *tmp){
    
    if(tmp==nullptr){
        return 0;
    }
    int l = getHeight(tmp->left);
    int r = getHeight(tmp->right);
    if(l>r){
        return l+1;
    }
    else{
        return r+1;
    }
} // end


void printSpiral(Node *tmp){
  deque<Node*> queue;
  vector<int> ans;
  ans.push_back(tmp->data);
  queue.push_back(tmp);
  

  int height  = getHeight(tmp);
  
  for(int i = 1; i<=height; i++){
      
      const int qsize  = queue.size();
      for(int j = 1; j<= qsize; j++){
         if(i%2==0){
            // cout<<"level even "<<i<<endl;
             auto *ele = queue.back();
            // cout<<ele->data<<" ";
             if(ele->right != nullptr){
                 queue.push_front(ele->right);
                 ans.push_back(ele->right->data);
                // cout<<ele->right->data<<" pushed "<<endl;
                 
             }
             if(ele->left != nullptr) {
                 queue.push_front(ele->left);
                 ans.push_back(ele->left->data);
               ///  cout<<ele->left->data<< " pushed "<<endl;
             }
             queue.pop_back();
         }
         else{
            // cout<<"Level odd "<<i<<endl;
             auto *ele = queue.front();
             if(ele->left != nullptr){
                 queue.push_back(ele->left);
                 ans.push_back(ele->left->data);
                // cout<<ele->left->data<<" pushed "<<endl;
             }
             if(ele->right != nullptr) {
                 queue.push_back(ele->right);
                 ans.push_back(ele->right->data);
                // cout<<ele->right->data<<" pushed "<<endl;
             }
             queue.pop_front();
             
         }
      
    
      }      
  } // height loop

  for(int i = 0;i<ans.size(); i++){
    cout<<ans[i]<<" ";
  }

  
} //  end of func
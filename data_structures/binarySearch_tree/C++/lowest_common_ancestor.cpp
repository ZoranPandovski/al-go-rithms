#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }
        /*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
     
    Node *lca(Node *root, int v1,int v2) {
      if(root==NULL)                                              // Corner case and base condition to check whether the root node is empty or not, if it returns NULL then it means that either the root node is empty or the nodes for which Lowest Common Ancestor are asked for are not there in the tree 
        return NULL;                                              
        
      
       if(v1<root->data && v2<root->data)                         // Recursive function to calculate the value of LCA of two nodes //
      {
        return lca(root->left,v1,v2);                             // Recursive call to the left subtree //
      }
      if(v1>root->data && v2>root->data)
      {
        return lca(root->right,v1,v2);                            // Recursive call to the right subtree//
      }
      
      return root;
      
		
    }
};
    
    int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  	
  	int v1, v2;
  	std::cin >> v1 >> v2;
  
    Node *ans = myTree.lca(root, v1, v2);
    
  	std::cout << ans->data;

    return 0;
}

// To run a test comment out the above main function and uncomment the following one//
/*
	int main() {
	Solution myTree;
	Node* root = NULL;
	root = myTree.insert(root,4);
	root = myTree.insert(root,2);
	root = myTree.insert(root,3);
	root = myTree.insert(root,1);
	root = myTree.insert(root,7);
	root = myTree.insert(root,6);
	
	Node*ans = myTree.lca(root,1,7);
	
	std::cout << ans->data;
	
	return 0;
}*/

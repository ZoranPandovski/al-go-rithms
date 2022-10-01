#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>

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
     
    /*Node *lca(Node *root, int v1,int v2) {
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
      
		
    }*/
/* Alternate way is to store the nodes encountered and check for node common in both path*/


Node *lca(Node *root, int v1, int v2){
  	if(!root){
  		return NULL;
  	}
	auto copy = root;
	vector<Node*> p1;
	vector<Node*> p2;
	while (v1 != copy->data) {
		if (v1 > copy->data) {
			p1.push_back(copy);
			copy = copy->right;
		}else {
			p1.push_back(copy);
			copy = copy->left;
		}
	}
	p1.push_back(copy);
	while (v2 != root->data) {
		if (v2 > root->data) {
			p2.push_back(root);
			root = root->right;
		}else {
			p2.push_back(root);
			root = root->left;
		}
	}
	p2.push_back(root);
	Node *low = NULL;
	 
	for (int i = 0; i < min((int)p1.size(), (int)p2.size()); i++) {
		if(p1[i] == p2[i]){
			low = p1[i];
		}
	}
	return low;
  }

 

};
    void fillMap(Node *root, int lvl, int horizontalDistance, map<int, pair<int, int>> &m){
    if(!root){
      return;
    }
    if(!m.count(horizontalDistance)){
      m[horizontalDistance] = make_pair(root->data, lvl);
    }else if(m[horizontalDistance].second > lvl){
      m[horizontalDistance] = make_pair(root->data, lvl);
    }
    fillMap(root->left, lvl+1, horizontalDistance-1, m);
    fillMap(root->right, lvl+1, horizontalDistance+1, m);
  }

  void topView(Node*root){
    if(!root){
      return;
    }
    map<int, pair<int, int>> m;
    fillMap(root, 0, 0, m);
    for (auto i = m.begin(); i != m.end(); i++){
      cout << i->second.first << " ";
    }
  }
/*
            4
           /  \
          /    \
        2       7
      /   \    /
      1   3   6

Nodes which are visible from top of the root node are considered for top view. In this 1 2 4 7 are visible
from top of root node.(Consider this as 3d model and nodes which are visible from top is our ans.)

 */

int height(Node *root){
	if(root){
		return 1 + max(height(root->left), height(root->right));
	}else {
		return -1;
	}
}


/*    int main() {
  
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
}*/

// To run a test comment out the above main function and uncomment the following one//

	int main() {
	Solution myTree;
	Node* root = NULL;
	root = myTree.insert(root,4);
	root = myTree.insert(root,2);
	root = myTree.insert(root,3);
	root = myTree.insert(root,1);
	root = myTree.insert(root,7);
	root = myTree.insert(root,6);
	//topView(root);
	// Node*ans = myTree.lca(root,1,7);
	
	// std::cout << ans->data;
	cout << height(root);
	return 0;
}




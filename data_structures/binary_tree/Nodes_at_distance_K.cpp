#include <iostream>
#include <queue>
using namespace std;

// Code for finding all nodes at a distanc of K from a given node in a binary tree.

class Node {
public:
  int data;
  Node *left;
  Node *right;

  Node(int x) {
    data = x;
    left = NULL;
    right = NULL;
  }
};

// Function for finding nodes in subtree of tree at distance of K from the given node.
void subtreeNodes(Node *root, int k, vector<Node *> &ans) {
  if (root == NULL || k < 0) return;
  if (k == 0) {
    ans.push_back(root);
    return;
  }
  subtreeNodes(root->left, k - 1, ans);
  subtreeNodes(root->right, k - 1, ans);
}

int findNodes(Node *root, int key, int k, vector<Node *> &ans) {
  if (root == NULL || k < 0) return -1;
  if (root->data == key) {
    subtreeNodes(root, k, ans);
    return k - 1;
  }
  int lDist = findNodes(root->left, key, k, ans);
  if (lDist >= 0) {
    if (lDist == 0) {
      ans.push_back(root);
      return -1;
    }
    subtreeNodes(root->right, lDist - 1, ans);
    return lDist - 1;
  }
  int rDist = findNodes(root->right, key, k, ans);
  if (rDist >= 0) {
    if (rDist == 0) {
      ans.push_back(root);
      return -1;
    }
    subtreeNodes(root->left, rDist - 1, ans);
    return rDist - 1;
  }
  return -1;
}

vector<Node *> findNodesAtK(Node *root, int key, int k) {
  vector<Node *> ans;
  findNodes(root, key, k, ans);
  return ans;
}

int main() {
  Node *root = new Node(5);
  root->left = new Node(9);
  root->right = new Node(6);
  root->right->right = new Node(8);
  root->right->left = new Node(3);
  root->right->left->left = new Node(16);
  root->right->left->left->right = new Node(66);
  root->left->right = new Node(10);
  vector<Node *> ans = findNodesAtK(root, 8, 3);
  for (auto e : ans) {
    cout << e->data << " ";
  }
  cout << endl;
  return 0;
}
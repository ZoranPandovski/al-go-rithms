#include <iostream>
#include <queue>
using namespace std;

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

vector<Node *> rightView(Node *root) {
  vector<Node *> rightView;
  if (root == NULL) return rightView;
  queue<Node *> q;
  q.push(root);
  while (!q.empty()) {
    int n = q.size();
    for (int i = 0; i < n; i++) {
      Node *elem = q.front();
      q.pop();
      if (i == n - 1) rightView.push_back(elem);
      if (elem->left != NULL) q.push(elem->left);
      if (elem->right != NULL) q.push(elem->right);
    }
  }
  return rightView;
}

vector<Node *> leftView(Node *root) {
  vector<Node *> leftView;
  if (root == NULL) return leftView;
  queue<Node *> q;
  q.push(root);
  while (!q.empty()) {
    int n = q.size();
    for (int i = 0; i < n; i++) {
      Node *elem = q.front();
      q.pop();
      if (i == 0) leftView.push_back(elem);
      if (elem->left != NULL) q.push(elem->left);
      if (elem->right != NULL) q.push(elem->right);
    }
  }
  return leftView;
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
  vector<Node *> Rview = rightView(root);
  cout << "Right view:\n";
  for (auto node : Rview) {
    cout << node->data << endl;
  }
  cout << "Left view:\n";
  vector<Node *> Lview = leftView(root);
  for (auto node : Lview) {
    cout << node->data << endl;
  }
  return 0;
}
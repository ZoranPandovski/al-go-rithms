#include <cstdlib>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

// Treap has 2 main operations that are O(log(n)):
// - split(t, k) -> split t into 2 trees, one with all keys <= k, the other with the rest
// - merge(t1, t2) -> merge 2 trees where keys of t1 are smaller than any key in t2

struct Tree {
  Tree* left;
  Tree* right;
  int key;
  int value;
  int priority;

  Tree(int k, int v) {
    left = right = 0;
    key = k;
    value = v;
    priority = rand();
  }
};

pair<Tree*, Tree*> split(Tree* t, int k) {
  if (t == 0) return make_pair(nullptr, nullptr);
  if (t->key <= k) {
    auto p = split(t->right, k);
    t->right = p.first;
    return make_pair(t, p.second);
  }
  auto p = split(t->left, k);
  t->left = p.second;
  return make_pair(p.first, t);
}

Tree* merge(Tree* t1, Tree* t2) {
  if (t1 == 0) return t2;
  if (t2 == 0) return t1;
  if (t1->priority >= t2->priority) {
    t1->right = merge(t1->right, t2);
    return t1;
  }
  t2->left = merge(t1, t2->left);
  return t2;
}

// More complex operations can be implemented using only merge and split. See for example insert.
Tree* insert(Tree* t, int k, int v) {
  Tree* n = new Tree(k, v);
  auto p = split(t, k);
  return merge(p.first, merge(n, p.second));
}

void print(Tree* t, int level = 0) {
  if (t->right) print(t->right, level + 1);
  cout << string(4 * level, ' ') << "key: " << t->key << ", value: " << t->value << ", priority:"
       << t->priority << endl;
  if (t->left) print(t->left, level + 1);
}

void destroy(Tree* t) {
  if (t->left) destroy(t->left);
  if (t->right) destroy(t->right);
  delete t;
}

int main() {
  Tree* root = nullptr;
  for (int i = 0; i < 10; ++i) {
    int k = rand() % 10;
    root = insert(root, k, i);
  }
  print(root);
  destroy(root);
}

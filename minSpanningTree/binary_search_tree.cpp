#include <iostream>
#include "create_tree.h"

void searchbst(Node* root, int val){
  if(root==nullptr){
    std::cout << "Value not found" << '\n';
    return;
  }
  if (root->data==val){
    std::cout << "Value found at address -->" <<root<< '\n';
    return;
  }

  else if(val<root->data){
    searchbst(root->left_child,val);
  }
  else if(val>root->data){
    searchbst(root->right_child,val);
}
}

void display(Node* root){
  if (root==nullptr){
    return;
  }
  else{
  if(root->right_child==nullptr && root->left_child==nullptr){
    return;
  }
  if(root->right_child!=nullptr && root->left_child!=nullptr){
    std::cout << root->left_child->data<<"-->" ;
    std::cout << root->right_child->data<<"-->" ;
    display(root->left_child);
    display(root->right_child);
  }
  else if(root->right_child==nullptr){
    std::cout << root->left_child->data << '\n';

  }
  else if(root->left_child==nullptr){
    std::cout << root->right_child->data << '\n';

  }

  std::cout<< '\n';
}
}


int main(){ //to run use g++ -o main binary_search_tree.cpp create_tree.cpp
  Node* root=new Node;//this will create the executable with name main. the default name is a.out
  create_tree tree;
  tree.add_root(&root,89);
  tree.add_node(root,56);
  tree.add_node(root,34);
  tree.add_node(root,78);
  tree.add_node(root,22);
  tree.add_node(root,96);
  tree.add_node(root,95);
  tree.add_node(root,104);
  searchbst(root,78);
  return 0;
}

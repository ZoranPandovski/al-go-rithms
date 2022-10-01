#include<iostream>
#include "create_tree.h"


void create_tree:: add_root(Node** root,int data){
  Node* new_node=new Node;
  Node* root_temp=*root;
  new_node->data=data;
  new_node->left_child=root_temp->left_child;
  new_node->right_child=root_temp->right_child;
  *root=new_node;
  delete(root_temp);
  std::cout << "root added of value-->" <<new_node->data<<"--> on address "<<new_node<< '\n';
}

void create_tree:: add_node(Node* root, int data){
  Node* new_node=new Node;
  new_node->data=data;
  while(1){
    if (data>root->data){
      if (root->right_child==nullptr){
        root->right_child=new_node;
        break;
      }
      else{
        root=root->right_child;
      }
    }
    else{
      if (root->left_child==nullptr){
        root->left_child=new_node;
        break;
      }
      else{
        root=root->left_child;
      }
    }
  }
}

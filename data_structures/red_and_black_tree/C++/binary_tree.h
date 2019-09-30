#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>
#include "node.h"
#include "function_object.h"
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <stack>
#include <math.h>
#include <vector>

using namespace std;

template <typename T>
struct TraitLess{
  typedef T DataType;
  typedef Less<DataType> cmp_Type;
};

template <typename T>
struct TraitGreatest{
  typedef T DataType;
  typedef Greatest<DataType> cmp_Type;
};

template <typename Tr>
class RedBlackTree
{
private:
  typedef typename Tr::DataType T;
  typedef typename Tr::cmp_Type C;
  typedef Node<T> node;
  typedef pair< Node<T>**, bool > pair_node_path;
  C cmp_;
public:
  Node<T>* root_;
  RedBlackTree();
  ~RedBlackTree();

  bool find(T /*n*/, Node<T>** &/*p_ */,vector< pair_node_path > &/*vectorNodes*/ );

  bool insert(T /*n*/);
  bool remove(T /*n*/);
  void liberate_memory(Node<T>* /*p*/);
  void print_inorder(Node<T>* /*p*/);
  void inorder_to_string(Node<T>* /*p*/, string &/*ret*/);
  void print_tree_in_png(string /*filename_*/);
  void change_colors(Node<T>** &/*p*/);
  Node<T>** get_replace(Node<T>**/*p*/);
  string string_to_export_in_dot();

  void balance_vector(vector< pair_node_path > &/*p_*/);
  void rotation_simple(node **& /*p_*/, bool side);

  //RedBlack Functions
  bool is_black(Node<T> * /*p_*/);
  void balance_add(stack< Node<T>** >  &/*stack_nodes_*/);
};

template <typename Tr>
RedBlackTree<Tr>::RedBlackTree()
{
  this->root_ = 0;
}

template <typename Tr>
void RedBlackTree<Tr>::liberate_memory(Node<T> *p){
  if(!p)return;
  liberate_memory(p->b_leaf_[0]);
  delete p;
  liberate_memory(p->b_leaf_[1]);
}

template <typename Tr>
RedBlackTree<Tr>::~RedBlackTree(){
  Node<T>* p = this->root_;
  this->liberate_memory(p);
}

template <typename Tr>
bool RedBlackTree<Tr>::find(T n, Node<T>** &p, vector< pair_node_path > &vectorNodes)
{
  vectorNodes.clear();
  p = &root_;
  while (*p) {
    if ((*p)->b_data_==n) {
      return 1;
    }
    bool side = cmp_((*p)->b_data_,n);
    pair_node_path pair_tmp;
    pair_tmp.first = p;
    pair_tmp.second = side;
    p=&(*p)->b_leaf_[side];
    vectorNodes.push_back(pair_tmp);
  }
  return 0;
}

template<typename Tr>
Node<typename Tr::DataType>** RedBlackTree<Tr>::get_replace(Node<T>** p_){
  srand(time(NULL) );
  bool change_ = rand()%2;
  Node<T>** temp_ = &(*p_)->b_leaf_[change_];
  while ( (*temp_)->b_leaf_[!change_] )
    temp_ = &(*temp_)->b_leaf_[!change_];
  return temp_;
}

template<typename Tr>
bool RedBlackTree<Tr>::remove(T n){
  /* To remove elements from a tree
   * we have 3 cases
   * when the node does not have leaf (Case 0)
   * when the node does not have 1 leaf (Case 1)
   * and when the node have the 2 leafs (Case 2)
  */
  Node<T>** p;
  Node<T>** q;
  if(!find(n,p)) return 0;
  bool left = !!(*p)->b_leaf_[0];
  bool right = !!(*p)->b_leaf_[1];
  //Case 2
  if(left & right){
    q = get_replace(p);
    (*p)->b_data_ = (*q)->b_data_;
    p = q;
    left = !!(*p)->b_leaf_[0];
    right = !!(*p)->b_leaf_[1];
  }
  //Case 1
  if(left | right){
    Node<T>* t = *p;
    *p = (*p)->b_leaf_[right];
    delete t;
    return 1;
  }
  else{
    //Otherwise Case 0
    delete *p;
    *p = 0;
    return 1;
  }
}


template <typename Tr>
bool RedBlackTree<Tr>::insert(T n){
  vector< pair_node_path > path;
  Node<T>** p_;
  if( find(n,p_,path) ) return 0;
  //Node<T>* q = new Node<T>(n);
  (*p_) = new Node<T>(n);
  pair_node_path pair_p;
  pair_p.first = p_;
  pair_p.second = 0;

  path.push_back(pair_p);

  int sizeVector = path.size();
  if(sizeVector < 3){
    if( !this->is_black( this->root_ ) ){
      this->root_->change_color();
    }
    return 1;
  }
  this->balance_vector(path);
  if( !this->is_black( this->root_ ) ){
    this->root_->change_color();
  }
  return 1;
}

template <typename Tr>
void RedBlackTree<Tr>::change_colors(Node<T>** &p_){
  (*p_)->color_ = BLACK;
  (*p_)->b_leaf_[0]->color_ = RED;
  (*p_)->b_leaf_[1]->color_ = RED;
}

template <typename Tr>
void RedBlackTree<Tr>::balance_vector(vector<pair_node_path> &path){
  int i = path.size()-2;
  if((*path[i].first)->color_ == RED ){
    bool side = (path[i].second);
    bool side2 = (path[i-1].second);
    node **brother = &(*path[i-1].first)->b_leaf_[!side2];
    if( !!(*brother) && (*brother)->color_ == RED ){
      (*brother)->color_ = BLACK;
      (*path[i-1].first)->color_ = RED;
      (*path[i].first)->color_ = BLACK;
      (*path[i+1].first)->color_ = RED;
    }
    else if(side == side2 /*&& ( (*brother)->color_ == BLACK && !!(*brother) )*/ ){
      this->rotation_simple(path[i-1].first,side);
      this->change_colors(path[i-1].first);
    }
    else{

      this->rotation_simple(path[i].first,side);
      this->rotation_simple(path[i-1].first,side2);
      this->change_colors(path[i-1].first);
    }
  }
  if(i<2){
    return;
  }
  else{
    i -= 2;
    for(;i>0;i-=2){
      if((*path[i].first)->color_ == RED && (*path[i+1].first)->color_ == RED){
        bool side = (path[i].second);
        bool side2 = (path[i-1].second);
        node **brother = &(*path[i-1].first)->b_leaf_[!side2];
        if( !!(*brother) && (*brother)->color_ == RED ){
          (*brother)->color_ = BLACK;
          (*path[i-1].first)->color_ = RED;
          (*path[i].first)->color_ = BLACK;
          (*path[i+1].first)->color_ = RED;
        }
        else if(side == side2 /*&& ( (*brother)->color_ == BLACK && !!(*brother) )*/ ){
          this->rotation_simple(path[i-1].first,side);
          this->change_colors(path[i-1].first);
        }
        else{
          this->rotation_simple(path[i].first,side);
          this->rotation_simple(path[i-1].first,side2);
          this->change_colors(path[i-1].first);
        }

      }
    }
  }
  return;
}

//This function will make a rotation simple, the parameter
//pos will define the type of rotation, 0 is for left
//and 1 is for right
template <typename Tr>
void RedBlackTree<Tr>::rotation_simple(node** &p_, bool pos){
  node* N = *p_;
  (*p_) = (*p_)->b_leaf_[pos];
  if( !!(*p_)->b_leaf_[!pos] ){
    N->b_leaf_[pos] = (*p_)->b_leaf_[!pos];
  }
  else{
    N->b_leaf_[pos] = NULL;
  }
  (*p_)->b_leaf_[!pos] = N;
  N = NULL;
}

template <typename Tr>
bool RedBlackTree<Tr>::is_black(Node<T>* p_){
  if( !p_ || p_->color_ == BLACK ){
    return true;
  }
  return false;
}

template <typename Tr>
void RedBlackTree<Tr>::balance_add(stack<Node<T> **> &stack_nodes_){

}

//End of AVL functions

template <typename Tr>
void RedBlackTree<Tr>::print_inorder(Node<T>* p){
  if(!p){
    return;
  }
  print_inorder(p->b_leaf_[0]);
  cout << p->b_data_ << endl;
  print_inorder(p->b_leaf_[1]);

}

template <typename Tr>
void RedBlackTree<Tr>::inorder_to_string(Node<T>* p,string &ret){
  if(!p){
    return;
  }
  inorder_to_string(p->b_leaf_[0],ret);
  if(p->getNodeInfo()!=""){
    ret += p->getNodeInfo();
    ret += '\n';
  }
  inorder_to_string(p->b_leaf_[1],ret);

}

template <typename Tr>
string RedBlackTree<Tr>::string_to_export_in_dot(){
  string ret;
  ret += "digraph treeBinary {";
  ret += '\n';
  ret += "node [color=grey, style=filled];";
  ret += '\n';
  string tmp;
  inorder_to_string(this->root_,tmp);
  ret += tmp;
  ret += '\n';
  ret += "}";
  return ret;
}

template <typename Tr>
void RedBlackTree<Tr>::print_tree_in_png(string filename_){
  string extDot= filename_+".dot";
  string extPNG = filename_+".dot";
  string genDot = "dot -Tpng "+filename_+".dot > "+filename_+".png";
  string seePNG = "gwenview "+filename_+".png";
  ofstream out(extDot.c_str());
  //in the function tree.string_to_export_in_dot is the magic
  out << this->string_to_export_in_dot();
  out.close();
  //its time to generate the png
  system(genDot.c_str());
  //this is optional, if you dont like, only remove
  system(seePNG.c_str());

}



#endif // BINARY_TREE_H

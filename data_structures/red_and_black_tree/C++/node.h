#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
#include <sstream>

using namespace std;


enum Colors{RED,BLACK};

//macro to cast for a string
#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

template <class T>
class Node{
 public:
  Node(T data_){
    this->color_ = RED;
    this->b_data_ = data_;
    this->b_leaf_[0] = NULL;
    this->b_leaf_[1] = NULL;
    this->labelColors[0] = "red";
    this->labelColors[1] = "grey";
  }
  Node(){
    this->color_ = RED;
    this->b_leaf_[0] = NULL;
    this->b_leaf_[1] = NULL;
  }
  string labelColors[2];
  T b_data_;
  Node<T>*b_leaf_[2];
  int black_height_;
  Colors color_;

  string getNodeInfo(){
    string ret;
    if( !(this->b_leaf_[0]) && !(this->b_leaf_[1])){
      ret += SSTR(this->b_data_)+" [color=black, "+"fillcolor="+this->labelColors[color_]+"]";
      ret += '\n';
    }
    else{
      if( !(this->b_leaf_[0]) ){
        ret += SSTR(this->b_data_)+" [color=black, "+"fillcolor="+this->labelColors[color_]+"]";
        ret += '\n';
        ret += SSTR(this->b_data_);
        ret += "->";
        ret += SSTR(this->b_leaf_[1]->b_data_);
      }
      else if( !(this->b_leaf_[1]) ){
        ret += SSTR(this->b_data_)+" [color=black, "+"fillcolor="+this->labelColors[color_]+"]";
        ret += '\n';
        ret += SSTR(this->b_data_);
        ret += "->";
        ret += SSTR(this->b_leaf_[0]->b_data_);
      }
      else{
        ret += SSTR(this->b_data_)+" [color=black, "+"fillcolor="+this->labelColors[color_]+"]";
        ret += '\n';
        ret += SSTR(this->b_data_);
        ret += "->";
        ret += SSTR(this->b_leaf_[0]->b_data_);
        ret += '\n';
        ret += SSTR(this->b_data_);
        ret += "->";
        ret += SSTR(this->b_leaf_[1]->b_data_);
      }
    }
    return ret;
  }

  void change_color(){
    if( this->color_ == RED ){
      this->color_ = BLACK;
      return;
    }
    this->color_ = RED;
    return;
  }

};

#endif // NODE_H

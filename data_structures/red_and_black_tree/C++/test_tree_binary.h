#ifndef TEST_TREE_BINARY_H
#define TEST_TREE_BINARY_H

//#include "binary_tree.h"
//#include <assert.h>

//class TestAvlTree{
// public:
//  TestAvlTree(){

//  }
//  void run_tests(){
//    this->test_insert();
//    this->test_find();
//    this->test_remove();
//  }

//  void test_insert(){
//    AvlTree< TraitGreatest<int> > tree;
//    tree.insert(7);
//    tree.insert(6);
//    tree.insert(9);

//    assert(tree.root_->b_leaf_[0]->b_data_ < tree.root_->b_data_);
//    assert(tree.root_->b_leaf_[1]->b_data_ > tree.root_->b_data_);
//    assert(tree.root_->b_data_ == 7);
//  }
//  void test_remove(){
//    AvlTree< TraitGreatest<int> > tree;
//    tree.insert(7);
//    tree.insert(6);
//    tree.insert(9);
//    tree.insert(1);
//    //I will test the case 0:
//    tree.remove(1);
//    Node<int>** p;
//    assert( (tree.find(1,p)) == 0 );
//    //I need insert the element again
//    tree.insert(1);

//    //Now I will test the case 1
//    tree.remove(9);
//    Node<int>** q;
//    assert( tree.find(9,q) == 0 );
//    //I need insert the element again
//    tree.insert(9);

//    //Now I will test the case 2
//    tree.remove(7);
//    Node<int>** r;
//    assert( tree.find(7,r) == 0 );
//    //I need insert the element again
//    tree.insert(9);

//  }
//  void test_find(){
//    AvlTree< TraitGreatest<int> > tree;
//    tree.insert(7);
//    tree.insert(6);
//    tree.insert(9);
//    tree.insert(1);

//    Node<int>** r;
//    assert( tree.find(7,r) );
//  }

//};

#endif // TEST_TREE_BINARY_H

#include <iostream>
#include "binary_tree.h"
//#include "test_tree_binary.h"
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <list>

using namespace std;

int main()
{
  srand(time(NULL));
  RedBlackTree< TraitGreatest<int> > tree;
  for(int i=1;i<200;i++){
    int a = rand()%128;
    tree.insert(a);
    cout << a << endl;
  }

//  tree.insert(10);
//  tree.insert(85);
//  tree.insert(15);
//  tree.insert(70);
//  tree.insert(20);


  //tree.print_inorder(tree.root_);
  tree.print_tree_in_png("agasg");
  return 0;
}

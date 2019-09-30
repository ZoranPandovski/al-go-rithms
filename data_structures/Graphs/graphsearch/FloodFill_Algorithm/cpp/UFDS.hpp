// Purpose: 
// Author: 
// Date of Creation: 
// Bugs:

#ifndef UFDS_
#define UFDS_ 1
#include <iostream>
using namespace std;
#include "seqLinearList.hpp"

class UFDS {
  // Private attributes and functions for class
  // If you want to add any more variables, please add them
  // and give a valid reason for their use.
  // DO NOT DELETE ANY OF THE MEMBERS FROM BELOW
  // YOU NEED TO USE THEM ALL.

  // node in consideration for union find data structure
  // stores parent and rank for each vertex
  // You may add new members to the node, with explanation as to
  // why the members were necessary.
  class node {
    public:
      int parent;
      int rank;
    //  int size;
  };

  LinearList<node> vertex;
  LinearList<int> set_size;
  int size_;


  //int num_dis_sets;

  public:
    // Create an empty union find data structure with N isolated sets.
    UFDS(int N);

    // Default constructor
    ~UFDS();

    // Make a new set with N vertices with all sets being disjoint
    void make_set (int N);

    // Return the representative / parent of set consisting of object x.
    int find_set (int x);
    
    // Unite sets containing objects x and y.
    void union_set (int x, int y);

    void link (int x, int y);
    
    // Are objects x and y in the same set?
    bool is_same_set (int x, int y);

    // Return the number of disjoint sets.
    int num_disjoint_sets();
    
    // Return the size of the set containing object x.
    int size_set (int x); 
  };    

    UFDS :: UFDS(int N)
{
	this->vertex.resize(N);
	this->size_ = N;
	set_size.resize(N);
}

UFDS :: ~UFDS()
{

}

void UFDS :: make_set( int N)
{
	this->vertex[N].parent = N;
	this->vertex[N].rank = 0;
	set_size[N] = 1;
}

int UFDS :: find_set( int x)
{
	if(x != this->vertex[x].parent)
		this->vertex[x].parent = find_set(this->vertex[x].parent);
	return this->vertex[x].parent;
}

void UFDS :: union_set( int x, int y)
{
	if(is_same_set(x,y) == false)
		this->size_--;
	this->link(this->find_set(x),this->find_set(y));
}

void UFDS :: link( int x, int y)
{
	if(this->vertex[x].rank > this->vertex[y].rank)
	{
		this->vertex[y].parent = x;
		this->set_size[x]++;
	}
	else
	{
		this->set_size[y]++;
		this->vertex[x].parent = y;
		if(this->vertex[x].rank == this->vertex[y].rank)
			this->vertex[y].rank ++;
	}
}

bool UFDS :: is_same_set( int x, int y)
{
	return (this->find_set(x) == this->find_set(y));
}

int UFDS :: num_disjoint_sets()
{
	return this->size_;
}

int UFDS :: size_set( int x)
{
	return this->set_size[find_set(x)];
}

#endif  /* UFDS_ */

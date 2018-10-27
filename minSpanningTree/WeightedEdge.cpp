/*
 * WeightedEdge.cpp
 *
 *  Created on: 4 abr. 2016
 *      Author: roure
 */

#include "WeightedEdge.h"
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <sstream>


namespace std {
template <typename T>
  string NumberToString ( T Number )
  {
     ostringstream ss;
     ss << Number;
     return ss.str();
  }



WeightedEdge::WeightedEdge(int v, int w, double weight) {
	this->from = v;
	this->to = w;
	this->weight = weight;
}

WeightedEdge::~WeightedEdge() {
}

double WeightedEdge::getWeight() const{
	return weight;
}

int WeightedEdge::getEitherEnd() const{
	return from;
}

int WeightedEdge::getOtherEnd(int u) const{
	if (u == from) return to;
	else if (u == to) return from;
	else throw runtime_error("Did not give a correct edge end");
}

// don't know why but must be declared outside the class. Otherwise, it seems not to recognize parameters
std::ostream & operator<<(std::ostream & Str, WeightedEdge const & e) {

  Str << NumberToString(e.getEitherEnd()) << " " << NumberToString(e.getOtherEnd(e.getEitherEnd())) << " " << NumberToString(e.getWeight());
  return Str;
}


}


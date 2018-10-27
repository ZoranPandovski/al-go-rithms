/*
 * AdjListGraph.cpp
 *
 *  Created on: 4 febr. 2016
 *      Author: roure
 */

#include <stdexcept>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "EdgeWeightedGraph.h"

namespace std {
template <typename T>
  string NumberToString ( T Number )
  {
     ostringstream ss;
     ss << Number;
     return ss.str();
  }



EdgeWeightedGraph::EdgeWeightedGraph(int order) {
	adjacent =  new list<WeightedEdge *>[order];
	this->order = order;
	size = 0;
}

EdgeWeightedGraph::EdgeWeightedGraph(string fileName) {
	int v,u, nl;
	double w;
	string line;

	ifstream file;
	file.open(fileName);

	//read order
	file >> order;

	//read size (num lines)
	file >> nl;
	getline(file, line); // reading to the end of the second line
	size = 0;

	adjacent =  new list<WeightedEdge *>[order];

	for (int i=0; i<nl; i++) {
		//cout << i << " :::  ";
		getline(file, line);
		istringstream iss(line);
		iss >> u >> v >> w;
		//cout << u << " " << v << " " << w << endl;
		addEdge(new WeightedEdge(u,v,w));
	}

}

EdgeWeightedGraph::~EdgeWeightedGraph() {
	for (auto e: edgesOnce) {
		delete e;
	}

	delete[] adjacent;
}


int EdgeWeightedGraph::getSize() {
	return size;
}

int EdgeWeightedGraph::getOrder() {
	return order;
}

void EdgeWeightedGraph::addEdge(WeightedEdge *e) {
	int u = e->getEitherEnd();
	int v = e->getOtherEnd(u);

	adjacent[u].push_back(e);
	adjacent[v].push_back(e);
	edgesOnce.push_back(e);
	size++;
}


list<WeightedEdge *> & EdgeWeightedGraph::adj(int v) const{
	if (v < 0 || v >= size)  {
		throw invalid_argument ("Invalid argument");
	}
	return adjacent[v];
}

list<WeightedEdge *> & EdgeWeightedGraph::getAllEdges() {
	return edgesOnce;
}


string EdgeWeightedGraph::toString() {
	string result;

	result = NumberToString(order) + "\n";
	result.append(NumberToString(size) + "\n");

	for (int i=0; i<order; i++) {
		result.append(NumberToString(i) + ": ");
		for (auto v : adjacent[i]) {
			ostringstream s;
			s  << *v;
			result.append(s.str() + ", ");
		}
		result.append("\n");
	}


	return result;
}
} /* namespace std */

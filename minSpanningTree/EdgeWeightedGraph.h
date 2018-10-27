/*
 * AdjListGraph.h
 *
 *  Created on: 4 febr. 2016
 *      Author: roure
 */

#ifndef BASICLISTGRAPH_EDGEWEIGHTEDGRAPH_H_
#define BASICLISTGRAPH_EDGEWEIGHTEDGRAPH_H_

#include <list>
#include <string>
#include "WeightedEdge.h"

namespace std {

class EdgeWeightedGraph {
private:
	int order;  // number of vertex
	int size; // number of edges
	list<WeightedEdge *> * adjacent;
	list<WeightedEdge *> edgesOnce; // a list of all edges (no duplications)

public:
	EdgeWeightedGraph(int size);
	EdgeWeightedGraph(string fileName);

	int getSize(); //edges
	int getOrder(); //vertex
	void addEdge(WeightedEdge *e);
	list<WeightedEdge *> & adj(int v) const;
	list<WeightedEdge *> & getAllEdges();
	int degree (int v);
	string toString();


	virtual ~EdgeWeightedGraph();
};

} /* namespace std */

#endif /* BASICLISTGRAPH_ADJLISTGRAPH_H_ */

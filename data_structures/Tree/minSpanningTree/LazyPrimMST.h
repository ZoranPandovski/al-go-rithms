/*
 * LazyPrimMST.h
 *
 *  Created on: 5 abr. 2016
 *      Author: roure
 */

#ifndef MINSPANNINGTREE_LAZYPRIMMST_H_
#define MINSPANNINGTREE_LAZYPRIMMST_H_

#include "EdgeWeightedGraph.h"
#include <queue>

namespace std {

class LazyPrimMST {
public:
	LazyPrimMST(EdgeWeightedGraph & g);
	virtual ~LazyPrimMST();

	list<WeightedEdge *> & getMST();

private:
	bool * visited;
	list<WeightedEdge *> mst;
	priority_queue<WeightedEdge *, vector<WeightedEdge *>, WeightedEdgeComparison> pq;



	void visit(EdgeWeightedGraph &g, int v);
};

} /* namespace std */

#endif /* MINSPANNINGTREE_LAZYPRIMMST_H_ */

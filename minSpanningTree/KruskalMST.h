/*
 * KruskalMST.h
 *
 *  Created on: 5 abr. 2016
 *      Author: roure
 */

#ifndef MINSPANNINGTREE_KRUSKALMST_H_
#define MINSPANNINGTREE_KRUSKALMST_H_

#include "EdgeWeightedGraph.h"
#include <queue>
#include "../Structures/UnionFind.cpp"

namespace std {

class KruskalMST {
public:
	KruskalMST(EdgeWeightedGraph & g);
	virtual ~KruskalMST();

	list<WeightedEdge *> & getMST();

private:
	list<WeightedEdge *> mst;
	priority_queue<WeightedEdge *, vector<WeightedEdge *>, WeightedEdgeComparison> pq;
	UF * uf;
};

} /* namespace std */

#endif /* MINSPANNINGTREE_KRUSKALMST_H_ */

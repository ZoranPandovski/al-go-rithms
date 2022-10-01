/*
 * KruskalMST.cpp
 *
 *  Created on: 5 abr. 2016
 *      Author: roure
 */

#include "KruskalMST.h"
#include <iostream>

namespace std {

KruskalMST::KruskalMST(EdgeWeightedGraph & g) {
	uf = new UF(g.getOrder()); //keeps disjoint subsets

	for (auto &edge : g.getAllEdges()) {
		pq.push(edge);
	}

	while (!pq.empty() && (mst.size() < g.getOrder())) {
		//go for the least cost edge
		WeightedEdge *e = pq.top();
		pq.pop();

		int u = e->getEitherEnd();
		int v = e->getOtherEnd(u);
		if (uf->connected(u,v)) continue; // connected in MST

		//add edge to tree
		cout << "add tree: " << *e << endl;
		mst.push_back(e);
		uf->merge(u,v);
	}
}

KruskalMST::~KruskalMST() {
	delete uf;
}

list<WeightedEdge *> & KruskalMST::getMST() {
	return mst;
}

} /* namespace std */

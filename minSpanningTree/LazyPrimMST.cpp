/*
 * LazyPrimMST.cpp
 *
 *  Created on: 5 abr. 2016
 *      Author: roure
 */

#include "LazyPrimMST.h"
#include <iostream>

namespace std {

LazyPrimMST::LazyPrimMST(EdgeWeightedGraph & g) {
	visited = new bool[g.getOrder()];
	for (int i=0; i<g.getOrder(); i++) {
		visited[i]=false;
	}

	visit(g,0);
	while (!pq.empty()) {
		//go for the least cost edge
		WeightedEdge *e = pq.top();
		pq.pop();

		int u = e->getEitherEnd();
		int v = e->getOtherEnd(u);
		if (visited[u] && visited[v]) continue; // ineligible edge

		//add edge to tree
		cout << "add tree: " << *e << endl;
		mst.push_back(e);

		//add vertex to tree
		if (!visited[u]) visit(g,u);
		if (!visited[v]) visit(g,v);
	}
}

LazyPrimMST::~LazyPrimMST() {
	delete[] visited;
}

list<WeightedEdge *> & LazyPrimMST::getMST() {
	return mst;
}

void LazyPrimMST::visit(EdgeWeightedGraph & g, int v) {
	visited[v]=true;

	for (auto e: g.adj(v)) {
		if (!visited[e->getOtherEnd(v)])
			pq.push(e);
	}
}

} /* namespace std */

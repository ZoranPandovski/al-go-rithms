/*
 * WeightedEdge.h
 *
 *  Created on: 4 abr. 2016
 *      Author: roure
 */

#ifndef MINSPANNINGTREE_WEIGHTEDEDGE_H_
#define MINSPANNINGTREE_WEIGHTEDEDGE_H_

#include <string>
namespace std {

class WeightedEdge {

public:

	WeightedEdge(int v, int w, double weight);
	virtual ~WeightedEdge();

	double getWeight() const;
	int getEitherEnd() const;
	int getOtherEnd(int v) const;

	friend std::ostream & operator<<(std::ostream & Str, WeightedEdge const & e); // this is a friend function. It doesn't belong to the class
private:

	int from;
	int to;
	double weight;

};

/*
 * This class will be used to compare two weighted edges
 */
class WeightedEdgeComparison {
public:
	bool operator() (const WeightedEdge *lhs, const WeightedEdge * rhs) const {
		//we want to prioritize small values
		return lhs->getWeight() > rhs->getWeight();
	}
};


}


#endif /* MINSPANNINGTREE_WEIGHTEDEDGE_H_ */

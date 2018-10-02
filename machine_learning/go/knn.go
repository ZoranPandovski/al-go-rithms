package main

import (
	"strings"
)

type Item struct {
	features []float64
	class    string
}


// k-Nearest Neighbors
func NearestNeighborLearner(dataset []Item, k int) func([]float64) string {
	return func(example []float64) string {
		itemHeap := InitMinHeap()
		for _, item := range dataset {
			dis := euclidean(example, item.features)
			itemHeap.HeapPush(dis, item.class)
		}

		nearest := itemHeap.SmallestN(k)
		class := FindMaxInMap(Occurences(nearest))
		return strings.TrimSpace(class)
	}
}

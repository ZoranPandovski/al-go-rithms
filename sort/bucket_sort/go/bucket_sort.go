package main

import (
	"math"
	"sort"
)

func bucketSort(arr []int) {
	sqrtN := math.Sqrt(float64(len(arr)))
	n := int(sqrtN)

	buckets := make([][]int, n)
	for idx := range buckets {
		buckets[idx] = []int{}
	}

	max := findMax(arr)
	for _, ele := range arr {
		bIdx := hash(ele, max, n)
		buckets[bIdx] = append(buckets[bIdx], ele)
	}

	arrIdx := 0
	for idx := range buckets {
		sort.Ints(buckets[idx])
		for _, val := range buckets[idx] {
			arr[arrIdx] = val
			arrIdx++
		}
	}
}

func findMax(arr []int) int {
	max := arr[0]

	for i := 1; i < len(arr); i++ {
		if max < arr[i] {
			max = arr[i]
		}
	}

	return max
}

func hash(val, max, n int) int {
	return int(float64(val) / float64(max) * float64(n-1))
}

func main() {

}

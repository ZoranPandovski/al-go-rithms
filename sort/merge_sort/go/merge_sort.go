package main

import "fmt"

func main() {
	arr := []int{5,15,154,1,3,2,4,8,9,5,8,4,5,6,3,2,4,5}

	fmt.Printf("Unsorted: %v\n", arr)
	fmt.Printf("Sorted: %v\n", Sort(arr))
}

func merge(left []int, right []int) []int {
	var arr = make([]int, len(left) + len(right))
	var leftIndex = 0
	var rightIndex = 0

	for leftIndex < len(left) && rightIndex < len(right) {

		if left[leftIndex] <= right[rightIndex] {
			arr[leftIndex+rightIndex] = left[leftIndex]
			leftIndex++
		} else {
			arr[leftIndex+rightIndex] = right[rightIndex]
			rightIndex++
		}

	}

	for ; leftIndex < len(left); leftIndex++ {
		arr[leftIndex+rightIndex] = left[leftIndex]
	}

	for ; rightIndex < len(right); rightIndex++ {
		arr[leftIndex+rightIndex] = right[rightIndex]
	}

	return arr
}

func Sort(items []int) []int {
	if len(items) < 2 {
		return items
	}

	middle := len(items) / 2

	a := Sort(items[:middle])
	b := Sort(items[middle:])

	return merge(a, b)
}
package main

import (
	"fmt"
	"algoutils"
)

func selectionSort(array []int) {
	
	for i := 0; i < len(array) - 1; i++ {
		min := i
		for j := i + 1; j < len(array) - 1; j++ {
			if array[j] < array[min] {
				min = j
			}
		}
		algoutils.Swap(array, i, min)
	}
}

func main() {

	array := []int{1, 6, 2, 4, 9, 0, 5, 3, 7, 8}
	fmt.Println("Unsorted array: ", array)
	selectionSort(array)
	fmt.Println("Sorted array: ", array)
}

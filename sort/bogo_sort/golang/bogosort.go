package main

import (
	"fmt"
	"math/rand"
)

func main() {
	arr := []int{8, 32, 128, 2}
	fmt.Printf("Original array %v\n", arr)
	Bogosort(arr)
	fmt.Printf("Sorted array %v\n", arr)
	arr = []int{12, 31, -2}
	fmt.Printf("Original array %v\n", arr)
	Bogosort(arr)
	fmt.Printf("Sorted array %v\n", arr)
}

func Bogosort(arr []int) {
	for !IsSorted(arr) {
		rand.Shuffle(len(arr), func(i, j int) {
			arr[i], arr[j] = arr[j], arr[i]
		})
	}
}

func IsSorted(arr []int) bool {
	for i := range arr[1:] {
		if arr[i] > arr[i+1] {
			return false
		}
	}

	return true
}

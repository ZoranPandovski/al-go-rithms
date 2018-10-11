package main

import (
	"fmt"
)

//Variable indicating no of comparisons in BS
var binarysearch int

//Binary Search by dividing into 2 subparts findind data and return  its location
func BS(arr []int, data, low, high int) int {
	mid := (low + high) / 2

	if low == high {
		return high
	}
	if data > arr[mid] {
		binarysearch++
		return BS(arr, data, mid+1, high)

	}
	if data < arr[mid] {
		binarysearch++
		return BS(arr, data, low, mid)

	}
	if data == arr[mid] {
		binarysearch++
		return mid
	}
	return mid
}

func BIS(arr []int, n int) []int {
	var location int //where select should be inserted
	for i := 1; i < n; i++ {
		location = BS(arr, arr[i], 0, i)
		temp := arr[i]
		//Move all elements after location
		for j := i - 1; j >= location; j-- {
			arr[j+1] = arr[j]
		}
		arr[location] = temp
	}
	return arr
}

func main() {
	var n int
	fmt.Scanf("%d", &n)

	var binarysearch int

	var arr = make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &arr[i])
	}
	arr = BIS(arr, n)
	fmt.Println(binarysearch)
	fmt.Println(arr)
}

package main

import "errors"

// ErrNotFound is the value when the item is not in the list
var ErrNotFound = errors.New("not found")

// LinearSearch sequentially checks each element of a list until
// the correct element is found or until all elements have been searched
func LinearSearch(nums []int, x int) (int, error) {
	for i, num := range nums {
		if num == x {
			return i, nil
		}
	}
	return 0, ErrNotFound
}

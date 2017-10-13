package main

import "errors"
import "fmt"

// ErrNotFound is the value when the item is not in the list
var ErrNotFound = errors.New("not found")

func main() {
	nums := []int{3, 4, 5, 66, 42, 443, 4, 54, 6}
	item := 42
	idx, err := LinearSearch(nums, item)
	if err != nil {
		fmt.Println(err)
		return
	}

	fmt.Printf("%d found on index: %d\n", item, idx)
}

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

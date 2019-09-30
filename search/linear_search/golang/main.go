package main

import "fmt"

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

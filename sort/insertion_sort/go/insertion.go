package main

import "fmt"

func InsertionSort(arg []int) {
	i := 1
	j := 0
	var x int
	var y int
	for i < len(arg) {
		x = arg[i]
		j = i - 1
		y = arg[j]
		for j >= 0 && y > x {
			arg[j+1] = arg[j]
			j -= 1
			if j >= 0 {
				y = arg[j]
			}
		}
		arg[j+1] = x
		i += 1
	}
}

func main() {
	test1 := []int{8, 5, 1, 4, 2, 7}
	fmt.Printf("Original #1 %v\n", test1)
	InsertionSort(test1)
	fmt.Printf("Sorted   #1 %v\n", test1)
}


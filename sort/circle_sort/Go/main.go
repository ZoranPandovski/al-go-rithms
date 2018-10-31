package main

import (
	"circleSort/circlesort"
	"fmt"
)

func main() {
	arrayToBeSorted := []int{6, 14, 144, 7, -24, 9, 12, 23, 7, 331, -6, 13, 12, -1}
	fmt.Println(circlesort.CircleSort(arrayToBeSorted))
}
package main

import "fmt"

func main() {
	dataset := []float32{2, 7, 3, 9, 2, 5, 4, 1, 92, 12, 45, 22, 56, 24, 6.2}
	sorted := ShakerSort(dataset)
	fmt.Println(dataset)
	fmt.Println(sorted)
}

func ShakerSort(dataset []float32) []float32 {
	sorted := make([]float32, len(dataset))
	copy(sorted, dataset)
	swapped := false
	for i := 0; i < len(sorted)/2; i++ {
		// Go one direction
		for j := i; j < len(sorted)-1-i; j++ {
			if sorted[j] > sorted[j+1] {
				sorted[j], sorted[j+1] = sorted[j+1], sorted[j]
				swapped = true
			}
		}

		//Go the other direction
		for j := len(sorted) - 2 - i; j > i; j-- {
			if sorted[j] < sorted[j-1] {
				sorted[j], sorted[j-1] = sorted[j-1], sorted[j]
				swapped = true
			}
		}
		if swapped == false {
			break
		}
	}
	return sorted
}

package main

import "errors"

// Distance calculate Hamming distance between a and b
func Distance(a, b string) (int, error) {

	if len(a) != len(b) {
		return -1, errors.New("a and b has a different size")
	}

	distance := 0
	for index, _ := range a {
		if a[index] != b[index] {
			distance++
		}

	}
	return distance, nil
}

func main() {}

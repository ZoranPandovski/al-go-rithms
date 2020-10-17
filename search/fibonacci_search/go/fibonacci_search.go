package fibonaccisearch

import "math"

func fibonnaciSearch(arr []int, x int) (index int) {
	// fibonacci numbers initialization
	fib1 := 1
	fib2 := 0
	fib := fib1 + fib2
	n := len(arr)
	offset := -1 // leftout list for the array

	// find the smallest fibonacci greater than or equal to array length
	for fib < n {
		fib2 = fib1
		fib1 = fib
		fib = fib2 + fib1
	}

	for fib > 1 {
		i := int(math.Min(float64(offset+fib2), float64(n-1))) // Check if fib is a valid index

		// If x is greater then the value at index fib2, cut the array from offset to i
		if arr[i] < x {
			fib = fib1
			fib1 = fib2
			fib2 = fib - fib1
			offset = i

		} else if arr[i] > x { // If x is smaller then the value at index fib2, cut the array after i+1
			fib = fib2
			fib1 = fib1 - fib2
			fib2 = fib - fib1
		} else {
			return i
		}
	}

	// Compare last element with x
	if fib1 == x && arr[offset+1] == x {
		return offset + 1
	}

	return -1 // Return -1 if not found element

}

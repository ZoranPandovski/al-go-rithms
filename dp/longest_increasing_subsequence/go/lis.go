// Longest Increasing Subsequence implementation using Binary search
// Time complexity O(nlog(n))
// Memory complexity O(n)

package main

import (
	"fmt"
	"math"
)

type end struct {
	value float64
	index int
}

var (
	len, result int
	trace       []int
	input       []float64
	bestEnd     []end
)

func BinarySearch(low, high int, key float64) int {
	for low <= high {
		mid := (low + high) / 2
		if bestEnd[mid].value >= key {
			high = mid - 1
		} else {
			low = mid + 1
		}
	}
	return low
}

func solve() {
	for i := 1; i <= len; i++ {
		newLen := BinarySearch(0, len, input[i])
		if bestEnd[newLen].value > input[i] {
			bestEnd[newLen] = end{input[i], i}
			trace[i] = bestEnd[newLen-1].index
		}
		if newLen > result {
			result = newLen
		}
	}
}

func main() {
	fmt.Print("Length of your sequence?: ")
	fmt.Scanln(&len)
	trace = make([]int, len+1)
	input = make([]float64, len+1)
	bestEnd = make([]end, len+1)
	for i := range bestEnd {
		bestEnd[i].value = math.MaxFloat64
	}
	fmt.Println("Input your sequence, seperated by space or newline:")
	for i := 1; i <= len; i++ {
		fmt.Scan(&input[i])
	}
	bestEnd[0].value = 0
	solve()
	fmt.Printf("\n--------------------------------------------------------------\n")
	fmt.Printf("The longest increasing subsequence is of length: %d\n", result)
	output := make([]float64, result+1)
	outputIndex := make([]int, result+1)
	for i, j := result, bestEnd[result].index; i >= 1; i-- {
		output[i] = input[j]
		outputIndex[i] = j
		j = trace[j]
	}
	fmt.Printf("The longest increasing subsequence with the lowest lexicographic order is:\n")
	for i := 1; i <= result; i++ {
		fmt.Printf("%f, ", output[i])
	}
	fmt.Printf("\nThis subsequence is composed of the following indices:\n")
	for i := 1; i <= result; i++ {
		fmt.Printf("%d ", outputIndex[i])
	}
	fmt.Println()
}

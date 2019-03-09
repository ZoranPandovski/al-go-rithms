package main

import "fmt"

func main() {
	n := 123423129675
	fmt.Printf("Number: %d\n", n)
	fmt.Printf("Greatest digit: %d\n", greatestDigit(n))

}

func greatestDigit(n int) int {
	maxDigit := n % 10

	for n > 0 {
		currentDigit := n % 10
		if currentDigit > maxDigit {
			maxDigit = currentDigit
		}
		n = n / 10
	}

	return maxDigit
}

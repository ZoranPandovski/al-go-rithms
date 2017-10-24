package main

import (
	"fmt"
	"math"
)

func isPrime(num int) bool {
	end := int(math.Floor(math.Sqrt(float64(num))))
	for i := 2; i <= end; i++ {
		if num%i == 0 {
			return false
		}
	}
	return true
}

func main() {
	fmt.Println(isPrime(97))
	fmt.Println(isPrime(98))
	fmt.Println(isPrime(2))
}

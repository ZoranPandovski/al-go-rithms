package main

import "fmt"

func main() {
	fmt.Println("5 is a prime number: ", isPrime(5))
	fmt.Println("6 is a prime number: ", isPrime(6))
}

func isPrime(num int) bool {
	if num == 1 {
		return false
	} else {
		for i := 2; i <= num*num; i++ {
			if isPrime(i) {
				if num%i == 0 {
					return false
				}
			}
		}
		return true
	}
}

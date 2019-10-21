package main

import (
	"fmt"
)

func buildPrimes(limit int64) []int64 {
	if limit < 2 {
		return []int64{}
	}
	sieve := make([]bool, limit+1)
	primes := []int64{2}
	for i := int64(3); i <= limit; i +=2 {
	    if sieve[i] == false {
			primes = append(primes, i)
			for j := i*i; j < limit; j += 2*i {
				sieve[j] = true
			}
		}
	}
    return primes
}

func main() {
	fmt.Print(len(buildPrimes(1000)))
}


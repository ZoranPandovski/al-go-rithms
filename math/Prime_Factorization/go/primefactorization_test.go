package primefactorization

import (
	_ "testing"
	"testing"
)

func Test(t *testing.T) {
	primes := primeFactors(91)
	if primes[0] != uint64(7) {
		t.Error("first factor is not 7")
	}
	if primes[1] != uint64(13) {
		t.Error("second factor is not 13")
	}
}

package sieve

func sieveOfEratosthenes(n int) []int {

	sieve := make([]bool, n+1)
	var primes []int

	for i := 2; i <= n; i++ {
		if sieve[i] == true {
			continue
		} else {
			primes = append(primes, i)
		}
		for j := i * i; j <= n; j += i {
			sieve[j] = true
		}
	}
	return primes

}

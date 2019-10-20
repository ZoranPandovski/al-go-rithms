package primefactorization

import "fmt"

func primeFactors(n uint64) []uint64 {
	primes := make([]uint64, 0);

	if n == 1 {
		return primes
	}

	tmp := uint64(2)
	for tmp <= n {
		if n % tmp == 0 {
			primes = append(primes, tmp)
			n = n/tmp
			tmp = uint64(1)
		}
		tmp++
	}

	return primes
}

func main(){
	primes := primeFactors(91)
	fmt.Println(primes)
}

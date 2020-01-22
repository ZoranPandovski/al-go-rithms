package fibs

import "math/big"

// Fib calculates de nth fibonacci number using dynamic programming techniques
func Fib(n int) *big.Int {
	if n == 0 {
		return big.NewInt(0)
	}

	fibs := make([]*big.Int, n+1)

	// Base cases
	fibs[0] = big.NewInt(0)
	fibs[1] = big.NewInt(1)

	// Calculate from subproblems
	for i := 2; i <= n; i++ {
		fibs[i] = big.NewInt(0).Add(fibs[i-1], fibs[i-2])
	}

	return fibs[n]
}

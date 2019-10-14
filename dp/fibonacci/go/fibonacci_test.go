package fibs

import (
	"math/big"
	"testing"
)

func TestFibonacci(t *testing.T) {
	tcs := map[string]struct {
		n        int
		expected string //Use string to allow for values that overflow an int64
	}{
		"n = 0":   {0, "0"},
		"n = 1":   {1, "1"},
		"n = 2":   {2, "1"},
		"n = 50":  {50, "12586269025"},
		"n = 100": {100, "354224848179261915075"},
		"n = 200": {200, "280571172992510140037611932413038677189525"},
	}

	for name, tc := range tcs {
		t.Run(name, func(t *testing.T) {
			expected, ok := big.NewInt(0).SetString(tc.expected, 10)
			if !ok {
				t.Fatalf("Bad expected value in test case: %s", tc.expected)
			}
			res := Fib(tc.n)
			if res.Cmp(expected) != 0 {
				t.Fatalf("want %v, got %v\n", tc.expected, res)
			}
		})
	}
}

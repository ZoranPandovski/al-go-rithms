package coins

import "testing"

func TestCoinChange(t *testing.T) {
	tcs := map[string]struct {
		n        int
		s        []int
		expected int
	}{
		"n=4, s={1, 2, 3}":      {n: 4, s: []int{1, 2, 3}, expected: 4},
		"n=5, s={1, 2, 3}":      {n: 5, s: []int{1, 2, 3}, expected: 5},
		"n=10, s={2, 3, 5, 6}":  {n: 10, s: []int{2, 3, 5, 6}, expected: 5},
		"n=12, s={1, 2, 5, 10}": {n: 12, s: []int{1, 2, 5, 10}, expected: 15},
	}

	for name, tc := range tcs {
		t.Run(name, func(t *testing.T) {
			count := CountWays(tc.n, tc.s)
			if count != tc.expected {
				t.Fatalf("want: %d, got: %d\n", tc.expected, count)
			}
		})
	}
}
